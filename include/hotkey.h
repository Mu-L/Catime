/**
 * @file hotkey.h
 * @brief Hotkey management and configuration dialog
 */

#ifndef HOTKEY_H
#define HOTKEY_H

#include <windows.h>

#define HOTKEY_COUNT 12
#define HOTKEY_EDIT_FIRST IDC_HOTKEY_EDIT1
#define HOTKEY_EDIT_LAST IDC_HOTKEY_EDIT12
#define DIALOG_BG_COLOR RGB(0xF3, 0xF3, 0xF3)
#define BUTTON_BG_COLOR RGB(0xFD, 0xFD, 0xFD)

void ShowHotkeySettingsDialog(HWND hwndParent);
INT_PTR CALLBACK HotkeySettingsDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK HotkeyControlSubclassProc(HWND hwnd, UINT uMsg, WPARAM wParam, 
                                         LPARAM lParam, UINT_PTR uIdSubclass, 
                                         DWORD_PTR dwRefData);

#endif
