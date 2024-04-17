/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ossplit.m
 *
 */

/* Operating System split view */

#include "ossplit.h"
#include "osgui_osx.inl"
#include "ossplit_osx.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include "osgui.inl"
#include "oslistener.inl"
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

@interface OSXSplitView : NSView
{
  @public
    uint32_t flags;
    NSTrackingArea *track_area;
    NSRect divrect;
    bool_t left_button;
    Listener *OnDrag;
}

- (void)mouseDragged:(NSEvent *)theEvent;
- (void)mouseUp:(NSEvent *)theEvent;

@end

/*---------------------------------------------------------------------------*/

@implementation OSXSplitView

/*---------------------------------------------------------------------------*/

static NSCursor *i_cursor(NSView *view, NSPoint *pt_window)
{
    NSPoint pt = [view convertPoint:*pt_window fromView:nil];

    if ([view isKindOfClass:[OSXSplitView class]])
    {
        OSXSplitView *split = (OSXSplitView *)view;
        if (NSPointInRect(pt, split->divrect) == YES)
        {
            if (split_get_type(split->flags) == ekSPLIT_HORZ)
                return [NSCursor resizeUpDownCursor];
            else
                return [NSCursor resizeLeftRightCursor];
        }
    }

    for (NSView *child in [view subviews])
    {
        NSRect rect = [child frame];
        if (NSPointInRect(pt, rect) == YES)
            return i_cursor(child, pt_window);
    }

    return [NSCursor arrowCursor];
}

/*---------------------------------------------------------------------------*/

- (void)mouseMoved:(NSEvent *)event
{
    cassert_no_null(event);
    if (self->left_button == FALSE)
    {
        NSPoint pt = [event locationInWindow];
        NSCursor *cursor = i_cursor(self, &pt);
        cassert(cursor != nil);
        [cursor set];
    }
}

/*---------------------------------------------------------------------------*/

- (NSView *)hitTest:(NSPoint)aPoint
{
    if (self->left_button == FALSE)
    {
        NSPoint local_point = [self convertPoint:aPoint fromView:[self superview]];
        if (NSPointInRect(local_point, self->divrect) == YES)
        {
            return self;
        }
        else
        {
            NSArray *children = [self subviews];
            NSUInteger count = [children count];
            NSView *child1 = nil;
            NSView *hit1 = nil;
            cassert(count == 1 || count == 2);
            child1 = (NSView *)[children objectAtIndex:0];
            hit1 = [child1 hitTest:aPoint];
            if (hit1 != nil)
            {
                return hit1;
            }
            else if (count == 2)
            {
                NSView *child2 = (NSView *)[children objectAtIndex:1];
                return [child2 hitTest:aPoint];
            }
            else
            {
                return nil;
            }
        }
    }
    else
    {
        return nil;
    }
}

/*---------------------------------------------------------------------------*/

- (void)mouseDragged:(NSEvent *)theEvent
{
    /* Called whenever graphics state updated (such as window resize)
     * OpenGL rendering is not synchronous with other rendering on the OSX.
     * Therefore, call disableScreenUpdatesUntilFlush so the window server
     * doesn't render non-OpenGL content in the window asynchronously from
     * OpenGL content, which could cause flickering.  (non-OpenGL content
     * includes the title bar and drawing done by the app with other APIs) */
    NSWindow *window = [self window];
    if (window != nil)
        [window disableScreenUpdatesUntilFlush];

    if (self->left_button == TRUE)
    {
        _oslistener_mouse_dragged2(self, theEvent, ekGUI_MOUSE_LEFT, NULL, self->OnDrag);
        [window disableCursorRects];
        if (split_get_type(self->flags) == ekSPLIT_HORZ)
            [[NSCursor resizeUpDownCursor] set];
        else
            [[NSCursor resizeLeftRightCursor] set];
    }
}

/*---------------------------------------------------------------------------*/

- (void)mouseDown:(NSEvent *)theEvent
{
    unref(theEvent);
    cassert(self->left_button == FALSE);
    self->left_button = TRUE;
}

/*---------------------------------------------------------------------------*/

- (void)mouseUp:(NSEvent *)theEvent
{
    unref(theEvent);
    if (self->left_button == TRUE)
    {
        NSWindow *window = [self window];
        self->left_button = FALSE;
        [window enableCursorRects];
        [window resetCursorRects];
    }
}

/*---------------------------------------------------------------------------*/

- (BOOL)isFlipped
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)dealloc
{
    [super dealloc];
    heap_auditor_delete("OSXSplit");
}

@end

/*---------------------------------------------------------------------------*/

BOOL _ossplit_is(NSView *view)
{
    return [view isKindOfClass:[OSXSplitView class]];
}

/*---------------------------------------------------------------------------*/

OSSplit *ossplit_create(const uint32_t flags)
{
    OSXSplitView *view;
    heap_auditor_add("OSXSplit");
    view = [[OSXSplitView alloc] initWithFrame:NSZeroRect];
    view->flags = flags;
    view->track_area = [[NSTrackingArea alloc] initWithRect:NSZeroRect options:(NSTrackingAreaOptions)(NSTrackingMouseEnteredAndExited | NSTrackingActiveAlways) owner:view userInfo:nil];
    view->divrect = NSZeroRect;
    view->left_button = FALSE;
    view->OnDrag = NULL;
    [view addTrackingArea:view->track_area];
    [view setAutoresizesSubviews:NO];
    return (OSSplit *)view;
}

/*---------------------------------------------------------------------------*/

void ossplit_destroy(OSSplit **view)
{
    OSXSplitView *split = nil;
    cassert_no_null(view);
    split = *(OSXSplitView **)view;
    cassert_no_null(split);
    cassert([[split subviews] count] == 0);
    listener_destroy(&split->OnDrag);
    [split removeTrackingArea:split->track_area];
    [split->track_area release];
    [split release];
    *view = NULL;
}

/*---------------------------------------------------------------------------*/

#if defined(__ASSERTS__)
static BOOL i_exists_subview(OSXSplitView *view, NSView *subview)
{
    NSArray *subviews = [view subviews];
    NSUInteger count = [subviews count];
    NSUInteger i = 0;
    cassert(count <= 2);
    for (i = 0; i < count; ++i)
    {
        if ([subviews objectAtIndex:i] == subview)
            return YES;
    }

    return NO;
}
#endif

/*---------------------------------------------------------------------------*/

void ossplit_attach_control(OSSplit *view, OSControl *control)
{
    cassert_no_null(view);
    cassert_no_null(control);
    cassert(i_exists_subview((OSXSplitView *)view, (NSView *)control) == NO);
    [(OSXSplitView *)view addSubview:(NSView *)control];
    cassert(i_exists_subview((OSXSplitView *)view, (NSView *)control) == YES);
}

/*---------------------------------------------------------------------------*/

void ossplit_detach_control(OSSplit *view, OSControl *control)
{
    cassert_no_null(view);
    cassert_no_null(control);
    cassert([(NSView *)control superview] == (OSXSplitView *)view);
    cassert(i_exists_subview((OSXSplitView *)view, (NSView *)control) == YES);
    [(NSView *)control removeFromSuperviewWithoutNeedingDisplay];
    cassert(i_exists_subview((OSXSplitView *)view, (NSView *)control) == NO);
}

/*---------------------------------------------------------------------------*/

void ossplit_OnDrag(OSSplit *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&((OSXSplitView *)view)->OnDrag, listener);
}

/*---------------------------------------------------------------------------*/

void ossplit_track_area(OSSplit *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    OSXSplitView *split = (OSXSplitView *)view;
    cassert_no_null(split);
    split->divrect = NSMakeRect((CGFloat)x, (CGFloat)y, (CGFloat)width, (CGFloat)height);
}

/*---------------------------------------------------------------------------*/

void ossplit_attach(OSSplit *view, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)view);
}

/*---------------------------------------------------------------------------*/

void ossplit_detach(OSSplit *view, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)view);
}

/*---------------------------------------------------------------------------*/

void ossplit_visible(OSSplit *view, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)view, is_visible);
}

/*---------------------------------------------------------------------------*/

void ossplit_enabled(OSSplit *view, const bool_t is_enabled)
{
    unref(view);
    unref(is_enabled);
}

/*---------------------------------------------------------------------------*/

void ossplit_size(const OSSplit *view, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)view, width, height);
}

/*---------------------------------------------------------------------------*/

void ossplit_origin(const OSSplit *view, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)view, x, y);
}

/*---------------------------------------------------------------------------*/

void ossplit_frame(OSSplit *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    OSXSplitView *split = (OSXSplitView *)view;
    cassert_no_null(split);
    _oscontrol_set_frame(split, x, y, width, height);
    [split removeTrackingArea:split->track_area];
    [split->track_area release];
    split->track_area = [[NSTrackingArea alloc] initWithRect:NSMakeRect((CGFloat)x, (CGFloat)y, (CGFloat)width, (CGFloat)height) options:(NSTrackingAreaOptions)(NSTrackingMouseMoved | NSTrackingActiveInActiveApp) owner:split userInfo:nil];
    [split addTrackingArea:split->track_area];
}
