#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.fstream.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_serialization_$ class SerializerOutput { $
    std::ofstream stream;
    #ifdef serialization$
        boost::archive::text_oarchive* archive;
    #endif
    constructor(SerializerOutput(String filename))
    destructor$(SerializerOutput())
    void close();
    template <typename T> SerializerOutput(String filename, const T& dataToSerialize) : SerializerOutput(filename) {
        #ifdef serialization$
            *archive << dataToSerialize;
        #endif
        this->close();
    }
    template <typename T> SerializerOutput& operator<<(const T& dataToSerialize) {
        #ifdef serialization$
            *this->archive << dataToSerialize;
        #endif
        return *this;
    }
} godmode_foundation_serialization_$$