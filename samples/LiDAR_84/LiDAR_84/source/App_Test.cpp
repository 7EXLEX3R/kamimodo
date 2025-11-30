#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include "App.h"

test$class(LiDAR_84Sample,
    test$method(constructor) {
        LiDAR_84Sample* app = (LiDAR_84Sample*)$_engineRuntime;
        expect(app->respawnPositions.length() == 4);
    }
)
#endif