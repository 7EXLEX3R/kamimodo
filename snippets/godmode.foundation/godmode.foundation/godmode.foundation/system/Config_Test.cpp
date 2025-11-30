#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/system/Config.h>

test$class(Config,
    test$method(playground) {
        console->log($_config->toString());
        String promptEndpoint = $_config->get("ai.llmController.url"); // FIXME: getting unexisting field endup with exception
        expect(promptEndpoint == "http://localhost:3001");
        console->log($_config->toString());
    }
)
#endif