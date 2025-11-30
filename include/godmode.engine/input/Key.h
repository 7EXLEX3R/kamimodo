#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/Enum.h>

godmode_engine_input(enum$$(Key) enum$items(Key,
    NONE,
    ESCAPE,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _0,
    MINUS,
    EQUALS,
    BACK,
    TAB,
    Q,
    W,
    E,
    R,
    T,
    Y,
    U,
    I,
    O,
    P,
    LBRACKET,
    RBRACKET,
    RETURN,
    LCONTROL,
    A,
    S,
    D,
    F,
    G,
    H,
    J,
    K,
    L,
    SEMICOLON,
    APOSTROPHE,
    GRAVE,
    LSHIFT,
    BACKSLASH,
    Z,
    X,
    C,
    V,
    B,
    N,
    M,
    COMMA,
    PERIOD,
    SLASH,
    RSHIFT,
    MULTIPLY,
    LMENU,
    SPACE,
    CAPITAL
) enum$items(Key,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    NUMLOCK,
    SCROLL,
    NUMPAD7,
    NUMPAD8,
    NUMPAD9,
    SUBTRACT,
    NUMPAD4,
    NUMPAD5,
    NUMPAD6,
    ADD,
    NUMPAD1,
    NUMPAD2,
    NUMPAD3,
    NUMPAD0,
    DECIMAL,
    OEM_102,
    F11,
    F12,
    F13,
    F14,
    F15,
    KANA,
    ABNT_C1,
    CONVERT,
    NOCONVERT,
    YEN,
    ABNT_C2,
    NUMPADEQUALS,
    PREVTRACK,
    AT,
    COLON,
    UNDERLINE,
    KANJI,
    STOP,
    AX,
    UNLABELED,
    NEXTTRACK,
    NUMPADENTER,
    RCONTROL,
    MUTE,
    CALCULATOR,
    PLAYPAUSE,
    MEDIASTOP,
    VOLUMEDOWN,
    VOLUMEUP,
    WEBHOME,
    NUMPADCOMMA,
    DIVIDE,
    SYSRQ,
    RMENU,
    PAUSE,
    HOME
) enum$items(Key,
    UP,
    PRIOR,
    LEFT,
    RIGHT,
    END,
    DOWN,
    NEXT,
    INSERT,
    DEL3TE,
    LWIN,
    RWIN,
    APPS,
    POWER,
    SLEEP,
    WAKE,
    WEBSEARCH,
    WEBFAVORITES,
    WEBREFRESH,
    WEBSTOP,
    WEBFORWARD,
    WEBBACK,
    MYCOMPUTER,
    MAIL,
    MEDIASELECT,
    BACKSPACE,
    NUMPADSTAR,
    LALT,
    CAPSLOCK,
    NUMPADMINUS,
    NUMPADPLUS,
    NUMPADPERIOD,
    NUMPADSLASH,
    RALT,
    UPARROW,
    PGUP,
    LEFTARROW,
    RIGHTARROW,
    DOWNARROW,
    PGDN)
    String toString(bool shift) const;
    static String toString(const Key& key, bool shift);
enum$$$)

// MINUS, // - on main keyboard
// BACK, // backspace
// RETURN, // Enter on main keyboard
// GRAVE,  // accent grave
// PERIOD,  // . on main keyboard
// SLASH,  // / on main keyboard
// MULTIPLY,  // * on numeric keypad
// LMENU,  // left Alt
// SCROLL,  // Scroll Lock
// SUBTRACT,  // - on numeric keypad
// ADD,  // + on numeric keypad
// DECIMAL,  // . on numeric keypad
// OEM_102,  // <> or \| on RT 102-key keyboard (Non-U.S.)
// F13,  // (NEC PC98)
// F14,  // (NEC PC98)
// F15,  // (NEC PC98)
// KANA,  // (Japanese keyboard)
// ABNT_C1,  // /? on Brazilian keyboard
// CONVERT,  // (Japanese keyboard)
// NOCONVERT,  // (Japanese keyboard)
// YEN,  // (Japanese keyboard)
// ABNT_C2,  // Numpad . on Brazilian keyboard
// NUMPADEQUALS,  // = on numeric keypad (NEC PC98)
// PREVTRACK,  // Previous Track (= CIRCUMFLEX on Japanese keyboard)
// AT,  // (NEC PC98)
// COLON,  // (NEC PC98)
// UNDERLINE,  // (NEC PC98)
// KANJI,  // (Japanese keyboard)
// STOP,  // (NEC PC98)
// AX,  // (Japan AX)
// UNLABELED,  // (J3100)
// NEXTTRACK,  // Next Track
// NUMPADENTER,  // Enter on numeric keypad
// MUTE,  // Mute
// CALCULATOR,  // Calculator
// PLAYPAUSE,  // Play / Pause
// MEDIASTOP,  // Media Stop
// VOLUMEDOWN,  // Volume -
// VOLUMEUP,  // Volume +
// WEBHOME,  // Web home
// NUMPADCOMMA,  // , on numeric keypad (NEC PC98)
// DIVIDE,  // / on numeric keypad
// RMENU,  // right Alt
// PAUSE,  // Pause
// HOME,  // Home on arrow keypad
// UP,  // UpArrow on arrow keypad
// PRIOR,  // PgUp on arrow keypad
// LEFT,  // LeftArrow on arrow keypad
// RIGHT,  // RightArrow on arrow keypad
// END,  // End on arrow keypad
// DOWN,  // DownArrow on arrow keypad
// NEXT,  // PgDn on arrow keypad
// INSERT,  // Insert on arrow keypad
// DEL3TE,  // Delete on arrow keypad (renamed to avoid macro clash)
// LWIN,  // Left Windows key
// RWIN,  // Right Windows key
// APPS,  // AppMenu key
// POWER,  // System Power
// SLEEP,  // System Sleep
// WAKE,  // System Wake
// WEBSEARCH,  // Web Search
// WEBFAVORITES,  // Web Favorites
// WEBREFRESH,  // Web Refresh
// WEBSTOP,  // Web Stop
// WEBFORWARD,  // Web Forward
// WEBBACK,  // Web Back
// MYCOMPUTER,  // My Computer
// MAIL,  // Mail
// MEDIASELECT,  // Media Select
// BACKSPACE,  // = BACK
// NUMPADSTAR,  // = MULTIPLY
// LALT,  // = LMENU
// CAPSLOCK,  // = CAPITAL
// NUMPADMINUS,  // = SUBTRACT
// NUMPADPLUS,  // = ADD
// NUMPADPERIOD,  // = DECIMAL
// NUMPADSLASH,  // = DIVIDE
// RALT,  // = RMENU
// UPARROW,  // = UP
// PGUP,  // = PRIOR
// LEFTARROW,  // = LEFT
// RIGHTARROW,  // = RIGHT
// DOWNARROW,  // = DOWN
// PGDN  // = NEXT