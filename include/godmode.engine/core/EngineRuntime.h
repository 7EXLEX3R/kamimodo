#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/core/Module.h>
#include <godmode.foundation/core/Runtime.h>

godmode_engine_core(class EngineRuntime : public Runtime { $
    constructor(EngineRuntime())
    destructor$(EngineRuntime())
    virtual void init();
    int run();
    int frameBegin();
    virtual void update();
    virtual void update$active();
    virtual void update$inactive();
    void frameEnd();
    void pause();
    void resume();
    void terminate();
    bool isRunning;
    bool isPaused;
})
godmode_engine_core$extern($_engineRuntime, EngineRuntime*)