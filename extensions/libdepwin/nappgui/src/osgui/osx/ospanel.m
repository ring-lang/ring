/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel.m
 *
 */

/* Operating System native panel */

#include "ospanel.h"
#include "ospanel_osx.inl"
#include "oscontrol_osx.inl"
#include "oscontrol.inl"
#include "osgui.inl"
#include <core/arrst.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

typedef struct _area_t Area;
struct _area_t
{
    void *obj;
    NSRect rect;
    NSColor *bgcolor;
    NSColor *skcolor;
};

DeclSt(Area);

/*---------------------------------------------------------------------------*/

@interface OSXPanel : NSView
{
  @public
    NSScrollView *scroll;
    CGSize content_size;
    ArrSt(Area) *areas;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXPanel

/*---------------------------------------------------------------------------*/

- (void)dealloc
{
    [super dealloc];
    heap_auditor_delete("OSXPanel");
}

/*---------------------------------------------------------------------------*/

- (void)drawRect:(NSRect)rect
{
    [super drawRect:rect];
    if (self->areas != NULL)
    {
        arrst_foreach(area, self->areas, Area)
            if (area->bgcolor != nil)
            {
                [area->bgcolor set];
                NSRectFill(area->rect);
            }
            if (area->skcolor != NULL)
            {
                [area->skcolor set];
                NSFrameRect(area->rect);
            }
        arrst_end()
    }
}

/*---------------------------------------------------------------------------*/

- (BOOL)isFlipped
{
    return YES;
}

@end

/*---------------------------------------------------------------------------*/

OSPanel *ospanel_create(const uint32_t flags)
{
    OSXPanel *panel = nil;
    heap_auditor_add("OSXPanel");
    panel = [[OSXPanel alloc] initWithFrame:NSZeroRect];
    panel->areas = NULL;
    panel->content_size = CGSizeMake(-1, -1);
    [panel setAutoresizesSubviews:NO];

    if (flags & ekVIEW_HSCROLL || flags & ekVIEW_VSCROLL)
    {
        NSScrollView *scroll = [[NSScrollView alloc] initWithFrame:NSZeroRect];
        [scroll setDrawsBackground:NO];
        [scroll setDocumentView:panel];
        [scroll setHasHorizontalScroller:(flags & ekVIEW_HSCROLL) ? YES : NO];
        [scroll setHasVerticalScroller:(flags & ekVIEW_VSCROLL) ? YES : NO];
        [scroll setAutohidesScrollers:YES];
        [scroll setBorderType:(flags & ekVIEW_BORDER) ? NSGrooveBorder : NSNoBorder];
        panel->scroll = scroll;
        return (OSPanel *)scroll;
    }
    else
    {
        panel->scroll = nil;
        return (OSPanel *)panel;
    }
}

/*---------------------------------------------------------------------------*/

static void i_remove_area(Area *area)
{
    if (area->bgcolor != nil)
        [area->bgcolor release];
    if (area->skcolor != nil)
        [area->skcolor release];
}

/*---------------------------------------------------------------------------*/

static OSXPanel *i_get_panel(const OSPanel *panel)
{
    cassert_no_null(panel);
    if ([(NSView *)panel isKindOfClass:[OSXPanel class]])
    {
        return (OSXPanel *)panel;
    }
    else
    {
        NSScrollView *scroll = (NSScrollView *)panel;
        return [scroll documentView];
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_destroy(OSPanel **panel)
{
    OSXPanel *lpanel;
    NSScrollView *scroll = nil;

    cassert_no_null(panel);
    lpanel = i_get_panel(*panel);
    cassert_no_null(lpanel);
    cassert([[lpanel subviews] count] == 0);

    if (lpanel->areas != NULL)
        arrst_destroy(&lpanel->areas, i_remove_area, Area);

    scroll = lpanel->scroll;
    [lpanel release];

    if (scroll != nil)
        [scroll release];

    *panel = NULL;
}

/*---------------------------------------------------------------------------*/

BOOL _ospanel_is(NSView *view)
{
    return [view isKindOfClass:[OSXPanel class]];
}

/*---------------------------------------------------------------------------*/

void _ospanel_destroy(OSPanel **panel)
{
    register OSXPanel *panelp;
    register NSArray *subviews;
    register NSUInteger i, num_elems;
    cassert_no_null(panel);
    panelp = i_get_panel(*panel);
    cassert_no_null(panelp);
    subviews = [panelp subviews];
    num_elems = [subviews count];
    for (i = 0; i < num_elems; ++i)
    {
        NSView *child = [subviews objectAtIndex:0];
        oscontrol_detach_and_destroy(OSControlDPtr(&child), *panel);
        cassert([subviews count] == num_elems - i - 1);
    }

    ospanel_destroy(panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_area(OSPanel *panel, void *obj, const color_t bgcolor, const color_t skcolor, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    OSXPanel *lpanel = i_get_panel(panel);
    cassert_no_null(lpanel);
    if (obj != NULL)
    {
        Area *area = NULL;

        if (lpanel->areas == NULL)
            lpanel->areas = arrst_create(Area);

        arrst_foreach(larea, lpanel->areas, Area)
            if (larea->obj == obj)
            {
                area = larea;
                break;
            }
        arrst_end()

        if (area == NULL)
        {
            area = arrst_new(lpanel->areas, Area);
            area->obj = obj;
            area->bgcolor = nil;
            area->skcolor = nil;
        }

        area->rect.origin.x = (CGFloat)x;
        area->rect.origin.y = (CGFloat)y;
        area->rect.size.width = (CGFloat)width;
        area->rect.size.height = (CGFloat)height;

        if (area->bgcolor != nil)
        {
            [area->bgcolor release];
            area->bgcolor = nil;
        }

        if (area->skcolor != nil)
        {
            [area->skcolor release];
            area->skcolor = nil;
        }

        if (bgcolor != 0)
            area->bgcolor = [_oscontrol_color(bgcolor) retain];

        if (skcolor != 0)
            area->skcolor = [_oscontrol_color(skcolor) retain];
    }
    else
    {
        if (lpanel->areas != NULL)
            arrst_clear(lpanel->areas, i_remove_area, Area);
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_scroller_size(const OSPanel *panel, real32_t *width, real32_t *height)
{
    if ([(NSView *)panel isKindOfClass:[NSScrollView class]])
    {
        NSScrollView *scroll = (NSScrollView *)panel;

        if (width)
        {
            NSScroller *scroller = [scroll verticalScroller];
            *width = 0;
            if (scroller != nil)
                *width = (real32_t)[scroller frame].size.width;
        }

        if (height)
        {
            NSScroller *scroller = [scroll horizontalScroller];
            *height = 0;
            if (scroller != nil)
                *height = (real32_t)[scroller frame].size.height;
        }
    }
    else
    {
        if (width)
            *width = 16;

        if (height)
            *height = 16;
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnUpdateSize(OSPanel *panel)
{
    OSXPanel *lpanel = i_get_panel(panel);
    if ([(NSView *)panel isKindOfClass:[NSScrollView class]])
    {
        CGFloat diff = 0;
        NSScroller *scroller = [(NSScrollView *)panel verticalScroller];
        if (scroller != nil && [scroller isHidden] == NO)
            diff = [scroller frame].size.width;

        [lpanel setFrame:NSMakeRect(0, 0, lpanel->content_size.width - diff, lpanel->content_size.height)];
    }
    else
    {
        cassert(lpanel->content_size.width == -1);
        cassert(lpanel->content_size.height == -1);
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_content_size(OSPanel *panel, const real32_t width, const real32_t height, const real32_t line_width, const real32_t line_height)
{
    OSXPanel *lpanel = i_get_panel(panel);
    cassert([(NSView *)panel isKindOfClass:[NSScrollView class]]);
    cassert(lpanel == [(NSScrollView *)panel documentView]);
    unref(line_width);
    unref(line_height);
    lpanel->content_size.width = (CGFloat)width;
    lpanel->content_size.height = (CGFloat)height;
    i_OnUpdateSize(panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_display(OSPanel *panel)
{
    OSXPanel *lpanel = i_get_panel(panel);
    [lpanel setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void ospanel_attach(OSPanel *panel, OSPanel *parent_panel)
{
    _oscontrol_attach_to_parent((NSView *)panel, (NSView *)parent_panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_detach(OSPanel *panel, OSPanel *parent_panel)
{
    _oscontrol_detach_from_parent((NSView *)panel, (NSView *)parent_panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_visible(OSPanel *panel, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)panel, is_visible);
}

/*---------------------------------------------------------------------------*/

void ospanel_enabled(OSPanel *panel, const bool_t is_enabled)
{
    unref(panel);
    unref(is_enabled);
}

/*---------------------------------------------------------------------------*/

void ospanel_size(const OSPanel *panel, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)panel, width, height);
}

/*---------------------------------------------------------------------------*/

void ospanel_origin(const OSPanel *panel, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)panel, x, y);
}

/*---------------------------------------------------------------------------*/

void ospanel_frame(OSPanel *panel, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((NSView *)panel, x, y, width, height);
    i_OnUpdateSize(panel);
}

/*---------------------------------------------------------------------------*/

void _ospanel_attach_control(OSPanel *panel, NSView *control)
{
    OSXPanel *lpanel = i_get_panel(panel);
    _oscontrol_attach_to_parent(control, (NSView *)lpanel);
}

/*---------------------------------------------------------------------------*/

void _ospanel_detach_control(OSPanel *panel, NSView *control)
{
    OSXPanel *lpanel = i_get_panel(panel);
    _oscontrol_detach_from_parent(control, (NSView *)lpanel);
}

/*---------------------------------------------------------------------------*/

bool_t ospanel_with_scroll(const OSPanel *panel)
{
    OSXPanel *lpanel = i_get_panel(panel);
    return (bool_t)(lpanel->scroll != nil);
}

/*---------------------------------------------------------------------------*/

void ospanel_scroll(OSPanel *panel, const int32_t x, const int32_t y)
{
    NSPoint origin;
    OSXPanel *lpanel = i_get_panel(panel);
    cassert_no_null(lpanel->scroll);
    origin = [lpanel->scroll documentVisibleRect].origin;
    if (x != INT32_MAX)
        origin.x = (CGFloat)x;
    if (y != INT32_MAX)
        origin.y = (CGFloat)y;

    /* https://stackoverflow.com/questions/5834056/how-i-set-the-default-position-of-a-nsscroll-view */
    [[lpanel->scroll contentView] scrollToPoint:origin];
    [lpanel->scroll reflectScrolledClipView:[lpanel->scroll contentView]];
}

/*---------------------------------------------------------------------------*/

void ospanel_scroll_frame(const OSPanel *panel, OSFrame *rect)
{
    NSRect frame;
    OSXPanel *lpanel = i_get_panel(panel);
    cassert_no_null(rect);
    cassert_no_null(lpanel->scroll);
    frame = [lpanel->scroll documentVisibleRect];
    rect->left = (int32_t)frame.origin.x;
    rect->top = (int32_t)frame.origin.y;
    rect->right = rect->left + (int32_t)frame.size.width;
    rect->bottom = rect->top + (int32_t)frame.size.height;
}
