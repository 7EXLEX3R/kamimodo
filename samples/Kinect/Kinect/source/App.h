#pragma once
#include <godmode.foundation.h>
#include <godmode.engine.h>

//  kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____
//
//  kamimodo SDK™ - Kinect - kinect controller integration example
//  - attaches Kinect's left and right hand position readings to two physical objects using skull.x 3d model
//  - fills the scene with infinitely falling skull physical objects
//  - allows interacting with scene objects using hand movements
//
//  レ  ク  サ  ー

typedef class KinectSample : public EngineRuntime { $
    NxPhysicsScene3d* scene = nullptr;
    PhysicsEntity3d* leftHandObject = nullptr;
    PhysicsEntity3d* rightHandObject = nullptr;
    List<PhysicsEntity3d*> skulls;
    List<PhysicsEntity3d*> allEntities;
    float3 leftHandPosition = { 0, 0, 20 };
    float3 rightHandPosition = { 0, 0, 20 };
    constructor(KinectSample() : EngineRuntime() {
        this->scene = (NxPhysicsScene3d*) godmode::$_sceneManager->addScene3d();
        this->scene->addEntity(this->leftHandObject = $_entityFactory->createObject3d(params$(Object3d,
            _.position = { 0, 0, 20 };
            _.scale = { 1.5, 1.5, 1.5 };
            _.model = this->scene->content->addModel("models/skull/skull.x");
            _.physicsEntityType = PhysicsEntityType::SPHERE;
            _.mass = 5;
        )));
        this->scene->addEntity(this->rightHandObject = $_entityFactory->createObject3d(params$(Object3d,
            _.position = { 0, 0, 20 };
            _.scale = { 1.5, 1.5, 1.5 };
            _.model = this->scene->content->addModel("models/skull/skull.x");
            _.physicsEntityType = PhysicsEntityType::SPHERE;
            _.mass = 5;
        )));
        List<PhysicsEntity3d*> allEntities;
        allEntities.add(this->leftHandObject);
        allEntities.add(this->rightHandObject);
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < 30; i++)
                this->scene->addEntity(this->skulls.add($_entityFactory->createObject3d(params$(Object3d,
                    _.position = { i * 2 - 30, 15 - j * 2, 20 };
                    _.model = this->scene->content->addModel("models/skull/skull.x");
                    _.physicsEntityType = PhysicsEntityType::SPHERE;
                    _.mass = 1;
                ))).back());
        allEntities.add(this->skulls);
        allEntities.forEach([](PhysicsEntity3d* p3d) {
            p3d->pxRigidDynamic->setRigidDynamicLockFlags(PxRigidDynamicLockFlag::eLOCK_LINEAR_Z);
        });
        this->leftHandObject->pxRigidDynamic->setRigidBodyFlag(PxRigidBodyFlag::eKINEMATIC, false);
        this->rightHandObject->pxRigidDynamic->setRigidBodyFlag(PxRigidBodyFlag::eKINEMATIC, false);
        this->leftHandObject->pxRigidDynamic->setMass(2.0f);
        this->rightHandObject->pxRigidDynamic->setMass(2.0f);
    })
    void update() override {
        this->leftHandPosition = godmode::$_kinect->leftHandPosition;
        this->rightHandPosition = godmode::$_kinect->rightHandPosition;
        this->leftHandPosition.z = this->rightHandPosition.z = 20;
        auto applyTargetVelocity = [&](PhysicsEntity3d* entity, const float3& targetPos) {
            PxVec3 currentPos = entity->pxRigidDynamic->getGlobalPose().p;
            PxVec3 target = PxVec3(targetPos.x, targetPos.y, targetPos.z);
            PxVec3 delta = target - currentPos;
            PxVec3 velocity = delta * 20.0;
            entity->pxRigidDynamic->setLinearVelocity(velocity);
            entity->pxRigidDynamic->setAngularVelocity(PxVec3(0));
        };
        applyTargetVelocity(this->leftHandObject, this->leftHandPosition);
        applyTargetVelocity(this->rightHandObject, this->rightHandPosition);
        for (int i = 0; i < 60; i++)
            if (this->skulls[i]->getPositionY() < -10.0) {
                this->skulls[i]->setPosition(float3((i%30) * 2 - 30, 15 - Math::random(-2, 3), 20));
                this->skulls[i]->pxRigidDynamic->setLinearVelocity(PxVec3(0.0f));
                this->skulls[i]->pxRigidDynamic->setAngularVelocity(PxVec3(0.0f));
            }
    }
} App;