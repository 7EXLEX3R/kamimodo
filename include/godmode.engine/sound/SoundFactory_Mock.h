#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/sound/SoundFactory.h>
#include <godmode.engine/sound/Sound_Mock.h>

godmode_engine_sound(class SoundFactoryMock : public SoundFactory { $
    constructor(SoundFactoryMock() : SoundFactory() {})
    destructor$(SoundFactoryMock() {})
    SoundDevice* createSoundDevice() { return nullptr; };
    Sound* createSound(String path, String name = "") { return new SoundMock(path, name); };
})