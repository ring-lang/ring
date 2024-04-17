/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osview.m
 *
 */

/* Cocoa CustomView */

#include "osview.h"
#include "osview.inl"
#include "osview_osx.inl"
#include "osgui.inl"
#include "oslistener.inl"
#include "osscrolls.inl"
#include "osscroll_osx.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include "oswindow_osx.inl"
#include <draw2d/dctxh.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXView : NSView
{
  @public
    OSScrolls *scroll;
    DCtx *ctx;
    uint32_t flags;
    NSTrackingArea *tracking_area;
    ViewListeners listeners;
    OSDraw osdraw;
    Listener *OnFocus;
    Listener *OnResignFocus;
    Listener *OnAcceptFocus;
    Listener *OnOverlay;
    BOOL mouse_inside;
    BOOL focused;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXView

/*---------------------------------------------------------------------------*/

- (void)drawFocusRingMask
{
    NSRectFill([self bounds]);
}

/*---------------------------------------------------------------------------*/

- (NSRect)focusRingMaskBounds
{
    return [self bounds];
}

/*---------------------------------------------------------------------------*/

- (void)drawRect:(NSRect)rect
{
    if (self->listeners.OnDraw != NULL)
    {
        EvDraw params;
        rect = [self frame];
        params.ctx = NULL;
        params.x = 0;
        params.y = 0;
        params.width = (real32_t)rect.size.width;
        params.height = (real32_t)rect.size.height;

        if (self->scroll != NULL)
        {
            params.x = (real32_t)osscrolls_x_pos(self->scroll);
            params.y = (real32_t)osscrolls_y_pos(self->scroll);
        }

        if ((self->flags & ekVIEW_OPENGL) == 0)
        {
            NSGraphicsContext *nscontext;

            if (self->ctx == NULL)
            {
                self->ctx = dctx_create();
                dctx_set_flipped(self->ctx, (bool_t)[self isFlipped]);
                dctx_data(self->ctx, &self->osdraw, NULL, OSDraw);
            }

            params.ctx = self->ctx;
            nscontext = [NSGraphicsContext currentContext];
            dctx_set_gcontext(self->ctx, nscontext, (uint32_t)rect.size.width, (uint32_t)rect.size.height, params.x, params.y, 0, TRUE);
            listener_event(self->listeners.OnDraw, ekGUI_EVENT_DRAW, (OSView *)self, &params, NULL, OSView, EvDraw, void);
            dctx_unset_gcontext(self->ctx);

            if (self->OnOverlay != NULL)
            {
                params.x = 0;
                params.y = 0;
                dctx_set_gcontext(self->ctx, nscontext, (uint32_t)rect.size.width, (uint32_t)rect.size.height, 0, 0, 0, TRUE);
                listener_event(self->OnOverlay, ekGUI_EVENT_OVERLAY, (OSView *)self, &params, NULL, OSView, EvDraw, void);
                dctx_unset_gcontext(self->ctx);
            }
        }
        else
        {
            listener_event(self->listeners.OnDraw, ekGUI_EVENT_DRAW, (OSView *)self, &params, NULL, OSView, EvDraw, void);
        }
    }

    /* Draw focus ring in older mac OSX */
#if defined(MAC_OS_X_VERSION_10_11) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_11
#else
    if (self->flags & ekVIEW_BORDER)
    {
        if (self->focused == YES)
        {
            NSRect r = [self bounds];
            if (self->scroll != NULL)
            {
                r.size.width -= (CGFloat)(osscrolls_bar_width(self->scroll, TRUE) + 2);
                r.size.height -= (CGFloat)(osscrolls_bar_height(self->scroll, TRUE) + 2);
            }
            NSSetFocusRingStyle(NSFocusRingOnly);
            NSRectFill(r);
        }
    }
#endif
}

/*---------------------------------------------------------------------------*/

- (BOOL)acceptsFirstResponder
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (BOOL)mouseDownCanMoveWindow
{
    return NO;
}

/*---------------------------------------------------------------------------*/

- (void)mouseEntered:(NSEvent *)theEvent
{
    self->mouse_inside = YES;
    _oslistener_mouse_enter(self, theEvent, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)mouseExited:(NSEvent *)theEvent
{
    unref(theEvent);
    self->mouse_inside = NO;
    _oslistener_mouse_exit(self, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)mouseMoved:(NSEvent *)theEvent
{
    if (self->mouse_inside == YES)
        _oslistener_mouse_moved(self, theEvent, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)mouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down(OSControlPtr(self)) == TRUE)
        _oslistener_mouse_down(self, theEvent, ekGUI_MOUSE_LEFT, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)rightMouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down(OSControlPtr(self)) == TRUE)
        _oslistener_mouse_down(self, theEvent, ekGUI_MOUSE_RIGHT, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)otherMouseDown:(NSEvent *)theEvent
{
    if (_oswindow_mouse_down(OSControlPtr(self)) == TRUE)
        _oslistener_mouse_down(self, theEvent, ekGUI_MOUSE_MIDDLE, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)mouseUp:(NSEvent *)theEvent
{
    _oslistener_mouse_up(self, theEvent, ekGUI_MOUSE_LEFT, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)rightMouseUp:(NSEvent *)theEvent
{
    _oslistener_mouse_up(self, theEvent, ekGUI_MOUSE_RIGHT, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)otherMouseUp:(NSEvent *)theEvent
{
    _oslistener_mouse_up(self, theEvent, ekGUI_MOUSE_MIDDLE, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)mouseDragged:(NSEvent *)theEvent
{
    _oslistener_mouse_dragged(self, theEvent, ekGUI_MOUSE_LEFT, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)rightMouseDragged:(NSEvent *)theEvent
{
    _oslistener_mouse_dragged(self, theEvent, ekGUI_MOUSE_RIGHT, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)otherMouseDragged:(NSEvent *)theEvent
{
    _oslistener_mouse_dragged(self, theEvent, ekGUI_MOUSE_MIDDLE, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)scrollWheel:(NSEvent *)theEvent
{
    if (self->scroll != nil)
    {
        gui_scroll_t ev = osscroll_wheel_event(theEvent);
        if (ev != ENUM_MAX(gui_scroll_t))
            _osview_scroll_event(self, ekGUI_VERTICAL, ev);
    }

    _oslistener_scroll_whell(self, theEvent, self->scroll, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)keyDown:(NSEvent *)theEvent
{
    if (_oswindow_key_down(OSControlPtr(self), theEvent) == FALSE)
        _oslistener_key_down(self, theEvent, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)keyUp:(NSEvent *)theEvent
{
    _oslistener_key_up(self, theEvent, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (void)flagsChanged:(NSEvent *)theEvent
{
    _oslistener_key_flags_changed(self, theEvent, &self->listeners);
}

/*---------------------------------------------------------------------------*/

- (BOOL)isFlipped
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)NAppGUIOSX_setOpenGL
{
    self->flags |= ekVIEW_OPENGL;
}

/*---------------------------------------------------------------------------*/

- (void)NAppGUIOSX_unsetOpenGL
{
    self->flags &= (uint32_t)~ekVIEW_OPENGL;
}

@end

/*---------------------------------------------------------------------------*/

OSView *osview_create(const uint32_t flags)
{
    OSXView *view = [[OSXView alloc] initWithFrame:NSZeroRect];
    heap_auditor_add("OSXView");
    _oscontrol_init(view);
    view->flags = flags;
    view->ctx = NULL;
    view->tracking_area = NULL;
    view->OnFocus = NULL;
    view->OnResignFocus = NULL;
    view->OnAcceptFocus = NULL;
    view->OnOverlay = NULL;
    view->mouse_inside = NO;
    view->focused = NO;
    view->osdraw.view = view;
    _oslistener_init(&view->listeners);

    /* https://developer.apple.com/documentation/macos-release-notes/appkit-release-notes-for-macos-14#NSView */
#if defined(MAC_OS_VERSION_14_0) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_14
    [view setClipsToBounds:YES];
#endif

    if (flags & ekVIEW_HSCROLL || flags & ekVIEW_VSCROLL)
    {
        view->scroll = osscrolls_create(OSControlPtr(view), (bool_t)(flags & ekVIEW_HSCROLL) != 0, (bool_t)(flags & ekVIEW_VSCROLL) != 0);
    }
    else
    {
        view->scroll = nil;
    }

    if (flags & ekVIEW_BORDER)
        [view setFocusRingType:NSFocusRingTypeExterior];
    else
        [view setFocusRingType:NSFocusRingTypeNone];

    return (OSView *)view;
}

/*---------------------------------------------------------------------------*/

static OSXView *i_get_view(const OSView *view)
{
    cassert_no_null(view);
    if ([(NSView *)view isKindOfClass:[OSXView class]])
    {
        return (OSXView *)view;
    }

    return nil;
}

/*---------------------------------------------------------------------------*/

void osview_destroy(OSView **view)
{
    OSXView *lview = nil;
    cassert_no_null(view);
    lview = i_get_view(*view);
    cassert_no_null(lview);

    _oslistener_release(&lview->listeners);
    listener_destroy(&lview->OnFocus);
    listener_destroy(&lview->OnResignFocus);
    listener_destroy(&lview->OnAcceptFocus);
    listener_destroy(&lview->OnOverlay);

    if (lview->tracking_area != nil)
    {
        [lview removeTrackingArea:lview->tracking_area];
        [lview->tracking_area release];
    }

    if (lview->ctx != NULL)
        dctx_destroy(&lview->ctx);

    if (lview->scroll != NULL)
        osscrolls_destroy(&lview->scroll);

    [lview release];
    *view = NULL;
    heap_auditor_delete("OSXView");
}

/*---------------------------------------------------------------------------*/

void osview_OnDraw(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnDraw, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnOverlay(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->OnOverlay, listener);
}

/*---------------------------------------------------------------------------*/

static bool_t i_needs_tracking_area(OSXView *view)
{
    cassert_no_null(view);
    if (view->listeners.OnClick != NULL)
        return TRUE;
    if (view->listeners.OnMoved != NULL)
        return TRUE;
    if (view->listeners.OnEnter != NULL)
        return TRUE;
    if (view->listeners.OnExit != NULL)
        return TRUE;
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static void i_update_tracking_area(OSXView *view)
{
    NSSize track_size = [view frame].size;
    if (track_size.width > 0 && track_size.height > 0)
    {
        bool_t with_area = i_needs_tracking_area(view);
        NSUInteger options = NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved | NSTrackingActiveAlways | NSTrackingInVisibleRect;

        /* Tracking area shouldn't have effect in scrollbars */
        if (view->scroll != NULL)
        {
            track_size.width -= (CGFloat)osscrolls_bar_width(view->scroll, TRUE);
            track_size.height -= (CGFloat)osscrolls_bar_height(view->scroll, TRUE);
        }

        /* Updated the current area */
        if (view->tracking_area != nil && with_area == TRUE)
        {
            NSSize current_size = [view->tracking_area rect].size;

            if (NSEqualSizes(track_size, current_size) == NO)
            {
                [view removeTrackingArea:view->tracking_area];
                [view->tracking_area release];
                view->tracking_area = [[NSTrackingArea alloc] initWithRect:NSMakeRect(0, 0, track_size.width, track_size.height) options:(NSTrackingAreaOptions)options owner:view userInfo:nil];
                [view addTrackingArea:view->tracking_area];
                cassert([[view trackingAreas] count] == 1);
            }
        }
        /* Delete the area, not necessary */
        else if (view->tracking_area != nil)
        {
            cassert(with_area == FALSE);
            [view removeTrackingArea:view->tracking_area];
            [view->tracking_area release];
            view->tracking_area = nil;
        }
        /* Create one area */
        else if (with_area == TRUE)
        {
            cassert(view->tracking_area == nil);
            view->tracking_area = [[NSTrackingArea alloc] initWithRect:NSMakeRect(0, 0, track_size.width, track_size.height) options:(NSTrackingAreaOptions)options owner:view userInfo:nil];
            [view addTrackingArea:view->tracking_area];
            cassert([[view trackingAreas] count] == 1);
        }
    }
}

/*---------------------------------------------------------------------------*/

void osview_OnEnter(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnEnter, listener);
    i_update_tracking_area(lview);
}

/*---------------------------------------------------------------------------*/

void osview_OnExit(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnExit, listener);
    i_update_tracking_area(lview);
}

/*---------------------------------------------------------------------------*/

void osview_OnMoved(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnMoved, listener);
    i_update_tracking_area(lview);
}

/*---------------------------------------------------------------------------*/

void osview_OnDown(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnDown, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnUp(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnUp, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnClick(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnClick, listener);
    i_update_tracking_area(lview);
}

/*---------------------------------------------------------------------------*/

void osview_OnDrag(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnDrag, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnWheel(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnWheel, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnKeyDown(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnKeyDown, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnKeyUp(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->listeners.OnKeyUp, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnFocus(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnResignFocus(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->OnResignFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnAcceptFocus(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    listener_update(&lview->OnAcceptFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnScroll(OSView *view, Listener *listener)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    osscrolls_OnScroll(lview->scroll, listener);
}

/*---------------------------------------------------------------------------*/

void osview_scroll(OSView *view, const real32_t x, const real32_t y)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    osscrolls_set(lview->scroll, x >= 0 ? (uint32_t)x : UINT32_MAX, y >= 0 ? (uint32_t)y : UINT32_MAX, FALSE);
}

/*---------------------------------------------------------------------------*/

void osview_scroll_get(const OSView *view, real32_t *x, real32_t *y)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);

    if (x != NULL)
        *x = (real32_t)osscrolls_x_pos(lview->scroll);

    if (y != NULL)
        *y = (real32_t)osscrolls_y_pos(lview->scroll);
}

/*---------------------------------------------------------------------------*/

void osview_scroller_size(const OSView *view, real32_t *width, real32_t *height)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);

    if (width != NULL)
        *width = (real32_t)osscrolls_bar_width(lview->scroll, TRUE);

    if (height != NULL)
        *height = (real32_t)osscrolls_bar_height(lview->scroll, TRUE);
}

/*---------------------------------------------------------------------------*/

void osview_scroller_visible(OSView *view, const bool_t horizontal, const bool_t vertical)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    osscrolls_visible(lview->scroll, horizontal, vertical);
}

/*---------------------------------------------------------------------------*/

void osview_content_size(OSView *view, const real32_t width, const real32_t height, const real32_t line_width, const real32_t line_height)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    osscrolls_content_size(lview->scroll, (uint32_t)width, (uint32_t)height, (uint32_t)line_width, (uint32_t)line_height);
    i_update_tracking_area(lview);
}

/*---------------------------------------------------------------------------*/

real32_t osview_scale_factor(const OSView *view)
{
#if defined(MAC_OS_X_VERSION_10_7) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7
    OSXView *lview = i_get_view(view);
    NSWindow *window = nil;
    cassert_no_null(lview);
    window = [lview window];
    if (window != nil)
        return (real32_t)[window backingScaleFactor];

    return (real32_t)[[NSScreen mainScreen] backingScaleFactor];
#else
    unref(view);
    return 1;
#endif
}

/*---------------------------------------------------------------------------*/

void osview_set_need_display(OSView *view)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    [lview setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

void *osview_get_native_view(const OSView *view)
{
    return (void *)view;
}

/*---------------------------------------------------------------------------*/

void osview_attach(OSView *view, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)view);
}

/*---------------------------------------------------------------------------*/

void osview_detach(OSView *view, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)view);
}

/*---------------------------------------------------------------------------*/

void osview_visible(OSView *view, const bool_t is_visible)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    _oscontrol_set_visible(lview, is_visible);
}

/*---------------------------------------------------------------------------*/

void osview_enabled(OSView *view, const bool_t is_enabled)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    _oslistener_set_enabled(&lview->listeners, is_enabled);
}

/*---------------------------------------------------------------------------*/

void osview_size(const OSView *view, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)view, width, height);
}

/*---------------------------------------------------------------------------*/

void osview_origin(const OSView *view, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)view, x, y);
}

/*---------------------------------------------------------------------------*/

void osview_frame(OSView *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    OSXView *lview = i_get_view(view);
    cassert_no_null(lview);
    _oscontrol_set_frame((NSView *)lview, x, y, width, height);

    if (lview->scroll)
        osscrolls_control_size(lview->scroll, (uint32_t)width, (uint32_t)height);

    i_update_tracking_area(lview);
    [lview setNeedsDisplay:YES];
}

/*---------------------------------------------------------------------------*/

bool_t osview_resign_focus(const OSView *view)
{
    OSXView *lview = i_get_view(view);
    bool_t resign = TRUE;
    cassert_no_null(lview);
    if (lview->OnResignFocus != NULL)
        listener_event(lview->OnResignFocus, ekGUI_EVENT_FOCUS_RESIGN, view, NULL, &resign, OSView, void, bool_t);
    return resign;
}

/*---------------------------------------------------------------------------*/

bool_t osview_accept_focus(const OSView *view)
{
    OSXView *lview = i_get_view(view);
    bool_t accept = TRUE;
    cassert_no_null(view);
    if (lview->OnAcceptFocus != NULL)
        listener_event(lview->OnAcceptFocus, ekGUI_EVENT_FOCUS_ACCEPT, view, NULL, &accept, OSView, void, bool_t);
    return accept;
}

/*---------------------------------------------------------------------------*/

void osview_focus(OSView *view, const bool_t focus)
{
    OSXView *lview = i_get_view((OSView *)view);
    cassert_no_null(lview);
    if (lview->listeners.is_enabled == YES && lview->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(lview->OnFocus, ekGUI_EVENT_FOCUS, (OSView *)lview, &params, NULL, OSView, bool_t, void);
    }

    lview->focused = (BOOL)focus;

#if defined(MAC_OS_X_VERSION_10_11) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_11
#else
    if (lview->flags & ekVIEW_BORDER)
        [lview setKeyboardFocusRingNeedsDisplayInRect:[lview bounds]];
#endif
}

/*---------------------------------------------------------------------------*/

BOOL _osview_is(NSView *view)
{
    return (BOOL)(i_get_view((OSView *)view) != nil);
}

/*---------------------------------------------------------------------------*/

NSView *_osview_focus_widget(NSView *view)
{
    OSXView *lview = i_get_view((OSView *)view);
    cassert_no_null(lview);
    return (NSView *)lview;
}

/*---------------------------------------------------------------------------*/

void _osview_scroll_event(NSView *view, const gui_orient_t orient, const gui_scroll_t event)
{
    OSXView *lview = (OSXView *)view;
    cassert_no_null(lview);
    cassert_no_null(lview->scroll);
    cassert([view isKindOfClass:[OSXView class]]);
    if (osscrolls_event(lview->scroll, orient, event, FALSE) == TRUE)
        [lview setNeedsDisplay:YES];
}

/*
// DRAG SUPPORT

- (IBAction)onImageDrag:(id)sender
{
    cassert(sender == self);
    unreferenced_release(sender);

    if ([self isEnabled] == YES && self->OnImageDragged.object != NULL)
    {
        cassert(FALSE);
                Event event;
         event.sender = self;
         event.type = ekEVENT_TYPE_CONTROL_INCOMMING_DRAG;
         event.data.cdrag.obj = (const void*)[self image];
         listener_event(&self->OnImageDragged, &event);
    }
}


- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender
{
    if ([self isEnabled] == YES && self->accepts_drag == YES && self->OnAccepsDraggedImage.object != NULL)
    {
        NSPasteboard *paste;
        NSString *desired_type;
        NSData *carried_data;

        paste = [sender draggingPasteboard];

        {
            NSArray *types;

            types = [NSArray arrayWithObjects:NSTIFFPboardType, NSFilenamesPboardType, nil];
            desired_type = [paste availableTypeFromArray:types];
        }

        carried_data = [paste dataForType:desired_type];

        if (carried_data != nil)
        {
            NSImage *image;

            if ([desired_type isEqualToString:NSTIFFPboardType])
            {
                image = [[NSImage alloc] initWithData:carried_data];
            }
            else if ([desired_type isEqualToString:NSFilenamesPboardType])
            {
                NSArray *file_array;
                NSString *path;

                file_array = [paste propertyListForType:@"NSFilenamesPboardType"];
                path = [file_array objectAtIndex:0];
                image = [[NSImage alloc] initWithContentsOfFile:path];
            }
            else
            {
                image = nil;
            }

            if (image != nil)
            {
                //                Event event;
                BOOL accepts;

                cassert(FALSE);

                 event.sender = self;
                 event.type = ekEVENT_TYPE_CONTROL_ACCEPTS_DRAG;
                 event.data.cdrag.obj = (const void*)image;
                 listener_event(&self->OnAccepsDraggedImage, &event);

                 if (event.ret.rbool == TRUE)
                 {
                 [self setImage:image];
                 [self setNeedsDisplay:YES];
                 accepts = YES;
                 }
                 else
                 {
                 accepts = NO;
                 }

                [image release];
                return accepts;
            }
            else
            {
                return NO;
            }
        }
        else
        {
            return NO;
        }
    }
    else
    {
        return NO;
    }
}


OSImageView *osimageview_create(void)
{
    OSXImageView *view = NULL;
    _osgui_imageview_alloc(0);
    view = [[OSXImageView alloc] initWithFrame:NSZeroRect];
    [view setHidden:YES];
    view->accepts_drag = NO;
    listener_init_empty(&view->OnAccepsDraggedImage);
    listener_init_empty(&view->OnImageDragged);
    [view setImageFrameStyle:NSImageFrameNone];
    [view setImageAlignment:NSImageAlignCenter];
    [view setImageScaling:NSImageScaleProportionallyUpOrDown];
    [view setEditable:YES];
    [view setTarget:view];
    [view setAction:@selector(onImageDrag:)];
    [[view cell] setFocusRingType:NSFocusRingTypeNone];
    return (OSImageView*)view;
}

*/
