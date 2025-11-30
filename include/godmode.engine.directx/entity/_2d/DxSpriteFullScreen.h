#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_2d/SpriteFullScreen.h>

godmode_engine_directx_entity__2d(class DxSpriteFullScreen : public SpriteFullScreen { $
    LPDIRECT3DVERTEXBUFFER9 vb = nullptr;
    LPDIRECT3DINDEXBUFFER9 ib = nullptr;
    constructor(DxSpriteFullScreen(const SpriteFullScreenParams& params = SpriteFullScreenParams()))
    destructor$(DxSpriteFullScreen())
    void render();
    void createVertexBuffer();
    void createIndexBuffer();
    void recreate();
    s11n$declareSplit()
})
s11n$export(DxSpriteFullScreen);