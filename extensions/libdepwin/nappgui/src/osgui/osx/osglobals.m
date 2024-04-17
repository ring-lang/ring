/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osglobals.m
 *
 */

/* Operating System globals */

#include "osgui_osx.inl"
#include "osglobals.h"
#include "osglobals.inl"
#include "oscolor.inl"
#include "oscontrol_osx.inl"
#include <draw2d/color.h>
#include <draw2d/image.h>
#include <core/arrpt.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

@interface OSXHeader : NSView
{
  @public
    NSTableHeaderCell *cell;
    BOOL highlight;
}
@end

static NSImage *i_UNCHECKBOX_NORMAL_IMAGE = nil;
static NSImage *i_UNCHECKBOX_PRESSED_IMAGE = nil;
static NSImage *i_UNCHECKBOX_DISABLE_IMAGE = nil;
static NSImage *i_CHECKBOX_NORMAL_IMAGE = nil;
static NSImage *i_CHECKBOX_PRESSED_IMAGE = nil;
static NSImage *i_CHECKBOX_DISABLE_IMAGE = nil;
static NSImage *i_HEADER_NORMAL_IMAGE = nil;
static NSImage *i_HEADER_PRESSED_IMAGE = nil;
static NSRect i_CHECKBOX_RECT;
static NSRect i_HEADER_RECT;
static CGFloat i_TEXT_COLOR[4];
static CGFloat i_SELTX_COLOR[4];
static CGFloat i_HOTTX_COLOR[4];
static CGFloat i_TEXTBACKDROP_COLOR[4];
static CGFloat i_SELTXBACKDROP_COLOR[4];
static CGFloat i_HOTTXBACKDROP_COLOR[4];
static CGFloat i_BACK_COLOR[4];
static CGFloat i_SELBG_COLOR[4];
static CGFloat i_HOTBG_COLOR[4];
static CGFloat i_BACKBACKDROP_COLOR[4];
static CGFloat i_SELBGBACKDROP_COLOR[4];
static CGFloat i_HOTBGBACKDROP_COLOR[4];
static color_t i_GRID_COLOR;
static color_t i_FOCUS_COLOR;
static bool_t i_DARK_MODE = FALSE;
static ArrPt(Listener) *i_ONIDLES = NULL;
DeclPt(Listener);

/*---------------------------------------------------------------------------*/

@implementation OSXHeader

- (void)drawRect:(NSRect)rect
{
    if (self->highlight == YES)
        [self->cell highlight:YES withFrame:rect inView:self];
    else
        [self->cell drawWithFrame:rect inView:self];
}
@end

/*---------------------------------------------------------------------------*/

#define i_SET_COLOR(v, r, g, b, a) ((v)[0] = (CGFloat)(r), (v)[1] = (CGFloat)(g), (v)[2] = (CGFloat)(b), (v)[3] = (CGFloat)(a))

/*---------------------------------------------------------------------------*/

static void i_theme_colors(void)
{
    CGFloat r, g, b, a;

    oscolor_NSColor_rgba([NSColor windowBackgroundColor], &r, &g, &b, &a);
    i_DARK_MODE = (.21 * r + .72 * g + .07 * b) < .5 ? TRUE : FALSE;

    /* Text color (normal, selected, mouse over) */
    oscolor_NSColor_rgba_v([NSColor controlTextColor], i_TEXT_COLOR);
    oscolor_NSColor_rgba_v([NSColor selectedMenuItemTextColor], i_SELTX_COLOR);
    oscolor_NSColor_rgba_v([NSColor controlTextColor], i_HOTTX_COLOR);

    /* Text color in not active windows (normal, selected, mouse over) */
    oscolor_NSColor_rgba_v([NSColor controlTextColor], i_TEXTBACKDROP_COLOR);

#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    oscolor_NSColor_rgba_v([NSColor unemphasizedSelectedTextColor], i_SELTXBACKDROP_COLOR);
#else
    oscolor_NSColor_rgba_v([NSColor controlTextColor], i_SELTXBACKDROP_COLOR);
#endif

    oscolor_NSColor_rgba_v([NSColor controlTextColor], i_HOTTXBACKDROP_COLOR);

    /* Text background color (normal, selected, mouse over */
    oscolor_NSColor_rgba_v([NSColor controlBackgroundColor], i_BACK_COLOR);
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    oscolor_NSColor_rgba_v([NSColor selectedContentBackgroundColor], i_SELBG_COLOR);
#else
    oscolor_NSColor_rgba_v([NSColor selectedMenuItemColor], i_SELBG_COLOR);
#endif

    oscolor_NSColor_rgba_v([NSColor controlColor], i_HOTBG_COLOR);

    /* Text background color in not active windows (normal, selected, mouse over) */
    oscolor_NSColor_rgba_v([NSColor controlColor], i_BACKBACKDROP_COLOR);
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    oscolor_NSColor_rgba_v([NSColor unemphasizedSelectedTextBackgroundColor], i_SELBGBACKDROP_COLOR);
#else
    oscolor_NSColor_rgba_v([NSColor controlColor], i_SELBGBACKDROP_COLOR);
#endif
    oscolor_NSColor_rgba_v([NSColor controlColor], i_HOTBGBACKDROP_COLOR);

    /* Color for grids */
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    i_GRID_COLOR = oscolor_from_NSColor([NSColor separatorColor]);
#else
    i_GRID_COLOR = oscolor_from_NSColor([NSColor gridColor]);
#endif

    /* Focus ring color */
    i_FOCUS_COLOR = oscolor_from_NSColor([NSColor keyboardFocusIndicatorColor]);

    unref(a);
}

/*---------------------------------------------------------------------------*/

#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
#define REGULAR_SQUARE_BEZEL NSBezelStyleRegularSquare
#define SWITCH_BUTTON NSButtonTypeSwitch
#define RADIO_BUTTON NSButtonTypeRadio
#else
#define REGULAR_SQUARE_BEZEL NSRegularSquareBezelStyle
#define PUSH_IN_BUTTON NSMomentaryPushInButton
#define SWITCH_BUTTON NSSwitchButton
#define RADIO_BUTTON NSRadioButton
#endif

#if defined(MAC_OS_X_VERSION_10_13) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_13
#define BUTTON_ON NSControlStateValueOn
#define BUTTON_OFF NSControlStateValueOff
#else
#define BUTTON_ON NSOnState
#define BUTTON_OFF NSOffState
#endif

/*---------------------------------------------------------------------------*/

static NSImage *i_image_from_view(NSView *view, NSRect *pixrect)
{
    NSRect rect = [view frame];
    NSBitmapImageRep *irep = [view bitmapImageRepForCachingDisplayInRect:rect];
    NSImage *image = [[NSImage alloc] initWithSize:rect.size];
    [irep setSize:rect.size];
    [view cacheDisplayInRect:rect toBitmapImageRep:irep];
    [image addRepresentation:irep];
    [image setSize:rect.size];

    /* Locate the exact frame of pixels block */
    if (pixrect != NULL)
    {
        NSInteger w = [irep pixelsWide];
        NSInteger h = [irep pixelsHigh];
        NSInteger line = [irep bytesPerRow];
        NSInteger x0 = w, x1 = 0, yy0 = h, yy1 = 0;
        unsigned char *pixplanes[5] = {NULL, NULL, NULL, NULL, NULL};
        uint32_t *buffer = NULL;
        CGFloat scale = w / rect.size.width;
        NSInteger i = 0, j = 0;
        cassert([irep bitsPerPixel] == 32);
        [irep getBitmapDataPlanes:pixplanes];
        buffer = (uint32_t *)pixplanes[0];

        for (j = 0; j < h; ++j)
        {
            for (i = 0; i < w; ++i)
            {
                if (buffer[i] != 0)
                {
                    if (i < x0)
                        x0 = i;
                    if (i > x1)
                        x1 = i;
                    if (j < yy0)
                        yy0 = j;
                    if (j > yy1)
                        yy1 = j;
                }
            }

            buffer += line / 4;
        }

        pixrect->origin.x = (CGFloat)ceil((CGFloat)x0 / scale);
        pixrect->origin.y = (CGFloat)ceil((CGFloat)yy0 / scale);
        pixrect->size.width = (CGFloat)ceil((CGFloat)(x1 - x0 + 1) / scale);
        pixrect->size.height = (CGFloat)ceil((CGFloat)(yy1 - yy0 + 1) / scale);
    }

    return image;
}

/*---------------------------------------------------------------------------*/

static void i_init_checkbox(void)
{
    NSInteger width = 30, height = 30;
    NSButton *button = [[NSButton alloc] initWithFrame:NSMakeRect(0, 0, (CGFloat)width, (CGFloat)height)];
    cassert(i_UNCHECKBOX_NORMAL_IMAGE == nil);
    cassert(i_UNCHECKBOX_PRESSED_IMAGE == nil);
    cassert(i_UNCHECKBOX_DISABLE_IMAGE == nil);
    cassert(i_CHECKBOX_NORMAL_IMAGE == nil);
    cassert(i_CHECKBOX_PRESSED_IMAGE == nil);
    cassert(i_CHECKBOX_DISABLE_IMAGE == nil);

    [button setTitle:@""];
    [button setBezelStyle:REGULAR_SQUARE_BEZEL];
    [button setBordered:NO];
    [button setShowsBorderOnlyWhileMouseInside:NO];
    [[button cell] setImageScaling:NSImageScaleNone];
    [button setButtonType:SWITCH_BUTTON];
    [button setState:BUTTON_OFF];
    [button highlight:NO];
    [button setEnabled:YES];
    i_UNCHECKBOX_NORMAL_IMAGE = i_image_from_view(button, &i_CHECKBOX_RECT);

    [button highlight:YES];
    i_UNCHECKBOX_PRESSED_IMAGE = i_image_from_view(button, NULL);

    [button highlight:NO];
    [button setEnabled:NO];
    i_UNCHECKBOX_DISABLE_IMAGE = i_image_from_view(button, NULL);

    [button setState:BUTTON_ON];
    [button highlight:NO];
    [button setEnabled:YES];
    i_CHECKBOX_NORMAL_IMAGE = i_image_from_view(button, NULL);

    [button highlight:YES];
    i_CHECKBOX_PRESSED_IMAGE = i_image_from_view(button, NULL);

    [button highlight:NO];
    [button setEnabled:NO];
    i_CHECKBOX_DISABLE_IMAGE = i_image_from_view(button, NULL);

    [button release];
}

/*---------------------------------------------------------------------------*/

device_t osglobals_device(const void *non_used)
{
    cassert(non_used == NULL);
    unref(non_used);
    return ekDESKTOP;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_color(const syscolor_t *color)
{
    cassert_no_null(color);
    switch (*color)
    {
    case ekSYSCOLOR_DARKMODE:
        return (color_t)i_DARK_MODE;

    case ekSYSCOLOR_LABEL:
#if defined(MAC_OS_X_VERSION_10_10) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_10
        return oscolor_from_NSColor([NSColor labelColor]);
#else
        return oscolor_from_NSColor([NSColor controlTextColor]);
#endif

    case ekSYSCOLOR_VIEW:
        return oscolor_from_NSColor([NSColor controlBackgroundColor]);

    case ekSYSCOLOR_LINE:
        return i_GRID_COLOR;

    case ekSYSCOLOR_LINK:
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
        return oscolor_from_NSColor([NSColor linkColor]);
#else
        return oscolor_from_NSColor([NSColor colorWithCalibratedRed:0 green:(CGFloat).410 blue:(CGFloat).853 alpha:1]);
#endif

    case ekSYSCOLOR_BORDER:
        return i_GRID_COLOR;

        cassert_default();
    }

    return kCOLOR_BLACK;
}

/*---------------------------------------------------------------------------*/

void osglobals_resolution(const void *non_used, real32_t *width, real32_t *height)
{
    NSRect frame;
    cassert(non_used == NULL);
    unref(non_used);
    cassert_no_null(width);
    cassert_no_null(height);
    frame = [[NSScreen mainScreen] frame];
    *width = (real32_t)frame.size.width;
    *height = (real32_t)frame.size.height;
}

/*---------------------------------------------------------------------------*/

void osglobals_mouse_position(const void *non_used, real32_t *x, real32_t *y)
{
    NSRect mouse_frame;
    NSPoint origin;
    cassert(non_used == NULL);
    unref(non_used);
    cassert_no_null(x);
    cassert_no_null(y);
    mouse_frame.origin = [NSEvent mouseLocation];
    mouse_frame.size = NSZeroSize;
    _oscontrol_origin_in_screen_coordinates(&mouse_frame, &origin.x, &origin.y);
    *x = (real32_t)origin.x;
    *y = (real32_t)origin.y;
}

/*---------------------------------------------------------------------------*/

Cursor *osglobals_cursor(const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y)
{
    NSCursor *nscursor = nil;
    switch (cursor)
    {
    case ekGUI_CURSOR_ARROW:
        nscursor = [[NSCursor arrowCursor] retain];
        break;
    case ekGUI_CURSOR_HAND:
        nscursor = [[NSCursor openHandCursor] retain];
        break;
    case ekGUI_CURSOR_IBEAM:
        nscursor = [[NSCursor IBeamCursor] retain];
        break;
    case ekGUI_CURSOR_CROSS:
        nscursor = [[NSCursor crosshairCursor] retain];
        break;
    case ekGUI_CURSOR_SIZEWE:
        nscursor = [[NSCursor resizeLeftRightCursor] retain];
        break;
    case ekGUI_CURSOR_SIZENS:
        nscursor = [[NSCursor resizeUpDownCursor] retain];
        break;
    case ekGUI_CURSOR_USER:
    {
        NSImage *nsimage = (NSImage *)image_native(image);
        nscursor = [[NSCursor alloc] initWithImage:nsimage hotSpot:NSMakePoint((CGFloat)hot_x, (CGFloat)hot_y)];
        break;
    }

        cassert_default();
    }

    heap_auditor_add("NSCursor");
    return (Cursor *)nscursor;
}

/*---------------------------------------------------------------------------*/

void osglobals_cursor_destroy(Cursor **cursor)
{
    cassert_no_null(cursor);
    cassert_no_null(*cursor);
    [(NSCursor *)*cursor release];
    heap_auditor_delete("NSCursor");
    *cursor = NULL;
}

/*---------------------------------------------------------------------------*/

void osglobals_value(const uint32_t index, void *value)
{
    cassert_no_null(value);
    switch (index)
    {
    case 0:
        (*(uint32_t *)value) = 0;
        break;

    case 1:
        (*(uint32_t *)value) = 0;
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void osglobals_transitions(void *nonused, const real64_t prtime, const real64_t crtime)
{
    unref(nonused);
    unref(prtime);
    unref(crtime);
    if (i_ONIDLES != NULL)
    {
        if (arrpt_size(i_ONIDLES, Listener) > 0)
        {
            Listener *listener = arrpt_first(i_ONIDLES, Listener);
            listener_event(listener, ekGUI_EVENT_IDLE, NULL, NULL, NULL, void, void, void);
            arrpt_delete(i_ONIDLES, 0, listener_destroy, Listener);
        }
    }
}

/*---------------------------------------------------------------------------*/

void osglobals_OnIdle(void *nonused, Listener *listener)
{
    unref(nonused);
    if (i_ONIDLES == NULL)
        i_ONIDLES = arrpt_create(Listener);
    arrpt_append(i_ONIDLES, listener, Listener);
}

/*---------------------------------------------------------------------------*/

void osglobals_init(void)
{
    oscolor_init();
    i_theme_colors();
}

/*---------------------------------------------------------------------------*/

static void i_destroy_checkbox(void)
{
    if (i_UNCHECKBOX_NORMAL_IMAGE != nil)
    {
        [i_UNCHECKBOX_NORMAL_IMAGE release];
        [i_UNCHECKBOX_PRESSED_IMAGE release];
        [i_UNCHECKBOX_DISABLE_IMAGE release];
        [i_CHECKBOX_NORMAL_IMAGE release];
        [i_CHECKBOX_PRESSED_IMAGE release];
        [i_CHECKBOX_DISABLE_IMAGE release];
        i_UNCHECKBOX_NORMAL_IMAGE = nil;
        i_UNCHECKBOX_PRESSED_IMAGE = nil;
        i_UNCHECKBOX_DISABLE_IMAGE = nil;
        i_CHECKBOX_NORMAL_IMAGE = nil;
        i_CHECKBOX_PRESSED_IMAGE = nil;
        i_CHECKBOX_DISABLE_IMAGE = nil;
    }
}

/*---------------------------------------------------------------------------*/

static void i_destroy_header(void)
{
    if (i_HEADER_NORMAL_IMAGE != nil)
    {
        [i_HEADER_NORMAL_IMAGE release];
        [i_HEADER_PRESSED_IMAGE release];
        i_HEADER_NORMAL_IMAGE = nil;
        i_HEADER_PRESSED_IMAGE = nil;
    }
}

/*---------------------------------------------------------------------------*/

void osglobals_finish(void)
{
    oscolor_finish();
    i_destroy_checkbox();
    i_destroy_header();
    arrpt_destopt(&i_ONIDLES, listener_destroy, Listener);
}

/*---------------------------------------------------------------------------*/

uint32_t osglobals_check_width(void)
{
    if (i_UNCHECKBOX_NORMAL_IMAGE == nil)
        i_init_checkbox();
    return (uint32_t)i_CHECKBOX_RECT.size.width;
}

/*---------------------------------------------------------------------------*/

uint32_t osglobals_check_height(void)
{
    if (i_UNCHECKBOX_NORMAL_IMAGE == nil)
        i_init_checkbox();
    return (uint32_t)i_CHECKBOX_RECT.size.height;
}

/*---------------------------------------------------------------------------*/

NSSize osglobals_check_size(void)
{
    if (i_UNCHECKBOX_NORMAL_IMAGE == nil)
        i_init_checkbox();
    return i_CHECKBOX_RECT.size;
}

/*---------------------------------------------------------------------------*/

NSRect osglobals_check_rect(void)
{
    if (i_UNCHECKBOX_NORMAL_IMAGE == nil)
        i_init_checkbox();
    return i_CHECKBOX_RECT;
}

/*---------------------------------------------------------------------------*/

static void i_init_header(void)
{
    OSXHeader *view = [[OSXHeader alloc] initWithFrame:NSMakeRect(0, 0, 100, 50)];
    view->cell = [[NSTableHeaderCell alloc] init];
    cassert(i_HEADER_NORMAL_IMAGE == nil);
    cassert(i_HEADER_PRESSED_IMAGE == nil);
    [view->cell setTitle:@""];
    view->highlight = NO;
    i_HEADER_NORMAL_IMAGE = i_image_from_view(view, &i_HEADER_RECT);
    view->highlight = YES;
    i_HEADER_PRESSED_IMAGE = i_image_from_view(view, nil);
    [view->cell release];
    [view release];
}

/*---------------------------------------------------------------------------*/

NSRect osglobals_header_rect(void)
{
    if (i_HEADER_NORMAL_IMAGE == nil)
        i_init_header();
    return i_HEADER_RECT;
}

/*---------------------------------------------------------------------------*/

NSImage *osglobals_checkbox_image(const bool_t pressed, const ctrl_state_t state)
{
    if (i_UNCHECKBOX_NORMAL_IMAGE == nil)
        i_init_checkbox();

    if (pressed == TRUE)
    {
        switch (state)
        {
        case ekCTRL_STATE_NORMAL:
        case ekCTRL_STATE_BKNORMAL:
        case ekCTRL_STATE_HOT:
        case ekCTRL_STATE_BKHOT:
            return i_CHECKBOX_NORMAL_IMAGE;

        case ekCTRL_STATE_PRESSED:
        case ekCTRL_STATE_BKPRESSED:
            return i_CHECKBOX_PRESSED_IMAGE;

        case ekCTRL_STATE_DISABLED:
            return i_CHECKBOX_DISABLE_IMAGE;

            cassert_default();
        }
    }
    else
    {
        switch (state)
        {
        case ekCTRL_STATE_NORMAL:
        case ekCTRL_STATE_BKNORMAL:
        case ekCTRL_STATE_HOT:
        case ekCTRL_STATE_BKHOT:
            return i_UNCHECKBOX_NORMAL_IMAGE;

        case ekCTRL_STATE_PRESSED:
        case ekCTRL_STATE_BKPRESSED:
            return i_UNCHECKBOX_PRESSED_IMAGE;

        case ekCTRL_STATE_DISABLED:
            return i_UNCHECKBOX_DISABLE_IMAGE;

            cassert_default();
        }
    }

    return i_CHECKBOX_NORMAL_IMAGE;
}

/*---------------------------------------------------------------------------*/

NSImage *osglobals_header_image(const bool_t pressed)
{
    if (i_HEADER_NORMAL_IMAGE == nil)
        i_init_header();

    if (pressed == TRUE)
        return i_HEADER_PRESSED_IMAGE;
    else
        return i_HEADER_NORMAL_IMAGE;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_text_color(void)
{
    return i_TEXT_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_seltx_color(void)
{
    return i_SELTX_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_hottx_color(void)
{
    return i_HOTTX_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_textbackdrop_color(void)
{
    return i_TEXTBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_seltxbackdrop_color(void)
{
    return i_SELTXBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_hottxbackdrop_color(void)
{
    return i_HOTTXBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_back_color(void)
{
    return i_BACK_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_hotbg_color(void)
{
    return i_HOTBG_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_selbg_color(void)
{
    return i_SELBG_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_backbackdrop_color(void)
{
    return i_BACKBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_hotbgbackdrop_color(void)
{
    return i_HOTBGBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

const CGFloat *osglobals_selbgbackdrop_color(void)
{
    return i_SELBGBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_focus_color(void)
{
    return i_FOCUS_COLOR;
}

/*---------------------------------------------------------------------------*/

void osglobals_theme_changed(void)
{
    i_theme_colors();
    i_destroy_checkbox();
    i_destroy_header();
}
