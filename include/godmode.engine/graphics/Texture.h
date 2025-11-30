#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Color.h>
#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_graphics(class Texture : public ContentItem {
    protected$(int width = 0)
    protected$(int height = 0)
    protected$(int renderStage = -1)
    protected$(bool renderingStarted = false)
    protected$(bool isFromFile = false)
    constructor(Texture())
    constructor(Texture(String path, String name = ""))
    constructor(Texture(int width, int height, String name = ""))
    destructor$(Texture())
    virtual bool load(String path, String name = "") = 0;
    virtual bool save(String path) = 0;
    virtual bool create(int width, int height, String name = "") = 0;
    virtual void recreate();
    int getWidth() const;
    int getHeight() const;
    virtual void beginRenderOn(bool beginRendering = true, int renderStage = 0, float4 &clearColor = float4(0, 0, 0, 0)) = 0;
    virtual void endRenderOn() = 0;
    virtual Color getPixelColor(int x, int y) = 0;
    virtual String toString();
    virtual void fromString(String string);
    s11n$declare()
})