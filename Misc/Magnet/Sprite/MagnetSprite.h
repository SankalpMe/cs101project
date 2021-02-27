//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_MAGNETSPRITE_H
#define LASSOPROJECT_MAGNETSPRITE_H

#include "GameObjects/MO/MovingObject.h"


class MagnetSprite : public MovingObject {
    Text t;
public:
    void init();

    MagnetSprite(Vector2D position = {100, 100}) : MovingObject(position, {0, 0}, {0, 0}) {

    }

    void hide() {
        t.hide();
    }

    void show() {
        t.show();
    }
};


#endif //LASSOPROJECT_MAGNETSPRITE_H
