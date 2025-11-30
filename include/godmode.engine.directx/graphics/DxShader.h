#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/Types/String.h>
#include <godmode.foundation/log/Logger.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/graphics/Shader.h>

godmode_engine_directx_graphics(class DxShader : public Shader { $
    LPD3DXEFFECT dxFx = nullptr;
    constructor(DxShader())
    constructor(DxShader(String path, String name))
    destructor$(DxShader())
    void release();
    void restore();
    bool load(String path, String name = "");
    void begin();
    void end();
    void injectValue(String parameter, void *v, unsigned int bytes);
    void injectBool(String parameter, bool b);
    void injectInt(String parameter, int i);
    void injectFloat(String parameter, float f);
    void injectFloatArray(String parameter, const float *f, unsigned int count);
    void injectTexture(String parameter, Texture *texture);
    void injectTexture(String parameter, CubeTexture *texture);
    void injectTexture(String parameter, LPDIRECT3DBASETEXTURE9 texture);
    void injectMatrix(String parameter, float4x4 *m);
    void setMatrixArray(String parameter, const float4x4 *m, unsigned int count);
    void setTechnique(String t);
    int getNumTechniques();
    String getTechnique(int index);
    int getTechniqueIndex(String name);
    private$(Logger<DxShader> logger{this})
    s11n$declareSplit()
})
s11n$export(DxShader);