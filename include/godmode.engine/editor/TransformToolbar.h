#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/TransformAxisType.h>
#include <godmode.engine/editor/TransformType.h>
#include <godmode.engine/events/BaseEntity3dSelectEvent.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/Label.h>
#include <godmode.foundation/events/EventListener.h>

godmode_engine_editor(class TransformToolbar : public Container, public EventListener<BaseEntity3dSelectEvent> { $
    Label* position = nullptr;
    Label* rotation = nullptr;
    Label* scale = nullptr;
    Button* positionTransformations[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    Button* rotationTransformations[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    Button* scaleTransformations[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    List<BaseEntity3d*> relativeEntities;
    constructor(TransformToolbar())
    destructor$(TransformToolbar())
    void preprocess();
    void refresh();
    bool isControl();
    TransformType getControlledTransformType();
    TransformAxisType getControlledTransformAxisType();
    void handleEvent(BaseEntity3dSelectEvent* event);
    void setPositionRelativeToEntities(List<BaseEntity3d*>& entities);
})