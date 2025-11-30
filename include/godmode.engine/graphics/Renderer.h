#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/graphics/CubeTexture.h>
#include <godmode.engine/graphics/Effects.h>
#include <godmode.engine/graphics/PostProcessor.h>
#include <godmode.engine/graphics/PreProcessor.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/graphics/effects/SSAO.h>
#include <godmode.engine/graphics/effects/SSR.h>
#include <godmode.engine/logic/Camera.h>
#include <godmode.engine/logic/Lightning.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>

godmode_engine_graphics(template <class BaseEntityType> class Renderer { $
    int renderWidth = 0;
    int renderHeight = 0;
    Texture *renderTexture = nullptr;
    Texture *depthTexture = nullptr;
    Texture *velocityTexture = nullptr;
    Texture *lastVelocityTexture = nullptr;
    Texture *refractDepthTexture = nullptr;
    Texture *refractRenderTexture = nullptr;
    Texture *normalTexture = nullptr;
    Texture *materialTexture = nullptr;
    Texture *lightDiffuseTexture = nullptr;
    Texture *lightSpecularTexture = nullptr;
    Texture *lightShadowTexture = nullptr;
    Texture *composeTexture = nullptr;
    Texture *renderedTexture = nullptr;
    Sprite *fullscreenQuad = nullptr;
    PreProcessor<BaseEntityType> *preProcessor = nullptr;
    PostProcessor *postProcessor = nullptr;
    List<Texture *> shadowMaps;
    Shader *shadowMapShader = nullptr;
    Texture *shadowMapTexture = nullptr;
    Camera3d *auxiliaryCamera = nullptr;
    Shader *cubeShadowMapShader = nullptr;
    List<CubeTexture *> cubeShadowMapTextures;
    List<Texture *> screenSpaceShadowTexture;
    MappedList<String, Texture *> mapTextures;
    List<BaseEntityType *> processedEntities;
    bool deferred = false;
    Effect *deferredProcessor = nullptr;
    SSAO *ssao = nullptr;
    SSR *ssr = nullptr;
    bool boundingRenderingEnabled = false;
    bool renderingEnabled = true;
    bool postProcessingEnabled = true;
    String configName = "renderer";
    private$(int $maxCubeShadowMapCount = 4)
    constructor(Renderer())
    constructor(Renderer(unsigned renderWidth, unsigned renderHeight))
    constructor(Renderer(String configName))
    destructor$(Renderer())
    void render2d(List<BaseEntityType *> &entities, Camera *camera, Lightning *lightning, Effects *effects);
    void render(List<BaseEntityType *> &entities, Camera *camera, Lightning *lightning, Effects *effects);
    void renderOpaques(List<BaseEntityType *> &entities, Camera *camera, Lightning *lightning);
    void renderTranslucents(List<BaseEntityType *> &entities, Camera *camera, Lightning *lightning);
    void renderShadowMaps(List<BaseEntityType *> &entities, Camera *camera, Lightning *lightning);
    void renderShadowCubeMaps(List<BaseEntityType *> &entities, Camera *camera, Lightning *lightning);
    void renderShadowsToScreenSpace(List<BaseEntityType *> &entities, Camera *camera);
    void init();
    void recreate();
    s11n$declareSplit()
})
s11n$export(Renderer<BaseEntity2d>);
s11n$export(Renderer<BaseEntity3d>);