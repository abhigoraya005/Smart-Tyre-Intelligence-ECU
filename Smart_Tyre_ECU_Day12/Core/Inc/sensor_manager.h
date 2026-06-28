#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include "main.h"

typedef struct
{
    float temperature;
    float pressure;
    float vibration;
    float load;

} TyreSensorData;

/* Function Prototypes */

void SensorManager_Init(void);

void SensorManager_Update(void);

TyreSensorData SensorManager_GetData(void);

#endif
