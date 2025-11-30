#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Forward.h>
#include <godmode.engine/logic/LogicEntityType.h>
#include <godmode.engine/math/Quaternion.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/math/float4x4.h>

godmode_engine_logic(template <class PositionType, class RotationType, class ScaleType> struct LogicEntityParams {
    PositionType position = PositionType();
    RotationType rotation = RotationType();
    ScaleType scale = ScaleType(1.0f);
    float3 xaxis = float3(1, 0, 0);
    float3 yaxis = float3(0, 1, 0);
    float3 zaxis = float3(0, 0, 1);
    float3 rollAxis = float3(0, 1, 0);
    float rollAngle = 0;
    float positionTransition = 1;
    float rotationTransition = 1;
    float scaleTransition = 1;
    float rollAngleTransition = 1;
    float rollAxisTransition = 1;
    PositionType center = PositionType();
    float radius = 0;
    PositionType minOffset = PositionType();
    PositionType maxOffset = PositionType();
    ScaleType size = ScaleType();
    LogicEntityType logicEntityType = LogicEntityType::OTHER;
})
godmode_engine_logic(template <class PositionType, class RotationType, class ScaleType> class LogicEntity
        : virtual public LogicEntityParams<PositionType, RotationType, ScaleType> { $
    using TypedLogicEntityParams = LogicEntityParams<PositionType, RotationType, ScaleType>;
    LogicEntity<PositionType, RotationType, ScaleType> *relativeEntity;
    PositionType positionLast, positionDest;
    RotationType rotationLast, rotationDest;
    ScaleType scaleLast, scaleDest;
    float3 xaxisBase, yaxisBase, zaxisBase;
    float3 rollAxisLast, rollAxisDest;
    float rollAngleLast, rollAngleDest;
    PositionType baseCenter;
    float baseRadius;
    PositionType baseMinOffset;
    PositionType baseMaxOffset;
    int offsetPointsCount;
    PositionType *offsetPoints;
    float distanceMod;
    float distance;
    float4x4 baseMatrix;
    float4x4 positionMatrix;
    float4x4 rotationMatrix;
    float4x4 rollMatrix;
    float4x4 scaleMatrix;
    float4x4 matrixBuffer;
    float4x4 worldMatrix;
    float4x4 originWorldMatrix;
    float4x4 lastWorldMatrix;
    bool freezeVectorsUpdate;
    bool freezeMatricesUpdate;
    constructor(LogicEntity(const TypedLogicEntityParams& params = TypedLogicEntityParams()))
    destructor$(LogicEntity())
    void setBoundingParams(PositionType &center, float radius, PositionType &minOffset, PositionType &maxOffset);
    virtual void setPosition(PositionType &position);
    virtual PositionType getPosition() const;
    LogicEntity<PositionType, RotationType, ScaleType> *withPosition(PositionType &position);
    virtual void setRotation(RotationType rotation);
    virtual RotationType getRotation() const;
    LogicEntity<PositionType, RotationType, ScaleType> *withRotation(RotationType &rotation);
    virtual void setScale(ScaleType &scale);
    virtual ScaleType getScale() const;
    LogicEntity<PositionType, RotationType, ScaleType> *withScale(ScaleType &scale);
    virtual void move(PositionType &value, bool perSecond = true);
    virtual void rotate(RotationType value, bool perSecond = true);
    virtual void rescale(ScaleType &value, bool perSecond = true);
    virtual void roll(float value, bool perSecond = true);
    ScaleType getSize() const;
    virtual void setSize(ScaleType val);
    virtual void updateVectors();
    virtual void updatePositionMatrix() = 0;
    virtual void updateRotationMatrix() = 0;
    virtual void updateRollMatrix();
    virtual void updateScaleMatrix() = 0;
    virtual void updateMatrices();
    virtual void updateBoundingParams();
    virtual void updateOffsetPoints() = 0;
    virtual void updateAxes();
    virtual void transform();
    private$(void init())
    virtual void update();
    virtual void process();
    s11n$declare()
})
godmode_engine_logic(typedef LogicEntity<float2, float, float2> LogicEntity2dTypedef)
godmode_engine_logic(typedef LogicEntity<float3, float3, float3> LogicEntity3dTypedef)