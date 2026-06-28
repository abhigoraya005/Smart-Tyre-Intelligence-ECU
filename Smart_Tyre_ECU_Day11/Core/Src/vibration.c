#include "vibration.h"

void Vibration_Init(void)
{

}

float Vibration_GetValue(uint16_t adcValue)
{
    /*
     * Simulation
     * ADC 0     -> 0 g
     * ADC 4095  -> 5 g
     */

    return (5.0f * adcValue) / 4095.0f;
}
