#include <SDL3/SDL.h>
#include <stdlib.h>

#include "../../include/Yanda_event.h"
#include "Yanda_event_internal.h"

#define EVENT_QUEUE_SIZE 256

static YANDA_Event g_EventQueue[EVENT_QUEUE_SIZE];
static int g_QueueHead = 0;
static int g_QueueTail = 0;

static int Queue_full() {
    return ((g_QueueTail + 1) % EVENT_QUEUE_SIZE) == g_QueueHead;
}

static int Queue_empty() {
    return g_QueueHead == g_QueueTail;
}

static void Queue_push(YANDA_Event *EVENT) {
    if (!Queue_full()) {
        g_EventQueue[g_QueueTail] = *EVENT;
        g_QueueTail = (g_QueueTail + 1) % EVENT_QUEUE_SIZE;
    }
}

static int Queue_pop(YANDA_Event *EVENT) {
    if (Queue_empty()) return 0;

    *EVENT = g_EventQueue[g_QueueHead];
    g_QueueHead = (g_QueueHead + 1) % EVENT_QUEUE_SIZE;

    return 1;
}

void YANDA__PushEventFromSDL(SDL_Event *SDL) {
    YANDA_Event EVENT = {0};

    switch (SDL -> type) {
        case SDL_EVENT_QUIT:
            EVENT.Type = YANDA_EVENT_QUIT;

            break;

        case SDL_EVENT_KEY_DOWN:
            EVENT.Type = YANDA_EVENT_KEY_DOWN;
            EVENT.Key.Keycode = SDL -> key.key;

            break;

        case SDL_EVENT_KEY_UP:
            EVENT.Type = YANDA_EVENT_KEY_UP;
            EVENT.Key.Keycode = SDL -> key.key;

            break;

        case SDL_EVENT_MOUSE_MOTION:
            EVENT.Type = YANDA_EVENT_MOUSE_MOVE;
            EVENT.MouseMove.x = SDL -> motion.x;
            EVENT.MouseMove.y = SDL -> motion.y;

            break;

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            EVENT.Type = YANDA_EVENT_MOUSE_BUTTON_DOWN;
            EVENT.MouseButton.Button = SDL -> button.button;

            break;

        case SDL_EVENT_MOUSE_BUTTON_UP:
            EVENT.Type = YANDA_EVENT_MOUSE_BUTTON_UP;
            EVENT.MouseButton.Button = SDL -> button.button;

            break;

        case SDL_EVENT_WINDOW_RESIZED:
            EVENT.Type = YANDA_EVENT_WINDOW_RESIZED;
            EVENT.WindowResize.WIDTH  = SDL -> window.data1;
            EVENT.WindowResize.HEIGHT = SDL -> window.data2;

            break;

        default:
            return;
    }

    Queue_push(&EVENT);
}

int YANDA_PollEvent(YANDA_Event *OUT) {
    SDL_Event SDL;

    while (SDL_PollEvent(&SDL))
        YANDA__PushEventFromSDL(&SDL);

    return Queue_pop(OUT);
}
