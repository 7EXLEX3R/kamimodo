#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/Refreshable.h>
#include <godmode.foundation/types/List.h>

godmode_engine_logic(class Refreshables : public List<Refreshable *> { $
    constructor(Refreshables())
    destructor$(Refreshables())
    void refresh();
})
godmode_engine_logic$extern($_refreshables, Refreshables*)