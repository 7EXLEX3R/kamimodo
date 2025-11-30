#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/LogicEntity3d.h>

godmode_engine_logic__3d(struct Camera3dParams : virtual CameraParams, virtual LogicEntity3dParams {})
godmode_engine_logic__3d(class Camera3d : virtual public Camera3dParams, public Camera, public LogicEntity3d { $
    float3 rotationPassed;
    constructor(Camera3d(const Camera3dParams& params = Camera3dParams()))
    destructor$(Camera3d())
    virtual void updateView();
    virtual void updateProjection();
    virtual void updateRotationMatrix();
    virtual void updateAxes();
    bool sphereInFrustum(float3 &center, float radius);
    bool cubeInFrustum(float3 &minCorner, float3 &maxCorner);
    void refresh();
    s11n$declare()
})
s11n$export(Camera3d);