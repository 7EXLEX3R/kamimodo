#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/file/JsonFile.h>

test$class(JsonFile,
    test$method(read) {
        JsonFile* jsonfile = new JsonFile("config/application.config.json");
        // console->log(jsonfile->getSource());
        delete jsonfile;
    }
)
#endif