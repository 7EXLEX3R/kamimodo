#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/$_preprocessor.h>

godmode_foundation(struct ParamsTestClassParams {
    float value = 1;
    float otherValue = 2;
    float otherValue_2 = 3;
    void* pointer = nullptr;
})
godmode_foundation(class ParamsTestClass { $
    float value;
    float otherValue;
    float otherValue_2;
    void* pointer;
    ParamsTestClass(ParamsTestClassParams p = ParamsTestClassParams())
        :   value(p.value),
            otherValue(p.otherValue),
            otherValue_2(p.otherValue_2),
            pointer(p.pointer) {
        console->log(p.value);
    }
})