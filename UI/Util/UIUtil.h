//
// Created by sankalp on 07/02/21.
//

#ifndef LASSOPROJECT_UIUTIL_H
#define LASSOPROJECT_UIUTIL_H


#include <simplecpp>
#include "Misc/GameConstants.h"

void showBombBoom(string msg); // to show boom effect

void showStartMessage(string msg); // shows start message

void showAlert(string msg); // alert user about something

void showSmartAlert(string msg); // multirow alert
bool showConfirmAlert(string msg); // confirmation dialog box
void showControls(); // show in game controls.

bool waitForKeyAndMouse(); // returns true if any key / mouse event caught
#endif //LASSOPROJECT_UIUTIL_H
