#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>

test$class(Content,
    test$method(serialize) {
        Content* content = new Content();
        content->addCubeTexture(512, "cube");
        content->addFont("Tahoma", 12);
        content->addModel("xxx");
        content->addShader("xxx");
        content->addSound("xxx");
        content->addTexture("xxx");
        Content* deserializedContent;
        SerializerOutput so("temp/Content.test.serialize", content);
        SerializerInput si("temp/Content.test.serialize", deserializedContent);
        expect(content->cubeTextures[0]->size == deserializedContent->cubeTextures[0]->size);
        expect(content->fonts[0]->fontFace == deserializedContent->fonts[0]->fontFace);
        expect(content->models[0]->getName() == deserializedContent->models[0]->getName());
        expect(content->sounds[0]->getName() == deserializedContent->sounds[0]->getName());
        expect(content->textures[0]->getName() == deserializedContent->textures[0]->getName());
        expect(content->shaders[0]->getName() == deserializedContent->shaders[0]->getName());
        delete content;
        delete deserializedContent;
    }
)
#endif