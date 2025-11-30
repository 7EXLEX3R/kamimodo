#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/EditorSettings.h>
#include <godmode.engine/ui/JsonSchemaApp.h>

godmode_engine_ui_apps(class EditorSettingsApp : public JsonSchemaApp { $
    EditorSettings *settings = nullptr;
    JSON jsonSchema;
    constructor(EditorSettingsApp(EditorSettings *settings))
    destructor$(EditorSettingsApp())
})