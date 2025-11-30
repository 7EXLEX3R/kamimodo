#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/async/Async.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_ai(class LLM { $
    constructor(LLM())
    destructor$(LLM())
    virtual Async<String>* prompt(String prompt);
    virtual Async<String>* promptStream(String prompt, Function<void(String)> streamingHandler);
})
godmode_foundation_ai$extern($_llm, LLM*)