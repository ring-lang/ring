/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo.m
 *
 */

/* Operating System native combo box */

#include "oscombo.h"
#include "oscombo_osx.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include "oswindow_osx.inl"
#include "osgui.inl"
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

/*---------------------------------------------------------------------------*/

@interface OSXCombo : NSComboBox
{
  @public
    OSTextAttr attrs;
    Listener *OnFilter;
    Listener *OnChange;
    Listener *OnFocus;
    Listener *OnSelect;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXCombo

/*---------------------------------------------------------------------------*/

- (void)textDidChange:(NSNotification *)notification
{
    unref(notification);
    if ([self isEnabled] == YES && self->OnFilter != NULL)
    {
        EvText params;
        EvTextFilter result;
        NSText *text = NULL;
        params.text = (const char_t *)[[self stringValue] UTF8String];
        text = [[self window] fieldEditor:YES forObject:self];
        params.cpos = (uint32_t)[text selectedRange].location;
        result.apply = FALSE;
        result.text[0] = '\0';
        result.cpos = UINT32_MAX;
        listener_event(self->OnFilter, ekGUI_EVENT_TXTFILTER, (OSCombo *)self, &params, &result, OSCombo, EvText, EvTextFilter);

        if (result.apply == TRUE)
            _oscontrol_set_text(self, &self->attrs, result.text);

        if (result.cpos != UINT32_MAX)
            [text setSelectedRange:NSMakeRange((NSUInteger)result.cpos, 0)];
        else
            [text setSelectedRange:NSMakeRange((NSUInteger)params.cpos, 0)];
    }
}

/*---------------------------------------------------------------------------*/

- (void)textDidEndEditing:(NSNotification *)notification
{
    unsigned int whyEnd = [[[notification userInfo] objectForKey:@"NSTextMovement"] unsignedIntValue];
    NSWindow *window = [self window];

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

- (void)mouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down((OSControl *)self) == TRUE)
        [super mouseDown:theEvent];
}

/*---------------------------------------------------------------------------*/

/*
- (IBAction)onSelectionChange:(id)sender
{
    cassert(sender == self);
    if ([self isEnabled] == YES && self->OnSelect.object != NULL)
    {
        Event event;
        EvButton params;
        event.type = ekGUI_EVENT_BUTTON_PUSH;
        event.sender1 = self;
        event.params1 = &params;
        event.result1 = NULL;
        #if defined (__ASSERTS__)
        event.sender_type = "OSCombo";
        event.params_type = "EvButton";
        event.result_type = "";
        #endif
        params.state = ekGUI_STATE_ON;
        params.index = (uint16_t)[self indexOfSelectedItem];
        params.text = NULL;
        listener_event(&self->OnSelect, &event);
    }
}*/

@end

/*---------------------------------------------------------------------------*/

OSCombo *oscombo_create(const uint32_t flags)
{
    OSXCombo *combo = nil;
    NSComboBoxCell *cell = nil;
    unref(flags);
    heap_auditor_add("OSXCombo");
    combo = [[OSXCombo alloc] initWithFrame:NSZeroRect];
    combo->OnFilter = NULL;
    combo->OnChange = NULL;
    combo->OnFocus = NULL;
    combo->OnSelect = NULL;
    _oscontrol_init(combo);
    _oscontrol_init_textattr(&combo->attrs);
    _oscontrol_set_align(combo, &combo->attrs, ekLEFT);
    _oscontrol_set_font(combo, &combo->attrs, combo->attrs.font);
    cell = [combo cell];
    [cell setStringValue:@""];
    _oscontrol_cell_set_control_size(cell, ekGUI_SIZE_REGULAR);
    /*[combo setTarget:combo];*/
    /*[combo setAction:@selector(onSelectionChange:)];*/
    [combo setUsesDataSource:NO];
    [combo setEditable:YES];
    [combo setSelectable:YES];
    [combo setHasVerticalScroller:YES];
    [combo setNumberOfVisibleItems:10];
    return (OSCombo *)combo;
}

/*---------------------------------------------------------------------------*/

void oscombo_destroy(OSCombo **combo)
{
    OSXCombo *lcombo = nil;
    cassert_no_null(combo);
    lcombo = (OSXCombo *)*combo;
    cassert_no_null(lcombo);
    listener_destroy(&lcombo->OnFilter);
    listener_destroy(&lcombo->OnChange);
    listener_destroy(&lcombo->OnFocus);
    listener_destroy(&lcombo->OnSelect);
    _oscontrol_remove_textattr(&lcombo->attrs);
    [lcombo release];
    *combo = NULL;
    heap_auditor_delete("OSXCombo");
}

/*---------------------------------------------------------------------------*/

void oscombo_OnFilter(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&((OSXCombo *)combo)->OnFilter, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnChange(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&((OSXCombo *)combo)->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnFocus(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&((OSXCombo *)combo)->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnSelect(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&((OSXCombo *)combo)->OnSelect, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_text(OSCombo *combo, const char_t *text)
{
    _oscontrol_set_text((OSXCombo *)combo, &((OSXCombo *)combo)->attrs, text);
}

/*---------------------------------------------------------------------------*/

void oscombo_tooltip(OSCombo *combo, const char_t *text)
{
    _oscontrol_tooltip_set((OSXCombo *)combo, text);
}

/*---------------------------------------------------------------------------*/

void oscombo_font(OSCombo *combo, const Font *font)
{
    _oscontrol_set_font((OSXCombo *)combo, &((OSXCombo *)combo)->attrs, font);
}

/*---------------------------------------------------------------------------*/

void oscombo_align(OSCombo *combo, const align_t align)
{
    _oscontrol_set_align((OSXCombo *)combo, &((OSXCombo *)combo)->attrs, align);
}

/*---------------------------------------------------------------------------*/

void oscombo_passmode(OSCombo *combo, const bool_t passmode)
{
    /* Utilizar NSSecureTextFieldCell al crear el control */
    unref(combo);
    unref(passmode);
    cassert_msg(FALSE, "Not implemented");
}

/*---------------------------------------------------------------------------*/

void oscombo_color(OSCombo *combo, const color_t color)
{
    _oscontrol_set_text_color((OSXCombo *)combo, &((OSXCombo *)combo)->attrs, color);
}

/*---------------------------------------------------------------------------*/

void oscombo_bgcolor(OSCombo *combo, const color_t color)
{
    NSColor *nscolor = nil;
    cassert_no_null(combo);
    if (color != 0)
        nscolor = _oscontrol_color(color);
    else
        nscolor = [NSColor textBackgroundColor];
    [(OSXCombo *)combo setBackgroundColor:nscolor];
}

/*---------------------------------------------------------------------------*/

void oscombo_elem(OSCombo *combo, const ctrl_op_t op, const uint32_t idx, const char_t *text, const Image *image)
{
    cassert_no_null(combo);
    unref(image);
    if (op != ekCTRL_OP_DEL)
    {
        NSString *str = [[NSString alloc] initWithUTF8String:(const char *)text];

        switch (op)
        {
        case ekCTRL_OP_ADD:
            [(NSComboBox *)combo addItemWithObjectValue:str];
            break;
        case ekCTRL_OP_INS:
            [(NSComboBox *)combo insertItemWithObjectValue:str atIndex:(NSInteger)idx];
            break;
        case ekCTRL_OP_SET:
            [(NSComboBox *)combo removeItemAtIndex:(NSInteger)idx];
            [(NSComboBox *)combo insertItemWithObjectValue:str atIndex:(NSInteger)idx];
            break;
        case ekCTRL_OP_DEL:
            cassert_default();
        }

        [str release];
    }
    else
    {
        [(NSComboBox *)combo removeItemAtIndex:(NSInteger)idx];
    }
}

/*---------------------------------------------------------------------------*/

void oscombo_selected(OSCombo *combo, const uint32_t idx)
{
    cassert_no_null(combo);
    if (idx == UINT32_MAX)
    {
        NSInteger selected = [(OSXCombo *)combo indexOfSelectedItem];
        if (selected != -1)
            [(OSXCombo *)combo deselectItemAtIndex:selected];
    }
    else
    {
        [(OSXCombo *)combo selectItemAtIndex:(NSInteger)idx];
    }
}

/*---------------------------------------------------------------------------*/

uint32_t oscombo_get_selected(const OSCombo *combo)
{
    cassert_no_null(combo);
    return (uint32_t)[(OSXCombo *)combo indexOfSelectedItem];
}

/*---------------------------------------------------------------------------*/

void oscombo_bounds(const OSCombo *combo, const real32_t refwidth, real32_t *width, real32_t *height)
{
    cassert_no_null(combo);
    cassert_no_null(width);
    cassert_no_null(height);
    _oscontrol_text_bounds(((OSXCombo *)combo)->attrs.font, "OO", -1.f, width, height);
    *width = refwidth;
    *height = 27.f;
}

/*---------------------------------------------------------------------------*/

void oscombo_attach(OSCombo *combo, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)combo);
}

/*---------------------------------------------------------------------------*/

void oscombo_detach(OSCombo *combo, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)combo);
}

/*---------------------------------------------------------------------------*/

void oscombo_visible(OSCombo *combo, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)combo, is_visible);
}

/*---------------------------------------------------------------------------*/

void oscombo_enabled(OSCombo *combo, const bool_t is_enabled)
{
    OSXCombo *lcombo = (OSXCombo *)combo;
    _oscontrol_set_enabled(lcombo, is_enabled);
    _oscontrol_set_text_color(lcombo, &lcombo->attrs, lcombo->attrs.color);
}

/*---------------------------------------------------------------------------*/

void oscombo_size(const OSCombo *combo, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)combo, width, height);
}

/*---------------------------------------------------------------------------*/

void oscombo_origin(const OSCombo *combo, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)combo, x, y);
}

/*---------------------------------------------------------------------------*/

void oscombo_frame(OSCombo *combo, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((NSView *)combo, x, y, width, height);
    [(NSView *)combo setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

bool_t oscombo_resign_focus(const OSCombo *combo)
{
    bool_t lost_focus = TRUE;
    OSXCombo *lcombo = (OSXCombo *)combo;
    cassert_no_null(lcombo);
    if (lcombo->OnChange != NULL && _oswindow_in_destroy([lcombo window]) == NO)
    {
        EvText params;
        params.text = (const char_t *)[[lcombo stringValue] UTF8String];
        listener_event(lcombo->OnChange, ekGUI_EVENT_TXTCHANGE, combo, &params, &lost_focus, OSCombo, EvText, bool_t);
    }

    return lost_focus;
}

/*---------------------------------------------------------------------------*/

void oscombo_focus(OSCombo *combo, const bool_t focus)
{
    OSXCombo *lcombo = (OSXCombo *)combo;
    cassert_no_null(lcombo);
    if (lcombo->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(lcombo->OnFocus, ekGUI_EVENT_FOCUS, combo, &params, NULL, OSCombo, bool_t, void);
    }

    if (focus == FALSE)
        [[lcombo window] endEditingFor:nil];
}

/*---------------------------------------------------------------------------*/

BOOL _oscombo_is(NSView *view)
{
    return [view isKindOfClass:[OSXCombo class]];
}
