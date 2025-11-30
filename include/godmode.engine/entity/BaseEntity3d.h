#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.engine/entity/BaseEntity.h>
#include <godmode.engine/logic/LogicEntity3d.h>

godmode_engine_entity(struct BaseEntity3dParams : virtual BaseEntityParams<LogicEntity3dParams> {})
#define BaseEntity3dParams_$(params) BaseEntity3dParams(params), BaseEntityParams<LogicEntity3dParams>(params), LogicEntity3dParams_$(params), GraphicsEntityParams(params)
godmode_engine_entity(class BaseEntity3d
    :   virtual public BaseEntity3dParams,
        public BaseEntity<LogicEntity3d, LogicEntity3dParams> { $
    constructor(BaseEntity3d(const BaseEntity3dParams& params = BaseEntity3dParams()))
    destructor$(BaseEntity3d())
    s11n$declare()
})