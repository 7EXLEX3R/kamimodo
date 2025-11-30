#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>
#include <godmode.engine/entity/EntityFactory.h>
#include <godmode.engine/entity/_3d/Object3d.h>
#include <godmode.engine/input/InputApi.h>
#include <godmode.engine/logic/SceneAttachable.h>
#include <godmode.engine/math/Quaternion.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/utils/gameplay/Bullet.h>
#include <godmode.engine/utils/gameplay/Player.h>
#include <godmode.foundation/types/List.h>

godmode_engine_utils(class Weapons : public SceneAttachable<Scene3d> { $
    Model* impactHammer = nullptr;
    Model* plasmaRifle = nullptr;
    Model* plasmaRifleBullet = nullptr;
    Shader* deferredShader = nullptr;
    bool switching = false;
    int activeWeaponIndex = 0;
    Object3d* activeWeapon = nullptr;
    float shotCooldown = 0;
    Player* attachedPlayer = nullptr;
    Object3d* hammer = nullptr;
    Object3d* plasma = nullptr;
    float3 offset;
    List<Object3d*> weapons;
    List<Bullet*> bullets;
    constructor(Weapons())
    destructor$(Weapons())
    void process();
    void attachPlayer(Player* player);
    void detachPlayer();
    virtual void attachTo(Scene3d* relativeScene = 0);
    virtual void detachFrom(Scene3d* relativeScene = 0);
    void handleSwitch();
    void handleShot();
    void manageWeaponPositionUtil();
})