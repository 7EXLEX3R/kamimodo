#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/physx.h>

godmode_engine_physics(class NxPhysicsEntity3d { $
    PxRigidActor *pxRigidActor = nullptr;
    PxRigidStatic *pxRigidStatic = nullptr;
    PxRigidDynamic *pxRigidDynamic = nullptr;
    PxScene *relatedScene = nullptr;
    constructor(NxPhysicsEntity3d())
    destructor$(NxPhysicsEntity3d())
    // NxSphereShapeDesc sphereDesc;
    // NxBoxShapeDesc boxDesc;
    // NxConvexShapeDesc convexDesc;
    // NxTriangleMeshShapeDesc triangleDesc;
})