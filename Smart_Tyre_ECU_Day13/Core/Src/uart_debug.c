#include "uart_debug.h"

#include "sensor_manager.h"
#include "tyre_health.h"
#include "fault_manager.h"
#include "warning_manager.h"
#include "predictive_maintenance.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    TyreSensorData sensor = SensorManager_GetData();
    TyreHealthData health = TyreHealth_GetData();
    FaultData fault = FaultManager_GetData();
    WarningData warning = WarningManager_GetData();
    MaintenanceData maintenance = PredictiveMaintenance_GetData();

    const char *statusText;
    const char *systemMode;

    switch (health.status)
    {
        case TYRE_STATUS_EXCELLENT:
            statusText = "EXCELLENT";
            systemMode = "NORMAL";
            break;

        case TYRE_STATUS_GOOD:
            statusText = "GOOD";
            systemMode = "NORMAL";
            break;

        case TYRE_STATUS_WARNING:
            statusText = "WARNING";
            systemMode = "WARNING";
            break;

        case TYRE_STATUS_CRITICAL:
            statusText = "CRITICAL";
            systemMode = "CRITICAL";
            break;

        default:
            statusText = "UNKNOWN";
            systemMode = "UNKNOWN";
            break;
    }

    printf("\r\n");
    printf("============================================================\r\n");
    printf("          SMART TYRE INTELLIGENCE ECU v1.0\r\n");
    printf("------------------------------------------------------------\r\n");
    printf("          STM32F103C8T6 Automotive Firmware\r\n");
    printf("          Developed by Abhiney Kumar\r\n");
    printf("============================================================\r\n");

    printf("ECU STATUS      : %s\r\n", statusText);
    printf("SYSTEM MODE     : %s\r\n", systemMode);
    printf("HEALTH SCORE    : %.2f %%\r\n", health.healthScore);
    printf("ACTIVE SENSORS  : 4\r\n");

    printf("\r\n");

    printf("--------------- SENSOR DATA --------------------\r\n");

    printf("Temperature        : %7.2f C\r\n", sensor.temperature);
    printf("Pressure           : %7.2f PSI\r\n", sensor.pressure);
    printf("Vibration          : %7.2f g\r\n", sensor.vibration);
    printf("Load               : %7.2f %%\r\n", sensor.load);

    printf("\r\n");

    printf("-------------- ACTIVE FAULTS -------------------\r\n");

    printf("Over Temperature   : %s\r\n",
           fault.overTemperature ? "YES" : "NO");

    printf("Low Pressure       : %s\r\n",
           fault.lowPressure ? "YES" : "NO");

    printf("High Pressure      : %s\r\n",
           fault.highPressure ? "YES" : "NO");

    printf("High Vibration     : %s\r\n",
           fault.highVibration ? "YES" : "NO");

    printf("Over Load          : %s\r\n",
           fault.overload ? "YES" : "NO");

    printf("\r\n");

    printf("------------- ACTIVE WARNINGS ------------------\r\n");

    if (!(warning.tyreOverheated ||
          warning.lowPressureWarning ||
          warning.highPressureWarning ||
          warning.vibrationWarning ||
          warning.overloadWarning))
    {
        printf("[OK] No Active Warnings\r\n");
    }
    else
    {
        if (warning.tyreOverheated)
            printf("[CRITICAL] TYRE OVERHEATED\r\n");

        if (warning.lowPressureWarning)
            printf("[WARNING ] LOW TYRE PRESSURE\r\n");

        if (warning.highPressureWarning)
            printf("[WARNING ] HIGH TYRE PRESSURE\r\n");

        if (warning.vibrationWarning)
            printf("[CRITICAL] HIGH TYRE VIBRATION\r\n");

        if (warning.overloadWarning)
            printf("[WARNING ] VEHICLE OVERLOADED\r\n");
    }

    printf("\r\n");

    printf("----------- RECOMMENDED ACTION -----------------\r\n");

    if (health.status == TYRE_STATUS_EXCELLENT)
    {
        printf("No maintenance required.\r\n");
    }
    else if (health.status == TYRE_STATUS_GOOD)
    {
        printf("Continue regular monitoring.\r\n");
    }
    else if (health.status == TYRE_STATUS_WARNING)
    {
        printf("Schedule tyre inspection soon.\r\n");
    }
    else
    {
        printf("Immediate maintenance required!\r\n");
        printf("Stop vehicle if safe to do so.\r\n");
    }

    printf("\r\n");

    printf("-------- PREDICTIVE MAINTENANCE ----------------\r\n");

    printf("Replace Tyre          : %s\r\n",
           maintenance.replaceTyre ? "YES" : "NO");

    printf("Wheel Balancing       : %s\r\n",
           maintenance.wheelBalancing ? "YES" : "NO");

    printf("Suspension Inspection : %s\r\n",
           maintenance.suspensionInspection ? "YES" : "NO");

    printf("Pressure Inspection   : %s\r\n",
           maintenance.pressureInspection ? "YES" : "NO");

    printf("\r\n");

    printf("Maintenance Priority  : ");

    switch (maintenance.priority)
    {
        case 0:
            printf("NONE");
            break;

        case 1:
            printf("LOW");
            break;

        case 2:
            printf("MEDIUM");
            break;

        case 3:
            printf("HIGH (Immediate Action)");
            break;

        default:
            printf("UNKNOWN");
            break;
    }

    printf("\r\n\r\n");

    printf("---------------- ECU SUMMARY -------------------\r\n");

    printf("Health Status        : %s\r\n", statusText);
    printf("Health Score         : %.2f %%\r\n", health.healthScore);
    printf("Active Sensors       : 4\r\n");
    printf("Firmware Version     : v1.0\r\n");
    printf("MCU                  : STM32F103C8T6\r\n");

    printf("\r\n");

    printf("------------------------------------------------------------\r\n");
    printf("Developed By : Abhiney Kumar\r\n");
    printf("Target MCU   : STM32F103C8T6\r\n");
    printf("Build        : Release v1.0\r\n");
    printf("============================================================\r\n");
}
