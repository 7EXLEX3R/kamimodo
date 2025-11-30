#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.engine/events/BaseEntity3dSelectEvent.h>
#include <godmode.engine/physics/PhysicsEntity3d.h>
#include <godmode.engine/ui/JsonSchemaApp.h>

godmode_engine_ui_apps(class Entity3dApp : public JsonSchemaApp, public EventListener<BaseEntity3dSelectEvent> { $
    PhysicsEntity3d *entity3d = nullptr;
    List<BaseEntity3d *> selectedEntities;
    bool isNewEntitySelected = false;
    constructor(Entity3dApp())
    destructor$(Entity3dApp())
    virtual void handleEvent(BaseEntity3dSelectEvent *event);
    virtual void refresh();
    virtual JSON postprocessModel(JSON model);
    virtual void fixSceneAttachmentForSelection();
})