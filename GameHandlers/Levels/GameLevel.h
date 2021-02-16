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

protected:
    GameEngine *engine;
    ObjectManagers obmgs;
    int coinTarget;
    int levelTime;
    bool enableMagnets;
public:
    bool levelCompleted;
    GameLevel(): obmgs(){
        levelCompleted = false;
        coinTarget = 1;
        engine = new GameEngine();
        levelTime = -10;
        enableMagnets = false;
    }
    void init(){
        engine->bindManagers(obmgs.coinManager,obmgs.bombManager);
        engine->init();
        sceneSettings(obmgs.coinManager,obmgs.bombManager);




        _init();
        postinit();
    }
    void addRandomCoins(){
        double xpos = PLAY_X_START +  rand() % (WINDOW_X - 100 - PLAY_X_START );

        double  xvel = -50.0 + rand() % 100;
        double  yvel = -70.0 - rand() % 80;
        obmgs.coinManager->addCoin({xpos,PLAY_Y_HEIGHT},{xvel,yvel});
    }
    virtual void _init(){

    }
    void postinit(){
        engine->targetCoins = coinTarget;
        engine->state.stepRemaining = levelTime;
        engine->spawnMagnets = enableMagnets;
    }
    void restart() {

        delete engine;
        obmgs.reset();
        engine = new GameEngine();
        run();
    }
    virtual void sceneSettings(CoinManager *cmg,BombManager *bmg){

        cmg->allowCoinRespawn = true;

        cmg->addCoin({10,PLAY_Y_HEIGHT},{0,-100});
        bmg->addBomb({70,PLAY_Y_HEIGHT},{0,-140});

    }
    void run(){
        init();
        engine->loop();
        handleCompletion();
    }

    virtual void handleCompletion(){
       int gc =  engine->state.score.GoldCoin;

       if(gc < coinTarget){
           showAlert("FAILED TO COMPLETE LEVEL - STARTING LEVEL AGAIN!");
           restart();
           return;
       }
       levelCompleted = true;
       showAlert("LEVEL COMPLETED");
       return;
    }

};


#endif //LASSOPROJECT_GAMELEVEL_H
