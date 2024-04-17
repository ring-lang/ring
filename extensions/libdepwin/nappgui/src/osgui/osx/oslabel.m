/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslabel.m
 *
 */

/* Cocoa text label */

#include "oslabel.h"
#include "oslabel_osx.inl"
#include "oslistener.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include <geom2d/t2d.h>
#include <draw2d/color.h>
#include <draw2d/dctx.h>
#include <draw2d/dctxh.h>
#include <draw2d/draw.h>
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXLabel : NSView
{
  @public
    DCtx *ctx;
    String *text;
    uint32_t flags;
    color_t color;
    color_t bgcolor;
    NSTrackingArea *tracking_area;
    Listener *OnClick;
    Listener *OnMouseEntered;
    Listener *OnMouseExited;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXLabel

/*---------------------------------------------------------------------------*/

- (void)mouseEntered:(NSEvent *)theEvent
{
    cassert_no_null(theEvent);
    if (self->OnMouseEntered != NULL)
    {
        EvMouse params;
        _oslistener_mouse_position_in_view_coordinates(self, [theEvent locationInWindow], &params.x, &params.y);
        params.lx = params.x;
        params.ly = params.y;
        params.button = ENUM_MAX(gui_mouse_t);
        params.count = 0;
        params.modifiers = 0;
        params.tag = 0;
        listener_event(self->OnMouseEntered, ekGUI_EVENT_ENTER, (OSLabel *)self, &params, NULL, OSLabel, EvMouse, void);
    }
}

/*---------------------------------------------------------------------------*/

- (void)mouseExited:(NSEvent *)theEvent
{
    unref(theEvent);
    if (self->OnMouseExited != NULL)
        listener_event(self->OnMouseExited, ekGUI_EVENT_EXIT, (OSLabel *)self, NULL, NULL, OSLabel, void, void);
}

/*---------------------------------------------------------------------------*/

- (void)mouseUp:(NSEvent *)theEvent
{
    unref(theEvent);
    if (self->OnClick != NULL)
    {
        EvText params;
        params.text = NULL;
        listener_event(self->OnClick, ekGUI_EVENT_LABEL, (OSLabel *)self, &params, NULL, OSLabel, EvText, void);
    }
}

/*---------------------------------------------------------------------------*/

- (BOOL)isFlipped
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)drawRect:(NSRect)rect
{
    NSGraphicsContext *nscontext;
    unref(rect);
    cassert_no_null(self->ctx);
    nscontext = [NSGraphicsContext currentContext];
    dctx_set_gcontext(self->ctx, nscontext, (uint32_t)rect.size.width, (uint32_t)rect.size.height, 0, 0, 0, FALSE);
    if (self->bgcolor != kCOLOR_DEFAULT)
    {
        draw_fill_color(self->ctx, self->bgcolor);
        draw_rect(self->ctx, ekFILL, 0, 0, (real32_t)rect.size.width, (real32_t)rect.size.height);
    }

    if (self->color != kCOLOR_DEFAULT)
        draw_text_color(self->ctx, color);
    else
        draw_text_color(self->ctx, ekSYSCOLOR_LABEL);

    switch (label_get_type(self->flags))
    {
    case ekLABEL_SINGLE:
        draw_text_single_line(self->ctx, tc(self->text), 0, 0);
        break;
    case ekLABEL_MULTI:
        draw_text(self->ctx, tc(self->text), 0, 0);
        break;
        cassert_default();
    }

    dctx_unset_gcontext(ctx);
}

@end

/*---------------------------------------------------------------------------*/

OSLabel *oslabel_create(const uint32_t flags)
{
    OSXLabel *label = nil;
    heap_auditor_add("OSXLabel");
    label = [[OSXLabel alloc] initWithFrame:NSZeroRect];

    /* https://developer.apple.com/documentation/macos-release-notes/appkit-release-notes-for-macos-14#NSView */
#if defined(MAC_OS_VERSION_14_0) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_14
    [label setClipsToBounds:YES];
#endif

    _oscontrol_init(label);
    label->ctx = dctx_create();
    label->flags = flags;
    dctx_set_flipped(label->ctx, (bool_t)[label isFlipped]);
    label->text = str_c("");
    label->color = kCOLOR_DEFAULT;
    label->bgcolor = kCOLOR_DEFAULT;
    /*draw_font(label->ctx, kFONT_DEFAULT);*/
    draw_text_align(label->ctx, ekLEFT, ekTOP);
    draw_text_width(label->ctx, -1);
    draw_text_halign(label->ctx, ekLEFT);
    label->tracking_area = nil;
    label->OnClick = NULL;
    label->OnMouseEntered = NULL;
    label->OnMouseExited = NULL;
    return (OSLabel *)label;
}

/*---------------------------------------------------------------------------*/

void oslabel_destroy(OSLabel **label)
{
    OSXLabel *llabel = nil;
    cassert_no_null(label);
    llabel = (OSXLabel *)*label;
    cassert_no_null(llabel);
    listener_destroy(&llabel->OnClick);
    listener_destroy(&llabel->OnMouseEntered);
    listener_destroy(&llabel->OnMouseExited);
    str_destroy(&llabel->text);
    dctx_destroy(&llabel->ctx);

    if (llabel->tracking_area != nil)
    {
        [llabel removeTrackingArea:llabel->tracking_area];
        [llabel->tracking_area release];
    }

    [llabel release];
    *label = NULL;
    heap_auditor_delete("OSXLabel");
}

/*---------------------------------------------------------------------------*/

static bool_t i_is_mouse_sensible(OSXLabel *label)
{
    cassert_no_null(label);
    if (label->OnClick != NULL)
        return TRUE;
    if (label->OnMouseEntered != NULL)
        return TRUE;
    if (label->OnMouseExited != NULL)
        return TRUE;
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static void i_update_tracking_area(OSXLabel *label)
{
    bool_t with_area = i_is_mouse_sensible(label);

    if (label->tracking_area != nil && with_area == TRUE)
    {
        NSSize required_size = [label frame].size;
        NSSize current_size = [label->tracking_area rect].size;
        if (NSEqualSizes(required_size, current_size) == NO)
        {
            [label removeTrackingArea:label->tracking_area];
            [label->tracking_area release];
            label->tracking_area = [[NSTrackingArea alloc] initWithRect:NSMakeRect(0.f, 0.f, required_size.width, required_size.height) options:(NSTrackingAreaOptions)(NSTrackingMouseEnteredAndExited | NSTrackingActiveAlways) owner:label userInfo:nil];
            [label addTrackingArea:label->tracking_area];
        }

        return;
    }

    if (label->tracking_area != nil)
    {
        [label removeTrackingArea:label->tracking_area];
        [label->tracking_area release];
        label->tracking_area = nil;
    }

    if (with_area == TRUE)
    {
        NSSize size = [label frame].size;
        label->tracking_area = [[NSTrackingArea alloc] initWithRect:NSMakeRect(0.f, 0.f, size.width, size.height) options:(NSTrackingAreaOptions)(NSTrackingMouseEnteredAndExited | NSTrackingActiveAlways) owner:label userInfo:nil];
        [label addTrackingArea:label->tracking_area];
    }
}

/*---------------------------------------------------------------------------*/

void oslabel_OnClick(OSLabel *label, Listener *listener)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    listener_update(&llabel->OnClick, listener);
    i_update_tracking_area(llabel);
}

/*---------------------------------------------------------------------------*/

void oslabel_OnEnter(OSLabel *label, Listener *listener)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    listener_update(&llabel->OnMouseEntered, listener);
    i_update_tracking_area(llabel);
}

/*---------------------------------------------------------------------------*/

void oslabel_OnExit(OSLabel *label, Listener *listener)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    listener_update(&llabel->OnMouseExited, listener);
    i_update_tracking_area(llabel);
}

/*---------------------------------------------------------------------------*/

void oslabel_text(OSLabel *label, const char_t *text)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    str_upd(&llabel->text, text);
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void oslabel_font(OSLabel *label, const Font *font)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    draw_font(llabel->ctx, font);
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void oslabel_align(OSLabel *label, const align_t align)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    draw_text_halign(llabel->ctx, align);
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void oslabel_ellipsis(OSLabel *label, const ellipsis_t ellipsis)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    draw_text_trim(llabel->ctx, ellipsis);
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void oslabel_color(OSLabel *label, const color_t color)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    llabel->color = color;
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void oslabel_bgcolor(OSLabel *label, const color_t color)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    llabel->bgcolor = color;
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void oslabel_bounds(const OSLabel *label, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    draw_text_extents(llabel->ctx, text, refwidth, width, height);
}

/*---------------------------------------------------------------------------*/

void oslabel_attach(OSLabel *label, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_detach(OSLabel *label, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_visible(OSLabel *label, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)label, is_visible);
}

/*---------------------------------------------------------------------------*/

void oslabel_enabled(OSLabel *label, const bool_t is_enabled)
{
    unref(label);
    unref(is_enabled);
}

/*---------------------------------------------------------------------------*/

void oslabel_size(const OSLabel *label, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)label, width, height);
}

/*---------------------------------------------------------------------------*/

void oslabel_origin(const OSLabel *label, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)label, x, y);
}

/*---------------------------------------------------------------------------*/

void oslabel_frame(OSLabel *label, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    OSXLabel *llabel = (OSXLabel *)label;
    cassert_no_null(llabel);
    _oscontrol_set_frame(llabel, x, y, width, height);
    draw_text_width(llabel->ctx, width);
    i_update_tracking_area((OSXLabel *)label);
    [llabel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

BOOL _oslabel_is(NSView *view)
{
    return [view isKindOfClass:[OSXLabel class]];
}
