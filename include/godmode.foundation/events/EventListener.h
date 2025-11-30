#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/AbstractEventListener.h>
#include <godmode.foundation/events/Event.h>

godmode_foundation_events(template <class EventClass> class EventListener : public AbstractEventListener { $
    virtual void handleEvent(EventClass *event) = 0;
    void handle(Event *event) {
        if (auto casted = dynamic_cast<EventClass *>(event))
            this->handleEvent(casted);
    }
})