//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_COINUI_H
#define LASSOPROJECT_COINUI_H

#include <simplecpp>
class CoinUI {
    int coinsCollected;
    Rectangle bdrop;
    Text cointext;
    Line ld;
    int coins;
public:
    CoinUI(){
        coins = 0;
        ld.setZIndex(1);
        bdrop.reset(20+50,50+10,100,20);
        cointext.reset(25+textWidth("Coins: 0")/2,50+10,"Coins: 0");
        bdrop.setFill(true);
        bdrop.setColor(COLOR("yellow"));
    }
    void step(){

        string rstring = "Coins: ";
        rstring += to_string(coins);
        bdrop.reset(20+(textWidth(rstring)+10)/2,50+10,(textWidth(rstring)+10),20);
        cointext.setMessage(rstring);
    }
    void setCoins(int _coins){
        coins = _coins;
    }
};


#endif //LASSOPROJECT_COINUI_H
