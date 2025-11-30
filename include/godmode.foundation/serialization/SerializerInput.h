#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.fstream.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/String.h>

godmode_foundation_serialization_$ class SerializerInput { $
    std::ifstream stream;
    constructor(SerializerInput(String filename))
    destructor$(SerializerInput())
    void close();
    #ifdef serialization$
        boost::archive::text_iarchive* archive;
    #endif
    template <typename T>
    SerializerInput(String filename, T& dataToDeserialize) : SerializerInput(filename) {
        #ifdef serialization$
            *archive >> dataToDeserialize;
        #endif
        this->close();
    }
    template <typename T>
    SerializerInput& operator>>(T& dataToDeserialize) {
        #ifdef serialization$
            *this->archive >> dataToDeserialize;
        #endif
        return *this;
    }
} godmode_foundation_serialization_$$