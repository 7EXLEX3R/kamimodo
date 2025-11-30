#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d.h>

godmode_engine_entity__3d(class Object3dMock : public Object3d { $
    constructor(Object3dMock(const Object3dParams& params = Object3dParams()) : Object3d(params) {})
    destructor$(Object3dMock() {})
    void render() {};
    s11n$defineInline({
        ar.template register_type<Object3dMock>();
        ar &boost::serialization::base_object<Object3d>(*this);
    });
})
s11n$export(Object3dMock);
s11n$instantiate(Object3dMock);