#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>

godmode_engine_editor(class EditorSettings : public JsonRepresentable { $
    float positionSnap = 0;
    float rotationSnap = 0;
    float scaleSnap = 0;
    bool renderBoundingEnabled = false;
    bool isGuiAlwaysVisible = false;
    bool isEffects = false;
    JSON config;
    constructor(EditorSettings(JSON config))
    destructor$(EditorSettings())
    JSON toJson();
    void fromJson(JSON json);
})