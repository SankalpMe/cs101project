//
// Created by sankalp on 09/02/21.
//

#include "Magnet.h"


void Magnet::attract(Lasso *lasso, double step_time) {
    vector<CoinInfo> &coins = coinManager->coins;

    //dcircle.reset(lasso->getXPosition(),lasso->getYPosition(),magDist);

    // iterate over all coins
    for (auto &cinfo: coins) {
        Vector2D cpos = cinfo.coin->getPosition();
        Vector2D lpos = lasso->getPosition();
        double dist = (lpos - cpos).magnitude(); // calculate distance
        Vector2D compAccel = (lpos - cpos) * magnetStrength; // calculate acceleration value

        if (dist <= magDist)
            cinfo.coin->setVelocity(compAccel); // apply force if in appropriate distance

    }
}