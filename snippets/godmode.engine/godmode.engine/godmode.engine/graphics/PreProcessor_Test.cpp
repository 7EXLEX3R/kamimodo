#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/graphics/PreProcessor.h>

test$class(PreProcessor,
    test$method(serialize) {
        PreProcessor<BaseEntity3d>* preprocessor = new PreProcessor<BaseEntity3d>();
        preprocessor->maxDistance = .2;
        PreProcessor<BaseEntity3d>* preprocessorFromFile;
        Serializer::pipe(preprocessor, preprocessorFromFile);
        expect(preprocessor->maxDistance == preprocessorFromFile->maxDistance);
        delete preprocessor;
        delete preprocessorFromFile;
    }
)
#endif