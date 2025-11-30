#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/time/TimeStruct.h>
#include <godmode.foundation/types/StringRepresentable.h>

godmode_foundation_time(class Date : public TimeStruct, public StringRepresentable { $
    constructor(Date())
    destructor$(Date())
    unsigned getSecond();
    unsigned getMinute();
    unsigned getHour();
    unsigned getDayOfWeek();
    unsigned getDayOfMonth();
    unsigned getDayOfYear();
    unsigned getMonth();
    unsigned getYear();
    bool isDaylightSavingTime();
    String toString();
    static TimeStruct getCurrentTime();
})