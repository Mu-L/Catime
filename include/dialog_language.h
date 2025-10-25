/**
 * @file dialog_language.h
 * @brief Dialog localization support
 */

#ifndef DIALOG_LANGUAGE_H
#define DIALOG_LANGUAGE_H

#include <windows.h>

BOOL InitDialogLanguageSupport(void);
BOOL ApplyDialogLanguage(HWND hwndDlg, int dialogID);

#endif
