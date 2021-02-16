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
    Text ctext;
    Text qtext;
public:
    bool levelCompleted;
    GameLevel(): obmgs(){

    }
    void init(){

        levelCompleted = false;
        coinTarget = 1;
        engine = new GameEngine();
        levelTime = -10;
        enableMagnets = false;

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
    bool restart() {

        delete engine;
        obmgs.reset();
        engine = new GameEngine();
        return run();
    }
    virtual void sceneSettings(CoinManager *cmg,BombManager *bmg){

        cmg->allowCoinRespawn = true;

        cmg->addCoin({10,PLAY_Y_HEIGHT},{0,-100});
        bmg->addBomb({70,PLAY_Y_HEIGHT},{0,-140});

    }
    bool run(){
        init();
        engine->loop();
        return handleCompletion();
    }

    virtual bool handleCompletion(){
       int gc =  engine->state.score.GoldCoin;
       if(engine->quitKey){
            showSmartAlert("LEVEL QUIT \n- SUBMITTING FINAL SCORE -");
            return false;

       }
       if(gc < coinTarget){
           showAlert("FAILED TO COMPLETE LEVEL - STARTING LEVEL AGAIN!");
           restart();
           return true;
       }
       levelCompleted = true;
       showAlert("LEVEL COMPLETED");
       return true;
    }
    void cleanup(){
        delete engine;
        engine = nullptr;
    }
    void beginnerPrompt(){
        ctext.reset(WINDOW_X/2,30,"PRESS [C] IF YOU FORGOT THE CONTROLS");
        qtext.reset(WINDOW_X/2,35+textHeight(),"PRESS [Q] TO QUIT - ONCE YOU QUIT YOUR PROGRESS WILL RESET.");
    }
    ~GameLevel(){
        delete engine;
    }
};




#endif //LASSOPROJECT_GAMELEVEL_H
