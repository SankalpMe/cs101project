//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_GAMESTATE_H
#define LASSOPROJECT_GAMESTATE_H

#include "GameObjects/bomb/bomb.h"
#include <vector>

class GameState {
public:
    char charInput; // recent char input

    struct Score {
        int GoldCoin; // count of gold coins
    } score;

    struct Health {
        int heartLeft; // lives left
        int maxHearts; // total no. of lives
    } health;
    bool isMagnetized; // is lasso a  magnet
    int magnetStepRemaining; // time remaining for magnetic effect
    int stepRemaining; // time left for the given level
    struct BombingInfo {
        int bombNo; // no of bombs the player got boomed with
    } bombingInfo;

    GameState();
};


#endif //LASSOPROJECT_GAMESTATE_H
