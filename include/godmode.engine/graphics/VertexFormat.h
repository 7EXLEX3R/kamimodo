#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>

godmode_engine_graphics(template <class VertexModel> class VertexFormat { $
    VertexModel* vertexBuffer = nullptr;
    constructor(VertexFormat() {})
    destructor$(VertexFormat() {
        if (this->vertexBuffer) {
            delete[] this->vertexBuffer;
            this->vertexBuffer = nullptr;
        }
    })
    virtual int getVertexCount() = 0;
    virtual int getTriangleCount() = 0;
    List<VertexModel> getVerticesList() {
        List<VertexModel> vertexList;
        VertexModel* vertexArray = getVertices();
        for (int i = 0; i < getVertexCount(); i++) {
            vertexList.add(vertexArray[i]);
        }
        return vertexList;
    }
    virtual VertexModel* getVertices() = 0;
    static float3Struct* getVertexPositions(VertexModel* vertices, unsigned int count) {
        float3Struct* positions = new float3Struct[count];
        for (unsigned int i = 0; i < count; i++) {
            positions[i] = float3Struct(vertices[i].pos.x, vertices[i].pos.y, vertices[i].pos.z);
        }
        return positions;
    }
})