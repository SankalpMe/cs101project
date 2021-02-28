//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_GAMELEVEL_H
#define LASSOPROJECT_GAMELEVEL_H

#include "Misc/GameConstants.h"
#include "GameHandlers/Engine/GameEngine.h"
#include "Manager/BombManager.h"
#include "Manager/CoinManager.h"

// manages all the spawners in  the gamelevel
struct ObjectManagers {
    CoinManager *coinManager; //manages coin spawning
    BombManager *bombManager; //manages bomb spawning

    ObjectManagers() {
        coinManager = new CoinManager();
        bombManager = new BombManager();
    }

    //resets all the managers
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
    GameEngine *engine; // the main core of the game
    ObjectManagers obmgs;
    int coinTarget; // no of coins to collect in a given level , -1 : no coin target.
    int levelTime; // time limit for a level, -10 : no time limit
    bool enableMagnets;// to enable magnet Spawn
    int maxHearts; // no. of hearts per level.
    double levelScore; //score assigned to a level

    double coinSpeedFactor; // affects the coin speed
    // For displaying some ingame instructions
    Text ctext;
    Text qtext;
public:
    bool levelCompleted; // status for level completion
    bool userQuit; // checks if user quit the level.

    GameLevel() : obmgs() {
        coinSpeedFactor = 1;
        levelTime = -10;
        enableMagnets = false;
        maxHearts = 3;
        coinTarget = -1;
        levelScore = 100;
    }

    void init(); // init sequence sets some paramaeters.

    void addRandomCoins(int coins = 1); // helper to add random coins
    void addRandomBombs(int bombs = 1); // helper to add random bombs

    // function to be implemented by inherited levels.
    virtual void _init() {

    }

    // post initialization routine
    void postinit() {
        // configures base parameters from super parameters
        engine->targetCoins = coinTarget;
        engine->state.stepRemaining = levelTime;
        engine->spawnMagnets = enableMagnets;
        engine->maxHearts = maxHearts;
        engine->state.health.heartLeft = maxHearts;
        obmgs.coinManager->speedFactor = coinSpeedFactor;
    }

    // restart the level
    bool restart() {

        delete engine;
        obmgs.reset();

        return run();
    }


    // modify scene settings : spawning of coins and bombs
    virtual void sceneSettings(CoinManager *cmg, BombManager *bmg) {

    }

    // run () : to run / start the given level
    bool run() {
        beginFrame();
        init();
        engine->loop(); // start the engine loop
        return handleCompletion(); // handle completion of game ( termination and score calculation)
    }

    // to be implement by game level to handle completion
    virtual bool handleCompletion();

    // handle state after level quit call
    virtual void levelQuit() {
        showSmartAlert("LEVEL QUIT \n- SUBMITTING FINAL SCORE -");
    }

    // check the player achievement
    virtual bool checkAchievements() {
        return (coinTarget == -1 || coinTarget <= engine->state.score.GoldCoin) && !engine->died;
    };


    // grade() : calculates the score earned by the player
    virtual double grade() {

        double gscore = 100.0 * (engine->state.health.heartLeft) / engine->state.health.maxHearts +
                        checkAchievements() * levelScore +
                        (levelTime != -10) * (((double) engine->state.stepRemaining) / levelTime) * 50.0;
        cout << gscore << endl;
        gscore = ((int) (gscore * 100)) / 100.0; // round score to 2 decimals
        return gscore;
    };

    //clear up the code
    void cleanup() {
        if (engine)
            delete engine;
        engine = nullptr;
    }

    void beginnerPrompt(); // shows control instruction for beginners.


    virtual ~GameLevel() {
        delete engine;
    }
};


#endif //LASSOPROJECT_GAMELEVEL_H
