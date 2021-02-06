//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_BOMBMANAGER_H
#define LASSOPROJECT_BOMBMANAGER_H

#include "bomb.h"
#include "lasso.h"
#include <vector>
//class to manage multiple bombs

struct BombInfo {
    Bomb *bomb;
    double endTime;
};

class BombManager {
    vector<BombInfo> bombs;

public:
    BombManager() {

    }

    //Add Coin To Game
    void addBomb(Vector2D position, Vector2D velocity = {0, -10}) {
        Bomb *bomb = new Bomb(position, velocity, {0, COIN_G});
        bomb->init();
        bombs.push_back({bomb, 0});

    }

    void pauseAllBombs() {
        for (auto &bomb: bombs) {
            bomb.bomb->pause();
        }
    }

    void resumeAllBombs() {
        for (auto &bomb: bombs) {
            bomb.bomb->unpause();
        }
    }

    //Handle game event steps for all bombs.
    void stepBombs(float timeStep, double currentTime) {
        vector<BombInfo> newbombs;
        for(auto &bomb: bombs){
            if(!bomb.bomb->destroyed){
                newbombs.push_back(bomb);
            }else{
                delete bomb.bomb;
            }
        }

        bombs = newbombs;


        for (auto &bomb: bombs) {
            bomb.bomb->nextStep(timeStep);

            if (bomb.bomb->getYPosition() > PLAY_Y_HEIGHT) {
                bomb.bomb->reset();
                bomb.bomb->destroyed = true;
                bomb.bomb->hide();
                bomb.endTime = currentTime;

            }

            if (bomb.bomb->isPaused()) {
                if ((currentTime - bomb.endTime) >= COIN_GAP) {
                    bomb.bomb->unpause();
                }
            }
        }


    }

    void checkForLasso(Lasso &lasso) {
        for (auto &bomb: bombs) {
            lasso.check_for_bomb(bomb.bomb);
        }
    }

    ~BombManager();
};


#endif //LASSOPROJECT_BOMBMANAGER_H
