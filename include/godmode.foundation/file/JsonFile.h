#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_file(class JsonFile : public ContentItem { $
    static JSON loadJson(String path);
    static JSON transformSchemaToDefaultModel(JSON schema);
    constructor(JsonFile(String path))
    destructor$(JsonFile())
    bool load(String path, String name = "");
    bool save(String path = "");
    String getSource() const;
    JsonValue get(String property);
    JsonValue getRoot() const;
    void setSource(String val);
    void setRoot(Json::Value val);
    String toString();
    private$(String source)
    private$(JsonValue root)
    private$(JsonReader reader)
    private$(JsonWriter writer)
})