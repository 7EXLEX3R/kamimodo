#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/logic/_2d/Quadtree.h>

test$class(Quadtree,
    test$method(serialize) {
        Quadtree* quadtree = new Quadtree();
        //quadtree->a = 1;
        Quadtree* quadtreeFromFile;
        Serializer::pipe(quadtree, quadtreeFromFile);
        //expect(quadtree->a == quadtreeFromFile->a);
        delete quadtree;
        delete quadtreeFromFile;
    }
)
#endif