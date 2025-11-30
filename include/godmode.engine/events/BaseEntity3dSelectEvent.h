#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.foundation/events/Event.h>

godmode_engine_events(class BaseEntity3dSelectEvent : public Event { $
    List<BaseEntity3d*> entities;
    void* invoker = nullptr;
    constructor(BaseEntity3dSelectEvent(List<BaseEntity3d*> logicEntities, void* invoker = 0))
    constructor(BaseEntity3dSelectEvent(BaseEntity3d* logicEntity, void* invoker = 0))
    destructor$(BaseEntity3dSelectEvent())
})