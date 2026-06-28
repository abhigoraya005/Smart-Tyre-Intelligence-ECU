#include "ecu_manager.h"
#include "uart_debug.h"
#include "temperature.h"
#include "pressure.h"
#include "vibration.h"
#include "load.h"
#include "sensor_manager.h"
#include "tyre_health.h"
#include "fault_manager.h"
#include "warning_manager.h"
#include "predictive_maintenance.h"
#include "main.h"

void ECU_Init(void)
{
    Temperature_Init();
    Pressure_Init();
    Vibration_Init();
    Load_Init();

    SensorManager_Init();

    TyreHealth_Init();

    FaultManager_Init();
    WarningManager_Init();
    PredictiveMaintenance_Init();
}
void ECU_Run(void)
{
    SensorManager_Update();

    TyreHealth_Update();

    FaultManager_Update();

    WarningManager_Update();

    PredictiveMaintenance_Update();

    UART_Debug_Print();

    HAL_Delay(1000);
}
