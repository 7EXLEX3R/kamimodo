#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/Event.h>
#include <godmode.foundation/types/List.h>

godmode_foundation_events(class AbstractEventListener { $
    constructor(AbstractEventListener())
    destructor$(AbstractEventListener())
    virtual void handle(Event *event) = 0;
})
godmode_foundation_events$extern($_eventListeners, List<AbstractEventListener*>)