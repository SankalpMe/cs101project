//
// Created by sankalp on 28/02/21.
//

#ifndef LASSOPROJECT_LEVEL9_H
#define LASSOPROJECT_LEVEL9_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level9 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {
        cmg->allowCoinRespawn = false;
        cmg->insaneMode  = false;
        addRandomCoins(12);
    }

    void _init() {
        beginnerPrompt();
        levelScore = 600;
        maxHearts = 3;
        enableMagnets = true;
        coinTarget = 5;

        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 9\nThis Level Is Gonna Be Tough\nCoins Don't Respawn\nYou Gotta Aim Hard And Fast\nDon't Be Greedy");
        showSmartAlert(
                "REMEMBER\nCoins Don't Respawn\nBe Fast\nFive Coins To Collect");
    }

};
#endif //LASSOPROJECT_LEVEL9_H
