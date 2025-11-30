#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Logger.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/graphics/CubeTexture.h>

godmode_engine_directx_graphics(class DxCubeTexture : public CubeTexture { $
    LPDIRECT3DCUBETEXTURE9 dxCubeTexture = nullptr;
    LPDIRECT3DSURFACE9 dxStencil[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    constructor(DxCubeTexture())
    constructor(DxCubeTexture(int size, String name = "tTexture"))
    destructor$(DxCubeTexture())
    bool create(int size, String name = "");
    void recreate();
    void beginRenderOn(CubeTextureFace cubeTextureFace, bool beginRendering = true, int renderStage = 0);
    void endRenderOn(CubeTextureFace cubeTextureFace);
    private$(Logger<DxCubeTexture> logger{this})
    s11n$declareSplit()
})
s11n$export(DxCubeTexture);