#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>

test$class(String,
    test$method(constructor) {
        String otherString = "string";
        const char* constChar = "string";
        std::string stdString = "string";
        char _char = 's';
        expect(String(otherString) == "string");
        expect(String(constChar) == "string");
        expect(String(stdString) == "string");
        expect(String(_char) == "s");
    }
    test$method(length) {
        expect(String("").length() == 0);
        expect(String("abc").length() == 3);
    }
    test$method(includes) {
        expect(String("abcd").includes("ab"));
        expect(String("abcd").includes("abcd"));
        expect(String("abcd").includes("abd") == false);
    }
    test$method(indexOf) {
        expect(String("Blue Whale").indexOf("Blue") ==  0);
        expect(String("Blue Whale").indexOf("Wale") == -1);
        expect(String("Blue Whale").indexOf("Whale", 0) ==  5);
        expect(String("Blue Whale").indexOf("Whale", 5) ==  5);
        expect(String("Blue Whale").indexOf("Whale", 7) == -1);
        expect(String("Blue Whale").indexOf("") ==  0);
        expect(String("Blue Whale").indexOf("", 9) ==  9);
        expect(String("Blue Whale").indexOf("", 10) == 10);
        expect(String("Blue Whale").indexOf("", 11) == 10);
    }
    test$method(lastIndexOf) {
        expect(String("canal").lastIndexOf("a") == 3);
        expect(String("canal").lastIndexOf("a", 2) == 1);
        expect(String("canal").lastIndexOf("a", 0) == -1);
        expect(String("canal").lastIndexOf("x") == -1);
        expect(String("canal").lastIndexOf("c", -5) == 0);
        expect(String("canal").lastIndexOf("c", 0) == 0);
        expect(String("canal").lastIndexOf("") == 5);
        expect(String("canal").lastIndexOf("", 2) == 2);
    }
    test$method(at) {
        expect(String("abc").at(0) == 'a');
        expect(String("abc").at(2) == 'c');
        expect(String("abc").at(3) == char(0));
        expect(String("abc").at(-1) == 'c');
        expect(String("abc").at(-4) == char(0));
    }
    test$method(startsWith) {
        expect(String("abcd").startsWith("abc") == true);
        expect(String("abcd").startsWith("bc") == false);
    }
    test$method(endsWith) {
        expect(String("abcd").endsWith("cd") == true);
        expect(String("abcd").endsWith("bc") == false);
    }
    test$method(count) {
        expect(String("ab/cd/ef/gh").count("/") == 3);
        expect(String("ab/cd/ef//gh").count("/") == 4);
        expect(String("...").count(".") == 3);
        expect(String("...").count(".", 1) == 2);
        expect(String("...").count("2") == 0);
        expect(String("...").count("..") == 1);
    }
    test$method(upper) {
        expect(String(".aBcD").upper() == ".ABCD");
    }
    test$method(lower) {
        expect(String(".aBcD").lower() == ".abcd");
    }
    test$method(trim) {
        expect(String("..aa.x.").trim(".") == "aa.x");
    }
    test$method(trimStart) {
        expect(String("  a ").trimStart() == "a ");
    }
    test$method(trimEnd) {
        expect(String("  a ").trimEnd() == "  a");
    }
    test$method(replace) {
        expect(String("ababa").replace("ba", "dz") == "adzba");
    }
    test$method(replaceLast) {
        expect(String("ababa").replaceLast("ba", "dz") == "abadz");
    }
    test$method(replaceAll) {
        expect(String("ababa").replaceAll("ba", "dz") == "adzdz");
        expect(String("ababa").replaceAll("a", "dz") == "dzbdzbdz");
        expect(String("     a   ;").replaceAll("  ", " ") == " a ;");
    }
    test$method(substring) {
        test$context("index") {
            expect(String("abcd").substring(0, 3) == "abc");
            expect(String("abcd").substring(0) == "abcd");
            expect(String("abcd").substring(1) == "bcd");
            expect(String("abcd").substring(0, 3, true) == "abcd");
            expect(String("abcd").substring(1, 1) == "");
            expect(String("abcd").substring(1, 1, true) == "b");
        }
        test$context("string") {
            expect(String("abcd").substring("a", "d", true) == "abcd");
            expect(String("abcd").substring("a", "cd", false) == "b");
            expect(String("abcd").substring("ab", "", true) == "abcd");
            expect(String("abcd").substring("b", "", false) == "cd");
            expect(String("a'bc'd").substring("'", "'", false) == "bc");
            expect(String("./path/to/content.jpg").substring("/") == "path/to/content.jpg");
            expect(String("./path/to/content.jpg").substring("/", ".") == "path/to/content");
            expect(String("./path/to/content.jpg").substring("/", ".", true) == "/path/to/content.");
        }
    }
    test$method(substringLast) {
        expect(String("./path/to/content.jpg").substringLast("/") == "content.jpg");
        expect(String("./path/to/content.jpg").substringLast("/", ".") == "content");
        expect(String("./path/to/content.jpg").substringLast("/", ".", true) == "/content.");
    }
    test$method(substringTo) {
        expect(String("./path/to/content.jpg").substringTo("/") == ".");
        expect(String("./path/to/content.jpg").substringTo(".") == "");
        expect(String("./path/to/content.jpg").substringTo("/", true) == "./");
    }
    test$method(substringToLast) {
        expect(String("./path/to/content.jpg").substringToLast("/") == "./path/to");
        expect(String("./path/to/content.jpg").substringToLast(".") == "./path/to/content");
        expect(String("./path/to/content.jpg").substringToLast("/", true) == "./path/to/");
    }
    test$method(split) {
        expect(String("").split(".").length() == 1);
        expect(String("").split("").length() == 0);
        expect(String("aba").split("b").length() == 2);
        expect(String(".a.").split(".")[0] == "" && String(".a.").split(".")[2] == "");
        expect(String(".b.").split(".").length() == 3);
        expect(String("a.b.").split(".").length() == 3);
        expect(String("a.b.c").split(".").length() == 3);
        expect(String("a").split("a").length() == 2);
        List<String> split = String("2/2").split("/");
        expect(split[0] == "2" && split[1] == "2");
        List<String> splitString = String("a").split("a");
        expect(splitString[0] == "" && splitString[1] == "");
    }
    test$method(assignFrom) {
        expect(String().assignFrom<bool>(true) == "true");
    }
    test$method(from) {
        expect(String::to<float>(".9f") == 0.9f);
        expect(String::to<double>(".9") == 0.9);
        expect(String::to<int>("9") == 9);
        expect(String::to<bool>("true") == true);
    }
    test$method(to) {
        expect(String::to<float>(".9f") == 0.9f);
        expect(String::to<double>(".9") == 0.9);
        expect(String::to<int>("9") == 9);
        expect(String::to<bool>("false") == false);
    }
    test$method(isTruthy) {
        expect(!String("").isTruthy());
        expect(!String("0").isTruthy());
        expect(!String("false").isTruthy());
        expect(String("any other string").isTruthy());
        expect(String("true").isTruthy());
        expect(String("1").isTruthy());
    }
    test$method(isNumber) {
        expect(String("").isNumber<int>() == false);
        expect(String::isNumber<int>("0") == true);
        expect(String::isNumber<int>("false") == false);
        expect(String::isNumber<int>("any other") == false);
        expect(String::isNumber<int>("true") == false);
        expect(String::isNumber<int>("1") == true);
        expect(String::isNumber<float>("3.14") == true);
        expect(String::isNumber<float>("3.14abc") == false);
        expect(String::isNumber<int>(" 123 ") == false);
        expect(String::isNumber<int>("-42") == true);
        expect(String::isNumber<int>("0x1A") == false);
    }
    test$method(operator_equals) {
        String string = "a-string";
        String otherString = "b-string";
        const char* constChar = "c-string";
        std::string stdString = "d-string";

        string = otherString;
        expect(string == "b-string");
        string = constChar;
        expect(string == "c-string");
        string = stdString;
        expect(string == "d-string");
    }
    test$method(operator_equals_equals) {
        String string = "a-string";
        String otherString = "a-string";
        const char* constChar = "a-string";
        expect(string == otherString);
        expect(string == constChar);
    }
    test$method(operator_not_equals) {
        String string = "a-string";
        String otherString = "b-string";
        const char* constChar = "c-string";
        expect(string != otherString);
        expect(string != constChar);
    }
    test$method(operator_lessthan) {
        String a = "abc";
        String b = "bcd";
        String c = "abc";
        const char* d = "zzz";
        expect(a < b);
        expect(!(b < a));
        expect(!(a < c));
        expect(a < d);
    }
    test$method(operator_greaterthan) {
        String a = "xyz";
        String b = "aaa";
        String c = "xyz";
        const char* d = "abb";
        expect(a > b);
        expect(!(b > a));
        expect(!(a > c));
        expect(a > d);
    }
    test$method(operator_brackets) {
        expect(String("abc")[0] == 'a');
        expect(String("abc")[2] == 'c');
        expect(String("abc")[3] == char(0));
        expect(String("abc")[-1] == 'c');
        expect(String("abc")[-4] == char(0));
    }
    test$method(operator_plus_equals) {
        String a = "a";
        a += "b";
        a += String("c");
        expect(a == "abc");
    }
    test$method(operator_plus) {
        expect("a" + String("b") == "ab");
    }
    test$method(operator_stream_out) {
        String a = "abc";
        std::stringstream ss;
        ss << a;
        expect(ss.str() == "abc");
    }
    test$method(operator_stream_in) {
        std::stringstream ss("xyz");
        String a;
        ss >> a;
        expect(a == "xyz");
    }
    test$method(serialize) {
        String a = "abc";
        String b;
        Serializer::pipe(a, b);
        expect(a == b);
    }
)
#endif