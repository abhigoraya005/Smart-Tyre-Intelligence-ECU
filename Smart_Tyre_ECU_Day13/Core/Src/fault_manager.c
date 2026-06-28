#include "fault_manager.h"

#include "sensor_manager.h"

static FaultData fault;

void FaultManager_Init(void)
{
    fault.overTemperature = false;
    fault.lowPressure = false;
    fault.highPressure = false;
    fault.highVibration = false;
    fault.overload = false;
}

void FaultManager_Update(void)
{
    TyreSensorData sensor = SensorManager_GetData();

    fault.overTemperature = (sensor.temperature > 120.0f);

    fault.lowPressure = (sensor.pressure < 28.0f);

    fault.highPressure = (sensor.pressure > 40.0f);

    fault.highVibration = (sensor.vibration > 3.0f);

    fault.overload = (sensor.load > 80.0f);
}

FaultData FaultManager_GetData(void)
{
    return fault;
}
