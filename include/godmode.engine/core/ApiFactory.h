#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/GraphicsApi.h>
#include <godmode.engine/input/InputApi.h>
#include <godmode.engine/physics/PhysicsApi.h>
#include <godmode.engine/sound/SoundApi.h>
#include <godmode.engine/system/SystemApi.h>

godmode_engine_core(class ApiFactory { $
    constructor(ApiFactory())
    destructor$(ApiFactory())
    virtual SystemApi* createSystemApi(void* apiData = 0) = 0;
    virtual GraphicsApi* createGraphicsApi(void* apiData = 0) = 0;
    virtual PhysicsApi* createPhysicsApi(void* apiData = 0) = 0;
    virtual InputApi* createInputApi(void* apiData = 0) = 0;
    virtual SoundApi* createSoundApi(void* apiData = 0) = 0;
    virtual InputFactory* createInputFactory() = 0;
    virtual GraphicsFactory* createGraphicsFactory() = 0;
    virtual EntityFactory* createEntityFactory() = 0;
    virtual SoundFactory* createSoundFactory() = 0;

})
godmode_engine_core$extern($_apiFactory, ApiFactory*)