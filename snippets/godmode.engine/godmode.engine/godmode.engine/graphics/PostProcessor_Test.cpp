#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/PostProcessor.h>

test$class(PostProcessor,
    test$method(serialize) {
        PostProcessor* postprocessor = new PostProcessor();
        postprocessor->renderBufferTextureName = "test";
        PostProcessor* postprocessorFromFile;
        Serializer::pipe(postprocessor, postprocessorFromFile);
        expect(postprocessor->renderBufferTextureName == postprocessorFromFile->renderBufferTextureName);
        delete postprocessor;
        delete postprocessorFromFile;
    }
)
#endif