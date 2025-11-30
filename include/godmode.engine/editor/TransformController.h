#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/TransformAxisType.h>
#include <godmode.engine/editor/TransformType.h>
#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.foundation/types/List.h>

godmode_engine_editor(class TransformController { $
    TransformType transformType = TransformType::NONE;
    TransformAxisType transformAxisType = TransformAxisType::NONE;
    TransformType lastTransformType = TransformAxisType::NONE;
    float3 dragDisplacement;
    float positionSnap = 0;
    float rotationSnap = 0;
    float scaleSnap = 0;
    bool transformTypeChanged = true;
    static Map<TransformAxisType, float3 (*)(float3 move)> axisToFilter;
    constructor(TransformController())
    destructor$(TransformController())
    static bool staticTransformControllerConstructor();
    void control(BaseEntity3d *entity3d, List<BaseEntity3d *> *entities3d = 0);
    void setTransformType(TransformType transformType = TransformType::NONE, TransformAxisType transformAxisType = TransformAxisType::NONE);
    void setSimulation(List<BaseEntity3d *> *entities3d, bool simulation);
})