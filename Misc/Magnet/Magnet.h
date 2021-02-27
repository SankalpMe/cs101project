//
// Created by sankalp on 09/02/21.
//

#ifndef LASSOPROJECT_MAGNET_H
#define LASSOPROJECT_MAGNET_H

#include "Manager/CoinManager.h"

class Magnet {
public:
    CoinManager *coinManager; // coinManager ptr to apply force on coins
    double magDist; // distance till which field has influence
    double magnetStrength; // magnet pull strength
public:
    Magnet() {
        magDist = 100;
        magnetStrength = 0.5;
    }

    // tie the coin manager to the magnet
    void bindCoinManager(CoinManager *_coinManager) {
        coinManager = _coinManager;
    }

    void attract(Lasso *lasso, double step_time); // attract coins near the lasso


};


#endif //LASSOPROJECT_MAGNET_H
