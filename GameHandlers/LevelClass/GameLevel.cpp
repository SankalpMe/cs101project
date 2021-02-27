//
// Created by sankalp on 06/02/21.
//

#include "GameLevel.h"

void GameLevel::init() {

    // configuring basic settings.
    levelCompleted = false;
    coinTarget = -1;
    levelTime = -10;
    enableMagnets = false;
    maxHearts = 3;
    userQuit = false;
    engine = new GameEngine();
    _init();

    //binding the managers to the engine
    engine->bindManagers(obmgs.coinManager, obmgs.bombManager);

    engine->init(); // engine init sequence
    sceneSettings(obmgs.coinManager, obmgs.bombManager); // setting up the scene


    postinit(); // continuing to post init
}

// handle completion event of level.
bool GameLevel::handleCompletion() {
    int gc = engine->state.score.GoldCoin;

    // level quit
    if (engine->quitKey) {
        userQuit = true;
        levelQuit();
        return false;
    }


    bool levelCheck =  checkAchievements(); // check level completion

    if (!levelCheck) {
        return false;
    }else{
        levelCompleted = true;
        showAlert("LEVEL COMPLETED");
        return true;
    }

}

//add random coins to game
void GameLevel::addRandomCoins(int coins) {
    repeat(coins){
        double xpos = PLAY_X_START + rand() % (WINDOW_X - 100 - PLAY_X_START);

        double xvel = -50.0 + rand() % 100;
        double yvel = -70.0 - rand() % 80;
        obmgs.coinManager->addCoin({xpos, PLAY_Y_HEIGHT}, {xvel, yvel});
    }

}

//add  bomb in random config
void GameLevel::addRandomBombs(int bombs){
    repeat(bombs){
        obmgs.bombManager->addBomb({0, WINDOW_Y}, {0, 100});
    }
}

// shows instructions for beginners
void GameLevel::beginnerPrompt() {
    ctext.reset(WINDOW_X / 2, 30, "PRESS [C] IF YOU FORGOT THE CONTROLS");
    qtext.reset(WINDOW_X / 2, 35 + textHeight(), "PRESS [Q] TO QUIT - ONCE YOU QUIT YOUR PROGRESS WILL RESET.");
}