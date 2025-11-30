#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/LogicEntity3d.h>

test$class(LogicEntity3d,
    test$method(serialize) {
        // LogicEntity3d* relatedEntity = new LogicEntity3d(float3(3,2,1), float3(3,2,1), float3(3,2,1));
        LogicEntity3d* entity = new$(LogicEntity3d, _.position = float3(1, 2, 3), _.rotation = float3(4, 5, 6), _.scale = float3(7, 8, 9));
        // entity->relativeEntity = relatedEntity;
        LogicEntity3d* entityFromFile;
        Serializer::pipe(entity, entityFromFile);
        expect(entity->position == entityFromFile->position);
        expect(entity->rotation == entityFromFile->rotation);
        expect(entity->scale == entityFromFile->scale);
        delete entity;
        // delete relatedEntity;
        // delete entityFromFile->relativeEntity;
        delete entityFromFile;
    }
)
#endif