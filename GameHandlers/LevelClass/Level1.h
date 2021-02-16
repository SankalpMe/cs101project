//
// Created by sankalp on 17/02/21.
//

#ifndef LASSOPROJECT_LEVEL1_H
#define LASSOPROJECT_LEVEL1_H

#include "GameHandlers/Levels/GameLevel.h"

class Level1: public GameLevel {
    void sceneSettings(CoinManager *cmg,BombManager *bmg){

        cmg->allowCoinRespawn = true;
        addRandomCoins();
        addRandomCoins();
        addRandomCoins();
    }
    void _init(){
        coinTarget = 10;
        levelTime = 1000;
        enableMagnets = false;
    }
};


#endif //LASSOPROJECT_LEVEL1_H
