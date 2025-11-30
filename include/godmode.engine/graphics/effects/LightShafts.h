#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_graphics_effects(class LightShafts : public Effect {
    private$(Texture* brightPassTexture = nullptr)
    private$(Sprite* brightPassSprite = nullptr)
    private$(float threshold = 0.5)
    private$(float maxValue = 1)
    private$(float decay = 0.97)
    private$(float density = 0.6)
    private$(unsigned numSamples = 100)
    float3* lightPos = nullptr;
    constructor(LightShafts(JSON config = JSON::null))
    destructor$(LightShafts())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setThreshold(float t);
    void setMaxValue(float m);
    void setDecay(float d);
    void setDensity(float d);
    void setNumSamples(unsigned n);
    float getThreshold() const;
    float getMaxValue() const;
    float getDecay() const;
    float getDensity() const;
    unsigned getNumSamples() const;
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(LightShafts);