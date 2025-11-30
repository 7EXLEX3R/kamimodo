#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.engine/physics/NxPhysicsScene.h>
#include <godmode.engine/physics/PhysicsEntity3d.h>

godmode_engine_physics(typedef NxPhysicsScene<PhysicsEntity3d, Scene3d, BaseEntity3d> NxPhysicsScene3dTemplate)
godmode_engine_physics(class NxPhysicsScene3d : public NxPhysicsScene<PhysicsEntity3d, Scene3d, BaseEntity3d> { $
    constructor(NxPhysicsScene3d())
    destructor$(NxPhysicsScene3d())
    s11n$declare()
})
s11n$export(NxPhysicsScene3d);