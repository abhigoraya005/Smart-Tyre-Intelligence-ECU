#include "warning_manager.h"

#include "fault_manager.h"

static WarningData warning;

void WarningManager_Init(void)
{
    warning.tyreOverheated = false;
    warning.lowPressureWarning = false;
    warning.highPressureWarning = false;
    warning.vibrationWarning = false;
    warning.overloadWarning = false;
}

void WarningManager_Update(void)
{
    FaultData fault = FaultManager_GetData();

    warning.tyreOverheated = fault.overTemperature;

    warning.lowPressureWarning = fault.lowPressure;

    warning.highPressureWarning = fault.highPressure;

    warning.vibrationWarning = fault.highVibration;

    warning.overloadWarning = fault.overload;
}

WarningData WarningManager_GetData(void)
{
    return warning;
}
