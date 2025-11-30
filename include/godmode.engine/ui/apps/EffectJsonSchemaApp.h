#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.engine/events/Scene3dChangeEvent.h>
#include <godmode.engine/ui/JsonSchemaApp.h>

godmode_engine_ui_apps(class EffectJsonSchemaApp : public JsonSchemaApp, public EventListener<Scene3dChangeEvent> { $
    Effect *effect = nullptr;
    constructor(EffectJsonSchemaApp(Effect *effect, JSON jsonSchema))
    destructor$(EffectJsonSchemaApp())
    virtual void handleEvent(Scene3dChangeEvent *event);
})