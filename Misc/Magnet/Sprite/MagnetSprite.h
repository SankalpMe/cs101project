//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_MAGNETSPRITE_H
#define LASSOPROJECT_MAGNETSPRITE_H

#include "GameObjects/MO/MovingObject.h"

class MagnetSprite: MovingObject {
    Rectangle br,lr,rr,tlr,trr;

    void init(){
        br.reset(0,0,20,10);
        addPart(&br);
    }
};


#endif //LASSOPROJECT_MAGNETSPRITE_H
