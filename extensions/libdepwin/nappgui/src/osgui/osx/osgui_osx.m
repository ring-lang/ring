/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui_osx.m
 *
 */

/* Operating system native gui */

#include "osgui_osx.inl"
#include "oscontrol_osx.inl"
#include "osgui.inl"
#include "osglobals.inl"
#include "oscomwin.inl"
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

NSNumber *kUNDERLINE_STYLE_NONE = nil;
NSNumber *kUNDERLINE_STYLE_SINGLE = nil;
NSMutableParagraphStyle *kLEFT_PARAGRAPH_STYLE = nil;
NSMutableParagraphStyle *kCENTER_PARAGRAPH_STYLE = nil;
NSMutableParagraphStyle *kRIGHT_PARAGRAPH_STYLE = nil;
static NSMenu *kEMPTY_MENUBAR = nil;

/*---------------------------------------------------------------------------*/

static const unsigned short i_kVIRTUAL_KEY[] =
    {
        UINT16_MAX, /* ekKEY_UNDEF      = 0 */
        kVK_ANSI_A, /* ekKEY_A          = 1 */
        kVK_ANSI_S, /* ekKEY_S          = 2 */
        kVK_ANSI_D, /* ekKEY_D          = 3 */
        kVK_ANSI_F, /* ekKEY_F          = 4 */
        kVK_ANSI_H, /* ekKEY_H          = 5 */
        kVK_ANSI_G, /* ekKEY_G          = 6 */
        kVK_ANSI_Z, /* ekKEY_Z          = 7 */
        kVK_ANSI_X, /* ekKEY_X          = 8 */
        kVK_ANSI_C, /* ekKEY_C          = 9 */

        kVK_ANSI_V, /* ekKEY_V          = 10 */
        0xA,        /* ekKEY_BSLASH     = 11 */
        kVK_ANSI_B, /* ekKEY_B          = 12 */
        kVK_ANSI_Q, /* ekKEY_Q          = 13 */
        kVK_ANSI_W, /* ekKEY_W          = 14 */
        kVK_ANSI_E, /* ekKEY_E          = 15 */
        kVK_ANSI_R, /* ekKEY_R          = 16 */
        kVK_ANSI_Y, /* ekKEY_Y          = 17 */
        kVK_ANSI_T, /* ekKEY_T          = 18 */
        kVK_ANSI_1, /* ekKEY_1          = 19 */

        kVK_ANSI_2,         /* ekKEY_2          = 20 */
        kVK_ANSI_3,         /* ekKEY_3          = 21 */
        kVK_ANSI_4,         /* ekKEY_4          = 22 */
        kVK_ANSI_6,         /* ekKEY_6          = 23 */
        kVK_ANSI_5,         /* ekKEY_5          = 24 */
        kVK_ANSI_9,         /* ekKEY_9          = 25 */
        kVK_ANSI_7,         /* ekKEY_7          = 26 */
        kVK_ANSI_8,         /* ekKEY_8          = 27 */
        kVK_ANSI_0,         /* ekKEY_0          = 28 */
        kVK_ANSI_Backslash, /* ekKEY_RCURLY     = 29 */

        kVK_ANSI_O,     /* ekKEY_O          = 30 */
        kVK_ANSI_U,     /* ekKEY_U          = 31 */
        kVK_ANSI_Quote, /* ekKEY_LCURLY     = 32 */
        kVK_ANSI_I,     /* ekKEY_I          = 33 */
        kVK_ANSI_P,     /* ekKEY_P          = 34 */
        kVK_Return,     /* ekKEY_RETURN     = 35 */
        kVK_ANSI_L,     /* ekKEY_L          = 36 */
        kVK_ANSI_J,     /* ekKEY_J          = 37 */
        10000,          /* ekKEY_SEMICOLON  = 38 */
        kVK_ANSI_K,     /* ekKEY_K          = 39 */

        kVK_ANSI_Minus,  /* ekKEY_QUEST      = 40 */
        kVK_ANSI_Comma,  /* ekKEY_COMMA      = 41 */
        kVK_ANSI_Slash,  /* ekKEY_MINUS      = 42 */
        kVK_ANSI_N,      /* ekKEY_N          = 43 */
        kVK_ANSI_M,      /* ekKEY_M          = 44 */
        kVK_ANSI_Period, /* ekKEY_PERIOD     = 45 */
        kVK_Tab,         /* ekKEY_TAB        = 46 */
        kVK_Space,       /* ekKEY_SPACE      = 47 */
        kVK_ANSI_Grave,  /* ekKEY_GTLT       = 48 */
        kVK_Delete,      /* ekKEY_BACK       = 49 */

        kVK_Escape,              /* ekKEY_ESCAPE     = 50 */
        kVK_F17,                 /* ekKEY_F17        = 51 */
        kVK_ANSI_KeypadDecimal,  /* ekKEY_NUMDECIMAL = 52 */
        kVK_ANSI_KeypadMultiply, /* ekKEY_NUMMULT    = 53 */
        kVK_ANSI_KeypadPlus,     /* ekKEY_NUMADD     = 54 */
        kVK_ANSI_KeypadClear,    /* ekKEY_NUMLOCK    = 55 */
        kVK_ANSI_KeypadDivide,   /* ekKEY_NUMDIV     = 56 */
        kVK_ANSI_KeypadEnter,    /* ekKEY_NUMRET     = 57 */
        kVK_ANSI_KeypadMinus,    /* ekKEY_NUMMINUS   = 58 */
        kVK_F18,                 /* ekKEY_F18        = 59 */

        kVK_F19,               /* ekKEY_F19        = 60 */
        kVK_ANSI_KeypadEquals, /* ekKEY_NUMEQUAL   = 61 */
        kVK_ANSI_Keypad0,      /* ekKEY_NUM0       = 62 */
        kVK_ANSI_Keypad1,      /* ekKEY_NUM1       = 63 */
        kVK_ANSI_Keypad2,      /* ekKEY_NUM2       = 64 */
        kVK_ANSI_Keypad3,      /* ekKEY_NUM3       = 65 */
        kVK_ANSI_Keypad4,      /* ekKEY_NUM4       = 66 */
        kVK_ANSI_Keypad5,      /* ekKEY_NUM5       = 67 */
        kVK_ANSI_Keypad6,      /* ekKEY_NUM6       = 68 */
        kVK_ANSI_Keypad7,      /* ekKEY_NUM7       = 69 */

        kVK_ANSI_Keypad8, /* ekKEY_NUM8       = 70 */
        kVK_ANSI_Keypad9, /* ekKEY_NUM9       = 71 */
        kVK_F5,           /* ekKEY_F5         = 72 */
        kVK_F6,           /* ekKEY_F6         = 73 */
        kVK_F7,           /* ekKEY_F7         = 74 */
        kVK_F3,           /* ekKEY_F3         = 75 */
        kVK_F8,           /* ekKEY_F8         = 76 */
        kVK_F9,           /* ekKEY_F9         = 77 */
        kVK_F11,          /* ekKEY_F11        = 78 */
        kVK_F13,          /* ekKEY_F13        = 79 */

        kVK_F16,           /* ekKEY_F16        = 80 */
        kVK_F14,           /* ekKEY_F14        = 81 */
        kVK_F10,           /* ekKEY_F10        = 82 */
        kVK_F12,           /* ekKEY_F12        = 83 */
        kVK_F15,           /* ekKEY_F15        = 84 */
        kVK_PageUp,        /* ekKEY_PAGEUP     = 85 */
        kVK_Home,          /* ekKEY_HOME       = 86 */
        kVK_ForwardDelete, /* ekKEY_SUPR       = 87 */
        kVK_F4,            /* ekKEY_F4         = 88 */
        kVK_PageDown,      /* ekKEY_PAGEDOWN   = 89 */

        kVK_F2,           /* ekKEY_F2         = 90 */
        kVK_End,          /* ekKEY_END        = 91 */
        kVK_F1,           /* ekKEY_F1         = 92 */
        kVK_LeftArrow,    /* ekKEY_LEFT       = 93 */
        kVK_RightArrow,   /* ekKEY_RIGHT      = 94 */
        kVK_DownArrow,    /* ekKEY_DOWN       = 95 */
        kVK_UpArrow,      /* ekKEY_UP         = 96 */
        kVK_Shift,        /* ekKEY_LSHIFT     = 97 */
        kVK_RightShift,   /* ekKEY_RSHIFT     = 98 */
        kVK_Control,      /* ekKEY_LCTRL      = 99 */
        kVK_RightControl, /* ekKEY_RCTRL      = 100 */

        kVK_Option,           /* ekKEY_LALT       = 101 */
        kVK_RightOption,      /* ekKEY_RALT       = 102 */
        kVK_Help,             /* ekKEY_INSERT     = 103 */
        kVK_ANSI_Equal,       /* ekKEY_EXCLAM     = 104 */
        0x6E,                 /* ekKEY_MENU       = 105 */
        kVK_Command,          /* ekKEY_LWIN       = 106 */
        kVK_RightCommand,     /* ekKEY_RWIN       = 107 */
        kVK_CapsLock,         /* ekKEY_CAPS       = 108 */
        kVK_ANSI_Semicolon,   /* ekKEY_TILDE      = 109 */
        kVK_ANSI_LeftBracket, /* ekKEY_GRAVE      = 110 */
        kVK_ANSI_RightBracket /* ekKEY_PLUS       = 111 */
};

/*---------------------------------------------------------------------------*/

void osgui_start_imp(void)
{
    kUNDERLINE_STYLE_NONE = [[NSNumber alloc] initWithInt:NSUnderlineStyleNone];
    kUNDERLINE_STYLE_SINGLE = [[NSNumber alloc] initWithInt:NSUnderlineStyleSingle];
    kLEFT_PARAGRAPH_STYLE = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
    [kLEFT_PARAGRAPH_STYLE setAlignment:_oscontrol_text_alignment(ekLEFT)];
    kCENTER_PARAGRAPH_STYLE = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
    [kCENTER_PARAGRAPH_STYLE setAlignment:_oscontrol_text_alignment(ekCENTER)];
    kRIGHT_PARAGRAPH_STYLE = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
    [kRIGHT_PARAGRAPH_STYLE setAlignment:_oscontrol_text_alignment(ekRIGHT)];
    kEMPTY_MENUBAR = [[NSMenu alloc] initWithTitle:@""];
    osglobals_init();
}

/*---------------------------------------------------------------------------*/

void osgui_finish_imp(void)
{
    [kLEFT_PARAGRAPH_STYLE release];
    [kCENTER_PARAGRAPH_STYLE release];
    [kRIGHT_PARAGRAPH_STYLE release];
    [kUNDERLINE_STYLE_SINGLE release];
    [kUNDERLINE_STYLE_NONE release];
    [kEMPTY_MENUBAR release];
    osglobals_finish();
    _oscomwin_destroy_globals();
}

/*---------------------------------------------------------------------------*/

void osgui_word_size(StringSizeData *data, const char_t *word, real32_t *width, real32_t *height)
{
    NSString *str = nil;
    NSSize word_size;
    cassert_no_null(data);
    cassert_no_null(width);
    cassert_no_null(height);
    str = [NSString stringWithUTF8String:word];
    word_size = [str sizeWithAttributes:data->dict];
    *width = (real32_t)word_size.width;
    *height = (real32_t)word_size.height;
}

/*---------------------------------------------------------------------------*/

void osgui_attach_menubar(OSWindow *window, OSMenu *menu)
{
    cassert_no_null(menu);
    unref(window);
    [NSApp setMainMenu:(NSMenu *)menu];
}

/*---------------------------------------------------------------------------*/

void osgui_detach_menubar(OSWindow *window, OSMenu *menu)
{
    cassert_no_null(menu);
    cassert([NSApp mainMenu] == (NSMenu *)menu);
    unref(window);
    [NSApp setMainMenu:kEMPTY_MENUBAR];
}

/*---------------------------------------------------------------------------*/

void osgui_change_menubar(OSWindow *window, OSMenu *previous_menu, OSMenu *new_menu)
{
    cassert_no_null(previous_menu);
    cassert_no_null(new_menu);
    cassert([NSApp mainMenu] == (NSMenu *)previous_menu);
    unref(window);
    [NSApp setMainMenu:(NSMenu *)new_menu];
}

/*---------------------------------------------------------------------------*/

void osgui_message_loop_imp(void)
{
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

bool_t osgui_is_pre_initialized_imp(void)
{
    cassert(FALSE);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void osgui_pre_initialize_imp(void)
{
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

vkey_t osgui_vkey(unsigned short keycode)
{
    vkey_t vkey = ENUM_MAX(vkey_t);
    uint32_t i, n = sizeof(i_kVIRTUAL_KEY) / sizeof(unsigned short);

    for (i = 0; i < n; ++i)
    {
        if (i_kVIRTUAL_KEY[i] == keycode)
        {
            vkey = (vkey_t)i;
            break;
        }
    }

    return vkey;
}

/*---------------------------------------------------------------------------*/

/*
   Virtual key bits
   17 = SHIFT   2 = Right 1 = Left
   18 = CTRL   13 = Right 1 = Left
   20 = COMMAND 4 = Right 3 = Left
   19 = ALT     6 = Right 5 = Left
    8 = From mouse in always
*/
static __INLINE bool_t i_modif(NSUInteger flags, uint32_t v1, uint32_t v2)
{
    /* BIT 8 indicate mouse */
    cassert(v2 - v1 == 256);
    if ((flags & v1) == v1)
        return TRUE;
    if ((flags & v2) == v2)
        return TRUE;
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void osgui_modifier_flags(
    NSUInteger flags,
    bool_t *rshift, bool_t *rctrl, bool_t *rcommand, bool_t *ralt,
    bool_t *lshift, bool_t *lctrl, bool_t *lcommand, bool_t *lalt)
{
    *rshift = i_modif(flags, 131076, 131332);
    *rctrl = i_modif(flags, 270336, 270592);
    *rcommand = i_modif(flags, 1048592, 1048848);
    *ralt = i_modif(flags, 524352, 524608);
    *lshift = i_modif(flags, 131074, 131330);
    *lctrl = i_modif(flags, 262145, 262401);
    *lcommand = i_modif(flags, 1048584, 1048840);
    *lalt = i_modif(flags, 524320, 524576);
}

/*---------------------------------------------------------------------------*/

uint32_t osgui_modifiers(NSUInteger flags)
{
    uint32_t modifiers = ekMKEY_NONE;
    bool_t rshift, rctrl, rcommand, ralt;
    bool_t lshift, lctrl, lcommand, lalt;
    osgui_modifier_flags(flags, &rshift, &rctrl, &rcommand, &ralt, &lshift, &lctrl, &lcommand, &lalt);
    if (rshift || lshift)
        modifiers |= ekMKEY_SHIFT;
    if (rctrl || lctrl)
        modifiers |= ekMKEY_CONTROL;
    if (rcommand || lcommand)
        modifiers |= ekMKEY_COMMAND;
    if (ralt || lalt)
        modifiers |= ekMKEY_ALT;
    return modifiers;
}

/*---------------------------------------------------------------------------*/

uint32_t osgui_key_equivalent_text(const char_t *text, char_t *buff, const uint32_t size)
{
    uint32_t i = 0;
    uint32_t key_equivalent = UINT32_MAX;
    cassert_no_null(text);
    cassert_no_null(buff);
    while (*text != 0 && i < size - 1)
    {
        if (*text == '&')
        {
            /* Double '&' just write one */
            if (*(text + 1) == '&')
            {
                buff[i] = '&';
                text += 2;
                i += 1;
            }
            /* Last '&' in the string is not taken into account */
            else if (*(text + 1) == 0)
            {
                text += 1;
            }
            /* Single '&' store the position */
            else
            {
                key_equivalent = i;
                text += 1;
            }
        }
        /* Other character */
        else
        {
            buff[i] = *text;
            i += 1;
            text += 1;
        }
    }

    /* There is plenty of space for copy (these are texts on buttons). */
    cassert(i < size - 1);
    buff[i] = 0;

    return key_equivalent;
}
