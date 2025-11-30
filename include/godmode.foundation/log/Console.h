#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.fstream.h>
#include <godmode.foundation/log/LogEntry.h>
#include <godmode.foundation/time/Date.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_foundation_log(class Console { $
    LogType logLevel = LogType::DEBUG;
    constructor(Console())
    destructor$(Console())
    LogEntry debug(String text, StringRepresentable* object = 0);
    LogEntry debug(String text, StringRepresentable& object);
    LogEntry debug(StringRepresentable* object);
    LogEntry debug(StringRepresentable& object);
    LogEntry success(String text, StringRepresentable* object = 0);
    LogEntry success(String text, StringRepresentable& object);
    LogEntry success(StringRepresentable* object);
    LogEntry success(StringRepresentable& object);
    LogEntry log(String text, StringRepresentable* object = 0, LogType logType = LogType::LOG);
    LogEntry log(String text, StringRepresentable& object, LogType logType = LogType::LOG);
    LogEntry log(StringRepresentable* object, LogType logType = LogType::LOG);
    LogEntry log(StringRepresentable& object, LogType logType = LogType::LOG);
    LogEntry warn(String text, StringRepresentable* object = 0);
    LogEntry warn(String text, StringRepresentable& object);
    LogEntry warn(StringRepresentable* object);
    LogEntry warn(StringRepresentable& object);
    LogEntry error(String text, StringRepresentable* object = 0);
    LogEntry error(String text, StringRepresentable& object);
    LogEntry error(StringRepresentable* object);
    LogEntry error(StringRepresentable& object);

    private$(void output(String outputString))
    private$(std::ofstream txtOutputFile)
    private$(String logFilePath)
})
godmode_foundation_log$extern(console, Console*)
godmode_foundation_log$extern($_console, Console*)