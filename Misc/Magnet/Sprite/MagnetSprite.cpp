//
// Created by sankalp on 13/02/21.
//

#include "MagnetSprite.h"

void MagnetSprite::init() {
    t.reset(0, 0, "M");
    t.setColor(COLOR("red"));
    addPart(&t);

    unpause();
}