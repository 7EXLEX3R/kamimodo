#pragma once

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/LogicEntity.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Forward.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_engine_logic(typedef LogicEntity<float3, float3, float3> LogicEntity3dTemplate)
godmode_engine_logic(struct LogicEntity3dParams : virtual LogicEntityParams<float3, float3, float3> {})
#define LogicEntity3dParams_$(params) LogicEntity3dParams(params), LogicEntityParams<float3, float3, float3>(params)
godmode_engine_logic(class LogicEntity3d
    :   virtual public LogicEntity3dParams,
        public LogicEntity3dTemplate,
        public StringRepresentable,
        public JsonRepresentable { $
    constructor(LogicEntity3d(const LogicEntity3dParams& params = LogicEntity3dParams()))
    destructor$(LogicEntity3d())
    virtual void setPositionX(float x);
    virtual void setPositionY(float y);
    virtual void setPositionZ(float z);
    float getPositionX() const;
    float getPositionY() const;
    float getPositionZ() const;
    virtual void setRotationX(float x);
    virtual void setRotationY(float y);
    virtual void setRotationZ(float z);
    float getRotationX() const;
    float getRotationY() const;
    float getRotationZ() const;
    virtual void setScaleX(float x);
    virtual void setScaleY(float y);
    virtual void setScaleZ(float y);
    float getScaleX() const;
    float getScaleY() const;
    float getScaleZ() const;
    virtual void moveLeft(float value, bool perSecond = true);
    virtual void moveRight(float value, bool perSecond = true);
    virtual void moveUp(float value, bool perSecond = true);
    virtual void moveDown(float value, bool perSecond = true);
    virtual void moveForward(float value, bool perSecond = true);
    virtual void moveBackward(float value, bool perSecond = true);
    virtual void moveX(float value, bool perSecond = true);
    virtual void moveY(float value, bool perSecond = true);
    virtual void moveZ(float value, bool perSecond = true);
    virtual void rotateX(float value, bool perSecond = true);
    virtual void rotateY(float value, bool perSecond = true);
    virtual void rotateZ(float value, bool perSecond = true);
    virtual void rescaleX(float value, bool perSecond = true);
    virtual void rescaleY(float value, bool perSecond = true);
    virtual void rescaleZ(float value, bool perSecond = true);
    virtual void updatePositionMatrix();
    virtual void updateRotationMatrix();
    virtual void updateScaleMatrix();
    virtual void updateOffsetPoints();
    String toString();
    virtual JSON toJson();
    virtual void fromJson(JSON json);
    s11n$declare()
})
s11n$export(LogicEntity3d)