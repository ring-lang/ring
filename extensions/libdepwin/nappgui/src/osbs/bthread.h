/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bthread.h
 * https://nappgui.com/en/osbs/bthread.html
 *
 */

/* Basic threading services */

#include "osbs.hxx"

__EXTERN_C

_osbs_api Thread *bthread_create_imp(FPtr_thread_main thmain, void *data);

_osbs_api int bthread_current_id(void);

_osbs_api void bthread_close(Thread **thread);

_osbs_api bool_t bthread_cancel(Thread *thread);

_osbs_api uint32_t bthread_wait(Thread *thread);

_osbs_api bool_t bthread_finish(Thread *thread, uint32_t *code);

_osbs_api void bthread_sleep(const uint32_t milliseconds);

__END_C

#define bthread_create(thmain, data, type) \
    ( \
        (void)(data == (type *)data), \
        FUNC_CHECK_THREAD_MAIN(thmain, type), \
        bthread_create_imp((FPtr_thread_main)thmain, (void *)data))
