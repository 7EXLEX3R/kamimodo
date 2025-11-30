#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/CubeTexture.h>
#include <godmode.engine/graphics/ShaderParameters.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/math/float4x4.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_graphics(class Shader : public ContentItem, public ShaderParameters { $
    constructor(Shader())
    constructor(Shader(String path, String name = ""))
    destructor$(Shader())
    virtual void begin() = 0;
    virtual void end() = 0;
    virtual void injectValue(String parameter, void* v, unsigned int bytes) = 0;
    virtual void injectBool(String parameter, bool b) = 0;
    virtual void injectInt(String parameter, int i) = 0;
    virtual void injectFloat(String parameter, float f) = 0;
    virtual void injectFloatArray(String parameter, const float* f, unsigned int count) = 0;
    void injectFloatList(String parameter, List<float> floatList);
    virtual void injectTexture(String parameter, Texture* texture) = 0;
    virtual void injectTexture(String parameter, CubeTexture* texture) = 0;
    virtual void injectMatrix(String parameter, float4x4* matrix);
    virtual void injectFloat2(String parameter, const float2Struct& f2);
    virtual void injectFloat3(String parameter, const float3Struct& f3);
    virtual void injectFloat4(String parameter, const float4Struct& f4);
    virtual void setTechnique(String t) = 0;
    virtual int getNumTechniques() = 0;
    // virtual List<String> getTechniques() = 0;
    virtual String getTechnique(int index) = 0;
    virtual int getTechniqueIndex(String name) = 0;
    void injectChanges();
    void prepare();
    static String resolveShaderPath(const String& path);
    s11n$declare()
})