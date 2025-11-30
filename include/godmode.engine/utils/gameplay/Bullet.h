#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>
#include <godmode.engine/entity/_3d/Object3d.h>

godmode_engine_utils(class Bullet { $
    Object3d* object = nullptr;
    float life = 0;
    float speed = 0;
    constructor(Bullet(Object3d* object, float speed, float maxLife))
    destructor$(Bullet())
    bool move();
})