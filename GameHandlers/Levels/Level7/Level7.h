//
// Created by sankalp on 28/02/21.
//

#ifndef LASSOPROJECT_LEVEL7_H
#define LASSOPROJECT_LEVEL7_H


#include "GameHandlers/LevelClass/GameLevel.h"

class Level7 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        cmg->insaneMode = true;



        addRandomCoins(4);


    }

    void _init() {
        beginnerPrompt();
        levelScore = 100;
        maxHearts = 3;
        enableMagnets = true;
        coinTarget = 5;

        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 7\nHey Hey\nNew Feature Coming\nIn The Game Wait For Sometime\nYou Would See A Magnet Spawn\nTry Collecting The Magnet\nafter that collect 5 coins\n\nNOTE: TO COLLECT THE MAGNET LASSO SHOULD JUST PASS NEAR THE\nNO NEED TO LOOP THE LASSO");
        showSmartAlert(
                "Hey Do Try To Collect The Magnet\nLater On It's Gonna Be\nUsefull");
    }

};

#endif //LASSOPROJECT_LEVEL7_H
