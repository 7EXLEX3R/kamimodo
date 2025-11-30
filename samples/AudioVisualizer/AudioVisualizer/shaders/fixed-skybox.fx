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

float4x4 worldMatrix;
float4x4 lastWorldMatrix;
float4x4 viewProjectionMatrix;
float4x4 lastViewProjectionMatrix;
void vs (
    in float4 position : POSITION,
    in float3 normal : NORMAL,
    in float2 uv : TEXCOORD0,
    out float4 outPosition : POSITION,
    out float2 outUV : TEXCOORD0,
    out float3 outNormal : TEXCOORD5,
    out float4 outCurrentPosition : TEXCOORD6,
    out float4 outLastPosition : TEXCOORD7,
    out float4 outWorldPosition : TEXCOORD8
) {
    outNormal = mul(normal, worldMatrix);
    outCurrentPosition = mul(position, mul(worldMatrix, viewProjectionMatrix));
    outLastPosition = mul(position, mul(lastWorldMatrix, lastViewProjectionMatrix));
    outPosition = outCurrentPosition;
    outWorldPosition = mul(position, worldMatrix);
    outUV = uv;
}
void ps (
	float4 currentPosition : TEXCOORD6,
	float3 normal : TEXCOORD5,
	float4 lastPosition : TEXCOORD7,
	float4 worldPosition : TEXCOORD8,
	out float4 outDiffuse : COLOR0,
	out float4 outDepth : COLOR1,
	out float4 outVelocity : COLOR2,
	out float4 outNormal : COLOR3
) {
	outDiffuse = float4(.1, .1, .1, 1);
	outDepth = float4(worldPosition.xyz, 1);
	outVelocity = float4(float2(currentPosition.xy / currentPosition.w - lastPosition.xy / lastPosition.w), 1, 1);
	outNormal = float4(0, 0, 0, 0);
}
technique _default { pass p0 {
    AlphaBlendEnable = false;
    AlphaTestEnable = false;
    CullMode = none;
    VertexShader = compile vs_3_0 vs();
    PixelShader = compile ps_3_0 ps();
}}