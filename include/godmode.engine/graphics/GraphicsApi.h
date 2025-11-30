#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/EntityFactory.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/graphics/Display.h>
#include <godmode.engine/graphics/DisplayMode.h>
#include <godmode.engine/graphics/GraphicsDevice.h>
#include <godmode.engine/graphics/GraphicsFactory.h>
#include <godmode.engine/graphics/Texture.h>

godmode_engine_graphics(class GraphicsApi { $
    GraphicsDevice *device = nullptr;
    Display *defaultDisplay = nullptr;
    Shader *deferredShader = nullptr;
    List<DisplayMode*> supportedDisplayModes;
    constructor(GraphicsApi())
    destructor$(GraphicsApi())
    GraphicsApi* run();
    virtual void initInternalContent();
    virtual void fillSupportedDisplayModesList() = 0;
})
godmode_engine_graphics$extern($_graphicsApi, GraphicsApi*)