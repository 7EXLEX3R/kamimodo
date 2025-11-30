#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/sound/AudioInput.h>
#include <godmode.engine/sound/Sound.h>
#include <godmode.engine/sound/Channel.h>
#include <godmode.engine/sound/SoundDevice.h>

godmode_engine_sound(class Mixer { $
    Channel* master = nullptr;
    MappedList<String, Channel*> channels;
    MappedList<String, AudioInput*> audioInputs;
    constructor(Mixer())
    destructor$(Mixer())
    void update();
    Channel* addChannel(Channel* channel, String name = "");
    Mixer* removeChannel(Channel* channel);
    Mixer* removeChannel(String name);
    AudioInput* addAudioInput(AudioInput* audioInput, String name = "");
    Mixer* removeAudioInput(AudioInput* audioInput);
    Mixer* removeAudioInput(String name);
})