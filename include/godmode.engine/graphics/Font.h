#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/FontDrawingOptions.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.foundation/file/ContentItem.h>

godmode_engine_graphics(class Font : public ContentItem { $
    String fontFace;
    int size = 0;
    int weight = 0;
    bool italic = false;
    int charactersWidth[256];
    constructor(Font())
    constructor(Font(String fontFace, int size, int weight = 500, bool italic = false))
    destructor$(Font())
    int getTextWidth(String text);
    virtual bool load(String path, String name = "") = 0;
    virtual void render(
        String text,
        float4 &color,
        float2 &fieldSize = float2(0, 0),
        float2 &padding = float2(0, 0),
        int fontDrawingOptions = int(FontDrawingOptions::LEFT)
    ) = 0;
    virtual float2 calculateTextSize(String text, float2 size = float2(0, 0)) = 0;
    virtual void calculateCharactersWidth() = 0;
    s11n$declare()
})