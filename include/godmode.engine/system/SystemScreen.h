#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>

godmode_engine_system(class SystemScreen { $
    virtual float2 getResolution() = 0;
})
godmode_engine_system$extern($_systemScreen, SystemScreen*)