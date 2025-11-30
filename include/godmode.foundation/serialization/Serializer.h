#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/SerializerInput.h>
#include <godmode.foundation/serialization/SerializerOutput.h>
#include <godmode.foundation/file/FileSystem.h>

godmode_foundation_serialization(class Serializer { $
    template <typename TInput, typename TOutput>
    static void pipe(const TInput& input, TOutput& output, String filename = "godmode.999") {
        SerializerOutput so(filename, input);
        SerializerInput si(filename, output);
        FileSystem::remove(filename);
    }
})