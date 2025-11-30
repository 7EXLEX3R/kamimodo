#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/entity/_2d/Line2dFixed.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/entity/_2d/SpriteFixed.h>
#include <godmode.engine/entity/_2d/SpriteFullScreen.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/entity/_3d/Line3d.h>
#include <godmode.engine/entity/_3d/Object3d.h>

godmode_engine_entity(class EntityFactory { $
    constructor(EntityFactory())
    destructor$(EntityFactory())
    virtual Text2d *createText2d(const Text2dParams& params = Text2dParams()) = 0;
    virtual Line2d *createLine2d(const Line2dParams& params = Line2dParams()) = 0;
    virtual Line2dFixed *createLine2dFixed(const Line2dFixedParams& params = Line2dFixedParams()) = 0;
    virtual Sprite *createSprite(const SpriteParams& params = SpriteParams()) = 0;
    virtual SpriteFixed *createSpriteFixed(const SpriteFixedParams& params = SpriteFixedParams()) = 0;
    virtual SpriteFullScreen *createSpriteFullScreen(const SpriteFullScreenParams& params = SpriteFullScreenParams()) = 0;
    virtual Object3d *createObject3d(const Object3dParams& params = Object3dParams()) = 0;
    virtual Line3d *createLine3d(const Line3dParams& params = Line3dParams()) = 0;
})
godmode_engine_entity$extern($_entityFactory, EntityFactory*)