#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/logic/_3d/Light.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_logic(class Lightning { $
    bool enabled = true;
    Light* ambient = nullptr;
    List<Light*> lights;
    constructor(Lightning())
    destructor$(Lightning())
    Light* addLight(Light* light);
    Light* removeLight(Light* light);
    void update(MappedList<String, Shader*>* shadersToUpdate = 0);
    s11n$declareSplit()
})