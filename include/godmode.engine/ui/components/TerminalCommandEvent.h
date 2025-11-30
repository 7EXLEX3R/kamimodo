#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/Event.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(class TerminalCommandEvent : public Event { $
    String command;
    constructor(TerminalCommandEvent(String command))
    destructor$(TerminalCommandEvent())
})