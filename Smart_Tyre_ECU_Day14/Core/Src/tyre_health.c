#include "tyre_health.h"

#include "sensor_manager.h"

static TyreHealthData tyreHealth;

void TyreHealth_Init(void)
{
    tyreHealth.healthScore = 100.0f;

    tyreHealth.status = TYRE_STATUS_EXCELLENT;
}

void TyreHealth_Update(void)
{
    TyreSensorData sensor = SensorManager_GetData();

    float score = 100.0f;

    /* Temperature */

    if(sensor.temperature > 120.0f)
        score -= 25.0f;

    /* Pressure */

    if(sensor.pressure < 28.0f || sensor.pressure > 40.0f)
        score -= 25.0f;

    /* Vibration */

    if(sensor.vibration > 3.0f)
        score -= 25.0f;

    /* Load */

    if(sensor.load > 80.0f)
        score -= 25.0f;

    if(score < 0.0f)
        score = 0.0f;

    tyreHealth.healthScore = score;

    if(score >= 90.0f)
        tyreHealth.status = TYRE_STATUS_EXCELLENT;

    else if(score >= 70.0f)
        tyreHealth.status = TYRE_STATUS_GOOD;

    else if(score >= 40.0f)
        tyreHealth.status = TYRE_STATUS_WARNING;

    else
        tyreHealth.status = TYRE_STATUS_CRITICAL;
}

TyreHealthData TyreHealth_GetData(void)
{
    return tyreHealth;
}
