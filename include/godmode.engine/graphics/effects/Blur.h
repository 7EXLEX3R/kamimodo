#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class Blur : public Effect { $
    private$(float intensity = 1)
    private$(float blur = 1)
    private$(unsigned numSamples = 8)
    private$(float pixelPerturbModifier = 4)
    private$(float pixelWeightModifier = 4)
    Texture* downSampledTexture = nullptr;
    Texture* downSampledTextureBuffer = nullptr;
    Sprite* downSampledSprite = nullptr;
    constructor(Blur(JSON config = JSON::null))
    destructor$(Blur())
    void setNumSamples(unsigned value);
    void setPixelPerturbModifier(float value);
    void setPixelWeightModifier(float value);
    void setIntensity(float intensity);
    void setBlur(float blur);
    unsigned getNumSamples() const;
    float getPixelPerturbModifier() const;
    float getPixelWeightModifier() const;
    float getIntensity() const;
    float getBlur() const;
    void postProcess(MappedList<String, Texture*> mapTextures);
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    s11n$declare()
})
s11n$export(Blur);