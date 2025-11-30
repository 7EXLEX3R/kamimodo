#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity2d.h>

godmode_engine_entity__2d(struct Line2dParams : virtual BaseEntity2dParams {
    float2 startPoint = {0, 0};
    float2 endPoint = {1, 0};
})
#define Line2dParams_$(params) Line2dParams(params), BaseEntity2dParams_$(params)
godmode_engine_entity__2d(class Line2d : virtual public Line2dParams, public BaseEntity2d { $
    constructor(Line2d(const Line2dParams& params = Line2dParams()))
    destructor$(Line2d())
})