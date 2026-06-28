#include "load.h"

void Load_Init(void)
{

}

float Load_GetValue(uint16_t adcValue)
{
    /*
     * Simulation
     * ADC 0     -> 0 %
     * ADC 4095  -> 100 %
     */

    return (100.0f * adcValue) / 4095.0f;
}
