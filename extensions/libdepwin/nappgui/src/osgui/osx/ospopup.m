/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospopup.m
 *
 */

/* Operating System native popup button */

#include "ospopup.h"
#include "ospopup_osx.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include "oswindow_osx.inl"
#include "osgui.inl"
#include <draw2d/image.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXPopUp : NSPopUpButton
{
  @public
    OSTextAttr attrs;
    Listener *OnSelect_listener;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXPopUp

/*---------------------------------------------------------------------------*/

- (IBAction)onSelectionChange:(id)sender
{
    cassert(sender == self);
    if ([self isEnabled] == YES && self->OnSelect_listener != NULL)
    {
        EvButton params;
        params.state = ekGUI_ON;
        params.index = (uint32_t)[self indexOfSelectedItem];
        params.text = NULL; /*(const char_t*)[[self titleOfSelectedItem] UTF8String];*/
        listener_event(self->OnSelect_listener, ekGUI_EVENT_POPUP, (OSPopUp *)sender, &params, NULL, OSPopUp, EvButton, void);
    }
}

/*---------------------------------------------------------------------------*/

- (void)mouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down((OSControl *)self) == TRUE)
        [super mouseDown:theEvent];
}

@end

/*---------------------------------------------------------------------------*/

OSPopUp *ospopup_create(const uint32_t flags)
{
    OSXPopUp *popup = nil;
    NSPopUpButtonCell *cell = nil;
    unref(flags);
    heap_auditor_add("OSXPopUp");
    popup = [[OSXPopUp alloc] initWithFrame:NSZeroRect];
    popup->OnSelect_listener = NULL;
    _oscontrol_init(popup);
    _oscontrol_init_textattr(&popup->attrs);
    _oscontrol_set_font(popup, &popup->attrs, popup->attrs.font);
    cell = [popup cell];
    /*[cell setBezelStyle:NSShadowlessSquareBezelStyle];*/
    [cell setArrowPosition:NSPopUpArrowAtBottom];
    _oscontrol_cell_set_control_size(cell, ekGUI_SIZE_REGULAR);
    [popup setPullsDown:NO];
    [popup setTarget:popup];
    [popup setAction:@selector(onSelectionChange:)];
    return (OSPopUp *)popup;
}

/*---------------------------------------------------------------------------*/

void ospopup_destroy(OSPopUp **popup)
{
    OSXPopUp *lpopup;
    cassert_no_null(popup);
    lpopup = (OSXPopUp *)*popup;
    cassert_no_null(lpopup);
    listener_destroy(&lpopup->OnSelect_listener);
    _oscontrol_remove_textattr(&lpopup->attrs);
    [lpopup release];
    *popup = NULL;
    heap_auditor_delete("OSXPopUp");
}

/*---------------------------------------------------------------------------*/

void ospopup_OnSelect(OSPopUp *popup, Listener *listener)
{
    cassert_no_null(popup);
    listener_update(&((OSXPopUp *)popup)->OnSelect_listener, listener);
}

/*---------------------------------------------------------------------------*/

static void i_add_elem(OSPopUp *popup, const char_t *text, const Image *image)
{
    NSString *str = nil;
    cassert_no_null(popup);
    cassert_no_null(text);
    unref(image);
    str = [[NSString alloc] initWithUTF8String:(const char *)text];
    [(OSXPopUp *)popup addItemWithTitle:str];
    [str release];

    if (image != NULL)
    {
        NSInteger num_items;
        NSMenuItem *item = nil;
        NSImage *nsimage = (NSImage *)image_native(image);
#if defined(__ASSERTS__)
        NSSize size = [nsimage size];
        cassert(size.width == 16.f && size.height == 16.f);
#endif

        num_items = [(OSXPopUp *)popup numberOfItems];
        cassert(num_items > 0);
        item = [(OSXPopUp *)popup itemAtIndex:num_items - 1];
        [item setImage:nsimage];
        [item setOnStateImage:nil];
        [item setMixedStateImage:nil];
    }
}

/*---------------------------------------------------------------------------*/

void ospopup_elem(OSPopUp *popup, const ctrl_op_t op, const uint32_t idx, const char_t *text, const Image *image)
{
    if (op == ekCTRL_OP_ADD)
    {
        i_add_elem(popup, text, image);
    }
    else if (op == ekCTRL_OP_SET)
    {
        NSArray *items = nil;
        NSMenuItem *item = nil;
        cassert_no_null(popup);
        items = [((OSXPopUp *)popup) itemArray];
        cassert_no_null(items);
        cassert(idx < [items count]);
        item = [items objectAtIndex:(NSUInteger)idx];

        {
            NSString *str = [[NSString alloc] initWithUTF8String:(const char *)text];
            [item setTitle:str];
            [str release];
        }

#if defined(__ASSERTS__)
        if (image != NULL)
        {
            NSSize size = [(NSImage *)image_native(image) size];
            cassert(size.width == 16.f && size.height == 16.f);
        }
#endif

        [item setImage:image != NULL ? (NSImage *)image_native(image) : nil];
    }
    else
    {
        cassert_msg(FALSE, "Not implemented");
    }
}

/*---------------------------------------------------------------------------*/

void ospopup_tooltip(OSPopUp *popup, const char_t *text)
{
    unref(popup);
    unref(text);
}

/*---------------------------------------------------------------------------*/

void ospopup_font(OSPopUp *popup, const Font *font)
{
    OSXPopUp *lpopup = (OSXPopUp *)popup;
    cassert_no_null(lpopup);
    _oscontrol_set_font(lpopup, &lpopup->attrs, font);
}

/*---------------------------------------------------------------------------*/

void ospopup_list_height(OSPopUp *popup, const uint32_t num_elems)
{
    unref(popup);
    unref(num_elems);
}

/*---------------------------------------------------------------------------*/

void ospopup_selected(OSPopUp *popup, const uint32_t lindex)
{
    OSXPopUp *lpopup = (OSXPopUp *)popup;
    cassert_no_null(lpopup);
    if (lindex != UINT32_MAX)
    {
        cassert((NSInteger)lindex <= [lpopup numberOfItems]);
        [lpopup selectItemAtIndex:(NSInteger)lindex];
    }
    else
    {
        [lpopup selectItemAtIndex:-1];
    }
}

/*---------------------------------------------------------------------------*/

uint32_t ospopup_get_selected(const OSPopUp *popup)
{
    OSXPopUp *lpopup = (OSXPopUp *)popup;
    cassert_no_null(lpopup);
    return (uint32_t)[lpopup indexOfSelectedItem];
}

/*---------------------------------------------------------------------------*/

void ospopup_bounds(const OSPopUp *popup, const char_t *text, real32_t *width, real32_t *height)
{
    OSXPopUp *lpopup = (OSXPopUp *)popup;
    cassert_no_null(lpopup);
    cassert_no_null(width);
    cassert_no_null(height);
    _oscontrol_text_bounds(lpopup->attrs.font, text, -1.f, width, height);
    *width += 40.f;
    *height = 24.f;
}

/*---------------------------------------------------------------------------*/

void ospopup_attach(OSPopUp *popup, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)popup);
}

/*---------------------------------------------------------------------------*/

void ospopup_detach(OSPopUp *popup, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)popup);
}

/*---------------------------------------------------------------------------*/

void ospopup_visible(OSPopUp *popup, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)popup, is_visible);
}

/*---------------------------------------------------------------------------*/

void ospopup_enabled(OSPopUp *popup, const bool_t is_enabled)
{
    _oscontrol_set_enabled((NSControl *)popup, is_enabled);
}

/*---------------------------------------------------------------------------*/

void ospopup_size(const OSPopUp *popup, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)popup, width, height);
}

/*---------------------------------------------------------------------------*/

void ospopup_origin(const OSPopUp *popup, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)popup, x, y);
}

/*---------------------------------------------------------------------------*/

void ospopup_frame(OSPopUp *popup, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((NSView *)popup, x, y, width, height);
}

/*---------------------------------------------------------------------------*/

BOOL _ospopup_is(NSView *view)
{
    return [view isKindOfClass:[OSXPopUp class]];
}
