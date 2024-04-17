/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenuitem.m
 *
 */

/* Cocoa NSMenuItem wrapper */

#include "osgui_osx.inl"
#include "osmenuitem.h"
#include "osgui.inl"
#include <draw2d/image.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

static uint16_t i_VIRTUAL_KEY[] =
    {
        UINT16_MAX, /*ekKEY_UNASSIGNED      = 0*/
        'a',        /*ekKEY_A               = 1*/
        's',        /*ekKEY_S               = 2*/
        'd',        /*ekKEY_D               = 3*/
        'f',        /*ekKEY_F               = 4*/
        'h',        /*ekKEY_H               = 5*/
        'g',        /*ekKEY_G               = 6*/
        'z',        /*ekKEY_Z               = 7*/
        'x',        /*ekKEY_X               = 8*/
        'c',        /*ekKEY_C               = 9*/

        'v', /*ekKEY_V               = 10*/
        '/', /*ekKEY_BACKSLASH       = 11*/
        'b', /*ekKEY_B               = 12*/
        'q', /*ekKEY_Q               = 13*/
        'w', /*ekKEY_W               = 14*/
        'e', /*ekKEY_E               = 15*/
        'r', /*ekKEY_R               = 16*/
        'y', /*ekKEY_Y               = 17*/
        't', /*ekKEY_T               = 18*/
        '1', /*ekKEY_1               = 19*/

        '2', /*ekKEY_2               = 20*/
        '3', /*ekKEY_3               = 21*/
        '4', /*ekKEY_4               = 22*/
        '6', /*ekKEY_6               = 23*/
        '5', /*ekKEY_5               = 24*/
        '9', /*ekKEY_9               = 25*/
        '7', /*ekKEY_7               = 26*/
        '8', /*ekKEY_8               = 27*/
        '0', /*ekKEY_0               = 28*/
        ']', /*ekKEY_RBRACKET        = 29*/

        'o',              /*ekKEY_O               = 30*/
        'u',              /*ekKEY_U               = 31*/
        '[',              /*ekKEY_LBRACKET        = 32*/
        'i',              /*ekKEY_I               = 33*/
        'p',              /*ekKEY_P               = 34*/
        NSEnterCharacter, /*ekKEY_RETURN          = 35*/
        'l',              /*ekKEY_L               = 36*/
        'j',              /*ekKEY_J               = 37*/
        ';',              /*ekKEY_SEMICOLON       = 38*/
        'k',              /*ekKEY_K               = 39*/

        '\'',                 /*ekKEY_APOSTROPHE      = 40*/
        ',',                  /*ekKEY_COMMA           = 41*/
        '-',                  /*ekKEY_MINUS           = 42*/
        'n',                  /*ekKEY_N               = 43*/
        'm',                  /*ekKEY_M               = 44*/
        '.',                  /*ekKEY_PERIOD          = 45*/
        NSTabCharacter,       /*ekKEY_TAB             = 46*/
        ' ',                  /*ekKEY_SPACE           = 47*/
        '<',                  /*ekKEY_MAJOR_MINOR     = 48*/
        NSBackspaceCharacter, /*ekKEY_BACK            = 49*/

        NSBreakFunctionKey, /*ekKEY_ESCAPE          = 50*/
        NSF17FunctionKey,   /*ekKEY_F17             = 51*/
        '.',                /*ekKEY_NUMPAD_DECIMAL  = 52*/
        '*',                /*ekKEY_NUMPAD_MULT     = 53*/
        '+',                /*ekKEY_NUMPAD_ADD      = 54*/
        ' ',                /*ekKEY_NUMLOCK         = 55*/
        '/',                /*ekKEY_NUMPAD_DIV      = 56*/
        NSEnterCharacter,   /*ekKEY_NUMPAD_RETURN   = 57*/
        '-',                /*ekKEY_NUMPAD_SUBTRACT = 58*/
        NSF18FunctionKey,   /*ekKEY_F18             = 59*/

        NSF19FunctionKey, /*ekKEY_F19             = 60*/
        '=',              /*ekKEY_NUMPAD_EQUAL    = 61*/
        '0',              /*ekKEY_NUMPAD0         = 62*/
        '1',              /*ekKEY_NUMPAD1         = 63*/
        '2',              /*ekKEY_NUMPAD2         = 64*/
        '3',              /*ekKEY_NUMPAD3         = 65*/
        '4',              /*ekKEY_NUMPAD4         = 66*/
        '5',              /*ekKEY_NUMPAD5         = 67*/
        '6',              /*ekKEY_NUMPAD6         = 68*/
        '7',              /*ekKEY_NUMPAD7         = 69*/

        '8',              /*ekKEY_NUMPAD8         = 70*/
        '9',              /*ekKEY_NUMPAD9         = 71*/
        NSF5FunctionKey,  /*ekKEY_F5              = 72*/
        NSF6FunctionKey,  /*ekKEY_F6              = 73*/
        NSF7FunctionKey,  /*ekKEY_F7              = 74*/
        NSF3FunctionKey,  /*ekKEY_F3              = 75*/
        NSF8FunctionKey,  /*ekKEY_F8              = 76*/
        NSF9FunctionKey,  /*ekKEY_F9              = 77*/
        NSF11FunctionKey, /*ekKEY_F11             = 78*/
        NSF13FunctionKey, /*ekKEY_F13             = 79*/

        NSF16FunctionKey,      /*ekKEY_F16             = 80*/
        NSF14FunctionKey,      /*ekKEY_F14             = 81*/
        NSF10FunctionKey,      /*ekKEY_F10             = 82*/
        NSF12FunctionKey,      /*ekKEY_F12             = 83*/
        NSF15FunctionKey,      /*ekKEY_F15             = 84*/
        NSPageUpFunctionKey,   /*ekKEY_PAGE_UP         = 85*/
        NSBeginFunctionKey,    /*ekKEY_PAGE_BEGIN      = 86*/
        NSDeleteFunctionKey,   /*ekKEY_SUPR            = 87*/
        NSF4FunctionKey,       /*ekKEY_F4              = 88*/
        NSPageDownFunctionKey, /*ekKEY_PAGE_DOWN       = 89*/

        NSF2FunctionKey,         /*ekKEY_F2              = 90*/
        NSEndFunctionKey,        /*ekKEY_PAGE_END        = 91*/
        NSF1FunctionKey,         /*ekKEY_F1              = 92*/
        NSLeftArrowFunctionKey,  /*ekKEY_LEFT            = 93*/
        NSRightArrowFunctionKey, /*ekKEY_RIGHT           = 94*/
        NSDownArrowFunctionKey,  /*ekKEY_DOWN            = 95*/
        NSUpArrowFunctionKey     /*ekKEY_UP              = 96*/
};

/*---------------------------------------------------------------------------*/

@interface OSXMenuItem : NSMenuItem
{
  @public
    Listener *OnClick;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXMenuItem

/*---------------------------------------------------------------------------*/

- (void)dealloc
{
    /*
    #include "log.h"
    NSString *str = [self title];
    const char_t *sstr = [str UTF8String];
    log_printf("%s", sstr);*/
    [super dealloc];
    heap_auditor_delete("OSXMenuItem");
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_state(const NSInteger state)
{
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    if (state == NSControlStateValueOff)
        return ekGUI_OFF;
    if (state == NSControlStateValueOn)
        return ekGUI_ON;
    if (state == NSControlStateValueMixed)
        return ekGUI_MIXED;
    cassert_msg(FALSE, "Unknown menu state");
    return ENUM_MAX(gui_state_t);
#else
    if (state == NSOffState)
        return ekGUI_OFF;
    if (state == NSOnState)
        return ekGUI_ON;
    if (state == NSMixedState)
        return ekGUI_MIXED;
    cassert_msg(FALSE, "Unknown menu state");
    return ENUM_MAX(gui_state_t);
#endif
}

/*---------------------------------------------------------------------------*/

- (IBAction)menuItemPressed:(id)sender
{
    cassert([sender isKindOfClass:[OSXMenuItem class]] == YES);
    if (((OSXMenuItem *)sender)->OnClick != NULL)
    {
        EvMenu params;
        params.index = UINT32_MAX;
        params.state = i_state([(OSXMenuItem *)sender state]);
        params.text = NULL;
        listener_event(((OSXMenuItem *)sender)->OnClick, ekGUI_EVENT_MENU, (OSMenuItem *)sender, &params, NULL, OSMenuItem, EvMenu, void);
    }
}

@end

/*---------------------------------------------------------------------------*/

OSMenuItem *osmenuitem_create(const uint32_t flag)
{
    switch (flag)
    {
    case ekMENU_ITEM:
    {
        OSXMenuItem *item = [[OSXMenuItem alloc] initWithTitle:[NSString string] action:@selector(menuItemPressed:) keyEquivalent:[NSString string]];
        heap_auditor_add("OSXMenuItem");
        item->OnClick = NULL;
        [item setAction:@selector(menuItemPressed:)];
        [item setTarget:item];
        [item setEnabled:YES];
        [item setHidden:NO];
        return (OSMenuItem *)item;
    }

    case ekMENU_SEPARATOR:
        return (OSMenuItem *)[NSMenuItem separatorItem];

        cassert_default();
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

#if defined(__ASSERTS__)
static BOOL i_check_item(NSObject *item)
{
    if ([item class] == [OSXMenuItem class])
    {
        return YES;
    }
    else if ([item class] == [NSMenuItem class])
    {
        return [(NSMenuItem *)item isSeparatorItem];
    }
    else
    {
        cassert(FALSE);
        return NO;
    }
}
#endif

/*---------------------------------------------------------------------------*/

void osmenuitem_destroy(OSMenuItem **item)
{
    cassert_no_null(item);
    cassert_no_null(*item);
    cassert(i_check_item((NSObject *)*item) == YES);

    if ([(NSObject *)*item isKindOfClass:[OSXMenuItem class]] == YES)
    {
        cassert([(NSMenuItem *)*item menu] == nil);
        listener_destroy(&((OSXMenuItem *)*item)->OnClick);
        [(NSMenuItem *)*item release];
    }

    *item = NULL;
}

/*---------------------------------------------------------------------------*/

void osmenuitem_OnClick(OSMenuItem *item, Listener *listener)
{
    cassert_no_null(item);
    cassert_no_null(listener);
    cassert(i_check_item((NSObject *)item) == YES);
    listener_update(&((OSXMenuItem *)item)->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

void osmenuitem_enabled(OSMenuItem *item, const bool_t enabled)
{
    cassert_no_null(item);
    cassert(i_check_item((NSObject *)item) == YES);
    [(OSXMenuItem *)item setEnabled:(BOOL)enabled];
}

/*---------------------------------------------------------------------------*/

void osmenuitem_visible(OSMenuItem *item, const bool_t visible)
{
    cassert_no_null(item);
    cassert(i_check_item((NSObject *)item) == YES);
    [(OSXMenuItem *)item setHidden:(BOOL)!visible];
}

/*---------------------------------------------------------------------------*/

void osmenuitem_text(OSMenuItem *item, const char_t *text)
{
    NSString *str = nil;
    NSMenu *subMenu = nil;
    cassert_no_null(item);
    cassert_no_null(text);
    cassert([((NSObject *)item) isKindOfClass:[OSXMenuItem class]] == YES);

    /* In Mac OS X El Capitan, the "Enter Full Screen" menu item appears by itself */
    /* https://github.com/electron/electron/issues/3038 */
    if (str_equ_nocase(text, "view") == TRUE || str_equ_nocase(text, "edit") == TRUE)
    {
        char_t nstr[32];
        char_t u200C[] = {(char_t)226, (char_t)128, (char_t)140, 0};
        str_copy_c(nstr, sizeof(nstr), text);
        str_cat_c(nstr, sizeof(nstr), u200C);
        str = [[NSString alloc] initWithUTF8String:(const char *)nstr];
    }
    else
    {
        str = [[NSString alloc] initWithUTF8String:(const char *)text];
    }

    [(OSXMenuItem *)item setTitle:str];
    /* The text printed in the menu do not take from NSMenuItem, but [NSMenuItem subMenu]
       lists.apple.com/archives/cocoa-dev/2008/Nov/msg00217.html */
    subMenu = [(OSXMenuItem *)item submenu];
    if (subMenu != nil)
        [subMenu setTitle:str];
    [str release];
}

/*---------------------------------------------------------------------------*/

void osmenuitem_image(OSMenuItem *item, const Image *image)
{
    cassert_no_null(item);
    [(OSXMenuItem *)item setImage:(NSImage *)image_native(image)];
}

/*---------------------------------------------------------------------------*/

static NSUInteger i_kmod(const uint32_t modifiers)
{
    NSUInteger mod = 0;
    if ((modifiers & ekMKEY_SHIFT) == ekMKEY_SHIFT)
        mod |= (1 << 17);
    if ((modifiers & ekMKEY_CONTROL) == ekMKEY_CONTROL)
        mod |= (1 << 18);
    if ((modifiers & ekMKEY_ALT) == ekMKEY_ALT)
        mod |= (1 << 19);
    if ((modifiers & ekMKEY_COMMAND) == ekMKEY_COMMAND)
        mod |= (1 << 20);
    return mod;
}

/*---------------------------------------------------------------------------*/

void osmenuitem_key(OSMenuItem *item, const uint32_t key, const uint32_t modifiers)
{
    unichar c;
    NSString *str = nil;
    cassert_no_null(item);
    cassert([((NSObject *)item) isKindOfClass:[OSXMenuItem class]] == YES);
    c = i_VIRTUAL_KEY[key];
    str = [NSString stringWithCharacters:&c length:1];
    [(OSXMenuItem *)item setKeyEquivalent:str];
    [(OSXMenuItem *)item setKeyEquivalentModifierMask:i_kmod(modifiers)];
}

/*---------------------------------------------------------------------------*/

static NSInteger i_menuitem_state(const gui_state_t state)
{
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    switch (state)
    {
    case ekGUI_OFF:
        return NSControlStateValueOff;
    case ekGUI_ON:
        return NSControlStateValueOn;
    case ekGUI_MIXED:
        return NSControlStateValueMixed;
    default:
        cassert(FALSE);
        return -1;
    }
#else
    switch (state)
    {
    case ekGUI_OFF:
        return NSOffState;
    case ekGUI_ON:
        return NSOnState;
    case ekGUI_MIXED:
        return NSMixedState;
    default:
        cassert(FALSE);
        return -1;
    }
#endif
}

/*---------------------------------------------------------------------------*/

void osmenuitem_state(OSMenuItem *item, const gui_state_t state)
{
    NSInteger _state;
    cassert_no_null(item);
    cassert([(NSObject *)item isKindOfClass:[OSXMenuItem class]] == YES);
    _state = i_menuitem_state(state);
    [(OSXMenuItem *)item setState:_state];
}

/*---------------------------------------------------------------------------*/

void osmenuitem_submenu(OSMenuItem *item, OSMenu *menu)
{
    OSXMenuItem *itemp = nil;
    NSUInteger retain_count = 0;
    cassert_no_null(item);
    cassert_no_null(menu);
    itemp = (OSXMenuItem *)item;
    cassert([itemp isKindOfClass:[OSXMenuItem class]] == YES);
    cassert([(NSObject *)menu isKindOfClass:[NSMenu class]] == YES);
    cassert([itemp submenu] == nil);
    retain_count = [(NSMenu *)menu retainCount];
    [itemp setSubmenu:(NSMenu *)menu];
    [(NSMenu *)menu setTitle:[itemp title]];
    cassert_unref([(NSMenu *)menu retainCount] == retain_count + 1, retain_count);
}

/*---------------------------------------------------------------------------*/

void osmenuitem_unset_submenu(OSMenuItem *item, OSMenu *menu)
{
    OSXMenuItem *itemp = nil;
    cassert_no_null(item);
    cassert_no_null(menu);
    itemp = (OSXMenuItem *)item;
    cassert([itemp isKindOfClass:[OSXMenuItem class]] == YES);
    cassert([(NSObject *)menu isKindOfClass:[NSMenu class]] == YES);
    cassert([(OSXMenuItem *)item submenu] == (NSMenu *)menu);
    [itemp setSubmenu:nil];
}
