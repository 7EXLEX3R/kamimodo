#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/boost.process.h>
#include <godmode.foundation/async/Async.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_async(class Process : public Async<String> { $
    boost::process::child process;
    String pid = "";
    constructor(Process(String command, String cwd = "."))
    destructor$(Process())
    String run(String command, String cwd = ".");
    void terminate();
    static void spawn(String command, String cwd = ".");
})