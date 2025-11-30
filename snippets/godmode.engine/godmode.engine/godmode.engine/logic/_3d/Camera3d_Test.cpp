#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_3d/Camera3d.h>

test$class(Camera3d, // TODO(4) - tests
    test$method(serialize) {
        // FIXME: display in graphicsDevice used in camera default constructor
        // module init on tests

        // FIXME: class boost::archive::archive_exception: input stream error
       /* List<Camera*> cameras;
        Camera3d* camera3d = new Camera3d(float3(1, 2, 3), float3(4, 5, 6), float3(7, 8, 9));
        camera3d->rotationPassed = float3(9, 8, 7);
        camera3d->process();
        SerializerOutput* so = new SerializerOutput("temp/Camera3d.test.serialize");
        cameras.add(camera3d);
        *so << cameras;
        delete so;

        Camera3d* camera3dFromFile;
        List<Camera*> deserializedCameras;
        SerializerInput* si = new SerializerInput("temp/Camera3d.test.serialize");
        *si >> deserializedCameras;
        camera3dFromFile = (Camera3d*)deserializedCameras[0];
        delete si;

        expect(camera3d->position == camera3dFromFile->position);
        expect(camera3d->viewProjectionMatrix == camera3dFromFile->viewProjectionMatrix);
        expect(camera3d->rotationPassed == camera3dFromFile->rotationPassed);

        delete camera3d;
        delete camera3dFromFile;*/
    }
)
#endif