#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_3d/Object3d.h>

godmode_engine_directx_entity__3d(class DxObject3d : public Object3d { $
    constructor(DxObject3d(const Object3dParams& params = Object3dParams()))
    destructor$(DxObject3d())
    void render();
    s11n$declare()
})
s11n$export(DxObject3d);