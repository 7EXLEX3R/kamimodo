#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/EntityTree.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_logic__3d(class Octree : public EntityTree { $
    constructor(Octree())
    destructor$(Octree())
    s11n$declare()
})
s11n$export(Octree);