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
    CoinManager(bool respawnPerm=true) {
        allowCoinRespawn = respawnPerm;
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

    //Handle game event steps for all bombs.

    void stepCoins(float timeStep, double currentTime) {
        if(!allowCoinRespawn){
            vector<CoinInfo> newcoins;
            for(auto &coin: coins){
                if(!coin.coin->destroyed){
                    newcoins.push_back(coin);
                }else{
                    delete coin.coin;
                }

            }

            coins = newcoins;
        }

        for (auto &coin: coins) {
            coin.coin->nextStep(timeStep);

            if (coin.coin->getYPosition() > PLAY_Y_HEIGHT) {
                coin.coin->hide();
                coin.coin->reset();
                coin.coin->pause();
                coin.endTime = currentTime;
            }

            if (coin.coin->isPaused()) {
                if ((currentTime - coin.endTime) >= COIN_GAP) {
                    coin.coin->show();
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
