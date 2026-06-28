#include "uart_debug.h"

#include "sensor_manager.h"
#include "temperature.h"
#include "pressure.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    uint16_t tempADC;
    uint16_t pressureADC;

    float temperature;
    float pressure;

    /* Read ADC Channels */

    tempADC = SensorManager_ReadADC(ADC_CHANNEL_0);
    pressureADC = SensorManager_ReadADC(ADC_CHANNEL_1);

    /* Convert ADC to Engineering Units */

    temperature = Temperature_GetValue(tempADC);
    pressure = Pressure_GetValue(pressureADC);

    /* UART Output */

    printf("\r\n");
    printf("=========================================\r\n");
    printf(" SMART TYRE INTELLIGENCE ECU\r\n");
    printf("=========================================\r\n");

    printf("ADC Temp      : %4d\r\n", tempADC);
    printf("Temperature   : %.2f C\r\n", temperature);

    printf("\r\n");

    printf("ADC Pressure  : %4d\r\n", pressureADC);
    printf("Pressure      : %.2f PSI\r\n", pressure);

    printf("=========================================\r\n");
}
