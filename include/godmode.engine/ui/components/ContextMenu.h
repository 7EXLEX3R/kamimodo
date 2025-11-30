#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/ListBox.h>
#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(class ContextMenu)
godmode_engine_ui_components(class ContextMenuItem)
godmode_engine_ui_components(struct ContextMenuItemParams {
    String title = "";
    void (*action)(void* context) = nullptr;
    void* context = nullptr;
    List<ContextMenuItem*> items;
})
godmode_engine_ui_components(class ContextMenuItem : virtual public ContextMenuItemParams { $
    ContextMenu* assignedContextMenu;
    constructor(ContextMenuItem(const ContextMenuItemParams& params = ContextMenuItemParams()))
    destructor$(ContextMenuItem())
})
godmode_engine_ui_components(struct ContextMenuParams : virtual ContainerParams {
    List<ContextMenuItem*> contextMenuItems;
})
godmode_engine_ui_components(class ContextMenu : virtual public ContextMenuParams, public Container { $
    List<ContextMenu*> contextMenus;
    bool open = false;
    ListBox* listBox = nullptr;
    constructor(ContextMenu(const ContextMenuParams& params = ContextMenuParams()))
    destructor$(ContextMenu())
    void onClick();
    void refresh();
    bool setOpen(bool open = true);
})