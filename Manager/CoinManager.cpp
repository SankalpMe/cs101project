//
// Created by sankalp on 06/02/21.
//


#include "CoinManager.h"

CoinManager::~CoinManager() {
    for (auto &coin: coins) {
        delete coin.coin;
    }
}

void CoinManager::addCoin(Vector2D position, Vector2D velocity) {
    Coin *coin = new Coin(position, velocity, {0, COIN_G});
    coin->init();
    coins.push_back({coin, 0});
}

void CoinManager::stepCoins(float timeStep, double currentTime) {
    if (!allowCoinRespawn) {
        // delete all lost coins
        vector<CoinInfo> newcoins;
        for (auto &coin: coins) {
            if (!coin.coin->destroyed) {
                newcoins.push_back(coin);
            } else {
                delete coin.coin;
            }

        }

        coins = newcoins;
    }

    // handle remaining alive coins
    for (auto &coin: coins) {
        coin.coin->nextStep(timeStep);

        // kill coin if out of bound
        if (coin.coin->getYPosition() > PLAY_Y_HEIGHT) {
            coin.coin->hide();
            coin.coin->reset();
            coin.coin->pause();
            coin.endTime = currentTime;
        }

        // delay coin spawn time by a small gap
        if (coin.coin->isPaused()) {
            if ((currentTime - coin.endTime) >= COIN_GAP) {
                coin.coin->show();
                coin.coin->unpause();
            }
        }
    }


}