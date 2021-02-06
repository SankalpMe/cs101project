#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "CoinManager.h"
#include "bomb.h"
#include "BombManager.h"
#include "GameConstants.h"
#include "GameEngine.h"
using namespace simplecpp;


int main() {
    initCanvas("Loop 'n Loops", WINDOW_X, WINDOW_Y); //this line cant be avoided.

    GameEngine engine;
    engine.init();
    showStartMessage("Brace Your Self!");
    engine.loop();
    exit(0);






    //Utility to handle multiple bombs.
    CoinManager coinManager;
    BombManager bombManager;

    Vector2D startPosition = {400, 300};

    coinManager.addCoin(startPosition, {20, -100});
    coinManager.addCoin({500, PLAY_Y_HEIGHT}, {-20, -120});
    coinManager.addCoin({500, PLAY_Y_HEIGHT}, {20, -120});
    bombManager.addBomb({400,PLAY_Y_HEIGHT},{30,-120});


    // After every COIN_GAP sec, make the bomb jump


    // When t is pressed, throw lasso
    // If lasso within range, make bomb stick
    // When y is pressed, yank lasso
    // When l is pressed, loop lasso
    // When q is pressed, quit

//    while (true) {
//
//
//
//        if(lasso.is_boomed){
//            cout << "Gameover" << endl;
//            break;
//        }
//        XEvent e;
//        bool pendingEv = checkEvent(e);
//        if (pendingEv) {
//            char c = ' ';
//            if (keyPressEvent(e)) {
//                c = charFromEvent(e);
//                c = tolower(c);
//            }
//
//            msg[msg.length() - 1] = c;
//            charPressed.setMessage(msg);
//            switch (c) {
//                case 'k':
//                    lasso.unpause();
//                    break;
//                case 'm':
//                    lasso.yank();
//                    break;
//                case 'l':
//                    if (!lasso.isLassoLoped() && !lasso.isPaused()) {
//                        lasso.loopit();
//
//                        coinManager.checkForLasso(lasso);
//                        bombManager.checkForLasso(lasso);
//
//                        wait(STEP_TIME * 5);
//                    }
//                    break;
//                case 'a':
//                    if (lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG); }
//                    break;
//                case 'd':
//                    if (lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
//                    break;
//                case 's':
//                    if (lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
//                    break;
//                case 'w':
//                    if (lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
//                    break;
//                case 'q':
//                    exit(0);
//                default:
//                    break;
//            }
//        }
//
//        lasso.nextStep(stepTime);
//
//        coinManager.stepCoins(stepTime, currTime);
//        bombManager.stepBombs(stepTime,currTime);
//
//        sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
//        coinScore.setMessage(coinScoreStr);
//
//        stepCount++;
//        currTime += stepTime;
//        wait(stepTime);
//    } // End for(;;)
//    showBombBoom("GAME OVER !");

} // End main_program
