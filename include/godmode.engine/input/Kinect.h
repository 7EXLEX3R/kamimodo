#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/$_dependencies/kinect.h>
#include <godmode.engine/input/InputDevice.h>
#include <godmode.engine/math/float3.h>

godmode_engine_input(class Kinect : public InputDevice { $
    float3 leftHandPosition = {0, 0, 0};
    float3 rightHandPosition = {0, 0, 0};
    bool available = false;
    constructor(Kinect())
    destructor$(Kinect())
    virtual void update();
})
godmode_engine_input$extern($_kinect, Kinect*)