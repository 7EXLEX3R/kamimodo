#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/logic/Lightning.h>
#include <godmode.engine/logic/Scene.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/logic/_3d/Octree.h>

godmode_engine_logic__3d(class Scene3d : public Scene<BaseEntity3d> { $
    constructor(Scene3d(int viewportWidth = 0, int viewportHeight = 0))
    constructor(Scene3d(String rendererConfig))
    destructor$(Scene3d())
    void updateEntities();
    void render();
    s11n$declare()
})