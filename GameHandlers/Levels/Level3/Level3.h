//
// Created by sankalp on 20/02/21.
//

#ifndef LASSOPROJECT_LEVEL3_H
#define LASSOPROJECT_LEVEL3_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level3 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        addRandomCoins(15);
    }

    void _init() {
        beginnerPrompt();
        coinTarget = 6;
        levelTime = 300;
        levelScore = 300;
        enableMagnets = false;
        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 3\nA Challenge This Time\nNow Collect The Coin 6 Times To Pass\nBut This There Is Time Limit\n\nNOTE: TIME LEFT IS VISIBLE IN THE BOTTOM BAR");
        showSmartAlert(
                "I HOPE YOU REMEMBER THE CONTROLS:\n THROW THE LASSO [K] IN THE APPROPIATE DIRECTION.\nONCE NEAR A COIN PRESS [L]\nNOW PULL THE LASSO BACK [M].\n\nTO MAKE THE GAME DIFFICULT\nYOU CAN [L] LOOP THE LASSO ONLY ONCE IN EACH THROW\nHENCE YOU MUST TIME THE LOOPING.");
    }
};



#endif //LASSOPROJECT_LEVEL3_H
