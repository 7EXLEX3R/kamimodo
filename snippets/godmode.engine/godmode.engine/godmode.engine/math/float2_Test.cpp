#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float2.h>

test$class(float2,
    test$method(constructor) {
        float2 f = {1, 2};
        expect(f.x == 1);
        expect(f.y == 2);
    }
    test$method(comparison) {
        float2 left = float2(1, 2);
        float2 leftMirror = float2(2, 1);
        float2 leftClone = float2(1, 2);
        float2 right = float2(2, 2);
        expect(leftMirror.x == left.y);
        expect(leftMirror.y == left.x);
        expect(leftMirror.x != left.x);
        expect(leftMirror.y != left.y);
        expect(left == leftClone);
        expect(leftClone == left);
        expect(left != right);
        expect(right != leftClone);
        expect(leftMirror != left);
    }
    test$method(add) {
        float2 left = float2(1, 2);
        float2 right = float2(2, 2);
        expect(left + right == float2(3, 4));
        expect(right + left == float2(3, 4));
        left += right;
        expect(left == float2(3, 4));
    }
    test$method(subtract) {
        float2 left = float2(1, 2);
        float2 right = float2(2, 2);
        expect(left - right == float2(-1, 0));
        expect(right - left == float2(1, 0));
        left -= right;
        expect(left == float2(-1, 0));
    }
    test$method(multiplication) {
        float2 left = float2(1, 2);
        float2 right = float2(2, 2);
        expect(left * right == float2(2, 4));
        expect(right * left == float2(2, 4));
        expect(left * 2 == float2(2, 4));
        expect(right * 2 == float2(4, 4));
        expect(2 * right == float2(4, 4));
        left = left * right;
        expect(left == float2(2, 4));
        expect(right == float2(2, 2));
    }
    test$method(division) {
        float2 left = float2(1, 2);
        float2 right = float2(2, 2);
        expect(left / right == float2(.5, 1));
        expect(right / left == float2(2, 1));
        expect(left / 2 == float2(.5, 1));
        expect(right / 2 == float2(1, 1));
        left = left / right;
        expect(left == float2(.5, 1));
        expect(right == float2(2, 2));
    }
    test$method(stringFormat) {
        float2 left = float2(1, 2);
        float2 right;
        right.fromString("2, 2");
        float2 invalid = float2(1, 1);
        invalid.fromString("invalid format");

        expect(left.toString() == "{ 1, 2 }");
        expect(right == float2(2, 2));
        expect(invalid == float2(1, 1));
    }
    test$method(jsonFormat) {
        JSON float2Json, invalidJson;
        float2Json["x"] = 2;
        float2Json["y"] = 2;
        float2 left = float2(1, 2);
        float2 right;
        right.fromJson(float2Json);
        float2 invalid = float2(1, 1);
        invalid.fromJson(invalidJson);
        expect(left.toJson()["x"].asDouble() == 1 && left.toJson()["y"].asDouble() == 2);
        expect(right == float2(2, 2));
        expect(invalid == float2(1, 1));
    }
    test$method(serialize) {
        float2 left = float2(1, 2);
        float2 right;
        Serializer::pipe(left, right);
        expect(left == right);
    }
)
#endif