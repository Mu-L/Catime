/**
 * @file markdown_parser.h
 * @brief Markdown parser for clickable links in dialogs
 */

#ifndef MARKDOWN_PARSER_H
#define MARKDOWN_PARSER_H

#include <windows.h>

typedef struct {
    int startIndex;
    int endIndex;
    wchar_t url[512];
    RECT bounds;
} MarkdownLink;

BOOL ParseMarkdownLinks(const wchar_t* input, wchar_t** displayText, MarkdownLink** links, int* linkCount);
void FreeMarkdownLinks(MarkdownLink* links, int linkCount);
BOOL IsCharacterInLink(MarkdownLink* links, int linkCount, int position, int* linkIndex);
void RenderMarkdownText(HDC hdc, const wchar_t* displayText, MarkdownLink* links, int linkCount, 
                       int x, int y, int maxWidth, COLORREF textColor, COLORREF linkColor);
BOOL HandleMarkdownClick(MarkdownLink* links, int linkCount, POINT clickPoint);

#define MARKDOWN_DEFAULT_LINK_COLOR RGB(0, 100, 200)
#define MARKDOWN_DEFAULT_TEXT_COLOR GetSysColor(COLOR_WINDOWTEXT)

#endif
