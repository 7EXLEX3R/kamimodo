#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Display.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/math/float4x4.h>

godmode_engine_graphics(class GraphicsDevice { $
    Display* display = nullptr;
    Sprite* backBufferSprite = nullptr;
    constructor(GraphicsDevice(Display* display = nullptr))
    destructor$(GraphicsDevice())
    virtual void setWorldTransform(float4x4* matrix) {};
    virtual void setViewTransform(float4x4* matrix) {};
    virtual void setProjectionTransform(float4x4* matrix) {};
    virtual void render(Texture* screenResultTexture) {};
    virtual void cloneTexture(Texture* sourceTexture, Texture* destTexture) {};
})
godmode_engine_graphics$extern($_graphicsDevice, GraphicsDevice*)