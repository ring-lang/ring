/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp_osx.m
 *
 */

/* Application runloop */

#include "osapp.h"
#include "osapp.inl"
#include "osapp_osx.inl"
#include <osgui/osglobals.h>
#include <core/event.h>
#include <osbs/log.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
@interface OSXAppDelegate : NSObject <NSApplicationDelegate>
#else
@interface OSXAppDelegate : NSObject
#endif
{
  @public
    uint32_t argc;
    char_t **argv;
    NSTimer *timer;
    uint32_t terminate_count;
    bool_t abnormal_termination;
    bool_t theme_changed;
    void *listener;

    FPtr_app_call func_OnFinishLaunching;
    FPtr_app_call func_OnTimerSignal;
    FPtr_destroy func_destroy;
    FPtr_app_void func_OnExecutionEnd;
    Listener *OnThemeChanged;
}

@end

/*---------------------------------------------------------------------------*/

#define i_TERMINATE_COUNTLOOP 15

/*---------------------------------------------------------------------------*/

@implementation OSXAppDelegate

/*---------------------------------------------------------------------------*/

- (void)realTerminate
{
    /* Cocoa releases certain objects at the end of the runLoop. This forces
     the execution of several RunLoops after completion, to ensure that all
     objects have been released and marked in 'heap'.

     self->func_destroy Destroys the app
     self->func_OnExecutionEnd Finishes libraries and logs
     */
    if (self->terminate_count == 1)
    {
        cassert_no_nullf(self->func_destroy);
        if (self->abnormal_termination == FALSE)
        {
            self->func_destroy(&self->listener);
        }
    }
    else if (self->terminate_count == i_TERMINATE_COUNTLOOP)
    {
        [NSApp terminate:self];
        log_printf("NSApp terminate shouldn't return");
    }

    self->terminate_count += 1;
}

/*---------------------------------------------------------------------------*/

- (void)synchronousTimer:(NSTimer *)t
{
    unref(t);
    /* https://stackoverflow.com/questions/52504872/updating-for-dark-mode-nscolor-ignores-appearance-changes?rq=1 */
    if (self->theme_changed == TRUE)
    {
        bool_t dark_mode = FALSE;

#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
        {
            NSArray *appers = [NSArray arrayWithObjects:NSAppearanceNameAqua, NSAppearanceNameDarkAqua, nil];
            NSAppearance *apper = [NSApp effectiveAppearance];
            NSAppearanceName name = [apper bestMatchFromAppearancesWithNames:appers];
            if ([name isEqualToString:NSAppearanceNameDarkAqua])
                dark_mode = TRUE;
        }
#endif

        unref(dark_mode);
        osglobals_theme_changed();

        if (self->OnThemeChanged != NULL)
            listener_event(self->OnThemeChanged, 0, (OSApp *)self->listener, NULL, NULL, OSApp, void, void);

        self->theme_changed = FALSE;
    }

    if (__FALSE_EXPECTED(self->terminate_count > 0))
    {
        [self realTerminate];
    }
    else
    {
        cassert_no_nullf(self->func_OnTimerSignal);
        self->func_OnTimerSignal(self->listener);
    }
}

/*---------------------------------------------------------------------------*/

- (void)terminateTimer:(NSTimer *)t
{
    unref(t);
    if (__FALSE_EXPECTED(self->terminate_count > 0))
    {
        [self realTerminate];
    }
}

/*---------------------------------------------------------------------------*/

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    unref(aNotification);
    cassert(self->timer == NULL);
    cassert_no_nullf(self->func_OnFinishLaunching);

    if (self->func_OnTimerSignal != NULL)
    {
        self->timer = [NSTimer timerWithTimeInterval:(.01) target:self selector:@selector(synchronousTimer:) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSModalPanelRunLoopMode];
    }
    else
    {
        self->timer = [NSTimer timerWithTimeInterval:(.25) target:self selector:@selector(terminateTimer:) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSModalPanelRunLoopMode];
    }

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
    [[NSDistributedNotificationCenter defaultCenter] addObserver:self
                                                        selector:@selector(themeChanged:)
                                                            name:@"AppleInterfaceThemeChangedNotification"
                                                          object:nil];
    [[NSDistributedNotificationCenter defaultCenter] addObserver:self selector:@selector(themeChanged:) name:@"AppleColorPreferencesChangedNotification" object:nil];
#endif

    self->func_OnFinishLaunching(self->listener);
}

/*---------------------------------------------------------------------------*/

/*- (BOOL)application:(NSApplication*)theApplication openFile:(NSString*)filename
{
    unref(theApplication);
    cassert_no_nullf(self->func_OnOpenFile);
    self->func_OnOpenFile(self->listener, (const char_t*)[filename UTF8String]);
    return YES;
}*/

/*---------------------------------------------------------------------------*/

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication
{
    unref(theApplication);
    return NO;
}

/*---------------------------------------------------------------------------*/

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender
{
    unref(sender);
    if (self->listener != NULL)
    {
        return NSTerminateCancel;
    }
    else
    {
        return NSTerminateNow;
    }
}

/*---------------------------------------------------------------------------*/

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
    unref(aNotification);
    cassert(self->listener == NULL);
    cassert_no_null(self->timer);
    cassert_no_nullf(self->func_OnExecutionEnd);
    [self->timer release];
    self->timer = nil;
    self->func_OnExecutionEnd();
    [[NSApplication sharedApplication] setDelegate:nil];
    [self release];
}

/*---------------------------------------------------------------------------*/

- (void)themeChanged:(NSNotification *)aNotification
{
    unref(aNotification);
    /* The new theme is not effective yet. We have to catch and notify in next loop cicle */
    self->theme_changed = TRUE;
}

/*---------------------------------------------------------------------------*/

- (void)dealloc
{
    [super dealloc];
}

@end

/*---------------------------------------------------------------------------*/

OSApp *osapp_init_imp(
    uint32_t argc,
    char_t **argv,
    void *instance,
    void *listener,
    const bool_t with_run_loop,
    FPtr_app_call func_OnFinishLaunching,
    FPtr_app_call func_OnTimerSignal)
{
    NSApplication *app;
    OSXAppDelegate *delegate;
    unref(instance);
    unref(with_run_loop);
    app = [NSApplication sharedApplication];
    cassert(app == NSApp);
    delegate = [OSXAppDelegate alloc];
    delegate->argc = argc;
    delegate->argv = argv;
    delegate->timer = NULL;
    delegate->listener = listener;
    delegate->terminate_count = 0;
    delegate->abnormal_termination = FALSE;
    delegate->theme_changed = FALSE;
    delegate->func_OnFinishLaunching = func_OnFinishLaunching;
    delegate->func_OnTimerSignal = func_OnTimerSignal;
    delegate->func_destroy = NULL;
    delegate->func_OnExecutionEnd = NULL;
    delegate->OnThemeChanged = NULL;
    [NSApp setDelegate:delegate];
    return (OSApp *)app;
}

/*---------------------------------------------------------------------------*/

void *osapp_init_pool(void)
{
    return (void *)[[NSAutoreleasePool alloc] init];
}

/*---------------------------------------------------------------------------*/

void osapp_release_pool(void *pool)
{
    [(NSAutoreleasePool *)pool drain];
}

/*---------------------------------------------------------------------------*/

void *osapp_listener_imp(void)
{
    cassert_no_null(NSApp);
    cassert_no_null([NSApp delegate]);
    return ((OSXAppDelegate *)[NSApp delegate])->listener;
}

/*---------------------------------------------------------------------------*/

void osapp_terminate_imp(
    OSApp **app,
    const bool_t abnormal_termination,
    FPtr_destroy func_destroy,
    FPtr_app_void func_OnExecutionEnd)
{
    OSXAppDelegate *delegate;
    cassert_no_null(app);
    cassert_no_null(*app);
    cassert((NSApplication *)(*app) == NSApp);
    delegate = [NSApp delegate];
    cassert_no_null(delegate);
    cassert(delegate->func_destroy == NULL);
    cassert(delegate->func_OnExecutionEnd == NULL);
    delegate->abnormal_termination = abnormal_termination;
    delegate->func_destroy = func_destroy;
    delegate->func_OnExecutionEnd = func_OnExecutionEnd;
    delegate->terminate_count = 1;
    listener_destroy(&delegate->OnThemeChanged);
}

/*---------------------------------------------------------------------------*/

uint32_t osapp_argc(OSApp *app)
{
    OSXAppDelegate *delegate = NULL;
    cassert_no_null(app);
    cassert((NSApplication *)app == NSApp);
    delegate = [(NSApplication *)app delegate];
    return delegate->argc;
}

/*---------------------------------------------------------------------------*/

void osapp_argv(OSApp *app, const uint32_t idx, char_t *argv, const uint32_t max_size)
{
    OSXAppDelegate *delegate = NULL;
    cassert_no_null(app);
    cassert((NSApplication *)app == NSApp);
    delegate = [(NSApplication *)app delegate];
    unicode_convers((const char_t *)delegate->argv[idx], argv, ekUTF8, ekUTF8, max_size);
}

/*---------------------------------------------------------------------------*/

void osapp_run(OSApp *app)
{
    cassert_no_null(app);
    cassert((NSApplication *)app == NSApp);
    [(NSApplication *)app run];
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void osapp_request_user_attention(OSApp *app)
{
    cassert_no_null(app);
    cassert((NSApplication *)app == NSApp);
    [(NSApplication *)app requestUserAttention:NSCriticalRequest];
}

/*---------------------------------------------------------------------------*/

void osapp_cancel_user_attention(OSApp *app)
{
    cassert_no_null(app);
    cassert((NSApplication *)app == NSApp);
    [(NSApplication *)app cancelUserAttentionRequest:NSCriticalRequest];
}

/*---------------------------------------------------------------------------*/

void *osapp_begin_thread(OSApp *app)
{
    /* A secondary thread shouldn't call Cocoa */
    /* But is possible that create NSImage objects whithout any AutoreleasePool */
    /* __NSAutoreleaseNoPool(): Object 0x10123a200 of class
        NSConcreteData autoreleased with no pool in place - just leaking */
    /* This snipplet avoid memory leaks */
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    unref(app);
    return (void *)pool;
}

/*---------------------------------------------------------------------------*/

void osapp_end_thread(OSApp *app, void *data)
{
    NSAutoreleasePool *pool = (NSAutoreleasePool *)data;
    unref(app);
    [pool drain];
}

/*---------------------------------------------------------------------------*/

void osapp_open_url(const char_t *url)
{
    NSString *str = [NSString stringWithUTF8String:url];
    NSURL *nsurl = [NSURL URLWithString:str];
    [[NSWorkspace sharedWorkspace] openURL:nsurl];
}

/*---------------------------------------------------------------------------*/

void osapp_set_lang(OSApp *app, const char_t *lang)
{
    NSAutoreleasePool *pool = nil;
    NSString *str = nil;
    cassert_no_null(app);
    cassert((NSApplication *)app == NSApp);
    pool = [[NSAutoreleasePool alloc] init];
    str = [[NSString alloc] initWithUTF8String:(const char *)lang];
    [[NSUserDefaults standardUserDefaults] setObject:[NSArray arrayWithObject:str] forKey:@"AppleLanguages"];
    [str release];
    [pool drain];
}

/*---------------------------------------------------------------------------*/

void osapp_OnThemeChanged(OSApp *app, Listener *listener)
{
    OSXAppDelegate *delegate = [(NSApplication *)app delegate];
    listener_update(&delegate->OnThemeChanged, listener);
}
