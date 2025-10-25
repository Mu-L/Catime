/**
 * @file cli.h
 * @brief Command-line interface parsing and help dialog
 */

#ifndef CLI_H
#define CLI_H

#include <windows.h>

/**
 * @brief Show or toggle CLI help dialog
 */
void ShowCliHelpDialog(HWND hwnd);

/**
 * @brief Process command-line arguments
 */
BOOL HandleCliArguments(HWND hwnd, const char* cmdLine);

/**
 * @brief Get CLI help dialog handle
 */
HWND GetCliHelpDialog(void);

/**
 * @brief Close CLI help dialog
 */
void CloseCliHelpDialog(void);

#endif