#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.foundation/events/Event.h>

godmode_engine_events(class Scene3dChangeEvent : public Event { $
    Scene3d *currentScene = nullptr;
    Scene3d *previousScene = nullptr;
    constructor(Scene3dChangeEvent(Scene3d *currentScene, Scene3d *previousScene))
    destructor$(Scene3dChangeEvent())
})