#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/types/List.h>

test$class(List,
    test$method(playground) {
        List<String> list = {"ab", "bc", "cd"};
        JSON json;
        json["array"] = Json::Value(Json::arrayValue);
        json["array"].append("def");
        json["array"].append("efg");
        json["array"].append("fgh");
        List<String> otherList = json["array"];
        List<String> listCopy = list;
        List<String> listSum = list + otherList;
        List<int> listF = list.map<int>([](String a) {
           return int(a.at(0));
        });
        list.forEach([](String element, int index) { console->log("list - " + String::from(index) + ": " + element); });
        otherList.forEach([](String element) { console->log("otherList - " + element); });
        listSum.forEach([](String element) { console->log("listSum - int(element.at(0)) - " + String::from(int(element.at(0)))); });
        int reducedList = listSum.reduce<int>([](int a, String element) {
            return a + int(element.at(0));
        }, 0);
        console->log("reducedList - listSum(string) - " + String::from(reducedList));
        listF.forEach([](int element) { console->log("listF(int) - " + String::from(element)); });
        list.filter([](String element) {
            return element.includes("b");
        }).forEach([](String element) { console->log("list filtered (includes('b')) - " + element); });
        List<String> strings = { "a", "b", "c", "d" };
        console->log(String::from(strings.length()));
        if (strings.at(3)) {
            console->log(*strings.at(3));
        }
    }
    test$method(constructor) {
        test$context("default") {
            expect(List<String>().length() == 0);
        }
        test$context("initializer") {
            List<String> list = { "a", "b", "c" };
            expect(*list.at(0) == "a");
            expect(*list.at(1) == "b");
            expect(*list.at(2) == "c");
            expect(list.at(3) == 0);
        }
        test$context("json") {
            JSON json;
            json["array"] = Json::Value(Json::arrayValue);
            json["array"].append("d");
            json["array"].append("e");
            json["array"].append("f");
            List<String> list = json["array"];
            expect(*list.at(0) == "d");
            expect(*list.at(1) == "e");
            expect(*list.at(2) == "f");
        }
        test$context("copy") {
            List<String> list = {"a"};
            List<String> copiedList = list;
            expect(*copiedList.at(0) == "a");
            copiedList.pop();
            expect(list.length() == 1);
            expect(copiedList.length() == 0);
        }
    }
    test$method(at) {
        List<String> list = { "a", "b", "c" };
        test$context("default") {
            expect(*list.at(0) == "a");
            expect(list.at(4) == 0);
        }
        test$context("negative") {
            expect(*list.at(-1) == "c");
            expect(*list.at(-2) == "b");
            expect(*list.at(-3) == "a");
            expect(list.at(-4) == 0);
        }
    }
    test$method(front) {
        List<String> list = { "a", "b", "c" };
        expect(*list.front() == "a");
        List<String> otherList;
        expect(otherList.front() == 0);
    }
    test$method(back) {
        List<String> list = { "a", "b", "c" };
        expect(*list.back() == "c");
        List<String> otherList;
        expect(otherList.back() == 0);
    }
    test$method(length) {
        List<String> list = { "a", "b", "c" };
        expect(list.length() == 3);
        list.unshift("z");
        expect(list.length() == 4);
        list.clear();
        expect(list.length() == 0);
    }
    test$method(includes) {
        List<String> list = { "a", "b", "c" };
        expect(list.includes("a") == true);
        expect(list.includes("z") == false);
    }
    test$method(indexOf) {
        List<String> list = { "a", "b", "c" };
        expect(list.indexOf("a") == 0);
        expect(list.indexOf("z") == -1);
    }
    test$method(add) {
        List<String> list = { "a", "b", "c" };
        expect(list.add("d") == list);
        expect(*list.at(3) == "d");
        list.add({ "g", "h" });
        expect(*list.back() == "h");
        expect(list.length() == 6);
        expect(list.add(list).length() == 12);
    }
    test$method(insert) {
        List<String> list = { "a", "c" };
        expect(list.insert("b", 1) == list);
        expect(*list.at(1) == "b");
        expect(*list.at(2) == "c");
        list.insert({ "g", "h" }, 1);
        expect(*list.at(1) == "g");
        expect(*list.at(2) == "h");
        expect(list.length() == 5);
    }
    test$method(unshift) {
        List<int> list = { 2, 4 };
        expect(list.unshift(1) == list);
        expect(*list.at(0) == 1);
        expect(*list.at(2) == 4);
        list.unshift(List<int>({ 16, 8 }));
        expect(*list.at(0) == 16);
        expect(*list.at(1) == 8);
        expect(list.length() == 5);
    }
    test$method(shift) {
        List<String> list = { "1", "2", "3" };
        String* first = list.shift();
        expect(*first == "1");
        expect(list.length() == 2);
        expect(*list.at(0) == "2");
    }
    test$method(pop) {
        List<String> list = { "1", "2", "3" };
        String* last = list.pop();
        expect(*last == "3");
        expect(list.length() == 2);
        expect(*list.at(0) == "1");
        expect(*list.at(1) == "2");
    }
    test$method(removeAt) {
        List<String> list = { "a", "b", "c", "d" };
        String* removed = list.removeAt(1);
        expect(*removed == "b");
        expect(list.length() == 3);
        expect(*list.at(0) == "a");
        expect(*list.at(1) == "c");
    }
    test$method(remove) {
        List<String> list = { "apple", "banana", "cherry" };
        list.remove("banana");
        expect(list.length() == 2);
        expect(list.indexOf("banana") == -1);
        String* cherry = list.at(1);
        list.remove(cherry);
        expect(list.length() == 1);
        expect(list.indexOf("cherry") == -1);
    }
    test$method(clear) {
        List<String> list = { "x", "y", "z" };
        list.clear();
        expect(list.length() == 0);
    }
    test$method(find) {
        List<String> list = { "apple", "banana", "apricot", "avocado" };
        String* firstA = list.find([](String s) {
            return s[0] == 'a';
            });
        expect(*firstA == "apple");
    }
    test$method(findLast) {
        List<String> list = { "apple", "banana", "apricot", "avocado" };
        String* lastA = list.findLast([](String s) {
            return s[0] == 'a';
        });
        expect(*lastA == "avocado");
    }
    test$method(sort) {
        List<int> list = { 5, 1, 4, 3 };
        list.sort();
        expect(*list.at(0) == 1);
        expect(*list.at(3) == 5);
        list.clear().add({ 5, 1, 4, 3 });
        list.sort([](int a, int b) { return a > b; });
        expect(*list.at(0) == 5);
        expect(*list.at(3) == 1);
    }
    test$method(forEach) {
        test$context("default") {
            String result;
            List<String>({ "a", "b", "c" }).forEach([&](String s) {
                result += s;
            });
            expect(result == "abc");
        }
        test$context("index") {
            String result;
            List<String>({ "a", "b", "c" }).forEach([&](String s, int index) {
                result += s + String::from(index);
            });
            expect(result == "a0b1c2");
        }
    }
    test$method(filter) {
        test$context("default") {
            List<int> evens = List<int>({ 1, 2, 3, 4, 5 }).filter([](int n) { return n % 2 == 0; });
            expect(evens.length() == 2);
            expect(*evens.at(0) == 2);
            expect(*evens.at(1) == 4);
        }
        test$context("index") {
            List<int> evenIndices = List<int>({ 1, 2, 3, 4, 5 }).filter([](int n, int index) { return index % 2 == 0; });
            expect(evenIndices.length() == 3);
            expect(*evenIndices.at(0) == 1);
            expect(*evenIndices.at(1) == 3);
            expect(*evenIndices.at(2) == 5);
        }
    }
    test$method(map) {
        List<int> lengths = List<String>({ "a", "bc", "defg" }).map<int>([](String s) {
            return s.length();
        });
        expect(*lengths.at(0) == 1);
        expect(*lengths.at(1) == 2);
        expect(*lengths.at(2) == 4);
    }
    test$method(reduce) {
        test$context("default") {
            expect(List<int>({ 1, 2, 3, 4 }).reduce<int>([](int acc, int val) {
                return acc + val;
            }, 0) == 10);
        }
        test$context("index") {
            expect(List<int>({ 1, 2, 3, 4 }).reduce<int>([](int acc, int val, int index) {
                return acc + val + index;
            }, 0) == 16);
        }
    }
    test$method(join) {
        expect(List<String>({ "a", "b", "c" }).join() == "abc");
        expect(List<String>({ "a", "b", "c" }).join("-") == "a-b-c");
        expect(List<String>({ "x" }).join() == "x");
        expect(List<String>().join() == "");
    }
    test$method(slice) {
        List<int> list = { 1, 2, 3, 4, 5 };
        auto mid = list.slice(1, 4);
        expect(mid.length() == 3);
        expect(*mid.at(0) == 2);
        expect(*mid.at(2) == 4);
        auto tail = list.slice(-2);
        expect(tail.length() == 2);
        expect(*tail.at(0) == 4);
        expect(*tail.at(1) == 5);
        auto empty = list.slice(3, 2);
        expect(empty.length() == 0);
    }
    test$method(operator_equals) {
        List<String> list = { "a", "b" };
        List<String> otherList = list;
        expect(list == otherList);
        list.pop();
        expect(list.length() == 1);
        expect(otherList.length() == 2);
        expect(list != otherList);
    }
    test$method(operator_equals_equals) {
        List<String> list = { "a" };
        List<String> otherList = { "a"};
        expect(list == otherList);
        expect(!(list == otherList + List<String>({ "b" })));
        }
    test$method(operator_not_equals) {
        List<String> list = { "a", "b" };
        List<String> otherList = { "a" };
        expect(list != otherList);
        expect(!(list != otherList + List<String>({"b"})));
    }
    test$method(operator_brackets) {
        List<String> list = { "a", "b", "c" };
        list[1] = "d";
        expect(list.join() == "adc");
        // TODO(2): out of range exception - exceptions in general
    }
    test$method(operator_plus_equals) {
        List<String> list = { "a", "b", "c" };
        expect((list += List<String>({ "d" })).length() == 4);
        expect(list.length() == 4);
    }
    test$method(operator_plus) {
        List<String> list = { "a", "b", "c" };
        expect((list + List<String>({"d"})).length() == 4);
        expect(list.length() == 3);
    }
    test$method(serialize) {
        List<String> list = { "a", "b", "c" };
        List<String> outputList;
        Serializer::pipe(list, outputList);
        expect(outputList == list);
        expect(*outputList.at(2) == "c");
    }
)
#endif