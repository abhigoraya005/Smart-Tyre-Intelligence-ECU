#ifndef PRESSURE_H
#define PRESSURE_H

#include <stdint.h>

void Pressure_Init(void);

float Pressure_GetValue(uint16_t adcValue);

#endif
