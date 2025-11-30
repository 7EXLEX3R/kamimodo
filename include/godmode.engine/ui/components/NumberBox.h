#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/TextBox.h>

godmode_engine_ui_components(struct NumberBoxParams : virtual ContainerParams {
    float value = 0;
    float step = 0;
    float minimum = 0;
    float maximum = 0;
    bool isMinimum = false;
    bool isMaximum = false;
})
godmode_engine_ui_components(class NumberBox : virtual public NumberBoxParams, public Container { $
    TextBox *textBox = nullptr;
    bool isEmpty = false;
    bool dragValue = false;
    constructor(NumberBox(const NumberBoxParams& params = NumberBoxParams()))
    destructor$(NumberBox())
    Text2d *numberDecrease;
    Text2d *numberIncrease;
    Line2d *numberDecreaseLines[2];
    Line2d *numberIncreaseLines[2];
    void setMinimum(float minimum);
    void setMaximum(float maximum);
    void unsetMinimum();
    void unsetMaximum();
    virtual void onClick();
    virtual void refresh();
    virtual void whenMouseIn();
    void setEmptyValue();
    void setValue(float value);
    void applyJsonValueBindingToValue();
    virtual void onActivate();
    virtual void onInactivate();
    virtual void whenActive();
    private$(String textBuffer)
})