#ifndef YANDA_WINDOW_INTERNAL_H
#define YANDA_WINDOW_INTERNAL_H

#include <SDL3/SDL.h>

struct YANDA_Window {
    SDL_Window *SDL_WINDOW;
    int ShouldClose;
};

#endif
