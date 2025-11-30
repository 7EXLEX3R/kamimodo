#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>

godmode_engine_directx_graphics(const DWORD SPRITE_FIXED_VERTEX_DECLARATION = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
godmode_engine_directx_graphics(struct SPRITE_FIXED_VERTEX {
    float2Struct position;
    float2Struct zw;
    DWORD color;
    float2Struct uv;
})
godmode_engine_directx_graphics(const DWORD SPRITE_VERTEX_DECLARATION = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE2(0))
godmode_engine_directx_graphics(struct SPRITE_VERTEX {
    float2Struct position;
    float z;
    float2Struct uv;
})
godmode_engine_directx_graphics(const DWORD LINE2D_FIXED_VERTEX_DECLARATION = D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
godmode_engine_directx_graphics(struct LINE2D_FIXED_VERTEX {
    float2Struct position;
    float2Struct zw;
    DWORD color;
})
godmode_engine_directx_graphics(const DWORD LINE2D_VERTEX_DECLARATION = D3DFVF_XYZ | D3DFVF_DIFFUSE)
godmode_engine_directx_graphics(struct LINE2D_VERTEX {
    float2Struct position;
    float z;
    DWORD color;
})
godmode_engine_directx_graphics(const DWORD LINE3D_VERTEX_DECLARATION = D3DFVF_XYZ | D3DFVF_DIFFUSE)
godmode_engine_directx_graphics(struct LINE3D_VERTEX {
    float3Struct position;
    DWORD color;
})