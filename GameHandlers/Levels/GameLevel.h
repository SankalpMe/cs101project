//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_GAMELEVEL_H
#define LASSOPROJECT_GAMELEVEL_H

#include "Misc/GameConstants.h"
#include "GameHandlers/Engine/GameEngine.h"
#include "Manager/BombManager.h"
#include "Manager/CoinManager.h"



struct ObjectManagers {
    CoinManager *coinManager;
    BombManager *bombManager;

    ObjectManagers(){
        coinManager = new CoinManager();
        bombManager = new BombManager();
    }
    void reset(){
        delete coinManager;
        delete bombManager;
        coinManager = new CoinManager();
        bombManager = new BombManager();
    }
    ~ObjectManagers(){
        delete coinManager;
        delete bombManager;
    }
};
class GameLevel {
    int coinTarget;
    GameEngine *engine;
    ObjectManagers obmgs;
public:
    GameLevel(): obmgs(){
        coinTarget = 1;
        engine = new GameEngine();
    }
    void init(){
        engine->bindManagers(obmgs.coinManager,obmgs.bombManager);
        engine->init();
        sceneSettings(obmgs.coinManager,obmgs.bombManager);

        engine->spawnMagnets = true;
        engine->state.stepRemaining = 100;
        engine->targetCoins = coinTarget;
    }
    void restart() {

        delete engine;
        obmgs.reset();
        engine = new GameEngine();
        run();
    }
    void sceneSettings(CoinManager *cmg,BombManager *bmg){

        cmg->allowCoinRespawn = true;

        cmg->addCoin({10,PLAY_Y_HEIGHT},{0,-100});
        bmg->addBomb({70,PLAY_Y_HEIGHT},{0,-140});
    }
    void run(){
        init();
        engine->loop();
        handleCompletion();
    }

    void handleCompletion(){
       int gc =  engine->state.score.GoldCoin;

       if(gc < coinTarget){
           showAlert("FAILED TO COMPLETE LEVEL - STARTING LEVEL AGAIN!");
           restart();
           return;
       }
       showAlert("LEVEL COMPLETED");
       return;
    }

};


#endif //LASSOPROJECT_GAMELEVEL_H
