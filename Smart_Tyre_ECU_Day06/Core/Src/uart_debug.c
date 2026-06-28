#include "uart_debug.h"

#include "sensor_manager.h"
#include "temperature.h"
#include "pressure.h"
#include "vibration.h"
#include "load.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    uint16_t tempADC;
    uint16_t pressureADC;
    uint16_t vibrationADC;
    uint16_t loadADC;

    float temperature;
    float pressure;
    float vibration;
    float load;

    /* Read ADC Channels */

    tempADC = SensorManager_ReadADC(ADC_CHANNEL_0);
    pressureADC = SensorManager_ReadADC(ADC_CHANNEL_1);
    vibrationADC = SensorManager_ReadADC(ADC_CHANNEL_2);
    loadADC = SensorManager_ReadADC(ADC_CHANNEL_3);

    /* Convert ADC Values */

    temperature = Temperature_GetValue(tempADC);
    pressure = Pressure_GetValue(pressureADC);
    vibration = Vibration_GetValue(vibrationADC);
    load = Load_GetValue(loadADC);

    printf("\r\n");
    printf("=================================================\r\n");
    printf("        SMART TYRE INTELLIGENCE ECU\r\n");
    printf("=================================================\r\n");

    printf("ADC Temp        : %4d\r\n", tempADC);
    printf("Temperature     : %.2f C\r\n", temperature);

    printf("\r\n");

    printf("ADC Pressure    : %4d\r\n", pressureADC);
    printf("Pressure        : %.2f PSI\r\n", pressure);

    printf("\r\n");

    printf("ADC Vibration   : %4d\r\n", vibrationADC);
    printf("Vibration       : %.2f g\r\n", vibration);

    printf("\r\n");

    printf("ADC Load        : %4d\r\n", loadADC);
    printf("Load            : %.2f %%\r\n", load);

    printf("=================================================\r\n");
}
