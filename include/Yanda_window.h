/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_window.h (Primary Header File)
 * Module Type: Core Utility / System Header
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the main header used by the user for all top-level windowing specific functions.
    *   It includes all windowing and other base functionalities, alongside window specified functions not found in the default Yanda.h file.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#ifndef YANDA_WINDOW_H
#define YANDA_WINDOW_H

#include "../src/Yanda.h"

YANDA_Window* YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT);
void YANDA_DestroyWindow(YANDA_Window *WINDOW);

int YANDA_IsWindowOpen(YANDA_Window *WINDOW);
void YANDA_PollEvents(YANDA_Window *WINDOW);

#endif
