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
    printf("RECOMMENDED ACTION\r\n\n");

    if (health.status == TYRE_STATUS_EXCELLENT)
    {
        printf("Tyre condition is excellent.\r\n");
        printf("No maintenance required.\r\n");
    }
    else if (health.status == TYRE_STATUS_GOOD)
    {
        printf("Tyre condition is good.\r\n");
        printf("Continue regular monitoring.\r\n");
    }
    else if (health.status == TYRE_STATUS_WARNING)
    {
        printf("Inspect tyre as soon as possible.\r\n");

        if (fault.lowPressure)
            printf("- Inflate tyre to recommended pressure.\r\n");

        if (fault.highPressure)
            printf("- Reduce tyre pressure.\r\n");

        if (fault.overTemperature)
            printf("- Allow tyre to cool before driving.\r\n");

        if (fault.highVibration)
            printf("- Check wheel balancing.\r\n");

        if (fault.overload)
            printf("- Reduce vehicle load.\r\n");
    }
    else
    {
        printf("Immediate maintenance required!\r\n");

        if (fault.overTemperature)
            printf("- Stop vehicle and inspect tyre.\r\n");

        if (fault.lowPressure)
            printf("- Inflate or repair tyre immediately.\r\n");

        if (fault.highPressure)
            printf("- Correct tyre pressure immediately.\r\n");

        if (fault.highVibration)
            printf("- Inspect suspension and wheel balancing.\r\n");

        if (fault.overload)
            printf("- Reduce vehicle load immediately.\r\n");

        printf("- Replace tyre if damage is observed.\r\n");
    }
    printf("=================================================\r\n");
}
