/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oshttpreq.inl
 *
 */

/* Secure HTTP request */

#include "inet.ixx"

__EXTERN_C

void oshttp_init(void);

void oshttp_finish(void);

OSHttp *oshttp_create(const char_t *host, const uint16_t port, const bool_t secure);

void oshttp_destroy(OSHttp **http);

void oshttp_clear_headers(OSHttp *http);

void oshttp_add_header(OSHttp *http, const char_t *name, const char_t *value);

void oshttp_get(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error);

void oshttp_post(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error);

Stream *oshttp_response(OSHttp *http);

void oshttp_response_body(OSHttp *http, Stream *body, ierror_t *error);

__END_C
