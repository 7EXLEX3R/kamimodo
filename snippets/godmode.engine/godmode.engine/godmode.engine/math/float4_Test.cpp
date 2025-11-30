#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float4.h>

test$class(float4,
    test$method(constructor) {
        float4 f = {1, 2, 3, 4};
        expect(f.x == 1);
        expect(f.y == 2);
        expect(f.z == 3);
        expect(f.w == 4);
    }
    test$method(comparison) {
        float4 left = float4(1, 2, 3, 4);
        float4 leftMirror = float4(4, 3, 2, 1);
        float4 leftClone = float4(1, 2, 3, 4);
        float4 right = float4(2, 2, 2, 2);
        expect(leftMirror.x == left.w);
        expect(leftMirror.y == left.z);
        expect(leftMirror.z == left.y);
        expect(leftMirror.w == left.x);
        expect(leftMirror.x != left.x);
        expect(leftMirror.y != left.y);
        expect(leftMirror.z != left.z);
        expect(leftMirror.w != left.w);
        expect(left == leftClone);
        expect(leftClone == left);
        expect(left != right);
        expect(right != leftClone);
        expect(leftMirror != left);
    }
    test$method(add) {
        float4 left = float4(1, 2, 3, 4);
        float4 right = float4(2, 2, 2, 2);
        expect(left + right == float4(3, 4, 5, 6));
        expect(right + left == float4(3, 4, 5, 6));
        left += right;
        expect(left == float4(3, 4, 5, 6));
    }
    test$method(subtract) {
        float4 left = float4(1, 2, 3, 4);
        float4 right = float4(2, 2, 2, 2);
        expect(left - right == float4(-1, 0, 1, 2));
        expect(right - left == float4(1, 0, -1, -2));
        left -= right;
        expect(left == float4(-1, 0, 1, 2));
    }
    test$method(multiplication) {
        float4 left = float4(1, 2, 3, 4);
        float4 right = float4(2, 2, 2, 2);
        expect(left * right == float4(2, 4, 6, 8));
        expect(right * left == float4(2, 4, 6, 8));
        expect(left * 2 == float4(2, 4, 6, 8));
        expect(right * 2 == float4(4, 4, 4, 4));
        expect(2 * right == float4(4, 4, 4, 4));
        left = left * right;
        expect(left == float4(2, 4, 6, 8));
        expect(right == float4(2, 2, 2, 2));
    }
    test$method(division) {
        float4 left = float4(1, 2, 3, 4);
        float4 right = float4(2, 2, 2, 2);
        expect(left / right == float4(.5, 1, 1.5, 2));
        expect(right / left == float4(2, 1, 2.0f / 3.0f, .5));
        expect(left / 2 == float4(.5, 1, 1.5, 2));
        expect(right / 2 == float4(1, 1, 1, 1));
        left = left / right;
        expect(left == float4(.5, 1, 1.5, 2));
        expect(right == float4(2, 2, 2, 2));
    }
    test$method(stringFormat) {
        float4 left = float4(1, 2, 3, 4);
        float4 right;
        right.fromString("2, 2, 2, 2");
        float4 invalid = float4(1, 1, 1, 1);
        invalid.fromString("invalid format");
        console->log(left.toString());
        expect(left.toString() == "{ 1, 2, 3, 4 }");
        expect(right == float4(2, 2, 2, 2));
        expect(invalid == float4(1, 1, 1, 1));
    }
    test$method(jsonFormat) {
        JSON float4Json, invalidJson;
        float4Json["x"] = 2;
        float4Json["y"] = 2;
        float4Json["z"] = 2;
        float4Json["w"] = 2;
        float4 left = float4(1, 2, 3, 4);
        float4 right;
        right.fromJson(float4Json);
        float4 invalid = float4(1, 1, 1, 1);
        invalid.fromJson(invalidJson);
        expect(left.toJson()["x"].asDouble() == 1 && left.toJson()["y"].asDouble() == 2 && left.toJson()["z"].asDouble() == 3 && left.toJson()["w"].asDouble() == 4);
        expect(right == float4(2, 2, 2, 2));
        expect(invalid == float4(1, 1, 1, 1));
    }
    test$method(serialize) {
        float4 left = float4(1, 2, 3, 4);
        float4 right;
        Serializer::pipe(left, right);
        expect(left == right);
    }
)
#endif