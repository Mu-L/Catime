/**
 * @file drawing.h
 * @brief Window rendering and text drawing
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <windows.h>

#define TIME_TEXT_MAX_LEN 50
#define FONT_NAME_MAX_LEN 256
#define TEXT_RENDER_PASSES 8

typedef struct {
    LONGLONG frequency;
    LONGLONG start_time;
    LONGLONG pause_time;
    LONGLONG accumulated_pause;
    int last_ms;
    BOOL is_paused;
} MillisecondTimer;

typedef struct {
    int centerX;
    int centerY;
    HDC hdcMem;
    HBITMAP hbmMem;
    HBITMAP hbmOld;
    HFONT hFont;
    RECT textRect;
    int windowWidth;
    int windowHeight;
} RenderContext;

void HandleWindowPaint(HWND hwnd, PAINTSTRUCT *ps);
void ResetTimerMilliseconds(void);
void PauseTimerMilliseconds(void);

#endif
