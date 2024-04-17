/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp.inl
 *
 */

/* Application runloop */

#include "osapp.ixx"

__EXTERN_C

OSApp *osapp_init_imp(
    uint32_t argc,
    char_t **argv,
    void *instance,
    void *listener,
    const bool_t with_run_loop,
    FPtr_app_call func_OnFinishLaunching,
    FPtr_app_call func_OnTimerSignal);

void *osapp_init_pool(void);

void osapp_release_pool(void *pool);

void *osapp_listener_imp(void);

void osapp_terminate_imp(
    OSApp **app,
    const bool_t abnormal_termination,
    FPtr_destroy func_destroy,
    FPtr_app_void func_OnExecutionEnd);

uint32_t osapp_argc(OSApp *app);

void osapp_argv(OSApp *app, const uint32_t index, char_t *argv, const uint32_t max_size);

void osapp_run(OSApp *app);

void osapp_request_user_attention(OSApp *app);

void osapp_cancel_user_attention(OSApp *app);

void *osapp_begin_thread(OSApp *app);

void osapp_end_thread(OSApp *app, void *data);

void osapp_set_lang(OSApp *app, const char_t *lang);

void osapp_OnThemeChanged(OSApp *app, Listener *listener);

__END_C

#define osapp_init(argc, argv, instance, listener, with_run_loop, func_OnFinishLaunching, func_OnTimerSignal, type) \
    ( \
        (void)((type *)listener == listener), \
        FUNC_CHECK_APP_CALL(func_OnFinishLaunching, type), \
        FUNC_CHECK_APP_CALL(func_OnTimerSignal, type), \
        osapp_init_imp( \
            argc, argv, instance, \
            (void *)listener, \
            with_run_loop, \
            (FPtr_app_call)func_OnFinishLaunching, \
            (FPtr_app_call)func_OnTimerSignal))

#define osapp_terminate(app, abnormal_termination, func_destroy, func_OnExecutionEnd, type) \
    ( \
        FUNC_CHECK_DESTROY(func_destroy, type), \
        FUNC_CHECK_APP_VOID(func_OnExecutionEnd), \
        osapp_terminate_imp( \
            app, abnormal_termination, \
            (FPtr_destroy)func_destroy, \
            (FPtr_app_void)func_OnExecutionEnd))

#define osapp_listener(type) \
    (type *)osapp_listener_imp()
