#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/EntityTree.h>
#include <godmode.engine/logic/Scene.h>
#include <godmode.engine/logic/_2d/Scene2d.h>
#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.engine/physics/PhysicsEntity3d.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_physics(template <class PhysicsEntityType, class SceneType, class BaseEntityType> class PhysicsScene
    :   public SceneType { $
    List<PhysicsEntityType *> physicEntities;
    bool physicEnabled = true;
    constructor(PhysicsScene())
    destructor$(PhysicsScene())
    virtual void simulate();
    virtual void startPhysicsSimulate() = 0;
    virtual void endPhysicsSimulate() = 0;
    virtual void addPhysicsEntity(PhysicsEntityType *physicEntity) = 0;
    virtual BaseEntityType *addEntity(BaseEntityType *baseEntity);
    virtual void removePhysicsEntity(PhysicsEntityType *physicsEntity) = 0;
    virtual BaseEntityType *removeEntity(BaseEntityType *baseEntity);
    s11n$declareSplit()
})
godmode_engine_physics(typedef PhysicsScene<PhysicsEntity3d, Scene3d, BaseEntity3d> PhysicsScene3dTypedef)
// s11n$export(PhysicsScene3dTypedef);
