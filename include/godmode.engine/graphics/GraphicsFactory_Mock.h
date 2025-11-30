#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/CubeTexture_Mock.h>
#include <godmode.engine/graphics/Font_Mock.h>
#include <godmode.engine/graphics/GraphicsFactory.h>
#include <godmode.engine/graphics/Model_Mock.h>
#include <godmode.engine/graphics/Shader_Mock.h>
#include <godmode.engine/graphics/Texture_Mock.h>

godmode_engine_graphics(class GraphicsFactoryMock : public GraphicsFactory { $
    constructor(GraphicsFactoryMock() : GraphicsFactory() {})
    destructor$(GraphicsFactoryMock() {})
    GraphicsDevice* createGraphicsDevice(Display* display = 0) { return new GraphicsDevice(display); }
    Font* createFont(String path, int size, int weight = 500, bool italic = false) { return new FontMock(path, size, weight, italic); };
    Texture* createTexture() { return new TextureMock(); };
    Texture* createTexture(String path, String name = "") { return new TextureMock(path, name); }
    Texture* createTexture(unsigned width, unsigned height, String name = "") { return new TextureMock(width, height, name); }
    CubeTexture* createCubeTexture(int size) { return new CubeTextureMock(size); }
    Shader* createShader(String path, String name = "") { return new ShaderMock(path, name); }
    Model* createModel(String path, String name = "") { return new ModelMock(path, name); }
})