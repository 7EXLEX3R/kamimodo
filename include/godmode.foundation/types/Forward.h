#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.utility.h>

#define forward$(className, paramsStructName, ...) template<typename... Args>  className(Args&&... args) \
    : paramsStructName { std::forward<Args>(args)... } { __VA_ARGS__; }