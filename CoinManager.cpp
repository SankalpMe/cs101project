//
// Created by sankalp on 06/02/21.
//


#include "CoinManager.h"

CoinManager::~CoinManager() {
    for (auto &coin: coins) {
        delete coin.coin;
    }
}