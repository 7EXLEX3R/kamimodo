#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/ColorChannel.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_graphics(class Color { $
    float r = 0;
    float g = 0;
    float b = 0;
    float a = 1;
    constructor(Color(float r = 0, float g = 0, float b = 0, float a = 1))
    constructor(Color(unsigned long hexColor))
    destructor$(Color())
    float getRed();
    float getGreen();
    float getBlue();
    float getAlpha();
    void setRed(float r = 0);
    void setGreen(float g = 0);
    void setBlue(float b = 0);
    void setAlpha(float a = 0);
    void fromHex(unsigned long hexColor);
    static float getFromHexToNormalizedColorChannelValue(ColorChannel cc, unsigned long hexColor);
    static float4 getFromHexToNormalizedColorValue(unsigned long hexColor);
    static unsigned long getFromNormalizedToHexColorValue(float4 &color);
})