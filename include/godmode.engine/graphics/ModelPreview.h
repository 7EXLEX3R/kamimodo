#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/logic/_3d/Scene3d.h>

godmode_engine_graphics(class ModelPreview { $
    Scene3d* scene3d = nullptr;
    Texture* texture = nullptr;
    Object3d* object3d = nullptr;
    Camera3d* camera3d = nullptr;
    Model* model = nullptr;
    constructor(ModelPreview())
    destructor$(ModelPreview())
    void update();
    void setModel(Model* model);
})