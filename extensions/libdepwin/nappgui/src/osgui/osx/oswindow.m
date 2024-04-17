/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow.m
 *
 */

/* Cocoa NSwindow wrapper */

#include "oswindow.h"
#include "oswindow.inl"
#include "osbutton_osx.inl"
#include "oscontrol_osx.inl"
#include "osgui_osx.inl"
#include "ospanel_osx.inl"
#include "osview_osx.inl"
#include "oswindow_osx.inl"
#include "oscontrol.inl"
#include "ostabstop.inl"
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXText : NSTextView
{
  @public
    uint32_t empty;
}
@end

/*---------------------------------------------------------------------------*/

@interface OSXWindow : NSPanel
{
  @public
    NSPoint origin;
    BOOL in_window_destroy;
    BOOL destroy_main_view;
    BOOL last_moved_by_interface;
    BOOL launch_resize_event;
    uint32_t flags;
    gui_role_t role;
    CGFloat alpha;
    OSTabStop tabstop;
    ArrSt(OSHotKey) *hotkeys;
    OSXText *text_editor;
}
@end

/*---------------------------------------------------------------------------*/

#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
@interface OSXWindowDelegate : NSObject <NSWindowDelegate>
#else
@interface OSXWindowDelegate : NSObject
#endif
{
  @public
    Listener *OnMoved;
    Listener *OnResize;
    Listener *OnClose;
}

@end

/*---------------------------------------------------------------------------*/

@implementation OSXText

/*---------------------------------------------------------------------------*/

- (void)keyDown:(NSEvent *)theEvent
{
    if (_oswindow_key_down(OSControlPtr(self), theEvent) == FALSE)
        [super keyDown:theEvent];
}

/*---------------------------------------------------------------------------*/

@end

/*---------------------------------------------------------------------------*/

@implementation OSXWindowDelegate

- (void)dealloc
{
    [super dealloc];
    heap_auditor_delete("OSXWindowDelegate");
}

/*---------------------------------------------------------------------------*/

/*
- (void)windowDidBecomeKey:(NSNotification*)notification
{
    OSXWindow *window;
    window = [notification object];
    cassert_no_null(window);
    [window makeFirstResponder:nil];
}*/

/*---------------------------------------------------------------------------*/

- (void)windowDidMove:(NSNotification *)notification
{
    OSXWindow *window = [notification object];
    cassert_no_null(window);
    if (self->OnMoved != NULL && window->last_moved_by_interface == NO)
    {
        NSRect frame;
        EvPos params;
        CGFloat origin_x, origin_y;
        frame = [window frame];
        _oscontrol_origin_in_screen_coordinates(&frame, &origin_x, &origin_y);
        params.x = (real32_t)origin_x;
        params.y = (real32_t)origin_y;
        listener_event(self->OnMoved, ekGUI_EVENT_WND_MOVED, (OSWindow *)window, &params, NULL, OSWindow, EvPos, void);
    }

    window->last_moved_by_interface = NO;
}

/*---------------------------------------------------------------------------*/

- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize
{
    OSXWindow *window = (OSXWindow *)sender;
    if (self->OnResize != NULL && window->launch_resize_event == YES)
    {
        NSRect frame, content_frame;
        EvSize params;
        EvSize result;
        frame = NSMakeRect(0.f, 0.f, frameSize.width, frameSize.height);
        content_frame = [window contentRectForFrameRect:frame];
        params.width = (real32_t)content_frame.size.width;
        params.height = (real32_t)content_frame.size.height;

        /* Called whenever graphics state updated (such as window resize)
         * OpenGL rendering is not synchronous with other rendering on the OSX.
         * Therefore, call disableScreenUpdatesUntilFlush so the window server
         * doesn't render non-OpenGL content in the window asynchronously from
         * OpenGL content, which could cause flickering.  (non-OpenGL content
         * includes the title bar and drawing done by the app with other APIs)
        */
        [window disableScreenUpdatesUntilFlush];

        listener_event(self->OnResize, ekGUI_EVENT_WND_SIZING, (OSWindow *)window, &params, &result, OSWindow, EvSize, EvSize);
        listener_event(self->OnResize, ekGUI_EVENT_WND_SIZE, (OSWindow *)window, &result, NULL, OSWindow, EvSize, void);
        frame = [window frameRectForContentRect:NSMakeRect(0.f, 0.f, (CGFloat)result.width, (CGFloat)result.height)];
        return frame.size;
    }
    else
    {
        return frameSize;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_close(OSXWindowDelegate *delegate, OSXWindow *window, const gui_close_t close_origin)
{
    bool_t closed = TRUE;
    cassert_no_null(window);
    cassert_no_null(delegate);

    /* Checks if the current control allows the window to be closed */
    if (close_origin == ekGUI_CLOSE_INTRO)
        closed = ostabstop_can_close_window(&window->tabstop);

    /* Notify the user and check if allows the window to be closed */
    if (closed == TRUE && delegate->OnClose != NULL)
    {
        EvWinClose params;
        params.origin = close_origin;
        listener_event(delegate->OnClose, ekGUI_EVENT_WND_CLOSE, (OSWindow *)window, &params, &closed, OSWindow, EvWinClose, bool_t);
    }

    return closed;
}

/*---------------------------------------------------------------------------*/

- (BOOL)windowShouldClose:(id)sender
{
    return (BOOL)i_close(self, sender, ekGUI_CLOSE_BUTTON);
}

/*---------------------------------------------------------------------------*/

- (BOOL)isFlipped
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)windowDidResignKey:(NSNotification *)notification
{
    OSXWindow *window = nil;
    cassert_no_null(notification);
    window = [notification object];
    cassert_no_null(window);
    if (window->role == ekGUI_ROLE_OVERLAY)
    {
        if (i_close(self, window, ekGUI_CLOSE_DEACT) == TRUE)
            window->role = ENUM_MAX(gui_role_t);
    }
}

/*---------------------------------------------------------------------------*/

- (id)windowWillReturnFieldEditor:(NSWindow *)sender toObject:(id)client
{
    /* https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/TextEditing/Tasks/FieldEditor.html */
    OSXWindow *window = (OSXWindow *)sender;
    cassert([sender isKindOfClass:[OSXWindow class]]);
    if (window->text_editor == nil)
        window->text_editor = [[OSXText alloc] initWithFrame:NSMakeRect(0, 0, 10, 10)];

    [window->text_editor setDrawsBackground:YES];

    if ([client isKindOfClass:[NSTextField class]])
        [window->text_editor setFieldEditor:YES];
    else
        [window->text_editor setFieldEditor:NO];

    return window->text_editor;
}

@end

/*---------------------------------------------------------------------------*/

@implementation OSXWindow

- (void)dealloc
{
    [super dealloc];
    heap_auditor_delete("OSXWindow");
}

/*---------------------------------------------------------------------------*/

- (BOOL)canBecomeKeyWindow
{
    return YES;
}

/*---------------------------------------------------------------------------*/

- (BOOL)acceptsFirstMouse:(NSEvent *)theEvent
{
    unref(theEvent);
    return YES;
}

/*---------------------------------------------------------------------------*/

- (void)recalculateKeyViewLoop
{
    /* Prevents automatic key view loop re-compute.
       It seems that [NSWindow setAutorecalculatesKeyViewLoop:NO] doesn't work properly
       Tested in OSX El Capitan */
}

/*---------------------------------------------------------------------------*/

/* ESC key */
- (void)cancelOperation:(id)sender
{
    unref(sender);
    if (self->flags & ekWINDOW_ESC)
    {
        if (i_close([self delegate], self, ekGUI_CLOSE_ESC) == TRUE)
            [self orderOut:nil];
    }
}

/*---------------------------------------------------------------------------*/

- (BOOL)processKeyDown:(NSEvent *)theEvent
{
    /* '231' Comes from OSXEdit intro keyDown */
    unsigned short code = (theEvent == (NSEvent *)231) ? kVK_Return : [theEvent keyCode];

    if (code == kVK_Tab)
    {
        BOOL previous = NO;

#if defined(MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
        NSEventModifierFlags flags = [theEvent modifierFlags];
        previous = (flags & NSEventModifierFlagShift) != 0;
#else
        NSUInteger flgs = [theEvent modifierFlags];
        previous = (flgs & NSShiftKeyMask) != 0;
#endif

        if (previous == YES)
            ostabstop_prev(&self->tabstop, TRUE);
        else
            ostabstop_next(&self->tabstop, TRUE);

        return YES;
    }

    else if (code == kVK_Return || code == kVK_ANSI_KeypadEnter)
    {
        BOOL def = _osbutton_OnIntro((NSResponder *)self->tabstop.defbutton);

        if (self->flags & ekWINDOW_RETURN)
        {
            if (i_close([self delegate], self, ekGUI_CLOSE_INTRO) == TRUE)
                [self orderOut:nil];

            return YES;
        }

        if (def == YES)
            return YES;
    }

    else if (code == kVK_Escape)
    {
        if (self->flags & ekWINDOW_ESC)
        {
            i_close([self delegate], self, ekGUI_CLOSE_ESC);
            return YES;
        }
    }

    if (self->hotkeys != NULL)
    {
        if (theEvent != (NSEvent *)231)
        {
            vkey_t vkey = osgui_vkey([theEvent keyCode]);
            uint32_t modifiers = osgui_modifiers((NSUInteger)[theEvent modifierFlags]);
            if (oswindow_hotkey_process(OSWindowPtr(self), self->hotkeys, vkey, modifiers) == TRUE)
                return YES;
        }
    }

    return NO;
}

/*---------------------------------------------------------------------------*/

- (void)keyDown:(NSEvent *)theEvent
{
    if ([self processKeyDown:theEvent] == NO)
    {
        if (theEvent != (NSEvent *)231)
            [super keyDown:theEvent];
    }
}

@end

/*---------------------------------------------------------------------------*/

static NSUInteger i_window_style_mask(const uint32_t flags)
{
    NSUInteger style_mask = 0;
#if defined(MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
    if (flags & ekWINDOW_TITLE)
        style_mask |= NSWindowStyleMaskTitled;

    if (flags & ekWINDOW_MIN)
        style_mask |= NSWindowStyleMaskMiniaturizable;

    if (flags & ekWINDOW_CLOSE)
        style_mask |= NSWindowStyleMaskClosable;

    if (flags & ekWINDOW_RESIZE)
        style_mask |= NSWindowStyleMaskResizable;
#else
    if (flags & ekWINDOW_TITLE)
        style_mask |= NSTitledWindowMask;

    if (flags & ekWINDOW_MIN)
        style_mask |= NSMiniaturizableWindowMask;

    if (flags & ekWINDOW_CLOSE)
        style_mask |= NSClosableWindowMask;

    if (flags & ekWINDOW_RESIZE)
        style_mask |= NSResizableWindowMask;
#endif
    return style_mask;
}

/*---------------------------------------------------------------------------*/

OSWindow *oswindow_create(const uint32_t flags)
{
    NSUInteger stylemask = 0;
    OSXWindow *window = NULL;
    OSXWindowDelegate *delegate = NULL;
    stylemask = i_window_style_mask(flags);
    heap_auditor_add("OSXWindow");
    window = [[OSXWindow alloc] initWithContentRect:NSZeroRect styleMask:stylemask backing:NSBackingStoreBuffered defer:NO];
    [window setAutorecalculatesKeyViewLoop:NO];
    window->origin.x = 0.f;
    window->origin.y = 0.f;
    window->in_window_destroy = NO;
    window->destroy_main_view = YES;
    window->last_moved_by_interface = NO;
    window->launch_resize_event = YES;
    window->flags = flags;
    window->role = ENUM_MAX(gui_role_t);
    window->alpha = .5f;
    window->hotkeys = NULL;
    window->text_editor = nil;
    ostabstop_init(&window->tabstop, (OSWindow *)window);
    heap_auditor_add("OSXWindowDelegate");
    delegate = [OSXWindowDelegate alloc];
    delegate->OnMoved = NULL;
    delegate->OnResize = NULL;
    delegate->OnClose = NULL;
    [window setDelegate:delegate];
    [window setAcceptsMouseMovedEvents:YES];
    [window setIsVisible:NO];
#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
    [window setMovable:YES];
#endif
    [window setWorksWhenModal:YES];
    [window setLevel:0];
    /* [window setFloatingPanel:NO]; */
    [window setHidesOnDeactivate:NO];
    [window setReleasedWhenClosed:NO];
    /* [window setBecomesKeyOnlyIfNeeded:YES]; */
    cassert([window contentView] != nil);
    return (OSWindow *)window;
}

/*---------------------------------------------------------------------------*/

OSWindow *oswindow_managed(void *native_ptr)
{
    unref(native_ptr);
    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

void oswindow_destroy(OSWindow **window)
{
    OSXWindow *windowp = NULL;
    OSXWindowDelegate *delegate = NULL;
    cassert_no_null(window);
    cassert([(NSResponder *)*window isKindOfClass:[OSXWindow class]] == YES);
    windowp = (OSXWindow *)*window;
    cassert_no_null(windowp);
    delegate = [windowp delegate];
    cassert_no_null(delegate);

    if (windowp->text_editor != nil)
        [windowp->text_editor release];

    if (windowp->destroy_main_view == YES)
    {
        OSPanel *panel = (OSPanel *)[windowp contentView];
        if (panel != NULL)
        {
            oswindow_detach_panel(*window, panel);
            _ospanel_destroy(&panel);
        }
    }

    cassert([windowp contentView] == nil);
    ostabstop_remove(&windowp->tabstop);
    oswindow_hotkey_destroy(&windowp->hotkeys);
    listener_destroy(&delegate->OnMoved);
    listener_destroy(&delegate->OnResize);
    listener_destroy(&delegate->OnClose);
    [windowp setDelegate:nil];
    [delegate release];
    [windowp close];
    [windowp release];
    *window = NULL;
}

/*---------------------------------------------------------------------------*/

void oswindow_OnMoved(OSWindow *window, Listener *listener)
{
    OSXWindowDelegate *delegate;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    delegate = [(OSXWindow *)window delegate];
    cassert_no_null(delegate);
    listener_update(&delegate->OnMoved, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnResize(OSWindow *window, Listener *listener)
{
    OSXWindowDelegate *delegate;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    delegate = [(OSXWindow *)window delegate];
    cassert_no_null(delegate);
    listener_update(&delegate->OnResize, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnClose(OSWindow *window, Listener *listener)
{
    OSXWindowDelegate *delegate;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    delegate = [(OSXWindow *)window delegate];
    cassert_no_null(delegate);
    listener_update(&delegate->OnClose, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_title(OSWindow *window, const char_t *text)
{
    NSString *str;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
#if defined(MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
    cassert(([(OSXWindow *)window styleMask] & NSWindowStyleMaskTitled) == NSWindowStyleMaskTitled);
#else
    cassert(([(OSXWindow *)window styleMask] & NSTitledWindowMask) == NSTitledWindowMask);
#endif
    cassert_no_null(text);
    str = [[NSString alloc] initWithUTF8String:(const char *)text];
    [(OSXWindow *)window setTitle:str];
    [str release];
}

/*---------------------------------------------------------------------------*/

void oswindow_edited(OSWindow *window, const bool_t is_edited)
{
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    [(OSXWindow *)window setDocumentEdited:(BOOL)is_edited];
}

/*---------------------------------------------------------------------------*/

void oswindow_movable(OSWindow *window, const bool_t is_movable)
{
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
    [(OSXWindow *)window setMovable:(BOOL)is_movable];
#endif
    [(OSXWindow *)window setMovableByWindowBackground:(BOOL)is_movable];
}

/*---------------------------------------------------------------------------*/

void oswindow_z_order(OSWindow *window, OSWindow *below_window)
{
    NSInteger below_level = 0;
    cassert_no_null(window);
    cassert_no_null(below_window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    below_level = [(OSXWindow *)below_window level];
    [(OSXWindow *)window setLevel:below_level + 10];
}

/*---------------------------------------------------------------------------*/

void oswindow_alpha(OSWindow *window, const real32_t alpha)
{
    cassert_no_null(window);
    cassert(alpha >= 0.f && alpha <= 1.f);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    cassert(FALSE);
    ((OSXWindow *)window)->alpha = (CGFloat)alpha;
}

/*---------------------------------------------------------------------------*/

void oswindow_enable_mouse_events(OSWindow *window, const bool_t enabled)
{
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    [(OSXWindow *)window setIgnoresMouseEvents:!(BOOL)enabled];
}

/*---------------------------------------------------------------------------*/

void oswindow_hotkey(OSWindow *window, const vkey_t key, const uint32_t modifiers, Listener *listener)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    oswindow_hotkey_set(&windowp->hotkeys, key, modifiers, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_taborder(OSWindow *window, OSControl *control)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    ostabstop_list_add(&windowp->tabstop, control);
    if (control == NULL)
    {
        /* The window main panel has changed. We ensure that default button is still valid */
        windowp->tabstop.defbutton = oswindow_apply_default_button(window, windowp->tabstop.defbutton);
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_tabcycle(OSWindow *window, const bool_t cycle)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    windowp->tabstop.cycle = cycle;
}

/*---------------------------------------------------------------------------*/

gui_focus_t oswindow_tabstop(OSWindow *window, const bool_t next)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    if (next == TRUE)
        return ostabstop_next(&windowp->tabstop, FALSE);
    else
        return ostabstop_prev(&windowp->tabstop, FALSE);
}

/*---------------------------------------------------------------------------*/

gui_focus_t oswindow_focus(OSWindow *window, OSControl *control)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    return ostabstop_move(&windowp->tabstop, control);
}

/*---------------------------------------------------------------------------*/

OSControl *oswindow_get_focus(const OSWindow *window)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    return windowp->tabstop.current;
}

/*---------------------------------------------------------------------------*/

gui_tab_t oswindow_info_focus(const OSWindow *window, void **next_ctrl)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(windowp);
    return ostabstop_info_focus(&windowp->tabstop, next_ctrl);
}

/*---------------------------------------------------------------------------*/

void oswindow_attach_panel(OSWindow *window, OSPanel *panel)
{
    cassert_no_null(window);
    cassert_no_null(panel);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    [(OSXWindow *)window setContentView:(NSView *)panel];
}

/*---------------------------------------------------------------------------*/

void oswindow_detach_panel(OSWindow *window, OSPanel *panel)
{
    NSUInteger count = 0;
    cassert_no_null(window);
    cassert_no_null(panel);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    cassert([(OSXWindow *)window contentView] == (NSView *)panel);
    count = [(NSView *)panel retainCount];
    cassert_unref(count > 0, count);
    ((OSXWindow *)window)->in_window_destroy = YES;
    [(OSXWindow *)window setContentView:nil /*[[NSView alloc] init]*/];
    /*   if (count == [(NSView*)main_view retainCount])
        [(NSView*)main_view release];
    cassert([(NSView*)main_view retainCount] == count - 1);*/
}

/*---------------------------------------------------------------------------*/

void oswindow_attach_window(OSWindow *parent_window, OSWindow *child_window)
{
    cassert_no_null(parent_window);
    cassert_no_null(child_window);
    [(OSXWindow *)parent_window addChildWindow:(OSXWindow *)child_window ordered:NSWindowAbove];
}

/*---------------------------------------------------------------------------*/

void oswindow_detach_window(OSWindow *parent_window, OSWindow *child_window)
{
    cassert_no_null(parent_window);
    cassert_no_null(child_window);
    [(OSXWindow *)parent_window removeChildWindow:(OSXWindow *)child_window];
}

/*---------------------------------------------------------------------------*/

void oswindow_launch(OSWindow *window, OSWindow *parent_window)
{
    OSXWindow *windowp = (OSXWindow *)window;
    OSXWindow *pwindowp = (OSXWindow *)parent_window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    if (pwindowp != nil)
    {
        cassert([(NSObject *)parent_window isKindOfClass:[OSXWindow class]] == YES);
        windowp->role = ekGUI_ROLE_OVERLAY;
    }
    else
    {
        pwindowp = nil; /*(OSXWindow*)window;*/
        windowp->role = ekGUI_ROLE_MAIN;
    }

    ostabstop_restore(&windowp->tabstop);

    /* https://developer.apple.com/forums/thread/729496
     * I started seeing same warnings but they weren't there before.
     * Not sure if some behaviour on macOS changed or is just noise, but to on the safe side
     * I changed my implementation to open the first window on my app.
     * The key is to use orderFrontRegardless() instead of makeKeyAndOrderFront(nil)
     */
    if (pwindowp != nil)
        [windowp makeKeyAndOrderFront:pwindowp];
    else
        [windowp orderFrontRegardless];
}

/*---------------------------------------------------------------------------*/

void oswindow_hide(OSWindow *window, OSWindow *parent_window)
{
    OSXWindow *parent = NULL;
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    if (parent_window != nil)
    {
        cassert([(NSObject *)parent_window isKindOfClass:[OSXWindow class]] == YES);
        parent = (OSXWindow *)parent_window;
    }
    else
    {
        parent = windowp;
    }

    windowp->role = ENUM_MAX(gui_role_t);
    [windowp orderOut:parent];
}

/*---------------------------------------------------------------------------*/
/* https://forums.developer.apple.com/thread/88825 */
/*
 As of macOS 10.13, we are starting to see some crashes in our app related to
 launching a dialog during a windowDidBecomeMain, whether via [NSApp runModalForWindow:]
 or [NSAlert runModal].  This has worked up until 10.13 (in 10.12 we didn't crash but
 often there would be drawing anomolies like the window title bar not drawing, etc., and
 in 10.11/10.10 everything appeared to draw fine), but as we have been looking into it,
 we have noticed some messages in the console like this as well:
 -[NSAlert runModal] may not be invoked inside of transaction begin/commit pair, or inside
 of transaction commit (usually this means it was invoked inside of a view's -drawRect: method.)
 */
uint32_t oswindow_launch_modal(OSWindow *window, OSWindow *parent_window)
{
    OSXWindow *windowp = (OSXWindow *)window;
    OSXWindow *pwindowp = (OSXWindow *)parent_window;
    OSXWindow *wfront = nil;
    NSInteger ret;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);

    if (pwindowp != nil)
    {
        cassert([(NSResponder *)parent_window isKindOfClass:[OSXWindow class]] == YES);
        [pwindowp setWorksWhenModal:NO];
        wfront = pwindowp;
    }

    windowp->role = ekGUI_ROLE_MODAL;

    /* https://developer.apple.com/forums/thread/729496
     * I started seeing same warnings but they weren't there before.
     * Not sure if some behaviour on macOS changed or is just noise, but to on the safe side
     * I changed my implementation to open the first window on my app.
     * The key is to use orderFrontRegardless() instead of makeKeyAndOrderFront(nil)
     */
    if (wfront != nil)
        [windowp makeKeyAndOrderFront:nil];
    else
        [windowp orderFrontRegardless];

    ostabstop_restore(&windowp->tabstop);
    ret = [NSApp runModalForWindow:windowp];

    if (pwindowp != nil)
    {
        ostabstop_restore(&pwindowp->tabstop);
        [pwindowp setWorksWhenModal:YES];
    }

    return (uint32_t)ret;
}

/*---------------------------------------------------------------------------*/

void oswindow_stop_modal(OSWindow *window, const uint32_t return_value)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    cassert([NSApp modalWindow] == (OSXWindow *)window);
    windowp->role = ENUM_MAX(gui_role_t);
    [windowp close];
    [NSApp stopModalWithCode:(NSInteger)return_value];
}

/*---------------------------------------------------------------------------*/

/*
//void oswindow_launch_sheet(OSWindow *window, OSWindow *parent)
//{
//    cassert_no_null(window);
//#if defined (MAC_OS_X_VERSION_10_10) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_10
//    cassert(FALSE);
//    [(OSXWindow*)parent beginSheet:(OSXWindow*)window completionHandler:nil];
//#else
//    [NSApp beginSheet:(OSXWindow*)window modalForWindow:(OSXWindow*)parent modalDelegate:nil didEndSelector:nil contextInfo:nil];
//#endif
//}
*/

/*---------------------------------------------------------------------------*/

/*
//void oswindow_stop_sheet(OSWindow *window, OSWindow *parent)
//{
//    cassert_no_null(window);
//    [(OSXWindow*)window orderOut:(OSXWindow*)window];
//    [NSApp endSheet:(OSXWindow*)window];
//    [(OSXWindow*)parent makeKeyAndOrderFront:nil];
//}
*/

/*---------------------------------------------------------------------------*/

void oswindow_get_origin(const OSWindow *window, real32_t *x, real32_t *y)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(windowp);
    cassert_no_null(x);
    cassert_no_null(y);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    if (*x == REAL32_MAX && *y == REAL32_MAX)
    {
        NSRect frame = [windowp frame];
        CGFloat origin_x, origin_y;
        _oscontrol_origin_in_screen_coordinates(&frame, &origin_x, &origin_y);
        *x = (real32_t)origin_x;
        *y = (real32_t)origin_y;
    }
    else
    {
        NSSize size = [[windowp contentView] frame].size;
#if defined(MAC_OS_X_VERSION_10_6) && MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_6
        NSPoint pt = [windowp convertRectToScreen:NSMakeRect((CGFloat)*x, size.height - (CGFloat)*y, 100, 100)].origin;
#else
        NSPoint pt = [windowp convertBaseToScreen:NSMakePoint((CGFloat)*x, size.height - (CGFloat)*y)];
#endif

        NSSize ssize = [[NSScreen mainScreen] frame].size;
        *x = (real32_t)pt.x;
        *y = (real32_t)pt.y;
        *y = (real32_t)(ssize.height - pt.y);
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_origin(OSWindow *window, const real32_t x, const real32_t y)
{
    OSXWindow *windowp = (OSXWindow *)window;
    NSRect window_frame;
    NSPoint origin;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    window_frame = [windowp frame];
    window_frame.origin.x = (CGFloat)x;
    window_frame.origin.y = (CGFloat)y;
    _oscontrol_origin_in_screen_coordinates(&window_frame, &origin.x, &origin.y);
    windowp->last_moved_by_interface = YES;
    [(OSXWindow *)windowp setFrameOrigin:origin];
}

/*---------------------------------------------------------------------------*/

void oswindow_get_size(const OSWindow *window, real32_t *width, real32_t *height)
{
    NSSize frame_size;
    cassert_no_null(window);
    cassert_no_null(width);
    cassert_no_null(height);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    frame_size = [(OSXWindow *)window frame].size;
    *width = (real32_t)frame_size.width;
    *height = (real32_t)frame_size.height;
}

/*---------------------------------------------------------------------------*/

void oswindow_size(OSWindow *window, const real32_t content_width, const real32_t content_height)
{
    NSSize size;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    size.width = (CGFloat)content_width;
    size.height = (CGFloat)content_height;
    ((OSXWindow *)window)->launch_resize_event = NO;
    [(OSXWindow *)window setContentSize:size];
    ((OSXWindow *)window)->launch_resize_event = YES;
}

/*---------------------------------------------------------------------------*/

void oswindow_set_default_pushbutton(OSWindow *window, OSButton *button)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    windowp->tabstop.defbutton = oswindow_apply_default_button(window, button);
}

/*---------------------------------------------------------------------------*/

void oswindow_set_cursor(OSWindow *window, Cursor *cursor)
{
    unref(window);
    if (cursor != nil)
        [(NSCursor *)cursor set];
    else
        [[NSCursor arrowCursor] set];
}

/*---------------------------------------------------------------------------*/

void oswindow_property(OSWindow *window, const gui_prop_t property, const void *value)
{
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    unref(value);
    switch (property)
    {
    case ekGUI_PROP_RESIZE:
        break;
    case ekGUI_PROP_CHILDREN:
        ((OSXWindow *)window)->destroy_main_view = NO;
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_widget_set_focus(OSWindow *window, OSWidget *widget)
{
    OSXWindow *windowp = (OSXWindow *)window;
    NSView *view = (NSView *)widget;
    BOOL ok = NO;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    cassert([(NSResponder *)widget isKindOfClass:[NSView class]] == YES);
    ok = [windowp makeFirstResponder:view];
    cassert_unref(ok == YES, ok);
}

/*---------------------------------------------------------------------------*/

static void i_get_controls(NSView *view, ArrPt(OSControl) *controls)
{
    OSControl *control = _oscontrol_from_nsview(view);
    if (control != NULL)
    {
        if (arrpt_find(controls, control, OSControl) == UINT32_MAX)
            arrpt_append(controls, control, OSControl);
    }

    {
        NSArray *children = [view subviews];
        NSUInteger i, count = [children count];
        for (i = 0; i < count; ++i)
        {
            NSView *child = (NSView *)[children objectAtIndex:i];
            i_get_controls(child, controls);
        }
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_find_all_controls(OSWindow *window, ArrPt(OSControl) *controls)
{
    OSXWindow *windowp = (OSXWindow *)window;
    NSView *main_view = nil;
    cassert_no_null(windowp);
    cassert(arrpt_size(controls, OSControl) == 0);
    main_view = [windowp contentView];
    i_get_controls(main_view, controls);
}

/*---------------------------------------------------------------------------*/

const ArrPt(OSControl) *oswindow_get_all_controls(const OSWindow *window)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(windowp);
    return windowp->tabstop.controls;
}

/*---------------------------------------------------------------------------*/

void oswindow_set_app(void *app, void *icon)
{
    cassert(FALSE);
    unref(app);
    unref(icon);
}

/*---------------------------------------------------------------------------*/

void oswindow_set_app_terminate(void)
{
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

BOOL _oswindow_in_destroy(NSWindow *window)
{
    cassert_no_null(window);
    cassert([window isKindOfClass:[OSXWindow class]] == YES);
    return ((OSXWindow *)window)->in_window_destroy;
}

/*---------------------------------------------------------------------------*/

NSView *_oswindow_main_view(OSWindow *window)
{
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    return [(OSXWindow *)window contentView];
}

/*---------------------------------------------------------------------------*/

void _oswindow_next_tabstop(NSWindow *window, const bool_t keypress)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    ostabstop_next(&windowp->tabstop, keypress);
}

/*---------------------------------------------------------------------------*/

void _oswindow_prev_tabstop(NSWindow *window, const bool_t keypress)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    ostabstop_prev(&windowp->tabstop, keypress);
}

/*---------------------------------------------------------------------------*/

void _oswindow_restore_focus(NSWindow *window)
{
    OSXWindow *windowp = (OSXWindow *)window;
    cassert_no_null(window);
    cassert([(NSResponder *)window isKindOfClass:[OSXWindow class]] == YES);
    ostabstop_restore(&windowp->tabstop);
}

/*---------------------------------------------------------------------------*/

bool_t _oswindow_key_down(OSControl *control, NSEvent *theEvent)
{
    OSXWindow *window = NULL;
    cassert_no_null(control);
    cassert([(NSResponder *)control isKindOfClass:[NSView class]] == YES);
    window = (OSXWindow *)[(NSView *)control window];
    cassert_no_null(window);
    return (bool_t)[window processKeyDown:theEvent];
}

/*---------------------------------------------------------------------------*/

bool_t _oswindow_mouse_down(OSControl *control)
{
    OSXWindow *window = NULL;
    cassert_no_null(control);
    cassert([(NSResponder *)control isKindOfClass:[NSView class]] == YES);
    window = (OSXWindow *)[(NSView *)control window];
    cassert_no_null(window);
    return ostabstop_mouse_down(&window->tabstop, control);
}

/*---------------------------------------------------------------------------*/

void _oswindow_release_transient_focus(OSControl *control)
{
    OSXWindow *window = NULL;
    cassert_no_null(control);
    cassert([(NSResponder *)control isKindOfClass:[NSView class]] == YES);
    window = (OSXWindow *)[(NSView *)control window];
    cassert_no_null(window);
    ostabstop_release_transient(&window->tabstop, control);
}
