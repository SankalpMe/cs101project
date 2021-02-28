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
    int killedCoins = 0;
    //handle killing coins
    if (!allowCoinRespawn) {
        // delete all lost coins
        vector<CoinInfo> newcoins;
        for (auto &coin: coins) {
            if (!coin.coin->destroyed) {
                newcoins.push_back(coin);
            } else {
                delete coin.coin;
                killedCoins++;
            }

        }

        coins = newcoins;
    } else
    if (insaneMode) {
        // delete all lost coins
        vector<CoinInfo> newcoins;
        for (auto &coin: coins) {
            if (!coin.coin->destroyed) {
                newcoins.push_back(coin);
            } else {
                delete coin.coin;
                killedCoins++;
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

    // spawn all killed coins:

    for(int i = 0 ; i < killedCoins;i++){
        addRandomCoin();
    }


}

void CoinManager::addRandomCoin(int ncoins) {
    repeat(ncoins){
        double xpos = PLAY_X_START + rand() % (WINDOW_X - 100 - PLAY_X_START);

        double xvel = -50.0 + rand() % 100;
        double yvel = -70.0 - rand() % 80;
        xvel *= speedFactor;
        yvel *= speedFactor;
        addCoin({xpos, PLAY_Y_HEIGHT}, {xvel, yvel});
    }
}

