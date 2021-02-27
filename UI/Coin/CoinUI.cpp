//
// Created by sankalp on 13/02/21.
//

#include "CoinUI.h"

//simplecpp graphics code


CoinUI::CoinUI() {
    coins = 0;

    bdrop.reset(20 + 50, 50 + 10, 100, 20);
    cointext.reset(25 + textWidth("Coins: 0") / 2, 50 + 10, "Coins: 0");
    bdrop.setFill(true);
    bdrop.setColor(COLOR("yellow"));
}

void CoinUI::step() {
    string rstring = "Coins: ";
    rstring += to_string(coins);
    bdrop.reset(20 + (textWidth(rstring) + 10) / 2, 50 + 10, (textWidth(rstring) + 10), 20);
    cointext.setMessage(rstring);
}