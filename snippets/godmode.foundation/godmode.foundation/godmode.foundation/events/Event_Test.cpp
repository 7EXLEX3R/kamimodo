#ifdef test$
#include <godmode.foundation/test/Test.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/events/Events.h>
#include <godmode.foundation/events/Event.h>
#include "Event_Test.h"

test$class(Event,
    test$method(playground) {
        ClickEventListener *clickEventListener = new ClickEventListener();
        new ClickEvent(true);
        new XEvent(555);
        $_events->update();
        expect(clickEventListener->counter == 1);
        XEventListener* xEventListener = new XEventListener();
        $_events->update();
        expect(clickEventListener->counter == 1);
        expect(xEventListener->counter == 0);
        new XEvent(555);
        $_events->update();
        expect(clickEventListener->counter == 1);
        expect(xEventListener->counter == 1);
    }
)
#endif