#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/entity/_2d/Line2dFixed.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_directx_entity__2d(class DxLine2dFixed : public Line2dFixed { $
    constructor(DxLine2dFixed(const Line2dFixedParams& params = Line2dFixedParams()))
    destructor$(DxLine2dFixed())
    void render();
    private$(LPDIRECT3DVERTEXBUFFER9 vb = nullptr)
    private$(void createVertexBuffer())
})