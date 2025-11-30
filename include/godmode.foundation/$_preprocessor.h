#pragma once

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#pragma warning(disable : 4996)  // disable deprecated warning
#pragma warning(disable : 4244)  // disable double to float conversion warning
#pragma warning(disable : 4018)  // disable signed/unsigned mismatch warning
#pragma warning(disable : 4305)  // disable 'initializing' : truncation from 'double' to 'float' warning
#pragma warning(disable : 4067)  // warning C4067: unexpected tokens following preprocessor directive - expected a newline
#pragma warning(disable : 4348)  // warning C4348: redefinition of default parameter
#pragma warning(disable : 4002)  // warning C4002: too many actual parameters for macro 'BOOST_TEST_STRINGIZE'

#define namespace$_1_$(a) namespace a {
#define namespace$_2_$(a, b) namespace a { namespace b {
#define namespace$_3_$(a, b, c) namespace a { namespace b { namespace c {
#define namespace$_4_$(a, b, c, d) namespace a { namespace b { namespace c { namespace d {
#define namespace$_5_$(a, b, c, d, e) namespace a { namespace b { namespace c { namespace d { namespace e {
#define namespace$_6_$(a, b, c, d, e, f) namespace a { namespace b { namespace c { namespace d { namespace e { namespace f {

#define namespace$_1_$$(a) ;} using namespace a;
#define namespace$_2_$$(a, b) ;}} using namespace a::b;
#define namespace$_3_$$(a, b, c) ;}}} using namespace a::b::c;
#define namespace$_4_$$(a, b, c, d) ;}}}} using namespace a::b::c::d;
#define namespace$_5_$$(a, b, c, d, e) ;}}}}} using namespace a::b::c::d::e;
#define namespace$_6_$$(a, b, c, d, e, f) ;}}}}}} using namespace a::b::c::d::e::f;

#define namespace$_1(a, ...) namespace a { __VA_ARGS__; } using namespace a;
#define namespace$_2(a, b, ...) namespace a { namespace b { __VA_ARGS__; }} using namespace a::b;
#define namespace$_3(a, b, c, ...) namespace a { namespace b { namespace c { __VA_ARGS__; }}} using namespace a::b::c;
#define namespace$_4(a, b, c, d, ...) namespace a { namespace b { namespace c { namespace d { __VA_ARGS__; }}}} using namespace a::b::c::d;
#define namespace$_5(a, b, c, d, e, ...) namespace a { namespace b { namespace c { namespace d { namespace e { __VA_ARGS__; }}}}} using namespace a::b::c::d::e;
#define namespace$_6(a, b, c, d, e, f, ...) namespace a { namespace b { namespace c { namespace d { namespace e { namespace f { __VA_ARGS__; }}}}}} using namespace a::b::c::d::e::f;

#define global$_1(a, name, ...) namespace$_1(a, extern __VA_ARGS__ name;) namespace a { using a::name; }
#define global$_2(a, b, name, ...) namespace$_2(a, b, extern __VA_ARGS__ name;) namespace a { using a::b::name; }
#define global$_3(a, b, c, name, ...) namespace$_3(a, b, c, extern __VA_ARGS__ name;) namespace a { using a::b::c::name; }
#define global$_4(a, b, c, d, name, ...) namespace$_4(a, b, c, d, extern __VA_ARGS__ name;) namespace a { using a::b::c::d::name; }
#define global$_5(a, b, c, d, e, name, ...) namespace$_5(a, b, c, d, e, extern __VA_ARGS__ name;) namespace a { using a::b::c::d::e::name; }
#define global$_6(a, b, c, d, e, f, name, ...) namespace$_6(a, b, c, d, e, f, extern __VA_ARGS__ name;) namespace a { using a::b::c::d::e::f::name; }

#define new$(Type, ...) new Type(([&]() -> Type##Params { Type##Params _; __VA_ARGS__; return _; }()))
#define params$(Type, ...) ([&]() -> Type##Params { Type##Params _; __VA_ARGS__; return _; }())
#define extend$(Type, params, ...) ([params]() -> Type##Params { Type##Params _ = params; __VA_ARGS__; return _; }())
#define safe$(ptr, ...) do { if (ptr) { ptr->__VA_ARGS__; } } while(0);
#define safe$$(ptr, ...) ptr && ptr->__VA_ARGS__
#define delete$(ptr) do { if (ptr) { delete ptr; ptr = 0; } } while(0);
#define deleteArray$(ptr) do { if (ptr) { delete [] ptr; ptr = 0; } } while(0);
#define release$(ptr) do { if (ptr) { ptr->Release(); ptr = 0; } } while(0);
#define function$(params, ...) [&] params { return __VA_ARGS__; }
#define $ public:
#define class$(header, body) header { $ body };
#define constructor(...) __VA_ARGS__;
#define destructor$(...) virtual ~__VA_ARGS__;
#define private$(...) private: __VA_ARGS__; public:
#define protected$(...) protected: __VA_ARGS__; public:
#define section$(name) /* name */