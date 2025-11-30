#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.fstream.h>
#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/file/File.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/crypto/EncryptionType.h>

godmode_foundation_file(class TextFile : public ContentItem { $
    private$(std::fstream fileStream)
    private$(String source)
    private$(List<String> sourceLines)
    private$(EncryptionType encryption = EncryptionType::NONE)
    constructor(TextFile())
    constructor(TextFile(String path, FileAccessMode fileAccessMode = FileAccessMode::OPEN, EncryptionType encryption = EncryptionType::NONE))
    destructor$(TextFile())
    bool load(String path, String name = "");
    bool save(String path = "");
    String read();
    String readLine();
    String getSource() const;
    List<String> getSourceLines() const;
    void setSource(String val);
})