/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: httpreq.h
 * https://nappgui.com/en/inet/httpreq.html
 *
 */

/* HTTP request */

#include "inet.hxx"

__EXTERN_C

_inet_api Http *http_create(const char_t *host, const uint16_t port);

_inet_api Http *http_secure(const char_t *host, const uint16_t port);

_inet_api void http_destroy(Http **http);

_inet_api void http_clear_headers(Http *http);

_inet_api void http_add_header(Http *http, const char_t *name, const char_t *value);

_inet_api bool_t http_get(Http *http, const char_t *path, const byte_t *data, const uint32_t size, ierror_t *error);

_inet_api bool_t http_post(Http *http, const char_t *path, const byte_t *data, const uint32_t size, ierror_t *error);

_inet_api uint32_t http_response_status(const Http *http);

_inet_api const char_t *http_response_protocol(const Http *http);

_inet_api const char_t *http_response_message(const Http *http);

_inet_api uint32_t http_response_size(const Http *http);

_inet_api const char_t *http_response_name(const Http *http, const uint32_t index);

_inet_api const char_t *http_response_value(const Http *http, const uint32_t index);

_inet_api const char_t *http_response_header(const Http *http, const char_t *name);

_inet_api bool_t http_response_body(const Http *http, Stream *body, ierror_t *error);

_inet_api Stream *http_dget(const char_t *url, uint32_t *result, ierror_t *error);

_inet_api bool_t http_exists(const char_t *url);

__END_C
