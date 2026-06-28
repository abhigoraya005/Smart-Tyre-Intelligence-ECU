#include "uart_debug.h"
#include "sensor_manager.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    TyreSensorData sensor = SensorManager_GetData();

    printf("\r\n");
    printf("=================================================\r\n");
    printf("        SMART TYRE INTELLIGENCE ECU\r\n");
    printf("=================================================\r\n");

    printf("Temperature : %.2f C\r\n", sensor.temperature);
    printf("Pressure    : %.2f PSI\r\n", sensor.pressure);
    printf("Vibration   : %.2f g\r\n", sensor.vibration);
    printf("Load        : %.2f %%\r\n", sensor.load);

    printf("=================================================\r\n");
}
