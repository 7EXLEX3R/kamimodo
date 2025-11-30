#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_3d/Light.h>

test$class(Light,
    test$method(serialize) {
        Light* light = new$(Light, _.position = float3(1, 2, 3), _.color = float4(1, 2, 3, 4), _.range = 500, _.enabled = true);
        light->process();
        Light* lightFromFile;
        Serializer::pipe(light, lightFromFile);
        expect(light->position == lightFromFile->position);
        expect(light->baseMaxOffset == lightFromFile->baseMaxOffset);
        delete light;
        delete lightFromFile;
    }
)
#endif