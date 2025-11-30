#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/entity/_2d/Line2d.h>

godmode_engine_entity__2d(typedef Line2dParams LineRectangleParams)
godmode_engine_entity__2d(class LineRectangle : public Line2d { $
    Line2d *lines[4] = { nullptr, nullptr, nullptr, nullptr };
    constructor(LineRectangle(const LineRectangleParams& params = LineRectangleParams()));
    destructor$(LineRectangle())
    void setBoundingPoints(float2 &startPoint, float2 &endPoint);
    void render();
    void update();
})