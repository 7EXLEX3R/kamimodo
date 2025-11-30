#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#ifdef test$
    #define BOOST_TEST_MODULE godmode
    #include <godmode.foundation/test/Test.h>
    #include <godmode.foundation/core/AppRunner.h>
    #include <boost/test/included/unit_test.hpp> // LINK : fatal error LNK1561: entry point must be defined

    #define fixture(init, deinit) \
    struct GodmodeTestFixture { \
        GodmodeTestFixture() { \
            init \
            boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_test_units); \
        } \
        ~GodmodeTestFixture() { \
            deinit \
            std::cin.get(); \
         } \
    }; BOOST_GLOBAL_FIXTURE(GodmodeTestFixture);
#endif