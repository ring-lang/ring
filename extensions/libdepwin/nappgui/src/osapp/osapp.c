/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp.c
 *
 */

/* Application runloop */

#include "osmain.h"
#include "osapp.h"
#include "osapp.inl"
#include <gui/gui.h>
#include <gui/menu.h>
#include <gui/window.h>
#include <osgui/osgui.h>
#include <osgui/osguictx.h>
#include <draw2d/guictx.h>
#include <core/arrpt.h>
#include <core/clock.h>
#include <core/core.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/hfile.h>
#include <core/objh.h>
#include <core/strings.h>
#include <osbs/bfile.h>
#include <osbs/bthread.h>
#include <osbs/log.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

typedef struct i_task_t i_Task;
typedef struct i_app_t i_App;

typedef enum _icon_t
{
    i_ekICON_ASSERT = 0,
    i_ekICON_CRASH = 1,
    i_ekICON_SYSTEM = 2
} icon_t;

typedef enum _task_state_t
{
    i_ekSTATE_RUNNING = 0,
    i_ekSTATE_WAITING = 1,
    i_ekSTATE_FINISH = 2,

    i_ekSTATE_ASSERT = 6,
    i_ekSTATE_ERROR = 7,
    i_ekSTATE_MESSAGE = 8,

    i_ekSTATE_DEBUG_BREAK = 9
} tstate_t;

struct i_task_t
{
    OSApp *osapp;
    Thread *thread;
    void *data;
    real64_t updtime;
    real64_t lastupd;
    FPtr_task_main func_main;
    FPtr_task_update func_update;
    FPtr_task_end func_end;
    tstate_t state;
};

struct i_app_t
{
    Object object;
    OSApp *osapp;
    tstate_t state;
    real64_t lframe;
    Clock *clock;
    Clock *app_clock;
    void *appitem;
    GuiCtx *native_gui;
    bool_t initialized;
    bool_t terminated;
    FPtr_app_create func_create;
    FPtr_destroy func_destroy;
    FPtr_app_update func_update;
    FPtr_gctx_call func_async_call;
    String *locale;
    ArrPt(i_Task) *scheduler;
};

DeclSt(i_Task);
DeclPt(i_Task);

/*---------------------------------------------------------------------------*/

static void i_destroy_task(i_Task **task)
{
    cassert_no_null(task);
    cassert_no_null(*task);
    bthread_close(&(*task)->thread);
    heap_delete(task, i_Task);
}

/*---------------------------------------------------------------------------*/

static void i_destroy_app(i_App **app)
{
    cassert_no_null(app);
    cassert_no_null(*app);
    cassert(arrpt_size((*app)->scheduler, i_Task) == 0);

    if ((*app)->appitem != NULL)
    {
        cassert_no_nullf((*app)->func_destroy);
        (*app)->func_destroy(&(*app)->appitem);
    }

    cassert_set_func(NULL, NULL);
    ptr_destopt(clock_destroy, &(*app)->clock, Clock);
    ptr_destopt(clock_destroy, &(*app)->app_clock, Clock);
    str_destroy(&(*app)->locale);
    arrpt_destroy(&(*app)->scheduler, i_destroy_task, i_Task);
    guictx_destroy(&(*app)->native_gui);
    obj_delete(app, i_App);
}

/*---------------------------------------------------------------------------*/

static void i_OnExecutionEnd(void)
{
    const char_t *logfile = log_get_file();
    gui_finish();
    osgui_finish();
    if (logfile != NULL)
        log_printf("You have an execution log in: '%s'", logfile);
}

/*---------------------------------------------------------------------------*/

static void i_terminate(void)
{
    i_App *app = osapp_listener(i_App);
    if (app->initialized == TRUE)
        osapp_terminate(&app->osapp, FALSE, i_destroy_app, i_OnExecutionEnd, i_App);
    else
        app->terminated = TRUE;
}

/*---------------------------------------------------------------------------*/

/* This function will run in a secondary thread
It should not call GUI functions */
static uint32_t i_dispatch_task(i_Task *task)
{
    uint32_t rvalue = UINT32_MAX;
    void *data;
    cassert_no_null(task);
    cassert(task->state == i_ekSTATE_WAITING);
    task->state = i_ekSTATE_RUNNING;
    data = osapp_begin_thread(task->osapp);
    cassert_no_nullf(task->func_main);
    rvalue = task->func_main(task->data);
    task->state = i_ekSTATE_FINISH;
    osapp_end_thread(task->osapp, data);
    return rvalue;
}

/*---------------------------------------------------------------------------*/

/* This function runs in the MAIN thread */
static void i_scheduler_cycle(ArrPt(i_Task) *scheduler, const real64_t crtime)
{
    i_Task *deleted_task = NULL;

    arrpt_foreach(task, scheduler, i_Task)
        if (task->state == i_ekSTATE_WAITING)
        {
            cassert(task->thread == NULL);
            task->thread = bthread_create(i_dispatch_task, task, i_Task);
            task->lastupd = crtime;
        }
        else if (task->state == i_ekSTATE_RUNNING)
        {
            if (task->func_update != NULL)
            {
                if (crtime - task->lastupd > task->updtime)
                {
                    task->func_update(task->data);
                    task->lastupd = crtime;
                }
            }
        }
        else if (task->state == i_ekSTATE_FINISH)
        {
            if (deleted_task == NULL)
            {
                uint32_t rvalue = bthread_wait(task->thread);
                if (task->func_end != NULL)
                    task->func_end(task->data, rvalue);
                deleted_task = task;
            }
        }
    arrpt_end()

    if (deleted_task != NULL)
    {
        uint32_t index = arrpt_find(scheduler, deleted_task, i_Task);
        arrpt_delete(scheduler, index, i_destroy_task, i_Task);
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnTimerSignal(i_App *app)
{
    real64_t prtime, crtime;
    cassert_no_null(app);
    if (clock_frame(app->clock, &prtime, &crtime))
    {
        if (app->state == i_ekSTATE_RUNNING)
        {
            i_scheduler_cycle(app->scheduler, crtime);
            gui_update_transitions(prtime, crtime);

            if (app->func_update != NULL)
            {
                real64_t prevapp_time, curapp_time;
                if (clock_frame(app->app_clock, &prevapp_time, &curapp_time))
                    app->func_update(app->appitem, prevapp_time, curapp_time);
            }
        }

        if (app->func_async_call != NULL)
        {
            FPtr_gctx_call func_async_call = app->func_async_call;
            app->func_async_call = NULL;
            func_async_call(app->appitem);
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnFinishLaunching(i_App *app)
{
    cassert_no_null(app);
    cassert(app->state == i_ekSTATE_WAITING);
    cassert(app->app_clock == NULL);
    cassert(app->initialized == FALSE);

    app->state = i_ekSTATE_RUNNING;

    if (app->func_update != NULL)
        app->app_clock = clock_create(app->lframe);

    if (app->func_create != NULL)
    {
        gui_update();
        app->appitem = app->func_create();
    }

    app->initialized = TRUE;
    osapp_cancel_user_attention(app->osapp);

    /* An application can terminate in app->func_create() */
    if (app->terminated == TRUE)
        i_terminate();
}

/*---------------------------------------------------------------------------*/

static void i_OnNotification(void *sender, Event *e)
{
    i_App *app = osapp_listener(i_App);
    uint32_t type = event_type(e);

    switch (type)
    {
    case ekGUI_NOTIF_LANGUAGE:
    {
        const char_t *params = event_params(e, char_t);
        osapp_set_lang(app->osapp, params);
        osgui_redraw_menubar();
        break;
    }

    case ekGUI_NOTIF_WIN_DESTROY:
    {
        const Window *window = event_params(e, Window);
        OSWindow *oswindow = (OSWindow *)window_imp(window);
        osgui_unset_menubar(NULL, oswindow);
        break;
    }

    case ekGUI_NOTIF_MENU_DESTROY:
    {
        const Menu *menu = event_params(e, Menu);
        OSMenu *osmenu = (OSMenu *)menu_imp(menu);
        osgui_unset_menubar(osmenu, NULL);
        break;
    }

        cassert_default();
    }
    unref(sender);
}

/*---------------------------------------------------------------------------*/

static void i_OnTheme(void *sender, Event *e)
{
    unref(sender);
    unref(e);
    gui_update();
}

/*---------------------------------------------------------------------------*/

void osmain_imp(
    uint32_t argc,
    char_t **argv,
    void *instance,
    const real64_t lframe,
    FPtr_app_create func_create,
    FPtr_app_update func_update,
    FPtr_destroy func_destroy,
    char_t *options)
{
    i_App *app = NULL;
    void *pool = NULL;
    char_t pathname[256];

    /* Init platform-dependent autorelease pool (MacOSX) */
    pool = osapp_init_pool();
    osgui_start();
    gui_start();

    if (options && str_str(options, "-hv") != NULL)
        heap_verbose(TRUE);

    bfile_dir_exec(pathname, sizeof(pathname));
    app = obj_new0(i_App);
    app->osapp = osapp_init(argc, argv, instance, app, TRUE, i_OnFinishLaunching, i_OnTimerSignal, i_App);
    app->state = i_ekSTATE_WAITING;
    app->lframe = lframe;
    app->clock = clock_create(.02);
    app->app_clock = NULL;
    app->appitem = NULL;
    app->native_gui = osguictx();
    app->func_create = func_create;
    app->func_destroy = func_destroy;
    app->func_update = func_update;
    app->func_async_call = NULL;
    app->locale = str_c("");
    app->scheduler = arrpt_create(i_Task);
    app->initialized = FALSE;
    app->terminated = FALSE;
    guictx_set_current(app->native_gui);
    gui_OnNotification(listener(NULL, i_OnNotification, void));

    osapp_OnThemeChanged(app->osapp, listener(NULL, i_OnTheme, void));
    osapp_set_lang(app->osapp, "en");
    osapp_request_user_attention(app->osapp);
    osapp_release_pool(pool);
    osapp_run(app->osapp);
}

/*---------------------------------------------------------------------------*/

void osapp_finish(void)
{
    i_terminate();
}

/*---------------------------------------------------------------------------*/

void osapp_task_imp(void *data, const real32_t updtime, FPtr_task_main func_task_main, FPtr_task_update func_task_update, FPtr_task_end func_task_end)
{
    i_App *app = osapp_listener(i_App);
    i_Task *task = heap_new0(i_Task);
    cassert_no_null(app);
    task->osapp = app->osapp;
    task->thread = NULL;
    task->data = data;
    task->updtime = updtime <= 0 && func_task_update ? .04 : updtime;
    task->lastupd = 0.;
    task->func_main = func_task_main;
    task->func_update = func_task_update;
    task->func_end = func_task_end;
    task->state = i_ekSTATE_WAITING;
    arrpt_append(app->scheduler, task, i_Task);
}

/*---------------------------------------------------------------------------*/

void osapp_menubar(Menu *menu, Window *window)
{
    void *oswindow = NULL;
    void *osmenu = NULL;
    cassert_no_null(menu);
    oswindow = window_imp(window);
    osmenu = menu_imp(menu);
    osgui_set_menubar((OSMenu *)osmenu, (OSWindow *)oswindow);
}
