#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/Event.h>
#include <godmode.foundation/types/List.h>

godmode_foundation_events(class Events { $
    List<Event*> pendingEvents;
    constructor(Events())
    destructor$(Events())
    void emit(Event *event);
    void update();
})
godmode_foundation_events$extern($_events, Events*)