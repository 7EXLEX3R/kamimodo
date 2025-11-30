#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/physics/NxCooking.h>
#include <godmode.engine/physics/NxPhysicsApi.h>
#include <godmode.engine/physics/PhysicsEntity3d.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_entity__3d(struct Object3dParams : virtual PhysicsEntity3dParams {
    Model* model = nullptr;
})
godmode_engine_entity__3d(class Object3d : virtual public Object3dParams, public PhysicsEntity3d { $
    constructor(Object3d(const Object3dParams& params = Object3dParams()))
    destructor$(Object3d());
    virtual void initAsNone();
    virtual void initAsPlane();
    virtual void initAsSphere();
    virtual void initAsBox();
    virtual void initAsCapsule();
    virtual void initAsConvex();
    virtual void initAsMesh();
    virtual void physics();
    virtual void recreate();
    void renderBoundingParams();
    void setModel(Model *model);
    s11n$declareSplit()
})