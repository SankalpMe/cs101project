//
// Created by sankalp on 17/02/21.
//

#ifndef LASSOPROJECT_LEVEL2_H
#define LASSOPROJECT_LEVEL2_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level2 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        addRandomCoins();
        addRandomCoins();
        addRandomCoins();
        addRandomCoins();
        addRandomCoins();
    }

    void _init() {
        beginnerPrompt();
        coinTarget = 5;
        levelTime = -10;
        enableMagnets = false;
        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 2\nStill A Very Simple Level\nCoins Do Move In Parabola  but are still slow\nNow Collect The Coin 5 Times To Pass\nNo Time Limit");
        showSmartAlert(
                "PS. RECAP:\n THROW THE LASSO [K] IN THE APPROPIATE DIRECTION.\nONCE NEAR A COIN PRESS [L]\nNOW PULL THE LASSO BACK [M].\n\nTO MAKE THE GAME DIFFICULT\nYOU CAN [L] LOOP THE LASSO ONLY ONCE IN EACH THROW\nHENCE YOU MUST TIME THE LOOPING.");
    }
};


#endif //LASSOPROJECT_LEVEL2_H
