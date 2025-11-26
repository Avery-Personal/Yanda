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

int YANDA_GetWindowWidth(YANDA_Window *WINDOW);
int YANDA_GetWindowHeight(YANDA_Window *WINDOW);
int YANDA_GetWindowSize(YANDA_Window *WINDOW);

// Window Customization

void YANDA_ShowWindow(YANDA_Window *WINDOW);
void YANDA_HideWindow(YANDA_Window *WINDOW);

void YANDA_CenterWindow(YANDA_Window *WINDOW);
void YANDA_SetWindowPosition(YANDA_Window *WINDOW, int X, int Y);
void YANDA_SetWindowSize(YANDA_Window *WINDOW, int WIDTH, int HEIGHT);

void YANDA_SetWindowResizable(YANDA_Window *WINDOW, int RESIZABLE);
void YANDA_SetFullscreen(YANDA_Window *WINDOW, int ENABLED);

void YANDA_SetWindowTitle(YANDA_Window *WINDOW, const char *TITLE);
void YANDA_SetWindowIcon(YANDA_Window *WINDOW, const char *ICON_PATH);

void YANDA_MaximizeWindow(YANDA_Window *WINDOW);
void YANDA_MinimizeWindow(YANDA_Window *WINDOW);
void YANDA_RestoreWindow(YANDA_Window *WINDOW);

int YANDA_ShouldClose(YANDA_Window *WINDOW);

#endif
