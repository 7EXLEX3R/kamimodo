#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.fstream.h>
#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/file/File.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/BinaryBuffer.h>
#include <godmode.foundation/crypto/EncryptionType.h>

godmode_foundation_file(class BinaryFile : public ContentItem { $
    private$(EncryptionType encryption = EncryptionType::NONE)
    private$(std::fstream fileStream)
    private$(std::vector<uint8_t> data)
    constructor(BinaryFile())
    constructor(BinaryFile(String path, FileAccessMode fileAccessMode = FileAccessMode::OPEN, EncryptionType encryption = EncryptionType::NONE))
    destructor$(BinaryFile())
    bool load(String path);
    bool save(String path = "");
    BinaryBuffer read();                  // read entire file
    void write(const BinaryBuffer& data); // overwrite file with data
    BinaryBuffer getData() const;
    void setData(const BinaryBuffer& val);
};)