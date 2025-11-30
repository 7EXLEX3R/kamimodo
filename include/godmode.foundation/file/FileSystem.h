#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>

godmode_foundation_file(class FileSystem { $
    static const String DIRECTORY_PARENT;
    static const String DIRECTORY_CURRENT;
    static const String EXTENSION_SEPARATOR;
    static const String FILE_SYSTEM_SLASH_DIVIDER;
    static const String NEW_LINE;
    static bool isFile(String path);
    static bool isDirectory(String path);
    static bool remove(String path);
})