#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/IndexFormat.h>
#include <godmode.engine/graphics/Material.h>
#include <godmode.engine/graphics/ModelVertex.h>
#include <godmode.engine/graphics/VertexFormat.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/types/List.h>

godmode_engine_graphics(class Model : public ContentItem, public VertexFormat<ModelVertex>, public IndexFormat { $
    List<Material*> materials;
    float radius = 0;
    float3 center;
    float3 minOffset;
    float3 maxOffset;
    constructor(Model())
    constructor(Model(String path, String name = ""))
    destructor$(Model())
    virtual bool load(String path, String name = "") = 0;
    virtual ModelVertex* getVertices() = 0;
    s11n$declare()
})