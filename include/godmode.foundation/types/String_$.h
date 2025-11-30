#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.string.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/List_$.h>
#include <godmode.foundation/types/Json_$.h>

godmode_foundation_types(class String { $
    std::string $string;
    constructor(String())
    constructor(String(const String& str))
    constructor(String(const char* constChar))
    constructor(String(std::string str))
    constructor(String(char _char))
    constructor(String(JSON json))
    int length() const;
    bool includes(String value) const;
    int indexOf(String value, int position = 0) const;
    int lastIndexOf(String value, int position = -1) const;
    char at(int index);
    bool startsWith(String value, int fromIndex = 0) const;
    bool endsWith(String value, int toIndex = -1) const;
    int count(String value, int fromIndex = 0) const;
    String upper();
    String lower();
    String trim(String value = " ");
    String trimStart(String value = " ");
    String trimEnd(String value = " ");
    String replace(int from, int to, String replace = "") const;
    String replace(String value, String replace = "") const;
    String replaceLast(String value, String replace = "") const;
    String replaceAll(String value, String replace = "") const;
    String substring(int from, int to = -1, bool inclusive = false) const;
    String substring(String from, String to = "", bool inclusive = false) const;
    String substringLast(String from, String to = "", bool inclusive = false) const;
    String substringTo(int to, bool inclusive = false) const;
    String substringTo(String to, bool inclusive = false) const;
    String substringToLast(String to, bool inclusive = false) const;
    List<String> split(String divider = "");
    std::string asStdString() const;
    std::wstring asStdWideString() const;
    std::string asAnsiString() const;
    const char* asConstChar();
    template <class Type>
    String& assignFrom(Type value) { this->$string = String::from<Type>(value).$string; return *this; }
    static String from(int value);
    static String from(float value);
    static String from(char value);
    static String from(bool value);
    template <class Type>
    static String from(Type value) {
        std::stringstream stream;
        std::string castedValue;
        stream << value;
        stream >> castedValue;
        return String(castedValue);
    }
    template <> static String from<bool>(bool value) { return String::from(value); }
    template <class Type> Type to() { return String::to<Type>(*this); }
    template <class Type> static Type to(String value) {
        std::stringstream stream;
        Type castedValue;
        stream << value;
        stream >> castedValue;
        return castedValue;
    }
    template <> static bool to<bool>(String value) { return value.isTruthy(); }
    bool isTruthy() const;
    template <typename T> bool isNumber() { return String::isNumber<T>(*this); }
    template <typename T> static bool isNumber(String str) {
        std::stringstream stream(str.asConstChar());
        T value;
        stream >> value;
        return !stream.fail() && stream.eof();
    }
    static bool isWhitespace(String str);
    static bool isWhitespace(char str);
    int findOppositeCharacterGroupIndexLeft(int index);
    int findOppositeCharacterGroupIndexRight(int index);
    bool isWhitespace();
    String operator=(const String& right);
    String operator=(const char* right);
    String operator=(std::string& right);
    bool operator==(const char* constChar);
    bool operator==(String& right);
    friend bool operator==(const String& left, const char* constChar);
    friend bool operator==(const String& left, const String& right);
    bool operator!=(const char* constChar);
    bool operator!=(String& right);
    bool operator!=(const String& right);
    friend bool operator!=(const String& left, const char* constChar);
    friend bool operator<(const String& left, const String& right);
    friend bool operator>(const String& left, const String& right);
    char operator[](int index);
    void operator+=(String& right);
    void operator+=(const String& right);
    String operator+(String& right);
    String operator+(const String& right);
    String operator+(const char* right);
    friend String operator+(const char* left, const String& right);
    friend String operator+(const String& left, const String& right);
    friend String operator+(const String& left, String& right);
    friend String operator+(const char* left, String& right);
    friend std::ostream& operator<<(std::ostream& stream, const String& right);
    friend std::istream& operator>>(std::istream& stream, String& right);
    operator bool() const { return this->isTruthy(); }
    private$(String $substr(int from, int to) const)
    s11n$declare()
};
namespace StringTraits {
    template<typename T> struct isStringLike : std::false_type {};
    template<> struct isStringLike<std::string> : std::true_type {};
    template<> struct isStringLike<String> : std::true_type {};
    template<> struct isStringLike<const char*> : std::true_type {};
})
s11n$export(String);