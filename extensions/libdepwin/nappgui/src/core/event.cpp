/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: event.cpp
 *
 */

/* Events */

#include "event.h"
#include "event.inl"
#include "heap.h"
#include "strings.h"
#include <sewer/cassert.h>

struct _event_t
{
    uint32_t type;
    void *sender;
    void *params;
    void *result;
#if defined(__ASSERTS__)
    const char_t *sender_type;
    const char_t *params_type;
    const char_t *result_type;
#endif
    /* http://lazarenko.me/wide-pointers/ */
    /* https://social.msdn.microsoft.com/Forums/vstudio/en-US/2793a64f-ec09-495c-b995-4f5b98a26321/vc-wrong-pointer-size-?forum=vcgeneral */
    /* On Apple pointer to member is double size than normal pointers */
    EventHandler member_event_handler;
};

struct _listener_t
{
    void *object;
    FPtr_release func_release;
    FPtr_event_handler func_event_handler;
    EventHandler member_event_handler;
    Event event;
};

/*---------------------------------------------------------------------------*/

static Listener *i_create_listener(void *object, FPtr_release func_release, FPtr_event_handler func_event_handler, EventHandler member_event_handler)
{
    Listener *listener = heap_new(Listener);
    listener->object = object;
    listener->func_release = func_release;
    listener->func_event_handler = func_event_handler;
    listener->member_event_handler = member_event_handler;
    return listener;
}

/*---------------------------------------------------------------------------*/

#define CALL_MEMBER_FN(object, ptrToMember) ((object)->*(ptrToMember))

static void i_cpp_func_event_handler(void *obj, Event *event)
{
    CALL_MEMBER_FN((IListener *)obj, event->member_event_handler)
    (event);
}

/*---------------------------------------------------------------------------*/

Listener *IListener::listen(IListener *object, void (IListener::*handler)(Event *))
{
    return i_create_listener((void *)object, PARAM(func_release, NULL), i_cpp_func_event_handler, handler);
}

/*---------------------------------------------------------------------------*/

Listener *listener_imp(void *object, FPtr_event_handler func_event_handler)
{
    cassert_no_nullf(func_event_handler);
    return i_create_listener(object, PARAM(func_release, NULL), func_event_handler, NULL);
}

/*---------------------------------------------------------------------------*/

void listener_destroy(Listener **listener)
{
    cassert_no_null(listener);
    if ((*listener) != NULL)
    {
        if ((*listener)->func_release != NULL)
            (*listener)->func_release(&(*listener)->object);
        heap_delete(listener, Listener);
    }
}

/*---------------------------------------------------------------------------*/

void listener_update(Listener **listener, Listener *new_listener)
{
    listener_destroy(listener);
    *listener = new_listener;
}

/*---------------------------------------------------------------------------*/

void _listener_retain(Listener *listener, FPtr_retain func_retain, FPtr_release func_release)
{
    cassert_no_null(listener);
    cassert_no_nullf(func_retain);
    cassert_no_nullf(func_release);
    cassert_no_null(listener->object);
    cassert(listener->func_release == NULL);
    func_retain(listener->object);
    listener->func_release = func_release;
}

/*---------------------------------------------------------------------------*/

void listener_event_imp(Listener *listener, const uint32_t type, void *sender, void *params, void *result, const char_t *sender_type, const char_t *params_type, const char_t *result_type)
{
    cassert_no_null(listener);
    cassert_no_nullf(listener->func_event_handler);
    listener->event.type = type;
    listener->event.sender = sender;
    listener->event.params = params;
    listener->event.result = result;
    listener->event.member_event_handler = listener->member_event_handler;
#if defined(__ASSERTS__)
    listener->event.sender_type = sender_type;
    listener->event.params_type = params_type;
    listener->event.result_type = result_type;
#else
    unref(sender_type);
    unref(params_type);
    unref(result_type);
#endif
    listener->func_event_handler(listener->object, &listener->event);
}

/*---------------------------------------------------------------------------*/

void listener_pass_event_imp(Listener *listener, Event *event, void *sender, const char_t *sender_type)
{
    void *previous_sender = NULL;
    EventHandler previous_member_event_handler = NULL;
#if defined(__ASSERTS__)
    const char_t *previous_sender_type = NULL;
#endif

    cassert_no_null(listener);
    cassert_no_nullf(listener->func_event_handler);
    cassert_no_null(event);
    previous_sender = event->sender;
    previous_member_event_handler = event->member_event_handler;
    event->sender = sender;
    event->member_event_handler = listener->member_event_handler;
#if defined(__ASSERTS__)
    previous_sender_type = event->sender_type;
    event->sender_type = sender_type;
#else
    unref(sender_type);
#endif

    listener->func_event_handler(listener->object, event);

    event->sender = previous_sender;
    event->member_event_handler = previous_member_event_handler;
#if defined(__ASSERTS__)
    event->sender_type = previous_sender_type;
#endif
}

/*---------------------------------------------------------------------------*/

uint32_t event_type(const Event *event)
{
    cassert_no_null(event);
    return event->type;
}

/*---------------------------------------------------------------------------*/

void *event_sender_imp(Event *event, const char_t *type)
{
    cassert_no_null(event);
#if defined(__ASSERTS__)
    if (type != NULL)
    {
        cassert(str_equ_c(type, event->sender_type) == TRUE);
    }
#else
    unref(type);
#endif
    return event->sender;
}

/*---------------------------------------------------------------------------*/

void *event_params_imp(Event *event, const char_t *type)
{
    cassert_no_null(event);
#if defined(__ASSERTS__)
    if (type != NULL)
    {
        cassert(str_equ_c(type, event->params_type) == TRUE);
    }
#else
    unref(type);
#endif
    return event->params;
}

/*---------------------------------------------------------------------------*/

void *event_result_imp(Event *event, const char_t *type)
{
    cassert_no_null(event);
#if defined(__ASSERTS__)
    if (type != NULL)
    {
        cassert(str_equ_c(type, event->result_type) == TRUE);
    }
#else
    unref(type);
#endif
    return event->result;
}

/*---------------------------------------------------------------------------*/

//void listener_init_imp(Listener *listener, void *object, FPtr_retain func_retain, FPtr_release func_release, FPtr_event_handler func_event_handler);
//void listener_init_imp(Listener *listener, void *object, FPtr_retain func_retain, FPtr_release func_release, FPtr_event_handler func_event_handler)
//{
//    cassert_no_nullf(func_event_handler);
//
//    if (object != NULL)
//    {
//        cassert_no_nullf(func_retain);
//        cassert_no_nullf(func_release);
//        object = func_retain(object);
//    }
//
//    i_init_listener(listener, object, func_retain, func_release, func_event_handler);
//}

/*---------------------------------------------------------------------------*/

//void listener_init_empty(Listener *listener);
//void listener_init_empty(Listener *listener)
//{
//    i_init_listener(listener, NULL, NULL, NULL, NULL);
//}

/*---------------------------------------------------------------------------*/

//void listener_remove(Listener *listener);
//void listener_remove(Listener *listener)
//{
//    cassert_no_null(listener);
//    cassert_no_null(listener->object);
//    cassert_no_nullf(listener->func_release);
//
//    if (__TRUE_EXPECTED(listener->func_release != NULL))
//    {
//        cassert_no_nullf(listener->func_retain);
//        listener->func_release(&listener->object);
//    }
//    else
//    {
//        cassert(listener->func_retain == NULL);
//    }
//
//    i_init_listener(listener, NULL, NULL, NULL, NULL);
//}

/*---------------------------------------------------------------------------*/

//void listener_destroy(Listener *listener);
//void listener_destroy(Listener *listener)
//{
//    cassert_no_null(listener);
//    if (listener->object != NULL)
//    {
//        if (__TRUE_EXPECTED(listener->func_release != NULL))
//        {
//            cassert_no_nullf(listener->func_retain);
//            listener->func_release(&listener->object);
//        }
//        else
//        {
//            cassert(listener->func_retain == NULL);
//        }
//    }
//
//    i_init_listener(listener, NULL, NULL, NULL, NULL);
//}

/*---------------------------------------------------------------------------*/

//void listener_event(Listener *listener, Event *event);
//void listener_event(Listener *listener, Event *event)
//{
//    cassert_no_null(listener);
//    cassert_no_nullf(listener->func_event_handler);
//    event->event_handler = listener->event_handler;
//    listener->func_event_handler(listener->object, event);
//}

/*---------------------------------------------------------------------------*/
