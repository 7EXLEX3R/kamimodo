#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/logic/_2d/Camera2d.h>
#include <godmode.engine/logic/_2d/Scene2d.h>

godmode_engine_utils(class HUD : public Scene2d, public Camera2d { $
    Sprite* crosshair = nullptr;
    Sprite* crosshairDot = nullptr;
    constructor(HUD())
    destructor$(HUD())
    void process();
})