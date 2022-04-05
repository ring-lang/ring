/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "httplib.h"
using namespace httplib;

#include <mutex>

std::mutex ringhttplibmtx;

extern "C" {
	#include "ring.h"

	RING_API void ringlib_init(RingState *pRingState);
}

#include "ringhttplib.h"

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

RING_FUNC(ring_new_multipartformdata)
{
	MultipartFormData *pMyPointer ;
	pMyPointer = (MultipartFormData *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(MultipartFormData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"MultipartFormData");
}

RING_FUNC(ring_new_managed_multipartformdata)
{
	MultipartFormData *pMyPointer ;
	pMyPointer = (MultipartFormData *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(MultipartFormData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"MultipartFormData",ring_state_free);
}

RING_FUNC(ring_destroy_multipartformdata)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData*) RING_API_GETCPOINTER(1,"MultipartFormData");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_multipartformdata_name)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	RING_API_RETSTRING(pMyPointer->name.c_str());
}

RING_FUNC(ring_set_multipartformdata_name)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	pMyPointer->name = RING_API_GETSTRING(2);
}

RING_FUNC(ring_get_multipartformdata_content)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	RING_API_RETSTRING(pMyPointer->content.c_str());
}

RING_FUNC(ring_set_multipartformdata_content)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	pMyPointer->content = RING_API_GETSTRING(2);
}

RING_FUNC(ring_get_multipartformdata_filename)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	RING_API_RETSTRING(pMyPointer->filename.c_str());
}

RING_FUNC(ring_set_multipartformdata_filename)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	pMyPointer->filename = RING_API_GETSTRING(2);
}

RING_FUNC(ring_get_multipartformdata_content_type)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	RING_API_RETSTRING(pMyPointer->content_type.c_str());
}

RING_FUNC(ring_set_multipartformdata_content_type)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(1,"MultipartFormData");
	pMyPointer->content_type = RING_API_GETSTRING(2);
}


RING_FUNC(ring_HTTPLib_Server_listen)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_listen_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_set_base_dir)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->set_base_dir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Server_set_base_dir_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_set_mount_point)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_set_mount_point_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_remove_mount_point)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove_mount_point(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Server_set_file_extension_and_mimetype_mapping)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_set_tcp_nodelay)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_tcp_nodelay( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_address_family)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_address_family( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_keep_alive_max_count)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_keep_alive_max_count( (size_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_keep_alive_timeout)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_keep_alive_timeout( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_read_timeout)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_read_timeout( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_read_timeout_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_read_timeout( (time_t ) RING_API_GETNUMBER(2), (time_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Server_set_write_timeout)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_write_timeout( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_write_timeout_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_write_timeout( (time_t ) RING_API_GETNUMBER(2), (time_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Server_set_idle_interval)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_idle_interval( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_set_idle_interval_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_idle_interval( (time_t ) RING_API_GETNUMBER(2), (time_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Server_set_payload_max_length)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_payload_max_length( (size_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Server_bind_to_port)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_bind_to_port_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_bind_to_any_port)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind_to_any_port(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Server_bind_to_any_port_2)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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


RING_FUNC(ring_HTTPLib_Server_listen_after_bind)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	RING_API_RETNUMBER(pObject->listen_after_bind());
}


RING_FUNC(ring_HTTPLib_Server_is_running)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	RING_API_RETNUMBER(pObject->is_running());
}


RING_FUNC(ring_HTTPLib_Server_stop)
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
	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
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

RING_FUNC(ring_HTTPLib_Server_wget)
{
	RingServer *pObject ;
	VM *pVMHTTPLib;
	char cHTTPLibRingCode[RINGHTTPLIB_RINGCODESIZE];
	pVMHTTPLib = (VM *) pPointer;

	RING_API_IGNORECPOINTERTYPE ;

	if (ring_httplib_checkpara(pPointer)) return ;

	strcpy(cHTTPLibRingCode,RING_API_GETSTRING(3));

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	pObject->Get(RING_API_GETSTRING(2), [pObject,pVMHTTPLib,cHTTPLibRingCode](const Request &req, Response &res) {
		ringhttplibmtx.lock();
		pObject->oRequest = &req;
		pObject->oResponse = &res;
		ring_vm_runcode(pVMHTTPLib, (char *) cHTTPLibRingCode);
		ringhttplibmtx.unlock();
	});
}

RING_FUNC(ring_HTTPLib_Server_wpost)
{
	RingServer *pObject ;
	VM *pVMHTTPLib;
	char cHTTPLibRingCode[RINGHTTPLIB_RINGCODESIZE];
	pVMHTTPLib = (VM *) pPointer;

	RING_API_IGNORECPOINTERTYPE ;

	if (ring_httplib_checkpara(pPointer)) return ;

	strcpy(cHTTPLibRingCode,RING_API_GETSTRING(3));

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	pObject->Post(RING_API_GETSTRING(2), [pObject,pVMHTTPLib,cHTTPLibRingCode](const Request &req, Response &res) {
		ringhttplibmtx.lock();
		pObject->oRequest = &req;
		pObject->oResponse = &res;
		ring_vm_runcode(pVMHTTPLib, (char *) cHTTPLibRingCode);
		ringhttplibmtx.unlock();
	});
}


RING_FUNC(ring_HTTPLib_Server_response)
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

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	RING_API_RETCPOINTER(pObject->oResponse,"HTTPLib_Response");

}

RING_FUNC(ring_HTTPLib_Server_request)
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

	pObject = (RingServer *) RING_API_GETCPOINTER(1,"HTTPLib_Server");
	RING_API_RETCPOINTER(pObject->oRequest,"HTTPLib_Request");

}


RING_FUNC(ring_HTTPLib_Response_has_header)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_header(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Response_get_header_value)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_header_value(RING_API_GETSTRING(2)).c_str());
}


RING_FUNC(ring_HTTPLib_Response_get_header_value_2)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_header_value(RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)).c_str());
}


RING_FUNC(ring_HTTPLib_Response_get_header_value_count)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_header_value_count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Response_set_header)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
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


RING_FUNC(ring_HTTPLib_Response_set_redirect)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_redirect(RING_API_GETSTRING(2));
}


RING_FUNC(ring_HTTPLib_Response_set_redirect_2)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
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


RING_FUNC(ring_HTTPLib_Response_set_content)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
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


RING_FUNC(ring_HTTPLib_Response_set_content_2)
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
	pObject = (Response *) RING_API_GETCPOINTER(1,"HTTPLib_Response");
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


RING_FUNC(ring_HTTPLib_Request_has_header)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_header(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Request_get_header_value)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_header_value(RING_API_GETSTRING(2)).c_str());
}


RING_FUNC(ring_HTTPLib_Request_get_header_value_2)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_header_value(RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)).c_str());
}


RING_FUNC(ring_HTTPLib_Request_get_header_value_count)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_header_value_count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Request_set_header)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
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


RING_FUNC(ring_HTTPLib_Request_has_param)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_param(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Request_get_param_value)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_param_value(RING_API_GETSTRING(2)).c_str());
}


RING_FUNC(ring_HTTPLib_Request_get_param_value_2)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_param_value(RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)).c_str());
}


RING_FUNC(ring_HTTPLib_Request_get_param_value_count)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_param_value_count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Request_is_multipart_form_data)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	RING_API_RETNUMBER(pObject->is_multipart_form_data());
}


RING_FUNC(ring_HTTPLib_Request_has_file)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_file(RING_API_GETSTRING(2)));
}


void ring_MultipartFormData_free(void *pState,void *pValue)
{
	delete (MultipartFormData *) pValue;
}

RING_FUNC(ring_HTTPLib_Request_get_file_value)
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
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		MultipartFormData *pValue ;
		// Since MultipartFormData is a C++ structure
		// We use New/Delete instead of malloc()/free()
		pValue = new MultipartFormData;
		*pValue = pObject->get_file_value(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"MultipartFormData",ring_MultipartFormData_free);
	}
}

RING_FUNC(ring_HTTPLib_Request_get_multipartformdata_content2)
{
	MultipartFormData *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MultipartFormData *) RING_API_GETCPOINTER(2,"MultipartFormData");
	RING_API_RETSTRING2(pMyPointer->content.c_str(),pMyPointer->content.size());
}

RING_FUNC(ring_HTTPLib_Request_matches)
{
	Request *pObject ;
	int nIndex;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Request *) RING_API_GETCPOINTER(1,"HTTPLib_Request");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	nIndex = (int) RING_API_GETNUMBER(2);
	std::string cString = pObject->matches[nIndex];
	RING_API_RETSTRING(cString.c_str());
}



RING_FUNC(ring_HTTPLib_Client_download)
{
	Client *pObject ;

	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}

	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	RING_API_RETSTRING(pObject->Get(RING_API_GETSTRING(2))->body.c_str());
}


RING_FUNC(ring_HTTPLib_Client_is_valid)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	RING_API_RETNUMBER(pObject->is_valid());
}


RING_FUNC(ring_HTTPLib_Client_is_socket_open)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	RING_API_RETNUMBER(pObject->is_socket_open());
}


RING_FUNC(ring_HTTPLib_Client_stop)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	pObject->stop();
}


RING_FUNC(ring_HTTPLib_Client_set_address_family)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_address_family( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_tcp_nodelay)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_tcp_nodelay( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_connection_timeout)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_connection_timeout( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_connection_timeout_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_connection_timeout( (time_t ) RING_API_GETNUMBER(2), (time_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Client_set_read_timeout)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_read_timeout( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_read_timeout_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_read_timeout( (time_t ) RING_API_GETNUMBER(2), (time_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Client_set_write_timeout)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_write_timeout( (time_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_write_timeout_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_write_timeout( (time_t ) RING_API_GETNUMBER(2), (time_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Client_set_basic_auth)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_basic_auth(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_HTTPLib_Client_set_bearer_token_auth)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_bearer_token_auth(RING_API_GETSTRING(2));
}


RING_FUNC(ring_HTTPLib_Client_set_keep_alive)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_keep_alive( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_follow_location)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_follow_location( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_url_encode)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_url_encode( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_compress)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_compress( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_decompress)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_decompress( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_HTTPLib_Client_set_interface)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_interface(RING_API_GETSTRING(2));
}


RING_FUNC(ring_HTTPLib_Client_set_proxy)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_proxy(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_HTTPLib_Client_set_proxy_basic_auth)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_proxy_basic_auth(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_HTTPLib_Client_set_proxy_bearer_token_auth)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->set_proxy_bearer_token_auth(RING_API_GETSTRING(2));
}


RING_FUNC(ring_HTTPLib_Client_Head)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Head(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Post)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Post(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Post_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Post(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (size_t ) RING_API_GETNUMBER(4),RING_API_GETSTRING(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Patch)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Patch(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Patch_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Patch(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (size_t ) RING_API_GETNUMBER(4),RING_API_GETSTRING(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Delete_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Delete(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Delete_3)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Delete(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (size_t ) RING_API_GETNUMBER(4),RING_API_GETSTRING(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Options)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Options(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Client_Options_2)
{
	Client *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Client *) RING_API_GETCPOINTER(1,"HTTPLib_Client");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Result *pValue ; 
		pValue = (Result *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Result)) ;
		*pValue = pObject->Options(RING_API_GETSTRING(2),* (const Headers  *) RING_API_GETCPOINTER(3,"const Headers"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Headers"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Result",ring_state_free);
	}
}


RING_FUNC(ring_HTTPLib_Result_has_request_header)
{
	Result *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Result *) RING_API_GETCPOINTER(1,"HTTPLib_Result");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->has_request_header(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_HTTPLib_Result_get_request_header_value)
{
	Result *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Result *) RING_API_GETCPOINTER(1,"HTTPLib_Result");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_request_header_value(RING_API_GETSTRING(2)).c_str());
}


RING_FUNC(ring_HTTPLib_Result_get_request_header_value_2)
{
	Result *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Result *) RING_API_GETCPOINTER(1,"HTTPLib_Result");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->get_request_header_value(RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)).c_str());
}


RING_FUNC(ring_HTTPLib_Result_get_request_header_value_count)
{
	Result *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (Result *) RING_API_GETCPOINTER(1,"HTTPLib_Result");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->get_request_header_value_count(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_HTTPLib_Server_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RingServer *pObject = new RingServer();
	RING_API_RETCPOINTER(pObject,"HTTPLib_Server");
}

RING_FUNC(ring_HTTPLib_Response_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Response *pObject = new Response();
	RING_API_RETCPOINTER(pObject,"HTTPLib_Response");
}

RING_FUNC(ring_HTTPLib_Request_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Request *pObject = new Request();
	RING_API_RETCPOINTER(pObject,"HTTPLib_Request");
}

RING_FUNC(ring_HTTPLib_Client_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	Client *pObject = new Client(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"HTTPLib_Client");
}

RING_FUNC(ring_HTTPLib_Server_delete)
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

RING_FUNC(ring_HTTPLib_Response_delete)
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

RING_FUNC(ring_HTTPLib_Request_delete)
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

RING_FUNC(ring_HTTPLib_Client_delete)
{
	Client *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (Client *) RING_API_GETCPOINTER(1,"Client");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_API void ringlib_init(RingState *pRingState)
{
	RING_API_REGISTER("httplib_server_listen",ring_HTTPLib_Server_listen);
	RING_API_REGISTER("httplib_server_listen_2",ring_HTTPLib_Server_listen_2);
	RING_API_REGISTER("httplib_server_set_base_dir",ring_HTTPLib_Server_set_base_dir);
	RING_API_REGISTER("httplib_server_set_base_dir_2",ring_HTTPLib_Server_set_base_dir_2);
	RING_API_REGISTER("httplib_server_set_mount_point",ring_HTTPLib_Server_set_mount_point);
	RING_API_REGISTER("httplib_server_set_mount_point_2",ring_HTTPLib_Server_set_mount_point_2);
	RING_API_REGISTER("httplib_server_remove_mount_point",ring_HTTPLib_Server_remove_mount_point);
	RING_API_REGISTER("httplib_server_set_file_extension_and_mimetype_mapping",ring_HTTPLib_Server_set_file_extension_and_mimetype_mapping);
	RING_API_REGISTER("httplib_server_set_tcp_nodelay",ring_HTTPLib_Server_set_tcp_nodelay);
	RING_API_REGISTER("httplib_server_set_address_family",ring_HTTPLib_Server_set_address_family);
	RING_API_REGISTER("httplib_server_set_keep_alive_max_count",ring_HTTPLib_Server_set_keep_alive_max_count);
	RING_API_REGISTER("httplib_server_set_keep_alive_timeout",ring_HTTPLib_Server_set_keep_alive_timeout);
	RING_API_REGISTER("httplib_server_set_read_timeout",ring_HTTPLib_Server_set_read_timeout);
	RING_API_REGISTER("httplib_server_set_read_timeout_2",ring_HTTPLib_Server_set_read_timeout_2);
	RING_API_REGISTER("httplib_server_set_write_timeout",ring_HTTPLib_Server_set_write_timeout);
	RING_API_REGISTER("httplib_server_set_write_timeout_2",ring_HTTPLib_Server_set_write_timeout_2);
	RING_API_REGISTER("httplib_server_set_idle_interval",ring_HTTPLib_Server_set_idle_interval);
	RING_API_REGISTER("httplib_server_set_idle_interval_2",ring_HTTPLib_Server_set_idle_interval_2);
	RING_API_REGISTER("httplib_server_set_payload_max_length",ring_HTTPLib_Server_set_payload_max_length);
	RING_API_REGISTER("httplib_server_bind_to_port",ring_HTTPLib_Server_bind_to_port);
	RING_API_REGISTER("httplib_server_bind_to_port_2",ring_HTTPLib_Server_bind_to_port_2);
	RING_API_REGISTER("httplib_server_bind_to_any_port",ring_HTTPLib_Server_bind_to_any_port);
	RING_API_REGISTER("httplib_server_bind_to_any_port_2",ring_HTTPLib_Server_bind_to_any_port_2);
	RING_API_REGISTER("httplib_server_listen_after_bind",ring_HTTPLib_Server_listen_after_bind);
	RING_API_REGISTER("httplib_server_is_running",ring_HTTPLib_Server_is_running);
	RING_API_REGISTER("httplib_server_stop",ring_HTTPLib_Server_stop);
	RING_API_REGISTER("httplib_server_wget",ring_HTTPLib_Server_wget);
	RING_API_REGISTER("httplib_server_wpost",ring_HTTPLib_Server_wpost);
	RING_API_REGISTER("httplib_server_response",ring_HTTPLib_Server_response);
	RING_API_REGISTER("httplib_server_request",ring_HTTPLib_Server_request);
	RING_API_REGISTER("httplib_response_has_header",ring_HTTPLib_Response_has_header);
	RING_API_REGISTER("httplib_response_get_header_value",ring_HTTPLib_Response_get_header_value);
	RING_API_REGISTER("httplib_response_get_header_value_2",ring_HTTPLib_Response_get_header_value_2);
	RING_API_REGISTER("httplib_response_get_header_value_count",ring_HTTPLib_Response_get_header_value_count);
	RING_API_REGISTER("httplib_response_set_header",ring_HTTPLib_Response_set_header);
	RING_API_REGISTER("httplib_response_set_redirect",ring_HTTPLib_Response_set_redirect);
	RING_API_REGISTER("httplib_response_set_redirect_2",ring_HTTPLib_Response_set_redirect_2);
	RING_API_REGISTER("httplib_response_set_content",ring_HTTPLib_Response_set_content);
	RING_API_REGISTER("httplib_response_set_content_2",ring_HTTPLib_Response_set_content_2);
	RING_API_REGISTER("httplib_request_has_header",ring_HTTPLib_Request_has_header);
	RING_API_REGISTER("httplib_request_get_header_value",ring_HTTPLib_Request_get_header_value);
	RING_API_REGISTER("httplib_request_get_header_value_2",ring_HTTPLib_Request_get_header_value_2);
	RING_API_REGISTER("httplib_request_get_header_value_count",ring_HTTPLib_Request_get_header_value_count);
	RING_API_REGISTER("httplib_request_set_header",ring_HTTPLib_Request_set_header);
	RING_API_REGISTER("httplib_request_has_param",ring_HTTPLib_Request_has_param);
	RING_API_REGISTER("httplib_request_get_param_value",ring_HTTPLib_Request_get_param_value);
	RING_API_REGISTER("httplib_request_get_param_value_2",ring_HTTPLib_Request_get_param_value_2);
	RING_API_REGISTER("httplib_request_get_param_value_count",ring_HTTPLib_Request_get_param_value_count);
	RING_API_REGISTER("httplib_request_is_multipart_form_data",ring_HTTPLib_Request_is_multipart_form_data);
	RING_API_REGISTER("httplib_request_has_file",ring_HTTPLib_Request_has_file);
	RING_API_REGISTER("httplib_request_get_file_value",ring_HTTPLib_Request_get_file_value);
	RING_API_REGISTER("httplib_request_get_multipartformdata_content2",ring_HTTPLib_Request_get_multipartformdata_content2);
	RING_API_REGISTER("httplib_request_matches",ring_HTTPLib_Request_matches);
	RING_API_REGISTER("httplib_client_download",ring_HTTPLib_Client_download);
	RING_API_REGISTER("httplib_client_is_valid",ring_HTTPLib_Client_is_valid);
	RING_API_REGISTER("httplib_client_is_socket_open",ring_HTTPLib_Client_is_socket_open);
	RING_API_REGISTER("httplib_client_stop",ring_HTTPLib_Client_stop);
	RING_API_REGISTER("httplib_client_set_address_family",ring_HTTPLib_Client_set_address_family);
	RING_API_REGISTER("httplib_client_set_tcp_nodelay",ring_HTTPLib_Client_set_tcp_nodelay);
	RING_API_REGISTER("httplib_client_set_connection_timeout",ring_HTTPLib_Client_set_connection_timeout);
	RING_API_REGISTER("httplib_client_set_connection_timeout_2",ring_HTTPLib_Client_set_connection_timeout_2);
	RING_API_REGISTER("httplib_client_set_read_timeout",ring_HTTPLib_Client_set_read_timeout);
	RING_API_REGISTER("httplib_client_set_read_timeout_2",ring_HTTPLib_Client_set_read_timeout_2);
	RING_API_REGISTER("httplib_client_set_write_timeout",ring_HTTPLib_Client_set_write_timeout);
	RING_API_REGISTER("httplib_client_set_write_timeout_2",ring_HTTPLib_Client_set_write_timeout_2);
	RING_API_REGISTER("httplib_client_set_basic_auth",ring_HTTPLib_Client_set_basic_auth);
	RING_API_REGISTER("httplib_client_set_bearer_token_auth",ring_HTTPLib_Client_set_bearer_token_auth);
	RING_API_REGISTER("httplib_client_set_keep_alive",ring_HTTPLib_Client_set_keep_alive);
	RING_API_REGISTER("httplib_client_set_follow_location",ring_HTTPLib_Client_set_follow_location);
	RING_API_REGISTER("httplib_client_set_url_encode",ring_HTTPLib_Client_set_url_encode);
	RING_API_REGISTER("httplib_client_set_compress",ring_HTTPLib_Client_set_compress);
	RING_API_REGISTER("httplib_client_set_decompress",ring_HTTPLib_Client_set_decompress);
	RING_API_REGISTER("httplib_client_set_interface",ring_HTTPLib_Client_set_interface);
	RING_API_REGISTER("httplib_client_set_proxy",ring_HTTPLib_Client_set_proxy);
	RING_API_REGISTER("httplib_client_set_proxy_basic_auth",ring_HTTPLib_Client_set_proxy_basic_auth);
	RING_API_REGISTER("httplib_client_set_proxy_bearer_token_auth",ring_HTTPLib_Client_set_proxy_bearer_token_auth);
	RING_API_REGISTER("httplib_client_head",ring_HTTPLib_Client_Head);
	RING_API_REGISTER("httplib_client_post",ring_HTTPLib_Client_Post);
	RING_API_REGISTER("httplib_client_post_2",ring_HTTPLib_Client_Post_2);
	RING_API_REGISTER("httplib_client_patch",ring_HTTPLib_Client_Patch);
	RING_API_REGISTER("httplib_client_patch_2",ring_HTTPLib_Client_Patch_2);
	RING_API_REGISTER("httplib_client_delete_2",ring_HTTPLib_Client_Delete_2);
	RING_API_REGISTER("httplib_client_delete_3",ring_HTTPLib_Client_Delete_3);
	RING_API_REGISTER("httplib_client_options",ring_HTTPLib_Client_Options);
	RING_API_REGISTER("httplib_client_options_2",ring_HTTPLib_Client_Options_2);
	RING_API_REGISTER("httplib_result_has_request_header",ring_HTTPLib_Result_has_request_header);
	RING_API_REGISTER("httplib_result_get_request_header_value",ring_HTTPLib_Result_get_request_header_value);
	RING_API_REGISTER("httplib_result_get_request_header_value_2",ring_HTTPLib_Result_get_request_header_value_2);
	RING_API_REGISTER("httplib_result_get_request_header_value_count",ring_HTTPLib_Result_get_request_header_value_count);
	RING_API_REGISTER("httplib_server_new",ring_HTTPLib_Server_new);
	RING_API_REGISTER("httplib_response_new",ring_HTTPLib_Response_new);
	RING_API_REGISTER("httplib_request_new",ring_HTTPLib_Request_new);
	RING_API_REGISTER("httplib_client_new",ring_HTTPLib_Client_new);
	RING_API_REGISTER("httplib_server_delete",ring_HTTPLib_Server_delete);
	RING_API_REGISTER("httplib_response_delete",ring_HTTPLib_Response_delete);
	RING_API_REGISTER("httplib_request_delete",ring_HTTPLib_Request_delete);
	RING_API_REGISTER("httplib_client_delete",ring_HTTPLib_Client_delete);
	RING_API_REGISTER("get_cpphttplib_keepalive_timeout_second",ring_get_cpphttplib_keepalive_timeout_second);
	RING_API_REGISTER("get_cpphttplib_keepalive_max_count",ring_get_cpphttplib_keepalive_max_count);
	RING_API_REGISTER("get_cpphttplib_connection_timeout_second",ring_get_cpphttplib_connection_timeout_second);
	RING_API_REGISTER("get_cpphttplib_connection_timeout_usecond",ring_get_cpphttplib_connection_timeout_usecond);
	RING_API_REGISTER("get_cpphttplib_read_timeout_second",ring_get_cpphttplib_read_timeout_second);
	RING_API_REGISTER("get_cpphttplib_read_timeout_usecond",ring_get_cpphttplib_read_timeout_usecond);
	RING_API_REGISTER("get_cpphttplib_write_timeout_second",ring_get_cpphttplib_write_timeout_second);
	RING_API_REGISTER("get_cpphttplib_write_timeout_usecond",ring_get_cpphttplib_write_timeout_usecond);
	RING_API_REGISTER("get_cpphttplib_idle_interval_second",ring_get_cpphttplib_idle_interval_second);
	RING_API_REGISTER("get_cpphttplib_idle_interval_usecond",ring_get_cpphttplib_idle_interval_usecond);
	RING_API_REGISTER("get_cpphttplib_request_uri_max_length",ring_get_cpphttplib_request_uri_max_length);
	RING_API_REGISTER("get_cpphttplib_redirect_max_count",ring_get_cpphttplib_redirect_max_count);
	RING_API_REGISTER("get_cpphttplib_payload_max_length",ring_get_cpphttplib_payload_max_length);
	RING_API_REGISTER("get_cpphttplib_tcp_nodelay",ring_get_cpphttplib_tcp_nodelay);
	RING_API_REGISTER("get_cpphttplib_compression_bufsiz",ring_get_cpphttplib_compression_bufsiz);
	RING_API_REGISTER("get_cpphttplib_thread_pool_count",ring_get_cpphttplib_thread_pool_count);
	RING_API_REGISTER("get_cpphttplib_recv_flags",ring_get_cpphttplib_recv_flags);
	RING_API_REGISTER("get_cpphttplib_listen_backlog",ring_get_cpphttplib_listen_backlog);
	RING_API_REGISTER("new_multipartformdata",ring_new_multipartformdata);
	RING_API_REGISTER("new_managed_multipartformdata",ring_new_managed_multipartformdata);
	RING_API_REGISTER("destroy_multipartformdata",ring_destroy_multipartformdata);
	RING_API_REGISTER("get_multipartformdata_name",ring_get_multipartformdata_name);
	RING_API_REGISTER("set_multipartformdata_name",ring_set_multipartformdata_name);
	RING_API_REGISTER("get_multipartformdata_content",ring_get_multipartformdata_content);
	RING_API_REGISTER("set_multipartformdata_content",ring_set_multipartformdata_content);
	RING_API_REGISTER("get_multipartformdata_filename",ring_get_multipartformdata_filename);
	RING_API_REGISTER("set_multipartformdata_filename",ring_set_multipartformdata_filename);
	RING_API_REGISTER("get_multipartformdata_content_type",ring_get_multipartformdata_content_type);
	RING_API_REGISTER("set_multipartformdata_content_type",ring_set_multipartformdata_content_type);
}
