#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serializer.h>
#include <godmode.foundation/types/JSON.h>
#include "JSON_Test.h"

test$class(JSON,
    test$method(playground) {
        JSON j;
        expect(j == JSON::null);
        j["array"] = JsonValueType::arrayValue;
        expect(j != JSON::null);
        j["array"].append(1);
        console->log(String(j.toString()).replaceAll(" ").replaceAll("\n"));
        expect(String(j.toString()).replaceAll(" ").replaceAll("\n") == R"({"array":[1]})");
        JSON j2 = j;
        expect(j == j2);
        j2["array"].append(2);
        expect(j["array"].size() == 1);
        expect(j2["array"].size() == 2);
        j2["object"]["object-level2"]["int"] = 3;
        expect(j2["object"]["object-level2"].type() == JsonValueType::objectValue);
        expect(j2["object"]["object-level2"]["int"] == 3);
        j.set("object.object-level2.int2", 5);
        JSON merged = JSON::merge(j2, j);
        expect(merged["array"].size() == 1);
        expect(merged["object"]["object-level2"]["int"] == 3);
        console->log(merged);
        expect(merged.get("object.object-level2.int2", 0) == 5);
        expect(JSON::from(R"({"int":4})").get("int", 0) == 4);
    }
    test$method(constructor) {
        JSON a(R"({
            "a": 1,
            "object": {
                "b": 3.0
            },
            "intArray": [1, 2, 3],
            "stringArray": ["a", "b", "c"]
        })");
        JSON b;
        b = a;
        a["a"] = 2;
        expect(a["a"] == 2);
        expect(b["a"] == 1);
        JSON c = b["object"];
        expect(c["b"] == 3.0);
    }
    test$method(get) {
        test$context("object") {
            JSON a(R"({
                "object": {
                    "b": 3,
                    "c": "string"
                }
            })");
            expect(a.get("object.b") == 3);
            expect(a.get("object.c").asString() == "string");
            expect(a.get("object.d") == JSON::null);
            String e = a.get("object.e", "abc"); // FIXME: a.get("object.e", "abc") == "abc"
            expect(e == "abc");
        }
        test$context("array") {
            expect(JSON::from(R"({"a":[{"a": 1}, {"a": 2}]})").get("a[0].a") == 1);
        }
    }
    test$method(set) {
        test$context("object") {
            JSON a(R"({})");
            a.set("object", JSON(R"({
                "object": {
                    "b": 3,
                    "c": 5
                }
            })").asJsonValue());
            expect(a.get("object.object.b") == 3);
            a.set("object.object.b", 7);
            expect(a.get("object.object.b") == 7);
            expect(a.get("object.object.c") == 5);
        }
        test$context("array") {
            JSON a;
            a.set("a[1]", 5);
            console->log(a);
            expect(a.get("a[0]") == JSON::null);
            expect(a.get("a[1]") == 5);
            a.set("a[0]", 3);
            a.set("a[2]", 7);
            expect(a.get("a[0]") == 3);
            expect(a.get("a[1]") == 5);
            expect(a.get("a[2]") == 7);
            a.set("a[1]", JSON(R"({
                "object": {
                    "b": 3,
                    "c": 5
                }
            })").asJsonValue());
            expect(a.get("a[0]") == 3);
            expect(a.get("a[1].object.c") == 5);
            expect(a.get("a[2]") == 7);
        }
    }
    test$method(from) {
        expect(JSON::from(R"({"a":1})").get("a") == 1);
    }
    test$method(merge) { // FIXME: merge not working the best
       JSON a(R"({
           "a": 1,
           "object": {
               "b": 4.0,
               "c": 2.0
           },
           "intArray": [1, 2, 3],
           "stringArray": ["a", "b", "c"]
       })");
       JSON b(R"({
           "a": 2,
           "object": {
               "b": 3.0
           },
           "intArray": [4, 5, 6],
           "stringArray2": ["a", "b", "c"]
       })");
       console->log(a);
       console->log(b);
       JSON c = JSON::merge(a, b);
       expect(c.get("a") == 2);
       expect(c.get("object.b") == 3.0);
       expect(c.get("object.c") == 2.0);
       expect(c.get("intArray").asIntegerList() == List<int>({4,5,6}));
       expect(c.get("stringArray").asStringList() == List<String>({"a", "b", "c"}));
       expect(c.get("stringArray2").asStringList() == List<String>({"a", "b", "c"}));
       console->log(c);
    }
    test$method(isString) {
        expect(JSON::from(R"({"a":1})").get("a").isString() == false);
        expect(JSON::from(R"({"a":"abc"})").get("a").isString() == true);
        expect(JSON(JSON::null).isString() == false);
    }
    test$method(asString) {
        expect(JSON::from(R"({"a":"abc"})").get("a").asString() == "abc");
    }
    test$method(asStringList) {
        expect(JSON::from(R"({"a":["a", "b", "c"]})").get("a").asStringList() == List<String>({"a", "b", "c"}));
    }
    test$method(isBoolean) {
        expect(JSON::from(R"({"a":1})").get("a").isBoolean() == false);
        expect(JSON::from(R"({"a":true})").get("a").isBoolean() == true);
        expect(JSON(JSON::null).isBoolean() == false);
    }
    test$method(asBoolean) {
        expect(JSON::from(R"({"a":true})").get("a").asBoolean() == true);
        expect(JSON::from(R"({"a":false})").get("a").asBoolean() == false);
    }
    test$method(asBooleanList) {
        expect(JSON::from(R"({"a":[true, false]})").get("a").asBooleanList() == List<bool>({true, false}));
    }
    test$method(isInteger) {
        expect(JSON::from(R"({"a":"1"})").get("a").isInteger() == false);
        expect(JSON::from(R"({"a":1})").get("a").isInteger() == true);
        expect(JSON(JSON::null).isInteger() == false);
    }
    test$method(asInteger) {
        expect(JSON::from(R"({"a":1})").get("a").asInteger() == 1);
    }
    test$method(asIntegerList) {
        expect(JSON::from(R"({"a":[1, 2]})").get("a").asIntegerList() == List<int>({1, 2}));
    }
    test$method(isDecimal) {
        expect(JSON::from(R"({"a":1.0})").get("a").isDecimal() == true);
        expect(JSON::from(R"({"a":1})").get("a").isDecimal() == false);
        expect(JSON::from(R"({"a":"1.0"})").get("a").isDecimal() == false);
        expect(JSON(JSON::null).isDecimal() == false);
    }
    test$method(asDecimal) {
        expect(JSON::from(R"({"a":1.5})").get("a").asDecimal() == 1.5);
    }
    test$method(asDecimalList) {
        expect(JSON::from(R"({"a":[1.1, 2.2]})").get("a").asDecimalList() == List<double>({1.1, 2.2}));
    }
    test$method(isList) {
        expect(JSON::from(R"({"a":[1.1, 2.2]})").get("a").isList() == true);
        expect(JSON::from(R"({"a":"string"})").get("a").isList() == false);
        expect(JSON(JSON::null).isList() == false);
    }
    test$method(isObject) {
        expect(JSON::from(R"({"a":[{"a": 1}, {"a": 2}]})").get("a[0]").isObject() == true);
        expect(JSON::from(R"({"a":[{"a": 1}, {"a": 2}]})").get("a").isObject() == false);
        expect(JSON(JSON::null).isObject() == false);
    }
    test$method(asObjectList) {
        List<JsonReturner*> list = JSON::from(R"({"a":[{"value": 1}, {"value": 2}]})").get("a").asObjectList<JsonReturner>();
        expect(list[0]->value == 1);
        expect(list[1]->value == 2);
        list.clear(true);
    }
    test$method(isMember) {
        expect(JSON::from(R"({"a":1)").isMember("a") == true);
        expect(JSON::from(R"({"a":1})").isMember("b") == false);
    }
    test$method(toString) {
        String a = "{\n   \"a\" : 1\n}\n";
        String b = JSON::from(R"({"a":1})").toString();
        expect(a == b);
    }
    test$method(fromString) {
        JSON a;
        a.fromString(R"({"a":1})");
        expect(a.get("a") == 1);
    }
    test$method(asJsonValue) {
        expect(JSON::from(R"({"a":1})").asJsonValue() != JSON::null);
    }
    test$method(serialize) {
        JsonReturner *jr = new JsonReturner(4);
        JsonReturner *jr2;
        Serializer::pipe(jr, jr2);
        expect(jr2->value == jr->value);
        delete jr;
        delete jr2;
    }
)
#endif