/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "httplib.h"
using namespace httplib;

extern "C" {
	#include "ring.h"
	RING_API void ringlib_init(RingState *pRingState);
	VM *pVMHTTPLib = NULL;
	char cHTTPLibRingCode[512];
}

RING_FUNC(ring_Server_listen)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->listen(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Server_listen_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->listen(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_Server_set_base_dir)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->set_base_dir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Server_set_base_dir_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->set_base_dir(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_Server_set_mount_point)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->set_mount_point(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_Server_set_mount_point_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->set_mount_point(RING_API_GETSTRING(2),RING_API_GETSTRING(3),* (Headers  *) RING_API_GETCPOINTER(4,"Headers")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Headers"));
}


RING_FUNC(ring_Server_remove_mount_point)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove_mount_point(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Server_set_file_extension_and_mimetype_mapping)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_file_extension_and_mimetype_mapping(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_Server_set_tcp_nodelay)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_tcp_nodelay( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_set_address_family)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_address_family( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_set_keep_alive_max_count)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_keep_alive_max_count( (size_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_set_keep_alive_timeout)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_keep_alive_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_read_timeout)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_read_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_read_timeout_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_read_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"),* (time_t  *) RING_API_GETCPOINTER(3,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"time_t"));
}


RING_FUNC(ring_Server_set_write_timeout)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_write_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_write_timeout_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_write_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"),* (time_t  *) RING_API_GETCPOINTER(3,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"time_t"));
}


RING_FUNC(ring_Server_set_idle_interval)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_idle_interval(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_idle_interval_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_idle_interval(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"),* (time_t  *) RING_API_GETCPOINTER(3,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"time_t"));
}


RING_FUNC(ring_Server_set_payload_max_length)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_payload_max_length( (size_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_bind_to_port)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind_to_port(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Server_bind_to_port_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind_to_port(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_Server_bind_to_any_port)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind_to_any_port(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Server_bind_to_any_port_2)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind_to_any_port(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Server_listen_after_bind)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	RING_API_RETNUMBER(pObject->listen_after_bind());
}


RING_FUNC(ring_Server_is_running)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	RING_API_RETNUMBER(pObject->is_running());
}


RING_FUNC(ring_Server_stop)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	pObject->stop();
}

RING_FUNC(ring_Server_wget)
{
	Server *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	if (pVMHTTPLib == NULL)
		pVMHTTPLib = (VM *) pPointer;

	strcpy(cHTTPLibRingCode,RING_API_GETSTRING(3));
	pObject->Get(RING_API_GETSTRING(2), [](const Request &, Response &res) {
		ring_vm_runcode(pVMHTTPLib, cHTTPLibRingCode);
	});
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

RING_FUNC(ring_Server_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Server *pObject = new Server();
	RING_API_RETCPOINTER(pObject,"Server");
}

RING_FUNC(ring_Server_delete)
{
	Server *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (Server *) RING_API_GETCPOINTER(1,"Server");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("server_listen",ring_Server_listen);
	ring_vm_funcregister("server_listen_2",ring_Server_listen_2);
	ring_vm_funcregister("server_set_base_dir",ring_Server_set_base_dir);
	ring_vm_funcregister("server_set_base_dir_2",ring_Server_set_base_dir_2);
	ring_vm_funcregister("server_set_mount_point",ring_Server_set_mount_point);
	ring_vm_funcregister("server_set_mount_point_2",ring_Server_set_mount_point_2);
	ring_vm_funcregister("server_remove_mount_point",ring_Server_remove_mount_point);
	ring_vm_funcregister("server_set_file_extension_and_mimetype_mapping",ring_Server_set_file_extension_and_mimetype_mapping);
	ring_vm_funcregister("server_set_tcp_nodelay",ring_Server_set_tcp_nodelay);
	ring_vm_funcregister("server_set_address_family",ring_Server_set_address_family);
	ring_vm_funcregister("server_set_keep_alive_max_count",ring_Server_set_keep_alive_max_count);
	ring_vm_funcregister("server_set_keep_alive_timeout",ring_Server_set_keep_alive_timeout);
	ring_vm_funcregister("server_set_read_timeout",ring_Server_set_read_timeout);
	ring_vm_funcregister("server_set_read_timeout_2",ring_Server_set_read_timeout_2);
	ring_vm_funcregister("server_set_write_timeout",ring_Server_set_write_timeout);
	ring_vm_funcregister("server_set_write_timeout_2",ring_Server_set_write_timeout_2);
	ring_vm_funcregister("server_set_idle_interval",ring_Server_set_idle_interval);
	ring_vm_funcregister("server_set_idle_interval_2",ring_Server_set_idle_interval_2);
	ring_vm_funcregister("server_set_payload_max_length",ring_Server_set_payload_max_length);
	ring_vm_funcregister("server_bind_to_port",ring_Server_bind_to_port);
	ring_vm_funcregister("server_bind_to_port_2",ring_Server_bind_to_port_2);
	ring_vm_funcregister("server_bind_to_any_port",ring_Server_bind_to_any_port);
	ring_vm_funcregister("server_bind_to_any_port_2",ring_Server_bind_to_any_port_2);
	ring_vm_funcregister("server_listen_after_bind",ring_Server_listen_after_bind);
	ring_vm_funcregister("server_is_running",ring_Server_is_running);
	ring_vm_funcregister("server_stop",ring_Server_stop);
	ring_vm_funcregister("server_wget",ring_Server_wget);
	ring_vm_funcregister("server_new",ring_Server_new);
	ring_vm_funcregister("server_delete",ring_Server_delete);
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
