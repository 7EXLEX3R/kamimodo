#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include "App.h"

test$class(LLMChatSample,
    test$method(constructor) {
        App *app = (App*) godmode::$_engineRuntime;
        expect(app->backgroundScene != nullptr);
        expect(app->chatBox != nullptr);
        expect(app->inputBox != nullptr);
    }
)
#endif