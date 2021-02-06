#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "CoinManager.h"
#include "bomb.h"
#include "BombManager.h"
using namespace simplecpp;

//simple functions to show alerts
void showAlert(string text,Color col=COLOR("red") ,int delay=5){

    Rectangle box(WINDOW_X/2,WINDOW_Y/2,textWidth(text)*2,textHeight()*2);
    box.setFill(true);
    box.setColor(COLOR("yellow"));

    Text t;
    t.reset(WINDOW_X/2,WINDOW_Y/2,text);
    t.setColor(COLOR("red"));
    t.setScale(3);

    repeat(delay){
        box.setScale(1.3);
        wait(0.2);
        box.setScale(1);
        wait(0.2);
    }


}//end : showAlert
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

    while (true) {


        if ((runTime > 0) && (currTime > runTime)) { break; }
        if(lasso.is_boomed){
            cout << "Gameover" << endl;
            break;
        }
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
                        bombManager.checkForLasso(lasso);

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
        bombManager.stepBombs(stepTime,currTime);

        sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
        coinScore.setMessage(coinScoreStr);

        stepCount++;
        currTime += stepTime;
        wait(stepTime);
    } // End for(;;)
    showAlert("GAME OVER !");

} // End main_program
