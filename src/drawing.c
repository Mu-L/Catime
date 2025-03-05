/**
 * @file drawing.c
 * @brief 窗口绘图功能实现
 * 
 * 本文件实现了应用程序窗口绘图相关的功能，
 * 包括文本渲染、颜色设置和窗口内容绘制等功能。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/drawing.h"
#include "../include/font.h"
#include "../include/color.h"
#include "../include/timer.h"
#include "../include/config.h"

// 从window_procedure.c引入的变量
extern int elapsed_time;

// 使用resource.h中定义的窗口绘制相关常量

/**
 * @brief 处理窗口绘制
 * @param hwnd 窗口句柄
 * @param ps 绘制结构体
 * 
 * 处理窗口的WM_PAINT消息，执行以下操作：
 * 1. 创建内存DC双缓冲防止闪烁
 * 2. 根据模式计算剩余时间/获取当前时间
 * 3. 动态加载字体资源(支持实时预览)
 * 4. 解析颜色配置(支持HEX/RGB格式)
 * 5. 使用双缓冲机制绘制文本
 * 6. 自动调整窗口尺寸适应文本内容
 */
void HandleWindowPaint(HWND hwnd, PAINTSTRUCT *ps) {
    static char time_text[50];
    HDC hdc = ps->hdc;
    RECT rect;
    GetClientRect(hwnd, &rect);

    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP memBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
    HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);

    SetGraphicsMode(memDC, GM_ADVANCED);
    SetBkMode(memDC, TRANSPARENT);
    SetStretchBltMode(memDC, HALFTONE);
    SetBrushOrgEx(memDC, 0, 0, NULL);

    int remaining_time = CLOCK_TOTAL_TIME - elapsed_time;
    if (elapsed_time >= CLOCK_TOTAL_TIME) {
        if (strcmp(CLOCK_TIMEOUT_TEXT, "0") == 0) {
            time_text[0] = '\0';
        } else if (strlen(CLOCK_TIMEOUT_TEXT) > 0) {
            strncpy(time_text, CLOCK_TIMEOUT_TEXT, sizeof(time_text) - 1);
            time_text[sizeof(time_text) - 1] = '\0';
        } else {
            time_text[0] = '\0';
        }
    } else {
        FormatTime(remaining_time, time_text);
    }

    const char* fontToUse = IS_PREVIEWING ? PREVIEW_FONT_NAME : FONT_FILE_NAME;
    HFONT hFont = CreateFont(
        -CLOCK_BASE_FONT_SIZE * CLOCK_FONT_SCALE_FACTOR,
        0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_TT_PRECIS,
        CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,   
        VARIABLE_PITCH | FF_SWISS,
        IS_PREVIEWING ? PREVIEW_INTERNAL_NAME : FONT_INTERNAL_NAME
    );
    HFONT oldFont = (HFONT)SelectObject(memDC, hFont);

    SetTextAlign(memDC, TA_LEFT | TA_TOP);
    SetTextCharacterExtra(memDC, 0);
    SetMapMode(memDC, MM_TEXT);

    DWORD quality = SetICMMode(memDC, ICM_ON);
    SetLayout(memDC, 0);

    int r = 255, g = 255, b = 255;
    const char* colorToUse = IS_COLOR_PREVIEWING ? PREVIEW_COLOR : CLOCK_TEXT_COLOR;
    
    if (strlen(colorToUse) > 0) {
        if (colorToUse[0] == '#') {
            if (strlen(colorToUse) == 7) {
                sscanf(colorToUse + 1, "%02x%02x%02x", &r, &g, &b);
            }
        } else {
            sscanf(colorToUse, "%d,%d,%d", &r, &g, &b);
        }
    }
    SetTextColor(memDC, RGB(r, g, b));

    if (CLOCK_EDIT_MODE) {
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
        FillRect(memDC, &rect, hBrush);
        DeleteObject(hBrush);
    } else {
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
        FillRect(memDC, &rect, hBrush);
        DeleteObject(hBrush);
    }

    if (strlen(time_text) > 0) {
        SIZE textSize;
        GetTextExtentPoint32(memDC, time_text, strlen(time_text), &textSize);

        if (textSize.cx != (rect.right - rect.left) || 
            textSize.cy != (rect.bottom - rect.top)) {
            RECT windowRect;
            GetWindowRect(hwnd, &windowRect);
            
            SetWindowPos(hwnd, NULL,
                windowRect.left, windowRect.top,
                textSize.cx + WINDOW_HORIZONTAL_PADDING, 
                textSize.cy + WINDOW_VERTICAL_PADDING, 
                SWP_NOZORDER | SWP_NOACTIVATE);
            GetClientRect(hwnd, &rect);
        }

        
        int x = (rect.right - textSize.cx) / 2;
        int y = (rect.bottom - textSize.cy) / 2;

        SetTextColor(memDC, RGB(r, g, b));
        
        for (int i = 0; i < 8; i++) {
            TextOutA(memDC, x, y, time_text, strlen(time_text));
        }
    }

    BitBlt(hdc, 0, 0, rect.right, rect.bottom, memDC, 0, 0, SRCCOPY);

    SelectObject(memDC, oldFont);
    DeleteObject(hFont);
    SelectObject(memDC, oldBitmap);
    DeleteObject(memBitmap);
    DeleteDC(memDC);
}