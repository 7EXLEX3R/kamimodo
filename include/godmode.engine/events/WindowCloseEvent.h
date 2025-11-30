#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/core/Content.h>
#include <godmode.engine/ui/Window.h>
#include <godmode.foundation/events/Event.h>

godmode_engine_events(class WindowCloseEvent : public Event { $
    Window *window = nullptr;
    constructor(WindowCloseEvent(Window *window))
    destructor$(WindowCloseEvent())
})