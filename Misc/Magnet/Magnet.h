//
// Created by sankalp on 09/02/21.
//

#ifndef LASSOPROJECT_MAGNET_H
#define LASSOPROJECT_MAGNET_H

#include "Manager/CoinManager.h"

class Magnet {
public:
    CoinManager *coinManager;
    double magDist;
    double gravStrength;
    Circle dcircle;
public:
    Magnet() {
        magDist = 100;
        gravStrength = 0.5;
    }

    void bindCoinManager(CoinManager *_coinManager) {
        coinManager = _coinManager;
    }

    void attract(Lasso *lasso, double step_time) {
        vector<CoinInfo> &coins = coinManager->coins;

        //dcircle.reset(lasso->getXPosition(),lasso->getYPosition(),magDist);

        for (auto &cinfo: coins) {
            Vector2D cpos = cinfo.coin->getPosition();
            Vector2D lpos = lasso->getPosition();
            double dist = (lpos - cpos).magnitude();
            Vector2D compAccel = (lpos - cpos) * gravStrength;

            if (dist <= magDist)
                cinfo.coin->setVelocity(compAccel);

        }
    }


};


#endif //LASSOPROJECT_MAGNET_H
