//
// Created by sankalp on 28/02/21.
//

#ifndef LASSOPROJECT_LEVEL8_H
#define LASSOPROJECT_LEVEL8_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level8 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        cmg->insaneMode = true;
        bmg->deadlyMode = true;


        addRandomCoins(8);
        addRandomBombs(10);

    }

    void _init() {
        beginnerPrompt();
        levelScore = 500;
        maxHearts = 1;
        enableMagnets = true;
        coinTarget = 10;


        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 8\nHey Only 1 Heart Is Left Don't Goof up\nGotta Collect 10 Coins\nBut Be aware of the bombs");
    }

};

#endif //LASSOPROJECT_LEVEL8_H
