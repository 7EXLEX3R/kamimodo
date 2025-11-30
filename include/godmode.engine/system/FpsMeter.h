#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.time.h>
#include <godmode.foundation/types/List.h>

godmode_engine_system(class FpsMeter { $
    long ticksInSecond = 0;
    protected$(long currentTicks = 0)
    protected$(long deltaTicks = 0)
    private$(double fps = 60.0)
    private$(double frameTime = 1.0 / 60.0)
    private$(double frameTicks = 0)
    private$(double time = 0)
    private$(int frameBufferSize = 0)
    private$(List<double> frameTicksBuffer)
    private$(unsigned long frameCount = 0);
    constructor(FpsMeter(int frameBufferSize = 3, long ticksInSecond = CLOCKS_PER_SEC))
    destructor$(FpsMeter())
    double getFps();
    double getFrameTime();
    double getTime();
    void frameBegin();
    void frameEnd();
    virtual long getClock();
    unsigned long getFrameCount();
})
godmode_engine_system$extern($_fpsMeter, FpsMeter*)