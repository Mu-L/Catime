/**
 * @file audio_player.h
 * @brief Audio playback with fallback: miniaudio → PlaySound → system beep
 */

#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <windows.h>

/**
 * @brief Callback function type for audio playback completion
 * @param hwnd Window handle to notify when playback completes
 */
typedef void (*AudioPlaybackCompleteCallback)(HWND hwnd);

/**
 * @brief Set callback for audio playback completion
 */
void SetAudioPlaybackCompleteCallback(HWND hwnd, AudioPlaybackCompleteCallback callback);

/**
 * @brief Play notification sound with automatic fallback
 */
BOOL PlayNotificationSound(HWND hwnd);

/**
 * @brief Pause currently playing notification sound
 */
BOOL PauseNotificationSound(void);

/**
 * @brief Resume paused notification sound
 */
BOOL ResumeNotificationSound(void);

/**
 * @brief Stop currently playing notification sound
 */
void StopNotificationSound(void);

/**
 * @brief Set audio playback volume (0-100)
 */
void SetAudioVolume(int volume);

#endif