#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class DepthOfField : public Effect { $
    private$(float focalPlaneDistance = 0)
    private$(float focusBias = 16)
    private$(float maxValue = 0.75)
    private$(unsigned numSamples = 16)
    private$(float pixelPerturbModifier = 4)
    private$(float pixelWeightModifier = 4)
    Texture* downSampledTexture = nullptr;
    Texture* downSampledTextureBuffer = nullptr;
    Sprite* downSampledSprite = nullptr;
    constructor(DepthOfField(JSON config = JSON::null))
    destructor$(DepthOfField())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setFocalPlaneDistance(float distance);
    void setFocusBias(float bias);
    void setNumSamples(unsigned value);
    void setPixelPerturbModifier(float value);
    void setPixelWeightModifier(float value);
    void setMaxValue(float maxValue);
    float getFocalPlaneDistance() const;
    float getFocusBias() const;
    unsigned getNumSamples() const;
    float getPixelPerturbModifier() const;
    float getPixelWeightModifier() const;
    float getMaxValue() const;
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(DepthOfField);