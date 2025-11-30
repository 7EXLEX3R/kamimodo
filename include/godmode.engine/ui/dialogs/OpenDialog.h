#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.engine/ui/Window.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/ComboBox.h>
#include <godmode.engine/ui/components/ListBox.h>
#include <godmode.engine/ui/components/TextBox.h>

godmode_engine_ui_dialogs(class OpenDialog : public Window { $
    ComboBox *locationComboBox = nullptr;
    ListBox *contentBrowserListBox = nullptr;
    TextBox *destinationPathTextBox = nullptr;
    TextBox *fileNameTextBox = nullptr;
    Button *openButton = nullptr;
    Button *createNewDirectoryButton = nullptr;
    MappedList<String, void *> getContentListItems(String directoryPath);
    void (*callback)(void *context, String filePath) = nullptr;
    void *context = nullptr;
    constructor(OpenDialog(void (*callback)(void *context, String filePath) = nullptr, void *context = nullptr, String dialogName = ""))
    destructor$(OpenDialog())
    void whenActive();
    private$(String activeLocationPath)
    private$(void setActiveLocationPath(String activeLocationPath))
    private$(void openFile())
})