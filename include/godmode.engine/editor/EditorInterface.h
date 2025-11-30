#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/EditorEngine.h>
#include <godmode.engine/editor/EditorSettings.h>
#include <godmode.engine/editor/Project.h>

godmode_engine_editor(class EditorInterface { $
    Project *project = nullptr;
    EditorEngine *_engine = nullptr;
    EditorSettings *settings = nullptr;
    constructor(EditorInterface(Project *project = nullptr, EditorEngine *_engine = nullptr, EditorSettings *settings = nullptr))
    destructor$(EditorInterface())
    void refresh();
})