#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/GraphicsDevice.h>
#include <godmode.engine/graphics/CubeTexture.h>
#include <godmode.engine/graphics/Font.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/graphics/Texture.h>

godmode_engine_graphics(class GraphicsFactory { $
    constructor(GraphicsFactory())
    destructor$(GraphicsFactory())
    virtual GraphicsDevice* createGraphicsDevice(Display* display = 0) = 0;
    virtual Font* createFont(String fontFace, int size, int weight = 500, bool italic = false) = 0;
    virtual Texture* createTexture() = 0;
    virtual Texture* createTexture(String path, String name = "") = 0;
    virtual Texture* createTexture(unsigned width, unsigned height, String name = "") = 0;
    virtual CubeTexture* createCubeTexture(int size) = 0;
    virtual Shader* createShader(String path, String name = "") = 0;
    virtual Model* createModel(String path, String name = "") = 0;
})
godmode_engine_graphics$extern($_graphicsFactory, GraphicsFactory*)