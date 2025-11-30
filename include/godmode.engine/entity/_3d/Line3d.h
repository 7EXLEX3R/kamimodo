#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>

godmode_engine_entity__3d(struct Line3dParams : virtual BaseEntity3dParams {
    float3 startPoint = { 0, 0, 0 };
    float3 endPoint = { 1, 0, 0 };
})
godmode_engine_entity__3d(class Line3d : virtual public Line3dParams, public BaseEntity3d { $
    constructor(Line3d(const Line3dParams& params = Line3dParams()))
    destructor$(Line3d())
    s11n$declare()
})