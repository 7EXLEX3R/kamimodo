#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/file/TextFile.h>

test$class(TextFile,
    test$method(read) {
        TextFile* textfile = new TextFile("config/application.config.json");
        // console->log(textfile->getSource());
        delete textfile;
    }
)
#endif