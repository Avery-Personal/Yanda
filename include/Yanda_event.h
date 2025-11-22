#ifndef YANDA_EVENT_H
#define YANDA_EVENT_H

typedef enum {
    YANDA_EVENT_NONE,
    YANDA_EVENT_QUIT,
    YANDA_EVENT_KEY_DOWN,
    YANDA_EVENT_KEY_UP,
    YANDA_EVENT_MOUSE_MOVE,
    YANDA_EVENT_MOUSE_BUTTON_DOWN,
    YANDA_EVENT_MOUSE_BUTTON_UP,
    YANDA_EVENT_WINDOW_RESIZED
} YANDA_EventType;

typedef struct {
    int Keycode;
} YANDA_KeyEvent;

typedef struct {
    int x, y;
} YANDA_MouseMoveEvent;

typedef struct {
    int Button;
} YANDA_MouseButtonEvent;

typedef struct {
    int WIDTH, HEIGHT;
} YANDA_WindowResizeEvent;

typedef struct {
    YANDA_EventType Type;

    union {
        YANDA_KeyEvent Key;
        YANDA_MouseMoveEvent MouseMove;
        YANDA_MouseButtonEvent MouseButton;
        YANDA_WindowResizeEvent WindowResize;
    };
} YANDA_Event;

int YANDA_PollEvent(YANDA_Event *OUT);

#endif
