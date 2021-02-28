//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_MAGNETSPRITE_H
#define LASSOPROJECT_MAGNETSPRITE_H

#include "GameObjects/MO/MovingObject.h"


class MagnetSprite : public MovingObject {
    Text t;
    int i = 0;
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

    void step() {
        i++;
        nextStep(0);

        if (i % 2) {
            t.setMessage(" M");
            t.setColor(COLOR("red"));
        } else {
            t.setColor(COLOR("black"));
            t.setMessage("M ");
        }
    }
};


#endif //LASSOPROJECT_MAGNETSPRITE_H
