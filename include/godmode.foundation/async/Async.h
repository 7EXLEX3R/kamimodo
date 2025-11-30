#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/async/AbstractAsync.h>
#include <godmode.foundation/async/AsyncState.h>
#include <godmode.foundation/system/Config.h>
#include <godmode.foundation/types/Any.h>
#include <godmode.foundation/types/Function.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/Promise.h>

godmode_foundation_async(template <class AsyncReturnType = Any> class Async : public AbstractAsync { $
    Promise<AsyncReturnType> promise;
    List<Function<void(AsyncReturnType)>> handlers;
    constructor(Async(Function<AsyncReturnType()> call, bool syncedAsyncs = $_config->get("async.syncedAsyncs", false).asBoolean()) {
        this->promise = std::async(std::launch::async, call);
        (syncedAsyncs ? $_asyncs : $_asyncAsyncs).add(this);
    })
    destructor$(Async() {
        if (this->promise.valid()) {
            try { this->promise.get(); }
            catch (const std::exception& e) {
                console->log(String(e.what()));
            }
        }
    })
    Async<AsyncReturnType>* then(Function<void(AsyncReturnType)> handler) {
        this->handlers.add(handler);
        return this;
    }
    AsyncState process() {
        if (this->promise.valid() && this->promise.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            for (int i = 0; i < this->handlers.length(); i++)
                this->handlers[i](this->promise.get());
            return AsyncState::SUCCESS;
        }
        return AsyncState::PENDING;
    }
})