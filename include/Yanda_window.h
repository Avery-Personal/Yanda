#ifndef YANDA_WINDOW_H
#define YANDA_WINDOW_H

#include "../src/Yanda.h"

YANDA_Window* YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT);
void YANDA_DestroyWindow(YANDA_Window *WINDOW);

int YANDA_IsWindowOpen(YANDA_Window *WINDOW);
void YANDA_PollEvents(YANDA_Window *WINDOW);

#endif
