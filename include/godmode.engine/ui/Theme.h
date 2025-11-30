#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Font.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_ui(class Theme { $
    Font* font = nullptr;
    float4 primaryBackgroundColor;
    float4 secondaryBackgroundColor;
    float4 thirdBackgroundColor;
    float4 primaryTextColor;
    float4 secondaryTextColor;
    float4 thirdTextColor;
    float2 primaryPadding;
})
godmode_engine_ui$extern($_theme, Theme*)