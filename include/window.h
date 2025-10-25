/**
 * @file window.h
 * @brief Main window creation and management
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>

extern int CLOCK_BASE_WINDOW_WIDTH;
extern int CLOCK_BASE_WINDOW_HEIGHT;
extern float CLOCK_WINDOW_SCALE;
extern int CLOCK_WINDOW_POS_X;
extern int CLOCK_WINDOW_POS_Y;
extern BOOL CLOCK_EDIT_MODE;
extern BOOL CLOCK_IS_DRAGGING;
extern POINT CLOCK_LAST_MOUSE_POS;
extern BOOL CLOCK_WINDOW_TOPMOST;
extern RECT CLOCK_TEXT_RECT;
extern BOOL CLOCK_TEXT_RECT_VALID;

#define MIN_SCALE_FACTOR 0.5f
#define MAX_SCALE_FACTOR 100.0f

extern float CLOCK_FONT_SCALE_FACTOR;
extern int CLOCK_BASE_FONT_SIZE;

HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow);
BOOL InitializeApplication(HINSTANCE hInstance);
void SetClickThrough(HWND hwnd, BOOL enable);
void SetBlurBehind(HWND hwnd, BOOL enable);
BOOL InitDWMFunctions(void);
void AdjustWindowPosition(HWND hwnd, BOOL forceOnScreen);
void SaveWindowSettings(HWND hwnd);
void SetWindowTopmost(HWND hwnd, BOOL topmost);
void ReattachToDesktop(HWND hwnd);
BOOL OpenFileDialog(HWND hwnd, wchar_t* filePath, DWORD maxPath);

#endif
