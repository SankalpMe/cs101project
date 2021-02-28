//
// Created by sankalp on 28/02/21.
//

#ifndef LASSOPROJECT_LEVEL10_H
#define LASSOPROJECT_LEVEL10_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level10 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {
        cmg->allowCoinRespawn = true;
        cmg->insaneMode = true;
        bmg->deadlyMode = true;
        coinSpeedFactor = 1.3;
        addRandomCoins(3);
        addRandomBombs(20);
    }

    void _init() {
        beginnerPrompt();
        levelScore = 1000;
        maxHearts = 1;
        enableMagnets = true;
        coinTarget = 10;
        levelTime=1500;

        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 10\nCatch 5 coins\nBe Fast\nDon't Be Greedy");
        showSmartAlert(
                "HEY\nYou Have Only 1 Heart\nAnd Lot's Of Bombs To Dodge");
    }

};
#endif //LASSOPROJECT_LEVEL10_H
