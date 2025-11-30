#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/sound/SoundDevice.h>

godmode_engine_directx_sound(class DxSoundDevice : public SoundDevice { $
    IDirectSound8* dxDevice = nullptr;
    constructor(DxSoundDevice())
    destructor$(DxSoundDevice())
})