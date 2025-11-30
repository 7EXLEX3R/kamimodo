#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/input/Keyboard.h>
#include <godmode.engine/logic/Releaseable.h>

godmode_engine_directx_input(class DxKeyboard : public Keyboard, public Releaseable { $
    LPDIRECTINPUTDEVICE8 dxDevice = nullptr;
    constructor(DxKeyboard())
    destructor$(DxKeyboard())
    void update();
    void release();
    void restore();
})