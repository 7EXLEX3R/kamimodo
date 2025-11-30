#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/Plane.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/math/float4x4.h>
#include <godmode.engine/system/FpsMeter.h>

godmode_engine_math(class Math { $
    static constexpr float PI = 3.141592654f;
    static float radian(float degree);
    static float degree(float radian);
    static float sine(float value, bool inDegree = true);
    static float cosine(float value, bool inDegree = true);
    static float arcsine(float value, bool inDegree = true);
    static float arccosine(float value, bool inDegree = true);
    static float tanget(float value, bool inDegree = true);
    static float cotanget(float value, bool inDegree = true);
    static float arctanget2(float value, float value2, bool inDegree = true);
    static float sqrt(float value);
    static float pow(float value, float exponent);
    static float exp(float value);
    static float gaussianDistribution(float x, float y, float rho);
    static int min(int x, int y);
    static float min(float x, float y);
    static double min(double x, double y);
    static int max(int x, int y);
    static float max(float x, float y);
    static double max(double x, double y);
    static float abs(float x);
    static float random(float min, float max);
    static float clamp(float value, float min, float max, bool minMaxSwap = false);
    static float lerp(float x, float y, float interpolate);
    static float2 transformFloat2ByRotation(const float2 &v2d, float rotation);
    static float2 transform(const float2 &vec, const float4x4 &matrix);
    static float length(const float2 &vec);
    static float3 transform(const float3 &vec, const float4x4 &matrix);
    static float dot(const float3 &vec, const float3 &vec2);
    static float length(const float3 &vec);
    static float3 cross(const float3 &vec, const float3 &vec2);
    static float3 normalize(const float3 &vec);
    static float3 projectVectorOnPlane(const float3 &vec, const float3 &planeNormal);
    static float planeDistance(const float3 &position, const float3 &normal);
    static float planeVectorDistance(const float3 &vec, const Plane &plane);
    static float3 planeVectorIntersection(const float3 &position, const float3 &direction, const Plane &plane);
    static Plane planeFromPositionAndNormal(const float3 &position, const float3 &normal);
    static Plane planeFromPoints(const float3 &vec1, const float3 &vec2, const float3 &vec3);
    static float3 transformScreenSpacePointToViewProjection(
        const float2 &screenSpacePoint,
        const float2 &displaySize,
        const float4x4 &viewMatrix,
        const float4x4 &projectionMatrix);
    static float2 getScreenspaceCoords(const float3 &point, const float4x4 &viewProjection);
    static float3 multiply(const float3 &vec, const float4x4 &matrix);
    static float3 rollEulerAngles(const float3 &eulerAngles, const float3 &rollAxis, float rollAngle);
    static float2 multiply(const float2 &vec, const float2 &vec2);
    static float3 multiply(const float3 &vec, const float3 &vec2);
    template <class TransitionValueType>
    static TransitionValueType transition(TransitionValueType from, TransitionValueType to, float transition, bool perSecond = false) {
        return (to - from) / (transition * (perSecond ? $_fpsMeter->getFps() / 60.0 : 1));
    }
})