#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Line3d.h>

godmode_engine_entity__3d(typedef Line3dParams LineBoxParams)
godmode_engine_entity__3d(class LineBox :public Line3d { $
    Line3d *lines[12] = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr
    };
    constructor(LineBox(const LineBoxParams& params = LineBoxParams()))
    destructor$(LineBox())
    void setBoundingPoints(float3 &startPoint, float3 &endPoint);
    void render();
    void update();
    void setColor(float4 &color, bool immediately = true);
    s11n$declare()
})
s11n$export(LineBox);