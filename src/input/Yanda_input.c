/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_input.c (Primary Header Ext File)
 * Module Type: Core Utility / System Header EXTENSION
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for the main Yanda_input.h header to declare the function(s)/initialized content that Yanda inputs use.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#include "../../include/Yanda_input.h"

#define KEY_MAX 512
static int KeyState[KEY_MAX];

#define MOUSE_BUTTON_MAX 8
static int MouseButtons[MOUSE_BUTTON_MAX];
static int MouseX = 0;
static int MouseY = 0;

int YANDA_InputIsKeyDown(int Key) {
    if (Key < 0 || Key >= KEY_MAX) return 0;

    return KeyState[Key];
}

int YANDA_InputIsMouseDown(int Button) {
    if (Button < 0 || Button >= MOUSE_BUTTON_MAX) return 0;

    return MouseButtons[Button];
}

void YANDA_InputGetMousePosition(int *x, int *y) {
    if (x) *x = MouseX;
    if (y) *y = MouseY;
}

void YANDA__InputProcessEvent(YANDA_Event *EVENT) {
    switch (EVENT -> Type) {
        case YANDA_EVENT_KEY_DOWN:
            KeyState[EVENT -> Key.Keycode] = 1;

            break;

        case YANDA_EVENT_KEY_UP:
            KeyState[EVENT -> Key.Keycode] = 0;

            break;

        case YANDA_EVENT_MOUSE_MOVE:
            MouseX = EVENT -> MouseMove.x;
            MouseY = EVENT -> MouseMove.y;

            break;

        case YANDA_EVENT_MOUSE_BUTTON_DOWN:
            MouseButtons[EVENT -> MouseButton.Button] = 1;

            break;

        case YANDA_EVENT_MOUSE_BUTTON_UP:
            MouseButtons[EVENT -> MouseButton.Button] = 0;

            break;
    }
}
