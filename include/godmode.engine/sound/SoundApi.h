#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/windows.h>
#include <godmode.foundation/types/Function.h>
#include <godmode.engine/sound/SoundDevice.h>
#include <godmode.engine/sound/SoundFactory.h>
#include <godmode.engine/sound/Mixer.h>
#include <godmode.engine/sound/Sampler.h>

godmode_engine_sound(class SoundApi { $
    Mixer* mixer = nullptr;
    Sampler* sampler = nullptr;
    SoundDevice* device = nullptr;
    AudioInput* systemAudioInput = nullptr;
    constructor(SoundApi())
    destructor$(SoundApi())
    void update();
    static DWORD CALLBACK wasapiProc(void* buffer, DWORD length, void* user);
    private$(int getLoopbackDeviceIndex())
})
godmode_engine_sound$extern($_soundApi, SoundApi*)