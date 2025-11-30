#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

godmode_foundation_types(template <typename T> struct DefaultValue {
    static constexpr T get() { return T{}; }
})
godmode_foundation_types(template <typename T> struct DefaultValue<T*> {
    static constexpr T* get() { return nullptr; }
})