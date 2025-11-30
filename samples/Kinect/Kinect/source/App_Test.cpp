#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include "App.h"

test$class(KinectSample,
    test$method(constructor) {
        KinectSample *app = (KinectSample*) godmode::$_engineRuntime;
        expect(godmode::$_kinect->available == true);
        expect(app->scene != nullptr);
        expect(app->leftHandObject != nullptr);
        expect(app->rightHandObject != nullptr);
    }
)
#endif