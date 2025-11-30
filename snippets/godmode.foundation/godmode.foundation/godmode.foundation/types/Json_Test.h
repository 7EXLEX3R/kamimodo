#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/Json.h>

class JsonReturner : public JsonRepresentable { $
    int value;
    JsonReturner() : value(0) {};
    JsonReturner(int value) : value(value) {};
    JSON toJson() {
        JSON j;
        j["value"] = this->value;
        return j;
    }
    void fromJson(JSON j) { this->value = j["value"].asInt(); }
    s11n$defineInlineSplit({
        ar << String(const_cast<JsonReturner*>(this)->toJson().toString());
    }, {
        String configString;
        ar >> configString;
        this->fromJson(JSON::from(configString));
    });
};