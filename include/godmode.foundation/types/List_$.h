#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.type_traits.h>

godmode_foundation_types(
    template <
        class ValueType,
        class ValueAccessType = typename std::conditional <
            std::is_pointer<ValueType>::value,
            ValueType,
            ValueType*
        >::type
    > class List
)