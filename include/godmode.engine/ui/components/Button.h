#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/Component.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(struct ButtonParams : virtual ComponentParams {
    String title = "";
})
godmode_engine_ui_components(class Button : virtual public ButtonParams, public Component { $
    Text2d *t2d = nullptr;
    bool checkable = false;
    bool checked = false;
    void *actionContext = nullptr;
    void (*action)(void* data) = nullptr;
    constructor(Button(const ButtonParams& params = ButtonParams()))
    destructor$(Button())
    virtual void onMouseEnter();
    virtual void onMouseLeave();
    virtual void onClick();
    virtual void onDoubleClick();
    bool setChecked(bool checked = true);
    void setColorsInactive();
    void setColorsActive();
    virtual List<BaseEntity2d *> getEntities();
})