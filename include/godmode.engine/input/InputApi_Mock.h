#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/input/InputApi.h>

godmode_engine_input(class InputApiMock : public InputApi { $
    constructor(InputApiMock() : InputApi() {})
    destructor$(InputApiMock() {})
    virtual void update() {};
})