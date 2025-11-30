#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/graphics/Font.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_entity__2d(struct Text2dParams : virtual SpriteParams {
    String value = "";
    Font* font = nullptr;
    float2 origin = float2(0, 0);
    float2 padding = float2(0, 0);
    float2 textScroll = float2(0, 0);
    int fontDrawingOptions = int(FontDrawingOptions::LEFT);
    Texture* fontTexture = nullptr;
    float4 backgroundColor = float4(0, 0, 0, 0);
})
#define Text2dParams_$(params) Text2dParams(params), SpriteParams_$(params)
godmode_engine_entity__2d(class Text2d : virtual public Text2dParams, public Sprite { $
    constructor(Text2d(const Text2dParams& params = Text2dParams()))
    destructor$(Text2d())
    virtual String getValue();
    virtual void setValue(String value);
    virtual void setPadding(float2 &padding);
    virtual void setColor(const float4 &color, bool immediately = true);
    virtual void setFontDrawingOptions(int fontDrawingOptions);
    virtual void setSize(float2 &size);
    float2 getValueTextSize();
    protected$(void preRender())
})