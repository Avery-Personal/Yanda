# Yanda

**Version:** 0.1.2
**License:** MIT
**Copyright © 2025 ASUKA Development Team**

Yanda is an AIO (All In One) public domain low-level library for creating cross-platform windowing software. Yanda is made in C, and built with the SDL3 library for the backend capabilities.

# Core

## Initialization

Yanda requires for you to initialize the library before any windowing, rendering, inputs, or other operations can occur. This is allowed for Yanda to set up internal memory, timers, platform-specified backends, etc.

```C
void YANDA_Initialize();
void YANDA_Shutdown();
```

> - `YANDA_Initialize` >> Sets up the engine with memory, etc, as previously stated.
> - `YANDA_Shutdown` >> Cleans all engine resources used, recommended to prevent errors.

## Window Management

Windows in Yanda are created with the custom YANDA_Window variable, which allows easy tracking on internal parts.

### Window Creation

```C
YANDA_Window *YANDA_CreateWindow(const char *Name, int WIDTH, int HEIGHT);
void YANDA_DestroyWindow(YANDA_Window *WINDOW);
```

> `YANDA_CreateWindow` >> Returns a handle with a newly created window.
> `YANDA_DestroyWindow` >> Frees all memory and resources associated with a window.

### Window Updates

Window update events on Yanda, are created under the Yanda_event.h, for specified needs. 

```C
YANDA_Window *YANDA_WindowPollEvents(YANDA_Window *window);
YANDA_Window *YANDA_WindowSwapBuffers(YANDA_Window *window);
```

> `YANDA_WindowPollEvents` >> Processes input and OS-level window messages.
> `YANDA_WindowSwapBuffers` >> Swaps the front and back buffers for double-buffered rendering.

## Input System

## Note(s)

None atm...

## License

Licensed under the **MIT License**.  
See [`LICENSE-MIT`](./LICENSES/MIT.md) or the root `LICENSE` file for full terms.