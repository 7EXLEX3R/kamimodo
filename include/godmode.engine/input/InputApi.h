#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/input/InputDevice.h>
#include <godmode.engine/input/InputFactory.h>
#include <godmode.foundation/types/List.h>

godmode_engine_input(class InputApi : public InputDevice { $
    List<InputDevice*> devices;
    constructor(InputApi())
    destructor$(InputApi())
    virtual InputApi* run();
    virtual void update();
    virtual KeyState keyState(int key);
    virtual bool keyPressed(int key);
    virtual bool keyDown(int key);
    virtual bool keyUp(int key);
    virtual int getKey();
    virtual List<int> getKeys();
    virtual int getKeyPressed();
    virtual List<int> getKeysPressed();
    virtual int getKeyPushed();
    virtual List<int> getKeysPushed();
    virtual int getKeyUp();
    virtual List<int> getKeysUp();
    virtual int getKeyDown();
    virtual List<int> getKeysDown();
    virtual void clearKeyBuffers();
    virtual void clearKeyPressedBuffer();
    virtual void clearKeyUpBuffer();
    virtual void clearKeyDownBuffer();
    InputDevice* addDevice(InputDevice* device);
    void removeDevice(InputDevice* device);
})
godmode_engine_input$extern($_inputApi, InputApi*)