#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_file(class Path { $
    static List<String> registry;
    static List<String> config;
    static void add(String path);
    static bool exists(String path);
    static String resolve(String path);
    static String cwd();
})