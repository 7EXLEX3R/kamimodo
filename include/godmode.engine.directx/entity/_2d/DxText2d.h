#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_2d/Text2d.h>

godmode_engine_directx_entity__2d(class DxText2d : public Text2d { $
    constructor(DxText2d(const Text2dParams& params = Text2dParams()))
    destructor$(DxText2d())
    void render();
    private$(void createVertexBuffer())
    private$(void createIndexBuffer())
    private$(LPDIRECT3DVERTEXBUFFER9 vb = nullptr)
    private$(LPDIRECT3DINDEXBUFFER9 ib = nullptr)
})