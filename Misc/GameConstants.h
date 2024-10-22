/*
 * GameConstants.h
 * Another improvement to the project
 * this header file holds all the important constants requried for the game
 */

#ifndef LASSOPROJECT_GAMECONSTANTS_H
#define LASSOPROJECT_GAMECONSTANTS_H


#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0

#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5

#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define LASSO_G 30
#define COIN_G 30

#define LASSO_SIZE 10
#define LASSO_RADIUS 50

#define COIN_SIZE 5
#define BOMB_SIZE 10

#define MAGNET_GAP 100
#define MAGNET_DURATION 50
#endif //LASSOPROJECT_GAMECONSTANTS_H
