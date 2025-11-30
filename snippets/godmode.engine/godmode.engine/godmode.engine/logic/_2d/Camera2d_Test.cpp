#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_2d/Camera2d.h>

test$class(Camera2d,
    test$method(serialize) {
        Camera2d* camera2d = new$(Camera2d, _.position = float2(1, 2), _.rotation = 6, _.scale = float2(7, 8));
        camera2d->process();
        Camera2d* camera2dFromFile;
        Serializer::pipe(camera2d, camera2dFromFile);
        expect(camera2d->position == camera2dFromFile->position);
        expect(camera2d->viewProjectionMatrix == camera2dFromFile->viewProjectionMatrix);

        delete camera2d;
        delete camera2dFromFile;
    }
)
#endif