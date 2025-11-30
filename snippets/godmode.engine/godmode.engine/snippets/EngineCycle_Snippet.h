#pragma once
#include <godmode.foundation.h>
#include <godmode.engine.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

class EngineCycleSnippet : public EngineRuntime { $
    int cycleCount = 999;
    EngineCycleSnippet() {
        console->log("EngineCycleSnippet constructor");
    }
    virtual ~EngineCycleSnippet() {
        console->log("EngineCycleSnippet destructor");
    }
    void update() override {
        console->log(String::from(this->cycleCount));
        this->cycleCount--;
        if (this->cycleCount == 0) {
            this->terminate();
        }
    }
};