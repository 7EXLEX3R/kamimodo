#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/EditorEngine.h>
#include <godmode.engine/editor/EditorInterface.h>
#include <godmode.engine/editor/EditorSettings.h>
#include <godmode.engine/editor/Project.h>

godmode_engine_editor(class Editor { $
    Project *project = nullptr;
    EditorEngine *engine = nullptr;
    EditorSettings *settings = nullptr;
    EditorInterface *editorInterface = nullptr;
    constructor(Editor(Project *project))
    destructor$(Editor())
    void preprocess();
    void process();
})
godmode_engine_editor$extern($_editor, Editor*)