/**
 * @file system_monitor.h
 * @brief System resource monitoring: CPU, memory, network
 */

#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include <windows.h>

void SystemMonitor_Init(void);
void SystemMonitor_Shutdown(void);
void SystemMonitor_SetUpdateIntervalMs(DWORD intervalMs);
void SystemMonitor_ForceRefresh(void);
BOOL SystemMonitor_GetCpuUsage(float* outPercent);
BOOL SystemMonitor_GetMemoryUsage(float* outPercent);
BOOL SystemMonitor_GetUsage(float* outCpuPercent, float* outMemPercent);
BOOL SystemMonitor_GetNetSpeed(float* outUpBytesPerSec, float* outDownBytesPerSec);

#endif
