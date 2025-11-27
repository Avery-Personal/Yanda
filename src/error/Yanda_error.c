#include <stdlib.h>

#include "../../include/Yanda_error.h"
#include "Yanda_error_internal.h"

static _Thread_local YAN_ErrorCode YANDA_LastError = YAN_SUCCESS;
static _Thread_local char *YANDA_LastErrorMessage = NULL;

static void YANDA__FreeErrorMsg(void) {
    if (YANDA_LastErrorMessage) {
        free(YANDA_LastErrorMessage);

        YANDA_LastErrorMessage = NULL;
    }
}

char *YANDA__SetErrorCode(YAN_ErrorCode CODE, const char* MESSAGE) {
    YANDA_LastError = (YAN_ErrorCode)CODE;

    YANDA__FreeErrorMsg();
    
    if (MESSAGE) {
        size_t len = strlen(MESSAGE) + 1;
        YANDA_LastErrorMessage = (char*)malloc(len);

        if (YANDA_LastErrorMessage) {
            memcpy(YANDA_LastErrorMessage, MESSAGE, len);
        }
    }

    return YANDA_LastErrorMessage;
}

void YANDA__ClearError(void) {
    YANDA_LastError = YAN_SUCCESS;

    YANDA__FreeErrorMsg();
}

YAN_ErrorCode YANDA_GetLastError(void) {
    return YANDA_LastError;
}

const char* YANDA_GetErrorString(YAN_ErrorCode CODE) {
    switch (CODE) {
        case YAN_SUCCESS:
            return "Success";
        case YAN_FAIL:
            return "Unknown failure";
        case YAN_NOT_INITIALIZED:
            return "Yanda has not been initialized";
        case YAN_ALREADY_INITIALIZED:
            return "Yanda already initialized";
        case YAN_INVALID_ARGUMENT:
            return "Invalid argument";
        case YAN_NULL_POINTER:
            return "Null pointer dereference";
        case YAN_PLATFORM_ERROR:
            return "Platform-specific error";
        case YAN_OUT_OF_MEMORY:
            return "Memory allocation failed";
        case YAN_SDL_ERROR:
            return SDL_GetError();
        case YAN_UNKNOWN:
        default:
            return "Unknown Yanda error";
    }
}

void YANDA_PrintError(void) {
    const char *Base = YANDA_GetErrorString(YANDA_LastError);

    if (YANDA_LastErrorMessage) {
        SDL_Log("YANDA ERROR: %s | %s", Base, YANDA_LastErrorMessage);
    } else {
        SDL_Log("YANDA ERROR: %s", Base);
    }
}