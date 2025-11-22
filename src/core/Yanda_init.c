/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_init.c (Primary Header Ext File)
 * Module Type: Core Utility / System Header EXTENSION
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for the main Yanda.h header to declare the function(s)/initialized content that Yanda uses.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#include <SDL3/SDL.h>

#include "../Yanda.h"

static int g_YandaInitialized = 0;

void YANDA_Initialize(void) {
    // At the minute I believe we'll do singular application based initialization.
    if (g_YandaInitialized) return;

    SDL_Init(SDL_INIT_VIDEO);
    g_YandaInitialized = 1;
}

// Think of it like a flip-flop function of Initialize
void YANDA_Shutdown(void) {
    if (!g_YandaInitialized) return;

    SDL_Quit();
    g_YandaInitialized = 0;
}