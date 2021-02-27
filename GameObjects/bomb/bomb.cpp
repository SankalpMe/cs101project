//
// Created by sankalp on 06/02/21.
//

#include "bomb.h"

void Bomb::hide() {
    bomb_circle.hide();
    bomb_fuse.hide();
}

void Bomb::show() {
    bomb_fuse.show();
    bomb_circle.show();
}

void Bomb::buildObject() {
    coin_circle.hide(); // hide coin_circle

    bomb_circle.reset(0, 0, BOMB_SIZE); // new bomb circle
    bomb_circle.setColor(COLOR("black"));
    bomb_circle.setFill(true);

    bomb_fuse.reset(0, 0, 0, 10);
    bomb_fuse.setThickness(2);
    bomb_fuse.setColor(COLOR("red"));

    // add combined sprite to the MovingObject
    addPart(&bomb_circle);
    addPart(&bomb_fuse, {0, -10});
    //Note: addPart(sprite,offset={0,0) , offset: Relative position of sprite from MO center.
}