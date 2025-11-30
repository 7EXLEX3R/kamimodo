#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/input/InputFactory.h>

godmode_engine_input(class InputFactoryMock : public InputFactory { $
    constructor(InputFactoryMock() : InputFactory() {})
    destructor$(InputFactoryMock() {})
    virtual InputDevice* createInputDevice(String id = "") { return 0; };
    virtual Keyboard* createKeyboard(String id = "") { return new Keyboard(); };
    virtual Mouse* createMouse(String id = "") { return new Mouse(); };
    virtual Gamepad* createGamepad(String id = "") { return 0; };
})