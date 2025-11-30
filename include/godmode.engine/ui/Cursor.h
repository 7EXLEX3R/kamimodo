#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Line2dFixed.h>
#include <godmode.engine/logic/_2d/Scene2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_ui(class Cursor : public float2 { $
    Line2dFixed *lines[4] = {nullptr, nullptr, nullptr, nullptr};
    float2 move;
    float2 guiPosition;
    Scene2d *relativeScene = nullptr;
    bool locked = false;
    constructor(Cursor(Scene2d *scene2d = 0))
    destructor$(Cursor())
    void update();
    void addToScene(Scene2d *scene2d);
})
godmode_engine_ui$extern($_cursor, Cursor*)