#include "pressure.h"

void Pressure_Init(void)
{

}

float Pressure_GetValue(uint16_t adcValue)
{
    /*
     * Automotive tyre pressure
     * 20 PSI → 50 PSI
     */

    return 20.0f + ((30.0f * adcValue) / 4095.0f);
}
