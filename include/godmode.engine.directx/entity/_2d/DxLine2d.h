#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_directx_entity__2d(class DxLine2d : public Line2d { $
    constructor(DxLine2d(const Line2dParams& params = Line2dParams()))
    destructor$(DxLine2d())
    void render();
    private$(LPDIRECT3DVERTEXBUFFER9 vb = nullptr)
    private$(void createVertexBuffer())
})