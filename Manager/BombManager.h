//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_BOMBMANAGER_H
#define LASSOPROJECT_BOMBMANAGER_H

#include "GameObjects/bomb/bomb.h"
#include "GameObjects/lasso/lasso.h"
#include <vector>
#include "Misc/GameConstants.h"
//class to manage multiple bombs

struct BombInfo {
    Bomb *bomb;
    double endTime;
};

class BombManager {
    vector<BombInfo> bombs;

public:
    bool deadlyMode; // bombs respawn when set true
    BombManager() {
        deadlyMode = false;
    }

    //adds a bomb to the game
    void addBomb(Vector2D position, Vector2D velocity = {0, -10}, double startTime = 0) ;

    // pauses all bombs in game
    void pauseAllBombs() {
        for (auto &bomb: bombs) {
            bomb.bomb->pause();
        }
    } // end of :  pauseAllBombs()

    // resumes the bombs
    void resumeAllBombs() {
        for (auto &bomb: bombs) {
            bomb.bomb->unpause();
        }
    }

    //Handle game steps for all bombs.
    void stepBombs(float timeStep, double currentTime);

    // lasso looping handling with bombs
    void checkForLasso(Lasso &lasso) {
        for (auto &bomb: bombs) {
            lasso.check_for_bomb(bomb.bomb);
        }
    }

    ~BombManager();
};


#endif //LASSOPROJECT_BOMBMANAGER_H
