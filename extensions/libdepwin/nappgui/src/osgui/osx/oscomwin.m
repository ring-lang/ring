/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscomwin.m
 *
 */

/* Operating System native common windows */

#include "oscomwin.h"
#include "oscomwin.inl"
#include "oscontrol_osx.inl"
#include <core/event.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

#if defined(MAC_OS_VERSION_12_0) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_VERSION_12_0

#include <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

static void i_set_ftypes(NSSavePanel *panel, const char_t **ftypes, const uint32_t size)
{
    NSMutableArray<UTType *> *array = [NSMutableArray array];

    if (ftypes != NULL && size > 0)
    {
        register uint32_t i;
        for (i = 0; i < size; ++i)
        {
            NSString *ext = [NSString stringWithUTF8String:ftypes[i]];
            UTType *type = [UTType typeWithFilenameExtension:ext];
            if (type != nil)
                [array addObject:type];
        }
    }

    [panel setAllowedContentTypes:array];
}

#else

static void i_set_ftypes(NSSavePanel *panel, const char_t **ftypes, const uint32_t size)
{
    if (ftypes != NULL && size > 0)
    {
        register uint32_t i;
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:(NSUInteger)size];
        for (i = 0; i < size; ++i)
        {
            NSString *str = [NSString stringWithUTF8String:(const char *)ftypes[i]];
            [array addObject:str];
        }

        [panel setAllowedFileTypes:array];
    }
    else
    {
        [panel setAllowedFileTypes:nil];
    }
}

#endif

/*---------------------------------------------------------------------------*/

static NSOpenPanel *i_open_file(const char_t **ftypes, const uint32_t size, const char_t *startdir)
{
    NSOpenPanel *open_panel = [NSOpenPanel openPanel];
    BOOL dirsel = NO;

#if defined(MAC_OS_X_VERSION_10_6) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6
    if (startdir != NULL)
    {
        NSString *str = [[NSString alloc] initWithUTF8String:startdir];
        NSURL *url = [[NSURL alloc] initWithString:str];
        [open_panel setDirectoryURL:url];
        [url release];
        [str release];
    }
    else
    {
        [open_panel setDirectoryURL:nil];
    }

#else
    unref(startdir);
#endif

    [open_panel setAllowsMultipleSelection:FALSE];
    if (ftypes != NULL)
    {
        cassert(size > 0);
        if (size == 1 && strcmp((const char *)ftypes[0], "..DIR..") == 0)
            dirsel = YES;
    }

    i_set_ftypes(open_panel, ftypes, size);
    [open_panel setCanChooseFiles:!dirsel];
    [open_panel setCanChooseDirectories:dirsel];
    return open_panel;
}

/*---------------------------------------------------------------------------*/

static NSSavePanel *i_save_file(const char_t **ftypes, const uint32_t size)
{
    NSSavePanel *save_panel = [NSSavePanel savePanel];

    /* 10.5
       [save_panel setDirectoryURL:nil];
       cassert(FALSE);
     */

    [save_panel setCanCreateDirectories:YES];
    i_set_ftypes(save_panel, ftypes, size);
    return save_panel;
}

/*---------------------------------------------------------------------------*/

static const char_t *i_open_file_selected(NSOpenPanel *open_panel)
{
    NSArray *urls;
    NSURL *url;
    cassert_no_null(open_panel);
    urls = [open_panel URLs];
    cassert([urls count] == 1);
    url = [urls objectAtIndex:0];
    cassert_no_null(url);
    return (const char_t *)[[url path] UTF8String];
}

/*---------------------------------------------------------------------------*/

static const char_t *i_save_file_selected(NSSavePanel *save_panel)
{
    NSURL *url;
    cassert_no_null(save_panel);
    url = [save_panel URL];
    cassert_no_null(url);
    return (const char_t *)[[url path] UTF8String];
}

/*---------------------------------------------------------------------------*/

const char_t *oscomwin_file(OSWindow *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir, const bool_t foropen)
{
    unref(parent);
    if (foropen == TRUE)
    {
        NSOpenPanel *open_panel = i_open_file(ftypes, size, start_dir);

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
        {
            NSModalResponse ret = [open_panel runModal];
            if (ret == NSModalResponseOK)
                return i_open_file_selected(open_panel);
            else
                return NULL;
        }
#else
        {
            NSUInteger ret = (NSUInteger)[open_panel runModal];
            if (ret == NSFileHandlingPanelOKButton)
                return i_open_file_selected(open_panel);
            else
                return NULL;
        }
#endif
    }
    else
    {
        NSSavePanel *save_panel = i_save_file(ftypes, size);

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
        {
            NSModalResponse ret = [save_panel runModal];
            if (ret == NSModalResponseOK)
                return i_save_file_selected(save_panel);
            else
                return NULL;
        }
#else
        {
            NSUInteger ret = (NSUInteger)[save_panel runModal];
            if (ret == NSFileHandlingPanelOKButton)
                return i_save_file_selected(save_panel);
            else
                return NULL;
        }
#endif
    }
}

/*---------------------------------------------------------------------------*/

@interface NSColorChoose : NSObject
{
  @public
    Listener *OnChange;
}
@end

@implementation NSColorChoose

- (IBAction)onColorChange:(id)sender
{
    NSColor *color = [sender color];
    color_t c = _oscontrol_from_NSColor(color);
    listener_event(self->OnChange, ekGUI_EVENT_COLOR, NULL, &c, NULL, void, color_t, void);
}

- (void)dealloc
{
    listener_destroy(&self->OnChange);
    [super dealloc];
}

@end

static NSColorChoose *i_COLOR_CHOOSE = nil;

/*---------------------------------------------------------------------------*/

void oscomwin_color(OSWindow *parent, const char_t *title, const real32_t x, const real32_t y, const align_t halign, const align_t valign, const color_t current, color_t *colors, const uint32_t n, Listener *OnChange)
{
    NSColorPanel *panel = [NSColorPanel sharedColorPanel];

    if (str_empty_c(title) == FALSE)
        [panel setTitle:[NSString stringWithUTF8String:title]];

    if (i_COLOR_CHOOSE != nil)
    {
        [i_COLOR_CHOOSE release];
        i_COLOR_CHOOSE = nil;
    }

    i_COLOR_CHOOSE = [NSColorChoose alloc];
    i_COLOR_CHOOSE->OnChange = OnChange;
    [panel setTarget:i_COLOR_CHOOSE];
    [panel setAction:@selector(onColorChange:)];

    /*[NSColorPanel setPickerMode:NSColorPanelModeRGB];*/
    [panel setColor:_oscontrol_color(current)];
    [panel setShowsAlpha:YES];

    if ([panel isVisible] == NO)
    {
        NSPoint origin = NSMakePoint((CGFloat)x, (CGFloat)y);
        NSSize size = [panel frame].size;
        CGFloat sh = [[NSScreen mainScreen] frame].size.height;
        if (halign != ekLEFT || valign != ekTOP)
        {
            switch (halign)
            {
            case ekLEFT:
            case ekJUSTIFY:
                break;
            case ekCENTER:
                origin.x -= size.width / 2;
                break;
            case ekRIGHT:
                origin.x -= size.width;
                break;
                cassert_default();
            }

            switch (valign)
            {
            case ekTOP:
            case ekJUSTIFY:
                break;
            case ekCENTER:
                origin.x -= size.height / 2;
                break;
            case ekBOTTOM:
                origin.x -= size.height;
                break;
                cassert_default();
            }
        }

        origin.y = sh - origin.y - size.height;
        [panel setFrameOrigin:origin];
        [panel makeKeyAndOrderFront:(NSWindow *)parent];
    }

    /* 
//    ret = [NSApp runModalForWindow:panel];

//#if defined (MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
//
//
////        NSModalResponse ret = [panel runModalForWindow:nil];
////        if (ret == NSModalResponseOK)
////            return i_save_file_selected(save_panel);
////        else
////            return NULL;
//    }
//    #else
//    {
//        NSUInteger ret = (NSUInteger)[save_panel runModal];
//        if (ret == NSFileHandlingPanelOKButton)
//            return i_save_file_selected(save_panel);
//        else
//            return NULL;
//    }
//    #endif
 */
    unref(parent);
    unref(title);
    unref(x);
    unref(y);
    unref(halign);
    unref(valign);
    unref(current);
    unref(colors);
    unref(n);
}

/*---------------------------------------------------------------------------*/

void _oscomwin_destroy_globals(void)
{
    if (i_COLOR_CHOOSE != nil)
    {
        [i_COLOR_CHOOSE release];
        i_COLOR_CHOOSE = nil;
    }
}

/*---------------------------------------------------------------------------*/

/*
void oscommon_file(
                    OSWindow *owner_window,
                    const uchar_t **allowed_file_types,
                    const uint32_t num_file_types,
                    const bool_t for_open,
                    Listener *OnAccept_listener)
{
    cassert([(NSObject*)owner_window isKindOfClass:[OSXWindow class]] == YES);
    cassert_no_null(OnAccept_listener);
    unreferenced(OnAccept_listener);
    unreferenced(owner_window);
    if (for_open == TRUE)
    {
        NSOpenPanel *open_panel;
        open_panel = i_open_file_panel(allowed_file_types, num_file_types, NULL);
        [open_panel setLevel:1000];
        [open_panel setFloatingPanel:NO];

            // 10.5
      //  cassert(FALSE);


        [open_panel beginSheetModalForWindow:(NSWindow*)owner_window completionHandler:^(NSInteger result)
        {
            if (result == NSFileHandlingPanelOKButton)
            {
                Event event;
                EvFile params;
                event.type = ekGUI_EVENT_OPEN_FILE;
                event.sender = open_panel;
                event.params = &params;
                event.result = NULL;
                params.pathname = i_open_file_selected(open_panel);
                listener_launch_event(OnAccept_listener, &event);
            }
        }];

    }
    else
    {
        NSSavePanel *save_panel;
        save_panel = i_save_file_panel(allowed_file_types, num_file_types);
        [save_panel setLevel:1000];
        [save_panel setFloatingPanel:NO];

        // 10.5
    //    cassert(FALSE);

        [save_panel beginSheetModalForWindow:(NSWindow*)owner_window completionHandler:^(NSInteger result)
        {
            if (result == NSFileHandlingPanelOKButton)
            {
                Event event;
                EvFile params;
                event.type = ekGUI_EVENT_SAVE_FILE;
                event.sender = save_panel;
                event.params = &params;
                event.result = NULL;
                params.pathname = i_save_file_selected(save_panel);
                listener_launch_event(OnAccept_listener, &event);
            }
        }];*/
/*  }
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_close(void)
{
    [[NSColorPanel sharedColorPanel] orderOut:nil];
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_convert_to_hud(void)
{
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_set_size(const real32_t width, const real32_t height)
{
    NSRect frame;
    frame = [NSColorPanel sharedColorPanel].frame;
    frame.origin.y += frame.size.height - (CGFloat)height;
    frame.size.width = (CGFloat)width;
    frame.size.height = (CGFloat)height;
    [[NSColorPanel sharedColorPanel] setFrame:frame display:YES animate:NO];
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_get_size(real32_t *width, real32_t *height)
{
    NSSize size;
    cassert_no_null(width);
    cassert_no_null(height);
    size = [[NSColorPanel sharedColorPanel] frame].size;
    *width = (real32_t)size.width;
    *height = (real32_t)size.height;
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_set_origin(const real32_t x, const real32_t y)
{
    NSRect window_frame;
    NSPoint origin;
    window_frame = [[NSColorPanel sharedColorPanel] frame];
    window_frame.origin.x = (CGFloat)x;
    window_frame.origin.y = (CGFloat)y;
    _oscontrol_origin_in_screen_coordinates(&window_frame, &origin.x, &origin.y);
    [[NSColorPanel sharedColorPanel] setFrameOrigin:origin];
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_get_origin(real32_t *x, real32_t *y)
{
    NSRect frame;
    NSPoint origin;
    cassert_no_null(x);
    cassert_no_null(y);
    frame = [[NSColorPanel sharedColorPanel] frame];
    _oscontrol_origin_in_screen_coordinates(&frame, &origin.x, &origin.y);
    *x = (real32_t)origin.x;
    *y = (real32_t)origin.y;
}*/
