#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/serialization/SerializerInput.h>
#include <godmode.foundation/serialization/SerializerOutput.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/types/MappedList.h>

test$class(MappedList,
    test$method(constructor) {
        test$context("default") {
            expect(MappedList<String, String>().length() == 0);
        }
        test$context("initializer") {
            MappedList<String, String> mappedList = { {"a", "x"}, {"b", "y"}, {"c", "z"} };
            expect(*mappedList.at("a") == "x");
            expect(*mappedList.at("b") == "y");
            expect(*mappedList.at("c") == "z");
            expect(mappedList.at("d") == 0);
            expect(mappedList.length() == 3);
            expect(*mappedList.at(0) == "x");
            expect(*mappedList.at(1) == "y");
            expect(*mappedList.at(2) == "z");
        }
        test$context("json") {
            JSON json;
            json["a"] = "x";
            json["b"] = "y";
            MappedList<String, String> mappedList = json.asJsonValue();
            expect(*mappedList.at("a") == "x");
            expect(*mappedList.at("b") == "y");
            expect(mappedList.length() == 2);
            expect(*mappedList.at(0) == "x");
            expect(*mappedList.at(1) == "y");
            expect(mappedList.length() == 2);
        }
        test$context("copy") {
            Map<String, String> mappedList = { {"a", "x"} };
            Map<String, String> copiedMap = mappedList;
            expect(*copiedMap.at("a") == "x");
            copiedMap.removeAt("a");
            expect(mappedList.length() == 1);
            expect(copiedMap.length() == 0);
        }
    }
    test$method(length) {
        MappedList<String, int> mappedList = { {"a", 1}, {"b", 2}, {"c", 3} };
        expect(mappedList.length() == 3);
        mappedList.unshift("z", 4);
        expect(mappedList.length() == 4);
        mappedList.clear();
        expect(mappedList.length() == 0);
    }
    test$method(mapLength) {
        MappedList<String, int> mappedList = { {"a", 1}, {"a", 2}, {"c", 3} };
        expect(mappedList.mapLength() == 2);
        expect(mappedList.length() == 3);
    }
    test$method(includes) {
        test$context("indextype == valuetype") {
            MappedList<String, String> mappedList = { {"a", "x"} };
            expect(mappedList.includes("x") == true);
            expect(mappedList.includes("a") == false);
            expect(mappedList.includes("z") == false);
        }
        test$context("indextype != valuetype") {
            MappedList<String, int> mappedListInt = { {"a", 1} };
            expect(mappedListInt.includes("a") == true);
            expect(mappedListInt.includes("x") == false);
            expect(mappedListInt.includes(1) == true);
        }
    }
    test$method(indexOf) {
        MappedList<String, String> mappedList = { {"a", "1"}, {"b", "2"} };
        expect(mappedList.indexOf("1") == 0);
        expect(mappedList.indexOf("2") == 1);
        expect(mappedList.indexOf("a") == -1);
        expect(mappedList.indexOf("b") == -1);
        expect(mappedList.indexOf("c") == -1);
    }
    test$method(mapIndexOf) {
        MappedList<String, String> mappedList = {{"a", "1"}, {"b", "2"}};
        expect(*mappedList.mapIndexOf("1") == "a");
        expect(mappedList.mapIndexOf("a") == nullptr);
        expect(mappedList.mapIndexOf("3") == nullptr);
        expect(*mappedList.mapIndexOf("2") == "b");
    }
    test$method(mapIndexBy) {
        MappedList<String, String> mappedList = { {"a", "1"}, {"b", "2"} };
        expect(*mappedList.mapIndexBy(0) == "a");
        expect(*mappedList.mapIndexBy(1) == "b");
        expect(mappedList.mapIndexBy(2) == nullptr);
    }
    test$method(at) {
        MappedList<String, String> mappedList = { {"a", "1"}, {"b", "2"} };
        test$context("list") {
            expect(*mappedList.at(0) == "1");
            expect(*mappedList.at(1) == "2");
            expect(mappedList.at(2) == nullptr);
            expect(*mappedList.at(-1) == "2");
        }
        test$context("map") {
            expect(*mappedList.at("a") == "1");
            expect(*mappedList.at("b") == "2");
            expect(mappedList.at("c") == nullptr);
        }
    }
    test$method(front) {
        MappedList<String, String> mappedList = { {"a", "1"}, {"b", "2"} };
        expect(*mappedList.front() == "1");
        MappedList<String, String> otherMappedListpedList;
        expect(otherMappedListpedList.front() == 0);
    }
    test$method(back) {
        MappedList<String, String> mappedList = { {"a", "1"}, {"b", "2"} };
        expect(*mappedList.back() == "2");
        MappedList<String, String> otherList;
        expect(otherList.back() == 0);
    }
    test$method(add) {
        test$context("index, value") {
            MappedList<String, int> mappedList;
            mappedList.add("1", 1);
            mappedList.add("2", 2);
            expect(mappedList.length() == 2);
            expect(*mappedList.at("1") == 1);
            expect(*mappedList.at(1) == 2);
            expect(*mappedList.mapIndexOf(2) == "2");
        }
        test$context("map") {
            Map<String, int> map = {{"1", 1}, {"2", 2}};
            MappedList<String, int> mappedList;
            mappedList.add(map);
            expect(mappedList.length() == 2);
            expect(*mappedList.at("1") == 1);
            expect(*mappedList.at(1) == 2);
            expect(*mappedList.mapIndexOf(2) == "2");
            expect(mappedList.clear().length() == 0);
            expect(map.length() == 2);
        }
        test$context("initializerMap") {
            MappedList<String, int> mappedList;
            mappedList.add({ {"1", 1}, {"2", 2} });
            expect(mappedList.length() == 2);
            expect(*mappedList.at("1") == 1);
            expect(*mappedList.at(1) == 2);
            expect(*mappedList.mapIndexOf(2) == "2");
            expect(mappedList.clear().length() == 0);
        }
    }
    test$method(modify) {
        test$context("primitive") {
            MappedList<String, bool> mappedList;
            mappedList.add("S", true);
            expect(*mappedList.at("S") == true);
            mappedList.modify("S", false);
            expect(*mappedList.at("S") == false);
        }
        test$context("pointer") {
            String before = "before";
            String after = "after";
            MappedList<String, String*> mappedList;
            mappedList.add("S", &before);
            mappedList.modify("S", &after);
            expect(mappedList.at("S") != &before);
            expect(mappedList.at("S") == &after);
        }
    }
    test$method(remove) {
        MappedList<String, String> mappedList = { {"a", "1"} , {"b", "2"} , {"c", "3"} };
        mappedList.remove("1");
        expect(mappedList.length() == 2);
        expect(mappedList.mapLength() == 2);
        expect(mappedList.at("a") == nullptr);
        expect(*mappedList.at(0) == "2");
        expect(*mappedList.at(1) == "3");
        expect(mappedList.at(2) == nullptr);
    }
    test$method(removeBy) {
        MappedList<String, String> mappedList = { {"a", "1"} , {"b", "2"} , {"c", "3"} };
        mappedList.removeBy(0);
        expect(mappedList.length() == 2);
        expect(mappedList.mapLength() == 2);
        expect(mappedList.at("a") == nullptr);
        expect(*mappedList.at(0) == "2");
        expect(*mappedList.at(1) == "3");
        expect(mappedList.at(2) == nullptr);
    }
    test$method(removeAt) {
        MappedList<String, String> mappedList = { {"a", "1"} , {"b", "2"} , {"c", "3"} };
        mappedList.removeAt("a");
        expect(mappedList.length() == 2);
        expect(mappedList.mapLength() == 2);
        expect(mappedList.at("a") == nullptr);
        expect(*mappedList.at(0) == "2");
        expect(*mappedList.at(1) == "3");
        expect(mappedList.at(2) == nullptr);
    }
    test$method(clear) {
        MappedList<String, String> mappedList = { {"a", "1"} , {"b", "2"} , {"c", "3"} };
        mappedList.clear();
        expect(mappedList.length() == 0);
        expect(mappedList.mapLength() == 0);
    }
    test$method(operator_equals) {
        MappedList<String, String> mappedList = { {"a", "x"} };
        MappedList<String, String> otherMappedList = mappedList;
        expect(mappedList == otherMappedList);
        mappedList.remove("x");
        expect(mappedList.length() == 0);
        expect(otherMappedList.length() == 1);
        expect(mappedList != otherMappedList);
    }
    test$method(operator_equals_equals) {
        MappedList<String, String> mappedList = { {"a", "x"} };
        MappedList<String, String> otherMappedList = { {"a", "x"} };
        expect(mappedList == otherMappedList);
        expect(!(mappedList == otherMappedList + MappedList<String, String>({ {"b", "y"} })));
    }
    test$method(operator_not_equals) {
        MappedList<String, String> mappedList = { {"a", "x"}, {"b", "y"} };
        MappedList<String, String> otherMappedList = { {"a", "x"} };
        expect(mappedList != otherMappedList);
        expect(!(mappedList != otherMappedList + MappedList<String, String>({ {"b", "y"} })));
    }
    test$method(operator_brackets) {
        //
    }
    test$method(operator_plus_equals) {
        MappedList<String, String> mappedList = { {"a", "x"} };
        expect((mappedList += MappedList<String, String>({ {"b", "y"}, {"c", "z"} })).length() == 3);
        expect(mappedList.length() == 3);
        mappedList += MappedList<String, String>({ {"b", "y"}, {"d", "9"} });
        expect(mappedList.length() == 5);
        expect(mappedList.mapLength() == 4);
    }
    test$method(operator_plus) {
        MappedList<String, String> mappedList = { {"a", "x"} };
        expect((mappedList + MappedList<String, String>({ {"b", "y"} })).length() == 2);
        expect(mappedList.length() == 1);
    }
    test$method(serialize) {
        test$context("primitive") {
            MappedList<String, int> mappedList;
            mappedList.add("a", 5);
            MappedList<String, int> deserialized;
            Serializer::pipe(mappedList, deserialized);
            expect(*deserialized.at("a") == 5);
            expect(*deserialized.at(0) == 5);
            expect(*deserialized.mapIndexOf(5) == "a");
        }
        test$context("pointer") {

        }
    }
)
#endif