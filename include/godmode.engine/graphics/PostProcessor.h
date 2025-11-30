#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/Effects.h>
#include <godmode.engine/graphics/GraphicsApi.h>
#include <godmode.engine/logic/Lightning.h>
#include <godmode.engine/logic/_2d/Camera2d.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/math/Math.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_graphics(class PostProcessor { $
    List<Effect*> effects;
    String renderTextureName;
    String renderBufferTextureName;
    Sprite* sprite = nullptr;
    Texture* buffer = nullptr;
    constructor(PostProcessor())
    destructor$(PostProcessor())
    Effect* addEffect(Effect* effect);
    Effect* removeEffect(Effect* effect);
    void process(MappedList<String, Texture*>& mapTextures, Camera* camera, Lightning* lightning, Effects* effects);
    void setupShader(Shader* shader, MappedList<String, Texture*>& mapTextures, Camera* camera, Lightning* lightning);
    s11n$declare()
})
s11n$export(PostProcessor);