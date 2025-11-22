#include <stdlib.h>
#include <SDL3/SDL.h>

#include "../../include/Yanda_window.h"
#include "Yanda_window_internal.h"

YANDA_Window *YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT) {
    YANDA_Window *WINDOW = malloc(sizeof(YANDA_Window));

    WINDOW -> SDL_WINDOW = SDL_CreateWindow(Name, WIDTH, HEIGHT, 0);
    WINDOW -> ShouldClose = 0;

    return WINDOW;
}

void YANDA_DestroyWindow(YANDA_Window *WINDOW) {
    if (!WINDOW) return;

    SDL_DestroyWindow(WINDOW -> SDL_WINDOW);

    free(WINDOW);
}

int YANDA_ShouldClose(YANDA_Window *WINDOW) {
    return WINDOW -> ShouldClose;
}

void YANDA_PollEvents(YANDA_Window *WINDOW) {
    SDL_Event EVENT;

    while (SDL_PollEvent(&EVENT)) {
        if (EVENT.type == SDL_EVENT_QUIT) {
            WINDOW -> ShouldClose = 1;
        }
    }
}