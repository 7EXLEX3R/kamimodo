#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.engine/entity/BaseEntity.h>
#include <godmode.engine/logic/LogicEntity2d.h>

godmode_engine_entity(struct BaseEntity2dParams : virtual BaseEntityParams<LogicEntity2dParams> {})
#define BaseEntity2dParams_$(params) BaseEntity2dParams(params), BaseEntityParams<LogicEntity2dParams>(params), LogicEntity2dParams_$(params), GraphicsEntityParams(params)
godmode_engine_entity(class BaseEntity2d
    :   virtual public BaseEntity2dParams,
        public BaseEntity<LogicEntity2d, LogicEntity2dParams> { $
    constructor(BaseEntity2d(const BaseEntity2dParams& params = BaseEntity2dParams()))
    destructor$(BaseEntity2d())
    s11n$declare()
})