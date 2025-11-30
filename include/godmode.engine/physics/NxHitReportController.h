#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/physx.h>

godmode_engine_physics(class NxHitReportController
    :   public PxUserControllerHitReport, public PxControllerBehaviorCallback { $
    virtual void onShapeHit(const PxControllerShapeHit& hit);
    virtual void onControllerHit(const PxControllersHit& hit);
    virtual void onObstacleHit(const PxControllerObstacleHit& hit);
    virtual PxControllerBehaviorFlags getBehaviorFlags(const PxShape& shape, const PxActor& actor);
    virtual PxControllerBehaviorFlags getBehaviorFlags(const PxController& controller);
    virtual PxControllerBehaviorFlags getBehaviorFlags(const PxObstacle& obstacle);
    void addForceAtLocalPos(PxRigidBody& body, const PxVec3& force, const PxVec3& pos, PxForceMode::Enum mode, bool wakeup = true);
})