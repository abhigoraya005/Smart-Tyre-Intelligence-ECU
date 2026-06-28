#include "temperature.h"

void Temperature_Init(void)
{

}

float Temperature_GetValue(uint16_t adcValue)
{
    float voltage;

    voltage = (3.3f * adcValue) / 4095.0f;

    return voltage * 100.0f;
}
