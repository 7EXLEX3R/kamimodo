#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.engine/sound/AudioStream.h>

godmode_engine_sound(class Channel : public AudioStream { $
    static const int bandLimits[17];
    static const float gain[16];
    int bandCount;
    int bandHistoryBufferSize;
    List<float*> bandsHistory;
	List<float> bands;
	List<AudioStream*> linkedAudioStreams;
    constructor(Channel())
    destructor$(Channel())
    void link(AudioStream* audioStream);
    void unlink(AudioStream* audioStream);
    void update();
})