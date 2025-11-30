#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Logger.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/sound/Sound.h>

godmode_engine_directx_sound(class DxSound : public Sound { $
    IDirectSoundBuffer8* dxSoundBuffer = nullptr;
    constructor(DxSound())
    constructor(DxSound(String path, String name = ""))
    destructor$(DxSound())
    bool load(String path, String name = "");
    bool play();
    bool pause();
    bool stop();
    private$(Logger<DxSound> logger{this})
    s11n$declareSplit()
})
s11n$export(DxSound);