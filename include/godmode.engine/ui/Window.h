#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/Label.h>

godmode_engine_ui(struct WindowParams : virtual ContainerParams {
    String title = "";
})
godmode_engine_ui(class Window : virtual public WindowParams, public Container { $
    Text2d *t2d = nullptr;
    Sprite *background = nullptr;
    Button *closeButton = nullptr;
    Button *expandButton = nullptr;
    Label *titleLabel = nullptr;
    int sortIndex = -1;
    int destSortIndex = -1;
    String title;
    bool expanded = false;
    float2 expandedSize;
    constructor(Window(const WindowParams& params = WindowParams()))
    destructor$(Window())
    void whenDrag(float2 &move);
    void setSize(float2 &size, bool isExpandedSize = true);
    void setTitle(String title);
    void expand(bool isExpand = true);
    bool isExpanded();
    void close();
    void refresh();
})