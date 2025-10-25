/**
 * @file window_procedure.h
 * @brief Main window message handler and hotkey management
 */

#ifndef WINDOW_PROCEDURE_H
#define WINDOW_PROCEDURE_H

#include <windows.h>

#define WM_APP_SHOW_CLI_HELP (WM_APP + 2)
#define WM_APP_QUICK_COUNTDOWN_INDEX (WM_APP + 3)
#define WM_APP_ANIM_PATH_CHANGED (WM_APP + 50)
#define WM_APP_ANIM_SPEED_CHANGED (WM_APP + 51)
#define WM_APP_DISPLAY_CHANGED (WM_APP + 52)
#define WM_APP_TIMER_CHANGED (WM_APP + 53)
#define WM_APP_POMODORO_CHANGED (WM_APP + 54)
#define WM_APP_NOTIFICATION_CHANGED (WM_APP + 55)
#define WM_APP_HOTKEYS_CHANGED (WM_APP + 56)
#define WM_APP_RECENTFILES_CHANGED (WM_APP + 57)
#define WM_APP_COLORS_CHANGED (WM_APP + 58)

#define COPYDATA_ID_CLI_TEXT 0x10010001

#define HOTKEY_ID_SHOW_TIME       100
#define HOTKEY_ID_COUNT_UP        101
#define HOTKEY_ID_COUNTDOWN       102
#define HOTKEY_ID_QUICK_COUNTDOWN1 103
#define HOTKEY_ID_QUICK_COUNTDOWN2 104
#define HOTKEY_ID_QUICK_COUNTDOWN3 105
#define HOTKEY_ID_POMODORO        106
#define HOTKEY_ID_TOGGLE_VISIBILITY 107
#define HOTKEY_ID_EDIT_MODE       108
#define HOTKEY_ID_PAUSE_RESUME    109
#define HOTKEY_ID_RESTART_TIMER   110
#define HOTKEY_ID_CUSTOM_COUNTDOWN 111

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
BOOL RegisterGlobalHotkeys(HWND hwnd);
void UnregisterGlobalHotkeys(HWND hwnd);
void ToggleShowTimeMode(HWND hwnd);
void StartCountUp(HWND hwnd);
void StartDefaultCountDown(HWND hwnd);
void StartPomodoroTimer(HWND hwnd);
void ToggleEditMode(HWND hwnd);
void TogglePauseResume(HWND hwnd);
void RestartCurrentTimer(HWND hwnd);
void StartQuickCountdownByIndex(HWND hwnd, int index);
void CleanupBeforeTimerAction(void);
BOOL StartCountdownWithTime(HWND hwnd, int seconds);
BOOL HandleLanguageSelection(HWND hwnd, UINT menuId);
BOOL HandlePomodoroTimeConfig(HWND hwnd, int selectedIndex);
void GetActiveColor(char* outColor, size_t bufferSize);
void GetActiveFont(char* outFontName, char* outInternalName, size_t bufferSize);
BOOL GetActiveShowMilliseconds(void);

#endif
