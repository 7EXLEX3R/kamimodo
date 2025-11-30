#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/Component.h>

godmode_engine_ui_components(struct ScrollBarParams : virtual ComponentParams {
    float minimum = 0;
    float maximum = 0;
    float value = 0;
    float range = 0;
    float step = 1;
})
godmode_engine_ui_components(class ScrollBar : virtual public ScrollBarParams, public Component { $
    Text2d *scrollDecrease = nullptr;
    Text2d *scrollIncrease = nullptr;
    Text2d *scrollBar = nullptr;
    bool isVertical;
    Line2d *scrollDecreaseLines[2];
    Line2d *scrollIncreaseLines[2];
    private$(bool scrollDrag = false)
    private$(float2 dragStart)
    private$(float2 positionStart)
    private$(float valueStart = 0)
    private$(float positionRange = 0)
    private$(float positionMinimum = 0)
    private$(float positionMaximum = 0)
    private$(float shorterSize = 0)
    private$(float longerSize = 0)
    private$(float valueRange = 0)
    private$(float scrollBarSize = 0)
    private$(List<Text2d*> scrollElements)
    constructor(ScrollBar(const ScrollBarParams& params = ScrollBarParams()))
    destructor$(ScrollBar())
    virtual void whenMouseIn();
    virtual void refresh();
    float setValue(float value);
    float setRange(float range);
    float setMinimum(float minimum);
    float setMaximum(float maximum);
    float scroll(float value, bool useSteps = true);
    float scrollMin();
    float scrollMax();
    private$(float valueFromPosition(float value))
    private$(float positionFromValue(float position))
    private$(void recalculateBasis())
})