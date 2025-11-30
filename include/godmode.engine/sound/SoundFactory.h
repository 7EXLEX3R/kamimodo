#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/sound/SoundDevice.h>
#include <godmode.engine/sound/Sound.h>

godmode_engine_sound(class SoundFactory { $
    constructor(SoundFactory())
    destructor$(SoundFactory())
    virtual SoundDevice* createSoundDevice() = 0;
    virtual Sound* createSound(String path, String name = "") = 0;
})
godmode_engine_sound$extern($_soundFactory, SoundFactory*)