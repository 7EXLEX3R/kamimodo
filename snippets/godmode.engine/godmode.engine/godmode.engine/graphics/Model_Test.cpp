#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Model_Mock.h>

test$class(Model,
    test$method(serialize) {
        Model* model = new ModelMock("SSS", "NNN");
        Model* modelFromFile;
        Serializer::pipe(model, modelFromFile);
        expect(model->getName() == modelFromFile->getName());
        delete model;
        delete modelFromFile;
    }
)
#endif