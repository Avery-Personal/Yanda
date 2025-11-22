#include <SDL3/SDL.h>

#include "../Yanda.h"

static int g_YandaInitialized = 0;

void YANDA_Initialize(void) {
    // At the minute I believe we'll do singular application based initialization.
    if (g_YandaInitialized) return;

    SDL_Init(SDL_INIT_VIDEO);
    g_YandaInitialized = 1;
}

// Think of it like a flip-flop function of Initialize
void YANDA_Shutdown(void) {
    if (!g_YandaInitialized) return;

    SDL_Quit();
    g_YandaInitialized = 0;
}