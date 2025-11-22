/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_input.h (Extenstion Header File)
 * Module Type: Core Utility / System Header EXTENSION
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for an extension of the YANDA Event(s). Instead of checking for when something changes/happens and does something when it does, it checks every frame for input of a certain key/input.
    * 
    *   Events - Do something when something changes
    *   Input - Check every frame for an input and do something when it is true/happening.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#ifndef YANDA_INPUT_H
#define YANDA_INPUT_H

#include "Yanda_event.h"

int YANDA_InputIsKeyDown(int Key);
void YANDA_InputGetMousePosition(int *x, int *y);
int YANDA_InputIsMouseDown(int Button);

void YANDA__InputProcessEvent(YANDA_Event *EVENT);

#endif
