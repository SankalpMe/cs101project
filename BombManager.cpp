//
// Created by sankalp on 06/02/21.
//


#include "BombManager.h"

BombManager::~BombManager() {
    for (auto &bomb: bombs) {
        delete bomb.bomb;
    }
}