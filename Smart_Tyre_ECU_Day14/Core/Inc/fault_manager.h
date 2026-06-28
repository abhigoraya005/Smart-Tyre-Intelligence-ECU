#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H

#include <stdbool.h>

typedef struct
{
    bool overTemperature;
    bool lowPressure;
    bool highPressure;
    bool highVibration;
    bool overload;

} FaultData;

void FaultManager_Init(void);

void FaultManager_Update(void);

FaultData FaultManager_GetData(void);

#endif
