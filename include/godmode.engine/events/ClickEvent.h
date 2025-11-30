#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/Component.h>
#include <godmode.foundation/events/Event.h>
#include <godmode.foundation/log/Logger.h>

godmode_engine_events(class ClickEvent : public Event, public StringRepresentable { $
    float2 position;
    Component *clickedComponent = nullptr;
    constructor(ClickEvent(float2 &position, Component *const clickedComponent))
    destructor$(ClickEvent())
})