#include "uart_debug.h"
#include "temperature.h"
#include "sensor_manager.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    uint16_t adcValue;
    float temperature;

    adcValue = SensorManager_ReadADC(ADC_CHANNEL_0);

    temperature = Temperature_GetValue(adcValue);

    printf("\r\n");
    printf("=====================================\r\n");
    printf(" SMART TYRE INTELLIGENCE ECU\r\n");
    printf("=====================================\r\n");
    printf("ADC Value   : %4d\r\n", adcValue);
    printf("Temperature : %.2f C\r\n", temperature);
    printf("=====================================\r\n");
}
