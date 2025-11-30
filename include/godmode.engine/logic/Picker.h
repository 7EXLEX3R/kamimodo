#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine/math/Plane.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_logic(struct PickerProduct {
    ModelVertex vertices[3];
    Plane verticesPlane;
    float planeDistance = 0;
    bool picked = false;
})
godmode_engine_logic(class Picker { $
    static bool isRayIntersectingTriangle(float3& position, float3& direction, float3& v0, float3& v1, float3& v2);
    static PickerProduct pick(float3& position, float3& direction, Object3d* object);
})