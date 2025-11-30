#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

godmode_engine_graphics(class DisplayMode { $
    unsigned int width = 0;
    unsigned int height = 0;
    unsigned int refreshRate = 0;
    unsigned int format = 0;
    constructor(DisplayMode())
    constructor(DisplayMode(unsigned int width, unsigned int height, unsigned int refreshRate, unsigned int format = 0))
    destructor$(DisplayMode())
})