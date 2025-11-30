#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/entity/_2d/Line2d.h>
#include <godmode.engine/entity/_2d/Sprite.h>
#include <godmode.engine/entity/_2d/Text2d.h>
#include <godmode.engine/math/float2.h>
#include <godmode.engine/ui/components/Container.h>
#include <godmode.engine/ui/components/TextHistoryItem.h>

godmode_engine_ui_components(struct TextBoxParams : virtual ContainerParams {
    String value = "";
    int minWriteIndex = 0;
    bool readonly = false;
    bool multiline = false;
})
#define TextBoxParams_$(params) TextBoxParams(params), ContainerParams_$(params)
godmode_engine_ui_components(class TextBox : virtual public TextBoxParams, public Container { $
    Text2d *t2d = nullptr;
    List<Sprite *> selectionSprites;
    Line2d *textCursor = nullptr;
    Line2d *selectCursor = nullptr;
    String charset;
    List<TextHistoryItem> history;
    int historyIndex = 0;
    private$(int columnIndex = 0)
    private$(int writeIndex = 0)
    private$(int writeIndexX = 0)
    private$(int writeIndexY = 0)
    private$(int selectIndex = 0)
    private$(int selectIndexX = 0)
    private$(int selectIndexY = 0)
    private$(Sprite* background)
    private$(double lastActionTimestamp = 0)
    constructor(TextBox(const TextBoxParams& params = TextBoxParams()))
    destructor$(TextBox())
    virtual void whenActive();
    virtual void onActivate();
    virtual void onInactivate();
    virtual void onClick();
    virtual void whenPushed();
    virtual void onDoubleClick();
    virtual void onMouseEnter();
    virtual void onMouseLeave();
    virtual void refresh();
    void applyJsonValueBindingToValue();
    void setValue(String value, int writeIndexReplacement = 0, bool historyAppend = true);
    void setWriteIndex(int writeIndex = -1);
    String getValue();
    void clearHistory();
    private$(bool textCursorMovement())
    private$(List<String> textLines)
    private$(void calculateTextCursorPosition())
    private$(float2 calculateIndexPosition(int index))
    private$(void calculateSelection(bool keepSelectIndex = true))
    private$(float2 getXYByIndex(int index))
    private$(int getIndexByXY(int x, int y))
    private$(void updateIndexByXY())
    private$(void updateXYByIndex())
    private$(void updateSelectionSprites())
    private$(void initBackground())
})