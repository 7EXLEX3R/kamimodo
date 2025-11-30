#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class EdgeDetect : public Effect { $
    float intensity = 1;
    constructor(EdgeDetect(JSON config = JSON::null))
    destructor$(EdgeDetect())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})