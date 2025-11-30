#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(struct GroupBoxParams : virtual ContainerParams {
    String title = "";
})
godmode_engine_ui_components(class GroupBox : virtual public GroupBoxParams, public Container { $
    Text2d *t2d = nullptr;
    constructor(GroupBox(const GroupBoxParams& params = GroupBoxParams()))
    destructor$(GroupBox())
})