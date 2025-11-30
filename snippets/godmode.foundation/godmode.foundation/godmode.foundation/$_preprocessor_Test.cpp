#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_preprocessor.h>
#include "$_preprocessor_Test.h"

test$class(preprocessor,
    test$method(params) {
        test$context("default") {
            ParamsTestClass tpc = ParamsTestClass();
            expect(tpc.value == ParamsTestClass().value);
            expect(tpc.otherValue == ParamsTestClass().otherValue);
            expect(tpc.pointer == ParamsTestClass().pointer);
        }
        test$context("partialy default") {
            ParamsTestClass tpc = ParamsTestClass(params$(ParamsTestClass, _.otherValue = 4; _.otherValue_2 = 3;));
            expect(tpc.value == ParamsTestClass().value);
            expect(tpc.otherValue == 4);
            expect(tpc.otherValue_2 == 3);
            expect(tpc.pointer == nullptr);
        }
        test$context("extended") {
            ParamsTestClass tpc = ParamsTestClass(params$(ParamsTestClass, _.otherValue = 4; _.otherValue_2 = 3;));
            ParamsTestClassParams tp;
            tp.otherValue = 44;
            ParamsTestClass tpc2 = ParamsTestClass(extend$(ParamsTestClass, tp, _.otherValue_2 = 33;));
            expect(tpc.value == ParamsTestClass().value);
            expect(tpc.otherValue == 4);
            expect(tpc.otherValue_2 == 3);
            expect(tpc.pointer == nullptr);
            expect(tpc2.otherValue == 44);
            expect(tpc2.otherValue_2 == 33);
            expect(tpc2.pointer == nullptr);
        }
    }
)
#endif