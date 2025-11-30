#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/physx.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/math/float3.h>
#include <godmode.engine/math/float4.h>

godmode_engine_physics(template<class T = unsigned short> PxTriangleMesh* createBV33TriangleMesh(
    PxU32 numVertices,
    const v3* vertices,
    PxU32 numTriangles,
    const T* indices,
    bool skipMeshCleanup,
    bool skipEdgeData,
    bool inserted,
    bool cookingPerformance,
    bool meshSizePerfTradeoff))
godmode_engine_physics(PxConvexMesh* createConvexMesh(
    PxU32 numVerts,
    const v3* verts,
    PxConvexMeshCookingType::Enum convexMeshCookingType,
    bool directInsertion,
    PxU32 gaussMapLimit))