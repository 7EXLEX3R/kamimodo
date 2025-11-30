#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/system/Config.h>
#include <godmode.engine/logic/_3d/Scene3d.h>
#include <godmode.engine/input/InputApi.h>

godmode_engine_utils(class EffectsController { $
    static bool reloadEffectsOnCtrlS(Scene3d* scene) {
       if (godmode::$_inputApi->key(Key::LCONTROL) && godmode::$_inputApi->keyDown(Key::S)) {
           delete godmode::$_config;
           godmode::$_config = new Config();
           delete scene->effects;
           scene->effects = new Effects();
           return true;
       }
       return false;
    }
    static bool reloadShaderOnCtrlS(String shaderPath, Scene3d* scene = nullptr) {
        if (godmode::$_inputApi->key(Key::LCONTROL) && godmode::$_inputApi->keyDown(Key::S)) {
            Content* content = scene != nullptr ? scene->content : godmode::$_content;
            String shaderName = shaderPath.split("shaders/")[1].split(".fx")[0];
            Shader* shader = content->shaders.at(shaderName);
            if (!shader)
                shader = $_internalContent->shaders.at(shaderName);
            shader->load(shaderPath);
            return true;
        }
        return false;
    }
    static bool reloadShaderOnCtrlS(Shader *shader) {
        if (godmode::$_inputApi->key(Key::LCONTROL) && godmode::$_inputApi->keyDown(Key::S)) {
            shader->load(shader->getPath());
            return true;
        }
        return false;
    }
})