/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bsocket.h
 * https://nappgui.com/en/osbs/bsocket.html
 *
 */

/* Sockets base API */

#include "osbs.hxx"

__EXTERN_C

_osbs_api Socket *bsocket_connect(const uint32_t ip, const uint16_t port, const uint32_t timeout_ms, serror_t *error);

_osbs_api Socket *bsocket_server(const uint16_t port, const uint32_t max_connect, serror_t *error);

_osbs_api Socket *bsocket_accept(Socket *socket, const uint32_t timeout_ms, serror_t *error);

_osbs_api void bsocket_close(Socket **socket);

_osbs_api void bsocket_local_ip(Socket *socket, uint32_t *ip, uint16_t *port);

_osbs_api void bsocket_remote_ip(Socket *socket, uint32_t *ip, uint16_t *port);

_osbs_api void bsocket_read_timeout(Socket *socket, const uint32_t timeout_ms);

_osbs_api void bsocket_write_timeout(Socket *socket, const uint32_t timeout_ms);

_osbs_api bool_t bsocket_read(Socket *socket, byte_t *data, const uint32_t size, uint32_t *rsize, serror_t *error);

_osbs_api bool_t bsocket_write(Socket *socket, const byte_t *data, const uint32_t size, uint32_t *wsize, serror_t *error);

_osbs_api uint32_t bsocket_url_ip(const char_t *url, serror_t *error);

_osbs_api uint32_t bsocket_str_ip(const char_t *ip);

_osbs_api const char_t *bsocket_host_name(char_t *buffer, const uint32_t size);

_osbs_api const char_t *bsocket_host_name_ip(const uint32_t ip, char_t *buffer, const uint32_t size);

_osbs_api const char_t *bsocket_ip_str(const uint32_t ip);

_osbs_api void bsocket_hton2(byte_t *dest, const byte_t *src);

_osbs_api void bsocket_hton4(byte_t *dest, const byte_t *src);

_osbs_api void bsocket_hton8(byte_t *dest, const byte_t *src);

_osbs_api void bsocket_ntoh2(byte_t *dest, const byte_t *src);

_osbs_api void bsocket_ntoh4(byte_t *dest, const byte_t *src);

_osbs_api void bsocket_ntoh8(byte_t *dest, const byte_t *src);

__END_C
