#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/ViewFrustum.h>
#include <godmode.engine/math/Math.h>
#include <godmode.engine/math/float4x4.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_logic(struct CameraParams {
    float fov = .3;
    float2 displaySize = float2(0, 0);
    bool orthographic = false;
    float minDepth = 0.05;
    float maxDepth = 150000;
})
godmode_engine_logic(class Camera : virtual public CameraParams { $
    float4x4 lastProjectionMatrix;
    float4x4 projectionMatrix;
    float4x4 lastViewMatrix;
    float4x4 viewMatrix;
    float4x4 viewInverseMatrix;
    float4x4 viewProjectionMatrix;
    float4x4 lastViewProjectionMatrix;
    float3 up;
    float3 right;
    float3 front;
    float baseFov = 0.3;
    ViewFrustum *viewFrustum;
    constructor(Camera(const CameraParams& params))
    destructor$(Camera())
    void setDisplaySize(float2 &displaySize);
    float2 getDisplaySize() const;
    void setDisplaySizeToDefault();
    void updateViewProjection();
    virtual void updateView() = 0;
    virtual void updateProjection() = 0;
    virtual void refresh() = 0;
    s11n$declare()
})
// s11n$exportImplementation( Camera );