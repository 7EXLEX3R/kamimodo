#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/graphics/GraphicsEntity.h>
#include <godmode.engine/logic/Scene.h>
#include <godmode.engine/logic/_2d/Camera2d.h>
#include <godmode.engine/logic/_2d/Quadtree.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_logic__2d(class Scene2d : public Scene<BaseEntity2d> { $
    List<Sprite*> sprites;
    constructor(Scene2d(int viewportWidth = 0, int viewportHeight = 0))
    destructor$(Scene2d())
    Sprite* addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void updateEntities();
    void render();
    s11n$declare()
})
s11n$export(Scene2d)