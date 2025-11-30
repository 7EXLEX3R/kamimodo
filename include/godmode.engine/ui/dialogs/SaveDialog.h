#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.engine/ui/Window.h>
#include <godmode.engine/ui/components/Button.h>
#include <godmode.engine/ui/components/ComboBox.h>
#include <godmode.engine/ui/components/ListBox.h>
#include <godmode.engine/ui/components/TextBox.h>

godmode_engine_ui_dialogs(class SaveDialog : public Window { $
    ComboBox *locationComboBox = nullptr;
    ListBox *contentBrowserListBox = nullptr;
    TextBox *destinationPathTextBox = nullptr;
    TextBox *fileNameTextBox = nullptr;
    Button *saveButton = nullptr;
    Button *createNewDirectoryButton = nullptr;
    String objectToSaveFileName;
    ContentItem *objectToSave = nullptr;
    void (*callback)(void *context, String filePath) = nullptr;
    void *context = nullptr;
    constructor(SaveDialog(
        ContentItem *objectToSave,
        void (*callback)(void *context, String filePath) = nullptr,
        void *context = nullptr,
        String objectToSaveFileName = "",
        String dialogName = ""))
    destructor$(SaveDialog())
    void whenActive();
    MappedList<String, void *> getContentListItems(String directoryPath);
    private$(String activeLocationPath)
    private$(void setActiveLocationPath(String activeLocationPath))
    private$(void saveFile())
})