//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_COINMANAGER_H
#define LASSOPROJECT_COINMANAGER_H

#include "coin.h"
#include "lasso.h"
#include <vector>
//class to manage multiple coins

struct CoinInfo {
    Coin *coin;
    double endTime;
};

class CoinManager {
    vector<CoinInfo> coins;

public:
    CoinManager() {

    }

    //Add Coin To Game
    void addCoin(Vector2D position, Vector2D velocity = {0, -10}) {
        Coin *coin = new Coin(position, velocity, {0, COIN_G});
        coin->init();
        coins.push_back({coin, 0});

    }

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

    //Handle game event steps for all coins.
    void stepCoins(float timeStep, double currentTime) {
        for (auto &coin: coins) {
            coin.coin->nextStep(timeStep);

            if (coin.coin->getYPosition() > PLAY_Y_HEIGHT) {
                coin.coin->reset();
                coin.endTime = currentTime;
            }

            if (coin.coin->isPaused()) {
                if ((currentTime - coin.endTime) >= COIN_GAP) {
                    coin.coin->unpause();
                }
            }
        }


    }

    void checkForLasso(Lasso &lasso) {
        for (auto &coin: coins) {
            lasso.check_for_coin(coin.coin);
        }
    }

    ~CoinManager();
};


#endif //LASSOPROJECT_COINMANAGER_H
