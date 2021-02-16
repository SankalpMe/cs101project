//
// Created by sankalp on 17/02/21.
//

#ifndef LASSOPROJECT_LEVEL1_H
#define LASSOPROJECT_LEVEL1_H

#include "GameHandlers/Levels/GameLevel.h"

class Level1: public GameLevel {
    void sceneSettings(CoinManager *cmg,BombManager *bmg){

        cmg->allowCoinRespawn = true;
        cmg->addCoin({300,PLAY_Y_HEIGHT},{0,-100});
    }
    void _init(){

        coinTarget = 3;
        levelTime = -10;
        enableMagnets = false;

        showSmartAlert("LEVEL 1\nVery Simple Level\nCoins Don't Move In Parabola and are much slower\nJust Collect The Coin 3 Times To Pass\nNo Time Limit");
    }
};


#endif //LASSOPROJECT_LEVEL1_H
