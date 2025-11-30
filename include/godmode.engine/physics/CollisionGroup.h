#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Enum.h>

godmode_engine_physics(enum$(CollisionGroup,
    NONE,
    NON_COLLIDABLE,
    COLLIDABLE_NON_PUSHABLE,
    COLLIDABLE_PUSHABLE
))
#define COLLIDABLE_MASK (1 << CollisionGroup::COLLIDABLE_NON_PUSHABLE) | (1 << CollisionGroup::COLLIDABLE_PUSHABLE)