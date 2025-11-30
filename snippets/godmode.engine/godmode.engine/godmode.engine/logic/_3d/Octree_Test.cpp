#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_3d/Octree.h>

test$class(Octree,
    test$method(serialize) {
        Octree* octree = new Octree();
        //octree->a = 1;
        Octree* octreeFromFile;
        Serializer::pipe(octree, octreeFromFile);
        //expect(octree->a == octreeFromFile->a);
        delete octree;
        delete octreeFromFile;
    }
)
#endif