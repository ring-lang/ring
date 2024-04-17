/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenu.m
 *
 */

/* Cocoa NSMenu wrapper */

#include "osgui_osx.inl"
#include "osmenu.h"
#include "osgui.inl"
#include "oswindow_osx.inl"
#include <sewer/cassert.h>
#include <core/heap.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXMenu : NSMenu
{
  @public
    void *non_used;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXMenu

- (void)dealloc
{
    [super dealloc];
}

@end

/*---------------------------------------------------------------------------*/

OSMenu *osmenu_create(const enum_t flags)
{
    OSXMenu *menu = [[OSXMenu alloc] initWithTitle:[NSString string]];
    unref(flags);
    heap_auditor_add("OSXMenu");
    [menu setAutoenablesItems:NO];
    [menu setShowsStateColumn:YES];
    return (OSMenu *)menu;
}

/*---------------------------------------------------------------------------*/

void osmenu_destroy(OSMenu **menu)
{
    OSXMenu *menup = nil;
    cassert_no_null(menu);
    menup = (OSXMenu *)*menu;
    cassert_no_null(menup);
    cassert([menup supermenu] == nil);
    cassert([NSApp mainMenu] != menup);
    heap_auditor_delete("OSXMenu");
    [menup release];
    *menu = NULL;
}

/*---------------------------------------------------------------------------*/

void osmenu_add_item(OSMenu *menu, OSMenuItem *menuitem)
{
    /* In BigSur, the retainCount after addItem is not +1
     * NSUInteger retain_count = 0;
     * NSUInteger retain_count2 = 0;
     */
    NSUInteger num_items = 0;
    NSMenuItem *item = nil;
    cassert_no_null(menu);
    cassert_no_null(menuitem);
    cassert([(NSObject *)menu isKindOfClass:[OSXMenu class]] == YES);
    cassert([(NSObject *)menuitem isKindOfClass:[NSMenuItem class]] == YES);
    num_items = [[(OSXMenu *)menu itemArray] count];
    item = (NSMenuItem *)menuitem;
    cassert([item menu] == nil);
    /* retain_count = [item retainCount]; */
    [(OSXMenu *)menu addItem:item];
    /* retain_count2 = [item retainCount]; */
    /* cassert([item retainCount] == retain_count + 1); */
    cassert([item menu] == (OSXMenu *)menu);
    cassert_unref([[(OSXMenu *)menu itemArray] count] == num_items + 1, num_items);
}

/*---------------------------------------------------------------------------*/

void osmenu_delete_item(OSMenu *menu, OSMenuItem *menuitem)
{
    NSUInteger num_items = 0;
    NSMenuItem *item = nil;
    cassert_no_null(menu);
    cassert_no_null(menuitem);
    cassert([(NSObject *)menu isKindOfClass:[OSXMenu class]] == YES);
    num_items = [[(OSXMenu *)menu itemArray] count];
    cassert(num_items > 0);
    item = (NSMenuItem *)menuitem;
    cassert([item menu] == (OSXMenu *)menu);
    [(OSXMenu *)menu removeItem:item];
    cassert([item menu] == nil);
    cassert_unref([[(OSXMenu *)menu itemArray] count] == num_items - 1, num_items);
}

/*---------------------------------------------------------------------------*/

void osmenu_launch(OSMenu *menu, OSWindow *window, const real32_t x, const real32_t y)
{
    NSView *view = nil;
    CGFloat ly = 0.f;
    cassert_no_null(menu);
    cassert([(NSObject *)menu isKindOfClass:[OSXMenu class]] == YES);
    /* TODO: Use vuew (convert from screen to view coordinate) */
    view = _oswindow_main_view(window);
    unref(view);
    ly = [[NSScreen mainScreen] frame].size.height - (CGFloat)y;
    [(OSXMenu *)menu popUpMenuPositioningItem:nil atLocation:NSMakePoint((CGFloat)x, ly) inView:nil];
}

/*---------------------------------------------------------------------------*/

void osmenu_hide(OSMenu *menu)
{
    unref(menu);
    cassert(FALSE);
}
