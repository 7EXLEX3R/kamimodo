#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Model.h>

godmode_engine_graphics(class ModelMock : public Model { $
    constructor(ModelMock() : Model() {})
    constructor(ModelMock(String path, String name = "") : Model(path, name) {
        this->center = float3(0, 0, 0);
        this->radius = 1;
        this->minOffset = float3(-1, -1, -1);
        this->maxOffset = float3(1, 1, 1);
    })
    destructor$(ModelMock() {})
    virtual bool load(String path, String name = "") { return true; };
    virtual ModelVertex* getVertices() { return this->vertexBuffer; };
    virtual void fillIndexBuffer() {};
    int getVertexCount() { return 0; };
    int getTriangleCount() { return 0; };
    DWORD getIndexCount() { return 0; };
    s11n$defineInline({
        ar.template register_type<ModelMock>();
        ar & boost::serialization::base_object<Model>(*this);
    });
})
s11n$export(ModelMock);
s11n$instantiate(ModelMock);