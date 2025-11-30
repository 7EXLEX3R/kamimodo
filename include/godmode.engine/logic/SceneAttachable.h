#pragma once
#include <godmode.engine/$_namespaces.h>

#include <godmode.engine/logic/Scene.h>

godmode_engine_logic(template <class SceneType> class SceneAttachable { $
    SceneType *relativeScene = nullptr;  // TODO: scenelist
    constructor(SceneAttachable())
    destructor$(SceneAttachable())
    virtual void attachTo(SceneType *relativeScene = 0);
    virtual void detachFrom(SceneType *relativeScene = 0);
})