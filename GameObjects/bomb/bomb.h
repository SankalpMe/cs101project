//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_BOMB_H
#define LASSOPROJECT_BOMB_H

#include "GameObjects/coin/coin.h"
#include "Misc/GameConstants.h"

//IN GAME BOMB CLASS : inherits the coin class as similar functionality
class Bomb : public Coin {
    Line bomb_fuse; // bomb fuse wire
    Circle bomb_circle; // bomb circle
public:
    Bomb(const Vector2D &position, const Vector2D &velocity, const Vector2D &acceleration, bool isPaused = true)
            : Coin(position, velocity, acceleration, isPaused) {

    }

    //New object rendering for bomb.
    void buildObject();

    void hide();

    void show();
};


#endif //LASSOPROJECT_BOMB_H
