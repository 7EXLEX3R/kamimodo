#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/entity/_2d/SpriteVertexPrecision.h>
#include <godmode.engine/graphics/Texture.h>

godmode_engine_entity__2d(struct SpriteParams : virtual BaseEntity2dParams {
    Texture* texture = nullptr;
    SpriteVertexPrecision spriteVertexPrecision = SpriteVertexPrecision::FLOATING;
})
#define SpriteParams_$(params) SpriteParams(params), BaseEntity2dParams_$(params)
godmode_engine_entity__2d(class Sprite : virtual public SpriteParams, public BaseEntity2d { $
    constructor(Sprite(const SpriteParams& spriteParams = SpriteParams()))
    destructor$(Sprite())
    s11n$declare()
})