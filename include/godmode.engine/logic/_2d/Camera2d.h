#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/LogicEntity2d.h>

godmode_engine_logic__2d(struct Camera2dParams : virtual CameraParams, virtual LogicEntity2dParams {})
godmode_engine_logic__2d(class Camera2d : virtual public Camera2dParams, public Camera, public LogicEntity2d { $
    constructor(Camera2d(const Camera2dParams& params = Camera2dParams()))
    destructor$(Camera2d())
    virtual void updateView();
    virtual void updateProjection();
    bool sphereInFrustum(float2 &center, float radius);
    bool cubeInFrustum(float2 &minCorner, float2 &maxCorner);
    void refresh();
    s11n$declare()
})
s11n$export(Camera2d);