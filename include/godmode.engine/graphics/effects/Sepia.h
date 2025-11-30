#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class Sepia : public Effect {
    private$(float intensity = 1)
    constructor(Sepia(JSON config = JSON::null))
    destructor$(Sepia())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void postProcess(MappedList<String, Texture*> mapTextures);
    void setIntensity(float intensity);
    float getIntensity();
    s11n$declare()
})
s11n$export(Sepia);