/**
 * @file update_checker.h
 * @brief Application update checking
 */

#ifndef UPDATE_CHECKER_H
#define UPDATE_CHECKER_H

#include <windows.h>

void CheckForUpdate(HWND hwnd);
void CheckForUpdateSilent(HWND hwnd, BOOL silentCheck);

#endif
