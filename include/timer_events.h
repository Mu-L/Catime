/**
 * @file timer_events.h
 * @brief Timer event processing and Pomodoro initialization
 */

#ifndef TIMER_EVENTS_H
#define TIMER_EVENTS_H

#include <windows.h>

#define TIMER_ID_MAIN 1
#define TIMER_ID_TOPMOST_RETRY 999
#define TIMER_ID_VISIBILITY_RETRY 1000
#define TIMER_ID_FORCE_REDRAW 1004
#define TIMER_ID_FONT_VALIDATION 1006

BOOL HandleTimerEvent(HWND hwnd, WPARAM wp);
void ResetMillisecondAccumulator(void);
void InitializePomodoro(void);

#endif
