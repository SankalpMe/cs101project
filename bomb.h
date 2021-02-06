//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_BOMB_H
#define LASSOPROJECT_BOMB_H

#include "coin.h"

//inherits coin class
class Bomb: public Coin {
    Line bomb_fuse;
    Circle bomb_circle;
public:
    Bomb(const Vector2D &position, const Vector2D &velocity, const Vector2D &acceleration, bool isPaused=true)
            : Coin(position, velocity, acceleration, isPaused) {

    }
    //New object rendering for bomb.
    void buildObject(){
        bomb_circle.reset(0, 0, 10);
        bomb_circle.setColor(COLOR("black"));

        bomb_circle.setFill(true);
        bomb_fuse.reset(0,0,0,10);
        bomb_fuse.setThickness(2);
        bomb_fuse.setColor(COLOR("red"));
        addPart(&bomb_circle);
        addPart(&bomb_fuse,{0,-10});
    }
};


#endif //LASSOPROJECT_BOMB_H
