/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "httplib.h"
using namespace httplib;

#include <mutex>

std::mutex ringhttplibmtx;

extern "C" {
	#include "ring.h"
	RING_API void ringlib_init(RingState *pRingState);
}

#define RINGHTTPLIB_RINGCODESIZE 512
#define RINGHTTPLIB_MAXRINGCODE  511
#define RINGHTTPLIB_ERRORINCODESIZE "The string that contains Ring code is larger than expected (Max. size = 511)"

class RingServer: public Server {
	public:
	const Request *oRequest;
	const Response *oResponse;
};


RING_FUNC(ring_Server_listen)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->set_base_dir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Server_set_base_dir_2)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove_mount_point(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Server_set_file_extension_and_mimetype_mapping)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_tcp_nodelay( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_set_address_family)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_address_family( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_set_keep_alive_max_count)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_keep_alive_max_count( (size_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_set_keep_alive_timeout)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_keep_alive_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_read_timeout)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_read_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_read_timeout_2)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_read_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"),* (time_t  *) RING_API_GETCPOINTER(3,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"time_t"));
}


RING_FUNC(ring_Server_set_write_timeout)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_write_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_write_timeout_2)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_write_timeout(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"),* (time_t  *) RING_API_GETCPOINTER(3,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"time_t"));
}


RING_FUNC(ring_Server_set_idle_interval)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_idle_interval(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
}


RING_FUNC(ring_Server_set_idle_interval_2)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->set_idle_interval(* (time_t  *) RING_API_GETCPOINTER(2,"time_t"),* (time_t  *) RING_API_GETCPOINTER(3,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"time_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"time_t"));
}


RING_FUNC(ring_Server_set_payload_max_length)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_payload_max_length( (size_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_Server_bind_to_port)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind_to_any_port(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Server_bind_to_any_port_2)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
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
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	RING_API_RETNUMBER(pObject->listen_after_bind());
}


RING_FUNC(ring_Server_is_running)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	RING_API_RETNUMBER(pObject->is_running());
}


RING_FUNC(ring_Server_stop)
{
	RingServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->stop();
}


int ring_httplib_checkpara(void *pPointer)
{

	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return 1;
	}

	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return 1;
	}

	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return 1;
	}

	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return 1;
	}

	// Check Ring Code size
	if ( strlen(RING_API_GETSTRING(3)) > RINGHTTPLIB_MAXRINGCODE ) {
		RING_API_ERROR(RINGHTTPLIB_ERRORINCODESIZE);
		return 1;
	}

	return 0;
}

RING_FUNC(ring_Server_wget)
{
	RingServer *pObject ;
	VM *pVMHTTPLib;
	char cHTTPLibRingCode[RINGHTTPLIB_RINGCODESIZE];
	pVMHTTPLib = (VM *) pPointer;

	RING_API_IGNORECPOINTERTYPE ;

	if (ring_httplib_checkpara(pPointer)) return ;

	strcpy(cHTTPLibRingCode,RING_API_GETSTRING(3));

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	pObject->Get(RING_API_GETSTRING(2), [pObject,pVMHTTPLib,cHTTPLibRingCode](const Request &req, Response &res) {
		ringhttplibmtx.lock();
		pObject->oRequest = &req;
		pObject->oResponse = &res;
		ring_vm_runcode(pVMHTTPLib, cHTTPLibRingCode);
		ringhttplibmtx.unlock();
	});
}

RING_FUNC(ring_Server_response)
{
	RingServer *pObject ;

	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}

	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	RING_API_RETCPOINTER(pObject->oResponse,"response");

}

RING_FUNC(ring_Server_request)
{
	RingServer *pObject ;

	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}

	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"Server");
	RING_API_RETCPOINTER(pObject->oRequest,"request");

}


RING_FUNC(ring_Response_set_content)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_content(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_Response_set_content_2)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_content(RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_Response_set_redirect)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_redirect(RING_API_GETSTRING(2));
}


RING_FUNC(ring_Response_set_redirect_2)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_redirect(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_Response_set_header)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_header(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_Response_get_header_value_count)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_header_value_count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Response_has_header)
{
	Response *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_header(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Request_has_header)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_header(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Request_get_header_value_count)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_header_value_count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Request_set_header)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_header(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_Request_has_param)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_param(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Request_get_param_value_count)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_param_value_count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Request_is_multipart_form_data)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	RING_API_RETNUMBER(pObject->is_multipart_form_data());
}


RING_FUNC(ring_Request_has_file)
{
	Request *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_file(RING_API_GETSTRING(2)));
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
	RingServer *pObject = new RingServer();
	RING_API_RETCPOINTER(pObject,"Server");
}

RING_FUNC(ring_Response_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Response *pObject = new Response();
	RING_API_RETCPOINTER(pObject,"Response");
}

RING_FUNC(ring_Request_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Request *pObject = new Request();
	RING_API_RETCPOINTER(pObject,"Request");
}

RING_FUNC(ring_Server_delete)
{
	RingServer *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (RingServer *) RING_API_GETCPOINTER(1,"RingServer");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_Response_delete)
{
	Response *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (Response *) RING_API_GETCPOINTER(1,"Response");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_Request_delete)
{
	Request *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (Request *) RING_API_GETCPOINTER(1,"Request");
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
	ring_vm_funcregister("server_response",ring_Server_response);
	ring_vm_funcregister("server_request",ring_Server_request);
	ring_vm_funcregister("response_set_content",ring_Response_set_content);
	ring_vm_funcregister("response_set_content_2",ring_Response_set_content_2);
	ring_vm_funcregister("response_set_redirect",ring_Response_set_redirect);
	ring_vm_funcregister("response_set_redirect_2",ring_Response_set_redirect_2);
	ring_vm_funcregister("response_set_header",ring_Response_set_header);
	ring_vm_funcregister("response_get_header_value_count",ring_Response_get_header_value_count);
	ring_vm_funcregister("response_has_header",ring_Response_has_header);
	ring_vm_funcregister("request_has_header",ring_Request_has_header);
	ring_vm_funcregister("request_get_header_value_count",ring_Request_get_header_value_count);
	ring_vm_funcregister("request_set_header",ring_Request_set_header);
	ring_vm_funcregister("request_has_param",ring_Request_has_param);
	ring_vm_funcregister("request_get_param_value_count",ring_Request_get_param_value_count);
	ring_vm_funcregister("request_is_multipart_form_data",ring_Request_is_multipart_form_data);
	ring_vm_funcregister("request_has_file",ring_Request_has_file);
	ring_vm_funcregister("server_new",ring_Server_new);
	ring_vm_funcregister("response_new",ring_Response_new);
	ring_vm_funcregister("request_new",ring_Request_new);
	ring_vm_funcregister("server_delete",ring_Server_delete);
	ring_vm_funcregister("response_delete",ring_Response_delete);
	ring_vm_funcregister("request_delete",ring_Request_delete);
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
