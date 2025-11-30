#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/physx.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_engine_math(typedef D3DXMATRIX Matrix)
godmode_engine_math(class float4x4 : public Matrix, public StringRepresentable, public JsonRepresentable { $
    float4x4();
    float4x4(float _11, float _12, float _13, float _14,
             float _21, float _22, float _23, float _24,
             float _31, float _32, float _33, float _34,
             float _41, float _42, float _43, float _44);
    float4x4(const Matrix& _matrix);
    float4x4(const float4x4& f4x4);
    float4x4(const PxMat44& pxMat44);
    float4x4(float* floats);
    float4x4(InitializerList<int> initList);
    float4x4(InitializerList<float> initList);
    float4x4(InitializerList<double> initList);
    float& operator()(int row, int col);
    float operator()(int row, int col) const;
    operator float*();
    operator const float*() const;
    float4x4& operator*=(const float4x4&);
    float4x4& operator+=(const float4x4&);
    float4x4& operator-=(const float4x4&);
    float4x4& operator*=(float);
    float4x4& operator/=(float);
    float4x4 operator+() const;
    float4x4 operator-() const;
    float4x4 operator*(const float4x4&) const;
    float4x4 operator+(const float4x4&) const;
    float4x4 operator-(const float4x4&) const;
    float4x4 operator*(float) const;
    float4x4 operator/(float) const;
    bool operator==(const float4x4&) const;
    bool operator!=(const float4x4&) const;
    PxMat44 toPxMat44();
    PxQuat toPxQuat();
    String toString();
    void fromString(String string);
    JSON toJson();
    void fromJson(JSON json);
    s11n$declare()
})
godmode_engine_math(typedef float4x4 f4x4)
godmode_engine_math(float4x4 operator*(float, const float4x4&))