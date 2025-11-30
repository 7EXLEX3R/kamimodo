#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/Component.h>

godmode_engine_ui_components(struct LabelParams : virtual ComponentParams {
    String title = "";
})
godmode_engine_ui_components(class Label : virtual public LabelParams, public Component { $
    Text2d *t2d = nullptr;
    constructor(Label(const LabelParams& params = LabelParams()))
    destructor$(Label())
})