#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/input/InputDevice.h>

godmode_engine_input(class Gamepad : public InputDevice { $
    constructor(Gamepad(String id = "gamepad"))
    destructor$(Gamepad())
    virtual void update() = 0;
})
godmode_engine_input$extern($_gamepad, Gamepad*)