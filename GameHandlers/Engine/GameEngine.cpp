//
// Created by sankalp on 06/02/21.
//

#include "GameEngine.h"

//code to improve event cluttering
void pumpEvents(GameEngine *engine) {
    XInitThreads();
    while (engine->isRunning) {
        XEvent e;
        bool pendingEv = checkEvent(e);

        if (pendingEv) {
            engine->eventQueue.push(e);
        }
        sleep(0.4);
    }
} // end of pumpEvents()
void GameEngine::startPumping() {
    eventThread = new thread(pumpEvents, this); // multi threaded solution for event cluttering
} // end of start pumping
void GameEngine::handleEvent() {
    char c = '_';
    state.charInput = c;
    // helps save from cluttering events.
    while (!eventQueue.empty()) {
        c = ' ';


        XEvent e = eventQueue.front();
        eventQueue.pop();

        if (keyPressEvent(e)) {
            c = charFromEvent(e);
            c = tolower(c);
        }

        state.charInput = c;
        bool ans;
        // handle input key and perform respective actions
        switch (c) {
            case 'c':
                showControls();
                resetEventQueue(); // clear the event queue
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
                ans = showConfirmAlert("Do You Want To Quit Level?"); // confirm from user
                resetEventQueue();
                if (ans) {
                    isRunning = false;
                    quitKey = true;
                }
                break;
            default:
                break;
        }
    }
} // end of handleEvent


// calls many important step functions in the game.
void GameEngine::handleStepUpdates() {

    lassoPtr->nextStep(step.time); //update lasso

    coinManager->stepCoins(step.time, currentTime); //update coins

    bool caughtMagnet = magnetGiver->step(lassoPtr, &state); //magnet catcher
    if (caughtMagnet) {
        magnetGiver->disable(); // disable magnet spawning
        magLastTime = currentTime; // timing delay for next spawning
    };

    if (magnetGiver->disabled) {
        if ((currentTime - magLastTime) > MAGNET_GAP) {
            // find a random location
            double x = 0 + rand() % WINDOW_X;
            double y = 0 + rand() % PLAY_Y_HEIGHT;
            magnetGiver->enable({x, y}); // enable spawning
        }
    }

    bombManager->stepBombs(step.time, currentTime); // update bombs
    if (!lassoPtr->isPaused()) {
        if (state.isMagnetized && state.magnetStepRemaining > 0) {
            magnet->attract(lassoPtr, step.time); // perform magnetic field
        }
    }

    plr.step(); // ui step

    // magnetic effect countdown
    if (state.magnetStepRemaining > 0) {
        state.magnetStepRemaining--;
    } else {
        state.isMagnetized = false;
    }

    // gameLevel timer disabled when set to -10
    if (state.stepRemaining != -10) {
        if (state.stepRemaining < 0) {
            isRunning = false;
            cleanup(); // exit from level
        }
        state.stepRemaining--;
    }

    // exit when target is achieved,  -1 is set when no target.
    if (targetCoins != -1) {
        if (targetCoins <= state.score.GoldCoin) {
            cerr << "Target Complete" << endl;
            isRunning = false;
            cleanup();
        }
    }

    state.health.maxHearts = maxHearts;

}  // end of : handleStepUpdates()

// cleans up all the pointers and engine init.
void GameEngine::cleanup() {
    // cleanup / reset all allocated engine objects...
    if (engineCleaned) {
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

