#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>

godmode_engine_directx_graphics(struct DxStrip {
    LPDIRECT3DINDEXBUFFER9 dxIndexBuffer = nullptr;
    LPDIRECT3DINDEXBUFFER9 dxIndexBufferForMany = nullptr;
    DWORD indexCount = 0;
    DWORD* lengths = nullptr;
    DWORD count = 0;
    constructor(DxStrip())
    destructor$(DxStrip())
})