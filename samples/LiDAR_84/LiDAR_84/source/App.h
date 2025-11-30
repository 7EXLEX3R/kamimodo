#pragma once
#include <godmode.foundation.h>
#include <godmode.engine.h>

//  kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____
//
//  kamimodo SDK™ - LiDAR_84 - character controller placed inside of physical, 3d-scanned real-world
//                             locations with oversaturated postprocessing effects example
//  - allows moving the character using mouse movement to look around and keyboard keys:
//    WSAD - move; LShift - run; LCtrl - crouch; Space - jump
//  - allows controlling camera field of view value using Z / X keys
//  - shows live shader/custom.fx coding possibility
//  - shows live config/effects.json reconfiguration possibility
//
//  # effect config/shader live changes are applied on LCtrl + S keys press
//  # each fall-off of "the map" causes a respawn in one of 4 predefined spots; there
//    is a brightness controller causing brightness to go down while getting closer
//    to the limit on Y axis, which is responsible for triggering respawn
//  # press LCtrl + LAlt keys to toggle lockCursor mode
// 
//  レ  ク  サ  ー

typedef class LiDAR_84Sample : public EngineRuntime { $
    Camera3d* camera = nullptr;
	NxPhysicsScene3d* scene = nullptr;
    NxCharacterController* controller = nullptr;
    Shader* customShader = nullptr;
    float baseBrightness;
    float brightness;
    float destBrightness;
    ColorAdjust* colorAdjust;
    List<float3> respawnPositions = {
        { -4.15232, -18.8805, 4.18166 },
        { 12.8867, -23.0002, -35.6011 },
        { 16.3976, -19.0409, 30.8789 },
        { -22.0113, -16.6896, 20.9471 }
    };
    List<float3> respawnRotations = {
        { 13.38, 57.24, 0.0 },
        { -12.24, 369.33, 0.0 },
        { -3.21, 899.22, 0.0 },
        { -17.7, -50.7897, 0.0 }
    };
	LiDAR_84Sample() : EngineRuntime() {
        this->initSceneBasics();
        this->initSceneCameraController();
        this->initSceneObjects();
	}
	void initSceneBasics() {
	    this->customShader = godmode::$_content->addShader("shaders/custom.fx");
        this->scene = (NxPhysicsScene3d*) godmode::$_sceneManager->addScene3d();
        this->scene->lightning->ambient->color = {1, 1, 1, 1};
        this->scene->lightning->ambient->direction = {.8, -.33, 1.0};
        this->colorAdjust = this->scene->effects->colorAdjustEffects.back();
        this->baseBrightness = this->destBrightness = this->brightness = 1;
	}
	void initSceneCameraController() {
	    this->scene->addCamera(this->camera = new$(Camera3d,
            _.position = *this->respawnPositions.at(0);
            _.rotation = *this->respawnRotations.at(0);
            _.fov = 0.535;
        ));
        this->controller = new NxCharacterController(this->camera->positionDest);
        this->controller->attachTo(this->scene);
	}
	void initSceneObjects() {
	    this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.scale = {.1, .1, .1};
            _.model = this->scene->content->addModel("models/skybox/skybox.x");
            _.shader = this->scene->content->addShader("shaders/hue-skybox.fx");
        )));
        this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.model = this->scene->content->addModel("models/84-hotel/84-hotel.x");
            _.physicsEntityType = PhysicsEntityType::MESH;
            _.position = float3(0, -20, 0);
            _.scale = float3(.15, .15, .15);
        )));
        this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.model = this->scene->content->addModel("models/84-ski-jump/84-ski-jump.x");
            _.physicsEntityType = PhysicsEntityType::MESH;
            _.position = float3(20, -20, 20);
            _.scale = float3(.3, .3, .3);
        )));
        this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.model = this->scene->content->addModel("models/84-building/84-building.x");
            _.physicsEntityType = PhysicsEntityType::MESH;
            _.position = float3(-35, -18, 35);
            _.rotation = float3(0, 0, 0);
            _.scale = float3(.10, .10, .10);
        )));
        this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.model = this->scene->content->addModel("models/84-track-area/84-track-area.x");
            _.physicsEntityType = PhysicsEntityType::MESH;
            _.position = float3(38, -20, -38);
            _.scale = float3(.1, .1, .1);
        )));
	}
	void update() override {
	    EffectsController::reloadShaderOnCtrlS(this->customShader);
	    EffectsController::reloadEffectsOnCtrlS(this->scene);
        this->controlCamera();
        this->respawnHandler();
	}
	void controlCamera() {
        float3 direction = godmode::$_systemWindow->isActive()
            ? CameraController::control(this->camera, true)
            : f3(0);
        float3 normal = {0, 1, 0};
        float3 displacement = {0, 0, 0};
        this->controller->move(direction, normal, displacement);
        this->camera->setPosition(this->controller->getPosition());
    }
	void respawnHandler() {
        if (this->camera->position.y < -25)
            this->brightness = this->destBrightness = Math::clamp(1 - (-25 - this->camera->position.y) * 0.04, 0.0, 20);
        else
            this->brightness += Math::transition<float>(this->brightness, this->destBrightness, 24, true);
        if (this->camera->position.y < -50) {
            this->destBrightness = this->baseBrightness;
            int respawnIndex = int(Math::random(0, 2048)) % 3;
            this->camera->setPosition(*this->respawnPositions.at(respawnIndex));
            this->camera->setRotation(*this->respawnRotations.at(respawnIndex));
            this->controller->setPosition(*this->respawnPositions.at(respawnIndex));
        }
        this->colorAdjust->color.x = this->colorAdjust->color.y = this->colorAdjust->color.z = this->brightness;
    }
	void update$active() override {
        this->controlCameraFov();
        this->controlAppTermination();
        this->controlSystemCursorLock();
    }
    void controlCameraFov() {
        if (godmode::$_inputApi->key(Key::X))
            this->scene->currentCamera->fov -= .015;
        if (godmode::$_inputApi->key(Key::Z))
            this->scene->currentCamera->fov += .015;
    }
    void controlAppTermination() {
        if (godmode::$_inputApi->key(Key::LCONTROL) && godmode::$_inputApi->key(Key::Q))
            this->terminate();
    }
    void controlSystemCursorLock() {
        if ($_keyboard->key(Key::LCONTROL) && $_keyboard->keyDown(Key::LALT))
            $_systemApi->lockCursor = !$_systemApi->lockCursor;
    }
} App;