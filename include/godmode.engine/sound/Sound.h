#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/sound/AudioStream.h>

godmode_engine_sound(class Sound : public AudioStream, public ContentItem { $
    constructor(Sound())
    constructor(Sound(String path, String name = ""))
    destructor$(Sound())
    virtual bool load(String path, String name = "");
    virtual bool play();
    virtual bool stop();
    virtual bool pause();
    virtual bool isPlaying();
    virtual bool isStopped();
    virtual bool isPaused();
    s11n$declare()
})
// s11n$export(Sound);