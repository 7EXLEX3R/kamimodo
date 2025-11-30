#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/system/SystemApi.h>

godmode_engine_system(class SystemApiMock : public SystemApi { $
    constructor(SystemApiMock() : SystemApi() {})
    destructor$(SystemApiMock() {})
    virtual int update() { return 0; };
    FpsMeter* createFpsMeter() { return new FpsMeter(); };
    SystemScreen* createSystemScreen() { return 0; }
    SystemWindow* createSystemWindow() { return 0; }
    List<String> getSupportedFontList() { return List<String>(); }
})