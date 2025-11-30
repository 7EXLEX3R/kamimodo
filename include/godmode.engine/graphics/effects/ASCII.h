#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class ASCII : public Effect { $
    float fragmentSize = 16;
    float intensity = 1;
    constructor(ASCII(JSON config = JSON::null))
    destructor$(ASCII())
    virtual void postProcess(MappedList<String, Texture*> mapTextures);
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    s11n$declare()
})
s11n$export(ASCII);