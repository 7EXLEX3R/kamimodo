#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Logger.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/graphics/Texture.h>

godmode_engine_directx_graphics(class DxTexture : public Texture { $
    LPDIRECT3DTEXTURE9 dxTexture = nullptr;
    LPDIRECT3DSURFACE9 dxSurface = nullptr;
    LPDIRECT3DSURFACE9 dxStencil = nullptr;
    DWORD usage = 0;
    int levels = 0;
    D3DFORMAT fmt = D3DFMT_UNKNOWN;
    D3DPOOL pool = D3DPOOL_DEFAULT;
    constructor(DxTexture())
    constructor(DxTexture(String path, String name = ""))
    constructor(DxTexture(int width, int height, String name = "tTexture"))
    destructor$(DxTexture())
    bool load(String path, String name = "");
    bool save(String path);
    bool create(int width, int height, String name = "tTexture");
    void beginRenderOn(bool beginRendering = true, int renderStage = 0, float4 &clearColor = float4(0, 0, 0, 0));
    void endRenderOn();
    Color getPixelColor(int x, int y);
    private$(Logger<DxTexture> logger{this})
    s11n$declareSplit()
})
s11n$export(DxTexture);