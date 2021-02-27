//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_COINUI_H
#define LASSOPROJECT_COINUI_H

#include <simplecpp>

// class renders the no. of coins collected
class CoinUI {

    Rectangle bdrop; // coin ui bg rect
    Text cointext; // coin ui render text

    int coins; // ui state for coin count
public:
    CoinUI();

    void step();

    // sync ui and state coins
    void setCoins(int _coins) {
        coins = _coins;
    } // end : setCoin(...)
};


#endif //LASSOPROJECT_COINUI_H
