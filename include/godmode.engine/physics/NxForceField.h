#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/physics/NxPhysicsScene3d.h>

godmode_engine_physics(class NxForceField { $
    // NxForceField* gForceField;
    // NxForceFieldShape* m_excludeShape;
    // NxForceFieldShapeGroup* m_excludeGroup;
    // NxForceFieldLinearKernel* m_linearKernel;
    constructor(NxForceField(NxPhysicsScene3d *scene))
    destructor$(NxForceField())
})