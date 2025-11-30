#pragma once
#include <godmode.engine/$_namespaces.h>

//   レ  ク  サ  ー

#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/BaseEntity2d.h>
#include <godmode.engine/logic/LogicEntity2d.h>
#include <godmode.engine/logic/_2d/Scene2d.h>

godmode_engine_ui(struct ComponentParams : virtual LogicEntity2dParams {})
#define ComponentParams_$(params) ComponentParams(params), LogicEntity2dParams_$(params)
godmode_engine_ui(class Component : virtual public ComponentParams, public LogicEntity2d { $
    Component *parent = nullptr;
    Scene2d *relativeScene = nullptr;
    List<BaseEntity2d *> entities;
    List<BaseEntity2d *> visibilityControlExcludedEntities;
    bool eventable = true;
    bool active = false;
    bool mouseEnter = false;
    bool mouseLeave = false;
    bool mouseIn = false;
    bool mouseOut = true;
    bool clicked = false;
    bool clickedOut = false;
    bool secondaryClicked = false;
    bool secondaryClickedOut = false;
    bool doubleClicked = false;
    bool pushed = false;
    bool dragStart = false;
    bool drag = false;
    bool dragEnd = false;
    int tabIndex = -1;
    bool hasValueChanged = false;
    bool activeWhenInvisible = false;
    LogicEntity2d *originEntity = nullptr;
    LogicEntity2d *scrollEntity = nullptr;
    bool isContainer = false;
    JsonValue *jsonValueBinding = nullptr;
    bool valueable = true;
    protected$(bool visible = true)
    protected$(bool enabled = true)
    private$(double doubleClickCooldown = 0)
    constructor(Component(const ComponentParams& params = ComponentParams()))
    destructor$(Component())
    void updateComponent();
    virtual void updateComponents();
    virtual void preprocess();
    virtual void refresh();
    virtual void onMouseEnter();
    virtual void whenMouseIn();
    virtual void onMouseLeave();
    virtual void whenMouseOut();
    virtual void onClick();
    virtual void onDoubleClick();
    virtual void whenPushed();
    virtual void whenActive();
    virtual void whenInactive();
    virtual void onActivate();
    virtual void onInactivate();
    virtual void onDragStart();
    virtual void whenDrag(float2 &move);
    virtual void onDragEnd();
    virtual void setVisible(bool visible);
    virtual void setEnabled(bool enabled);
    virtual void setActive(bool active = true);
    bool getVisible();
    bool getEnabled();
    virtual void applyJsonValueBindingToValue();
    virtual void attachTo(Scene2d *relativeScene = 0);
    virtual void detachFrom(Scene2d *relativeScene = 0);
    virtual List<BaseEntity2d *> getEntities();
})