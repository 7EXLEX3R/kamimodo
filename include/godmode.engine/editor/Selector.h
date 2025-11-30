#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/editor/TransformController.h>
#include <godmode.engine/editor/TransformToolbar.h>
#include <godmode.engine/entity/BaseEntity3d.h>
#include <godmode.engine/entity/_2d/LineRectangle.h>
#include <godmode.engine/logic/Refreshable.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/math/Plane.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.foundation/types/List.h>

godmode_engine_editor(class Selector : public Refreshable { $
    LineRectangle* selectRectangle;
    Plane selectPlanes[5];
    List<BaseEntity3d*> selectedEntities;
    List<BaseEntity3d*> highlightedEntities;
    float4 idleColor;
    float4 highlightColor;
    float4 selectColor;
    TransformController* transformController;
    TransformToolbar* transformToolbar;
    BaseEntity3d* externalPickedEntity;
    bool allowDeleteWhenGuiActive;
    constructor(Selector())
    destructor$(Selector())
    void refresh();
    private$(Camera3d* currentCamera)
    private$(float2 selectStart)
    private$(float2 selectEnd)
    private$(float2 selectGuiStart)
    private$(float2 selectGuiEnd)
    private$(bool isSelecting)
    private$(float3 dragDisplacement)
    private$(BaseEntity3d* pickedEntity)
    private$(BaseEntity3d* picking())
    private$(BaseEntity3d* externalPicking())
    private$(List<BaseEntity3d*> obtainHighlightedEntities())
    private$(void transformProcess())
    private$(void clearSelection())
    private$(void startSelecting())
    private$(void updateSelectRectangle())
    private$(void updateHighlightedEntities(List<BaseEntity3d*>& inframeHighlightedEntities))
    private$(List<BaseEntity3d*> mergeSelectedEntities(List<BaseEntity3d*>& entities))
    private$(void applySelectedEntities(List<BaseEntity3d*>& entities))
    private$(void updateSelectedEntitiesColors())
    private$(void removeSelectedItems())
})