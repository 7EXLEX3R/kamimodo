#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.engine/events/Scene3dChangeEvent.h>
#include <godmode.engine/ui/Window.h>
#include <godmode.engine/ui/components/ImageBox.h>

godmode_engine_ui_apps(class RendererTexturesApp : public Window, public EventListener<Scene3dChangeEvent> { $
    ImageBox *renderTexture = nullptr;
    ImageBox *depthTexture = nullptr;
    ImageBox *velocityTexture = nullptr;
    ImageBox *normalTexture = nullptr;
    ImageBox *lastVelocityTexture = nullptr;
    ImageBox *refractDepthTexture = nullptr;
    ImageBox *refractRenderTexture = nullptr;
    ImageBox *materialTexture = nullptr;
    ImageBox *lightDiffuse = nullptr;
    ImageBox *lightSpecularTexture = nullptr;
    ImageBox *lightShadowTexture = nullptr;
    ImageBox *composeTexture = nullptr;
    ImageBox *renderedTexture = nullptr;
    constructor(RendererTexturesApp())
    destructor$(RendererTexturesApp())
    void whenActive();
    void handleEvent(Scene3dChangeEvent *event);
    private$(void attachTexturesToImageBoxes())
})