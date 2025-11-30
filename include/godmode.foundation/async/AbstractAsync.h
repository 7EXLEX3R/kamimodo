#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/async/AsyncState.h>
#include <godmode.foundation/types/List.h>

godmode_foundation_async(class AbstractAsync { $
    destructor$(AbstractAsync() {})
    virtual AsyncState process() = 0;
})
godmode_foundation_async$extern($_asyncs, List<AbstractAsync*>)
godmode_foundation_async$extern($_asyncAsyncs, List<AbstractAsync*>)