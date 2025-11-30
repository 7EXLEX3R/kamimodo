#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/EntityFactory.h>
#include <godmode.engine/entity/_2d/Line2dFixed_Mock.h>
#include <godmode.engine/entity/_2d/SpriteFullScreen_Mock.h>
#include <godmode.engine/entity/_2d/Sprite_Mock.h>
#include <godmode.engine/entity/_3d/Line3d_Mock.h>
#include <godmode.engine/entity/_3d/Object3d_Mock.h>

godmode_engine_entity(class EntityFactoryMock : public EntityFactory { $
    constructor(EntityFactoryMock() : EntityFactory() {})
    destructor$(EntityFactoryMock() {})
    Text2d *createText2d(const Text2dParams& params = Text2dParams()) { return 0; }
    Line2d *createLine2d(const Line2dParams& params = Line2dParams()) { return 0; }
    Line2dFixed *createLine2dFixed(const Line2dFixedParams& params = Line2dFixedParams()) { return new Line2dFixedMock(); }
    Sprite *createSprite(const SpriteParams& params = SpriteParams()) { return new SpriteMock(); }
    SpriteFixed *createSpriteFixed(const SpriteFixedParams& params = SpriteFixedParams()) { return 0; }
    SpriteFullScreen *createSpriteFullScreen(const SpriteFullScreenParams& params = SpriteFullScreenParams()) { return new SpriteFullScreenMock(); }
    Object3d *createObject3d(const Object3dParams& params = Object3dParams()) { return new Object3dMock(); }
    Line3d *createLine3d(const Line3dParams& params = Line3dParams()) { return new Line3dMock(); }
})