#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d.h>
#include <godmode.engine/logic/LogicEntity3d.h>
#include <godmode.engine/logic/SceneAttachable.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/physics/NxCharacterController.h>
#include <godmode.engine/physics/NxPhysicsScene3d.h>
#include <godmode.engine/utils/gameplay/Character.h>
#include <godmode.foundation/types/List.h>

godmode_engine_utils(class Player : public Character, public SceneAttachable<Scene3d> { $
    NxCharacterController *characterController = nullptr;
    Camera3d *camera3d = nullptr;
    float speed = 0;
    LogicEntity3d logicEntity;
    double distancePassed = 0;
    double moveWeaponDisplacement = 0;
    double jumpWeaponDisplacement = 0;
    Camera3d *auxCamera3d = nullptr;
    double spinDest = 0;
    double spin = 0;
    double spinAngularVelocity = 0;
    double spinTransition = 0;
    double surfaceGravityModifier = 0;
    double surfaceGravityDistance = 0;
    constructor(Player())
    destructor$(Player())
    bool adjustUpVector(List<Object3d *> &pickable);
    void moveCharacter();
    void rotateCamera();
    void moveCameraUsingWheel();
    void config();
    virtual void attachTo(Scene3d *relativeScene = 0);
    virtual void detachFrom(Scene3d *relativeScene = 0);
})