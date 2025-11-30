#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d.h>

godmode_engine_utils(class Character { $
    Object3d* object = nullptr;
    constructor(Character())
    destructor$(Character())
    void process();
    s11n$declare()
})
s11n$export(Character);