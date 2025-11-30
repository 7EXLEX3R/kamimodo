#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Texture.h>
#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/types/String.h>

godmode_engine_graphics(class TextureMock : public Texture { $
    constructor(TextureMock() : Texture() {})
    constructor(TextureMock(String path, String name = "") : Texture("", "") {})
    constructor(TextureMock(int width, int height, String name = "tTexture") : Texture("", "") {})
    destructor$(TextureMock() {})
    bool load(String path) {
        console->log("path " + path);
        return true;
    }
    bool load(String path, String name = "") {
        console->log("path " + path);
        return true;
    }
    bool save(String path) { return true; }
    bool create(int width, int height, String name = "tTexture") { return true; }
    void beginRenderOn(bool beginRendering = true, int renderStage = 0, float4 &clearColor = float4(0, 0, 0, 0)) {}
    void endRenderOn() {}
    Color getPixelColor(int x, int y) { return Color(0, 0, 0, 0); }
    s11n$defineInline({
        ar.template register_type<TextureMock>();
        ar& boost::serialization::base_object<Texture>(*this);
        });
})
s11n$export(TextureMock);
s11n$instantiate(TextureMock);