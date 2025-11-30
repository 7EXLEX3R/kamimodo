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
texture extraNormalTexture; sampler2D extraNormalSampler = sampler_state {
    Texture = <extraNormalTexture>;
    AddressU = Mirror; AddressV = Mirror;
    MinFilter = Point; MagFilter = Point; MipFilter = Point;
};
float4x4 worldMatrix;
float4x4 viewMatrix;
float4x4 projectionMatrix;
void vs (
    float4 position : POSITION,
    float2 uv : TEXCOORD0,
    out float4 outPosition : POSITION,
    out float2 outUV : TEXCOORD0
) {
    outPosition = mul(position, mul(mul(worldMatrix, viewMatrix), projectionMatrix));
    outUV = uv;
}
float time;
float screenWidth;
float screenHeight;
float3 postEffectColorMultiplier;
float mandelbrot(float2 uv, int maxIter) {
    float2 center = float2(-0.74364388703, 0.13182590421);
    float zoom = pow(0.98, (fmod(time, 7.5) + 20) * 20);
    float2 c = (uv - 0.5) * zoom * 3.0 + center;
    float2 z = float2(0.0, 0.0);
    int i;
    for (i = 0; i < maxIter; i++) {
        float x = (z.x * z.x - z.y * z.y) + c.x;
        float y = (2.0 * z.x * z.y) + c.y;
        z = float2(x, y);
        if (dot(z, z) > 4.0) break;
    }
    return i / (float)maxIter;
}
float4 ps (float2 uv : TEXCOORD0) : COLOR0 {
    float2 fractalUV = uv * float2(screenWidth / screenHeight, 1);
    float mandelValue = (mandelbrot(fractalUV, 512) - .5);
    float3 normal = normalize(2.0f * tex2D(extraNormalSampler, uv + time.xx * .1).rgb - 1.0f);
    float3 color = (tex2D(diffuseSampler, uv + mandelValue.xx * .25 * normal.xz * .25).rgb);
    return float4(saturate(color.xxx * 500) * .25 * postEffectColorMultiplier * .25, 1.0);
}
technique _default { pass p0 {
    CullMode = ccw;
    VertexShader = compile vs_3_0 vs();
    PixelShader = compile ps_3_0 ps();
}}