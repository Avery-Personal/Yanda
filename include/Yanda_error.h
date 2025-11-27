#ifndef YANDA_ERROR_H
#define YANDA_ERROR_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum {
    YAN_SUCCESS = 0,
    YAN_FAIL,
    YAN_NOT_INITIALIZED,
    YAN_ALREADY_INITIALIZED,
    YAN_INVALID_ARGUMENT,
    YAN_NULL_POINTER,
    YAN_PLATFORM_ERROR,
    YAN_OUT_OF_MEMORY,
    YAN_SDL_ERROR,
    YAN_UNKNOWN,
} YAN_ErrorCode;

YAN_ErrorCode YANDA_GetLastError(void);
const char* YANDA_GetErrorString(YAN_ErrorCode CODE);
void YANDA_PrintError(void);

#ifdef __cplusplus
}
#endif

#endif
