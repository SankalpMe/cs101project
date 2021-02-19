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

    //adds bomb to the game
    void addBomb(Vector2D position, Vector2D velocity = {0, -10}) {
        Bomb *bomb = new Bomb(position, velocity, {0, COIN_G}); // similar physics as COIN
        bomb->init(); // initialize  bomb ( Rendering and Constants ).
        bombs.push_back({bomb, 0});
    } // end of addBomb(...)

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
    void stepBombs(float timeStep, double currentTime) {

        // to remove all destroyed / exploaded bombs from the scene
        vector<BombInfo> newbombs;
        int bombsLost = 0;
        for(auto &bomb: bombs){
            if(!bomb.bomb->destroyed){
                newbombs.push_back(bomb);
            }else{
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

            if (bomb.bomb->isPaused()) {
                if ((currentTime - bomb.endTime) >= COIN_GAP) {
                    bomb.bomb->unpause();
                }
            }
        }

        // respawn bombs if deadly mode:

        if(deadlyMode){
            for(int i = 0 ; i < bombsLost;i++){
                addBomb({0.0+rand() % WINDOW_X, PLAY_Y_HEIGHT},{0.0 + rand() % 50,-50.0- (rand()%100)}); // spawns a new bomb at different location
            }
        }


    }

    // lasso collision handling
    void checkForLasso(Lasso &lasso) {
        for (auto &bomb: bombs) {
            lasso.check_for_bomb(bomb.bomb);
        }
    }

    ~BombManager();
};


#endif //LASSOPROJECT_BOMBMANAGER_H
