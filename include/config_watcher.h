/**
 * @file config_watcher.h
 * @brief Configuration file change monitoring
 */

#ifndef CONFIG_WATCHER_H
#define CONFIG_WATCHER_H

#include <windows.h>

void ConfigWatcher_Start(HWND hwnd);
void ConfigWatcher_Stop(void);

#endif
