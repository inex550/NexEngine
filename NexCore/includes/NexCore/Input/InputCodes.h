#ifndef __NexCore_Core_Input_InputCodes_H__
#define __NexCore_Core_Input_InputCodes_H__

namespace nex {
    enum class InputState {
        Pressed,
        Released,
    };

    enum class KeyCodes {    
        /* The unknown key */
        Unknown            = -1,

        /* Printable keys */
        Space              = 32,
        Apostrophe         = 39,  /* ' */
        Comma              = 44,  /* , */
        Minus              = 45,  /* - */
        Period             = 46,  /* . */
        Splash             = 47,  /* / */
        D0                 = 48,
        D1                 = 49,
        D2                 = 50,
        D3                 = 51,
        D4                 = 52,
        D5                 = 53,
        D6                 = 54,
        D7                 = 55,
        D8                 = 56,
        D9                 = 57,
        Semicolon          = 59,  /* ; */
        Equal              = 61,  /* = */
        A                  = 65,
        B                  = 66,
        C                  = 67,
        D                  = 68,
        E                  = 69,
        F                  = 70,
        G                  = 71,
        H                  = 72,
        I                  = 73,
        J                  = 74,
        K                  = 75,
        L                  = 76,
        M                  = 77,
        N                  = 78,
        O                  = 79,
        P                  = 80,
        Q                  = 81,
        R                  = 82,
        S                  = 83,
        T                  = 84,
        U                  = 85,
        V                  = 86,
        W                  = 87,
        X                  = 88,
        Y                  = 89,
        Z                  = 90,
        LeftBracket        = 91,  /* [ */
        Backslash          = 92,  /* \ */
        RightBracket       = 93,  /* ] */
        GraveAccent        = 96,  /* ` */
        World1             = 161, /* non-US #1 */
        World2             = 162, /* non-US #2 */

        /* Function keys */
        Escape             = 256,
        Enter              = 257,
        Tab                = 258,
        Backspace          = 259,
        Inset              = 260,
        Delete             = 261,
        Right              = 262,
        Left               = 263,
        Down               = 264,
        Up                 = 265,
        PageUp             = 266,
        PageDown           = 267,
        Home               = 268,
        End                = 269,
        CapsLock           = 280,
        ScrollLock         = 281,
        NumLock            = 282,
        PrintScreen        = 283,
        Pause              = 284,
        KeypadF1           = 290,
        KeypadF2           = 291,
        KeypadF3           = 292,
        KeypadF4           = 293,
        KeypadF5           = 294,
        KeypadF6           = 295,
        KeypadF7           = 296,
        KeypadF8           = 297,
        KeypadF9           = 298,
        KeypadF10          = 299,
        KeypadF11          = 300,
        KeypadF12          = 301,
        KeypadF13          = 302,
        KeypadF14          = 303,
        KeypadF15          = 304,
        KeypadF16          = 305,
        KeypadF17          = 306,
        KeypadF18          = 307,
        KeypadF19          = 308,
        KeypadF20          = 309,
        KeypadF21          = 310,
        KeypadF22          = 311,
        KeypadF23          = 312,
        KeypadF24          = 313,
        KeypadF25          = 314,
        Keypad0            = 320,
        Keypad1            = 321,
        Keypad2            = 322,
        Keypad3            = 323,
        Keypad4            = 324,
        Keypad5            = 325,
        Keypad6            = 326,
        Keypad7            = 327,
        Keypad8            = 328,
        Keypad9            = 329,
        KeypadDecimal      = 330,
        KeypadDivice       = 331,
        KeypadMultiply     = 332,
        KeypadSubtract     = 333,
        KeypadAdd          = 334,
        KeypadEnter        = 335,
        KeypadEqual        = 336,
        LeftShift          = 340,
        LeftControl        = 341,
        LeftAlt            = 342,
        LeftSuper          = 343,
        RightShift         = 344,
        RightControl       = 345,
        RightAlt           = 346,
        RightSuper         = 347,
        Menu               = 348,
    
        Last = Menu,
    };

    enum class MouseButtonCodes {
        Unknown         = -1,

        Button1         = 0,
        Button2         = 1,
        Button3         = 2,
        Button4         = 3,
        Button5         = 4,
        Button6         = 5,
        Button7         = 6,
        Button8         = 7,

        ButtonLeft      = Button1,
        ButtonRight     = Button2,
        ButtonMiddle    = Button3,

        ButtonLast      = Button8,
    };
}

#endif // __NexCore_Core_Input_InputCodes_H__