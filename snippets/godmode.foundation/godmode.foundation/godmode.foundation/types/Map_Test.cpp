#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/types/Map.h>

test$class(Map,
    test$method(playground) {
        Map<String, String> map = {{"a","x"}};
        map["b"] = "y";
        if (!map.at("c"))
            map += Map<String, String>({{"c","z"}});
        map.removeAt("a");
        expect(map == Map<String, String>({ {"b", "y"}, {"c", "z"} }));
        expect(map.$map.size());
        expect(map.forEach([](String item, String index) {
            console->log(index + ": " + item);
        }).filter([](String item) {
            return item == "y";
        }).forEach([](String item, String index) {
            console->log(index + ": " + item);
        }).remove("y").length() == 0);
    }
    test$method(constructor) {
        test$context("default") {
            expect(Map<String, String>().length() == 0);
        }
        test$context("initializer") {
            Map<String, String> map = { {"a", "x"}, {"b", "y"}, {"c", "z"} };
            expect(*map.at("a") == "x");
            expect(*map.at("b") == "y");
            expect(*map.at("c") == "z");
            expect(map.at("d") == 0);
            expect(map.length() == 3);
        }
        test$context("json") {
            JSON json;
            json["a"] = "x";
            json["b"] = "y";
            Map<String, String> map = json.asJsonValue();
            expect(*map.at("a") == "x");
            expect(*map.at("b") == "y");
            expect(map.length() == 2);
        }
        test$context("copy") {
            Map<String, String> map = { {"a", "x"} };
            Map<String, String> copiedMap = map;
            expect(*copiedMap.at("a") == "x");
            copiedMap.removeAt("a");
            expect(map.length() == 1);
            expect(copiedMap.length() == 0);
        }
    }
    test$method(at) {
        Map<String, String> map = { {"a", "x"}, {"b", "y"}, {"c", "z"} };
        expect(*map.at("a") == "x");
        expect(*map.at("b") == "y");
        expect(*map.at("c") == "z");
        expect(map.at("d") == 0);
    }
    test$method(length) {
        Map<String, String> map = { {"a", "x"}, {"b", "y"}, {"c", "z"} };
        expect(map.length() == 3);
        map.add("d", "a");
        expect(map.length() == 4);
        map.clear();
        expect(map.length() == 0);
    }
    test$method(includes) {
        Map<String, String> map = { {"a", "x"}, {"b", "y"}, {"c", "z"} };
        expect(map.includes("x") == true);
        expect(map.includes("a") == false);
    }
    test$method(indexOf) {
        Map<String, String> map = { {"a", "x"}};
        expect(*map.indexOf("x") == "a");
        expect(map.indexOf("z") == 0);
    }
    test$method(add) {
        Map<String, String> map = { {"a", "x"} };
        expect(map.add("b", "y") == map);
        expect(*map.at("b") == "y");
        expect(*map.indexOf("y") == "b");
        map.add(Map<String, String>({{"c", "z"}, {"d", "a"}}));
        expect(map.length() == 4);
        expect(*map.at("b") == "y");
        expect(*map.at("d") == "a");
        map.add({ {"c", "999"}, {"e", "e"} });
        expect(map.length() == 5);
        expect(*map.indexOf("999") == "c");
        expect(*map.at("c") == "999");
        map.add({{ "c", "888" }}, true);
        expect(*map.at("c") == "999");
    }
    test$method(removeAt) {
        Map<String, String> map = { {"a", "x"},  {"b", "y"},  {"c", "z"} };
        expect(*map.removeAt("a") == "x");
        expect(map.removeAt("a") == nullptr);
        expect(map.length() == 2);
    }
    test$method(remove) {
        Map<String, String> map = { {"a", "x"},  {"b", "y"},  {"c", "z"} };
        expect(map.length() == 3);
        expect(map.remove("non-existing").length() == 3);
        expect(map.remove("x").length() == 2);
    }
    test$method(clear) {
        Map<String, String> map = { {"a", "x"} };
        expect(map.length() == 1);
        expect(map.at("a") != nullptr);
        map.clear();
        expect(map.length() == 0);
        expect(map.at("a") == nullptr);
    }
    test$method(forEach) {
        test$context("default") {
            String result;
            Map<String, String>({ {"a", "x"},  {"b", "y"},  {"c", "z"} }).forEach([&](String s) {
                result += s;
            });
            expect(result == "xyz");
        }
        test$context("index") {
            String result;
            Map<String, String>({ {"a", "x"},  {"b", "y"},  {"c", "z"} }).forEach([&](String s, String index) {
                result += s + index;
            });
            expect(result == "xaybzc");
        }
    }
    test$method(filter) {
        test$context("default") {
            String result;
            Map<String, String> evens = Map<String, String>({ {"a97", "x120"},  {"b", "y"},  {"c", "z"} }).filter([](String s) {
                return int(s.at(0)) % 2 == 0;
            }).forEach([&](String s) {
                result += s ;
            });
            expect(evens.length() == 2);
            expect(result == "x120z");
        }
        test$context("index") {
            String result;
            Map<String, String> evens = Map<String, String>({ {"a97", "x120"},  {"b", "y"},  {"c", "z"} }).filter([](String s, String index) {
                return int(index.at(0)) % 2 == 0;
            }).forEach([&](String s, String index) {
                result += index;
            });
            expect(evens.length() == 1);
            expect(result == "b");
        }
    }
    test$method(operator_equals) {
        Map<String, String> map = { {"a", "x"} };
        Map<String, String> otherMap = map;
        expect(map == otherMap);
        map.remove("x");
        expect(map.length() == 0);
        expect(otherMap.length() == 1);
        expect(map != otherMap);
    }
    test$method(operator_equals_equals) {
        Map<String, String> map = { {"a", "x"} };
        Map<String, String> otherMap = { {"a", "x"} };
        expect(map == otherMap);
        expect(!(map == otherMap + Map<String, String>({ {"b", "y"} })));
    }
    test$method(operator_not_equals) {
        Map<String, String> map = { {"a", "x"}, {"b", "y"} };
        Map<String, String> otherMap = { {"a", "x"} };
        expect(map != otherMap);
        expect(!(map != otherMap + Map<String, String>({ {"b", "y"} })));
    }
    test$method(operator_brackets) {
        Map<String, String> map = { {"a", "x"} };
        expect(*map.at("a") == "x");
        map["a"] = "y";
        expect(*map.at("a") == "y");
        expect(map.length() == 1);
        map["b"] = "x";
        expect(*map.at("b") == "x");
        expect(map.length() == 2);
        // TODO(2): out of range exception - exceptions in general
    }
    test$method(operator_plus_equals) {
        Map<String, String> map = { {"a", "x"} };
        expect((map += Map<String, String>({ {"b", "y"}, {"c", "z"} })).length() == 3);
        expect(map.length() == 3);
        expect((map += Map<String, String>({ {"b", "y"}, {"d", "9"} })).length() == 4);
    }
    test$method(operator_plus) {
        Map<String, String> map = { {"a", "x"} };
        expect((map + Map<String, String>({ {"b", "y"}})).length() == 2);
        expect(map.length() == 1);
    }
    test$method(serialize) {
        Map<String, String> map = { {"a", "x"} };
        Map<String, String> outputMap;
        Serializer::pipe(map, outputMap);
        expect(outputMap == map);
        expect(*outputMap.at("a") == "x");
    }
)
#endif