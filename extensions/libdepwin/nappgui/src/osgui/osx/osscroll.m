/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osscroll.m
 *
 */

/* Operating System native scrollbar */

#include "osscroll.inl"
#include "osscroll_osx.inl"
#include "oscontrol_osx.inl"
#include "osview_osx.inl"
#include <core/heap.h>
#include <sewer/cassert.h>

@interface OSXScroller : NSScroller
{
  @public
    OSControl *control;
    gui_orient_t orient;
    uint32_t pos;
    uint32_t page;
    uint32_t max;
    uint32_t bar_width;
    uint32_t click_pos;
    uint32_t knob_size;
    CGFloat mouse_click;
    double px_scroll;
}
@end

/*---------------------------------------------------------------------------*/

static const uint32_t i_MIN_KNOB = 20;

/*---------------------------------------------------------------------------*/

static NSView *i_parent(OSXScroller *scroller)
{
    cassert_no_null(scroller);
    cassert_no_null(scroller->control);
    cassert([(NSObject *)scroller->control isKindOfClass:[NSView class]]);
    return (NSView *)scroller->control;
}

/*---------------------------------------------------------------------------*/

static __INLINE double i_max_val(const OSXScroller *scroller)
{
    cassert_no_null(scroller);
    cassert(scroller->max >= scroller->page);
    cassert(scroller->page > 0);
    return (double)(scroller->max - scroller->page);
}

/*---------------------------------------------------------------------------*/

static void i_scroller_event(OSXScroller *scroller)
{
    NSView *parent = i_parent(scroller);
    cassert_no_null(scroller);
    if (_osview_is(parent) == YES)
    {
        _osview_scroll_event(parent, scroller->orient, ekGUI_SCROLL_THUMB);
    }
    else
    {
        cassert(FALSE);
    }
}

/*---------------------------------------------------------------------------*/

static NSScrollerPart i_hit_pos(const OSXScroller *scroller, uint32_t pos, double *val)
{
    double sp = [scroller doubleValue];
    uint32_t st = (uint32_t)(sp * ((double)scroller->page - (double)scroller->knob_size));
    uint32_t ed = st + scroller->knob_size;
    cassert_no_null(val);

    /* New scroller value associated with click point */
    *val = ((double)pos - (double)(scroller->knob_size / 2)) / (double)(scroller->page - scroller->knob_size);

    /* Click before the knob */
    if (pos < st)
    {
        return NSScrollerDecrementPage;
    }
    /* Click after the knob */
    else if (pos > ed)
    {
        return NSScrollerIncrementPage;
    }

    /* Click over the knob */
    return NSScrollerKnob;
}

/*---------------------------------------------------------------------------*/

@implementation OSXScroller

#if defined(MAC_OS_X_VERSION_10_7) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7

+ (BOOL)isCompatibleWithOverlayScrollers
{
    return NO;
}

#endif

/*---------------------------------------------------------------------------*/

- (void)mouseDown:(NSEvent *)theEvent
{
    NSView *parent = i_parent(self);
    NSPoint pt;
    NSScrollerPart hit_part;
    double hitval;
    cassert_no_null(self);
    cassert_no_null(theEvent);
    pt = [parent convertPoint:[theEvent locationInWindow] fromView:nil];

    if (self->orient == ekGUI_HORIZONTAL)
        self->mouse_click = pt.x;
    else
        self->mouse_click = pt.y;

    hit_part = i_hit_pos(self, (uint32_t)self->mouse_click, &hitval);

    /* Click outside the knob --> First direct position event */
    if (hit_part != NSScrollerKnob)
    {
        [self setDoubleValue:hitval];
        i_scroller_event(self);
    }

    /* Begin dragging */
    self->click_pos = self->pos;
}

/*---------------------------------------------------------------------------*/

- (void)mouseUp:(NSEvent *)theEvent
{
    self->click_pos = UINT32_MAX;
    self->mouse_click = UINT32_MAX;
    unref(theEvent);
}

/*---------------------------------------------------------------------------*/

- (void)mouseDragged:(NSEvent *)theEvent
{
    cassert_no_null(self);
    cassert_no_null(theEvent);
    if (self->click_pos != UINT32_MAX)
    {
        NSView *parent = (NSView *)self->control;
        NSPoint pt = [parent convertPoint:[theEvent locationInWindow] fromView:nil];
        CGFloat diff = 0;
        double npos = 0;
        double nvalue = 0;
        cassert_no_null(theEvent);
        cassert(self->max > 0);
        if (self->orient == ekGUI_HORIZONTAL)
            diff = pt.x - self->mouse_click;
        else
            diff = pt.y - self->mouse_click;

        npos = (self->click_pos + (diff * self->px_scroll));
        nvalue = npos / i_max_val(self);

        [self setDoubleValue:nvalue];
        i_scroller_event(self);
    }
}

/*---------------------------------------------------------------------------*/

- (void)scrollWheel:(NSEvent *)theEvent
{
    NSView *parent = i_parent(self);
    gui_scroll_t ev = osscroll_wheel_event(theEvent);
    if (ev != ENUM_MAX(gui_scroll_t))
    {
        if (_osview_is(parent) == YES)
        {
            _osview_scroll_event(parent, self->orient, ev);
        }
        else
        {
            cassert(FALSE);
        }
    }
}

@end

/*---------------------------------------------------------------------------*/

static OSXScroller *i_scroller(OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert([(NSObject *)scroll isKindOfClass:[OSXScroller class]]);
    return (OSXScroller *)scroll;
}

/*---------------------------------------------------------------------------*/

static const OSXScroller *i_cscroller(const OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert([(NSObject *)scroll isKindOfClass:[OSXScroller class]]);
    return (OSXScroller *)scroll;
}

/*---------------------------------------------------------------------------*/

static OSScroll *i_create(const gui_orient_t orient, OSControl *control, NSRect rect)
{
    OSXScroller *scroll = [[OSXScroller alloc] initWithFrame:rect];
    NSControlSize csize = _oscontrol_control_size(ekGUI_SIZE_REGULAR);
    heap_auditor_add("OSXScroller");
#if defined(MAC_OS_X_VERSION_10_7) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7
    [scroll setScrollerStyle:NSScrollerStyleLegacy /*NSScrollerStyleOverlay*/];
    [scroll setKnobStyle:NSScrollerKnobStyleDefault];
#endif
    [scroll setControlSize:csize];
    [scroll setEnabled:YES];
    [scroll setAlphaValue:1];
    scroll->control = control;
    scroll->orient = orient;
    scroll->pos = 0;
    scroll->page = 0;
    scroll->max = 0;
#if defined(MAC_OS_X_VERSION_10_7) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7
    scroll->bar_width = (uint32_t)[OSXScroller scrollerWidthForControlSize:csize scrollerStyle:NSScrollerStyleLegacy];
#else
    scroll->bar_width = (uint32_t)[OSXScroller scrollerWidthForControlSize:csize];
#endif
    scroll->click_pos = UINT32_MAX;
    scroll->mouse_click = UINT32_MAX;
    [i_parent(scroll) addSubview:scroll];
    return (OSScroll *)scroll;
}

/*---------------------------------------------------------------------------*/

OSScroll *osscroll_horizontal(OSControl *control)
{
    return i_create(ekGUI_HORIZONTAL, control, NSMakeRect(0, 0, 11, 10));
}

/*---------------------------------------------------------------------------*/

OSScroll *osscroll_vertical(OSControl *control)
{
    return i_create(ekGUI_VERTICAL, control, NSMakeRect(0, 0, 10, 11));
}

/*---------------------------------------------------------------------------*/

void osscroll_destroy(OSScroll **scroll, OSControl *control)
{
    OSXScroller *scroller = nil;
    cassert_no_null(scroll);
    cassert_no_null(*scroll);
    scroller = i_scroller(*scroll);
    cassert_unref(scroller->control == control, control);
    [scroller release];
    heap_auditor_delete("OSXScroller");
    *scroll = NULL;
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_pos(const OSScroll *scroll)
{
    const OSXScroller *scroller = i_cscroller(scroll);
    return scroller->pos;
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_trackpos(const OSScroll *scroll)
{
    const OSXScroller *scroller = i_cscroller(scroll);
    double pos = [scroller doubleValue];
    cassert(pos >= 0 && pos <= 1);
    return (uint32_t)(pos * i_max_val(scroller));
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_bar_width(const OSScroll *scroll)
{
    const OSXScroller *scroller = i_cscroller(scroll);
    unref(scroller);
    return scroller->bar_width;
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_bar_height(const OSScroll *scroll)
{
    const OSXScroller *scroller = i_cscroller(scroll);
    unref(scroller);
    return scroller->bar_width;
}

/*---------------------------------------------------------------------------*/

void osscroll_set_pos(OSScroll *scroll, const uint32_t pos)
{
    OSXScroller *scroller = i_scroller(scroll);
    cassert_no_null(scroller);
    scroller->pos = pos;
    [scroller setDoubleValue:(double)pos / i_max_val(scroller)];
}

/*---------------------------------------------------------------------------*/

void osscroll_visible(OSScroll *scroll, const bool_t visible)
{
    OSXScroller *scroller = i_scroller(scroll);
    cassert_no_null(scroller);
    [scroller setHidden:visible == TRUE ? NO : YES];
}

/*---------------------------------------------------------------------------*/

void osscroll_config(OSScroll *scroll, const uint32_t pos, const uint32_t max, const uint32_t page)
{
    OSXScroller *scroller = i_scroller(scroll);
    cassert_no_null(scroller);
    cassert(page > 0);
    cassert(max >= page);
    cassert_unref(max >= pos, pos);
    scroller->max = max;
    scroller->page = page;

    /* Compute Knob size */
    {
        uint32_t scroll_req = max - page;
        if (scroll_req < page)
            scroller->knob_size = page - scroll_req;
        if (scroller->knob_size < i_MIN_KNOB)
            scroller->knob_size = i_MIN_KNOB;
    }

    {
        uint32_t motion_px = page - scroller->knob_size;
        scroller->px_scroll = (double)(max - page) / (double)motion_px;
    }

    [scroller setKnobProportion:(CGFloat)((double)scroller->knob_size / (double)page)];
    osscroll_set_pos(scroll, pos);
}

/*---------------------------------------------------------------------------*/

void osscroll_frame(OSScroll *scroll, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
    OSXScroller *scroller = i_scroller(scroll);
    cassert_no_null(scroller);
    _oscontrol_set_frame((NSView *)scroller, (real32_t)x, (real32_t)y, (real32_t)width, (real32_t)height);
}

/*---------------------------------------------------------------------------*/

void osscroll_control_scroll(OSControl *control, const int32_t incr_x, const int32_t incr_y)
{
    unref(control);
    unref(incr_x);
    unref(incr_y);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

gui_scroll_t osscroll_wheel_event(const NSEvent *event)
{
    CGFloat d = 0;
    gui_scroll_t ev = ENUM_MAX(gui_scroll_t);
    cassert_no_null(event);
    d = [event deltaY];
    if (d != 0)
    {
        if (d > 0)
            ev = ekGUI_SCROLL_STEP_LEFT;
        else
            ev = ekGUI_SCROLL_STEP_RIGHT;
    }

    return ev;
}
