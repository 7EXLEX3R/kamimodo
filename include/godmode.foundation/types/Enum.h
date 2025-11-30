#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/boost.preprocessor.h>
#include <godmode.foundation/$_preprocessor.h>
#include <godmode.foundation/types/String.h>

#define enum$item(r, $name, $item) static const $name $item;
#define enum$items($name, ...) BOOST_PP_SEQ_FOR_EACH(enum$item, $name, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))
#define enum$($name, ...) class $name { $ \
    int code; \
    enum$items($name, __VA_ARGS__) \
    constructor($name()) \
    constructor($name(const $name& k)) \
    constructor($name(int code)) \
    operator int() const; \
    operator int(); \
    String toString() const; \
    static String toString(const $name& value); \
    static $name fromString(String value); \
};
#define enum$$($name) class $name { $ \
    int code; \
    constructor($name()) \
    constructor($name(const $name& k)) \
    constructor($name(int code)) \
    operator int() const; \
    operator int(); \
    String toString() const; \
    static String toString(const $name& value);
#define enum$$$ \
};
#define enum$defineItem(r, $name, $item) const $name $name::BOOST_PP_TUPLE_ELEM(2, 0, $item) = $name(BOOST_PP_TUPLE_ELEM(2, 1, $item));
#define enum$defineItems($name, seq) BOOST_PP_SEQ_FOR_EACH(enum$defineItem, $name, seq)
#define enum$FromStringEntryDefinition(r, $name, $item) if (value == BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(2, 0, $item))) return $name::BOOST_PP_TUPLE_ELEM(2, 0, $item);
#define enum$ToStringEntryDefinition(r, $name, $item) if (value == $name::BOOST_PP_TUPLE_ELEM(2, 0, $item)) return BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(2, 0, $item));
#define enum$FromStringEntriesDefinition($name, seq) BOOST_PP_SEQ_FOR_EACH(enum$FromStringEntryDefinition, $name, seq)
#define enum$ToStringEntriesDefinition($name, seq) BOOST_PP_SEQ_FOR_EACH(enum$ToStringEntryDefinition, $name, seq)
#define enum$define($name, ...) \
$name::$name() { *this = $name::NONE; } \
$name::$name(const $name& k) : code(k.code) {} \
$name::$name(int code) : code(code) {} \
$name::operator int() const { return this->code; } \
$name::operator int() { return this->code; } \
$name $name::fromString(String value) { \
    enum$FromStringEntriesDefinition($name, __VA_ARGS__) \
    return $name::NONE; \
} \
String $name::toString() const { return $name::toString(*this); } \
String $name::toString(const $name& value) { \
    enum$ToStringEntriesDefinition($name, __VA_ARGS__) \
    return ""; \
} \
enum$defineItems($name, __VA_ARGS__)
#define enum$define$($name, ...) \
$name::$name() { *this = $name::NONE; } \
$name::$name(const $name& k) : code(k.code) {} \
$name::$name(int code) : code(code) {} \
$name::operator int() const { return this->code; } \
$name::operator int() { return this->code; } \
String $name::toString() const { return $name::toString(*this); } \
String $name::toString(const $name& value) {
#define enum$define$$ \
    return ""; \
}