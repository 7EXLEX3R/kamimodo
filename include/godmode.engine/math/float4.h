#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/physx.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/InitializerList.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_engine_math(typedef D3DXVECTOR4 float4Struct)
godmode_engine_math(typedef D3DXVECTOR4 v4)
godmode_engine_math(class float4 : public v4, public StringRepresentable, public JsonRepresentable { $
    float4();
    float4(float x, float y, float z, float w);
    float4(float xyzw);
    float4(const v4& _v4);
    float4(const float4& f4);
    float4(const PxVec4& pxVec4);
    float4(InitializerList<int> initList);
    float4(InitializerList<float> initList);
    float4(InitializerList<double> initList);
    float4& operator+=(const float4&);
    float4& operator-=(const float4&);
    float4& operator*=(float);
    float4& operator/=(float);
    float4 operator+() const;
    float4 operator-() const;
    float4 operator+(const float4&) const;
    float4 operator-(const float4&) const;
    float4 operator*(float) const;
    float4 operator/(float) const;
    bool operator==(const float4&) const;
    bool operator!=(const float4&) const;
    PxVec4 toPxVec();
    String toString();
    void fromString(String string);
    JSON toJson();
    void fromJson(JSON json);
    static float4 from(JSON json);
    s11n$declare()
})
godmode_engine_math(typedef float4 f4)
godmode_engine_math(
    float4 operator*(float, const float4&);
    float4 operator*(float4& left, float4& right);
    float4 operator/(float4& left, float4& right);
)