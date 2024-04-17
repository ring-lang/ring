/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osprogress.m
 *
 */

/* Operating System native progress indicator */

#include "osprogress.h"
#include "osprogress_osx.inl"
#include "oscontrol_osx.inl"
#include "ospanel_osx.inl"
#include "osgui.inl"
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

@interface OSXProgress : NSProgressIndicator
{
  @public
    void *non_used;
}
@end

/*---------------------------------------------------------------------------*/

@implementation OSXProgress

@end

/*---------------------------------------------------------------------------*/

#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
#define STYLE_BAR NSProgressIndicatorStyleBar
#else
#define STYLE_BAR NSProgressIndicatorBarStyle
#endif

/*---------------------------------------------------------------------------*/

OSProgress *osprogress_create(const uint32_t flags)
{
    OSXProgress *progress;
    cassert_unref(progress_get_type(flags) == ekPROGRESS_HORZ, flags);
    heap_auditor_add("OSXProgress");
    progress = [[OSXProgress alloc] initWithFrame:NSZeroRect];
    _oscontrol_init(progress);
    [progress setStyle:STYLE_BAR];
    [progress setUsesThreadedAnimation:NO];
    [progress setIndeterminate:NO];
    [progress setMinValue:0.];
    [progress setMaxValue:1.];
    return (OSProgress *)progress;
}

/*---------------------------------------------------------------------------*/

void osprogress_destroy(OSProgress **progress)
{
    cassert_no_null(progress);
    [(OSXProgress *)*progress release];
    *progress = NULL;
    heap_auditor_delete("OSXProgress");
}

/*---------------------------------------------------------------------------*/

void osprogress_position(OSProgress *progress, const real32_t position)
{
    cassert_no_null(progress);
    /* Indeterminate progress */
    if (position < 0.f)
    {
        if ([(OSXProgress *)progress isIndeterminate] == NO)
            [(OSXProgress *)progress setIndeterminate:YES];

        if (position < -1.f)
            [(OSXProgress *)progress startAnimation:nil];
        else
            [(OSXProgress *)progress stopAnimation:nil];
    }
    else
    {
        cassert(position <= 1.f);
        if ([(OSXProgress *)progress isIndeterminate] == YES)
            [(OSXProgress *)progress setIndeterminate:NO];

        [(OSXProgress *)progress setDoubleValue:(double)position];
    }
}

/*---------------------------------------------------------------------------*/

real32_t osprogress_thickness(const OSProgress *progress, const gui_size_t size)
{
    unref(progress);
    cassert_unref(size == ekGUI_SIZE_REGULAR, size);
    return 16;
}

/*---------------------------------------------------------------------------*/

void osprogress_attach(OSProgress *progress, OSPanel *panel)
{
    _ospanel_attach_control(panel, (NSView *)progress);
}

/*---------------------------------------------------------------------------*/

void osprogress_detach(OSProgress *progress, OSPanel *panel)
{
    _ospanel_detach_control(panel, (NSView *)progress);
}

/*---------------------------------------------------------------------------*/

void osprogress_visible(OSProgress *progress, const bool_t is_visible)
{
    _oscontrol_set_visible((NSView *)progress, is_visible);
}

/*---------------------------------------------------------------------------*/

void osprogress_enabled(OSProgress *progress, const bool_t is_enabled)
{
    cassert_no_null(progress);
    unref(is_enabled);
}

/*---------------------------------------------------------------------------*/

void osprogress_size(const OSProgress *progress, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((NSView *)progress, width, height);
}

/*---------------------------------------------------------------------------*/

void osprogress_origin(const OSProgress *progress, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((NSView *)progress, x, y);
}

/*---------------------------------------------------------------------------*/

void osprogress_frame(OSProgress *progress, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((NSView *)progress, x, y, width, height);
}

/*---------------------------------------------------------------------------*/

BOOL _osprogress_is(NSView *view)
{
    return [view isKindOfClass:[OSXProgress class]];
}
