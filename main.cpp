#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "CoinManager.h"
#include "bomb.h"
using namespace simplecpp;

main_program {

    initCanvas("Lasso", WINDOW_X, WINDOW_Y);
    int stepCount = 0;
    float stepTime = STEP_TIME;
    float runTime = -1; // sec; -ve means infinite
    float currTime = 0;

    // Draw lasso at start position
    double release_speed = INIT_RELEASE_SPEED; // m/s
    double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees


    Lasso lasso(release_speed, release_angle_deg, {0, LASSO_G}, true);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR("blue"));
    Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
    b2.setColor(COLOR("blue"));

    string msg("Cmd: _");
    Text charPressed(PLAY_X_START + 50, PLAY_Y_HEIGHT + 20, msg);
    char coinScoreStr[256];
    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    Text coinScore(PLAY_X_START + 50, PLAY_Y_HEIGHT + 50, coinScoreStr);

    //Utility to handle multiple coins.
    CoinManager coinManager;

    Vector2D startPosition = {400, 300};

    coinManager.addCoin(startPosition, {20, -100});
    coinManager.addCoin({500, PLAY_Y_HEIGHT}, {-20, -120});
    coinManager.addCoin({500, PLAY_Y_HEIGHT}, {20, -120});

    Bomb bb({200,200},{10,20},{0,10});
    bb.init();
    bb.unpause();
    // After every COIN_GAP sec, make the coin jump


    // When t is pressed, throw lasso
    // If lasso within range, make coin stick
    // When y is pressed, yank lasso
    // When l is pressed, loop lasso
    // When q is pressed, quit

    while (true) {
        bb.nextStep(stepTime);
        if(bb.getYPosition() > PLAY_Y_HEIGHT){
            bb.reset();
        }

        if ((runTime > 0) && (currTime > runTime)) { break; }

        XEvent e;
        bool pendingEv = checkEvent(e);
        if (pendingEv) {
            char c = ' ';
            if (keyPressEvent(e)) {
                c = charFromEvent(e);
                c = tolower(c);
            }

            msg[msg.length() - 1] = c;
            charPressed.setMessage(msg);
            switch (c) {
                case 'k':
                    lasso.unpause();
                    break;
                case 'm':
                    lasso.yank();
                    break;
                case 'l':
                    if (!lasso.isLassoLoped() && !lasso.isPaused()) {
                        lasso.loopit();
                        coinManager.checkForLasso(lasso);
                        wait(STEP_TIME * 5);
                    }
                    break;
                case 'a':
                    if (lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG); }
                    break;
                case 'd':
                    if (lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
                    break;
                case 's':
                    if (lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
                    break;
                case 'w':
                    if (lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
                    break;
                case 'q':
                    exit(0);
                default:
                    break;
            }
        }

        lasso.nextStep(stepTime);

        coinManager.stepCoins(stepTime, currTime);

        sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
        coinScore.setMessage(coinScoreStr);

        stepCount++;
        currTime += stepTime;
        wait(stepTime);
    } // End for(;;)

    wait(3);
} // End main_program
