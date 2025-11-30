#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include "App.h"

test$class(AudioVisualizerSample,
    test$method(constructor) {
        AudioVisualizerSample* app = (AudioVisualizerSample*)$_engineRuntime;
        expect(app->sound != nullptr);
        expect(app->camera != nullptr);
        expect(app->scene != nullptr);
    }
)
#endif