#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/GraphicsEntity.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_entity(template <class LogicEntityParamsType> struct BaseEntityParams
    :   virtual LogicEntityParamsType, virtual GraphicsEntityParams {})
godmode_engine_entity(template <class LogicEntityType, class LogicEntityParamsType> class BaseEntity
    :   virtual public BaseEntityParams<LogicEntityParamsType>,
        public LogicEntityType,
        public GraphicsEntity { $
    BaseEntity *boundingBox = nullptr;
    String name;
    constructor(BaseEntity(const BaseEntityParams<LogicEntityParamsType>& params = BaseEntityParams<LogicEntityParamsType>()))
    destructor$(BaseEntity())
    virtual void process();
    s11n$declare()
})