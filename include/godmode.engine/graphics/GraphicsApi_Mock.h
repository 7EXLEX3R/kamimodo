#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Display.h>
#include <godmode.engine/graphics/GraphicsApi.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/math/float4x4.h>

godmode_engine_graphics(class GraphicsApiMock : public GraphicsApi { $
    constructor(GraphicsApiMock() : GraphicsApi() {})
    destructor$(GraphicsApiMock() {})
    void fillSupportedDisplayModesList() {}
})