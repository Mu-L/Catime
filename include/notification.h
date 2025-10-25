/**
 * @file notification.h
 * @brief Multi-modal notification system: toast, modal, tray
 */

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <windows.h>
#include "config.h"

typedef enum {
    ANIM_FADE_IN,
    ANIM_VISIBLE,
    ANIM_FADE_OUT,
} AnimationState;

extern int NOTIFICATION_TIMEOUT_MS;

void ShowNotification(HWND hwnd, const wchar_t* message);
void ShowToastNotification(HWND hwnd, const wchar_t* message);
void ShowModalNotification(HWND hwnd, const wchar_t* message);
void CloseAllNotifications(void);

#endif
