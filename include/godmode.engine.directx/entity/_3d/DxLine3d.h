#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_3d/Line3d.h>

godmode_engine_directx_entity__3d(class DxLine3d : public Line3d { $
    LPDIRECT3DVERTEXBUFFER9 vb = nullptr;
    constructor(DxLine3d(const Line3dParams& params = Line3dParams()))
    destructor$(DxLine3d())
    void render();
    void recreate();
    void createVertexBuffer();
    s11n$declareSplit()
})
s11n$export(DxLine3d);