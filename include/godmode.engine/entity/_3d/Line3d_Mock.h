#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Line3d.h>

godmode_engine_entity__3d(class Line3dMock : public Line3d { $
    constructor(Line3dMock(const Line3dParams& params = Line3dParams()) : Line3d(params) {})
    destructor$(Line3dMock() {})
    void render() {};
    s11n$defineInline({
        ar.template register_type<Line3dMock>();
        ar &boost::serialization::base_object<Line3d>(*this);
    });
})
s11n$export(Line3dMock);