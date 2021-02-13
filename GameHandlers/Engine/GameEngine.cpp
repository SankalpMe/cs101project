//
// Created by sankalp on 06/02/21.
//

#include "GameEngine.h"

void pumpEvents(GameEngine *engine){
    XInitThreads();
    while (engine->isRunning){
        XEvent e;
        bool pendingEv = checkEvent(e);


        sleep(0.4);
    }
}
void GameEngine::startPumping() {

    eventThread = new thread(&GameEngine::loop, this);
    pumpEvents(this);
}
void GameEngine::handleEvent(){
    while (!eventQueue.empty()){
        char c = ' ';

        XEvent e = eventQueue.front();
        eventQueue.pop();
        if (keyPressEvent(e)) {
            c = charFromEvent(e);
            c = tolower(c);
        }

        state.charInput = c;

        switch (c) {
            case 'k':
                lassoPtr->unpause();
                break;
            case 'm':
                lassoPtr->yank();
                break;
            case 'l':
                if (!lassoPtr->isLassoLoped() && !lassoPtr->isPaused()) {
                    lassoPtr->loopit();
                    coinManager->checkForLasso(*lassoPtr);
                    bombManager->checkForLasso(*lassoPtr);

                    wait(STEP_TIME * 5);
                }
                break;
            case 'a':
                if (lassoPtr->isPaused()) { lassoPtr->addAngle(-RELEASE_ANGLE_STEP_DEG); }
                break;
            case 'd':
                if (lassoPtr->isPaused()) { lassoPtr->addAngle(+RELEASE_ANGLE_STEP_DEG); }
                break;
            case 's':
                if (lassoPtr->isPaused()) { lassoPtr->addSpeed(-RELEASE_SPEED_STEP); }
                break;
            case 'w':
                if (lassoPtr->isPaused()) { lassoPtr->addSpeed(+RELEASE_SPEED_STEP); }
                break;
            case 'q':
                isRunning = false;
            default:
                break;
        }
    }
}