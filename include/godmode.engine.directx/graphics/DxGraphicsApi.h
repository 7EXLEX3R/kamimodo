#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/graphics/GraphicsApi.h>

godmode_engine_directx_graphics(class DxGraphicsApi : public GraphicsApi { $
    IDirect3D9 *dxCore = nullptr;
    constructor(DxGraphicsApi())
    destructor$(DxGraphicsApi())
    void fillSupportedDisplayModesList();
})