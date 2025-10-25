/**
 * @file log.h
 * @brief Logging system with file rotation
 */

#ifndef LOG_H
#define LOG_H

#include <windows.h>

#define LOG_MAX_FILE_SIZE (10 * 1024 * 1024)
#define LOG_ROTATION_COUNT 3
#define UTF8_BOM "\xEF\xBB\xBF"
#define LOG_TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
} LogLevel;

typedef struct {
    HANDLE hFile;
    CRITICAL_SECTION csLock;
    LogLevel minLevel;
} LogState;

typedef struct {
    DWORD majorVersion;
    DWORD minorVersion;
    DWORD buildNumber;
} OSVersionInfo;

typedef struct {
    ULONGLONG totalPhysicalMB;
    ULONGLONG availablePhysicalMB;
    DWORD memoryLoad;
} MemoryInfo;

BOOL InitializeLogSystem(void);
void WriteLog(LogLevel level, const char* format, ...);
void CleanupLogSystem(void);
void SetMinimumLogLevel(LogLevel minLevel);
void LogOSVersion(void);
void LogCPUArchitecture(void);
void LogMemoryInfo(void);
void LogUACStatus(void);
void LogAdminPrivileges(void);
void GetLastErrorDescription(DWORD errorCode, char* buffer, int bufferSize);
void FormatBytes(ULONGLONG bytes, char* buffer, size_t bufferSize);
void SetupExceptionHandler(void);

#define LOG_DEBUG(format, ...) WriteLog(LOG_LEVEL_DEBUG, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...) WriteLog(LOG_LEVEL_INFO, format, ##__VA_ARGS__)
#define LOG_WARNING(format, ...) WriteLog(LOG_LEVEL_WARNING, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) WriteLog(LOG_LEVEL_ERROR, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) WriteLog(LOG_LEVEL_FATAL, format, ##__VA_ARGS__)

#define LOG_WINDOWS_ERROR(format, ...) do { \
    DWORD _err = GetLastError(); \
    char _errBuf[512]; \
    GetLastErrorDescription(_err, _errBuf, sizeof(_errBuf)); \
    WriteLog(LOG_LEVEL_ERROR, format " (Error %lu: %s)", ##__VA_ARGS__, _err, _errBuf); \
} while(0)

#endif
