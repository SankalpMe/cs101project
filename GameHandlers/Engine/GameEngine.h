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
    bool died;
    MagnetGiver *magnetGiver;
    bool quitKey;
    int targetCoins;
    int maxHearts;


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
        maxHearts = 3;
        died = false;
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
        cleanup();
    } // end of : loop()
    //handle game events bombing etc...
    void handleGameEvent() {

        // Performs the bombing aftereffect
        if(state.bombingInfo.bombNo > 0){

            state.health.heartLeft -= state.bombingInfo.bombNo;
            state.bombingInfo.bombNo = 0;

            // visual explosion effect
            if(state.bombingInfo.bombNo > 1)
                showBombBoom("The Bombs Went Boom!"); // mind the grammar
            else
                showBombBoom("The Bomb Went Boom!");

            resetEventQueue();

        }

        //kill player after health < 0
        if(state.health.heartLeft < 0) {
            cerr << "Player Died." << endl;
            isRunning = false;
            died = true;
        }


    }
    void resetEventQueue(){
        eventQueue = queue<XEvent>();
    }
    void handleStepUpdates() ;

    void handleEvent(); //handle the event in game
    void startPumping(); //start event loop and pump those events

};



void pumpEvents(GameEngine *engine);
#endif //LASSOPROJECT_GAMEENGINE_H
