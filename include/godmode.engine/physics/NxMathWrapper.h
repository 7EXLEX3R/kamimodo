#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/math/float4x4.h>

godmode_engine_physics(class NxMathWrapper { $
    static float3 radVector(float3 &nxVector);
    static float4x4 radMatrix(float3 &nxMatrix);
    static float3 nxVector(float3 &radVector);
    static float3 nxMatrix(float4x4 &radMatrix);
})