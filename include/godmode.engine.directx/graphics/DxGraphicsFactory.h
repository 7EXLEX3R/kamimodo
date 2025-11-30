#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/GraphicsFactory.h>

godmode_engine_directx_graphics(class DxGraphicsFactory : public GraphicsFactory { $
    constructor(DxGraphicsFactory())
    destructor$(DxGraphicsFactory())
    GraphicsDevice* createGraphicsDevice(Display* display = 0);
    Font* createFont(String path, int size, int weight = 500, bool italic = false);
    Texture* createTexture();
    Texture* createTexture(String path, String name = "");
    Texture* createTexture(unsigned width, unsigned height, String name = "");
    CubeTexture* createCubeTexture(int size);
    Shader* createShader(String path, String name = "");
    Model* createModel(String path, String name = "");
})