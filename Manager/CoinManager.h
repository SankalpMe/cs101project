//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_COINMANAGER_H
#define LASSOPROJECT_COINMANAGER_H

#include "GameObjects/coin/coin.h"
#include "GameObjects/lasso/lasso.h"
#include <vector>
#include "Misc/GameConstants.h"

//class to manage multiple bombs

struct CoinInfo {
    Coin *coin;
    double endTime;
};

class CoinManager {


public:
    vector<CoinInfo> coins; //for magnet class.
    bool allowCoinRespawn;
    bool insaneMode;
    double speedFactor;

    CoinManager(bool respawnPerm = true) {
        allowCoinRespawn = respawnPerm;
        insaneMode = false;
        speedFactor = 1.0;
    }

    //Add Coin To Game
    void addCoin(Vector2D position, Vector2D velocity = {0, -10});


    void addRandomCoin(int ncoins = 1); //adds random coin to game
    void pauseAllCoin() {
        for (auto &coin: coins) {
            coin.coin->pause();
        }
    }

    void resumeAllCoins() {
        for (auto &coin: coins) {
            coin.coin->unpause();
        }
    }

    //Handle game event steps for all bombs.
    void stepCoins(float timeStep, double currentTime);

    //handle lasso checking for all coins
    void checkForLasso(Lasso &lasso) {
        for (auto &coin: coins) {
            lasso.check_for_coin(coin.coin);
        }
    }

    ~CoinManager();
};


#endif //LASSOPROJECT_COINMANAGER_H
