#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/LogicEntity.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_engine_logic(typedef LogicEntity<float2, float, float2> LogicEntity2dTemplate)
godmode_engine_logic(struct LogicEntity2dParams : virtual LogicEntityParams<float2, float, float2> {})
#define LogicEntity2dParams_$(params) LogicEntity2dParams(params), LogicEntityParams<float2, float, float2>(params)
godmode_engine_logic(class LogicEntity2d
    :   virtual public LogicEntity2dParams,
        public LogicEntity2dTemplate,
        public StringRepresentable { $
    constructor(LogicEntity2d(const LogicEntity2dParams& params = LogicEntity2dParams()))
    destructor$(LogicEntity2d())
    virtual void setPositionX(float x);
    virtual void setPositionY(float y);
    float getPositionX();
    float getPositionY();
    virtual void setScaleX(float x);
    virtual void setScaleY(float y);
    float getScaleX();
    float getScaleY();
    virtual void moveLeft(float value, bool perSecond = true);
    virtual void moveRight(float value, bool perSecond = true);
    virtual void moveUp(float value, bool perSecond = true);
    virtual void moveDown(float value, bool perSecond = true);
    virtual void moveX(float value, bool perSecond = true);
    virtual void moveY(float value, bool perSecond = true);
    virtual void rescaleX(float value, bool perSecond = true);
    virtual void rescaleY(float value, bool perSecond = true);
    virtual void updatePositionMatrix();
    virtual void updateRotationMatrix();
    virtual void updateScaleMatrix();
    void transform();
    virtual void updateOffsetPoints();
    String toString();
    bool contains(float2 &point);
    s11n$declare()
})
s11n$export(LogicEntity2d);