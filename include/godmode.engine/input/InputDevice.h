#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/input/KeyState.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/Map.h>
#include <godmode.foundation/types/String.h>

godmode_engine_input(class InputDevice { $
    String id;
    constructor(InputDevice(String id = ""))
    destructor$(InputDevice())
    virtual void updateKeyBuffers();
    virtual void update() = 0;
    virtual KeyState keyState(int key);
    virtual bool keyState(int key, KeyState ks);
    virtual bool key(int key);
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
    virtual void keyProcess(List<int> &keys);
    protected$(List<int> keysPressed)
    protected$(List<int> keysPushed)
    protected$(List<int> keysDown)
    protected$(List<int> keysUp)
    protected$(List<int> keyBuffer)
    protected$(Map<char, int> keyCountMap)
})