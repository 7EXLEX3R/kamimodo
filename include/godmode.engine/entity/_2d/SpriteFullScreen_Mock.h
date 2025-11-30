#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/SpriteFullScreen.h>
#include <godmode.engine/math/float2.h>

godmode_engine_entity__2d(class SpriteFullScreenMock : public SpriteFullScreen { $
    constructor(SpriteFullScreenMock(const SpriteFullScreenParams& params = SpriteFullScreenParams()) : SpriteFullScreen(params) {})
    destructor$(SpriteFullScreenMock() {})
    void render() {};
    void createVertexBuffer() {};
    void createIndexBuffer() {};
    void recreate() {};
    s11n$defineInline({
        ar.template register_type<SpriteFullScreenMock>();
        ar &boost::serialization::base_object<SpriteFullScreen>(*this);
    });
})
s11n$export(SpriteFullScreenMock);