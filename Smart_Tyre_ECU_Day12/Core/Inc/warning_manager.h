#ifndef WARNING_MANAGER_H
#define WARNING_MANAGER_H

#include <stdbool.h>

typedef struct
{
    bool tyreOverheated;
    bool lowPressureWarning;
    bool highPressureWarning;
    bool vibrationWarning;
    bool overloadWarning;

} WarningData;

void WarningManager_Init(void);

void WarningManager_Update(void);

WarningData WarningManager_GetData(void);

#endif
