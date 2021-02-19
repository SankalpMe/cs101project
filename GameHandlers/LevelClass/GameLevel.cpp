//
// Created by sankalp on 06/02/21.
//

#include "GameLevel.h"

void GameLevel::init() {

    levelCompleted = false;
    coinTarget = 1;
    levelTime = -10;
    enableMagnets = false;
    maxHearts = 3;
    userQuit = false;
    engine = new GameEngine();
    _init();
    engine->bindManagers(obmgs.coinManager, obmgs.bombManager);
    engine->init();
    sceneSettings(obmgs.coinManager, obmgs.bombManager);


    postinit();
}

// handle completion event of level.
bool GameLevel::handleCompletion() {
    int gc = engine->state.score.GoldCoin;
    if (engine->quitKey) {
        userQuit = true;
        levelQuit();
        return false;
    }


    bool levelCheck =  checkAchievements();

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