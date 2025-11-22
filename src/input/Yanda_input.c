#include "../../include/Yanda_input.h"

#define KEY_MAX 512
static int KeyState[KEY_MAX];

#define MOUSE_BUTTON_MAX 8
static int MouseButtons[MOUSE_BUTTON_MAX];
static int MouseX = 0;
static int MouseY = 0;

int YANDA_InputIsKeyDown(int Key) {
    if (Key < 0 || Key >= KEY_MAX) return 0;

    return KeyState[Key];
}

int YANDA_InputIsMouseDown(int Button) {
    if (Button < 0 || Button >= MOUSE_BUTTON_MAX) return 0;

    return MouseButtons[Button];
}

void YANDA_InputGetMousePosition(int *x, int *y) {
    if (x) *x = MouseX;
    if (y) *y = MouseY;
}

void YANDA__InputProcessEvent(YANDA_Event *EVENT) {
    switch (EVENT -> Type) {
        case YANDA_EVENT_KEY_DOWN:
            KeyState[EVENT -> Key.Keycode] = 1;

            break;

        case YANDA_EVENT_KEY_UP:
            KeyState[EVENT -> Key.Keycode] = 0;

            break;

        case YANDA_EVENT_MOUSE_MOVE:
            MouseX = EVENT -> MouseMove.x;
            MouseY = EVENT -> MouseMove.y;

            break;

        case YANDA_EVENT_MOUSE_BUTTON_DOWN:
            MouseButtons[EVENT -> MouseButton.Button] = 1;

            break;

        case YANDA_EVENT_MOUSE_BUTTON_UP:
            MouseButtons[EVENT -> MouseButton.Button] = 0;

            break;
    }
}
