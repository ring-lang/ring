/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp_gtk.c
 *
 */

/* Application runloop */

#include "osapp.h"
#include "osapp.inl"
#include "osapp_gtk.inl"
#include <osgui/osgui.h>
#include <core/event.h>
#include <core/strings.h>
#include <osbs/bfile.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <stdlib.h>
#include <locale.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _osapp_t
{
    GtkApplication *gtk_app;
    uint32_t argc;
    char_t **argv;
    gchar *resources_dir;
    gchar *user_dir;
    guint timer_loop_id;
    guint timer_init_id;
    void *listener;
    GdkPixbuf *icon;
    bool_t is_init;
    bool_t terminate;
    bool_t abnormal_termination;
    bool_t with_run_loop;
    Listener *OnTheme;
    FPtr_app_call func_OnFinishLaunching;
    FPtr_app_call func_OnTimerSignal;
    FPtr_destroy func_destroy;
    FPtr_app_void func_OnExecutionEnd;
};

/*---------------------------------------------------------------------------*/

static OSApp i_APP;

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
    static char GDK_BACKEND[64];
    bmem_zero(&i_APP, OSApp);
    cassert_unref(instance == NULL, instance);
    cassert_no_null(listener);
    cassert_no_nullf(func_OnFinishLaunching);
    cassert(i_APP.listener == NULL);
    cassert(i_APP.func_OnFinishLaunching == NULL);
    cassert(i_APP.func_OnTimerSignal == NULL);
    str_copy_c(GDK_BACKEND, sizeof(GDK_BACKEND), "GDK_BACKEND=x11");
    putenv(GDK_BACKEND);
    cassert(g_application_id_is_valid("com.nappgui.app") == TRUE);
    i_APP.gtk_app = gtk_application_new("com.nappgui.app", G_APPLICATION_NON_UNIQUE);
    cassert_no_null(i_APP.gtk_app);
    i_APP.argc = argc;
    i_APP.argv = argv;
    i_APP.resources_dir = g_strdup("resources_dir");
    i_APP.user_dir = g_strdup("user_dir");
    i_APP.timer_loop_id = 0;
    i_APP.timer_init_id = 0;
    i_APP.listener = listener;
    i_APP.is_init = FALSE;
    i_APP.terminate = FALSE;
    i_APP.abnormal_termination = FALSE;
    i_APP.with_run_loop = with_run_loop;
    i_APP.OnTheme = NULL;
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
    cassert_no_nullf(app->func_destroy);
    cassert_no_nullf(app->func_OnExecutionEnd);
    cassert(app->terminate == TRUE);

    if (app->abnormal_termination == FALSE)
    {
        g_free((gpointer)app->resources_dir);
        g_free((gpointer)app->user_dir);
        app->func_destroy(&app->listener);
    }

    if (app->icon != NULL)
        g_object_unref(app->icon);

    listener_destroy(&app->OnTheme);
    osgui_terminate();

    g_application_quit(G_APPLICATION(app->gtk_app));
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
    (*app)->abnormal_termination = abnormal_termination;
    (*app)->func_destroy = func_destroy;
    (*app)->func_OnExecutionEnd = func_OnExecutionEnd;
    (*app)->terminate = TRUE;
}

/*---------------------------------------------------------------------------*/

uint32_t osapp_argc(OSApp *app)
{
    cassert_no_null(app);
    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

void osapp_argv(OSApp *app, const uint32_t index, char_t *argv, const uint32_t max_size)
{
    unref(app);
    unref(index);
    unref(argv);
    unref(max_size);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

/* This function will be called repeatedly during the life-cycle of the app
   until it returns FALSE, at which point the timeout is automatically destroyed
   and the function will not be called again. */
static gboolean i_OnTimerLoop(gpointer data)
{
    OSApp *app = (OSApp *)data;
    cassert(app == &i_APP);

    if (app->terminate == TRUE)
    {
        i_terminate(app);
        return FALSE;
    }

    if (app->func_OnTimerSignal != NULL)
        app->func_OnTimerSignal(app->listener);

    return TRUE;
}

/*---------------------------------------------------------------------------*/

/* This function will be called repeatedly until the application is created,
   at which point the timeout is automatically destroyed and the function will
   not be called again. */
static gboolean i_OnTimerInit(gpointer data)
{
    OSApp *app = (OSApp *)data;
    cassert(app == &i_APP);

    /* Create impostor window before app running */
    if (osgui_is_initialized() == TRUE)
    {
        if (app->is_init == FALSE)
        {
            app->is_init = TRUE;
            app->func_OnFinishLaunching(app->listener);
            return FALSE;
        }
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static void i_OnActivate(GtkApplication *gtk_app, OSApp *app)
{
    char_t pathname[1024];
    cassert_no_null(app);
    cassert_no_null(app->listener);
    cassert_no_nullf(app->func_OnTimerSignal);
    cassert(app->timer_loop_id == 0);
    cassert(app->timer_init_id == 0);
    if (bfile_dir_exec(pathname, sizeof(pathname)) < sizeof(pathname))
    {
        String *logo = str_cpath("%s.ico", pathname);
        app->icon = gdk_pixbuf_new_from_file(tc(logo), NULL);
        osgui_set_app(gtk_app, app->icon);
        str_destroy(&logo);
    }

    /* printf decimal separator */
    setlocale(LC_NUMERIC, "C");

    osgui_initialize();
    g_application_hold(G_APPLICATION(gtk_app));

    app->timer_loop_id = g_timeout_add(10, i_OnTimerLoop, (gpointer)app);
    app->timer_init_id = g_timeout_add(10, i_OnTimerInit, (gpointer)app);
    cassert(app->timer_loop_id > 0);
    cassert(app->timer_init_id > 0);
}

/*---------------------------------------------------------------------------*/

void osapp_run(OSApp *app)
{
    gulong signal_id = 0;
    int status = 0;
    cassert_no_null(app);
    cassert(app->with_run_loop == TRUE);
    signal_id = g_signal_connect(app->gtk_app, "activate", G_CALLBACK(i_OnActivate), (gpointer)app);
    cassert_unref(signal_id > 0, signal_id);
    status = g_application_run(G_APPLICATION(app->gtk_app), app->argc, app->argv);
    unref(status);
    app->func_OnExecutionEnd();
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
    String *cmd = str_printf("x-www-browser %s", url);
    int t = system(tc(cmd));
    str_destroy(&cmd);
    unref(t);
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
    cassert_no_null(app);
    listener_update(&app->OnTheme, listener);
}
