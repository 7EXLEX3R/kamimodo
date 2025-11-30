#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/List.h>

godmode_engine_editor(class Project : public ContentItem { $
    constructor(Project())
    constructor(Project(String path))
    destructor$(Project())
    void blank();
    virtual bool load(String path, String name = "");
    virtual bool save(String path = "");
    private$(Scene3d* createExampleScene())
    s11n$declare()
})