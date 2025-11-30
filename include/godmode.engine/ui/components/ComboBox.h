#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/ListBox.h>
#include <godmode.engine/ui/components/TextBox.h>

godmode_engine_ui_components(struct ComboBoxParams : virtual ContainerParams {
    MappedList<String, void*> elements;
    void* value = 0;
})
godmode_engine_ui_components(class ComboBox : virtual public ComboBoxParams, public Container { $
    Text2d *collapse = nullptr;
    Line2d *collapseLines[2] = {nullptr, nullptr};
    ListBox *listBox = nullptr;
    TextBox *textBox = nullptr;
    bool isEmpty = false;
    constructor(ComboBox(const ComboBoxParams& params = ComboBoxParams()))
    destructor$(ComboBox())
    void onClick();
    void refresh();
    void setValue(String value);
    void setEmptyValue();
    void applyJsonValueBindingToValue();
    void whenMouseIn();
})