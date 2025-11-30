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
texture normalTexture; sampler2D normalSampler = sampler_state {
    Texture = <normalTexture>;
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
float4 ps (float2 uv : TEXCOORD0) : COLOR0 {
    float3 diffuse = tex2D(diffuseSampler, uv).rgb;
    float3 normal = saturate(tex2D(normalSampler, uv).rgb);
    return float4(normalize(pow(diffuse * (float3(1, 1, 1) - normal), 2.0) * 2.0), 1.0);
}
technique _default { pass p0 {
    CullMode = ccw;
    VertexShader = compile vs_3_0 vs();
    PixelShader = compile ps_3_0 ps();
}}