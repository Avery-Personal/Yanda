#ifndef YANDA_INPUT_H
#define YANDA_INPUT_H

#include "Yanda_event.h"

int YANDA_InputIsKeyDown(int Key);
void YANDA_InputGetMousePosition(int *x, int *y);
int YANDA_InputIsMouseDown(int Button);

void YANDA__InputProcessEvent(YANDA_Event *EVENT);

#endif
