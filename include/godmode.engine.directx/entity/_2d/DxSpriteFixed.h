#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_2d/SpriteFixed.h>

godmode_engine_directx_entity__2d(class DxSpriteFixed : public SpriteFixed { $
    constructor(DxSpriteFixed(const SpriteFixedParams& params = SpriteFixedParams()))
    destructor$(DxSpriteFixed())
    void render();
    protected$(void createVertexBuffer())
    protected$(void createIndexBuffer())
    protected$(LPDIRECT3DVERTEXBUFFER9 vb = nullptr)
    protected$(LPDIRECT3DINDEXBUFFER9 ib = nullptr)
})