#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class Bloom : public Effect { $
    private$(float baseSaturation = 1)
    private$(float baseIntensity = 1)
    private$(float bloomSaturation = 1)
    private$(float bloomIntensity = 1)
    private$(float threshold = .5f)
    private$(float pixelPerturbModifier = 4)
    private$(float pixelWeightModifier = 4)
    private$(unsigned numSamples = 15)
    Texture* downSampledTexture = nullptr;
    Texture* downSampledTextureBuffer = nullptr;
    Sprite* downSampledSprite = nullptr;
    constructor(Bloom(JSON config = JSON::null))
    destructor$(Bloom())
    void setBaseSaturation(float value);
    void setBaseIntensity(float value);
    void setBloomSaturation(float value);
    void setBloomIntensity(float value);
    void setThreshold(float value);
    void setNumSamples(unsigned value);
    void setPixelPerturbModifier(float value);
    void setPixelWeightModifier(float value);
    float getBaseSaturation() const;
    float getBaseIntensity() const;
    float getBloomSaturation() const;
    float getBloomIntensity() const;
    float getThreshold() const;
    unsigned getNumSamples() const;
    float getPixelPerturbModifier() const;
    float getPixelWeightModifier() const;
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(Bloom);