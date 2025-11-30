#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/ui/Component.h>

godmode_engine_ui_components(struct ImageBoxParams : virtual ComponentParams {
    Texture* texture = nullptr;
});
godmode_engine_ui_components(class ImageBox : virtual public ImageBoxParams, public Component { $
    Sprite *background = nullptr;
    Text2d *t2d = nullptr;
    constructor(ImageBox(const ImageBoxParams& params = ImageBoxParams()))
    destructor$(ImageBox())
    void refresh();
})