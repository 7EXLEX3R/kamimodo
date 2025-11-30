//  kamimodo SDK™ : kamimodo™ - the legacy of GODMODE_999
//  Copyright © 2025 ____l____e____x____e____r____. All rights reserved.
//
//  This file is part of the kamimodo™ codebase.
//
//  Licensed under the Light Attribution License (LAL) 1.0.
//  See the LICENSE file in the project root or visit:
//  https://7EX.LEX3R.com/$/999/kamimodo™/LICENSE
//
//  Trademarks:
//  kamimodo™ and kamimodo SDK™ are trademarks of ____l____e____x____e____r____.
//
//  Legacy reference:
//  GODMODE_999 - former name of the project.

texture diffuseTexture; sampler2D diffuseSampler = sampler_state {
    Texture = <diffuseTexture>;
    AddressU = Mirror; AddressV = Mirror;
    MinFilter = Point; MagFilter = Point; MipFilter = Point;
};
float4x4 worldMatrix;
float4x4 viewMatrix;
float4x4 projectionMatrix;
void vs (
    in float4 position : POSITION,
    in float2 uv : TEXCOORD0,
    out float4 outPosition : POSITION,
    out float2 outUV : TEXCOORD0
) {
    outPosition = mul(position, mul(mul(worldMatrix, viewMatrix), projectionMatrix));
    outUV = uv;
}
float bandCount = 16.0;
float bands[16];
float time;
float3 swirlCrossVector = float3(0, 1, 0);
bool experimentalColors = false;
float2 swirl(float2 uv, float amount, float speed) {
    float2 center = float2(0.5, 0.5);
    float2 delta = uv - center;
    float dist = length(delta);
    float angle = atan2(delta.y, delta.x) + amount * sin(dist * 20.0 - time * speed);
    return center + float2(cos(angle), sin(angle)) * dist;
}
float4 ps (float2 uv : TEXCOORD0) : COLOR0 {
    float bass = bands[0];
    float mid = bands[7];
    float treble = bands[15];
    float swirlAmount = 2.0 + bass * 1.0;
    float swirlSpeed = 0.5 + mid * .01;
    float2 warpedUV = swirl(uv, swirlAmount, swirlSpeed);
    float ripple = sin((warpedUV.x + warpedUV.y) * 1.0 + time * 0.001 * 1.0 + treble * 1.0);
    warpedUV += ripple * 0.00005;
    float3 diffuseColor = tex2D(diffuseSampler, warpedUV).rgb;
    float3 color = diffuseColor;
    color.r += sin(warpedUV.x * 10.0 + time * 0.001 + bass * 10.0) * 0.1;
    color.g += cos(warpedUV.y * 10.0 + time * 0.001 * 1.5 + mid * 1.0) * 1;
    color.b += sin(dot(warpedUV, warpedUV) * 10.0 + time * 0.001 * 1.0 + treble * 1.0) * .2;
    float3 diffuse = tex2D(diffuseSampler, uv + color.rg * .0125).rgb;
    if (experimentalColors) {
        float3 outputColor = cross(swirlCrossVector, color * diffuseColor + diffuse);
        if (outputColor.x < 0) outputColor.x = -outputColor.x;
        if (outputColor.y < 0) outputColor.y = -outputColor.y;
        if (outputColor.z < 0) outputColor.z = -outputColor.z;
        return float4(outputColor, 1.0);
    }
    return float4(color * diffuseColor + diffuse, 1.0);
}
technique _default { pass p0 {
    CullMode = ccw;
    VertexShader = compile vs_3_0 vs();
    PixelShader = compile ps_3_0 ps();
}}