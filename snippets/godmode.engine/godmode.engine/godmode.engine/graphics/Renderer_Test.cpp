#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/graphics/Renderer.h>

test$class(Renderer,
    test$method(serialize) {
        Renderer<BaseEntity3d>* renderer = new Renderer<BaseEntity3d>(512, 512);
        renderer->deferred = true;
        Renderer<BaseEntity3d>* deserializedRenderer;
        Serializer::pipe(renderer, deserializedRenderer);
        expect(renderer->deferred == deserializedRenderer->deferred);
        delete renderer;
        delete deserializedRenderer;
    }
)
#endif