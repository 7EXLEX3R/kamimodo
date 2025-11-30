#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/Lightning.h>

test$class(Lightning,
    test$method(serialize) {
        Lightning* lightning = new Lightning();
        lightning->addLight(new$(Light, _.position = float3(1, 2, 3), _.color = float4(1, 2, 3, 4), _.range = 500));
        lightning->enabled = false;
        lightning->update();
        Lightning* lightningFromFile;
        Serializer::pipe(lightning, lightningFromFile);
        expect(lightning->enabled == lightningFromFile->enabled);
        expect(lightning->ambient->color == lightningFromFile->ambient->color);
        expect(lightning->lights[0]->baseMinOffset == lightningFromFile->lights[0]->baseMinOffset);
        delete lightning;
        delete lightningFromFile;
    }
)
#endif