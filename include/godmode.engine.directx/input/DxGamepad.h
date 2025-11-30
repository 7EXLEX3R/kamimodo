#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/input/Gamepad.h>

godmode_engine_directx_input(class DxGamepad : public Gamepad { $
    LPDIRECTINPUTDEVICE8 dxDevice = nullptr;
    constructor(DxGamepad(String id = ""))
    destructor$(DxGamepad())
    void update();
    void release();
    void restore();
})