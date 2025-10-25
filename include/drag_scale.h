/**
 * @file drag_scale.h
 * @brief Window dragging and scaling functionality
 */

#ifndef DRAG_SCALE_H
#define DRAG_SCALE_H

#include <windows.h>

#define SCALE_FACTOR_STEP 1.1f
#define CONFIG_SAVE_DELAY_MS 500
#define TIMER_ID_CONFIG_SAVE 1005
#define TIMER_ID_EDIT_MODE_REFRESH 2001
#define TIMER_REFRESH_INTERVAL_MS 150

extern BOOL PREVIOUS_TOPMOST_STATE;

void StartEditMode(HWND hwnd);
void EndEditMode(HWND hwnd);
void StartDragWindow(HWND hwnd);
void EndDragWindow(HWND hwnd);
BOOL HandleDragWindow(HWND hwnd);
BOOL HandleScaleWindow(HWND hwnd, int delta);
void ScheduleConfigSave(HWND hwnd);

#endif
