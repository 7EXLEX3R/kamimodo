#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui(class Clipboard { $
    List<String> strings;
    List<void*> objects;
    constructor(Clipboard())
    destructor$(Clipboard())
})
godmode_engine_ui$extern($_clipboard, Clipboard*)