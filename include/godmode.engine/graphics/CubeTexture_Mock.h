#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/CubeTexture.h>

godmode_engine_graphics(class CubeTextureMock : public CubeTexture { $
    constructor(CubeTextureMock(int size = 0) : CubeTexture(size) {})
    destructor$(CubeTextureMock() {})
    virtual void beginRenderOn(CubeTextureFace cubeTextureFace, bool beginRendering = true, int renderStage = 0) {};
    virtual void endRenderOn(CubeTextureFace cubeTextureFace) {};
    virtual void recreate() {};
    s11n$defineInline({
        ar.template register_type<CubeTextureMock>();
        ar & boost::serialization::base_object<CubeTexture>(*this);
    });
})
s11n$export(CubeTextureMock);
s11n$instantiate(CubeTextureMock);