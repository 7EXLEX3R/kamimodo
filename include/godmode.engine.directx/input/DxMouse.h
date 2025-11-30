#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/input/Mouse.h>
#include <godmode.engine/logic/Releaseable.h>

godmode_engine_directx_input(class DxMouse : public Mouse, public Releaseable { $
    LPDIRECTINPUTDEVICE8 dxDevice = nullptr;
    constructor(DxMouse())
    destructor$(DxMouse())
    void update();
    void release();
    void restore();
})