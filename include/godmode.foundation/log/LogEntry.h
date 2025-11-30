#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/LogType.h>
#include <godmode.foundation/time/Date.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_foundation_log(class LogEntry : public StringRepresentable { $
    String text;
    LogType type;
    Date date;
    constructor(LogEntry(String type, LogType logType = LogType::LOG))
    destructor$(LogEntry())
    String toString();
})