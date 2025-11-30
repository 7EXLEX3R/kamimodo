#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.containers.h>
#include <godmode.foundation/crypto/EncryptionType.h>
#include <godmode.foundation/types/BinaryBuffer.h>

godmode_foundation_crypto(class Cipher { $
    static String encrypt(String input, EncryptionType encryption = EncryptionType::NONE);
    static String decrypt(String input, EncryptionType encryption = EncryptionType::NONE);
    static BinaryBuffer encrypt(BinaryBuffer input, EncryptionType encryption = EncryptionType::NONE);
    static BinaryBuffer decrypt(BinaryBuffer input, EncryptionType encryption = EncryptionType::NONE);
})