#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/CubeTextureFace.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/math/float4x4.h>

godmode_engine_graphics(class CubeTexture { $
    List<Texture *> sides;
    Camera3d *auxiliaryCamera = nullptr;
    int size = 0;
    int renderStage = 0;
    bool renderingStarted = false;
    constructor(CubeTexture(int size = 0))
    destructor$(CubeTexture())
    virtual void beginRenderOn(CubeTextureFace cubeTextureFace, bool beginRendering = true, int renderStage = 0) = 0;
    virtual void endRenderOn(CubeTextureFace cubeTextureFace) = 0;
    virtual void recreate() = 0;
    s11n$declareSplit()
})