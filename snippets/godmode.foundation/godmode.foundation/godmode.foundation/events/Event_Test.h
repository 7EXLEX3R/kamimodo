#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/types/StringRepresentable.h>
#include <godmode.foundation/events/EventListener.h>
#include <godmode.foundation/events/Event.h>

class ClickEvent : public Event, public StringRepresentable { $
    bool value;
    constructor(ClickEvent(bool value) : value(value) {})
    destructor$(ClickEvent() {})
    String toString() { return "ClickEvent:" + String::from(value); }
};
class ClickEventListener : public EventListener<ClickEvent> { $
    int counter = 0;
    void handleEvent(ClickEvent *event) { console->log(event->toString()); this->counter++; }
};
class XEvent : public Event, public StringRepresentable { $
    int value;
    constructor(XEvent(int value) : value(value) {})
    destructor$(XEvent() {})
    String toString() { return "XEvent:" + String::from(value); }
};
class XEventListener : public EventListener<XEvent> { $
    int counter = 0;
    void handleEvent(XEvent *event) { console->log(event->toString()); this->counter++; }
};