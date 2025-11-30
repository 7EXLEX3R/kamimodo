#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Json_$.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/StringRepresentable.h>
#include <godmode.foundation/types/JsonRepresentable.h>

godmode_foundation_types(class JSON : public StringRepresentable { $
    static const JsonValue null;
    JsonValue $json;
    constructor(JSON())
    constructor(JSON(const JSON& json))
    constructor(JSON(JsonValue value))
    constructor(JSON(JsonValueType type))
    constructor(JSON(String string))
    constructor(JSON(const char* string))
    JSON get(String path, const JsonValue defaultValue = JSON::null);
    JSON get(String path, const String defaultValue);
    template<typename T>
    JSON get(String path, const T& defaultValue) {
        return StringTraits::isStringLike<T>::value
            ? this->get(path, String(defaultValue))
            : this->get(path, JsonValue(defaultValue));
    }
    JSON set(String path, const JsonValue value);
    static JSON from(String string);
    static JSON merge(JSON& target, const JSON& source);
    static JsonValue merge(JsonValue& target, const JsonValue& source);
    bool isString();
    String asString();
    List<String> asStringList();
    bool isBoolean();
    bool asBoolean();
    List<bool> asBooleanList();
    bool isInteger();
    int asInteger();
    List<int> asIntegerList();
    bool isDecimal();
    double asDecimal();
    List<double> asDecimalList();
    bool isList();
    bool isObject();
    template <class JsonRepresentableType>
    List<JsonRepresentableType*> asObjectList() {
        return List<JsonRepresentableType*>::generate(this->$json.size(), [&](int i) {
            JsonRepresentableType* object = new JsonRepresentableType();
            object->fromJson(JSON(this->$json[i]));
            return object;
        });
    }
    bool isMember(String name);
    String toString();
    void fromString(String string);
    JsonValue asJsonValue() const;
    JSON operator=(const JSON& json);
    JSON operator=(JsonValue value);
    JSON operator=(JsonValueType type);
    JsonValue& operator[](String index);
    JsonValue& operator[](int index);
    bool operator==(const JsonValue& right);
    bool operator==(const JSON& right);
    friend bool operator==(const JSON& left, const JSON& right);
    bool operator!=(const JsonValue& right);
    bool operator!=(const JSON& right);
    friend bool operator!=(const JSON& left, const JSON& right);
})