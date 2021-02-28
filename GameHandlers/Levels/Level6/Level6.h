//
// Created by sankalp on 28/02/21.
//

#ifndef LASSOPROJECT_LEVEL6_H
#define LASSOPROJECT_LEVEL6_H

#include "GameHandlers/LevelClass/GameLevel.h"

class Level6 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        cmg->insaneMode = true;
        bmg->deadlyMode = true;
        addRandomBombs(15);
        addRandomCoins(5);


    }

    void _init() {
        beginnerPrompt();
        levelScore = 500;
        maxHearts = 3;
        levelTime = 1000;
        coinTarget = 5;
        coinSpeedFactor = 1.2;
        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 6\nGood Luck Catching The Coins\nNow You Have To Collect Coins But There Are Just Two Many Bombs :(.\nObjective: Collect 10 Coins\nBut be careful you have only 3 hearts\nP.S. There is a Time Limit to this level.\n\nNOTE: BOMB CAUSE HEALTH DAMAGE YOU WILL SEE A HEALTH BAR ABOVE");
        showSmartAlert(
                "Please Mind The Bombs\nThere are lots and lot of them now\nThere is a time limit also.");
    }

};



#endif //LASSOPROJECT_LEVEL6_H
