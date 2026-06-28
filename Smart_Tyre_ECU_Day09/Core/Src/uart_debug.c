#include "uart_debug.h"

#include "sensor_manager.h"
#include "tyre_health.h"
#include "fault_manager.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    TyreSensorData sensor = SensorManager_GetData();
    TyreHealthData health = TyreHealth_GetData();
    FaultData fault = FaultManager_GetData();

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

    printf("Temperature : %6.2f C\r\n", sensor.temperature);
    printf("Pressure    : %6.2f PSI\r\n", sensor.pressure);
    printf("Vibration   : %6.2f g\r\n", sensor.vibration);
    printf("Load        : %6.2f %%\r\n", sensor.load);

    printf("-------------------------------------------------\r\n");

    printf("Health Score : %6.2f %%\r\n", health.healthScore);
    printf("Tyre Status  : %s\r\n", statusText);

    printf("-------------------------------------------------\r\n");

    printf("Fault Report\r\n\n");

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

    printf("=================================================\r\n");
}
