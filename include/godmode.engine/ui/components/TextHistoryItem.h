#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>

godmode_engine_ui_components(class TextHistoryItem { $
    String text;
    int writeIndex = 0;
    int selectIndex = 0;
    TextHistoryItem();
    TextHistoryItem(String text, int writeIndex, int selectIndex);
    bool operator==(TextHistoryItem thi);
})