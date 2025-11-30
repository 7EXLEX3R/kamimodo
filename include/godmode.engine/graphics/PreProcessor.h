#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/LogicEntity.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_graphics(template <class BaseEntityType> class PreProcessor { $
    bool frustumCulling = true;
    bool occlusionCulling = false;
    float levelOfDetailFactor = 0.5;
    float maxDistance = 1;  // <0,1>
    constructor(PreProcessor())
    destructor$(PreProcessor())
    List<BaseEntityType*> process(List<BaseEntityType*>& baseEntities, Camera* camera);
    List<BaseEntityType*> visibleCull(List<BaseEntityType*>& baseEntities);
    List<BaseEntityType*> frustumCull(List<BaseEntityType*>& baseEntities, Camera* camera);
    List<BaseEntityType*> occlusionCull(List<BaseEntityType*>& baseEntities, Camera* camera);
    s11n$declare()
})
s11n$export(PreProcessor<BaseEntity2d>);
s11n$export(PreProcessor<BaseEntity3d>);