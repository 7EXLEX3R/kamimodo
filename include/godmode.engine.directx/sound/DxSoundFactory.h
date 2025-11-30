#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/sound/SoundFactory.h>

godmode_engine_directx_sound(class DxSoundFactory : public SoundFactory { $
    constructor(DxSoundFactory())
    destructor$(DxSoundFactory())
    SoundDevice* createSoundDevice();
    Sound* createSound(String path, String name = "");
})