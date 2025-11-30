#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/input/InputDevice.h>
#include <godmode.engine/logic/Releaseable.h>

godmode_engine_directx_input(class DxInputDevice : public InputDevice, public Releaseable { $
    constructor(DxInputDevice(String id = ""))
    destructor$(DxInputDevice())
    virtual void release() = 0;
    virtual void restore() = 0;
})