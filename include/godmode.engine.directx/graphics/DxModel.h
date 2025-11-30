#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Logger.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine.directx/graphics/DxStrip.h>

godmode_engine_directx_graphics(class DxModel : public Model { $
    LPD3DXMESH dxMesh = nullptr;
    LPD3DXBUFFER dxAdjacencyBuffer = nullptr;
    LPDIRECT3DVERTEXBUFFER9 dxVertexBuffer = nullptr;
    LPDIRECT3DVERTEXDECLARATION9 dxVertexDeclaration = nullptr;
    DxStrip* strips = nullptr;
    constructor(DxModel())
    constructor(DxModel(String path, String name = ""))
    destructor$(DxModel())
    virtual bool load(String path, String name = "");
    void optimize();
    void calculateTangents();
    int getVertexCount();
    int getTriangleCount();
    ModelVertex* getVertices();
    int getIndexCount();
    void fillIndexBuffer();
    private$(Logger<DxModel> logger{this})
    s11n$declareSplit()
})
s11n$export(DxModel);