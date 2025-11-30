#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/logic/LogicEntity2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/Component.h>
#include <godmode.engine/ui/components/ScrollBar.h>


godmode_engine_ui_components(struct ContainerParams : virtual ComponentParams {})
#define ContainerParams_$(params) ContainerParams(params), ComponentParams_$(params)
godmode_engine_ui_components(class Container : virtual public ContainerParams, public Component { $
    List<Component *> components;
    LogicEntity2d *containerOriginEntity = nullptr;
    ScrollBar *verticalScroll = nullptr;
    ScrollBar *horizontalScroll = nullptr;
    float scrollingSpeed = 1;
    bool tabable = false;
    constructor(Container(const ContainerParams& params = ContainerParams()))
    destructor$(Container())
    Component *addComponent(Component *component);
    Component *removeComponent(Component *component, bool _delete = true);
    void updateComponents();
    virtual void onMouseEnter() {};
    virtual void whenMouseIn() {};
    virtual void onMouseLeave() {};
    virtual void whenMouseOut() {};
    virtual void onClick() {};
    virtual void onDoubleClick() {};
    virtual void whenPushed() {};
    virtual void onActivate();
    virtual void onInactivate();
    virtual void setVisible(bool visible);
    virtual void setEnabled(bool enabled);
    void initScrolls(float height = 0, float width = 0);
    virtual List<BaseEntity2d *> getEntities();
})