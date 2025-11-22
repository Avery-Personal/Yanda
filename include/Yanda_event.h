/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_event.h (Extenstion Header File)
 * Module Type: Core Utility / System Header EXTENSION
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for the uhhhh, i forgot ngl. It serves for detecting a change in input, or when you recieve one, different from input that checks while something is true/happening, instead of when it does happen.
    *
    *   Events - Do something when something changes
    *   Input - Check every frame for an input and do something when it is true/happening.
    * 
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#ifndef YANDA_EVENT_H
#define YANDA_EVENT_H

typedef enum {
    YANDA_EVENT_NONE,
    YANDA_EVENT_QUIT,
    YANDA_EVENT_KEY_DOWN,
    YANDA_EVENT_KEY_UP,
    YANDA_EVENT_MOUSE_MOVE,
    YANDA_EVENT_MOUSE_BUTTON_DOWN,
    YANDA_EVENT_MOUSE_BUTTON_UP,
    YANDA_EVENT_WINDOW_RESIZED
} YANDA_EventType;

typedef struct {
    int Keycode;
} YANDA_KeyEvent;

typedef struct {
    int x, y;
} YANDA_MouseMoveEvent;

typedef struct {
    int Button;
} YANDA_MouseButtonEvent;

typedef struct {
    int WIDTH, HEIGHT;
} YANDA_WindowResizeEvent;

typedef struct {
    YANDA_EventType Type;

    union {
        YANDA_KeyEvent Key;
        YANDA_MouseMoveEvent MouseMove;
        YANDA_MouseButtonEvent MouseButton;
        YANDA_WindowResizeEvent WindowResize;
    };
} YANDA_Event;

int YANDA_PollEvent(YANDA_Event *OUT);

#endif
