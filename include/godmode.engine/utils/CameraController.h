#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/math/float3.h>
#include <godmode.engine/logic/_3d/Camera3d.h>
#include <godmode.engine/input/InputApi.h>

godmode_engine_utils(class CameraController { $
    static float3 control(Camera3d *camera, bool suppressMovement = false) {
        float3 direction;
        camera->rotateX(((Mouse*)(godmode::$_inputApi->devices[1]))->y * .03f, false);
        camera->rotationDest.x = Math::min(90.0f, Math::max(-90.0f, camera->rotationDest.x));
        camera->rotateY(((Mouse*)(godmode::$_inputApi->devices[1]))->x * .03f, false);
        if (godmode::$_inputApi->key(MouseButton::MIDDLE)) {
            direction -= camera->xaxis * ((Mouse*)(godmode::$_inputApi->devices[1]))->x * .003f;
            direction += camera->yaxis * ((Mouse*)(godmode::$_inputApi->devices[1]))->y * .003f;
        }
        direction += camera->zaxis * ((Mouse*)(godmode::$_inputApi->devices[1]))->z * .003f;
        if (godmode::$_inputApi->key(Key::A))
            direction -= camera->xaxis;
        if (godmode::$_inputApi->key(Key::D))
            direction += camera->xaxis;
        if (godmode::$_inputApi->key(Key::W))
            direction += camera->zaxis;
        if (godmode::$_inputApi->key(Key::S))
            direction -= camera->zaxis;
        if (godmode::$_inputApi->key(Key::Q))
            direction += camera->yaxis;
        if (godmode::$_inputApi->key(Key::E))
            direction -= camera->yaxis;
        float3 finalDirection = direction * 10.0f * (godmode::$_inputApi->key(Key::LSHIFT) ? 5.0 : 1);
        if (!suppressMovement)
            camera->move(finalDirection);
        return finalDirection;
    }
})