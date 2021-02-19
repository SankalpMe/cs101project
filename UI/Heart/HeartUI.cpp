//
// Created by sankalp on 07/02/21.
//

#include "HeartUI.h"

void HeartUI::render(int _heartsLeft, int _maxHearts) {
    heartsLeft = _heartsLeft;

    if (_maxHearts != maxHearts) {
        setMaxHearts(_maxHearts);
    }

    int i;
    for (i = 0; i < heartsLeft; i++) {
        hearts[i].isFilled = true;
        hearts[i].offset.x = 20 + 2 * hearts[i].sq2l + 5 + i * (hearts[i].sq2l * 4 + 5);
        hearts[i].offset.y = 20 + 5 + hearts[i].sq2l;
        hearts[i].render();
    }
    for (i; i < maxHearts; i++) {
        hearts[i].isFilled = false;
        hearts[i].offset.x = 20 + 2 * hearts[i].sq2l + 5 + i * (hearts[i].sq2l * 4 + 5);
        hearts[i].offset.y = 20 + 5 + hearts[i].sq2l;
        hearts[i].render();
    }
} // end : render()