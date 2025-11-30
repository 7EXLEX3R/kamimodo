#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

godmode_foundation_file(struct WaveHeaderType {
    char chunkId[4] = { 0, 0, 0, 0 };
    unsigned long chunkSize = 0;
    char format[4] = { 0, 0, 0, 0 };
    char subChunkId[4] = { 0, 0, 0, 0 };
    unsigned long subChunkSize = 0;
    unsigned short audioFormat = 0;
    unsigned short numChannels = 0;
    unsigned long sampleRate = 0;
    unsigned long bytesPerSecond = 0;
    unsigned short blockAlign = 0;
    unsigned short bitsPerSample = 0;
    char dataChunkId[4] = {0, 0, 0, 0};
    unsigned long dataSize = 0;
})