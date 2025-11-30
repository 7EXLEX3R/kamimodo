#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/file/FileAccessMode.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_file(class File : public ContentItem { $
    constructor(File(String path, FileAccessMode fileAccessMode = FileAccessMode::OPEN))
})