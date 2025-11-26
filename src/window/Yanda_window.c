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

static void YANDA_ApplyWindowSettings(YANDA_Window* WINDOW) {
    if (!WINDOW || !WINDOW -> SDL_WINDOW) return;

    if (WINDOW -> Settings.Fullscreen) {
        SDL_SetWindowFullscreen(WINDOW -> SDL_WINDOW, SDL_WINDOW_FULLSCREEN);
    } else {
        SDL_SetWindowFullscreen(WINDOW -> SDL_WINDOW, 0);
    }

    SDL_SetWindowResizable(WINDOW -> SDL_WINDOW, WINDOW -> Settings.Resizable);

    if (WINDOW -> Settings.Visible) {
        SDL_ShowWindow(WINDOW -> SDL_WINDOW);
    } else {
        SDL_HideWindow(WINDOW -> SDL_WINDOW);
    }

    SDL_SetWindowSize(WINDOW -> SDL_WINDOW, WINDOW -> Settings.Width, WINDOW -> Settings.Height);
}

YANDA_Window *YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT) {
    YANDA_Window *WINDOW = malloc(sizeof(YANDA_Window));

    WINDOW -> SDL_WINDOW = SDL_CreateWindow(Name, WIDTH, HEIGHT, 0);
    if (!WINDOW -> SDL_WINDOW) {
        free(WINDOW);

        return NULL;
    }
    
    WINDOW -> ShouldClose = 0;

    WINDOW -> Settings.Width = WIDTH;
    WINDOW -> Settings.Height = HEIGHT;
    WINDOW -> Settings.Resizable = 1;
    WINDOW -> Settings.Fullscreen = 0;
    WINDOW -> Settings.Visible = 1;
    WINDOW -> Renderer = NULL;

    YANDA_ApplyWindowSettings(WINDOW);

    return WINDOW;
}

void YANDA_DestroyWindow(YANDA_Window *WINDOW) {
    if (!WINDOW) return;

    SDL_DestroyWindow(WINDOW -> SDL_WINDOW);

    free(WINDOW);
}

int YANDA_GetWindowWidth(YANDA_Window *WINDOW) {
    int WIDTH, HEIGHT;

    SDL_GetWindowSize(WINDOW -> SDL_WINDOW, &WIDTH, &HEIGHT);

    return WIDTH;
}

int YANDA_GetWindowHeight(YANDA_Window *WINDOW) {
    int WIDTH, HEIGHT;

    SDL_GetWindowSize(WINDOW -> SDL_WINDOW, &WIDTH, &HEIGHT);

    return HEIGHT;
}

int YANDA_GetWindowSize(YANDA_Window *WINDOW) {
    int WIDTH, HEIGHT;

    SDL_GetWindowSize(WINDOW -> SDL_WINDOW, &WIDTH, &HEIGHT);
    
    return WIDTH, HEIGHT;
}

int YANDA_ShouldClose(YANDA_Window *WINDOW) {
    return WINDOW -> ShouldClose;
}

void YANDA_SetFullscreen(YANDA_Window* WINDOW, int Fullscreen) {
    if (!WINDOW) return;

    WINDOW -> Settings.Fullscreen = Fullscreen;
    
    YANDA_ApplyWindowSettings(WINDOW);
}

void YANDA_SetWindowResizable(YANDA_Window* WINDOW, int Resizable) {
    if (!WINDOW) return;

    WINDOW -> Settings.Resizable = Resizable;

    YANDA_ApplyWindowSettings(WINDOW);
}

void YANDA_ShowWindow(YANDA_Window* WINDOW) {
    if (!WINDOW) return;

    WINDOW -> Settings.Visible = 1;

    YANDA_ApplyWindowSettings(WINDOW);
}

void YANDA_HideWindow(YANDA_Window* WINDOW) {
    if (!WINDOW) return;

    WINDOW -> Settings.Visible = 0;

    YANDA_ApplyWindowSettings(WINDOW);
}

void YANDA_SetWindowSize(YANDA_Window* WINDOW, int WIDTH, int HEIGHT) {
    if (!WINDOW) return;
    
    WINDOW -> Settings.Width = WIDTH;
    WINDOW -> Settings.Height = HEIGHT;

    YANDA_ApplyWindowSettings(WINDOW);
}

int YANDA_Update(YANDA_Window *WINDOW) {
    YANDA_Event EVENT;

    while (YANDA_PollEvent(&EVENT)) {
        if (EVENT.Type == YANDA_EVENT_QUIT) {
            WINDOW -> ShouldClose = 1;
        }

        YANDA__InputProcessEvent(&EVENT);
    }
    
    return !YANDA_ShouldClose(WINDOW);
}

void YANDA_Run(YANDA_Window *WINDOW, void (*Callback)(void)) {
    while (YANDA_Update(WINDOW)) {
        Callback();
    }
}