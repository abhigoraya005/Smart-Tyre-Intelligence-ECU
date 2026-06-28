#ifndef TYRE_HEALTH_H
#define TYRE_HEALTH_H

typedef enum
{
    TYRE_STATUS_EXCELLENT,
    TYRE_STATUS_GOOD,
    TYRE_STATUS_WARNING,
    TYRE_STATUS_CRITICAL

} TyreStatus;

typedef struct
{
    float healthScore;

    TyreStatus status;

} TyreHealthData;

void TyreHealth_Init(void);

void TyreHealth_Update(void);

TyreHealthData TyreHealth_GetData(void);

#endif
