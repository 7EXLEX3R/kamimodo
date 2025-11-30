#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/input/InputDevice.h>
#include <godmode.engine/input/InputFactory.h>

godmode_engine_directx_input(class DxInputFactory : public InputFactory { $
    constructor(DxInputFactory())
    destructor$(DxInputFactory())
    virtual InputDevice* createInputDevice(String id = "");
    virtual Keyboard* createKeyboard(String id = "");
    virtual Mouse* createMouse(String id = "");
    virtual Gamepad* createGamepad(String id = "");
})