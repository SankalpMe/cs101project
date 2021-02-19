//
// Created by sankalp on 17/02/21.
//

#ifndef LASSOPROJECT_LEVEL1_H
#define LASSOPROJECT_LEVEL1_H

#include "GameHandlers/Levels/GameLevel.h"

class Level1 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        cmg->addCoin({300, PLAY_Y_HEIGHT}, {0, -100});


    }

    void _init() {
        beginnerPrompt();
        coinTarget = 3;
        levelTime = 300;
        enableMagnets = false;
        maxHearts = 3;
        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 1\nVery Simple Level\nCoins Don't Move In Parabola and are much slower\nJust Collect The Coin 3 Times To Pass\nNo Time Limit");
        showSmartAlert(
                "HOW TO CATCH A COIN:\n THROW THE LASSO [K] IN THE APPROPIATE DIRECTION.\nONCE NEAR A COIN PRESS [L]\nNOW PULL THE LASSO BACK [M].\n\nTO MAKE THE GAME DIFFICULT\nYOU CAN [L] LOOP THE LASSO ONLY ONCE IN EACH THROW\nHENCE YOU MUST TIME THE LOOPING.");
    }
};


#endif //LASSOPROJECT_LEVEL1_H
