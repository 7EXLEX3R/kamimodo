#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>
#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class MotionBlur : public Effect {
    private$(float intensity = 1)
    private$(unsigned numSamples = 8)
    constructor(MotionBlur(JSON config = JSON::null))
    destructor$(MotionBlur())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setIntensity(float intensity);
    void setNumSamples(int numSamples);
    float getIntensity() const;
    unsigned getNumSamples() const;
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(MotionBlur);