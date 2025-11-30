#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/String.h>

godmode_engine_system(class SystemWindow { $
    String name;
    float width = 0;
    float height = 0;
    float x = 0;
    float y = 0;
    float cornerRadius = 0;
    bool fullScreen = false;
    bool titleBar = true;
    bool alwaysOnTop = false;
    bool clientAreaDragEnabled = false;
    void* windowHandle = nullptr;
    JSON config;
    constructor(SystemWindow(JSON config))
    destructor$(SystemWindow())
    virtual void autoPosition();
    virtual void autoSize();
    virtual bool isActive();
})
godmode_engine_system$extern($_systemWindow, SystemWindow*)