#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite.h>

godmode_engine_entity__2d(class SpriteMock : public Sprite { $
    constructor(SpriteMock(const SpriteParams& params = SpriteParams()) : Sprite(params) {})
    destructor$(SpriteMock() {})
    void render() {};
    s11n$defineInline({
        ar.template register_type<SpriteMock>();
        ar &boost::serialization::base_object<Sprite>(*this);
    });
})
s11n$export(SpriteMock);
s11n$instantiate(SpriteMock);