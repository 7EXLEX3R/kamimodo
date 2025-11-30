#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>
#include <godmode.engine/entity/_2d/Sprite.h>

godmode_engine_entity__2d(struct SpriteFullScreenParams : virtual SpriteParams {})
#define SpriteFullScreenParams_$(params) SpriteFullScreenParams(params), SpriteParams_$(params)
godmode_engine_entity__2d(class SpriteFullScreen : virtual public SpriteFullScreenParams, public Sprite { $
    constructor(SpriteFullScreen(const SpriteFullScreenParams& params = SpriteFullScreenParams()))
    destructor$(SpriteFullScreen())
    s11n$declare()
})