#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/SceneAttachable.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/physics/NxHitReportController.h>
#include <godmode.engine/physics/NxPhysicsScene3d.h>

godmode_engine_physics(class NxCharacterController : public SceneAttachable<NxPhysicsScene3d> { $
    PxCapsuleController *capsuleController = nullptr;
    PxController *nxController = nullptr;
    bool gravitable = true;
    double crouchFactor = 0.5;
    private$(PxCapsuleControllerDesc desc)
    private$(NxHitReportController hitReportController)
    private$(bool isJump = false)
    private$(double jumpVelocity = 0)
    private$(double moveVelocity = 0)
    private$(float3 moveDirection = {0, 0, 0})
    private$(double maxCrouchVelocity = 1)
    private$(double maxWalkVelocity = 8)
    private$(double maxRunVelocity = 5)
    private$(double crouchAcceleration = 250)
    private$(double walkAcceleration = 250)
    private$(double runAcceleration = 250)
    private$(double idleAcceleration = 250)
    private$(double airControl = 0.05)
    private$(double jumpStartVelocity = 3.66)
    private$(double jumpGravity = 9.81)
    private$(double maxJumpVelocity = 20)
    constructor(NxCharacterController(float3 &pos, float radius = 0, float height = 0, bool gravitable = 0, float stepOffset = 0, float slopeLimit = 0))
    destructor$(NxCharacterController())
    int move(float3 &direction, float3 &normal, float3 &outMoveDisplacement = float3(0, 0, 0), float3 &outJumpDisplacement = float3(0, 0, 0));
    void update();
    float3 getPosition();
    void setPosition(float3 &position);
    virtual void attachTo(NxPhysicsScene3d *relativeScene = 0);
    virtual void detachFrom(NxPhysicsScene3d *relativeScene = 0);
    private$(void config())
})