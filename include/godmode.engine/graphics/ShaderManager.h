#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>
#include <godmode.engine/logic/SceneManager.h>
#include <godmode.engine/system/FpsMeter.h>

godmode_engine_graphics(class ShaderManager { $
    double timeCounter = 0;
    double frameCounter = 0;
    constructor(ShaderManager())
    destructor$(ShaderManager())
    void update();
    void render();
})
godmode_engine_graphics$extern($_shaderManager, ShaderManager*)