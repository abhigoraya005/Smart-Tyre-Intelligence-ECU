#include "sensor_manager.h"

extern ADC_HandleTypeDef hadc1;

uint16_t SensorManager_ReadADC(uint32_t channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);

    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

    uint16_t adcValue = HAL_ADC_GetValue(&hadc1);

    HAL_ADC_Stop(&hadc1);

    return adcValue;
}
