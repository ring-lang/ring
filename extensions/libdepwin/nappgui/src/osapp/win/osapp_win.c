/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp_win.c
 *
 */

/* Application runloop */

#include "osapp.h"
#include "osapp.inl"
#include "osapp_win.inl"
#include <osgui/osgui.h>
#include <core/event.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <ShlObj.h>
#include <sewer/warn.hxx>

struct _osapp_t
{
    HINSTANCE instance;
    int nArgs;
    LPWSTR *szArgList;
    UINT_PTR timer;
    void *listener;
    bool_t abnormal_termination;
    bool_t with_run_loop;
    FPtr_app_call func_OnFinishLaunching;
    FPtr_app_call func_OnTimerSignal;
    FPtr_destroy func_destroy;
    FPtr_app_void func_OnExecutionEnd;
};

/*---------------------------------------------------------------------------*/

OSApp i_APP = {0};

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
    unref(argc);
    unref(argv);
    cassert_no_null(instance);
    cassert_no_null(listener);
    cassert_no_nullf(func_OnFinishLaunching);
    cassert(i_APP.instance == NULL);
    cassert(i_APP.listener == NULL);
    cassert(i_APP.func_OnFinishLaunching == NULL);
    cassert(i_APP.func_OnTimerSignal == NULL);
    i_APP.instance = (HINSTANCE)instance;
    i_APP.szArgList = CommandLineToArgvW(GetCommandLineW(), &i_APP.nArgs);
    cassert(i_APP.szArgList != NULL);
    i_APP.listener = listener;
    i_APP.abnormal_termination = FALSE;
    i_APP.with_run_loop = with_run_loop;
    i_APP.func_OnFinishLaunching = func_OnFinishLaunching;
    i_APP.func_OnTimerSignal = func_OnTimerSignal;
    return &i_APP;
}

/*---------------------------------------------------------------------------*/

void *osapp_init_pool(void)
{
    return NULL;
}

/*---------------------------------------------------------------------------*/

void osapp_release_pool(void *pool)
{
    cassert_unref(pool == NULL, pool);
}

/*---------------------------------------------------------------------------*/

void *osapp_listener_imp(void)
{
    return i_APP.listener;
}

/*---------------------------------------------------------------------------*/

static void i_terminate(OSApp *app)
{
    cassert_no_null(app);
    cassert(app == &i_APP);
    if (app->func_OnTimerSignal != NULL)
    {
        BOOL ok = KillTimer(NULL, app->timer);
        cassert_unref(ok != 0, ok);
    }

    {
        HLOCAL ret = LocalFree(app->szArgList);
        cassert_unref(ret == NULL, ret);
    }

    cassert_no_nullf(app->func_destroy);
    cassert_no_nullf(app->func_OnExecutionEnd);
    if (app->abnormal_termination == FALSE)
    {
        app->func_destroy(&app->listener);
        app->func_OnExecutionEnd();
    }
}

/*---------------------------------------------------------------------------*/

void osapp_terminate_imp(OSApp **app, const bool_t abnormal_termination, FPtr_destroy func_destroy, FPtr_app_void func_OnExecutionEnd)
{
    cassert_no_null(app);
    cassert_no_null(*app);
    cassert(*app == &i_APP);
    cassert((*app)->func_destroy == NULL);
    cassert((*app)->func_OnExecutionEnd == NULL);
    cassert_no_nullf(func_destroy);
    cassert_no_nullf(func_OnExecutionEnd);

    (*app)->func_destroy = func_destroy;
    (*app)->func_OnExecutionEnd = func_OnExecutionEnd;

    if (abnormal_termination == TRUE)
        ExitProcess(0);

    (*app)->abnormal_termination = FALSE;
    if ((*app)->with_run_loop == TRUE)
        PostQuitMessage(0);
    else
        i_terminate(*app);
}

/*---------------------------------------------------------------------------*/

uint32_t osapp_argc(OSApp *app)
{
    cassert_no_null(app);
    return (uint32_t)app->nArgs;
}

/*---------------------------------------------------------------------------*/

void osapp_argv(OSApp *app, const uint32_t index, char_t *argv, const uint32_t max_size)
{
    cassert_no_null(app);
    cassert(index < (uint32_t)app->nArgs);
    unicode_convers((const char_t *)app->szArgList[index], argv, ekUTF16, ekUTF8, max_size);
}

/*---------------------------------------------------------------------------*/

static VOID CALLBACK i_OnTimer(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    cassert(hwnd == NULL);
    unref(hwnd);
    cassert(uMsg == WM_TIMER);
    unref(uMsg);
    cassert(idEvent == i_APP.timer);
    unref(idEvent);
    unref(dwTime);
    cassert_no_nullf(i_APP.func_OnTimerSignal);
    i_APP.func_OnTimerSignal(i_APP.listener);
}

/*---------------------------------------------------------------------------*/

void osapp_run(OSApp *app)
{
    cassert_no_null(app);
    cassert_no_null(app->listener);
    cassert_no_nullf(app->func_OnFinishLaunching);
    cassert(app->timer == 0);

    if (app->func_OnTimerSignal != NULL)
    {
        app->timer = SetTimer(NULL, 0, 20, i_OnTimer);
        cassert(app->timer > 0);
    }

    app->func_OnFinishLaunching(app->listener);

    if (app->with_run_loop == TRUE)
    {
        osgui_message_loop();
        i_terminate(app);
    }
}

/*---------------------------------------------------------------------------*/

void osapp_request_user_attention(OSApp *app)
{
    unref(app);
}

/*---------------------------------------------------------------------------*/

void osapp_cancel_user_attention(OSApp *app)
{
    unref(app);
}

/*---------------------------------------------------------------------------*/

void *osapp_begin_thread(OSApp *app)
{
    unref(app);
    return NULL;
}

/*---------------------------------------------------------------------------*/

void osapp_end_thread(OSApp *app, void *data)
{
    unref(app);
    unref(data);
}

/*---------------------------------------------------------------------------*/

void osapp_open_url(const char_t *url)
{
    WCHAR wurl[512];
    uint32_t num_bytes = 0;
    num_bytes = unicode_convers(url, (char_t *)wurl, ekUTF8, ekUTF16, sizeof(wurl));
    cassert(num_bytes < sizeof(wurl));
    ShellExecute(NULL, L"open", wurl, NULL, NULL, SW_RESTORE);
}

/*---------------------------------------------------------------------------*/

void osapp_set_lang(OSApp *app, const char_t *lang)
{
    unref(app);
    unref(lang);
}

/*---------------------------------------------------------------------------*/

void osapp_OnThemeChanged(OSApp *app, Listener *listener)
{
    unref(app);
    listener_destroy(&listener);
}
