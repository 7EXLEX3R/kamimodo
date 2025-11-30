#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/EntityFactory.h>

godmode_engine_directx_entity(class DxEntityFactory : public EntityFactory { $
    constructor(DxEntityFactory())
    destructor$(DxEntityFactory())
    Text2d *createText2d(const Text2dParams& params = Text2dParams());
    Line2d *createLine2d(const Line2dParams& params = Line2dParams());
    Line2dFixed *createLine2dFixed(const Line2dFixedParams& params = Line2dFixedParams());
    Sprite *createSprite(const SpriteParams& params = SpriteParams());
    SpriteFixed *createSpriteFixed(const SpriteFixedParams& params = SpriteFixedParams());
    SpriteFullScreen *createSpriteFullScreen(const SpriteFullScreenParams& params = SpriteFullScreenParams());
    Object3d *createObject3d(const Object3dParams& params = Object3dParams());
    Line3d *createLine3d(const Line3dParams& params = Line3dParams());
})