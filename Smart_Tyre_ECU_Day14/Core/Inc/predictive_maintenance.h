#ifndef PREDICTIVE_MAINTENANCE_H
#define PREDICTIVE_MAINTENANCE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    bool replaceTyre;

    bool wheelBalancing;

    bool suspensionInspection;

    bool pressureInspection;

    uint8_t priority;

} MaintenanceData;

void PredictiveMaintenance_Init(void);

void PredictiveMaintenance_Update(void);

MaintenanceData PredictiveMaintenance_GetData(void);

#endif
