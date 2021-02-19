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
    bool quitKey;
    int targetCoins;


    struct  {
        int count;
        double time;

    } step;


    double currentTime;
    double magLastTime = 0;

    GameEngine(): state() {
        quitKey = false;
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
        magLastTime = 0;
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

        magnetGiver->disable();
        plr.bindState(&state);
        plr.init();
        startPumping();

    }// end of : init()
    void loop(){
        while (true){

            // break from loop if game is not running
            if(!isRunning){
                break;
            }


            // endFrame and beginFrame allow to speed up rendering as all the changes made are propogated once.
            beginFrame(); // pause renderer

            handleEvent(); // event Update
            handleGameEvent(); // game Event Updates handled.
            handleStepUpdates(); // step function of many objects called.

            wait((float)step.time); // fps mechanisim
            currentTime += step.time;


            endFrame(); // resume rendering

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
            cerr << "Died" << endl;
            isRunning = false;
        }
    } // end of : handleGameEvent()
    void handleStepUpdates() {

        lassoPtr->nextStep(step.time); //update lasso

        coinManager->stepCoins(step.time,currentTime); //update coins

        bool caughtMagnet = magnetGiver->step(lassoPtr,&state); //magnet catcher
        if(caughtMagnet){
            magnetGiver->disable(); // disable magnet spawning
            magLastTime = currentTime; // timing delay for next spawning
        };

        if(magnetGiver->disabled){
            if( (currentTime-magLastTime) > MAGNET_GAP ){
                // find a random location
                double x = 0 + rand() % WINDOW_X;
                double y = 0 + rand() % PLAY_Y_HEIGHT;
                magnetGiver->enable({x,y}); // enable spawning
            }
        }

        bombManager->stepBombs(step.time,currentTime); // update bombs
        if(!lassoPtr->isPaused()){
            if(state.isMagnetized && state.magnetStepRemaining > 0){
                magnet->attract(lassoPtr,step.time); // perform magnetic field
            }
        }

        plr.step(); // ui step

        // magnetic effect countdown
        if(state.magnetStepRemaining > 0){
            state.magnetStepRemaining--;
        }else{
            state.isMagnetized = false;
        }

        // gameLevel timer disabled when set to -10
        if(state.stepRemaining != -10){
            if(state.stepRemaining < 0){
                isRunning = false;
                cleanup(); // exit from level
            }
            state.stepRemaining--;
        }

        // exit when target is achieved,  -1 is set when no target.
        if(targetCoins != -1){
            if(targetCoins <= state.score.GoldCoin){
                cerr << "Target Complete" << endl;
                isRunning = false;
                cleanup();
            }
        }
    }  // end of : handleStepUpdates()

    void handleEvent(); //handle the event in game
    void startPumping(); //start event loop and pump those events

};



void pumpEvents(GameEngine *engine);
#endif //LASSOPROJECT_GAMEENGINE_H
