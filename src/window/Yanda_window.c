/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_window.c (Primary Header Ext File)
 * Module Type: Core Utility / System Header EXTENSION
 * Version: 1.0.1
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for the Yanda_window.h header to declare the function(s).
    *   It includes all windowing and other base functionalities, alongside window specified functions not found in the default Yanda.h file.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#include <stdlib.h>

#include <SDL3/SDL.h>

#include "../../include/Yanda_window.h"
#include "../../include/Yanda_input.h"
#include "Yanda_window_internal.h"

YANDA_Window *YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT) {
    YANDA_Window *WINDOW = malloc(sizeof(YANDA_Window));

    WINDOW -> SDL_WINDOW = SDL_CreateWindow(Name, WIDTH, HEIGHT, 0);
    WINDOW -> ShouldClose = 0;

    return WINDOW;
}

void YANDA_DestroyWindow(YANDA_Window *WINDOW) {
    if (!WINDOW) return;

    SDL_DestroyWindow(WINDOW -> SDL_WINDOW);

    free(WINDOW);
}

int YANDA_ShouldClose(YANDA_Window *WINDOW) {
    return WINDOW -> ShouldClose;
}

int YANDA_Update(YANDA_Window *WINDOW) {
    YANDA_Event EVENT;

    while (YANDA_PollEvent(&EVENT)) {
        YANDA__InputProcessEvent(&EVENT);
    }
    
    return !YANDA_ShouldClose(WINDOW);
}

void YANDA_PollEvents(YANDA_Window *WINDOW) {
    SDL_Event EVENT;

    while (SDL_PollEvent(&EVENT)) {
        if (EVENT.type == SDL_EVENT_QUIT) {
            WINDOW -> ShouldClose = 1;
        }
    }
}