#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>
#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/graphics/Font.h>
#include <godmode.engine/graphics/Renderer.h>
#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/EntityTree.h>
#include <godmode.engine/logic/SceneStateChangeType.h>
#include <godmode.engine/logic/_2d/Camera2d.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/serialization/Serialization.h>

godmode_engine_logic(template <class BaseEntityType> class Scene : public ContentItem { $
    List<Camera*> cameras;
    List<BaseEntityType*> entities;
    Camera* currentCamera = nullptr;
    Lightning* lightning = nullptr;
    Effects* effects = nullptr;
    Renderer<BaseEntityType>* renderer = nullptr;
    EntityTree* entityTree = nullptr;
    Content* content = nullptr;
    float viewportWidth = 0;
    float viewportHeight = 0;
    constructor(Scene())
    constructor(Scene(float viewportWidth, float viewportHeight))
    destructor$(Scene())
    Camera* addCamera(Camera* camera);
    void removeCamera(Camera* camera);
    Camera* setCurrentCamera(Camera* camera);
    Camera* getCurrentCamera() const;
    virtual BaseEntityType* addEntity(BaseEntityType* entity);
    virtual BaseEntityType* removeEntity(BaseEntityType* entity);
    virtual void simulate();
    void update();
    virtual void updateEntities();
    virtual void render();
    s11n$declareSplit()
})
s11n$export(Scene<BaseEntity2d>);
s11n$export(Scene<BaseEntity3d>);