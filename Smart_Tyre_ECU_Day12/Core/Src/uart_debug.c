#include "uart_debug.h"

#include "sensor_manager.h"
#include "tyre_health.h"
#include "fault_manager.h"
#include "warning_manager.h"
#include <stdio.h>

void UART_Debug_Print(void)
{
    TyreSensorData sensor = SensorManager_GetData();
    TyreHealthData health = TyreHealth_GetData();
    FaultData fault = FaultManager_GetData();
    WarningData warning = WarningManager_GetData();
    const char *statusText;

    switch (health.status)
    {
        case TYRE_STATUS_EXCELLENT:
            statusText = "EXCELLENT";
            break;

        case TYRE_STATUS_GOOD:
            statusText = "GOOD";
            break;

        case TYRE_STATUS_WARNING:
            statusText = "WARNING";
            break;

        case TYRE_STATUS_CRITICAL:
            statusText = "CRITICAL";
            break;

        default:
            statusText = "UNKNOWN";
            break;
    }

    printf("\r\n");
    printf("=================================================\r\n");
    printf("        SMART TYRE INTELLIGENCE ECU\r\n");
    printf("=================================================\r\n");

    printf("SYSTEM STATUS : %s\r\n", statusText);
    printf("HEALTH SCORE  : %.2f %%\r\n", health.healthScore);

    printf("-------------------------------------------------\r\n");
    printf("SENSOR DATA\r\n\n");

    printf("Temperature : %6.2f C\r\n", sensor.temperature);
    printf("Pressure    : %6.2f PSI\r\n", sensor.pressure);
    printf("Vibration   : %6.2f g\r\n", sensor.vibration);
    printf("Load        : %6.2f %%\r\n", sensor.load);

    printf("-------------------------------------------------\r\n");
    printf("ACTIVE FAULTS\r\n\n");

    printf("Over Temperature : %s\r\n",
           fault.overTemperature ? "YES" : "NO");

    printf("Low Pressure     : %s\r\n",
           fault.lowPressure ? "YES" : "NO");

    printf("High Pressure    : %s\r\n",
           fault.highPressure ? "YES" : "NO");

    printf("High Vibration   : %s\r\n",
           fault.highVibration ? "YES" : "NO");

    printf("Over Load        : %s\r\n",
           fault.overload ? "YES" : "NO");
    printf("-------------------------------------------------\r\n");
    printf("ACTIVE WARNINGS\r\n\n");

    if (!(warning.tyreOverheated ||
          warning.lowPressureWarning ||
          warning.highPressureWarning ||
          warning.vibrationWarning ||
          warning.overloadWarning))
    {
        printf("[OK] No active warnings.\r\n");
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

    printf("-------------------------------------------------\r\n");
    printf("RECOMMENDED ACTION\r\n\n");

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
    printf("=================================================\r\n");
}
