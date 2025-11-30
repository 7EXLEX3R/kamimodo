#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite.h>

godmode_engine_entity__2d(struct SpriteFixedParams : virtual SpriteParams {})
#define SpriteFixedParams_$(params) SpriteFixedParams(params), SpriteParams_$(params)
godmode_engine_entity__2d(class SpriteFixed : virtual public SpriteFixedParams, public Sprite { $
    constructor(SpriteFixed(const SpriteFixedParams& params = SpriteFixedParams()))
    destructor$(SpriteFixed())
})