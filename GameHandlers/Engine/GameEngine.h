//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_GAMEENGINE_H
#define LASSOPROJECT_GAMEENGINE_H

#include "GameObjects/lasso/lasso.h"
#include "Misc/GameConstants.h"
#include "GameHandlers/State/GameState.h"
#include "UI/PrelimRenderer/PrelimLevelRender.h"
#include "Manager/BombManager.h"
#include "Manager/CoinManager.h"
#include "UI/Util/UIUtil.h"
#include "Misc/Magnet/Magnet.h"
#include <thread>
#include <queue>

class GameEngine {
public:
    bool isRunning;
    int height,width;
    GameState state;
    Lasso *lassoPtr;
    PrelimLevelRender plr;
    CoinManager *coinManager;
    BombManager *bombManager;
    Magnet *magnet;
    thread *eventThread;
    queue<XEvent> eventQueue;
    bool engineCleaned;

    struct  {
        int count;
        double time;

    } step;


    double currentTime;


    GameEngine(): state() {
        height = WINDOW_Y;
        width = WINDOW_X;
        step.count = 0;
        step.time = STEP_TIME;
        currentTime = 0;
        isRunning = true;
        lassoPtr = nullptr;

        coinManager = nullptr;
        bombManager = nullptr;

        magnet = new Magnet();
        engineCleaned = false;
    }

    void bindManagers(CoinManager *coinManager1,BombManager *bombManager1){
        coinManager = coinManager1;
        bombManager = bombManager1;
    }
    //Cleaning up...
    ~GameEngine() {
        cleanup();
    }
    void cleanup();
    //init all engine objects
    void init(){

        lassoPtr = new Lasso();
        lassoPtr->bindState(&state);

//        coinManager = new CoinManager();
//        bombManager = new BombManager();

//        coinManager->addCoin({50,PLAY_Y_HEIGHT},{30,-120});
//        coinManager->addCoin({200,PLAY_Y_HEIGHT},{60,-70});
//        coinManager->addCoin({100,PLAY_Y_HEIGHT},{-45,-100});
//        bombManager->addBomb({50,PLAY_Y_HEIGHT},{50,-80});


       magnet->bindCoinManager(coinManager);


        plr.bindState(&state);
        plr.init();
        startPumping();

    }// end of : init()
    void loop(){
        while (true){
            beginFrame();
            if(!isRunning){
                break;
            }
            handleEvent();
            handleGameEvent();
            handleStepUpdates();
            wait((float)step.time);
            currentTime += step.time;
            endFrame();
        }

    } // end of : loop()
    //handle game events bombing etc...
    void handleGameEvent() {
        if(state.bombingInfo.bombNo > 0){
            state.health.heartLeft -= state.bombingInfo.bombNo;
            state.bombingInfo.bombNo = 0;
            if(state.bombingInfo.bombNo > 1)
                showBombBoom("The Bombs Went Boom!");
            else
                showBombBoom("The Bomb Went Boom!");

        }

        if(state.health.heartLeft < 0){
            cout << "Died" << endl;
            isRunning = false;
        }
    } // end of : handleGameEvent()
    void handleStepUpdates() {

        lassoPtr->nextStep(step.time);

        coinManager->stepCoins(step.time,currentTime);

        bombManager->stepBombs(step.time,currentTime);
        if(!lassoPtr->isPaused())
            magnet->attract(lassoPtr,step.time);
        plr.step();
    }  // end of : handleStepUpdates()

    void handleEvent();
    void startPumping();

};



void pumpEvents(GameEngine *engine);
#endif //LASSOPROJECT_GAMEENGINE_H
