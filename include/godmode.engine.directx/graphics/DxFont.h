#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/graphics/Font.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine.directx/graphics/DxGraphicsDevice.h>

godmode_engine_directx_graphics(class DxFont : public Font { $
    LPD3DXFONT dxFont = nullptr;
    constructor(DxFont())
    constructor(DxFont(String fontFace, int size, int weight = 500, bool italic = false))
    destructor$(DxFont())
    virtual bool load(String path, String name = "");
    void render(
        String text,
        float4 &color,
        float2 &fieldSize = float2(0, 0),
        float2 &padding = float2(0, 0),
        int fontDrawingOptions = int(FontDrawingOptions::LEFT));
    float2 calculateTextSize(String text, float2 size = float2(0, 0));
    void calculateCharactersWidth();
    s11n$declareSplit()
})
s11n$export(DxFont);