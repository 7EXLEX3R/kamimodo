#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/file/Directory.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/TreeBoxItem.h>

godmode_engine_ui_components(struct TreeBoxParams : virtual TreeBoxItemParams, virtual ContainerParams {
    String path = "";
})
godmode_engine_ui_components(class TreeBox : virtual public TreeBoxParams, public TreeBoxItem, public Container { $
    TreeBoxItem *selectedItem = nullptr;
    TreeBoxItem *highlightedItem = nullptr;
    List<String> filters;
    private$(Sprite *background = nullptr)
    private$(Directory *directory = nullptr)
    private$(float optionHeight = 16)
    constructor(TreeBox(const TreeBoxParams& params = TreeBoxParams()))
    destructor$(TreeBox())
    void refresh();
    void onClick();
    void whenMouseIn();
    void recalculateOptions();
    void createEntities(TreeBoxItem *item);
    void fromContentItem(TreeBoxItem *item, Directory *directory);
    void setFilter(List<String>& filters);
    void setItems(List<TreeBoxItem*>& items);
    private$(void initBackground())
    private$(void calculateScrolls())
})