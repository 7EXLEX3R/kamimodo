#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/Directory.h>
#include <godmode.foundation/file/JsonFile.h>
#include <godmode.foundation/types/MappedList.h>

godmode_foundation_system(class Config : public JSON { $
    String directoryPath;
    constructor(Config())
    destructor$(Config())
    void addFiles(String directoryPath);
})
godmode_foundation_system$extern($_config, Config*)