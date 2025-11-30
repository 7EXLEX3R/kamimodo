#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/ContextMenu.h>
#include <godmode.engine/ui/components/ListBox.h>

godmode_engine_ui_components(class MenuBarOption { $
    String title;
    List<ContextMenuItem*> contextMenuItems;
    void (*action)(void* context) = nullptr;
    void* context = nullptr;
    Button* assignedButton = nullptr;
    ContextMenu* assignedContextMenu = nullptr;
    constructor(MenuBarOption(String title, List<ContextMenuItem*>& contextMenuItems, void (*action)(void* context) = nullptr, void* context = nullptr))
    constructor(MenuBarOption(String title, void (*action)(void* context) = 0, void* context = 0))
    destructor$(MenuBarOption())
})
godmode_engine_ui_components(struct MenuBarParams : virtual ContainerParams {
    List<MenuBarOption*> menuBarItems;
    float optionWidth = 50;
})
godmode_engine_ui_components(class MenuBar : virtual public MenuBarParams, public Container { $
    List<Button*> buttonList;
    constructor(MenuBar(const MenuBarParams& params = MenuBarParams()))
    destructor$(MenuBar())
    void refresh();
})