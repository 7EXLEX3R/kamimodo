#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Shader.h>
#include <godmode.foundation/log/Console.h>

godmode_engine_graphics(class ShaderMock : public Shader { $
    constructor(ShaderMock() : Shader() {})
    constructor(ShaderMock(String path, String name) : Shader(path, name) {})
    destructor$(ShaderMock() {})
    virtual void begin() {};
    virtual void end() {};
    virtual void injectValue(String parameter, void *v, unsigned int bytes) {};
    virtual void injectBool(String parameter, bool b) {};
    virtual void injectInt(String parameter, int i) {};
    virtual void injectFloat(String parameter, float f) {};
    virtual void injectFloatArray(String parameter, const float *f, unsigned int count) {};
    virtual void injectTexture(String parameter, Texture *texture) {};
    virtual void injectTexture(String parameter, CubeTexture *texture) {};
    virtual void setTechnique(String t) {};
    virtual int getNumTechniques() { return 0; };
    virtual String getTechnique(int index) { return ""; };
    virtual int getTechniqueIndex(String name) { return 0; };
    virtual bool load(String path, String name = "") {
        console->log(path);
        return 0;
    };
    s11n$defineInline({
        ar.template register_type<ShaderMock>();
        ar &boost::serialization::base_object<Shader>(*this);
    });
})
s11n$export(ShaderMock);
s11n$instantiate(ShaderMock);