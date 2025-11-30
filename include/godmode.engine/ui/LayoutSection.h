#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.engine/ui/Window.h>

godmode_engine_ui(class LayoutSection { $
    float4 rect;
    float2 scroll;
    List<Window*> windowList;
    constructor(LayoutSection(float4& rect))
    destructor$(LayoutSection())
    void update(List<Window*>& windows);
    void checkout(Window* window);
    void scrolling();
})