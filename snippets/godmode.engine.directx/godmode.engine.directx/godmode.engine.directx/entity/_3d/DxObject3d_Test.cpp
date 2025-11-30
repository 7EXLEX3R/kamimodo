#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/EngineRuntime.h>
#include <godmode.engine.directx/entity/_3d/DxObject3d.h>
#include <godmode.engine.directx/graphics/DxModel.h>
#include <godmode.engine.directx/graphics/DxShader.h>

test$class(DxObject3d,
    test$method(serialize) {
        $_engineRuntime->frameBegin();
        Model* model = new DxModel("models/skybox/skybox.X");
        Shader* shader = new DxShader("shaders/solid.fx", "_default");
        Object3d* object = new DxObject3d(params$(Object3d, _.model = model, _.shader = shader));
        Object3d* deserializedObject;
        Serializer::pipe(object, deserializedObject);
        expect(object->model->getPath() == deserializedObject->model->getPath());
        delete object->shader;
        delete object->model;
        delete object;
        delete deserializedObject->shader;
        delete deserializedObject->model;
        delete deserializedObject;
        $_engineRuntime->frameEnd();
    }
)
#endif