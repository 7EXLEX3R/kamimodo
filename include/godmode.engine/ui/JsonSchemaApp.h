#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/JsonRepresentable.h>
#include <godmode.engine/ui/Component.h>
#include <godmode.engine/ui/Window.h>

godmode_engine_ui(class JsonSchemaApp : public Window { $
    JSON jsonSchema;
    JSON *model = nullptr;
    JSON internalModel;
    JsonRepresentable *jsonFormatObject = nullptr;
    List<Component *> jsonBindedComponents;
    Map<String, Component *> propertyToComponentMap;
    constructor(JsonSchemaApp(float2 &position, JSON jsonSchema, JsonRepresentable *jsonFormatObject = 0, JSON *model = 0))
    destructor$(JsonSchemaApp())
    void whenActive();
    void refresh();
    void setJsonRepresentableObjectModel(JsonRepresentable *jsonFormatObject = 0, JSON *model = 0);
    virtual JSON postprocessModel(JSON model);
    protected$(JSON modelBuffer)
    private$(Component *createNumberComponent(JSON &field, float2 &position, JSON &value, float width = 160, float height = 16))
    private$(Component *createTextComponent(JSON &field, float2 &position, JSON &value, float width = 160, float height = 16))
    private$(Component *createCheckboxComponent(JSON &field, float2 &position, JSON &value, float width = 160, float height = 16))
    private$(Component *createComboboxComponent(JSON &field, float2 &position, JSON &value, float width = 160, float height = 16))
    private$(List<String> getSortedProperties(JSON &field))
})