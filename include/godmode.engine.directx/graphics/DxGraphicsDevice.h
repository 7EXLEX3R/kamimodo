#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/graphics/GraphicsDevice.h>

godmode_engine_directx_graphics(class DxGraphicsDevice : public GraphicsDevice { $
    IDirect3DSurface9 *dxSurface = nullptr;
    IDirect3DSurface9 *dxStencil = nullptr;
    IDirect3DDevice9 *dxDevice = nullptr;
    constructor(DxGraphicsDevice(Display *display = nullptr))
    destructor$(DxGraphicsDevice())
    void render(Texture* screenResultTexture);
    void setWorldTransform(float4x4* matrix);
    void setViewTransform(float4x4* matrix);
    void setProjectionTransform(float4x4* matrix);
    void cloneTexture(Texture* sourceTexture, Texture* destTexture);
})
godmode_engine_directx_graphics$extern($_dxGraphicsDevice, DxGraphicsDevice*)