#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/Plane.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/math/float4x4.h>

godmode_engine_logic(class ViewFrustum { $
    Plane plane[6];
    void update(float4x4 *viewProjectionMatrixMatrix);
    bool sphereTest(float3 &center, float radius, int numPlanTests = 6);
    bool cubeTest(float3 *offsetPoints, int offsetPointsCount, int numPlanTests = 6);
    private$(void buildPlanarBoundingSpace(float4x4 *viewProjectionMatrix))
})