#pragma once
#include <godmode.engine/$_namespaces.h>

godmode_engine_logic(class Releaseable { $
    virtual void release() = 0;
    virtual void restore() = 0;
})