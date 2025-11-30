#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

godmode_engine_graphics(class Display { $
    private$(unsigned int width = 0)
    private$(unsigned int height = 0)
    private$(bool fullScreen = false)
    private$(bool vsync = false)
    constructor(Display())
    constructor(Display(unsigned int width, unsigned int height, bool fullScreen = false, bool vsync = false))
    destructor$(Display())
    unsigned int getWidth() const;
    void setWidth(unsigned int val);
    unsigned int getHeight() const;
    void setHeight(unsigned int val);
    bool getFullScreen() const;
    void setFullScreen(bool val);
    bool getVsync() const;
    void setVsync(bool val);
})