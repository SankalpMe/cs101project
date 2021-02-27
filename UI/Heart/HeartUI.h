//
// Created by sankalp on 07/02/21.
//

#ifndef LASSOPROJECT_HEARTUI_H
#define LASSOPROJECT_HEARTUI_H

#include <simplecpp>
#include "Misc/GameConstants.h"
#include "Misc/Vector2D/Vector2D.h"

// Each individual heart icon
class HeartICON : public Polygon {
public:
    double len; // heartDraw size len specification
    double sq2l; // calculation simplification 1.414*l
    bool isFilled; // state of heart being filled / empty ( alive / dead )
    Vector2D offset; // offset for rendering

    HeartICON(Vector2D _offset = {0, 0}, double _len = 3) {
        len = 3;
        isFilled = true;
        offset = _offset;
        sq2l = sqrt(2) * len;
    }

    void render(); // renders the heart icon to the screen
};

class HeartUI {
    Rectangle backDrop; // backdrop for the hearts
    vector<HeartICON> hearts; // group of all heart icons
    int maxHearts;
    int heartsLeft;
public:
    HeartUI();

    //Code For Rendering The Hearts
    void render(int _heartsLeft, int _maxHearts);

    //changes maxHearts.
    void setMaxHearts(int _maxHearts) {
        maxHearts = _maxHearts;
        backDrop.reset(20 + 3 * sqrt(2) * 2 * maxHearts + 2.5 * maxHearts + 2.5, 30,
                       3 * sqrt(2) * 4 * maxHearts + 5 * maxHearts + 5, 20);
        hearts.resize(_maxHearts);
    }
};


#endif //LASSOPROJECT_HEARTUI_H
