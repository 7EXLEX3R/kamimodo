#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/core/ModuleRegistry.h>
#include <godmode.engine/GodmodeEngine.h>
#include <godmode.engine/core/ApiFactory_Mock.h>

godmode_engine(class GodmodeEngineMock : public GodmodeEngine { $
    void init() {
        if (ModuleRegistry::add("godmode.engine.mock")) {
            godmode::$_apiFactory = new ApiFactoryMock();
            this->GodmodeEngine::init();
        }
    }
    void deinit() {
        if (ModuleRegistry::remove("godmode.engine.mock"))
            this->GodmodeEngine::deinit();
    }
})