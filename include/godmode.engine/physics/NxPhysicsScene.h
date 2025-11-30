#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.engine/physics/PhysicsEntity3d.h>
#include <godmode.engine/physics/PhysicsScene.h>
#include <godmode.foundation/log/Console.h>

godmode_engine_physics(template <class PhysicsEntityType, class SceneType, class BaseEntityType> class NxPhysicsScene
    :   public PhysicsScene<PhysicsEntityType, SceneType, BaseEntityType> { $
    PxScene* pxScene = nullptr;
    PxDefaultCpuDispatcher* gDispatcher = nullptr;
    PxControllerManager* gManager = nullptr;
    PxMaterial* defaultMaterial = nullptr;
    constructor(NxPhysicsScene())
    destructor$(NxPhysicsScene())
    virtual void startPhysicsSimulate();
    virtual void endPhysicsSimulate();
    void addPhysicsEntity(PhysicsEntityType* physicEntity);
    void removePhysicsEntity(PhysicsEntityType* physicEntity);
    s11n$declare()
})
godmode_engine_physics(typedef NxPhysicsScene<PhysicsEntity3d, Scene3d, BaseEntity3d> NxPhysicsScene3dTypedef)
s11n$export(NxPhysicsScene3dTypedef);