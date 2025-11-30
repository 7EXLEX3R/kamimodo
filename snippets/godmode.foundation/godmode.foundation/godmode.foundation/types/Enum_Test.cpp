#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Enum.h>

enum$(TestType, NONE, A, B)
enum$define(TestType, ((NONE, 0)) ((A, 1)) ((B, 3)))  // TODO: autodef for 0,1,2,3 / defs in .h in general

test$class(Enum,
    test$method(playground) {
        expect(TestType::NONE.toString() == "NONE");
        expect(TestType::fromString("A") == TestType::A);
        expect(TestType::fromString("C") == TestType::NONE);
        expect(TestType::fromString("B").toString() == "B");
        expect(TestType::A == 1);
        expect(TestType(3) == TestType::B);
        expect(TestType(2).toString() == "");
        expect(TestType(2) != TestType::NONE && TestType(2) != TestType::A && TestType(2) != TestType::B); // FIXME: shouldn't it be NONE same as for fromString("C")
    }
)
#endif