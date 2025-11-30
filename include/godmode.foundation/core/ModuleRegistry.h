#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_core(class ModuleRegistry { $
    static bool add(String moduleName);
    static bool remove(String moduleName);
    private$(static List<String> $registry);
})