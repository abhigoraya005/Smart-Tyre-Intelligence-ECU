#ifndef VIBRATION_H
#define VIBRATION_H

#include <stdint.h>

void Vibration_Init(void);

float Vibration_GetValue(uint16_t adcValue);

#endif
