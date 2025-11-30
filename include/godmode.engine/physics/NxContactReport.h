#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/physx.h>

godmode_engine_physics(class NxContactReportCallback : public PxSimulationEventCallback { $
    void onConstraintBreak(PxConstraintInfo* constraints, PxU32 count);
    void onWake(PxActor** actors, PxU32 count);
    void onSleep(PxActor** actors, PxU32 count);
    void onTrigger(PxTriggerPair* pairs, PxU32 count);
    void onAdvance(const PxRigidBody* const*, const PxTransform*, const PxU32);
    void onContact(const PxContactPairHeader& pairHeader, const PxContactPair* pairs, PxU32 nbPairs);
    static PxFilterFlags contactReportFilterShader(
        PxFilterObjectAttributes attributes0,
        PxFilterData filterData0,
        PxFilterObjectAttributes attributes1,
        PxFilterData filterData1,
        PxPairFlags& pairFlags,
        const void* constantBlock,
        PxU32 constantBlockSize);
})
godmode_engine_physics$extern($_contactReportCallback, NxContactReportCallback)