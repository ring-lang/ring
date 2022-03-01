/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "httplib.h"
using namespace httplib;

extern "C" {
	#include "ring.h"
	RING_API void ringlib_init(RingState *pRingState);
}
RING_FUNC(ring_get_cpphttplib_keepalive_timeout_second)
{
	RING_API_RETNUMBER(CPPHTTPLIB_KEEPALIVE_TIMEOUT_SECOND);
}

RING_FUNC(ring_get_cpphttplib_keepalive_max_count)
{
	RING_API_RETNUMBER(CPPHTTPLIB_KEEPALIVE_MAX_COUNT);
}

RING_FUNC(ring_get_cpphttplib_connection_timeout_second)
{
	RING_API_RETNUMBER(CPPHTTPLIB_CONNECTION_TIMEOUT_SECOND);
}

RING_FUNC(ring_get_cpphttplib_connection_timeout_usecond)
{
	RING_API_RETNUMBER(CPPHTTPLIB_CONNECTION_TIMEOUT_USECOND);
}

RING_FUNC(ring_get_cpphttplib_read_timeout_second)
{
	RING_API_RETNUMBER(CPPHTTPLIB_READ_TIMEOUT_SECOND);
}

RING_FUNC(ring_get_cpphttplib_read_timeout_usecond)
{
	RING_API_RETNUMBER(CPPHTTPLIB_READ_TIMEOUT_USECOND);
}

RING_FUNC(ring_get_cpphttplib_write_timeout_second)
{
	RING_API_RETNUMBER(CPPHTTPLIB_WRITE_TIMEOUT_SECOND);
}

RING_FUNC(ring_get_cpphttplib_write_timeout_usecond)
{
	RING_API_RETNUMBER(CPPHTTPLIB_WRITE_TIMEOUT_USECOND);
}

RING_FUNC(ring_get_cpphttplib_idle_interval_second)
{
	RING_API_RETNUMBER(CPPHTTPLIB_IDLE_INTERVAL_SECOND);
}

RING_FUNC(ring_get_cpphttplib_idle_interval_usecond)
{
	RING_API_RETNUMBER(CPPHTTPLIB_IDLE_INTERVAL_USECOND);
}

RING_FUNC(ring_get_cpphttplib_request_uri_max_length)
{
	RING_API_RETNUMBER(CPPHTTPLIB_REQUEST_URI_MAX_LENGTH);
}

RING_FUNC(ring_get_cpphttplib_redirect_max_count)
{
	RING_API_RETNUMBER(CPPHTTPLIB_REDIRECT_MAX_COUNT);
}

RING_FUNC(ring_get_cpphttplib_payload_max_length)
{
	RING_API_RETNUMBER(CPPHTTPLIB_PAYLOAD_MAX_LENGTH);
}

RING_FUNC(ring_get_cpphttplib_tcp_nodelay)
{
	RING_API_RETNUMBER(CPPHTTPLIB_TCP_NODELAY);
}

RING_FUNC(ring_get_cpphttplib_compression_bufsiz)
{
	RING_API_RETNUMBER(CPPHTTPLIB_COMPRESSION_BUFSIZ);
}

RING_FUNC(ring_get_cpphttplib_thread_pool_count)
{
	RING_API_RETNUMBER(CPPHTTPLIB_THREAD_POOL_COUNT);
}

RING_FUNC(ring_get_cpphttplib_recv_flags)
{
	RING_API_RETNUMBER(CPPHTTPLIB_RECV_FLAGS);
}

RING_FUNC(ring_get_cpphttplib_listen_backlog)
{
	RING_API_RETNUMBER(CPPHTTPLIB_LISTEN_BACKLOG);
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("get_cpphttplib_keepalive_timeout_second",ring_get_cpphttplib_keepalive_timeout_second);
	ring_vm_funcregister("get_cpphttplib_keepalive_max_count",ring_get_cpphttplib_keepalive_max_count);
	ring_vm_funcregister("get_cpphttplib_connection_timeout_second",ring_get_cpphttplib_connection_timeout_second);
	ring_vm_funcregister("get_cpphttplib_connection_timeout_usecond",ring_get_cpphttplib_connection_timeout_usecond);
	ring_vm_funcregister("get_cpphttplib_read_timeout_second",ring_get_cpphttplib_read_timeout_second);
	ring_vm_funcregister("get_cpphttplib_read_timeout_usecond",ring_get_cpphttplib_read_timeout_usecond);
	ring_vm_funcregister("get_cpphttplib_write_timeout_second",ring_get_cpphttplib_write_timeout_second);
	ring_vm_funcregister("get_cpphttplib_write_timeout_usecond",ring_get_cpphttplib_write_timeout_usecond);
	ring_vm_funcregister("get_cpphttplib_idle_interval_second",ring_get_cpphttplib_idle_interval_second);
	ring_vm_funcregister("get_cpphttplib_idle_interval_usecond",ring_get_cpphttplib_idle_interval_usecond);
	ring_vm_funcregister("get_cpphttplib_request_uri_max_length",ring_get_cpphttplib_request_uri_max_length);
	ring_vm_funcregister("get_cpphttplib_redirect_max_count",ring_get_cpphttplib_redirect_max_count);
	ring_vm_funcregister("get_cpphttplib_payload_max_length",ring_get_cpphttplib_payload_max_length);
	ring_vm_funcregister("get_cpphttplib_tcp_nodelay",ring_get_cpphttplib_tcp_nodelay);
	ring_vm_funcregister("get_cpphttplib_compression_bufsiz",ring_get_cpphttplib_compression_bufsiz);
	ring_vm_funcregister("get_cpphttplib_thread_pool_count",ring_get_cpphttplib_thread_pool_count);
	ring_vm_funcregister("get_cpphttplib_recv_flags",ring_get_cpphttplib_recv_flags);
	ring_vm_funcregister("get_cpphttplib_listen_backlog",ring_get_cpphttplib_listen_backlog);
}
