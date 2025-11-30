#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.engine/graphics/IndexFormatType.h>

class IndexFormat { $
    IndexFormatType indexFormatType = IndexFormatType::NONE;
    unsigned short* indexBuffer16 = nullptr;
    unsigned long* indexBuffer32 = nullptr;
    unsigned long indexCount = 0;
    constructor(IndexFormat() {})
    destructor$(IndexFormat() {
        deleteArray$(this->indexBuffer16)
        deleteArray$(this->indexBuffer32)
    })
    unsigned long getIndexCount() { return this->indexCount; }
    unsigned short* getIndices() { return this->indexBuffer16; }
    unsigned short* getIndices16() { return this->indexBuffer16; }
    unsigned long* getIndices32() { return this->indexBuffer32; }
    virtual void fillIndexBuffer() = 0;
};