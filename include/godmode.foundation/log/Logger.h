#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>

godmode_foundation_log(template <class LoggerType> class Logger { $
    private$(LoggerType* type = nullptr)
    constructor(Logger() {})
    constructor(Logger(LoggerType *type) : type(type) {})
    bool debug(const String method, const String reason = "") { console->debug(this->getLogText(method, reason)); return true; }
    bool success(const String method, const String reason = "") { console->success(this->getLogText(method, reason)); return true; }
    bool log(const String method, const String reason = "") { console->log(this->getLogText(method, reason)); return true; }
    bool warn(const String method, const String reason = "") { console->warn(this->getLogText(method, reason)); return true; }
    bool error(const String method, const String reason = "") { console->error(this->getLogText(method, reason)); return false; }
    String getLogText(const String& method, const String& reason) {
        String name = *String(typeid(LoggerType).name()).split("::").back();
        String additionalInfo = "";
        if (auto stringRepresentable = dynamic_cast<StringRepresentable*>(type))
            additionalInfo += " (" + stringRepresentable->toString() + ")";
        additionalInfo += " @ " + String(String::from(type).lower());
        return name + "::" + method + (reason ? " - " + reason : "") + additionalInfo;
    }
})