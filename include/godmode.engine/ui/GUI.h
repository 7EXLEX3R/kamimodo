#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/EventListener.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/String.h>
#include <godmode.engine/events/WindowCloseEvent.h>
#include <godmode.engine/logic/Refreshable.h>
#include <godmode.engine/logic/_2d/Camera2d.h>
#include <godmode.engine/logic/_2d/Scene2d.h>
#include <godmode.engine/ui/Component.h>
#include <godmode.engine/ui/LayoutSection.h>
#include <godmode.engine/ui/Window.h>

godmode_engine_ui(class GUI : public Scene2d, public Camera2d, public EventListener<WindowCloseEvent> { $
    List<Window*> windows;
    List<Component*> components;
    Window* activeWindow = nullptr;
    bool active = false;
    bool mouseIn = false;
    bool isScrollingEnabled = true;
    List<LayoutSection*> layoutSections;
    bool visible = true;
    constructor(GUI())
    destructor$(GUI())
    void updateEntities();
    Window* addWindow(Window* window);
    void removeWindow(Window* window, bool _delete = true);
    void detachEntities(Container* window);
    void attachEntities(Container* window);
    Component* addComponent(Component* component);
    void removeComponent(Component* component);
    void setVisible(bool visible = true);
    void handleEvent(WindowCloseEvent* event);
    void closeAllWindows();
})
godmode_engine_ui$extern($_gui, GUI*)