#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>

godmode_engine_graphics(class EffectFactory { $
    constructor(EffectFactory())
    destructor$(EffectFactory())
    Map<String, Effect* (*)(JSON config)> effectFactoryMap;
    Effect* createEffect(String name);
})
godmode_engine_graphics$extern($_effectFactory, EffectFactory*)