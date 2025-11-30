#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/Label.h>
#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(struct ListBoxParams : virtual ContainerParams {
    MappedList<String, void*> items;
})
godmode_engine_ui_components(class ListBox : virtual public ListBoxParams, public Container { $
    String selectedItemName;
    String mouseoverItemName;
    void* selectedItem = nullptr;
    void* mouseoverItem = nullptr;
    void* dragItem = nullptr;
    bool isDragAttempt = false;
    int dragReplaceIndex = -1;
    List<String> filters;
    float optionHeight = 16;
    bool replaceEnabled = false;
    bool removeEnabled = false;
    private$(Sprite* background)
    private$(Line2d* line2d)
    constructor(ListBox(const ListBoxParams& params = ListBoxParams()))
    destructor$(ListBox())
    void refresh();
    void onClick();
    void whenMouseIn();
    void whenMouseOut();
    bool selectItemByName(String name);
    bool selectItem(void* byValue);
    bool select(void* element);
    void unselect();
    void setItems(MappedList<String, void*>& options);
    void setFilter(List<String>& filters);
    private$(void calculateScrolls())
    private$(void recreateItemLabels())
    private$(void createItemLabels())
})