//
// Created by sankalp on 06/02/21.
//


#include "BombManager.h"

BombManager::~BombManager() {
    for (auto &bomb: bombs) {
        delete bomb.bomb;
    }
}

void BombManager::addBomb(Vector2D position, Vector2D velocity, double startTime) {
    Bomb *bomb = new Bomb(position, velocity, {0, COIN_G}); // similar physics as COIN
    bomb->init(); // initialize  bomb ( Rendering and Constants ).
    bombs.push_back({bomb, startTime});
    bomb->pause();
    bomb->hide();
} // end of addBomb(...)


void BombManager::stepBombs(float timeStep, double currentTime) {

    // to remove all destroyed / exploaded bombs from the scene
    vector<BombInfo> newbombs;
    int bombsLost = 0;
    for (auto &bomb: bombs) {
        if (!bomb.bomb->destroyed) {
            newbombs.push_back(bomb);
        } else {
            delete bomb.bomb;
            bombsLost++;
        }
    }

    bombs = newbombs; // copies all the present bombs

    // update each bomb
    for (auto &bomb: bombs) {
        bomb.bomb->nextStep(timeStep);

        // remove bombs going out of scene
        if (bomb.bomb->getYPosition() > PLAY_Y_HEIGHT) {
            bomb.bomb->reset();
            bomb.bomb->destroyed = true;
            bomb.bomb->hide(); // hide the bomb
            bomb.endTime = currentTime;

        }

        // bomb spawn time gap handling
        if (bomb.bomb->isPaused()) {
            if ((currentTime - bomb.endTime) >= COIN_GAP) {
                bomb.bomb->unpause();
                bomb.bomb->show();
            }
        }
    }

    // respawn bombs if deadly mode:

    if (deadlyMode) {
        for (int i = 0; i < bombsLost; i++) {
            // spawns a new bomb at different location
            addBomb({0.0 + rand() % WINDOW_X, PLAY_Y_HEIGHT}, {0.0 + rand() % 50, -50.0 - (rand() % 100)},
                    currentTime);
        }
    }


}