#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/EditorSettings.h>
#include <godmode.engine/editor/Project.h>
#include <godmode.engine/editor/Selector.h>
#include <godmode.engine/editor/TransformController.h>
#include <godmode.engine/events/ContentChangeEvent.h>
#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/Refreshable.h>
#include <godmode.engine/logic/SceneAttachable.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.foundation/events/EventListener.h>

godmode_engine_editor(class EditorEngine : public SceneAttachable<Scene3d>, public EventListener<ContentChangeEvent> { $
    Camera3d *camera = nullptr;
    Camera *cameraBuffer = nullptr;
    bool editMode = false;
    bool moveCameraMode = false;
    Selector *selector = nullptr;
    TransformController *transformController = nullptr;
    Model *model = nullptr;
    Object3d *newObject3d = nullptr;
    Project *project = nullptr;
    EditorSettings *settings = nullptr;
    constructor(EditorEngine(Project *project, EditorSettings *settings))
    destructor$(EditorEngine())
    void preprocess();
    void process();
    void rotateCamera();
    void toggleEditMode();
    void toggleEditMode(bool editMode);
    void setModel(Model *model);
    void handleEvent(ContentChangeEvent *event);
    void setSnap(float positionSnap = 0, float rotationSnap = 0, float scaleSnap = 0);
    virtual void attachTo(Scene3d *relativeScene = 0);
    virtual void detachFrom(Scene3d *relativeScene = 0);
})