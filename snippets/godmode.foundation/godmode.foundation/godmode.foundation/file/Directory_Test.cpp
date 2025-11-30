#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/log/Console.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/file/Directory.h>

test$class(Directory,
    test$method(read) {
        Directory* directory = new Directory(".");
        List<ContentItem*> items = directory->getContentItemsRecursively();
        for (int i = 0; i < items.length(); i++) {
            // console->log(items[i]->getPath());
        }
        delete directory;
    }
    test$method(readTree) {
        Directory* directory = new Directory(".", DirectoryAccessType::RECURSIVE_SCAN);
        List<ContentItem*> items = directory->getContentItemsRecursively();
        for (int i = 0; i < items.length(); i++) {
            // console->log(items[i]->getPath());
        }
        delete directory;
    }
)
#endif