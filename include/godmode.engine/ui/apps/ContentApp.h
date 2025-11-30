#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/List.h>
#include <godmode.engine/events/Scene3dChangeEvent.h>
#include <godmode.engine/graphics/Model.h>
#include <godmode.engine/graphics/ModelPreview.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/logic/SceneManager.h>
#include <godmode.engine/sound/Sound.h>
#include <godmode.engine/ui/Component.h>
#include <godmode.engine/ui/Window.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/ImageBox.h>
#include <godmode.engine/ui/components/ListBox.h>
#include <godmode.engine/ui/components/TreeBox.h>

godmode_engine_ui_apps(class ContentApp : public Window, public EventListener<Scene3dChangeEvent> { $
    ImageBox *imageBox = nullptr;
    TreeBox *contentBrowser = nullptr;
    ListBox *contentList = nullptr;
    ModelPreview *modelPreview = nullptr;
    List<String> supportedTextureExtensions;
    List<String> supportedSoundExtensions;
    List<String> supportedModelExtensions;
    List<String> supportedShaderExtensions;
    constructor(ContentApp())
    destructor$(ContentApp())
    void whenActive();
    private$(Texture *selectedTexture)
    private$(Model *selectedModel)
    private$(Sound *selectedSound)
    private$(Shader *selectedShader)
    private$(Button *modelsButton)
    private$(Button *shadersButton)
    private$(Button *texturesButton)
    private$(Button *soundsButton)
    private$(void updateFilters())
    private$(MappedList<String, void *> getContentListItems())
    private$(void handleEvent(Scene3dChangeEvent *event))
})