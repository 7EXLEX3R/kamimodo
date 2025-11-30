#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite_Mock.h>

test$class(Sprite,
    test$method(serialize) {
        Sprite* sprite = new SpriteMock(params$(Sprite, _.position = float2(1, 2), _.rotation = 3, _.scale = float2(4, 5)));
        Sprite* spriteFromFile;
        Serializer::pipe(sprite, spriteFromFile);
        expect(sprite->position == spriteFromFile->position);
        delete sprite;
        delete spriteFromFile;
    }
)
#endif