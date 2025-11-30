#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Shader.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/MappedList.h>

godmode_engine_graphics(class Effect : public JsonRepresentable { $
    JSON config;
    Shader* shader = nullptr;
    bool active = false;
    String name;
    protected$(bool hasEngineContentShader = false)
    Effect();
    constructor(Effect(Shader* shader, JSON config = JSON::null, String name = ""))
    destructor$(Effect())
    void update(MappedList<String, Texture*> mapTextures);
    virtual void postProcess(MappedList<String, Texture*> mapTextures);
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    void setup(JSON json = JSON::null);
    s11n$declareSplit()
})