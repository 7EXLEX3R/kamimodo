#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/CubeTexture.h>
#include <godmode.engine/graphics/Font.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/sound/Sound.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>

godmode_engine_core(class Content { $
    MappedList<String, Font*> fonts;
    MappedList<String, Texture*> textures;
    MappedList<String, CubeTexture*> cubeTextures;
    MappedList<String, Shader*> shaders;
    MappedList<String, Model*> models;
    MappedList<String, Sound*> sounds;
    constructor(Content())
    destructor$(Content())
    virtual Font* addFont(String fontFace, int size, int weight = 500, bool italic = false);
    virtual void removeFont(Font* font);
    virtual Texture* addTexture(String path, String name = "");
    virtual Texture* addTexture(unsigned width, unsigned height, String name = "");
    virtual void removeTexture(Texture* texture);
    virtual CubeTexture* addCubeTexture(int size, String name = "");
    virtual void removeCubeTexture(CubeTexture* texture);
    virtual Shader* addShader(String path, String name = "");
    virtual void removeShader(Shader* shader);
    virtual Model* addModel(String path, String name = "");
    virtual void removeModel(Model* model);
    virtual Sound* addSound(String path, String name = "");
    virtual void removeSound(Sound* sound);
    s11n$declare()
})
godmode_engine_core$extern($_content, Content*)
godmode_engine_core$extern($_internalContent, Content*)
s11n$export(Content);