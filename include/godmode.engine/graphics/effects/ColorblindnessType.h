#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics_effects(class ColorblindnessType { $ // TODO: types/Enum
    int code;
    static const ColorblindnessType NONE;
    static const ColorblindnessType PROTANOPIA;
    static const ColorblindnessType PROTANOMALY;
    static const ColorblindnessType DEUTERANOPIA;
    static const ColorblindnessType DEUTERANOMALY;
    static const ColorblindnessType TRITANOPIA;
    static const ColorblindnessType TRITANOMALY;
    static const ColorblindnessType ACHROMATOPSIA;
    static const ColorblindnessType ACHROMATOMALY;
    constexpr ColorblindnessType(int code = 0);
    constexpr ColorblindnessType(const ColorblindnessType& other);
    operator int() const;
    String toString() const;
    static String toString(const ColorblindnessType& type);
    static ColorblindnessType fromString(const String& name);
    const float* values() const;
    private$(static const String names[9])
    private$(static const float matrix[9][9])
})