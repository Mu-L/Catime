/**
 * @file tray_animation.h
 * @brief Animated tray icon system
 */

#ifndef TRAY_ANIMATION_H
#define TRAY_ANIMATION_H

#include <windows.h>

#define MAX_TRAY_FRAMES 64

void StartTrayAnimation(HWND hwnd, UINT intervalMs);
void StopTrayAnimation(HWND hwnd);
BOOL SetCurrentAnimationName(const char* name);
void StartAnimationPreview(const char* name);
void CancelAnimationPreview(void);
void PreloadAnimationFromConfig(void);
BOOL HandleAnimationMenuCommand(HWND hwnd, UINT id);
void ApplyAnimationPathValueNoPersist(const char* value);
void TrayAnimation_SetBaseIntervalMs(UINT ms);
void TrayAnimation_RecomputeTimerDelay(void);
void TrayAnimation_UpdatePercentIconIfNeeded(void);
void TrayAnimation_SetMinIntervalMs(UINT ms);
BOOL TrayAnimation_HandleUpdateMessage(void);

#endif
