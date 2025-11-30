#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Texture_Mock.h>

test$class(Texture,
    test$method(serialize) {
        Texture* texture = new TextureMock("SSS", "NNN");
        Texture* textureFromFile;
        Serializer::pipe(texture, textureFromFile);
        expect(texture->getName() == textureFromFile->getName());
        delete texture;
        delete textureFromFile;
    }
)
#endif