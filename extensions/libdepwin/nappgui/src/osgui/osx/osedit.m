/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osedit.m
 *
 */

/* Operating System edit box */

#include "osedit.h"
#include "osedit.inl"
#include "oscolor.inl"
#include "osgui.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include "oswindow_osx.inl"
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXTextFieldCell : NSTextFieldCell
{
  @public
    NSView *parent;
}

@end

/*---------------------------------------------------------------------------*/

@interface OSXSecureTextFieldCell : NSSecureTextFieldCell
{
  @public
    NSView *parent;
}
@end

/*---------------------------------------------------------------------------*/

@interface OSXTextField : NSTextField
{
  @public
    NSView *parent;
}
@end

/*---------------------------------------------------------------------------*/

@interface OSXSecureTextField : NSSecureTextField
{
  @public
    NSView *parent;
}
@end

/*---------------------------------------------------------------------------*/

@interface OSXEdit : NSView
{
  @public
    NSTextField *field;
    uint32_t flags;
    uint32_t vpadding;
    real32_t rpadding;
    CGFloat wpadding;
    OSTextAttr attrs;
    Listener *OnFilter;
    Listener *OnChange;
    Listener *OnFocus;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXEdit

- (BOOL)acceptsFirstResponder
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (BOOL)makeFirstResponder:(NSResponder *)responder
{
    unref(responder);
    return YES;
}

/*---------------------------------------------------------------------------*/

- (BOOL)becomeFirstResponder
{
    return [self->field becomeFirstResponder];
}

/*---------------------------------------------------------------------------*/

- (BOOL)resignFirstResponder
{
    return [self->field resignFirstResponder];
}

@end

/*---------------------------------------------------------------------------*/

@implementation OSXTextFieldCell

/*---------------------------------------------------------------------------*/

- (void)selectWithFrame:(NSRect)frame inView:(NSView *)controlView editor:(NSText *)textObj delegate:(id)anObject start:(NSInteger)selStart length:(NSInteger)selLength
{
    frame.origin.y += ((OSXEdit *)parent)->wpadding;
    [super selectWithFrame:frame inView:controlView editor:textObj delegate:anObject start:selStart length:selLength];
}

/*---------------------------------------------------------------------------*/

- (void)editWithFrame:(NSRect)frame inView:(NSView *)controlView editor:(NSText *)textObj delegate:(id)anObject event:(NSEvent *)theEvent
{
    frame.origin.y += ((OSXEdit *)parent)->wpadding;
    [super editWithFrame:frame inView:controlView editor:textObj delegate:anObject event:theEvent];
}

/*---------------------------------------------------------------------------*/

- (void)drawInteriorWithFrame:(NSRect)frame inView:(NSView *)controlView
{
    frame.origin.y += ((OSXEdit *)parent)->wpadding;
    [super drawInteriorWithFrame:frame inView:controlView];
}

/*---------------------------------------------------------------------------*/

@end

/*---------------------------------------------------------------------------*/

@implementation OSXSecureTextFieldCell

/*---------------------------------------------------------------------------*/

- (void)selectWithFrame:(NSRect)frame inView:(NSView *)controlView editor:(NSText *)textObj delegate:(id)anObject start:(NSInteger)selStart length:(NSInteger)selLength
{
    frame.origin.y += ((OSXEdit *)parent)->wpadding;
    [super selectWithFrame:frame inView:controlView editor:textObj delegate:anObject start:selStart length:selLength];
}

/*---------------------------------------------------------------------------*/

- (void)editWithFrame:(NSRect)frame inView:(NSView *)controlView editor:(NSText *)textObj delegate:(id)anObject event:(NSEvent *)theEvent
{
    frame.origin.y += ((OSXEdit *)parent)->wpadding;
    [super editWithFrame:frame inView:controlView editor:textObj delegate:anObject event:theEvent];
}

/*---------------------------------------------------------------------------*/

- (void)drawInteriorWithFrame:(NSRect)frame inView:(NSView *)controlView
{
    frame.origin.y += ((OSXEdit *)parent)->wpadding;
    [super drawInteriorWithFrame:frame inView:controlView];
}

/*---------------------------------------------------------------------------*/

@end

/*---------------------------------------------------------------------------*/

static void OSX_textDidChange(OSXEdit *edit, NSTextField *field)
{
    if ([field isEnabled] == YES && edit->OnFilter != NULL)
    {
        EvText params;
        EvTextFilter result;
        NSWindow *window = [field window];
        NSText *text = NULL;
        params.text = (const char_t *)[[field stringValue] UTF8String];
        text = [window fieldEditor:YES forObject:field];
        params.cpos = (uint32_t)[text selectedRange].location;
        result.apply = FALSE;
        result.text[0] = '\0';
        result.cpos = UINT32_MAX;
        listener_event(edit->OnFilter, ekGUI_EVENT_TXTFILTER, (OSEdit *)edit, &params, &result, OSEdit, EvText, EvTextFilter);

        if (result.apply == TRUE)
            _oscontrol_set_text(field, &edit->attrs, result.text);

        if (result.cpos != UINT32_MAX)
            [text setSelectedRange:NSMakeRange((NSUInteger)result.cpos, 0)];
        else
            [text setSelectedRange:NSMakeRange((NSUInteger)params.cpos, 0)];
    }
}

/*---------------------------------------------------------------------------*/

static void OSX_textDidEndEditing(OSXEdit *edit, NSNotification *notification)
{
    unsigned int whyEnd = [[[notification userInfo] objectForKey:@"NSTextMovement"] unsignedIntValue];
    NSWindow *window = [edit window];
    if (whyEnd == NSReturnTextMovement)
    {
        [window keyDown:(NSEvent *)231];
    }
    else if (whyEnd == NSTabTextMovement)
    {
        _oswindow_next_tabstop(window, TRUE);
    }
    else if (whyEnd == NSBacktabTextMovement)
    {
        _oswindow_prev_tabstop(window, TRUE);
    }
}

/*---------------------------------------------------------------------------*/

@implementation OSXTextField

/*---------------------------------------------------------------------------*/

- (BOOL)resignFirstResponder
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (BOOL)becomeFirstResponder
{
    [super becomeFirstResponder];
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)textDidChange:(NSNotification *)notification
{
    unref(notification);
    OSX_textDidChange((OSXEdit *)self->parent, self);
}

/*---------------------------------------------------------------------------*/

- (void)textDidEndEditing:(NSNotification *)notification
{
    OSX_textDidEndEditing((OSXEdit *)self->parent, notification);
}

/*---------------------------------------------------------------------------*/

- (void)mouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down((OSControl *)self->parent) == TRUE)
        [super mouseDown:theEvent];
}

@end

/*---------------------------------------------------------------------------*/

@implementation OSXSecureTextField

/*---------------------------------------------------------------------------*/

- (BOOL)resignFirstResponder
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (BOOL)becomeFirstResponder
{
    [super becomeFirstResponder];
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)textDidChange:(NSNotification *)notification
{
    unref(notification);
    OSX_textDidChange((OSXEdit *)self->parent, self);
}

/*---------------------------------------------------------------------------*/

- (void)textDidEndEditing:(NSNotification *)notification
{
    OSX_textDidEndEditing((OSXEdit *)self->parent, notification);
}

/*---------------------------------------------------------------------------*/

- (void)mouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down((OSControl *)self->parent) == TRUE)
        [super mouseDown:theEvent];
}

@end

/*---------------------------------------------------------------------------*/

static void i_update_cell(OSXEdit *edit)
{
    NSCell *cell = [edit->field cell];
    if ([(NSObject *)cell isKindOfClass:[OSXTextFieldCell class]] == YES)
    {
        ((OSXTextFieldCell *)cell)->parent = edit;
    }
    else
    {
        cassert([(NSObject *)cell isKindOfClass:[OSXSecureTextFieldCell class]] == YES);
        ((OSXSecureTextFieldCell *)cell)->parent = edit;
    }
}

/*---------------------------------------------------------------------------*/

static void i_update_vpadding(OSXEdit *edit)
{
    real32_t width, height;
    uint32_t defpadding = 0;

    cassert_no_null(edit);
    _oscontrol_text_bounds(edit->attrs.font, "OO", -1.f, &width, &height);

    defpadding = (uint32_t)((.3f * height) + .5f);
    if (defpadding % 2 == 1)
        defpadding += 1;

    if (defpadding < 5)
        defpadding = 5;

    if (edit->vpadding == UINT32_MAX)
    {
        edit->rpadding = (real32_t)defpadding;
        edit->wpadding = 0;
    }
    else
    {
        real32_t leading = font_leading(edit->attrs.font);
        uint32_t padding = (uint32_t)(edit->vpadding + leading);

        padding += 4;

        if (padding > defpadding)
            edit->wpadding = (CGFloat)((padding - defpadding) / 2);
        else
            edit->wpadding = 0;

        edit->rpadding = (real32_t)padding;
    }

    i_update_cell(edit);
}

/*---------------------------------------------------------------------------*/

OSEdit *osedit_create(const uint32_t flags)
{
    OSXEdit *edit = nil;
    OSXTextField *field = nil;
    heap_auditor_add("OSXEdit");
    edit = [[OSXEdit alloc] initWithFrame:NSZeroRect];
    field = [[OSXTextField alloc] initWithFrame:NSZeroRect];
    [field setCell:[[OSXTextFieldCell alloc] init]];
    edit->flags = flags;
    edit->vpadding = UINT32_MAX;
    edit->OnFilter = NULL;
    edit->OnChange = NULL;
    edit->OnFocus = NULL;
    [edit addSubview:field];
    edit->field = field;
    field->parent = edit;
    _oscontrol_init(edit);
    _oscontrol_init_textattr(&edit->attrs);
    i_update_vpadding(edit);
    [edit->field setEditable:YES];
    [edit->field setSelectable:YES];
    [edit->field setBordered:YES];
    [edit->field setBezeled:YES];
    [edit->field setDrawsBackground:YES];
    [edit->field setStringValue:@""];
    [edit->field setAlignment:_oscontrol_text_alignment(ekLEFT)];
    _oscontrol_set_align(edit->field, &edit->attrs, ekLEFT);
    _oscontrol_set_font(edit->field, &edit->attrs, edit->attrs.font);
#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
    [[edit->field cell] setUsesSingleLineMode:((flags & 1) == 1) ? NO : YES];
#endif
    return (OSEdit *)edit;
}

/*---------------------------------------------------------------------------*/

void osedit_destroy(OSEdit **edit)
{
    OSXEdit *ledit = nil;
    cassert_no_null(edit);
    ledit = *((OSXEdit **)edit);
    cassert_no_null(ledit);
    listener_destroy(&ledit->OnFilter);
    listener_destroy(&ledit->OnChange);
    listener_destroy(&ledit->OnFocus);
    _oscontrol_remove_textattr(&ledit->attrs);
    [ledit release];
    *edit = NULL;
    heap_auditor_delete("OSXEdit");
}

/*---------------------------------------------------------------------------*/

void osedit_OnFilter(OSEdit *edit, Listener *listener)
{
    cassert_no_null(edit);
    cassert([(NSObject *)edit isKindOfClass:[OSXEdit class]] == YES);
    listener_update(&((OSXEdit *)edit)->OnFilter, listener);
}

/*---------------------------------------------------------------------------*/

void osedit_OnChange(OSEdit *edit, Listener *listener)
{
    cassert_no_null(edit);
    cassert([(NSObject *)edit isKindOfClass:[OSXEdit class]] == YES);
    listener_update(&((OSXEdit *)edit)->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

void osedit_OnFocus(OSEdit *edit, Listener *listener)
{
    cassert_no_null(edit);
    cassert([(NSObject *)edit isKindOfClass:[OSXEdit class]] == YES);
    listener_update(&((OSXEdit *)edit)->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osedit_text(OSEdit *edit, const char_t *text)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    _oscontrol_set_text(ledit->field, &ledit->attrs, text);
}

/*---------------------------------------------------------------------------*/

void osedit_tooltip(OSEdit *edit, const char_t *text)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    _oscontrol_tooltip_set(ledit->field, text);
}

/*---------------------------------------------------------------------------*/

void osedit_font(OSEdit *edit, const Font *font)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    _oscontrol_set_font(ledit->field, &ledit->attrs, font);
    i_update_vpadding(ledit);
}

/*---------------------------------------------------------------------------*/

void osedit_align(OSEdit *edit, const align_t align)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    [ledit->field setAlignment:_oscontrol_text_alignment(align)];
    _oscontrol_set_align(ledit->field, &ledit->attrs, align);
}

/*---------------------------------------------------------------------------*/

void osedit_passmode(OSEdit *edit, const bool_t passmode)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    NSTextField *field = nil;
    cassert_no_null(ledit);
    if (passmode == TRUE)
    {
        if ([ledit->field isKindOfClass:[OSXTextField class]])
        {
            NSRect rect = [ledit->field frame];
            OSXSecureTextField *nfield = [[OSXSecureTextField alloc] initWithFrame:rect];
            [nfield setCell:[[OSXSecureTextFieldCell alloc] init]];
            nfield->parent = ledit;
            field = nfield;
        }
    }
    else
    {
        if ([ledit->field isKindOfClass:[OSXSecureTextField class]])
        {
            NSRect rect = [ledit->field frame];
            OSXTextField *nfield = [[OSXTextField alloc] initWithFrame:rect];
            [nfield setCell:[[OSXTextFieldCell alloc] init]];
            nfield->parent = ledit;
            field = nfield;
        }
    }

    if (field != nil)
    {
        NSString *text = [[ledit->field cell] stringValue];
        [field setEditable:[ledit->field isEditable]];
        [field setSelectable:[ledit->field isSelectable]];
        [field setBordered:[ledit->field isBordered]];
        [field setBezeled:[ledit->field isBezeled]];
        [field setDrawsBackground:[ledit->field drawsBackground]];
        _oscontrol_set_font(field, &ledit->attrs, ledit->attrs.font);
        _oscontrol_set_text_color(field, &ledit->attrs, ledit->attrs.color);
        _oscontrol_set_align(field, &ledit->attrs, ledit->attrs.align);
        _oscontrol_set_text(field, &ledit->attrs, (const char_t *)[text UTF8String]);
        _oscontrol_detach_from_parent(ledit->field, ledit);
#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
        [[field cell] setUsesSingleLineMode:((ledit->flags & 1) == 1) ? NO : YES];
#endif
        [ledit->field release];
        ledit->field = field;
        [ledit addSubview:field];
        i_update_cell(ledit);
    }
}

/*---------------------------------------------------------------------------*/

void osedit_editable(OSEdit *edit, const bool_t is_editable)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    [ledit->field setEditable:is_editable == TRUE ? YES : NO];
}

/*---------------------------------------------------------------------------*/

void osedit_autoselect(OSEdit *edit, const bool_t autoselect)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    if (autoselect == TRUE)
        BIT_SET(ledit->flags, ekEDIT_AUTOSEL);
    else
        BIT_CLEAR(ledit->flags, ekEDIT_AUTOSEL);
}

/*---------------------------------------------------------------------------*/

void osedit_select(OSEdit *edit, const int32_t start, const int32_t end)
{
    unref(edit);
    unref(start);
    unref(end);
}

/*---------------------------------------------------------------------------*/

void osedit_color(OSEdit *edit, const color_t color)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    _oscontrol_set_text_color(ledit->field, &ledit->attrs, color);
}

/*---------------------------------------------------------------------------*/

void osedit_bgcolor(OSEdit *edit, const color_t color)
{
    NSColor *nscolor = color != 0 ? oscolor_NSColor(color) : [NSColor textBackgroundColor];
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    [ledit->field setBackgroundColor:nscolor];
}

/*---------------------------------------------------------------------------*/

void osedit_vpadding(OSEdit *edit, const real32_t padding)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    cassert(padding >= 0);
    ledit->vpadding = (uint32_t)padding;
    i_update_vpadding(ledit);
}

/*---------------------------------------------------------------------------*/

void osedit_bounds(const OSEdit *edit, const real32_t refwidth, const uint32_t lines, real32_t *width, real32_t *height)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    cassert_no_null(width);
    cassert_no_null(height);
    cassert(lines > 0);

    if (lines == 1)
    {
        _oscontrol_text_bounds(ledit->attrs.font, "OO", -1.f, width, height);
    }
    else
    {
        register uint32_t i;
        char_t text[256] = "";
        cassert(edit_get_type(ledit->flags) == ekEDIT_MULTI);
        cassert(lines < 100);
        for (i = 0; i < lines - 1; ++i)
            str_cat_c(text, 256, "O\n");
        str_cat_c(text, 256, "O");
        _oscontrol_text_bounds(ledit->attrs.font, text, -1.f, width, height);
    }

    *width = refwidth;
    *height += ledit->rpadding;
}

/*---------------------------------------------------------------------------*/

void osedit_clipboard(OSEdit *edit, const clipboard_t clipboard)
{
    unref(edit);
    unref(clipboard);
}

/*---------------------------------------------------------------------------*/

void osedit_attach(OSEdit *edit, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)edit);
}

/*---------------------------------------------------------------------------*/

void osedit_detach(OSEdit *edit, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)edit);
}

/*---------------------------------------------------------------------------*/

void osedit_visible(OSEdit *edit, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)edit, is_visible);
}

/*---------------------------------------------------------------------------*/

/* http://alienryderflex.com/hasFocus.html */
static bool_t i_has_focus(id control)
{
    NSWindow *window = [control window];
    id first = [window firstResponder];
    return (bool_t)([first isKindOfClass:[NSTextView class]] && [window fieldEditor:NO forObject:nil] != nil && (first == control || [first delegate] == control));
}

/*---------------------------------------------------------------------------*/

void osedit_enabled(OSEdit *edit, const bool_t is_enabled)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    if (is_enabled == FALSE)
    {
        if (i_has_focus(ledit->field) == TRUE)
            [[ledit->field window] endEditingFor:ledit->field];
    }

    _oscontrol_set_enabled(ledit->field, is_enabled);
    _oscontrol_set_text_color(ledit->field, &ledit->attrs, ledit->attrs.color);
}

/*---------------------------------------------------------------------------*/

void osedit_size(const OSEdit *edit, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)edit, width, height);
}

/*---------------------------------------------------------------------------*/

void osedit_origin(const OSEdit *edit, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)edit, x, y);
}

/*---------------------------------------------------------------------------*/

void osedit_frame(OSEdit *edit, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);
    _oscontrol_set_frame((NSView *)ledit, x, y, width, height);
    _oscontrol_set_frame((NSView *)ledit->field, 0, 0, width, height);
    [ledit setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

bool_t osedit_resign_focus(const OSEdit *edit)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    NSWindow *window = [ledit window];
    bool_t resign = TRUE;
    cassert_no_null(ledit);

    if (ledit->OnChange != NULL && _oswindow_in_destroy(window) == NO)
    {
        EvText params;
        params.text = (const char_t *)[[ledit->field stringValue] UTF8String];
        listener_event(ledit->OnChange, ekGUI_EVENT_TXTCHANGE, edit, &params, &resign, OSEdit, EvText, bool_t);
    }

    if (resign == TRUE)
        [window endEditingFor:ledit];
    else
        [window makeFirstResponder:ledit];

    return resign;
}

/*---------------------------------------------------------------------------*/

void osedit_focus(OSEdit *edit, const bool_t focus)
{
    OSXEdit *ledit = (OSXEdit *)edit;
    cassert_no_null(ledit);

    if (ledit->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(ledit->OnFocus, ekGUI_EVENT_FOCUS, edit, &params, NULL, OSEdit, bool_t, void);
    }

    if (focus == TRUE)
    {
        if ([ledit->field isEnabled] == YES)
        {
            NSWindow *window = [ledit->field window];
            NSText *text = [window fieldEditor:YES forObject:ledit->field];

            if (BIT_TEST(ledit->flags, ekEDIT_AUTOSEL) == TRUE)
            {
                [text selectAll:nil];
            }
            else
            {
                NSRange range = [text selectedRange];
                [text setSelectedRange:NSMakeRange(range.length, 0)];
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

BOOL _osedit_is(NSView *view)
{
    return [view isKindOfClass:[OSXEdit class]];
}
