#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/sound/Sound.h>
#include <godmode.engine/sound/Channel.h>
#include <godmode.engine/sound/SoundDevice.h>
#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>

godmode_engine_sound(class Sampler { $
    MappedList<String, Sound*> samples;
    constructor(Sampler())
    destructor$(Sampler())
    void update();
    Sound* addSample(Sound* sound, String name = "");
    Sampler* removeSample(Sound* sound);
    Sampler* removeSample(String name);
})