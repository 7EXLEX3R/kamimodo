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

godmode_engine_math(typedef D3DXVECTOR3 float3Struct)
godmode_engine_math(typedef D3DXVECTOR3 v3)
godmode_engine_math(class float3 : public v3, public StringRepresentable, public JsonRepresentable { $
    float3();
    float3(float x, float y, float z);
    float3(float xyz);
    float3(const v3& _v3);
    float3(const float3& f3);
    float3(const PxVec3& pxVec3);
    float3(InitializerList<int> initList);
    float3(InitializerList<float> initList);
    float3(InitializerList<double> initList);
    float3& operator+=(const float3&);
    float3& operator-=(const float3&);
    float3& operator*=(float);
    float3& operator/=(float);
    float3 operator+() const;
    float3 operator-() const;
    float3 operator+(const float3&) const;
    float3 operator-(const float3&) const;
    float3 operator*(float) const;
    float3 operator/(float) const;
    bool operator==(const float3&) const;
    bool operator!=(const float3&) const;
    PxVec3 toPxVec();
    String toString();
    void fromString(String string);
    JSON toJson();
    void fromJson(JSON json);
    static float3 from(JSON json);
    s11n$declare()
})
godmode_engine_math(typedef float3 f3)
godmode_engine_math(
    float3 operator*(float, const float3&);
    float3 operator*(float3& left, float3& right);
    float3 operator/(float3& left, float3& right);
)