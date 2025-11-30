#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(struct CheckBoxParams : virtual ContainerParams {
    String title = "";
    bool checked = false;
})
godmode_engine_ui_components(class CheckBox : virtual public CheckBoxParams, public Container { $
    bool isEmpty = false;
    Text2d *t2d = nullptr;
    Line2d *lines[2] = { nullptr, nullptr };
    Button *button = nullptr;
    constructor(CheckBox(const CheckBoxParams& params = CheckBoxParams()))
    destructor$(CheckBox())
    void setValue(bool value);
    void setEmptyValue();
    void applyJsonValueBindingToValue();
    virtual void whenActive();
    virtual void onMouseEnter();
    virtual void onMouseLeave();
    virtual void onClick();
    virtual void onDoubleClick();
})