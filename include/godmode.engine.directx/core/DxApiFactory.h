#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/ApiFactory.h>

godmode_engine_directx_core(class DxApiFactory : public ApiFactory { $
    constructor(DxApiFactory())
    destructor$(DxApiFactory())
    SystemApi* createSystemApi(void* apiData = 0);
    GraphicsApi* createGraphicsApi(void* apiData = 0);
    PhysicsApi* createPhysicsApi(void* apiData = 0);
    InputApi* createInputApi(void* apiData = 0);
    SoundApi* createSoundApi(void* apiData = 0);
    InputFactory* createInputFactory();
    GraphicsFactory* createGraphicsFactory();
    EntityFactory* createEntityFactory();
    SoundFactory* createSoundFactory();
})