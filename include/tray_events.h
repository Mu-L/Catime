/**
 * @file tray_events.h
 * @brief Tray icon event handlers
 */

#ifndef CLOCK_TRAY_EVENTS_H
#define CLOCK_TRAY_EVENTS_H

#include <windows.h>

void HandleTrayIconMessage(HWND hwnd, UINT uID, UINT uMouseMsg);
void TogglePauseResumeTimer(HWND hwnd);
void SetStartupMode(HWND hwnd, const char* mode);
void OpenUserGuide(void);
void OpenSupportPage(void);
void OpenFeedbackPage(void);

#endif
