#include "src/Yanda.h"

int main() {
    YANDA_Initialize();

    YANDA_Window *WINDOW = YANDA_CreateWindow("Window Testing", 800, 600);

    while (YANDA_IsWindowOpen(WINDOW)) {
        continue;
    }

    YANDA_DestroyWindow(WINDOW);
    YANDA_Shutdown();
}