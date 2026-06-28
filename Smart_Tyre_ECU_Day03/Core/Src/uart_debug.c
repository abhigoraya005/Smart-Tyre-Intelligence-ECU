#include "uart_debug.h"
#include "temperature.h"

#include <stdio.h>

void UART_Debug_Print(void)
{
    float temperature;

    /* Temporary ADC Value */

    temperature = Temperature_GetValue(521);

    printf("\r\n");
    printf("=====================================\r\n");
    printf(" SMART TYRE INTELLIGENCE ECU\r\n");
    printf("=====================================\r\n");
    printf("Temperature : %.2f C\r\n", temperature);
    printf("=====================================\r\n");
}
