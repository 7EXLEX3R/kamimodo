#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/async/Async.h>
#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/types/Function.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_network(class Http { $
    static JSON requestSync(String url, JSON params = JSON::null);
    static JSON requestStreamSync(String url, JSON params = JSON::null,
        Function<void(String chunk)> streamingHandler = [](String chunk) -> void { console->log(chunk); });
    static Async<JSON>* request(String url, JSON params = JSON::null);
    static Async<JSON>* requestStream(String url, JSON params = JSON::null,
        Function<void(String chunk)> streamingHandler = [](String chunk) -> void { console->log(chunk); });
})