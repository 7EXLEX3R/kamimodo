#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class ColorAdjust : public Effect { $
    float brightness = 1;
    float contrast = 1;
    float gamma = 1;
    float4 color = {1, 1, 1, 1};
    float hueRotation = 0;
    constructor(ColorAdjust(JSON config = JSON::null))
    destructor$(ColorAdjust())
    virtual void postProcess(MappedList<String, Texture*> mapTextures);
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    s11n$declare()
})
s11n$export(ColorAdjust);