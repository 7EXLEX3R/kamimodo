#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(class TreeBoxItem)
godmode_engine_ui_components(struct TreeBoxItemParams {
    String value = "";
    void* data = nullptr;
    TreeBoxItem* parent = nullptr;
    bool open = false;
    bool collapsable = false;
    ContentItem* contentItem = nullptr;
    List<TreeBoxItem*> items;
})
godmode_engine_ui_components(class TreeBoxItem : virtual public TreeBoxItemParams { $
    constructor(TreeBoxItem(const TreeBoxItemParams& params = TreeBoxItemParams()))
    destructor$(TreeBoxItem())
})