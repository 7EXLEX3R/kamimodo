#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/sound/Sound.h>

godmode_engine_sound(class SoundMock : public Sound { $
    constructor(SoundMock())
    constructor(SoundMock(String path, String name = ""))
    destructor$(SoundMock())
    virtual bool load(String path, String name = "");
    virtual bool play();
    virtual bool stop();
    virtual bool pause();
    s11n$defineInline({
        ar.template register_type<SoundMock>();
        ar & boost::serialization::base_object<Sound>(*this);
    });
})
s11n$export(SoundMock);
s11n$instantiate(SoundMock);