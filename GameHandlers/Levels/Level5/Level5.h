//
// Created by sankalp on 20/02/21.
//

#ifndef LASSOPROJECT_LEVEL5_H
#define LASSOPROJECT_LEVEL5_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level5 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        bmg->deadlyMode = true;
        addRandomBombs(5);
        addRandomCoins(10);
    }

    void _init() {
        beginnerPrompt();
        levelScore = 500;
        maxHearts = 3;
        coinTarget = 12;
        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 5\nBeware Of The Bombs\nNow You Have To Collect Coins But Also Be Aware Of The Bombs.\nObjective: Collect 12 Coins\nBe careful you have only 3 hearts\n\nNOTE: BOMB CAUSE HEALTH DAMAGE YOU WILL SEE A HEALTH BAR ABOVE");
        showSmartAlert(
                "Please Mind The Bombs\nNo Timer In This Level.");
    }

};


#endif //LASSOPROJECT_LEVEL5_H
