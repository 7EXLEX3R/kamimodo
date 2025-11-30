#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/List.h>
#include <godmode.engine/events/FileSavedEvent.h>
#include <godmode.engine/events/SceneStateChangeEvent.h>
#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.engine/ui/Window.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/ListBox.h>
#include <godmode.engine/ui/components/TreeBox.h>
#include <godmode.engine/ui/dialogs/SaveDialog.h>

godmode_engine_ui_apps(class SceneManagerApp
    :   public Window,
        public EventListener<FileSavedEvent>,
        public EventListener<SceneStateChangeEvent<BaseEntity3d>> { $
    TreeBox* contentBrowser = nullptr;
    ListBox* availableScenesListBox = nullptr;
    TreeBox* entityBrowser = nullptr;
    constructor(SceneManagerApp())
    destructor$(SceneManagerApp())
    void whenActive();
    void handleEvent(FileSavedEvent* event);
    void handleEvent(SceneStateChangeEvent<BaseEntity3d>* event);
    void refresh();
    private$(SaveDialog* saveDialog)
    private$(MappedList<String, void*> getAvailableScenesListItems())
    private$(List<TreeBoxItem*> getEntityBrowserItems())
    private$(String formatEntityName(LogicEntity3d* entity))
    private$(void addNewScene())
    private$(void saveSelectedScene())
    private$(void removeSelectedScene())
})