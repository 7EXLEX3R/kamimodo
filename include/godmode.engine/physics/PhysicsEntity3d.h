#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine/physics/CollisionGroup.h>
#include <godmode.engine/physics/NxPhysicsEntity3d.h>
#include <godmode.engine/physics/PhysicsEntityType.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_physics(struct PhysicsEntity3dParams : virtual BaseEntity3dParams {
    PhysicsEntityType physicsEntityType = PhysicsEntityType::NONE;
    float mass = 0;
    void* actorData = nullptr;
    float density = 0;
    bool physicsEnabled = true;
    float airResistance = 0;
    unsigned int events = 0;
    CollisionGroup collisionGroup = CollisionGroup::NONE;
    bool lockInit = false;
})
godmode_engine_physics(class PhysicsEntity3d
    :   virtual public PhysicsEntity3dParams,
        public BaseEntity3d,
        public NxPhysicsEntity3d { $
    List<PhysicsEntity3d *> collisionStarts;
    List<PhysicsEntity3d *> collisions;
    List<PhysicsEntity3d *> collisionEnds;
    constructor(PhysicsEntity3d(const PhysicsEntity3dParams& params = PhysicsEntity3dParams()))
    destructor$(PhysicsEntity3d())
    void init();
    virtual void initAsNone();
    virtual void initAsPlane();
    virtual void initAsSphere();
    virtual void initAsBox();
    virtual void initAsCapsule();
    virtual void initAsConvex();
    virtual void initAsMesh();
    virtual void setActor(void *actorData);
    virtual void *getActor();
    virtual void physics() {};
    bool collisionStart(PhysicsEntity3d *otherPhysxalbe = 0);
    bool collision(PhysicsEntity3d *otherPhysxalbe = 0);
    bool collisionEnd(PhysicsEntity3d *otherPhysxalbe = 0);
    void transform();
    virtual JSON toJson();
    virtual void fromJson(JSON json);
    virtual void move(float3 &value, bool perSecond = true);
    virtual void rotate(float3 value, bool perSecond = true);
    virtual void rescale(float3 &value, bool perSecond = true);
    virtual void setPosition(float3 &position);
    virtual void setRotation(float3 rotation);
    virtual void setPositionX(float x);
    virtual void setPositionY(float y);
    virtual void setPositionZ(float z);
    virtual void setRotationX(float x);
    virtual void setRotationY(float y);
    virtual void setRotationZ(float z);
protected:
    void applyPosition();
    void applyRotation();
    s11n$declare()
})
// s11n$export(PhysicsEntity3d);