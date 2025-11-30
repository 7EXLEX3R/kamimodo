#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/List.h>
#include <godmode.engine/events/Scene3dChangeEvent.h>
#include <godmode.engine/ui/Window.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/ListBox.h>

godmode_engine_ui_apps(class EffectsApp : public Window, public EventListener<Scene3dChangeEvent> { $
    ListBox* availableEffectsListBox = nullptr;
    ListBox* activeEffectsListBox = nullptr;
    Effects* effects = nullptr;
    constructor(EffectsApp())
    destructor$(EffectsApp())
    void whenActive();
    void handleEvent(Scene3dChangeEvent* event);
    private$(MappedList<String, void*> getActiveEffectsListItems())
})
godmode_engine_ui_apps(struct EffectsAppContextStruct {
    Effect* effect;
    EffectsApp* app;
})