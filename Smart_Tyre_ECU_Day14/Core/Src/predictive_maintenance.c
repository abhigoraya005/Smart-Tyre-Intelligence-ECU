#include "predictive_maintenance.h"

#include "tyre_health.h"
#include "fault_manager.h"

static MaintenanceData maintenance;

void PredictiveMaintenance_Init(void)
{
    maintenance.replaceTyre = false;
    maintenance.wheelBalancing = false;
    maintenance.suspensionInspection = false;
    maintenance.pressureInspection = false;

    maintenance.priority = 0;
}

void PredictiveMaintenance_Update(void)
{
    TyreHealthData health = TyreHealth_GetData();
    FaultData fault = FaultManager_GetData();

    maintenance.replaceTyre = false;
    maintenance.wheelBalancing = false;
    maintenance.suspensionInspection = false;
    maintenance.pressureInspection = false;

    maintenance.priority = 0;

    if (health.status == TYRE_STATUS_CRITICAL)
    {
        maintenance.replaceTyre = true;
        maintenance.priority = 3;
    }

    if (fault.highVibration)
    {
        maintenance.wheelBalancing = true;
        maintenance.suspensionInspection = true;

        if (maintenance.priority < 2)
            maintenance.priority = 2;
    }

    if (fault.lowPressure || fault.highPressure)
    {
        maintenance.pressureInspection = true;

        if (maintenance.priority < 1)
            maintenance.priority = 1;
    }
}

MaintenanceData PredictiveMaintenance_GetData(void)
{
    return maintenance;
}
