#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/graphics/Material.h>
#include <godmode.engine/graphics/Shader.h>
#include <godmode.engine/graphics/Texture.h>
#include <godmode.engine/logic/LogicEntity.h>
#include <godmode.foundation/types/JsonRepresentable.h>

godmode_engine_graphics(struct GraphicsEntityParams {
    Shader* shader = nullptr;
    bool visible = true;
    bool wireframe = false;
    bool translucent = false;
    bool shadowable = true;
    bool shadowcaster = true;
    int blendSrc = 0;
    int blendDest = 0;
    int blendOp = 0;
    float4 color = float4(1, 1, 1, 1);
    float4 secondaryColor = float4(1, 1, 1, 1);
    float colorTransition = 1;
    float secondaryColorTransition = 1;
    float4 scissorRect = float4(0, 0, 0, 0);
    bool scissorRectEnabled = false;
    void* extraData = nullptr;
})
godmode_engine_graphics(class GraphicsEntity : virtual public GraphicsEntityParams, public JsonRepresentable { $
    bool frustumVisibility;
    bool occlusionVisibility;
    bool visibility;
    List<Material *> materials;
    float4 colorLast, colorDest;
    float4 secondaryColor, secondaryColorLast, secondaryColorDest;
    ShaderParameters parameters;
    constructor(GraphicsEntity(const GraphicsEntityParams& params = GraphicsEntityParams()))
    destructor$(GraphicsEntity())
    virtual void render() {};
    virtual void renderBoundingParams() {};
    virtual void setColor(const float4 &color, bool immediately = true);
    virtual void setSecondaryColor(const float4 &color, bool immediately = true);
    virtual void createVertexBuffer();
    virtual void createIndexBuffer();
    virtual void recreate();
    virtual void setShader(Shader *shader);
    Shader *getShader();
    GraphicsEntity *withShader(Shader *shader);
    virtual void fromJson(JSON json);
    virtual JSON toJson();
    virtual void updateGraphics();
   s11n$declare()
})