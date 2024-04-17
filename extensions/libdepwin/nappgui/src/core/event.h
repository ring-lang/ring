/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: event.h
 * https://nappgui.com/en/core/event.html
 *
 */

/* Events */

#include "core.hxx"

__EXTERN_C

_core_api Listener *listener_imp(void *object, FPtr_event_handler func_event_handler);

_core_api void listener_destroy(Listener **listener);

_core_api void listener_update(Listener **listener, Listener *new_listener);

_core_api void listener_event_imp(Listener *listener, const uint32_t type, void *sender, void *params, void *result, const char_t *sender_type, const char_t *params_type, const char_t *result_type);

_core_api void listener_pass_event_imp(Listener *listener, Event *event, void *sender, const char_t *sender_type);

_core_api uint32_t event_type(const Event *event);

_core_api void *event_sender_imp(Event *event, const char_t *type);

_core_api void *event_params_imp(Event *event, const char_t *type);

_core_api void *event_result_imp(Event *event, const char_t *type);

__END_C

#define listener(object, func_event_handler, type) \
    ( \
        (void)((type *)object == object), \
        FUNC_CHECK_EVENT_HANDLER(func_event_handler, type), \
        listener_imp((void *)object, (FPtr_event_handler)func_event_handler))

#ifdef __cplusplus

#define IListen(object, type, func_event_handler) \
    ( \
        (void)((type *)object == object), \
        listen(static_cast<IListener *>(object), static_cast<EventHandler>(&type::func_event_handler)))

#endif

#define listener_event(listener, type, sender, params, result, sender_type, params_type, result_type) \
    ( \
        (void)((sender_type *)sender == sender), \
        (void)((params_type *)params == params), \
        (void)((result_type *)result == result), \
        listener_event_imp((listener), type, (void *)sender, (void *)params, (void *)result, (const char_t *)(#sender_type), (const char_t *)(#params_type), (const char_t *)(#result_type)))

#define listener_pass_event(listener, event, sender, sender_type) \
    ( \
        (void)((sender_type *)sender == sender), \
        listener_pass_event_imp((listener), (event), (void *)sender, (const char_t *)(#sender_type)))

#define event_sender(event, type) \
    (type *)event_sender_imp((event), (const char_t *)#type)

#define event_params(event, type) \
    ((type *)event_params_imp((event), (const char_t *)#type))

#define event_result(event, type) \
    (type *)event_result_imp((event), (const char_t *)#type)
