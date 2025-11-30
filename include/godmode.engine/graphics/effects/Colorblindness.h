#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/effects/ColorblindnessType.h>

godmode_engine_graphics_effects(class ColorBlindness : public Effect { $
    private$(ColorblindnessType colorBlindnessType = ColorblindnessType::NONE)
    private$(float intensity = 1)
    constructor(ColorBlindness(JSON config = JSON::null))
    destructor$(ColorBlindness())
    void postProcess(MappedList<String, Texture*> mapTextures);
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setIntensity(float intensity);
    float getIntensity();
    void setColorBlindnessType(ColorblindnessType colorblindnessType);
    ColorblindnessType getColorBlindnessType();
    s11n$declare()
})
s11n$export(ColorBlindness);