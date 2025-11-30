#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/system/FpsMeter.h>

godmode_engine_graphics_effects(class Fog : public Effect {
    private$(float startDistance = 1)
    private$(float endDistance = 25)
    private$(float cutDistance = 250)
    private$(float maxValue = 0.8)
    private$(float4 color = {1, 1, 1, 1})
    constructor(Fog(JSON config = JSON::null))
    destructor$(Fog())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setStartDistance(float startDistance);
    void setEndDistance(float endDistance);
    void setCutDistance(float cutDistance);
    void setMaxValue(float maxValue);
    void setColor(float4 &color);
    float getStartDistance() const;
    float getEndDistance() const;
    float getFogDistance() const;
    float getMaxValue() const;
    float4 getColor() const;
    void postProcess(MappedList<String, Texture *> mapTextures);
    s11n$declare()
})
s11n$export(Fog);