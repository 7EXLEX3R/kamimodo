#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/LogicEntity3d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_logic__3d(struct LightParams : virtual LogicEntity3dParams {
    float4 color = float4(0, 0, 0, 0);
    float range = 0;
    float innerRadius = 0;
    float outerRadius = 0;
    float3 direction = float3(0, 0, 0);
    bool enabled = true;
})
godmode_engine_logic__3d(class Light : virtual public LightParams, public LogicEntity3d { $
    // LPDIRECT3DCUBETEXTURE9 *shadowCubeMap;
    constructor(Light(const LightParams& params = LightParams()))
    destructor$(Light())
    void setColor(float4 &color);
    float4 getColor() const;
    void setRange(float range);
    float getRange() const;
    void setEnabled(bool enabled);
    bool getEnabled() const;
    s11n$declare()
})
s11n$export(Light);