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

    ObjectManagers() {
        coinManager = new CoinManager();
        bombManager = new BombManager();
    }

    void reset() {
        delete coinManager;
        delete bombManager;
        coinManager = new CoinManager();
        bombManager = new BombManager();
    }

    ~ObjectManagers() {
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
    int maxHearts;

    Text ctext;
    Text qtext;
public:
    bool levelCompleted;
    bool userQuit;

    GameLevel() : obmgs() {
        levelTime = -10;
        enableMagnets = false;
        maxHearts = 3;
        coinTarget = -1;
    }

    void init();

    void addRandomCoins(int coins=1);
    void addRandomBombs(int bombs=1);

    virtual void _init() {

    }

    void postinit() {
        engine->targetCoins = coinTarget;
        engine->state.stepRemaining = levelTime;
        engine->spawnMagnets = enableMagnets;
        engine->maxHearts = maxHearts;
        engine->state.health.heartLeft = maxHearts;
    }

    bool restart() {

        delete engine;
        obmgs.reset();

        return run();
    }

    virtual void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;

        cmg->addCoin({10, PLAY_Y_HEIGHT}, {0, -100});
        bmg->addBomb({70, PLAY_Y_HEIGHT}, {0, -140});

    }

    bool run() {
        init();
        engine->loop();
        return handleCompletion();
    }

    virtual bool handleCompletion();

    // handle state after level quit call
    virtual void levelQuit(){
        showSmartAlert("LEVEL QUIT \n- SUBMITTING FINAL SCORE -");
    }
    virtual  bool checkAchievements() {
        return ( coinTarget == -1 || coinTarget <= engine->state.score.GoldCoin ) && !engine->died;
    };
    void cleanup() {
        delete engine;
        engine = nullptr;
    }

    void beginnerPrompt();


    virtual ~GameLevel() {
        delete engine;
    }
};


#endif //LASSOPROJECT_GAMELEVEL_H
