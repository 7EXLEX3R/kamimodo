#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/MappedList.h>
#include <godmode.foundation/types/Function.h>
#include <godmode.foundation/types/String.h>
#include <godmode.foundation/core/Module.h>
#include <godmode.foundation/core/Runtime.h>

godmode_foundation_core(class AppRunner { $
    static Runtime* app;
    static AppRunner& init(Function<void()> postinit);
    static AppRunner& init(void* app = nullptr, void* args = nullptr, void* opts = nullptr, Function<void()> postinit = nullptr);
    static int run(String engineName = "", String appName = "");
    static int run(Function<Module* ()> engineFactory, Function<Runtime* ()> appFactory);
    static Runtime* start(String engineName = "", String appName = "");
    static Runtime* start(Function<Module* ()> engineFactory, Function<Runtime* ()> appFactory);
    static void terminate();
    static void startEngine(String engineName = "");
    static void startEngine(Function<Module* ()> engineFactory);
    static void terminateEngine();
    static int runApp(String appName = "");
    static int runApp(Function<Runtime* ()> appFactory);
    static Runtime* startApp(String appName = "");
    static Runtime* startApp(Function<Runtime* ()> appFactory);
    static void terminateApp();
    private$(static AppRunner& instance())
})
godmode_foundation_core$extern($_engines, MappedList<String, Function<Module* ()>>)
godmode_foundation_core$extern($_apps, MappedList<String, Function<Runtime* ()>>)
