#pragma once
#include <godmode.engine.directx/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/entity/_2d/Sprite.h>

godmode_engine_directx_entity__2d(class DxSprite : public Sprite { $
    LPDIRECT3DVERTEXBUFFER9 vb = nullptr;
    LPDIRECT3DINDEXBUFFER9 ib = nullptr;
    constructor(DxSprite(const SpriteParams& params = SpriteParams()))
    destructor$(DxSprite())
    void render();
    void recreate();
    void createVertexBuffer();
    void createIndexBuffer();
    s11n$declareSplit()
})
s11n$export(DxSprite);