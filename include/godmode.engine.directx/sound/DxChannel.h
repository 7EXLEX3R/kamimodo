#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/sound/Channel.h>

godmode_engine_directx_sound(class DxChannel : public Channel { $
    IDirectSoundBuffer* dxSoundBuffer = nullptr;
    constructor(DxChannel())
    destructor$(DxChannel())
})