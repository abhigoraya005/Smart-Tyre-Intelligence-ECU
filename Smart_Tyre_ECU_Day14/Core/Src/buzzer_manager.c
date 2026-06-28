#include "buzzer_manager.h"

#include "tyre_health.h"

#include "main.h"

void Buzzer_Init(void)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
}

void Buzzer_Update(void)
{
    TyreHealthData health = TyreHealth_GetData();

    if(health.status == TYRE_STATUS_CRITICAL)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);

        HAL_Delay(100);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    }
}
