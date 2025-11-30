#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/system/FpsMeter.h>
#include <godmode.engine/system/SystemScreen.h>
#include <godmode.engine/system/SystemWindow.h>
#include <godmode.foundation/system/Config.h>
#include <godmode.foundation/types/List.h>

godmode_engine_system(class SystemApi { $
    void* app = nullptr;
    SystemWindow* window = nullptr;
    bool lockCursor = false;
    bool showCursor = false;
    constructor(SystemApi())
    destructor$(SystemApi())
    virtual FpsMeter* createFpsMeter(); // FIXME: systemfactory
    virtual SystemScreen* createSystemScreen() = 0; // FIXME: systemfactory
    virtual SystemWindow* createSystemWindow() = 0; // FIXME: systemfactory
    virtual int update() = 0;
    virtual List<String> getSupportedFontList() = 0;
})
godmode_engine_system$extern($_systemApi, SystemApi*)