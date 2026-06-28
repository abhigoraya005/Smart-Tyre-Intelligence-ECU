#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>

void Temperature_Init(void);

float Temperature_GetValue(uint16_t adcValue);

#endif
