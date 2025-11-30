#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Enum.h>

godmode_foundation_file(enum$(EncryptionType,
    NONE,
    XOR,
    AES,
    RC4,
    TEA,
    BASE64,
    LZ4_COMPRESS,
    CUSTOM_HASH,
    CHACHA20,
    RSA_SIGNED
))
