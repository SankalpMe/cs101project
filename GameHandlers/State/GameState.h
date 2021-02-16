//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_GAMESTATE_H
#define LASSOPROJECT_GAMESTATE_H

#include "GameObjects/bomb/bomb.h"
#include <vector>
class GameState {
public:
    char charInput;
    struct Score{
       int GoldCoin;
       int INFCoin;
    } score;

    struct Health{
        int heartLeft;
        int maxHearts;
    } health;
    bool isMagnetized;
    int magnetStepRemaining;
    int stepRemaining;
    struct BombingInfo{
       int bombNo;
    } bombingInfo;
    GameState(){
        score = {0,0};
        charInput='_';
        health = {3,3};
        bombingInfo = {0};
        isMagnetized = false;
        magnetStepRemaining = 0;
        stepRemaining = 0;
    }
};


#endif //LASSOPROJECT_GAMESTATE_H
