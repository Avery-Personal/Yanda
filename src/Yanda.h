/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda.h (Primary Header File)
 * Module Type: Core Utility / System Header
 * Version: 1.0.4
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the main header used by the user for all top-level functions.
    *   It includes all windowing, audio, input, and other base functionalities, with other specified ones in the ones with the weird names. 
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/

#ifndef YANDA_H
#define YANDA_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "../include/Yanda_event.h"

typedef struct YANDA_Window YANDA_Window;

void YANDA_Initialize(void);
void YANDA_Shutdown(void);

// Windowing specific

YANDA_Window *YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT);
void YANDA_DestroyWindow(YANDA_Window *WINDOW);

int YANDA_ShouldClose(YANDA_Window *WINDOW);
int YANDA_Update(YANDA_Window *WINDOW);
void YANDA_Run(YANDA_Window *WINDOW, void (*Callback)(void));

#define YANDA_MainLoop(WINDOW) while (YANDA_Update(WINDOW));

int YANDA_GetWindowWidth(YANDA_Window *WINDOW);
int YANDA_GetWindowHeight(YANDA_Window *WINDOW);
int YANDA_GetWindowSize(YANDA_Window *WINDOW);

#ifdef __cplusplus
}
#endif

#endif 
