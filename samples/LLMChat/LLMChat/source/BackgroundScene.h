#pragma once
#include <godmode.foundation.h>
#include <godmode.engine.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

class BackgroundScene { $
    Camera *camera = nullptr;
	Scene3d* scene = nullptr;
    Model* skullModel = nullptr;
    Texture* normalTexture;
    Shader* postEffectShader;
    List<LogicEntity3d*> skulls;
    const int skullCount = 32;
    List<float3> skullBasePositions;
    List<float3> skullBaseRotations;
    float minY = 0;
    float maxY = 0;
    float3 postEffectColorMultiplier = { 4, 0, 0 };
    float3 postEffectColorMultiplierDest = { 4, 0, 0 };
    BackgroundScene() {
        this->initPostEffect();
        this->initSceneBasics();
        this->initSkulls();
    }
    void initPostEffect() {
        this->postEffectShader = godmode::$_content->addShader("shaders/post-effect.fx");
        this->normalTexture = godmode::$_content->addTexture("textures/normal.png");
        this->postEffectShader->injectTexture("extraNormalTexture", this->normalTexture);
    }
    void initSceneBasics() {
        this->scene = godmode::$_sceneManager->addScene3d();
        this->scene->addCamera(this->camera = new$(Camera3d,
            _.position = { -2.66256, -8.87448, -3.18011 };
            _.rotation = { -13.05, 45.09, 0.0 };
            _.fov = 0.535;
        ));
        this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.model = this->scene->content->addModel("models/skybox/skybox.x");
            _.shader = this->scene->content->addShader("shaders/skybox.fx");
            _.scale = { .1, .1, .1 };
        )));
        this->skullModel = this->scene->content->addModel("models/skull/skull.x");
    }
    void initSkulls() {
        float skullScale = 1.6;
        float skullRadius = this->skullModel->radius * skullScale;
        this->skullBasePositions.add({ 0, 0, 0 });
        for (int i = 1; i < skullCount; i++) {
            this->skullBasePositions.add(float3(Math::random(-1, 1), Math::random(-20, 20), Math::random(-1, 1)) * skullRadius);
            if (this->skullBasePositions.back()->y < this->minY)
                this->minY = this->skullBasePositions.back()->y;
            if (this->skullBasePositions.back()->y > this->maxY)
                this->maxY = this->skullBasePositions.back()->y;
        }
        float maxAngle = 60;
        for (int i = 0; i < skullCount; i++)
            this->skullBaseRotations.add({
                Math::random(-maxAngle, maxAngle),
                Math::random(-maxAngle, maxAngle),
                Math::random(-maxAngle, maxAngle)
            });
        for (int i = 0; i < skullCount; i++) {
            this->skulls.add(this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
                _.position = this->skullBasePositions[i];
                _.rotation = this->skullBaseRotations[i];
                _.scale = skullScale;
                _.model = this->skullModel;
            ))));
        }
    }
    void update() {
        this->handleSkullsMovement();
        this->handlePostEffect();
    }
    void handleSkullsMovement() {
        List<LogicEntity3d*> sortedSkulls = this->skulls;
        sortedSkulls.sort(function$((LogicEntity3d * a, LogicEntity3d * b), a->position.y < b->position.y));
        for (int i = 0; i < skullCount; i++) {
            this->skulls[i]->moveY(-4);
            this->skulls[i]->roll(40);
            if (this->skulls[i]->position.y < this->minY)
                this->skulls[i]->setPositionY(this->maxY);
        }
    }
    void handlePostEffect() {
        this->postEffectColorMultiplier += Math::transition<float3>(this->postEffectColorMultiplier, this->postEffectColorMultiplierDest, 50, true);
        this->postEffectShader->injectFloat3("postEffectColorMultiplier", this->postEffectColorMultiplier);
    }
};