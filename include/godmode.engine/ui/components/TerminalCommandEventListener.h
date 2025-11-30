#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.engine/ui/components/TerminalCommandEvent.h>

godmode_engine_ui_components(class TerminalCommandEventListener : public EventListener<TerminalCommandEvent> { $
    virtual void handleEvent(TerminalCommandEvent *event);
})