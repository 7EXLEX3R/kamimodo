#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/ApiFactory.h>
#include <godmode.engine/graphics/GraphicsApi_Mock.h>
#include <godmode.engine/input/InputApi_Mock.h>
#include <godmode.engine/physics/NxPhysicsApi.h>
#include <godmode.engine/sound/SoundApi_Mock.h>
#include <godmode.engine/system/SystemApi_Mock.h>
#include <godmode.engine/graphics/GraphicsFactory.h>
#include <godmode.engine/graphics/GraphicsFactory_Mock.h>
#include <godmode.engine/entity/EntityFactory.h>
#include <godmode.engine/entity/EntityFactory_Mock.h>
#include <godmode.engine/sound/SoundFactory_Mock.h>
#include <godmode.engine/input/InputFactory_Mock.h>

godmode_engine_core(class ApiFactoryMock : public ApiFactory { $
    constructor(ApiFactoryMock() : ApiFactory() {})
    destructor$(ApiFactoryMock() {})
    SystemApi* createSystemApi(void* apiData = 0) { return new SystemApiMock(); }
    GraphicsApi* createGraphicsApi(void* apiData = 0) { return new GraphicsApiMock(); }
    PhysicsApi* createPhysicsApi(void* apiData = 0) { return new NxPhysicsApi(); }
    InputApi* createInputApi(void* apiData = 0) { return new InputApiMock(); }
    SoundApi* createSoundApi(void* apiData = 0) { return new SoundApiMock(); }
    GraphicsFactory* createGraphicsFactory() { return new GraphicsFactoryMock(); }
    EntityFactory* createEntityFactory() { return new EntityFactoryMock(); }
    SoundFactory* createSoundFactory() { return new SoundFactoryMock(); };
    InputFactory* createInputFactory() { return new InputFactoryMock(); }
})