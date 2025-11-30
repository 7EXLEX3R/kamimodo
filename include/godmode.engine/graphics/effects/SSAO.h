#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class SSAO : public Effect { $
    float randomTextureSize = 64;
    float sampleRadius = 0.75;
    float intensity = 0.3;
    float scale = 1;
    float bias = 0.2;
    float range = 0.5;
    Texture *randomTexture = nullptr;
    constructor(SSAO(JSON config = JSON::null))
    destructor$(SSAO())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    virtual void postProcess(MappedList<String, Texture *> mapTextures);
    s11n$declare()
})
s11n$export(SSAO);