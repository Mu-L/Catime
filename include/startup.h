/**
 * @file startup.h
 * @brief Windows startup integration and launch mode management
 */

#ifndef STARTUP_H
#define STARTUP_H

#include <windows.h>
#include <shlobj.h>

BOOL IsAutoStartEnabled(void);
BOOL CreateShortcut(void);
BOOL RemoveShortcut(void);
BOOL UpdateStartupShortcut(void);
void ApplyStartupMode(HWND hwnd);

#endif
