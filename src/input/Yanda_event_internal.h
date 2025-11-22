/*
 * ASUKA COSA Unified System Library | YANDA COSWA Windowing Library
 * Copyright (c) 2025 ASUKA Development Team
 *
 * Component: Yanda_event_internal.h (Internalized Header File)
 * Module Type: Core Utility / System Internals
 * Version: 1.0.0
 * 
 * Licensed under the MIT License.
 * 
 * See the LICENSE file for full terms.
*/

/*

    * Description:
    *   This file is the created for the Yanda_event.c file to get internal data user(s) won't use/see.
    *
    * Created: 2025-11-21
    * Last Modified: 2025-11-21

*/


#ifndef YANDA_EVENT_INTERNAL_H
#define YANDA_EVENT_INTERNAL_H

#include <SDL3/SDL.h>
#include "../../include/Yanda_event.h"

void YANDA__PushEventFromSDL(SDL_Event *SDL);

#endif
