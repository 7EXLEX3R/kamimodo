#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/math/float4x4.h>
#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>

godmode_engine_graphics(class ShaderParameters { $
    MappedList<String, bool> _boolean;
    MappedList<String, int> _integer;
    MappedList<String, float> _float;
    MappedList<String, List<float>> _floatList;
    MappedList<String, Texture *> _texture;
    MappedList<String, float2> _float2;
    MappedList<String, float3> _float3;
    MappedList<String, float4> _float4;
    MappedList<String, float4x4> _matrix;
    MappedList<String, bool *> _booleanPointer;
    MappedList<String, int *> _integerPointer;
    MappedList<String, float *> _floatPointer;
    MappedList<String, List<float> *> _floatListPointer;
    MappedList<String, Texture **> _texturePointer;
    MappedList<String, float2 *> _float2Pointer;
    MappedList<String, float3 *> _float3Pointer;
    MappedList<String, float4 *> _float4Pointer;
    MappedList<String, float4x4 *> _matrixPointer;
    MappedList<String, bool> _booleanOutput;
    MappedList<String, int> _integerOutput;
    MappedList<String, float> _floatOutput;
    MappedList<String, List<float>> _floatListOutput;
    MappedList<String, Texture *> _textureOutput;
    MappedList<String, float2> _float2Output;
    MappedList<String, float3> _float3Output;
    MappedList<String, float4> _float4Output;
    MappedList<String, float4x4> _matrixOutput;
    ShaderParameters *parentParams = nullptr;
    bool lightShader = true;
    String technique;
    constructor(ShaderParameters())
    destructor$(ShaderParameters())
    virtual void computeParameters();
    private$(void computeParametersFor(ShaderParameters *parameters))
    private$(template <class Type>
    void computeParameterType(MappedList<String, Type> &list, MappedList<String, Type *> &pointerList, MappedList<String, Type> &outputList) {
        for (int i = 0; i < list.length(); i++)
            outputList.modify(*list.mapIndexBy(i), list.$list[i]);
        for (int i = 0; i < pointerList.length(); i++)
            outputList.modify(*pointerList.mapIndexBy(i), *pointerList.$list[i]);
    })
    s11n$declare()
})
s11n$export(ShaderParameters);