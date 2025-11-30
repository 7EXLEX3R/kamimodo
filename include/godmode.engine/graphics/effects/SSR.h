#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class SSR : public Effect { $
    int numSamples = 10;
    float baseLength = 2;
    float fresnelPower = 3;
    float fresnelBias = 0;
    float blurBias = 4.0;
    float blurModifier = 4.0;
    int blurSamples = 2;
    constructor(SSR(JSON config = JSON::null))
    destructor$(SSR())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    virtual void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(SSR);