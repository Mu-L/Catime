/**
 * @file font.h
 * @brief Font loading and management system
 */

#ifndef FONT_H
#define FONT_H

#include <windows.h>

#define FONT_FOLDER_PREFIX "%LOCALAPPDATA%\\Catime\\resources\\fonts\\"
#define MAX_FONT_NAME_LEN 256
#define TTF_NAME_TABLE_TAG 0x656D616E
#define TTF_NAME_ID_FAMILY 1
#define TTF_STRING_SAFETY_LIMIT 1024

typedef struct {
    int resourceId;
    const char* fileName;
    const char* licenseType;
} FontResource;

typedef struct {
    WORD platformID;
    WORD encodingID;
    WORD languageID;
    WORD nameID;
    WORD length;
    WORD offset;
} TTF_NameRecord;

extern FontResource fontResources[];
extern const int FONT_RESOURCES_COUNT;
extern char FONT_FILE_NAME[100];
extern char FONT_INTERNAL_NAME[100];
extern char PREVIEW_FONT_NAME[100];
extern char PREVIEW_INTERNAL_NAME[100];
extern BOOL IS_PREVIEWING;

BOOL UnloadCurrentFontResource(void);
BOOL LoadFontFromFile(const char* fontFilePath);
BOOL FindFontInFontsFolder(const char* fontFileName, char* foundPath, size_t foundPathSize);
BOOL LoadFontByName(HINSTANCE hInstance, const char* fontName);
BOOL LoadFontByNameAndGetRealName(HINSTANCE hInstance, const char* fontFileName, 
                                  char* realFontName, size_t realFontNameSize);
BOOL GetFontNameFromFile(const char* fontFilePath, char* fontName, size_t fontNameSize);
void WriteConfigFont(const char* fontFileName, BOOL shouldReload);
void ListAvailableFonts(void);
BOOL PreviewFont(HINSTANCE hInstance, const char* fontName);
void CancelFontPreview(void);
void ApplyFontPreview(void);
BOOL SwitchFont(HINSTANCE hInstance, const char* fontName);
BOOL ExtractFontResourceToFile(HINSTANCE hInstance, int resourceId, const char* outputPath);
BOOL ExtractEmbeddedFontsToFolder(HINSTANCE hInstance);
BOOL CheckAndFixFontPath(void);

#endif
