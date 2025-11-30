#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/physics/NxCooking.h>
#include <godmode.engine/physics/PhysicsApi.h>

godmode_engine_physics(class NxPhysicsApi : public PhysicsApi { $
    PxPhysics *physx = nullptr;
    PxFoundation *foundation = nullptr;
    PxDefaultAllocator defaultAllocator;
    PxDefaultErrorCallback defaultErrorCallback;
    PxPvd *virtualDebugger = nullptr;
    PxMaterial *defaultMaterial = nullptr;
    PxCooking *cooking;
    constructor(NxPhysicsApi())
    destructor$(NxPhysicsApi())
})