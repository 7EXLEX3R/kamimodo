#pragma once
#include <godmode.foundation.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

class LLMChatSnippet : public Runtime { $ int run() override {
    Process::spawn("node main.js", "../../../samples/LLMChat/LLMChat");
    String promptUrl = $_config->get("ai.llmController.url").asString()
        + $_config->get("ai.llmController.promptRoute").asString();
    while (1) {
        std::string prompt;
        std::cout << "> ";
        std::getline(std::cin, prompt);
        std::cout << "\n";
        if (prompt == "exit")
            return 0;
        JSON params;
        params["prompt"] = prompt;
        params["chatId"] = 1;
        params["stream"] = true;
        Http::requestStreamSync(promptUrl, params, [](String chunk) {
            std::cout << chunk.replaceAll("\xEF", "\'");
        });
        std::cout << "\n";
        std::cout << "\n";
    }
}};