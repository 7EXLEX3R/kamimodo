#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Font.h>

godmode_engine_graphics(class FontMock : public Font { $
    constructor(FontMock() : Font() {})
    constructor(FontMock(String fontFace, int size, int weight = 500, bool italic = false)
        : Font(fontFace, size, weight, italic) {})
    destructor$(FontMock() {})
    virtual bool load(String path, String name = "") { return true; };
    virtual void render(String text, float4 &color, float2 &fieldSize = float2(0, 0), float2 &padding = float2(0, 0), int fontDrawingOptions = int(FontDrawingOptions::LEFT)) {};
    virtual float2 calculateTextSize(String text, float2 size = float2(0, 0)) { return float2(0, 0); };
    virtual void calculateCharactersWidth() {};
    s11n$defineInline({
        ar.template register_type<FontMock>();
        ar &boost::serialization::base_object<Font>(*this);
    });
})
s11n$export(FontMock);
s11n$instantiate(FontMock);