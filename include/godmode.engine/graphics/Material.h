#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Texture.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_graphics(class Material { $
    float specular = 0;  // <0,1>
    float glossiness = 0;  // <0,1>
    float reflectivity = 0;  // <0,1>
    float transparency = 0;  // <0,1>
    float emissive = 0;  // <0,1>
    Texture *diffuseTexture = nullptr;
    Texture *normalTexture = nullptr;
    Texture *materialTexture = nullptr;
    Texture *emissiveTexture = nullptr;
    constructor(Material())
    destructor$(Material())
    s11n$declare()
})