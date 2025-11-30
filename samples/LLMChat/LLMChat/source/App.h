#pragma once
#include <godmode.foundation.h>
#include <godmode.engine.h>

//  kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____
//
//  kamimodo SDK™ - LLMChat - Ollama integration via HTTP protocol example
//  - runs a background Node.js process using main.js script responsible for being a proxy between Ollama and the application
//  - gives the user a possibility to prompt LLM via a textbox attached to the app's GUI
//  - supports chat history on the Node.js app level
//  - uses config/ai.json configuration for connection establishment
//  - interprets Ollama output looking for 3-digit occurrences — when detected, passes them as background-color multiplier,
//    showing in a simple way a possible influence of the LLM on what’s being displayed
//
//  # possible to run both Ollama and this sample on a local machine, but such config could pretty badly affect performance;
//    best way is to run Ollama on a separate machine if possible, or deploy a Docker with Ollama on some pod
//    and connect to it; for this case check: https://github.com/7EXLEX3R/ollama_999
//  # configure config/ai.json's "ollama.url" property accordingly to your Ollama endpoint
//
//  レ  ク  サ  ー

#include "BackgroundScene.h"

typedef class LLMChatSample : public EngineRuntime { $
    TextBox* chatBox = nullptr;
    TextBox* inputBox = nullptr;
    float windowBoxSize = 640;
    float chatSize = windowBoxSize * 7 / 8;
    float inputSize = windowBoxSize * 1 / 8;
    String pendingIndicator = "...";
    bool pending = false;
    bool streaming = false;
    bool unloadingBuffer = false;
    String buffer;
    List<String>* chunks = new List<String>();
    BackgroundScene* backgroundScene = nullptr;
    LLMChatSample() : EngineRuntime() {
        $_gui->addComponent(this->chatBox = new$(TextBox,
            _.size = float2(windowBoxSize, chatSize);
            _.readonly = true;
        ));
        $_gui->addComponent(this->inputBox = new$(TextBox,
            _.position = float2(0, 0);
            _.size = float2(windowBoxSize, inputSize);
            _.value = " > ";
            _.minWriteIndex = 3;
        ));
        Process::spawn("node ../LLMChat/main.js");
        this->backgroundScene = new BackgroundScene();
	}
    ~LLMChatSample() {
        delete this->backgroundScene;
        delete this->chunks;
    }
    void update$active() override {
        this->handleUserInput();
        this->controlAppTermination();
    }
    void handleUserInput() {
        this->inputBox->setActive(!this->pending);
        if (godmode::$_inputApi->keyDown(Key::RETURN) && !this->pending && !this->streaming && !this->unloadingBuffer) {
            this->pending = true;
            safe$(this->chatBox->verticalScroll, scrollMax());
            this->chatBox->setValue(
                this->chatBox->getValue()
                + (this->chatBox->getValue().length() ? "\n\n" : "")
                + this->inputBox->getValue() + "\n\n"
            );
            godmode::$_llm->promptStream(this->inputBox->getValue().substring(this->inputBox->minWriteIndex), [&](String chunk) {
                this->chunks->add(chunk);
                this->pending = false;
                this->streaming = true;
            })->then([&](String message) {
                this->streaming = false;
                this->lookUpFor3Digits(message);
            });
            this->inputBox->setValue("> ");
            this->inputBox->setWriteIndex(2);
            this->inputBox->minWriteIndex = 2;
        }
    }
    void lookUpFor3Digits(String message) {
        float3 digits = {0, 0, 0};
        for (int i = 0; i < message.length(); i++)
            if (message.at(i) >= '0' && message.at(i) <= '9') {
                float value = int(message.at(i)) - 48;
                if (digits.x == 0) digits.x = value;
                else if (digits.y == 0) digits.y = value;
                else if (digits.z == 0) digits.z = value;
            }
        if (digits.x != 0) {
            console->log(digits);
            this->backgroundScene->postEffectColorMultiplierDest = digits;
        }
    }
    void controlAppTermination() {
        if (godmode::$_inputApi->key(Key::LALT) && godmode::$_inputApi->key(Key::Q))
            this->terminate();
    }
    void update() override {
        float textHeight = Math::min(this->chatBox->t2d->getValueTextSize().y, chatSize);
        this->inputBox->setPosition(float2(0, -(textHeight > 0 ? textHeight + 13: 0)));
        this->inputBox->setVisible(!this->pending);
        this->inputBox->setActive(false);
        this->handlePendingIndicator();
        this->handleReceivedChunks();
        this->backgroundScene->update();
    }
    void handlePendingIndicator() {
        static bool indicatorVisible = false;
        if (this->pending) {
            bool evenSecond = int($_fpsMeter->getTime()*2.0) % 2 == 0;
            if (evenSecond && !indicatorVisible) {
                this->chatBox->setValue(this->chatBox->value + this->pendingIndicator);
                indicatorVisible = true;
            } else if (!evenSecond && indicatorVisible) {
                this->chatBox->setValue(this->chatBox->getValue().substringTo(this->chatBox->getValue().length() - 3));
                indicatorVisible = false;
            }
        } else if (indicatorVisible) {
            this->chatBox->setValue(this->chatBox->getValue().substringTo(this->chatBox->getValue().length() - 3));
            indicatorVisible = false;
        }
    }
    void handleReceivedChunks() {
        if (this->chunks->length()) {
            this->buffer += chunks->join();
            this->chunks->clear();
        }
        if (this->buffer.length()) {
            String currentText = this->chatBox->getValue();
            if (this->unloadingBuffer)
                currentText = currentText.substringTo(currentText.length() - this->pendingIndicator.length());
            this->chatBox->setValue(currentText + String(buffer.at(0)) + this->pendingIndicator);
            this->buffer = this->buffer.substring(1);
            this->unloadingBuffer = !!this->buffer.length();
            if (!this->unloadingBuffer)
                this->chatBox->setValue(this->chatBox->getValue().substringTo(this->chatBox->getValue().length() - this->pendingIndicator.length()));
        }
    }
} App;