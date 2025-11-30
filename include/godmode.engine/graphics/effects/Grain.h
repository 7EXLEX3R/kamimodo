#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class Grain : public Effect { $
    float power = 0.02;  // [0.00 to 1.00] Intensity of applied grain
    bool isColored = false;  // [0 or 1] Whether grain should be colored or not
    float colorAmount = 0.6;  // [0.00 to 1.00] Amount of color to add to grain
    float size = 1.6;  // [1.50 to 2.50] Size of individual pieces of grain
    float brightness = 1;  // [0.00 to 1.00] Grain brightness $
    constructor(Grain(JSON config = JSON::null))
    destructor$(Grain())
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setPower(float power);
    void setIsColored(bool isColored);
    void setColorAmount(float colorAmount);
    void setSize(float size);
    void setBrightness(float brightness);
    float getPower() const;
    bool getIsColored() const;
    float getColorAmount() const;
    float getSize() const;
    float getBrightness() const;
    void postProcess(MappedList<String, Texture*> mapTextures);
    s11n$declare()
})
s11n$export(Grain);