#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Json_$.h>

godmode_foundation_types(class JsonRepresentable { $
    virtual JSON toJson() = 0;
    virtual void fromJson(JSON json) = 0;
    s11n$defineInline({});
})
s11n$exportAbstract(JsonRepresentable);