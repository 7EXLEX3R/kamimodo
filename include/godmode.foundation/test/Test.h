#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#ifdef test$
    #include <godmode.foundation/$_preprocessor.h>
    #include <godmode.foundation/$_dependencies/boost.testing.h>
    #include <godmode.foundation/$_dependencies/windows.h>
    #include <godmode.foundation/log/Console.h>
    #include <godmode.foundation/serialization/Serializer.h>
    #define test$class$(name) BOOST_AUTO_TEST_SUITE(name##_Test)
    #define test$class$$ BOOST_AUTO_TEST_SUITE_END()
    #define test$method(name) BOOST_AUTO_TEST_CASE(name)
    #define test$class(name, ...) test$class$(name) \
        __VA_ARGS__; \
        test$class$$
    #define test$context(name) BOOST_TEST_CONTEXT(name)
    #define expect(...) BOOST_CHECK(__VA_ARGS__)
#endif