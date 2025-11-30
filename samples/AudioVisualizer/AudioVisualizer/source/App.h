#pragma once
#include <godmode.foundation.h>
#include <godmode.engine.h>

//  kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____
//
//  kamimodo SDK™ - AudioVisualizer
//  - plays the "ç ç ç.mp3" sound file (toggle on/off by pressing the V key)
//  - analyzes the played sound + the system audio output's EQ bands
//  - visually processes the EQ analysis inside swirl.fx effect script file
//  - combines that with the scene's 16 skull objects representing each EQ band
//  - allows changing colorblindness effect type value by pressing Z / X
//  - allows toggling the experimentalColors flag of swirl.fx by pressing C
//      experimentalColors mode uses a randomized 3D vector value; each time EQ band values
//      drop below a certain threshold, the swirl's vector value gets randomized
//
//  # press X to cycle through colorblindness modes — it changes visually a lot
//  # press V twice in a short interval to toggle playback — fastest way to apply changes
//  # when playback is off, play some other stuff on Spotify / YouTube / ...
//  # press C to toggle experimentalColors mode for the base color scheme
//
//  レ  ク  サ  ー

typedef class AudioVisualizerSample : public EngineRuntime {
public:
    Scene3d* scene = nullptr;
    Camera3d* camera = nullptr;
	List<Object3d*> skulls;
    Sound* sound = nullptr;
    Shader* swirl = nullptr;
    bool experimentalColors = false;
	constructor(AudioVisualizerSample() : EngineRuntime() {
		this->initSceneBasics();
        this->initSceneEffects();
        this->initAudio();
	})
    void initSceneBasics() {
        this->scene = godmode::$_sceneManager->addScene3d();
        this->scene->addCamera(this->camera = new$(Camera3d,
            _.position = { 15, 12, -25 };
            _.displaySize = { 36, 36 };
            _.orthographic = true;
        ));
        this->scene->addEntity(godmode::$_entityFactory->createObject3d(params$(Object3d,
            _.model = this->scene->content->addModel("models/skybox/skybox.x");
            _.shader = this->scene->content->addShader("shaders/fixed-skybox.fx");
            _.scale = { .1, .1, .1 };
        )));
        for (int i = 0; i < 16; i++)
            this->scene->addEntity(this->skulls.add(godmode::$_entityFactory->createObject3d(params$(Object3d,
                _.model = this->scene->content->addModel("models/skull/skull.x");
                _.position = { i * 2, 0, 0 };
            ))).back());
    }
    void initSceneEffects() {
        this->swirl = this->scene->content->addShader("shaders/swirl.fx");
        this->swirl->injectBool("experimentalColors", this->experimentalColors);
        this->scene->effects->registry.unshift(new Effect(this->swirl));
        this->scene->effects->registry.add(new Effect(this->scene->content->addShader("shaders/merge-normals.fx")));
        this->scene->effects->registry.add(new EdgeDetect(JSON::from(R"({"intensity": 2})")));
    }
    void initAudio() {
        $_soundApi->mixer->master->link(
            $_soundApi->sampler->addSample(
                this->sound = new Sound("sounds/ç ç ç.mp3")));
        this->sound->play();
    }
    void update() override {
        this->handleKeyboardInput();
        this->syncSkulls();
        this->handleSwirlExperimentalColors();
    }
    void handleKeyboardInput() {
        if (godmode::$_inputApi->keyDown(Key::Z)) this->changeColorBlindnessType(-1);
        if (godmode::$_inputApi->keyDown(Key::X)) this->changeColorBlindnessType(1);
        if (godmode::$_inputApi->keyDown(Key::V)) this->togglePlayback();
        if (godmode::$_inputApi->keyDown(Key::C)) this->toggleExperimentalColors();
    }
    void changeColorBlindnessType(int value = -1) {
        static int colorBlindnessType = ColorblindnessType::ACHROMATOPSIA;
        colorBlindnessType += value;
        if (colorBlindnessType > 8)
            colorBlindnessType = 0;
        if (colorBlindnessType < 0)
            colorBlindnessType = 8;
        this->scene->effects->colorBlindnessEffects[0]->setColorBlindnessType((ColorblindnessType)colorBlindnessType);
    }
    void togglePlayback() {
        this->sound->isPlaying() ? this->sound->stop() : this->sound->play();
    }
    void toggleExperimentalColors() {
        this->swirl->injectBool("experimentalColors", this->experimentalColors = !this->experimentalColors);
	}
    void syncSkulls() {
        for (int i = 0; i < $_soundApi->mixer->master->bands.length(); i++) {
            this->skulls[i]->setPositionY($_soundApi->mixer->master->bands[i] * 10.0f);
            this->skulls[i]->setScale(f3($_soundApi->mixer->master->bands[i]) * 2.7);
        }
    }
    void handleSwirlExperimentalColors() {
        static float3 swirlCrossVector = { 1,1,1 };
        static float3 swirlCrossVectorDest = { 1,1,1 };
        static bool randomizeCrossVector = false;
        static float lastBandsSum = 0;
        float bandsSum = $_soundApi->mixer->master->bands.reduce<float>(function$((float a, float item), a + item), 0);
        if (lastBandsSum < 3.0 && bandsSum > 3.0)
            randomizeCrossVector = true;
        if (randomizeCrossVector) {
            randomizeCrossVector = false;
            swirlCrossVectorDest = float3(Math::random(-1, 1), Math::random(-1, 1), Math::random(-1, 1));
        }
        lastBandsSum = bandsSum;
        swirlCrossVector += Math::transition<float3>(swirlCrossVector, swirlCrossVectorDest, 16, true);
        this->swirl->injectFloatList("bands", $_soundApi->mixer->master->bands);
        this->swirl->injectFloat3("swirlCrossVector", swirlCrossVector);
    }
} App;