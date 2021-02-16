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
#include "GameObjects/MagnetGiver/MagnetGiver.h"


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
    bool spawnMagnets;

    MagnetGiver *magnetGiver;
    int targetCoins;


    struct  {
        int count;
        double time;

    } step;


    double currentTime;
    double magLastTime = 0;

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
        magnetGiver = nullptr;
        state.stepRemaining = 0;
        targetCoins = -1;
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

       magnet->bindCoinManager(coinManager);
       magnetGiver = new MagnetGiver();


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

        if(state.health.heartLeft < 0) {
            cout << "Died" << endl;
            isRunning = false;
        }
    } // end of : handleGameEvent()
    void handleStepUpdates() {

        lassoPtr->nextStep(step.time);

        coinManager->stepCoins(step.time,currentTime);

        bool caughtMagnet = magnetGiver->step(lassoPtr,&state);
        if(caughtMagnet){
            magnetGiver->disable();
            magLastTime = currentTime;
        };

        if(magnetGiver->disabled){
            if( (currentTime-magLastTime) > MAGNET_GAP ){
                double x = 0 + rand() % WINDOW_X;
                double y = 0 + rand() % PLAY_Y_HEIGHT;
                magnetGiver->enable({x,y});
            }
        }

        bombManager->stepBombs(step.time,currentTime);
        if(!lassoPtr->isPaused()){
            if(state.isMagnetized && state.magnetStepRemaining > 0){
                magnet->attract(lassoPtr,step.time);
            }
        }

        plr.step();

        if(state.magnetStepRemaining > 0){
            state.magnetStepRemaining--;
        }else{
            state.isMagnetized = false;
        }


        if(state.stepRemaining != -10){
            if(state.stepRemaining < 0){
                isRunning = false;
                cleanup();
            }
            state.stepRemaining--;
        }


        if(targetCoins != -1){
            if(targetCoins <= state.score.GoldCoin){
                cerr << "Target Complete" << endl;
                isRunning = false;
                cleanup();
            }
        }
    }  // end of : handleStepUpdates()

    void handleEvent();
    void startPumping();

};



void pumpEvents(GameEngine *engine);
#endif //LASSOPROJECT_GAMEENGINE_H
