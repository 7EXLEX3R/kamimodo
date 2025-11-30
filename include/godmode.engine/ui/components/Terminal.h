#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/String.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/TextBox.h>
#include <godmode.engine/math/float2.h>

godmode_engine_ui_components(struct TerminalParams : virtual ContainerParams {})
godmode_engine_ui_components(class Terminal : virtual public TerminalParams, public Container { $
    TextBox* logTextBox = nullptr;
    TextBox* textBox = nullptr;
    private$(int logCounter = 0)
    constructor(Terminal(const TerminalParams& params = TerminalParams()))
    destructor$(Terminal())
    virtual void refresh();
})