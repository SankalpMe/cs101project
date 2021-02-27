//
// Created by sankalp on 06/02/21.
//

#include "GameState.h"

GameState::GameState() {
    score = {0};
    charInput = '_';
    health = {3, 3};
    bombingInfo = {0};
    isMagnetized = false;
    magnetStepRemaining = 0;
    stepRemaining = 0;
}