//
// Created by sankalp on 07/02/21.
//

#include "HeartUI.h"

void HeartICON::render() {
    sq2l = sqrt(2) * len;
    // shape of the heart
    double pts_body[6][2] = {{0,         0},
                             {-sq2l,     -sq2l},
                             {-2 * sq2l, 0},
                             {0,         2 * sq2l},
                             {2 * sq2l,  0},
                             {sq2l,      -sq2l}};
    setFill(isFilled);

    //handle filling of heart
    if (isFilled)
        setColor(COLOR("red"), false);
    else
        setColor(COLOR("black"), false);

    reset(offset.x, offset.y, pts_body, 6);
}


HeartUI::HeartUI() {
    maxHearts = 0;
    backDrop.reset(20, 20, 200, 100);
    backDrop.setFill(true);

    backDrop.setColor(COLOR("yellow"));
    hearts.resize(maxHearts);
    heartsLeft = maxHearts;
}


void HeartUI::render(int _heartsLeft, int _maxHearts) {
    heartsLeft = _heartsLeft;

    if (_maxHearts != maxHearts) {
        setMaxHearts(_maxHearts);
    }

    size_t i;

    // display hearts according to no. of lives left + there position
    for (i = 0; i < (size_t) heartsLeft; i++) {
        hearts[i].isFilled = true;
        hearts[i].offset.x = 20 + 2 * hearts[i].sq2l + 5 + i * (hearts[i].sq2l * 4 + 5);
        hearts[i].offset.y = 20 + 5 + hearts[i].sq2l;
        hearts[i].render();
    }
    for (; i < (size_t) maxHearts; i++) {
        hearts[i].isFilled = false;
        hearts[i].offset.x = 20 + 2 * hearts[i].sq2l + 5 + i * (hearts[i].sq2l * 4 + 5);
        hearts[i].offset.y = 20 + 5 + hearts[i].sq2l;
        hearts[i].render();
    }
} // end : render()