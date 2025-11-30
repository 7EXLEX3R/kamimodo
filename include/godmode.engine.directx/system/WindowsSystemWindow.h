#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/directx.h>
#include <godmode.engine/system/SystemWindow.h>

godmode_engine_directx_system(class WindowsSystemWindow : public SystemWindow { $
    WNDCLASSEX params;
    HWND window = nullptr;
    constructor(WindowsSystemWindow(JSON config))
    destructor$(WindowsSystemWindow())
    static LRESULT CALLBACK wndProcedure(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
    bool isActive();
})