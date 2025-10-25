/**
 * @file dialog_procedure.h
 * @brief Dialog procedures for timer, settings, and info dialogs
 */

#ifndef DIALOG_PROCEDURE_H
#define DIALOG_PROCEDURE_H

#include <windows.h>

INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL ParseTimeInput(const char* input, int* seconds);

void ShowAboutDialog(HWND hwndParent);
INT_PTR CALLBACK AboutDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
void ShowErrorDialog(HWND hwndParent);
INT_PTR ShowFontLicenseDialog(HWND hwndParent);

void ShowPomodoroLoopDialog(HWND hwndParent);
INT_PTR CALLBACK PomodoroLoopDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
void ShowPomodoroComboDialog(HWND hwndParent);

void ShowWebsiteDialog(HWND hwndParent);
void ShowNotificationMessagesDialog(HWND hwndParent);
void ShowNotificationDisplayDialog(HWND hwndParent);
void ShowNotificationSettingsDialog(HWND hwndParent);

void MoveDialogToPrimaryScreen(HWND hwndDlg);

extern HWND g_hwndInputDialog;

#endif
