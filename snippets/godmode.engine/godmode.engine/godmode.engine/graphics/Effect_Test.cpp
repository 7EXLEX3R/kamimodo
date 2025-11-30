#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Effect.h>
#include <godmode.engine/graphics/Shader_Mock.h>

test$class(Effect,
    test$method(serialize) {
        Shader *shader = new ShaderMock("SSS", "NNN");
        Effect *e = new Effect(shader, JSON::null, "effect");
        Effect *e2 = new Effect(shader, JSON::null, "effect2");

        SerializerOutput *so = new SerializerOutput("temp/Effect.test.serialize");
        *so << e << e2;
        delete so;

        Effect *re, *re2;
        Effect *re22, *re222;

        SerializerInput *si = 0;
        si = new SerializerInput("temp/Effect.test.serialize");
        *si >> re >> re2;
        delete si;

        si = new SerializerInput("temp/Effect.test.serialize");
        *si >> re22 >> re222;
        delete si;
        expect(e->name == re->name);

        delete e;
        delete e2;
        delete shader;
        delete re->shader;
        delete re22->shader;
        delete re;
        delete re2;
        delete re22;
        delete re222;
    }
)
#endif