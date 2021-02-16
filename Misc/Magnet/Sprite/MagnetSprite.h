//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_MAGNETSPRITE_H
#define LASSOPROJECT_MAGNETSPRITE_H

#include "GameObjects/MO/MovingObject.h"


class MagnetSprite: public MovingObject {
    Rectangle br,lr,rr,tlr,trr;
public:
    void init(){
        br.reset(0,0,20,5);
        br.setColor(COLOR("red"));
        br.setFill(true);
        addPart(&br);

        unpause();
    }

    MagnetSprite(Vector2D position = {100,100}): MovingObject(position,{0,0},{0,0}) {

    }
};


#endif //LASSOPROJECT_MAGNETSPRITE_H
