#pragma once
#include <godmode.engine/$_namespaces.h>

#include <godmode.engine/graphics/effects/ASCII.h>
#include <godmode.engine/graphics/effects/Bloom.h>
#include <godmode.engine/graphics/effects/Blur.h>
#include <godmode.engine/graphics/effects/ColorAdjust.h>
#include <godmode.engine/graphics/effects/Colorblindness.h>
#include <godmode.engine/graphics/effects/DepthOfField.h>
#include <godmode.engine/graphics/effects/EdgeDetect.h>
#include <godmode.engine/graphics/effects/Fog.h>
#include <godmode.engine/graphics/effects/Grain.h>
#include <godmode.engine/graphics/effects/Grayscale.h>
#include <godmode.engine/graphics/effects/HaloLensFlare.h>
#include <godmode.engine/graphics/effects/HighDynamicRange.h>
#include <godmode.engine/graphics/effects/LightShafts.h>
#include <godmode.engine/graphics/effects/MotionBlur.h>
#include <godmode.engine/graphics/effects/SSAO.h>
#include <godmode.engine/graphics/effects/SSR.h>
#include <godmode.engine/graphics/effects/Sepia.h>
#include <godmode.engine/graphics/effects/Sharpen.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/system/Config.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/Map.h>

godmode_engine_graphics(class Effects { $
    List<Effect*> registry;
    List<Effect*> unknownEffects;
    List<ASCII*> asciiEffects;
    List<Bloom*> bloomEffects;
    List<Blur*> blurEffects;
    List<ColorAdjust*> colorAdjustEffects;
    List<ColorBlindness*> colorBlindnessEffects;
    List<DepthOfField*> depthOfFieldEffects;
    List<EdgeDetect*> edgeDetectEffects;
    List<Fog*> fogEffects;
    List<Grain*> grainEffects;
    List<GrayScale*> grayScaleEffects;
    List<HaloLensFlare*> haloLensFlareEffects;
    List<HighDynamicRange*> highDynamicRangeEffects;
    List<LightShafts*> lightShaftsEffects;
    List<MotionBlur*> motionBlurEffects;
    List<Sepia*> sepiaEffects;
    List<Sharpen*> sharpenEffects;
    List<SSAO*> ssaoEffects;
    List<SSR*> ssrEffects;
    constructor(Effects())
    destructor$(Effects())
    void sort(List<String> sortOrder = $_config->get("effects.$order").asStringList());
    void process();
    static Effect* cloneEffect(Effect* effect);
    s11n$declare()
})
godmode_engine_graphics$extern($_effects, Effects*)
s11n$export(Effects);