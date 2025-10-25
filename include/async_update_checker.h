/**
 * @file async_update_checker.h
 * @brief Asynchronous update checking using background threads
 */

#ifndef ASYNC_UPDATE_CHECKER_H
#define ASYNC_UPDATE_CHECKER_H

#include <windows.h>

/**
 * @brief Check for updates asynchronously
 * @param silentCheck TRUE = background check, FALSE = show all dialogs
 */
void CheckForUpdateAsync(HWND hwnd, BOOL silentCheck);

/**
 * @brief Clean up update thread (call on shutdown)
 */
void CleanupUpdateThread(void);

#endif