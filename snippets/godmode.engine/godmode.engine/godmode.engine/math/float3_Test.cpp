#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float3.h>

test$class(float3,
    test$method(constructor) {
        float3 f = {1, 2, 3};
        expect(f.x == 1);
        expect(f.y == 2);
        expect(f.z == 3);
    }
    test$method(comparison) {
        float3 left = float3(1, 2, 3);
        float3 leftMirror = float3(3, 2, 1);
        float3 leftClone = float3(1, 2, 3);
        float3 right = float3(2, 2, 2);
        expect(leftMirror.x == left.z);
        expect(leftMirror.y == left.y);
        expect(leftMirror.z == left.x);
        expect(leftMirror.x != left.x);
        expect(leftMirror.y == left.y);
        expect(leftMirror.z != left.z);
        expect(left == leftClone);
        expect(leftClone == left);
        expect(left != right);
        expect(right != leftClone);
        expect(leftMirror != left);
    }
    test$method(add) {
        float3 left = float3(1, 2, 3);
        float3 right = float3(2, 2, 2);
        expect(left + right == float3(3, 4, 5));
        expect(right + left == float3(3, 4, 5));
        left += right;
        expect(left == float3(3, 4, 5));
    }
    test$method(subtract) {
        float3 left = float3(1, 2, 3);
        float3 right = float3(2, 2, 2);
        expect(left - right == float3(-1, 0, 1));
        expect(right - left == float3(1, 0, -1));
        left -= right;
        expect(left == float3(-1, 0, 1));
    }
    test$method(multiplication) {
        float3 left = float3(1, 2, 3);
        float3 right = float3(2, 2, 2);
        expect(left * right == float3(2, 4, 6));
        expect(right * left == float3(2, 4, 6));
        expect(left * 2 == float3(2, 4, 6));
        expect(right * 2 == float3(4, 4, 4));
        expect(2 * right == float3(4, 4, 4));
        left = left * right;
        expect(left == float3(2, 4, 6));
        expect(right == float3(2, 2, 2));
    }
    test$method(division) {
        float3 left = float3(1, 2, 3);
        float3 right = float3(2, 2, 2);
        expect(left / right == float3(.5, 1, 1.5));
        expect(right / left == float3(2, 1, 2.0f / 3.0f));
        expect(left / 2 == float3(.5, 1, 1.5));
        expect(right / 2 == float3(1, 1, 1));
        left = left / right;
        expect(left == float3(.5, 1, 1.5));
        expect(right == float3(2, 2, 2));
    }
    test$method(stringFormat) {
        float3 left = float3(1, 2, 3);
        float3 right;
        right.fromString("2, 2, 2");
        float3 invalid = float3(1, 1, 1);
        invalid.fromString("invalid format");

        expect(left.toString() == "{ 1, 2, 3 }");
        expect(right == float3(2, 2, 2));
        expect(invalid == float3(1, 1, 1));
    }
    test$method(jsonFormat) {
        JSON float3Json, invalidJson;
        float3Json["x"] = 2;
        float3Json["y"] = 2;
        float3Json["z"] = 2;
        float3 left = float3(1, 2, 3);
        float3 right;
        right.fromJson(float3Json);
        float3 invalid = float3(1, 1, 1);
        invalid.fromJson(invalidJson);
        expect(left.toJson()["x"].asDouble() == 1 && left.toJson()["y"].asDouble() == 2 && left.toJson()["z"].asDouble() == 3);
        expect(right == float3(2, 2, 2));
        expect(invalid == float3(1, 1, 1));
    }
    test$method(serialize) {
        float3 left = float3(1, 2, 3);
        float3 right;
        Serializer::pipe(left, right);
        expect(left == right);
    }
)
#endif