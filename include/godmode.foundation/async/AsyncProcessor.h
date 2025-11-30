#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Promise.h>

godmode_foundation_async(class AsyncProcessor { $
    constructor(AsyncProcessor())
    destructor$(AsyncProcessor())
    void update();
    private$(bool alive);
    private$(Promise<void> asyncHandle);
})
godmode_foundation_async$extern($_asyncProcessor, AsyncProcessor*)