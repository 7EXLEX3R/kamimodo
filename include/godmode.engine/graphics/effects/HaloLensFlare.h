#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class HaloLensFlare : public Effect { $
    float threshold = 0.7;
    float pixelPerturbModifier = 4;
    float pixelWeightModifier = 4;
    unsigned numSamples = 16;
    float intensity = 0.4;
    float bias = 10.0;
    unsigned flaresCount = 8;
    float dispersal = 0.3;
    float haloWidth = 0.6;
    float chromeDistortion = 3;
    float dirtIntensity = 0.5;
    float baseIntensity = 1;
    Texture* downSampledTexture = nullptr;
    Texture* downSampledTextureBuffer = nullptr;
    Sprite* downSampledSprite = nullptr;
    Texture* dirtTexture = nullptr;
    constructor(HaloLensFlare(JSON config = JSON::null))
    destructor$(HaloLensFlare())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setThreshold(float value);
    void setNumSamples(unsigned value);
    void setPixelPerturbModifier(float value);
    void setPixelWeightModifier(float value);
    float getThreshold() const;
    unsigned getNumSamples() const;
    float getPixelPerturbModifier() const;
    float getPixelWeightModifier() const;
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(HaloLensFlare);