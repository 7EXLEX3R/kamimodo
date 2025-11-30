#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/input/Gamepad.h>
#include <godmode.engine/input/InputDevice.h>
#include <godmode.engine/input/Keyboard.h>
#include <godmode.engine/input/Mouse.h>
#include <godmode.engine/input/Kinect.h>

godmode_engine_input(class InputFactory { $
    constructor(InputFactory())
    destructor$(InputFactory())
    virtual InputDevice* createInputDevice(String id = "") = 0;
    virtual Keyboard* createKeyboard(String id = "") = 0;
    virtual Mouse* createMouse(String id = "") = 0;
    virtual Gamepad* createGamepad(String id = "") = 0;
    virtual Kinect* createKinect(String id = "");
})
godmode_engine_input$extern($_inputFactory, InputFactory*)