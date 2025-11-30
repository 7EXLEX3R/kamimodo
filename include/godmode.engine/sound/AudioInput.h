#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/sound/AudioStream.h>

godmode_engine_sound(class AudioInput : public AudioStream { $
    constructor(AudioInput())
    virtual bool captureSystemAudio();
})