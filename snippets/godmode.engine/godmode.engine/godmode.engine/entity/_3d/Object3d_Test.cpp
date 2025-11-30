#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d_Mock.h>

test$class(Object3d,
    test$method(serialize) {
        Object3d* object3d = new Object3dMock(params$(Object3d, _.position = {1,2,3}));
        Object3d* object3dFromFile;
        Serializer::pipe(object3d, object3dFromFile);
        expect(object3d->position == object3dFromFile->position);
        delete object3d;
        delete object3dFromFile;
    }
)
#endif