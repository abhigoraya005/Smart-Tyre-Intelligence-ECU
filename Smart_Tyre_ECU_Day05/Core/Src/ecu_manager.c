#include "ecu_manager.h"
#include "uart_debug.h"
#include "temperature.h"
#include "pressure.h"
#include "main.h"

void ECU_Init(void)
{
    Temperature_Init();
    Pressure_Init();
}
void ECU_Run(void)
{
    UART_Debug_Print();

    HAL_Delay(1000);
}
