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

godmode_engine_math(typedef D3DXVECTOR2 float2Struct)
godmode_engine_math(typedef D3DXVECTOR2 v2)
godmode_engine_math(class float2 : public float2Struct, public StringRepresentable, public JsonRepresentable { $
    float2();
    float2(float x, float y);
    float2(float xy);
    float2(const float2Struct& _v2);
    float2(const float2& f2);
    float2(const PxVec2& pxVec2);
    float2(InitializerList<int> initList);
    float2(InitializerList<float> initList);
    float2(InitializerList<double> initList);
    float2& operator+=(const float2&);
    float2& operator-=(const float2&);
    float2& operator*=(float);
    float2& operator/=(float);
    float2 operator+() const;
    float2 operator-() const;
    float2 operator+(const float2&) const;
    float2 operator-(const float2&) const;
    float2 operator*(float) const;
    float2 operator/(float) const;
    bool operator==(const float2&) const;
    bool operator!=(const float2&) const;
    PxVec2 toPxVec();
    String toString();
    void fromString(String string);
    static float2 from(String string);
    JSON toJson();
    void fromJson(JSON json);
    static float2 from(JSON json);
    s11n$declare()
})
godmode_engine_math(typedef float2 f2)
godmode_engine_math(
    float2 operator*(float, const float2&);
    float2 operator*(float2& left, float2& right);
    float2 operator/(float2& left, float2& right);
 )