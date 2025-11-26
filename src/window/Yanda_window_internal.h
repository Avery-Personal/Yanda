/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_window_internal.h (Internalized Header File)
 * Module Type: Core Utility / System Internals
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for the Yanda_window.c file to get internal data user(s) won't use/see.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#ifndef YANDA_WINDOW_INTERNAL_H
#define YANDA_WINDOW_INTERNAL_H

#include <SDL3/SDL.h>

typedef struct {
    int Width;
    int Height;

    int Resizable;
    int Fullscreen;
    int Visible;
} YANDA_WindowSettings;

struct YANDA_Window {
    SDL_Window *SDL_WINDOW;
    
    int ShouldClose;
    
    YANDA_WindowSettings Settings;

    void *Renderer;
};

#endif
