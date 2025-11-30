#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Line2dFixed.h>

godmode_engine_entity__2d(class Line2dFixedMock : public Line2dFixed { $
    using Line2dFixed::Line2dFixed;
    void render() {};
    s11n$defineInline({
        ar.template register_type<Line2dFixedMock>();
        ar& boost::serialization::base_object<Line2dFixed>(*this);
    });
})
s11n$export(Line2dFixedMock);