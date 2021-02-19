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
    eventThread = new thread(pumpEvents, this); // multi threaded solution for event cluttering
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
        // handle input key and perform respective actions
        switch (c) {
            case 'c':
                showControls();
                eventQueue = queue<XEvent>(); // clear the event queue
                break;
            case 'k':
                lassoPtr->unpause(); //throws the lasso
                break;
            case 'm':
                lassoPtr->yank(); // pulls the lasso back
                break;
            case 'l':
                // catch the coins
                if (!lassoPtr->isLassoLoped() && !lassoPtr->isPaused()) {
                    lassoPtr->loopit();
                    coinManager->checkForLasso(*lassoPtr); // pull checking for all coins
                    bombManager->checkForLasso(*lassoPtr); // pull checking for all bombs

                    wait(STEP_TIME * 5); // delay for user feedback
                }
                break;
            case 'a':
                // adjusts lasso projection angle
                if (lassoPtr->isPaused()) { lassoPtr->addAngle(-RELEASE_ANGLE_STEP_DEG); }
                break;
            case 'd':
                // adjusts lasso projection angle
                if (lassoPtr->isPaused()) { lassoPtr->addAngle(+RELEASE_ANGLE_STEP_DEG); }
                break;
            case 's':
                // adjusts lasso projection speed
                if (lassoPtr->isPaused()) { lassoPtr->addSpeed(-RELEASE_SPEED_STEP); }
                break;
            case 'w':
                // adjusts lasso projection speed
                if (lassoPtr->isPaused()) { lassoPtr->addSpeed(+RELEASE_SPEED_STEP); }
                break;
            case 'q':
                // quit the game
                isRunning = false;
                quitKey = true;
            default:
                break;
        }
    }
} // end of handleEvent
// cleans up all the pointers and engine init.
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