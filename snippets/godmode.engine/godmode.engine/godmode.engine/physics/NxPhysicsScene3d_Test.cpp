#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_3d/Object3d_Mock.h>
#include <godmode.engine/physics/NxPhysicsScene3d.h>

test$class(NxPhysicsScene3d, // TODO(4) - tests
    test$method(serialize) {
        // FIXME: class boost::archive::archive_exception: unregistered class
        /*NxPhysicsScene3d* scene3d = new NxPhysicsScene3d();
        scene3d->addEntity(new Object3dMock(float3(1, 2, 3), float3(4, 5, 6), float3(7, 8, 9), 0));
        NxPhysicsScene3d* deserializedScene;
        Serializer::pipe(scene3d, deserializedScene);
        expect(scene3d->entities[0]->position == deserializedScene->entities[0]->position);
        delete scene3d;
        delete deserializedScene;*/
    }
)
#endif