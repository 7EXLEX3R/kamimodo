#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Shader_Mock.h>

test$class(Shader,
    test$method(serialize) {
        Shader* shader = new ShaderMock("SSS", "NNN");
        Shader* shaderFromFile;
        Serializer::pipe(shader, shaderFromFile);
        expect(shader->getName() == shaderFromFile->getName());
        delete shader;
        delete shaderFromFile;
    }
)
#endif