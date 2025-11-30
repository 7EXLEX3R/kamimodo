#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Renderer.h>
#include <godmode.engine/logic/SceneAttachable.h>
#include <godmode.engine/logic/_2d/Scene2d.h>
#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.engine/physics/NxPhysicsScene3d.h>

godmode_engine_logic(class SceneManager { $
    List<Scene2d*> _2dScenes;
    List<Scene3d*> _3dScenes;
    List<SceneAttachable<Scene2d>*> scene2dAttachments;
    List<SceneAttachable<Scene3d>*> scene3dAttachments;
    Scene2d* activeScene2d = nullptr;
    Scene3d* activeScene3d = nullptr;
    Effect* sceneMerge = nullptr;
    constructor(SceneManager())
    destructor$(SceneManager())
    Scene2d* addScene2d(bool active = false);
    Scene2d* addExistingScene2d(Scene2d* scene, bool active = false);
    void removeScene2d(Scene2d* scene, bool _delete = false);
    void setActiveScene2d(Scene2d* scene);
    SceneAttachable<Scene2d>* addScene2dAttachable(SceneAttachable<Scene2d>* attachable);
    void removeScene2dAttachable(SceneAttachable<Scene2d>* attachable);
    Scene3d* addScene3d(bool active = false);
    Scene3d* addExistingScene3d(Scene3d* scene, bool active = false);
    void removeScene3d(Scene3d* scene, bool _delete = false);
    void setActiveScene3d(Scene3d* scene);
    SceneAttachable<Scene3d>* addScene3dAttachable(SceneAttachable<Scene3d>* attachable);
    void removeScene3dAttachable(SceneAttachable<Scene3d>* attachable);
    void update();
    void render();
    void blank();
    s11n$declare()
})
godmode_engine_logic$extern($_sceneManager, SceneManager*)