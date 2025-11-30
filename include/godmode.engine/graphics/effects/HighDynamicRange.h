#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class HighDynamicRange : public Effect {
    private$(float baseSaturation = 1)
    private$(float baseIntensity = 1)
    private$(float bloomSaturation = 1)
    private$(float bloomIntensity = 0.25)
    private$(float threshold = 0.3)
    private$(float pixelPerturbModifier = 4)
    private$(float pixelWeightModifier = 8)
    private$(unsigned numSamples = 16)
    private$(float middleGray = 0.6)
    private$(float3 luminanceVector = { 0.2125f, 0.7154f, 0.0721f })
    private$(float3 blueShiftVector = { 1.05f, 0.97f, 1.27f })
    private$(bool isToneMappingEnabled = true)
    private$(bool isBlueShiftEnabled = false)
    Texture* downSampledTexture = nullptr;
    Texture* downSampledTextureBuffer = nullptr;
    Sprite* downSampledSprite = nullptr;
    Texture* toneTextureMap64 = nullptr;
    Sprite* toneMapSprite64 = nullptr;
    Texture* toneTextureMap16 = nullptr;
    Sprite* toneMapSprite16 = nullptr;
    Texture* toneTextureMap4 = nullptr;
    Sprite* toneMapSprite4 = nullptr;
    Texture* toneTextureMap1 = nullptr;
    Sprite* toneMapSprite1 = nullptr;
    Texture* luminanceTexture = nullptr;
    Texture* luminanceTextureLast = nullptr;
    constructor(HighDynamicRange(JSON config = JSON::null))
    destructor$(HighDynamicRange())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
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
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(HighDynamicRange);