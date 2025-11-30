#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/input/InputApi.h>
#include <godmode.engine/logic/Releaseable.h>

godmode_engine_directx_input(class DxInputApi : public InputApi, public Releaseable { $
    LPDIRECTINPUT8 dxInput = nullptr;
    LPDIRECTINPUTDEVICE8 dxJoystickDevice = nullptr;
    DIJOYSTATE2 js;
    constructor(DxInputApi())
    destructor$(DxInputApi())
    void release();
    void restore();
    virtual void update();
})
godmode_engine_directx_input(struct DI_ENUM_CONTEXT {
    DIJOYCONFIG* pPreferredJoyCfg;
    bool bPreferredJoyCfgValid;
})
godmode_engine_directx_input(int CALLBACK enumJoysticksCallback(const DIDEVICEINSTANCE* pdidInstance, void* pContext))
godmode_engine_directx_input(int CALLBACK enumObjectsCallback(const DIDEVICEOBJECTINSTANCE* pdidoi, void* pContext))