//
// Created by sankalp on 06/02/21.
//

#include "GameEngine.h"

//code to improve event cluttering
void pumpEvents(GameEngine *engine){
    XInitThreads();
    while (engine->isRunning){
        XEvent e;
        bool pendingEv = checkEvent(e);

        if(pendingEv){
            engine->eventQueue.push(e);
        }
        sleep(0.4);
    }
} // end of pumpEvents()
void GameEngine::startPumping() {
    // multi threaded solution for event cluttering
    eventThread = new thread(pumpEvents, this);
} // end of start pumping
void GameEngine::handleEvent(){
    char c = '_';
    state.charInput = c;
    // helps save from cluttering events.
    while (!eventQueue.empty()){
        c = ' ';


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
} // end of handleEvent

void GameEngine::cleanup() {
    if(engineCleaned){
        return;
    }
    isRunning = false;
    delete lassoPtr;

    delete magnet;
    magnet = nullptr;
    lassoPtr = nullptr;

    eventThread->join();

    delete eventThread;
    endFrame();
    engineCleaned = true;
} // end of cleanUp()