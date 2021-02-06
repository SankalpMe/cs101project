//
// Created by sankalp on 07/02/21.
//

#ifndef LASSOPROJECT_HEARTUI_H
#define LASSOPROJECT_HEARTUI_H

#include <simplecpp>
#include "GameConstants.h"
#include "Vector2D.h"


class HeartICON: public Polygon{
public:
    double  len;
    double sq2l;
    bool isFilled ;
    Vector2D offset;
    HeartICON(Vector2D _offset={0,0},double  _len=3){
        len = 3;
        isFilled = true;
        offset = _offset;
        sq2l =sqrt(2) * len;
    }
    void render(){
        sq2l =sqrt(2) * len;
        double pts_body[6][2] = {{0, 0}, {-sq2l, -sq2l}, {-2*sq2l, 0}, {0,2*sq2l},{2*sq2l,0},{sq2l,-sq2l}};
        setFill(isFilled);
        if(isFilled)
        setColor(COLOR("red"), false);
        else
            setColor(COLOR("black"), false);

        reset(offset.x, offset.y,pts_body, 6);
    }
};
class HeartUI {
    Rectangle backDrop;
    vector<HeartICON> hearts;
    int maxHearts;
    int heartsLeft;
public:
    HeartUI(){
        maxHearts = 0;
        backDrop.reset(20,20,200,100);
        backDrop.setFill(true);

        backDrop.setColor(COLOR("yellow"));
        hearts.resize(maxHearts);
        heartsLeft = maxHearts;
    }
    //Code For Rendering The Hearts
    void render(int _heartsLeft){
        heartsLeft = _heartsLeft;
        int i ;
        for( i = 0 ; i < heartsLeft;i++){
            hearts[i].isFilled = true;
            hearts[i].offset.x = 20 + 2*hearts[i].sq2l + 5 + i * (hearts[i].sq2l*4 + 5);
            hearts[i].offset.y = 20 + 5 +hearts[i].sq2l;
            hearts[i].render();
        }
        for(i; i  < maxHearts;i++){
            hearts[i].isFilled = false;
            hearts[i].offset.x = 20 + 2*hearts[i].sq2l + 5 + i * (hearts[i].sq2l*4 + 5);
            hearts[i].offset.y = 20 + 5 +hearts[i].sq2l;
            hearts[i].render();
        }
    }
    //changes maxHearts.
    void setMaxHearts(int _maxHearts){
        maxHearts = _maxHearts;
        backDrop.reset(20+ 3*sqrt(2)*2*maxHearts + 2.5*maxHearts + 2.5,30 ,3*sqrt(2)*4*maxHearts + 5*maxHearts + 5,20);
        hearts.resize(_maxHearts);

    }
};


#endif //LASSOPROJECT_HEARTUI_H
