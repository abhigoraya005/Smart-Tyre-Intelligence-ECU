#include "sensor_manager.h"

#include "temperature.h"
#include "pressure.h"
#include "vibration.h"
#include "load.h"

extern ADC_HandleTypeDef hadc1;

static TyreSensorData tyreData;

/*--------------------------------------*/

static uint16_t Read_ADC_Channel(uint32_t channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);

    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

    uint16_t value = HAL_ADC_GetValue(&hadc1);

    HAL_ADC_Stop(&hadc1);

    return value;
}

/*--------------------------------------*/

void SensorManager_Init(void)
{
    tyreData.temperature = 0.0f;
    tyreData.pressure = 0.0f;
    tyreData.vibration = 0.0f;
    tyreData.load = 0.0f;
}

/*--------------------------------------*/

void SensorManager_Update(void)
{
    uint16_t tempADC;
    uint16_t pressureADC;
    uint16_t vibrationADC;
    uint16_t loadADC;

    tempADC = Read_ADC_Channel(ADC_CHANNEL_0);
    tyreData.temperature = Temperature_GetValue(tempADC);

    pressureADC = Read_ADC_Channel(ADC_CHANNEL_1);
    tyreData.pressure = Pressure_GetValue(pressureADC);

    vibrationADC = Read_ADC_Channel(ADC_CHANNEL_2);
    tyreData.vibration = Vibration_GetValue(vibrationADC);

    loadADC = Read_ADC_Channel(ADC_CHANNEL_3);
    tyreData.load = Load_GetValue(loadADC);
}

/*--------------------------------------*/

TyreSensorData SensorManager_GetData(void)
{
    return tyreData;
}
