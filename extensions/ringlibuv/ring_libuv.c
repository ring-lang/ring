/* Copyright (c) 2018-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#include <uv.h>
#include <ring.h>

typedef struct sockaddr_in sockaddr_in ;
typedef struct sockaddr_in6 sockaddr_in6 ;
typedef struct sockaddr sockaddr ;

List *aCallBack = NULL;
VM *pVMLibUV = NULL;

uv_mutex_t *pMutexLibUV;

#define RINGLIBUV_EVENTPARA  4

RING_API void ring_libuv_start(RingState *pRingState);

void *uv_new_mutex(void);

RING_API void ringlib_init(RingState *pRingState)
{
	pVMLibUV = pRingState->pVM;
	ring_vm_mutexfunctions(pVMLibUV,uv_new_mutex,
uv_mutex_lock,uv_mutex_unlock,uv_mutex_destroy);
	ring_libuv_start(pRingState) ;
}



int uv_checkevent_callback(void *pObject,const char *cEvent)
{
	List *pList;
	int x,t;
	x=0;
	ring_vm_mutexlock(pVMLibUV);
	for(t = 1 ; t <= ring_list_getsize(aCallBack) ; t++)
	{
		pList = ring_list_getlist(aCallBack,t) ;
		if ( ( ring_list_getpointer(pList,1) == pObject ) &&
		     ( strcmp(ring_list_getstring(pList,2) , cEvent) == 0 ) )
		{
			x=t;
			break;
		}
	}
	ring_vm_mutexunlock(pVMLibUV);
	return x;
}

void uv_timer_callback(uv_timer_t *handle)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"timer");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_timer_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));

}

void uv_prepare_callback(uv_prepare_t *handle)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"prepare");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_prepare_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_check_callback(uv_check_t *handle)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"check");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_check_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_idle_callback(uv_idle_t *obj)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"idle");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"uv_idle_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_poll_callback(uv_poll_t *obj,int status,int events)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"poll");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"uv_poll_t");
		ring_list_adddouble_gc(NULL,pPara,status);
		ring_list_adddouble_gc(NULL,pPara,events);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_signal_callback(uv_signal_t *obj,int signum)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"signal");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"uv_signal_t");
		ring_list_adddouble_gc(NULL,pPara,signum);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_shutdown_callback(uv_shutdown_t *obj,int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"shutdown");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"uv_shutdown_t");
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
	uv_close((uv_handle_t*) obj->handle, (uv_close_cb) free);
}

void uv_connection_callback(uv_stream_t *obj,int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"connection");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"uv_stream_t");
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_write_callback(uv_write_t *obj,int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"write");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"uv_write_t");
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_connect_callback(uv_connect_t *req, int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"connect");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_connect_t");
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_fs_event_callback(uv_fs_event_t *req, const char* filename, int events, int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"fs_event");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_fs_event_t");
		ring_list_addstring_gc(NULL,pPara,filename);
		ring_list_adddouble_gc(NULL,pPara,events);
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_fs_callback(uv_fs_t *req)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"fs");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_fs_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void *uv_new_mutex(void)
{
	if (pMutexLibUV == NULL)
	{
		pMutexLibUV = (uv_mutex_t *) malloc(sizeof(uv_mutex_t));
		uv_mutex_init(pMutexLibUV);
	}
	return pMutexLibUV;
}

void uv_thread_callback(void *obj)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(obj,"thread");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,obj,"void");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcodefromthread(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_walk_callback(uv_handle_t *handle, void *arg)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"walk");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_handle_t");
		ring_list_addcpointer_gc(NULL,pPara,arg,"void");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_close_callback(uv_handle_t *handle)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"close");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_handle_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_async_callback(uv_async_t *handle)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"async");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_async_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_alloc_callback(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"alloc");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_handle_t");
		ring_list_adddouble_gc(NULL,pPara,suggested_size);
		ring_list_addcpointer_gc(NULL,pPara,buf,"uv_buf_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_read_callback(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(stream,"read");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,stream,"uv_stream_t");
		ring_list_adddouble_gc(NULL,pPara,nread);
		ring_list_addcpointer_gc(NULL,pPara,(uv_buf_t *) buf,"uv_buf_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_udp_send_callback(uv_udp_send_t* req, int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"udp_send");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_udp_send_t");
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_udp_recv_callback(uv_udp_t* handle, ssize_t nread, const uv_buf_t* buf, const struct sockaddr* addr, unsigned flags)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"udp_recv");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_udp_t");
		ring_list_adddouble_gc(NULL,pPara,nread);
		ring_list_addcpointer_gc(NULL,pPara,(uv_buf_t *) buf,"uv_buf_t");
		ring_list_addcpointer_gc(NULL,pPara,(struct sockaddr *) addr,"sockaddr");
		ring_list_adddouble_gc(NULL,pPara,flags);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_fs_poll_callback(uv_fs_poll_t* handle, int status, const uv_stat_t* prev, const uv_stat_t* curr)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(handle,"fs_poll");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,handle,"uv_fs_poll_t");
		ring_list_adddouble_gc(NULL,pPara,status);
		ring_list_addcpointer_gc(NULL,pPara,(uv_stat_t *) prev,"uv_stat_t");
		ring_list_addcpointer_gc(NULL,pPara,(uv_stat_t *) curr,"uv_stat_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_work_callback(uv_work_t* req)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"work");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_work_t");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_after_work_callback(uv_work_t* req, int status)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"after_work");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_work_t");
		ring_list_adddouble_gc(NULL,pPara,status);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_getaddrinfo_callback(uv_getaddrinfo_t* req, int status, struct addrinfo* res)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"getaddrinfo");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_getaddrinfo_t");
		ring_list_adddouble_gc(NULL,pPara,status);
		ring_list_addcpointer_gc(NULL,pPara,res,"addrinfo");
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void uv_getnameinfo_callback(uv_getnameinfo_t* req, int status, const char* hostname, const char* service)
{
	int x;
	List *pList, *pPara;
	x = uv_checkevent_callback(req,"getnameinfo");
	if (x == 0) return ;
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	// Add the Event Parameters
		pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
		ring_list_deleteallitems_gc(NULL,pPara);
		ring_list_addcpointer_gc(NULL,pPara,req,"uv_getnameinfo_t");
		ring_list_adddouble_gc(NULL,pPara,status);
		ring_list_addstring_gc(NULL,pPara,hostname);
		ring_list_addstring_gc(NULL,pPara,service);
	ring_vm_mutexunlock(pVMLibUV);
	ring_vm_runcode(pVMLibUV,ring_list_getstring(pList,3));
}

void my_alloc_cb(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
buf->base = malloc(suggested_size);
buf->len = suggested_size;
}

RING_FUNC(ring_uv_deletecallbacks)
{
	void *pObject;
	List *pList;
	int x;
	RING_API_IGNORECPOINTERTYPE;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	pObject = RING_API_GETCPOINTER(1,"void");
	ring_vm_mutexlock(pVMLibUV);
	for(x = 1 ; x <= ring_list_getsize(aCallBack) ; x++)
	{
		pList = ring_list_getlist(aCallBack,x) ;
		if (  ring_list_getpointer(pList,1) == pObject  )
		{
			ring_list_deleteitem_gc(NULL,aCallBack,x);
			break ;
		}
	}
	ring_vm_mutexunlock(pVMLibUV);
	return ;
}

RING_FUNC(ring_uv_deleteallcallbacks)
{
	ring_vm_mutexlock(pVMLibUV);
	ring_list_deleteallitems_gc(NULL,aCallBack) ;
	ring_vm_mutexunlock(pVMLibUV);
}

RING_FUNC(ring_uv_callbackscount)
{
	RING_API_RETNUMBER(ring_list_getsize(aCallBack));
}

RING_FUNC(ring_uv_deletecallbacksafter)
{
	int x,nStart,nEnd;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	nStart = ring_list_getsize(aCallBack);
	nEnd = (int) RING_API_GETNUMBER(1);
	ring_vm_mutexlock(pVMLibUV);
	for (x = nStart ; x > nEnd  ; x-- ) {
		ring_list_deleteitem_gc(NULL,aCallBack,x);
	}
	ring_vm_mutexunlock(pVMLibUV);
}

RING_FUNC(ring_uv_callback)
{
	List *pList;
	const char *cCallBackType;
	RING_API_IGNORECPOINTERTYPE;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA) ;
		return ;
	}
	if ( (! RING_API_ISPOINTER(1)) || (! RING_API_ISSTRING(2)) || (! RING_API_ISSTRING(3)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ring_vm_mutexlock(pVMLibUV);
	if ( aCallBack == NULL )
	{
		aCallBack = ring_list_new_gc(NULL,0);
	}
	cCallBackType = RING_API_GETSTRING(2) ;
	pList = ring_list_newlist_gc(NULL,aCallBack);
	ring_list_addpointer_gc(NULL,pList,RING_API_GETCPOINTER(1,"void"));
	ring_list_addstring_gc(NULL,pList,cCallBackType);
	ring_list_addstring_gc(NULL,pList,RING_API_GETSTRING(3));
	// Add List for the Event Parameters
		ring_list_newlist_gc(NULL,pList);	
	ring_vm_mutexunlock(pVMLibUV);
	if (strcmp(cCallBackType,"timer") == 0)
	{
		RING_API_RETCPOINTER(uv_timer_callback,"void");
	}
	else if (strcmp(cCallBackType,"prepare") == 0)
	{
		RING_API_RETCPOINTER(uv_prepare_callback,"void");
	}
	else if (strcmp(cCallBackType,"check") == 0)
	{
		RING_API_RETCPOINTER(uv_check_callback,"void");
	}
	else if (strcmp(cCallBackType,"idle") == 0)
	{
		RING_API_RETCPOINTER(uv_idle_callback,"void");
	}
	else if (strcmp(cCallBackType,"poll") == 0)
	{
		RING_API_RETCPOINTER(uv_poll_callback,"void");
	}
	else if (strcmp(cCallBackType,"signal") == 0)
	{
		RING_API_RETCPOINTER(uv_signal_callback,"void");
	}
	else if (strcmp(cCallBackType,"shutdown") == 0)
	{
		RING_API_RETCPOINTER(uv_shutdown_callback,"void");
	}
	else if (strcmp(cCallBackType,"connection") == 0)
	{
		RING_API_RETCPOINTER(uv_connection_callback,"void");
	}
	else if (strcmp(cCallBackType,"write") == 0)
	{
		RING_API_RETCPOINTER(uv_write_callback,"void");
	}
	else if (strcmp(cCallBackType,"connect") == 0)
	{
		RING_API_RETCPOINTER(uv_connect_callback,"void");
	}
	else if (strcmp(cCallBackType,"fs_event") == 0)
	{
		RING_API_RETCPOINTER(uv_fs_event_callback,"void");
	}
	else if (strcmp(cCallBackType,"fs") == 0)
	{
		RING_API_RETCPOINTER(uv_fs_callback,"void");
	}
	else if (strcmp(cCallBackType,"thread") == 0)
	{
		RING_API_RETCPOINTER(uv_thread_callback,"void");
	}
	else if (strcmp(cCallBackType,"walk") == 0)
	{
		RING_API_RETCPOINTER(uv_walk_callback,"void");
	}
	else if (strcmp(cCallBackType,"close") == 0)
	{
		RING_API_RETCPOINTER(uv_close_callback,"void");
	}
	else if (strcmp(cCallBackType,"async") == 0)
	{
		RING_API_RETCPOINTER(uv_async_callback,"void");
	}
	else if (strcmp(cCallBackType,"alloc") == 0)
	{
		RING_API_RETCPOINTER(uv_alloc_callback,"void");
	}
	else if (strcmp(cCallBackType,"read") == 0)
	{
		RING_API_RETCPOINTER(uv_read_callback,"void");
	}
	else if (strcmp(cCallBackType,"udp_send") == 0)
	{
		RING_API_RETCPOINTER(uv_udp_send_callback,"void");
	}
	else if (strcmp(cCallBackType,"udp_recv") == 0)
	{
		RING_API_RETCPOINTER(uv_udp_recv_callback,"void");
	}
	else if (strcmp(cCallBackType,"fs_poll") == 0)
	{
		RING_API_RETCPOINTER(uv_fs_poll_callback,"void");
	}
	else if (strcmp(cCallBackType,"work") == 0)
	{
		RING_API_RETCPOINTER(uv_work_callback,"void");
	}
	else if (strcmp(cCallBackType,"after_work") == 0)
	{
		RING_API_RETCPOINTER(uv_after_work_callback,"void");
	}
	else if (strcmp(cCallBackType,"getaddrinfo") == 0)
	{
		RING_API_RETCPOINTER(uv_getaddrinfo_callback,"void");
	}
	else if (strcmp(cCallBackType,"getnameinfo") == 0)
	{
		RING_API_RETCPOINTER(uv_getnameinfo_callback,"void");
	}

}

RING_FUNC(ring_uv_eventpara)
{
	int x;
	List *pList, *pPara;
	char *cType;
	RING_API_IGNORECPOINTERTYPE;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( (! RING_API_ISPOINTER(1)) || (! RING_API_ISSTRING(2)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	if ( aCallBack == NULL )
	{
		return;
	}
	cType = RING_API_GETSTRING(2);
	x = uv_checkevent_callback(RING_API_GETCPOINTER(1,"void"),cType);
	ring_vm_mutexlock(pVMLibUV);
	pList = ring_list_getlist(aCallBack,x) ;
	pPara = ring_list_getlist(pList,RINGLIBUV_EVENTPARA);
	ring_vm_mutexunlock(pVMLibUV);
	RING_API_RETLIST(pPara);
}

RING_FUNC(ring_uv_myalloccallback)
{
	RING_API_RETCPOINTER(my_alloc_cb,"void");
}

RING_FUNC(ring_uv_pointer2string)
{
	RING_API_IGNORECPOINTERTYPE;
	RING_API_RETSTRING2(RING_API_GETCPOINTER(1,"char"),RING_API_GETNUMBER(2));
}

RING_FUNC(ring_uv_free)
{
	RING_API_IGNORECPOINTERTYPE;
	free(RING_API_GETCPOINTER(1,"void"));
}

RING_FUNC(ring_new_sockaddr_in)
{
	sockaddr_in *pMyPointer ;
	pMyPointer = (sockaddr_in *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(sockaddr_in)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"sockaddr_in");
}

RING_FUNC(ring_new_managed_sockaddr_in)
{
	sockaddr_in *pMyPointer ;
	pMyPointer = (sockaddr_in *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(sockaddr_in)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"sockaddr_in",ring_state_free);
}

RING_FUNC(ring_destroy_sockaddr_in)
{
	sockaddr_in *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (sockaddr_in*) RING_API_GETCPOINTER(1,"sockaddr_in");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_sockaddr_in6)
{
	sockaddr_in6 *pMyPointer ;
	pMyPointer = (sockaddr_in6 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(sockaddr_in6)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"sockaddr_in6");
}

RING_FUNC(ring_new_managed_sockaddr_in6)
{
	sockaddr_in6 *pMyPointer ;
	pMyPointer = (sockaddr_in6 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(sockaddr_in6)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"sockaddr_in6",ring_state_free);
}

RING_FUNC(ring_destroy_sockaddr_in6)
{
	sockaddr_in6 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (sockaddr_in6*) RING_API_GETCPOINTER(1,"sockaddr_in6");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_e2big)
{
	RING_API_RETNUMBER(UV_E2BIG);
}

RING_FUNC(ring_get_uv_eacces)
{
	RING_API_RETNUMBER(UV_EACCES);
}

RING_FUNC(ring_get_uv_eaddrinuse)
{
	RING_API_RETNUMBER(UV_EADDRINUSE);
}

RING_FUNC(ring_get_uv_eaddrnotavail)
{
	RING_API_RETNUMBER(UV_EADDRNOTAVAIL);
}

RING_FUNC(ring_get_uv_eafnosupport)
{
	RING_API_RETNUMBER(UV_EAFNOSUPPORT);
}

RING_FUNC(ring_get_uv_eagain)
{
	RING_API_RETNUMBER(UV_EAGAIN);
}

RING_FUNC(ring_get_uv_eai_addrfamily)
{
	RING_API_RETNUMBER(UV_EAI_ADDRFAMILY);
}

RING_FUNC(ring_get_uv_eai_again)
{
	RING_API_RETNUMBER(UV_EAI_AGAIN);
}

RING_FUNC(ring_get_uv_eai_badflags)
{
	RING_API_RETNUMBER(UV_EAI_BADFLAGS);
}

RING_FUNC(ring_get_uv_eai_badhints)
{
	RING_API_RETNUMBER(UV_EAI_BADHINTS);
}

RING_FUNC(ring_get_uv_eai_canceled)
{
	RING_API_RETNUMBER(UV_EAI_CANCELED);
}

RING_FUNC(ring_get_uv_eai_fail)
{
	RING_API_RETNUMBER(UV_EAI_FAIL);
}

RING_FUNC(ring_get_uv_eai_family)
{
	RING_API_RETNUMBER(UV_EAI_FAMILY);
}

RING_FUNC(ring_get_uv_eai_memory)
{
	RING_API_RETNUMBER(UV_EAI_MEMORY);
}

RING_FUNC(ring_get_uv_eai_nodata)
{
	RING_API_RETNUMBER(UV_EAI_NODATA);
}

RING_FUNC(ring_get_uv_eai_noname)
{
	RING_API_RETNUMBER(UV_EAI_NONAME);
}

RING_FUNC(ring_get_uv_eai_overflow)
{
	RING_API_RETNUMBER(UV_EAI_OVERFLOW);
}

RING_FUNC(ring_get_uv_eai_protocol)
{
	RING_API_RETNUMBER(UV_EAI_PROTOCOL);
}

RING_FUNC(ring_get_uv_eai_service)
{
	RING_API_RETNUMBER(UV_EAI_SERVICE);
}

RING_FUNC(ring_get_uv_eai_socktype)
{
	RING_API_RETNUMBER(UV_EAI_SOCKTYPE);
}

RING_FUNC(ring_get_uv_ealready)
{
	RING_API_RETNUMBER(UV_EALREADY);
}

RING_FUNC(ring_get_uv_ebadf)
{
	RING_API_RETNUMBER(UV_EBADF);
}

RING_FUNC(ring_get_uv_ebusy)
{
	RING_API_RETNUMBER(UV_EBUSY);
}

RING_FUNC(ring_get_uv_ecanceled)
{
	RING_API_RETNUMBER(UV_ECANCELED);
}

RING_FUNC(ring_get_uv_echarset)
{
	RING_API_RETNUMBER(UV_ECHARSET);
}

RING_FUNC(ring_get_uv_econnaborted)
{
	RING_API_RETNUMBER(UV_ECONNABORTED);
}

RING_FUNC(ring_get_uv_econnrefused)
{
	RING_API_RETNUMBER(UV_ECONNREFUSED);
}

RING_FUNC(ring_get_uv_econnreset)
{
	RING_API_RETNUMBER(UV_ECONNRESET);
}

RING_FUNC(ring_get_uv_edestaddrreq)
{
	RING_API_RETNUMBER(UV_EDESTADDRREQ);
}

RING_FUNC(ring_get_uv_eexist)
{
	RING_API_RETNUMBER(UV_EEXIST);
}

RING_FUNC(ring_get_uv_efault)
{
	RING_API_RETNUMBER(UV_EFAULT);
}

RING_FUNC(ring_get_uv_efbig)
{
	RING_API_RETNUMBER(UV_EFBIG);
}

RING_FUNC(ring_get_uv_ehostunreach)
{
	RING_API_RETNUMBER(UV_EHOSTUNREACH);
}

RING_FUNC(ring_get_uv_eintr)
{
	RING_API_RETNUMBER(UV_EINTR);
}

RING_FUNC(ring_get_uv_einval)
{
	RING_API_RETNUMBER(UV_EINVAL);
}

RING_FUNC(ring_get_uv_eio)
{
	RING_API_RETNUMBER(UV_EIO);
}

RING_FUNC(ring_get_uv_eisconn)
{
	RING_API_RETNUMBER(UV_EISCONN);
}

RING_FUNC(ring_get_uv_eisdir)
{
	RING_API_RETNUMBER(UV_EISDIR);
}

RING_FUNC(ring_get_uv_eloop)
{
	RING_API_RETNUMBER(UV_ELOOP);
}

RING_FUNC(ring_get_uv_emfile)
{
	RING_API_RETNUMBER(UV_EMFILE);
}

RING_FUNC(ring_get_uv_emsgsize)
{
	RING_API_RETNUMBER(UV_EMSGSIZE);
}

RING_FUNC(ring_get_uv_enametoolong)
{
	RING_API_RETNUMBER(UV_ENAMETOOLONG);
}

RING_FUNC(ring_get_uv_enetdown)
{
	RING_API_RETNUMBER(UV_ENETDOWN);
}

RING_FUNC(ring_get_uv_enetunreach)
{
	RING_API_RETNUMBER(UV_ENETUNREACH);
}

RING_FUNC(ring_get_uv_enfile)
{
	RING_API_RETNUMBER(UV_ENFILE);
}

RING_FUNC(ring_get_uv_enobufs)
{
	RING_API_RETNUMBER(UV_ENOBUFS);
}

RING_FUNC(ring_get_uv_enodev)
{
	RING_API_RETNUMBER(UV_ENODEV);
}

RING_FUNC(ring_get_uv_enoent)
{
	RING_API_RETNUMBER(UV_ENOENT);
}

RING_FUNC(ring_get_uv_enomem)
{
	RING_API_RETNUMBER(UV_ENOMEM);
}

RING_FUNC(ring_get_uv_enonet)
{
	RING_API_RETNUMBER(UV_ENONET);
}

RING_FUNC(ring_get_uv_enoprotoopt)
{
	RING_API_RETNUMBER(UV_ENOPROTOOPT);
}

RING_FUNC(ring_get_uv_enospc)
{
	RING_API_RETNUMBER(UV_ENOSPC);
}

RING_FUNC(ring_get_uv_enosys)
{
	RING_API_RETNUMBER(UV_ENOSYS);
}

RING_FUNC(ring_get_uv_enotconn)
{
	RING_API_RETNUMBER(UV_ENOTCONN);
}

RING_FUNC(ring_get_uv_enotdir)
{
	RING_API_RETNUMBER(UV_ENOTDIR);
}

RING_FUNC(ring_get_uv_enotempty)
{
	RING_API_RETNUMBER(UV_ENOTEMPTY);
}

RING_FUNC(ring_get_uv_enotsock)
{
	RING_API_RETNUMBER(UV_ENOTSOCK);
}

RING_FUNC(ring_get_uv_enotsup)
{
	RING_API_RETNUMBER(UV_ENOTSUP);
}

RING_FUNC(ring_get_uv_eperm)
{
	RING_API_RETNUMBER(UV_EPERM);
}

RING_FUNC(ring_get_uv_epipe)
{
	RING_API_RETNUMBER(UV_EPIPE);
}

RING_FUNC(ring_get_uv_eproto)
{
	RING_API_RETNUMBER(UV_EPROTO);
}

RING_FUNC(ring_get_uv_eprotonosupport)
{
	RING_API_RETNUMBER(UV_EPROTONOSUPPORT);
}

RING_FUNC(ring_get_uv_eprototype)
{
	RING_API_RETNUMBER(UV_EPROTOTYPE);
}

RING_FUNC(ring_get_uv_erange)
{
	RING_API_RETNUMBER(UV_ERANGE);
}

RING_FUNC(ring_get_uv_erofs)
{
	RING_API_RETNUMBER(UV_EROFS);
}

RING_FUNC(ring_get_uv_eshutdown)
{
	RING_API_RETNUMBER(UV_ESHUTDOWN);
}

RING_FUNC(ring_get_uv_espipe)
{
	RING_API_RETNUMBER(UV_ESPIPE);
}

RING_FUNC(ring_get_uv_esrch)
{
	RING_API_RETNUMBER(UV_ESRCH);
}

RING_FUNC(ring_get_uv_etimedout)
{
	RING_API_RETNUMBER(UV_ETIMEDOUT);
}

RING_FUNC(ring_get_uv_etxtbsy)
{
	RING_API_RETNUMBER(UV_ETXTBSY);
}

RING_FUNC(ring_get_uv_exdev)
{
	RING_API_RETNUMBER(UV_EXDEV);
}

RING_FUNC(ring_get_uv_unknown)
{
	RING_API_RETNUMBER(UV_UNKNOWN);
}

RING_FUNC(ring_get_uv_eof)
{
	RING_API_RETNUMBER(UV_EOF);
}

RING_FUNC(ring_get_uv_enxio)
{
	RING_API_RETNUMBER(UV_ENXIO);
}

RING_FUNC(ring_get_uv_emlink)
{
	RING_API_RETNUMBER(UV_EMLINK);
}

RING_FUNC(ring_get_uv_version_major)
{
	RING_API_RETNUMBER(UV_VERSION_MAJOR);
}

RING_FUNC(ring_get_uv_version_minor)
{
	RING_API_RETNUMBER(UV_VERSION_MINOR);
}

RING_FUNC(ring_get_uv_version_patch)
{
	RING_API_RETNUMBER(UV_VERSION_PATCH);
}

RING_FUNC(ring_get_uv_version_is_release)
{
	RING_API_RETNUMBER(UV_VERSION_IS_RELEASE);
}

RING_FUNC(ring_get_uv_version_hex)
{
	RING_API_RETNUMBER(UV_VERSION_HEX);
}

RING_FUNC(ring_get_uv_run_default)
{
	RING_API_RETNUMBER(UV_RUN_DEFAULT);
}

RING_FUNC(ring_get_uv_run_once)
{
	RING_API_RETNUMBER(UV_RUN_ONCE);
}

RING_FUNC(ring_get_uv_run_nowait)
{
	RING_API_RETNUMBER(UV_RUN_NOWAIT);
}

RING_FUNC(ring_get_uv_unknown_handle)
{
	RING_API_RETNUMBER(UV_UNKNOWN_HANDLE);
}

RING_FUNC(ring_get_uv_async)
{
	RING_API_RETNUMBER(UV_ASYNC);
}

RING_FUNC(ring_get_uv_check)
{
	RING_API_RETNUMBER(UV_CHECK);
}

RING_FUNC(ring_get_uv_fs_event)
{
	RING_API_RETNUMBER(UV_FS_EVENT);
}

RING_FUNC(ring_get_uv_fs_poll)
{
	RING_API_RETNUMBER(UV_FS_POLL);
}

RING_FUNC(ring_get_uv_handle)
{
	RING_API_RETNUMBER(UV_HANDLE);
}

RING_FUNC(ring_get_uv_idle)
{
	RING_API_RETNUMBER(UV_IDLE);
}

RING_FUNC(ring_get_uv_named_pipe)
{
	RING_API_RETNUMBER(UV_NAMED_PIPE);
}

RING_FUNC(ring_get_uv_poll)
{
	RING_API_RETNUMBER(UV_POLL);
}

RING_FUNC(ring_get_uv_prepare)
{
	RING_API_RETNUMBER(UV_PREPARE);
}

RING_FUNC(ring_get_uv_process)
{
	RING_API_RETNUMBER(UV_PROCESS);
}

RING_FUNC(ring_get_uv_stream)
{
	RING_API_RETNUMBER(UV_STREAM);
}

RING_FUNC(ring_get_uv_tcp)
{
	RING_API_RETNUMBER(UV_TCP);
}

RING_FUNC(ring_get_uv_timer)
{
	RING_API_RETNUMBER(UV_TIMER);
}

RING_FUNC(ring_get_uv_tty)
{
	RING_API_RETNUMBER(UV_TTY);
}

RING_FUNC(ring_get_uv_udp)
{
	RING_API_RETNUMBER(UV_UDP);
}

RING_FUNC(ring_get_uv_signal)
{
	RING_API_RETNUMBER(UV_SIGNAL);
}

RING_FUNC(ring_get_uv_file)
{
	RING_API_RETNUMBER(UV_FILE);
}

RING_FUNC(ring_get_uv_handle_type_max)
{
	RING_API_RETNUMBER(UV_HANDLE_TYPE_MAX);
}

RING_FUNC(ring_get_uv_unknown_req)
{
	RING_API_RETNUMBER(UV_UNKNOWN_REQ);
}

RING_FUNC(ring_get_uv_req)
{
	RING_API_RETNUMBER(UV_REQ);
}

RING_FUNC(ring_get_uv_connect)
{
	RING_API_RETNUMBER(UV_CONNECT);
}

RING_FUNC(ring_get_uv_write)
{
	RING_API_RETNUMBER(UV_WRITE);
}

RING_FUNC(ring_get_uv_shutdown)
{
	RING_API_RETNUMBER(UV_SHUTDOWN);
}

RING_FUNC(ring_get_uv_udp_send)
{
	RING_API_RETNUMBER(UV_UDP_SEND);
}

RING_FUNC(ring_get_uv_fs)
{
	RING_API_RETNUMBER(UV_FS);
}

RING_FUNC(ring_get_uv_work)
{
	RING_API_RETNUMBER(UV_WORK);
}

RING_FUNC(ring_get_uv_getaddrinfo)
{
	RING_API_RETNUMBER(UV_GETADDRINFO);
}

RING_FUNC(ring_get_uv_getnameinfo)
{
	RING_API_RETNUMBER(UV_GETNAMEINFO);
}

RING_FUNC(ring_get_uv_req_type_max)
{
	RING_API_RETNUMBER(UV_REQ_TYPE_MAX);
}

RING_FUNC(ring_get_uv_readable)
{
	RING_API_RETNUMBER(UV_READABLE);
}

RING_FUNC(ring_get_uv_writable)
{
	RING_API_RETNUMBER(UV_WRITABLE);
}

RING_FUNC(ring_get_uv_disconnect)
{
	RING_API_RETNUMBER(UV_DISCONNECT);
}

RING_FUNC(ring_get_uv_prioritized)
{
	RING_API_RETNUMBER(UV_PRIORITIZED);
}

RING_FUNC(ring_get_uv_process_setuid)
{
	RING_API_RETNUMBER(UV_PROCESS_SETUID);
}

RING_FUNC(ring_get_uv_process_setgid)
{
	RING_API_RETNUMBER(UV_PROCESS_SETGID);
}

RING_FUNC(ring_get_uv_process_windows_verbatim_arguments)
{
	RING_API_RETNUMBER(UV_PROCESS_WINDOWS_VERBATIM_ARGUMENTS);
}

RING_FUNC(ring_get_uv_process_detached)
{
	RING_API_RETNUMBER(UV_PROCESS_DETACHED);
}

RING_FUNC(ring_get_uv_process_windows_hide)
{
	RING_API_RETNUMBER(UV_PROCESS_WINDOWS_HIDE);
}

RING_FUNC(ring_get_uv_ignore)
{
	RING_API_RETNUMBER(UV_IGNORE);
}

RING_FUNC(ring_get_uv_create_pipe)
{
	RING_API_RETNUMBER(UV_CREATE_PIPE);
}

RING_FUNC(ring_get_uv_inherit_fd)
{
	RING_API_RETNUMBER(UV_INHERIT_FD);
}

RING_FUNC(ring_get_uv_inherit_stream)
{
	RING_API_RETNUMBER(UV_INHERIT_STREAM);
}

RING_FUNC(ring_get_uv_readable_pipe)
{
	RING_API_RETNUMBER(UV_READABLE_PIPE);
}

RING_FUNC(ring_get_uv_writable_pipe)
{
	RING_API_RETNUMBER(UV_WRITABLE_PIPE);
}

RING_FUNC(ring_get_uv_tty_mode_normal)
{
	RING_API_RETNUMBER(UV_TTY_MODE_NORMAL);
}

RING_FUNC(ring_get_uv_tty_mode_raw)
{
	RING_API_RETNUMBER(UV_TTY_MODE_RAW);
}

RING_FUNC(ring_get_uv_tty_mode_io)
{
	RING_API_RETNUMBER(UV_TTY_MODE_IO);
}

RING_FUNC(ring_get_uv_udp_ipv6only)
{
	RING_API_RETNUMBER(UV_UDP_IPV6ONLY);
}

RING_FUNC(ring_get_uv_udp_partial)
{
	RING_API_RETNUMBER(UV_UDP_PARTIAL);
}

RING_FUNC(ring_get_uv_udp_reuseaddr)
{
	RING_API_RETNUMBER(UV_UDP_REUSEADDR);
}

RING_FUNC(ring_get_uv_leave_group)
{
	RING_API_RETNUMBER(UV_LEAVE_GROUP);
}

RING_FUNC(ring_get_uv_join_group)
{
	RING_API_RETNUMBER(UV_JOIN_GROUP);
}

RING_FUNC(ring_get_uv_rename)
{
	RING_API_RETNUMBER(UV_RENAME);
}

RING_FUNC(ring_get_uv_change)
{
	RING_API_RETNUMBER(UV_CHANGE);
}

RING_FUNC(ring_get_uv_fs_event_watch_entry)
{
	RING_API_RETNUMBER(UV_FS_EVENT_WATCH_ENTRY);
}

RING_FUNC(ring_get_uv_fs_event_stat)
{
	RING_API_RETNUMBER(UV_FS_EVENT_STAT);
}

RING_FUNC(ring_get_uv_fs_event_recursive)
{
	RING_API_RETNUMBER(UV_FS_EVENT_RECURSIVE);
}

RING_FUNC(ring_get_uv_fs_unknown)
{
	RING_API_RETNUMBER(UV_FS_UNKNOWN);
}

RING_FUNC(ring_get_uv_fs_custom)
{
	RING_API_RETNUMBER(UV_FS_CUSTOM);
}

RING_FUNC(ring_get_uv_fs_open)
{
	RING_API_RETNUMBER(UV_FS_OPEN);
}

RING_FUNC(ring_get_uv_fs_close)
{
	RING_API_RETNUMBER(UV_FS_CLOSE);
}

RING_FUNC(ring_get_uv_fs_read)
{
	RING_API_RETNUMBER(UV_FS_READ);
}

RING_FUNC(ring_get_uv_fs_write)
{
	RING_API_RETNUMBER(UV_FS_WRITE);
}

RING_FUNC(ring_get_uv_fs_sendfile)
{
	RING_API_RETNUMBER(UV_FS_SENDFILE);
}

RING_FUNC(ring_get_uv_fs_stat)
{
	RING_API_RETNUMBER(UV_FS_STAT);
}

RING_FUNC(ring_get_uv_fs_lstat)
{
	RING_API_RETNUMBER(UV_FS_LSTAT);
}

RING_FUNC(ring_get_uv_fs_fstat)
{
	RING_API_RETNUMBER(UV_FS_FSTAT);
}

RING_FUNC(ring_get_uv_fs_ftruncate)
{
	RING_API_RETNUMBER(UV_FS_FTRUNCATE);
}

RING_FUNC(ring_get_uv_fs_utime)
{
	RING_API_RETNUMBER(UV_FS_UTIME);
}

RING_FUNC(ring_get_uv_fs_futime)
{
	RING_API_RETNUMBER(UV_FS_FUTIME);
}

RING_FUNC(ring_get_uv_fs_access)
{
	RING_API_RETNUMBER(UV_FS_ACCESS);
}

RING_FUNC(ring_get_uv_fs_chmod)
{
	RING_API_RETNUMBER(UV_FS_CHMOD);
}

RING_FUNC(ring_get_uv_fs_fchmod)
{
	RING_API_RETNUMBER(UV_FS_FCHMOD);
}

RING_FUNC(ring_get_uv_fs_fsync)
{
	RING_API_RETNUMBER(UV_FS_FSYNC);
}

RING_FUNC(ring_get_uv_fs_fdatasync)
{
	RING_API_RETNUMBER(UV_FS_FDATASYNC);
}

RING_FUNC(ring_get_uv_fs_unlink)
{
	RING_API_RETNUMBER(UV_FS_UNLINK);
}

RING_FUNC(ring_get_uv_fs_rmdir)
{
	RING_API_RETNUMBER(UV_FS_RMDIR);
}

RING_FUNC(ring_get_uv_fs_mkdir)
{
	RING_API_RETNUMBER(UV_FS_MKDIR);
}

RING_FUNC(ring_get_uv_fs_mkdtemp)
{
	RING_API_RETNUMBER(UV_FS_MKDTEMP);
}

RING_FUNC(ring_get_uv_fs_rename)
{
	RING_API_RETNUMBER(UV_FS_RENAME);
}

RING_FUNC(ring_get_uv_fs_scandir)
{
	RING_API_RETNUMBER(UV_FS_SCANDIR);
}

RING_FUNC(ring_get_uv_fs_link)
{
	RING_API_RETNUMBER(UV_FS_LINK);
}

RING_FUNC(ring_get_uv_fs_symlink)
{
	RING_API_RETNUMBER(UV_FS_SYMLINK);
}

RING_FUNC(ring_get_uv_fs_readlink)
{
	RING_API_RETNUMBER(UV_FS_READLINK);
}

RING_FUNC(ring_get_uv_fs_chown)
{
	RING_API_RETNUMBER(UV_FS_CHOWN);
}

RING_FUNC(ring_get_uv_fs_fchown)
{
	RING_API_RETNUMBER(UV_FS_FCHOWN);
}

RING_FUNC(ring_get_uv_fs_realpath)
{
	RING_API_RETNUMBER(UV_FS_REALPATH);
}

RING_FUNC(ring_get_uv_fs_copyfile)
{
	RING_API_RETNUMBER(UV_FS_COPYFILE);
}

RING_FUNC(ring_get_uv_dirent_unknown)
{
	RING_API_RETNUMBER(UV_DIRENT_UNKNOWN);
}

RING_FUNC(ring_get_uv_dirent_file)
{
	RING_API_RETNUMBER(UV_DIRENT_FILE);
}

RING_FUNC(ring_get_uv_dirent_dir)
{
	RING_API_RETNUMBER(UV_DIRENT_DIR);
}

RING_FUNC(ring_get_uv_dirent_link)
{
	RING_API_RETNUMBER(UV_DIRENT_LINK);
}

RING_FUNC(ring_get_uv_dirent_fifo)
{
	RING_API_RETNUMBER(UV_DIRENT_FIFO);
}

RING_FUNC(ring_get_uv_dirent_socket)
{
	RING_API_RETNUMBER(UV_DIRENT_SOCKET);
}

RING_FUNC(ring_get_uv_dirent_char)
{
	RING_API_RETNUMBER(UV_DIRENT_CHAR);
}

RING_FUNC(ring_get_uv_dirent_block)
{
	RING_API_RETNUMBER(UV_DIRENT_BLOCK);
}

RING_FUNC(ring_get_uv_fs_o_append)
{
	RING_API_RETNUMBER(UV_FS_O_APPEND);
}

RING_FUNC(ring_get_uv_fs_o_creat)
{
	RING_API_RETNUMBER(UV_FS_O_CREAT);
}

RING_FUNC(ring_get_uv_fs_o_direct)
{
	RING_API_RETNUMBER(UV_FS_O_DIRECT);
}

RING_FUNC(ring_get_uv_fs_o_directory)
{
	RING_API_RETNUMBER(UV_FS_O_DIRECTORY);
}

RING_FUNC(ring_get_uv_fs_o_dsync)
{
	RING_API_RETNUMBER(UV_FS_O_DSYNC);
}

RING_FUNC(ring_get_uv_fs_o_excl)
{
	RING_API_RETNUMBER(UV_FS_O_EXCL);
}

RING_FUNC(ring_get_uv_fs_o_exlock)
{
	RING_API_RETNUMBER(UV_FS_O_EXLOCK);
}

RING_FUNC(ring_get_uv_fs_o_noatime)
{
	RING_API_RETNUMBER(UV_FS_O_NOATIME);
}

RING_FUNC(ring_get_uv_fs_o_noctty)
{
	RING_API_RETNUMBER(UV_FS_O_NOCTTY);
}

RING_FUNC(ring_get_uv_fs_o_nofollow)
{
	RING_API_RETNUMBER(UV_FS_O_NOFOLLOW);
}

RING_FUNC(ring_get_uv_fs_o_nonblock)
{
	RING_API_RETNUMBER(UV_FS_O_NONBLOCK);
}

RING_FUNC(ring_get_uv_fs_o_random)
{
	RING_API_RETNUMBER(UV_FS_O_RANDOM);
}

RING_FUNC(ring_get_uv_fs_o_rdonly)
{
	RING_API_RETNUMBER(UV_FS_O_RDONLY);
}

RING_FUNC(ring_get_uv_fs_o_rdwr)
{
	RING_API_RETNUMBER(UV_FS_O_RDWR);
}

RING_FUNC(ring_get_uv_fs_o_sequential)
{
	RING_API_RETNUMBER(UV_FS_O_SEQUENTIAL);
}

RING_FUNC(ring_get_uv_fs_o_short_lived)
{
	RING_API_RETNUMBER(UV_FS_O_SHORT_LIVED);
}

RING_FUNC(ring_get_uv_fs_o_symlink)
{
	RING_API_RETNUMBER(UV_FS_O_SYMLINK);
}

RING_FUNC(ring_get_uv_fs_o_sync)
{
	RING_API_RETNUMBER(UV_FS_O_SYNC);
}

RING_FUNC(ring_get_uv_fs_o_temporary)
{
	RING_API_RETNUMBER(UV_FS_O_TEMPORARY);
}

RING_FUNC(ring_get_uv_fs_o_trunc)
{
	RING_API_RETNUMBER(UV_FS_O_TRUNC);
}

RING_FUNC(ring_get_uv_fs_o_wronly)
{
	RING_API_RETNUMBER(UV_FS_O_WRONLY);
}

RING_FUNC(ring_get_uv_if_namesize)
{
	RING_API_RETNUMBER(UV_IF_NAMESIZE);
}


RING_FUNC(ring_uv_strerror)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uv_strerror( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uv_err_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uv_err_name( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uv_translate_sys_error)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_translate_sys_error( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uv_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_version());
}


RING_FUNC(ring_uv_version_string)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(uv_version_string());
}

RING_FUNC(ring_new_uv_loop_t)
{
	uv_loop_t *pMyPointer ;
	pMyPointer = (uv_loop_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_loop_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_loop_t");
}

RING_FUNC(ring_new_managed_uv_loop_t)
{
	uv_loop_t *pMyPointer ;
	pMyPointer = (uv_loop_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_loop_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_loop_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_loop_t)
{
	uv_loop_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_loop_t*) RING_API_GETCPOINTER(1,"uv_loop_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_loop_t_data)
{
	uv_loop_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_loop_t");
	RING_API_RETCPOINTER(pMyPointer->data,"void");
}

RING_FUNC(ring_set_uv_loop_t_data)
{
	uv_loop_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_loop_t");
	pMyPointer->data = (void *) RING_API_GETCPOINTER(2,"void");
}


RING_FUNC(ring_uv_loop_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_loop_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}


RING_FUNC(ring_uv_loop_configure)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_loop_configure((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),* (uv_loop_option  *) RING_API_GETCPOINTER(2,"uv_loop_option"), (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_loop_option"));
}


RING_FUNC(ring_uv_loop_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_loop_close((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}


RING_FUNC(ring_uv_default_loop)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uv_default_loop(),"uv_loop_t");
}


RING_FUNC(ring_uv_run)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_run((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"), (uv_run_mode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_loop_alive)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_loop_alive((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}


RING_FUNC(ring_uv_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_stop((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"));
}


RING_FUNC(ring_uv_loop_size)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_loop_size());
}


RING_FUNC(ring_uv_backend_fd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_backend_fd((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}


RING_FUNC(ring_uv_backend_timeout)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_backend_timeout((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}


RING_FUNC(ring_uv_now)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_now((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}


RING_FUNC(ring_uv_update_time)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_update_time((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"));
}


RING_FUNC(ring_uv_walk)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_walk((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),RING_API_GETCPOINTER(2,"uv_walk_cb"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_walk_cb"));
}


RING_FUNC(ring_uv_walk_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_walk((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),RING_API_GETCPOINTER(2,"uv_walk_cb"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_walk_cb"));
}


RING_FUNC(ring_uv_loop_fork)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_loop_fork((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t")));
}

RING_FUNC(ring_new_uv_handle_t)
{
	uv_handle_t *pMyPointer ;
	pMyPointer = (uv_handle_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_handle_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_handle_t");
}

RING_FUNC(ring_new_managed_uv_handle_t)
{
	uv_handle_t *pMyPointer ;
	pMyPointer = (uv_handle_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_handle_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_handle_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_handle_t)
{
	uv_handle_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_handle_t*) RING_API_GETCPOINTER(1,"uv_handle_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_handle_t_loop)
{
	uv_handle_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_handle_t");
	RING_API_RETCPOINTER(pMyPointer->loop,"uv_loop_t");
}

RING_FUNC(ring_set_uv_handle_t_loop)
{
	uv_handle_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_handle_t");
	pMyPointer->loop = (uv_loop_t *) RING_API_GETCPOINTER(2,"uv_loop_t");
}

RING_FUNC(ring_get_uv_handle_t_type)
{
	uv_handle_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_handle_t");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_set_uv_handle_t_type)
{
	uv_handle_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_handle_t");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uv_handle_t_data)
{
	uv_handle_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_handle_t");
	RING_API_RETCPOINTER(pMyPointer->data,"void");
}

RING_FUNC(ring_set_uv_handle_t_data)
{
	uv_handle_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_handle_t");
	pMyPointer->data = (void *) RING_API_GETCPOINTER(2,"void");
}


RING_FUNC(ring_uv_is_active)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_is_active((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t")));
}


RING_FUNC(ring_uv_is_closing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_is_closing((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t")));
}


RING_FUNC(ring_uv_close)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_close((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"),* (uv_close_cb  *) RING_API_GETCPOINTER(2,"uv_close_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_close_cb"));
}


RING_FUNC(ring_uv_close_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_close((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"),* (uv_close_cb  *) RING_API_GETCPOINTER(2,"uv_close_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_close_cb"));
}


RING_FUNC(ring_uv_ref)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_ref((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"));
}


RING_FUNC(ring_uv_unref)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_unref((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"));
}


RING_FUNC(ring_uv_has_ref)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_has_ref((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t")));
}


RING_FUNC(ring_uv_handle_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_handle_size( (uv_handle_type )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uv_send_buffer_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_send_buffer_size((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_uv_recv_buffer_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_recv_buffer_size((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_uv_fileno)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fileno((uv_handle_t *) RING_API_GETCPOINTER(1,"uv_handle_t"),(uv_os_fd_t *) RING_API_GETCPOINTER(2,"uv_os_fd_t")));
}

RING_FUNC(ring_new_uv_req_t)
{
	uv_req_t *pMyPointer ;
	pMyPointer = (uv_req_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_req_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_req_t");
}

RING_FUNC(ring_new_managed_uv_req_t)
{
	uv_req_t *pMyPointer ;
	pMyPointer = (uv_req_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_req_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_req_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_req_t)
{
	uv_req_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_req_t*) RING_API_GETCPOINTER(1,"uv_req_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_req_t_data)
{
	uv_req_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_req_t");
	RING_API_RETCPOINTER(pMyPointer->data,"void");
}

RING_FUNC(ring_set_uv_req_t_data)
{
	uv_req_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_req_t");
	pMyPointer->data = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_get_uv_req_t_type)
{
	uv_req_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_req_t");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_set_uv_req_t_type)
{
	uv_req_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_req_t");
	pMyPointer->type = RING_API_GETNUMBER(2);
}


RING_FUNC(ring_uv_cancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_cancel((uv_req_t *) RING_API_GETCPOINTER(1,"uv_req_t")));
}


RING_FUNC(ring_uv_req_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_req_size(* (uv_req_type  *) RING_API_GETCPOINTER(1,"uv_req_type")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uv_req_type"));
}

RING_FUNC(ring_new_uv_timer_t)
{
	uv_timer_t *pMyPointer ;
	pMyPointer = (uv_timer_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_timer_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_timer_t");
}

RING_FUNC(ring_new_managed_uv_timer_t)
{
	uv_timer_t *pMyPointer ;
	pMyPointer = (uv_timer_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_timer_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_timer_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_timer_t)
{
	uv_timer_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_timer_t*) RING_API_GETCPOINTER(1,"uv_timer_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_timer_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_timer_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_timer_t *) RING_API_GETCPOINTER(2,"uv_timer_t")));
}


RING_FUNC(ring_uv_timer_start)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(uv_timer_start((uv_timer_t *) RING_API_GETCPOINTER(1,"uv_timer_t"),RING_API_GETCPOINTER(2,"uv_timer_cb"), (uint64_t ) RING_API_GETNUMBER(3), (uint64_t ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_timer_cb"));
}


RING_FUNC(ring_uv_timer_start_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(uv_timer_start((uv_timer_t *) RING_API_GETCPOINTER(1,"uv_timer_t"),RING_API_GETCPOINTER(2,"uv_timer_cb"), (uint64_t ) RING_API_GETNUMBER(3), (uint64_t ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_timer_cb"));
}


RING_FUNC(ring_uv_timer_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_timer_stop((uv_timer_t *) RING_API_GETCPOINTER(1,"uv_timer_t")));
}


RING_FUNC(ring_uv_timer_again)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_timer_again((uv_timer_t *) RING_API_GETCPOINTER(1,"uv_timer_t")));
}


RING_FUNC(ring_uv_timer_set_repeat)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_timer_set_repeat((uv_timer_t *) RING_API_GETCPOINTER(1,"uv_timer_t"), (uint64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uv_timer_get_repeat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_timer_get_repeat((uv_timer_t *) RING_API_GETCPOINTER(1,"uv_timer_t")));
}

RING_FUNC(ring_new_uv_prepare_t)
{
	uv_prepare_t *pMyPointer ;
	pMyPointer = (uv_prepare_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_prepare_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_prepare_t");
}

RING_FUNC(ring_new_managed_uv_prepare_t)
{
	uv_prepare_t *pMyPointer ;
	pMyPointer = (uv_prepare_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_prepare_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_prepare_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_prepare_t)
{
	uv_prepare_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_prepare_t*) RING_API_GETCPOINTER(1,"uv_prepare_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_prepare_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_prepare_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_prepare_t *) RING_API_GETCPOINTER(2,"uv_prepare_t")));
}


RING_FUNC(ring_uv_prepare_start)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_prepare_start((uv_prepare_t *) RING_API_GETCPOINTER(1,"uv_prepare_t"),RING_API_GETCPOINTER(2,"uv_prepare_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_prepare_cb"));
}


RING_FUNC(ring_uv_prepare_start_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_prepare_start((uv_prepare_t *) RING_API_GETCPOINTER(1,"uv_prepare_t"),RING_API_GETCPOINTER(2,"uv_prepare_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_prepare_cb"));
}


RING_FUNC(ring_uv_prepare_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_prepare_stop((uv_prepare_t *) RING_API_GETCPOINTER(1,"uv_prepare_t")));
}

RING_FUNC(ring_new_uv_check_t)
{
	uv_check_t *pMyPointer ;
	pMyPointer = (uv_check_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_check_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_check_t");
}

RING_FUNC(ring_new_managed_uv_check_t)
{
	uv_check_t *pMyPointer ;
	pMyPointer = (uv_check_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_check_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_check_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_check_t)
{
	uv_check_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_check_t*) RING_API_GETCPOINTER(1,"uv_check_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_check_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_check_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_check_t *) RING_API_GETCPOINTER(2,"uv_check_t")));
}


RING_FUNC(ring_uv_check_start)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_check_start((uv_check_t *) RING_API_GETCPOINTER(1,"uv_check_t"),RING_API_GETCPOINTER(2,"uv_check_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_check_cb"));
}


RING_FUNC(ring_uv_check_start_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_check_start((uv_check_t *) RING_API_GETCPOINTER(1,"uv_check_t"),RING_API_GETCPOINTER(2,"uv_check_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_check_cb"));
}


RING_FUNC(ring_uv_check_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_check_stop((uv_check_t *) RING_API_GETCPOINTER(1,"uv_check_t")));
}

RING_FUNC(ring_new_uv_idle_t)
{
	uv_idle_t *pMyPointer ;
	pMyPointer = (uv_idle_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_idle_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_idle_t");
}

RING_FUNC(ring_new_managed_uv_idle_t)
{
	uv_idle_t *pMyPointer ;
	pMyPointer = (uv_idle_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_idle_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_idle_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_idle_t)
{
	uv_idle_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_idle_t*) RING_API_GETCPOINTER(1,"uv_idle_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_idle_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_idle_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_idle_t *) RING_API_GETCPOINTER(2,"uv_idle_t")));
}


RING_FUNC(ring_uv_idle_start)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_idle_start((uv_idle_t *) RING_API_GETCPOINTER(1,"uv_idle_t"),RING_API_GETCPOINTER(2,"uv_idle_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_idle_cb"));
}


RING_FUNC(ring_uv_idle_start_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_idle_start((uv_idle_t *) RING_API_GETCPOINTER(1,"uv_idle_t"),RING_API_GETCPOINTER(2,"uv_idle_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_idle_cb"));
}


RING_FUNC(ring_uv_idle_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_idle_stop((uv_idle_t *) RING_API_GETCPOINTER(1,"uv_idle_t")));
}

RING_FUNC(ring_new_uv_async_t)
{
	uv_async_t *pMyPointer ;
	pMyPointer = (uv_async_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_async_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_async_t");
}

RING_FUNC(ring_new_managed_uv_async_t)
{
	uv_async_t *pMyPointer ;
	pMyPointer = (uv_async_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_async_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_async_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_async_t)
{
	uv_async_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_async_t*) RING_API_GETCPOINTER(1,"uv_async_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_async_init)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_async_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_async_t *) RING_API_GETCPOINTER(2,"uv_async_t"),RING_API_GETCPOINTER(3,"uv_async_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_async_cb"));
}


RING_FUNC(ring_uv_async_init_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_async_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_async_t *) RING_API_GETCPOINTER(2,"uv_async_t"),RING_API_GETCPOINTER(3,"uv_async_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_async_cb"));
}


RING_FUNC(ring_uv_async_send)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_async_send((uv_async_t *) RING_API_GETCPOINTER(1,"uv_async_t")));
}

RING_FUNC(ring_new_uv_poll_t)
{
	uv_poll_t *pMyPointer ;
	pMyPointer = (uv_poll_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_poll_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_poll_t");
}

RING_FUNC(ring_new_managed_uv_poll_t)
{
	uv_poll_t *pMyPointer ;
	pMyPointer = (uv_poll_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_poll_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_poll_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_poll_t)
{
	uv_poll_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_poll_t*) RING_API_GETCPOINTER(1,"uv_poll_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_poll_init)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_poll_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_poll_t *) RING_API_GETCPOINTER(2,"uv_poll_t"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_poll_init_socket)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_poll_init_socket((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_poll_t *) RING_API_GETCPOINTER(2,"uv_poll_t"),* (uv_os_sock_t  *) RING_API_GETCPOINTER(3,"uv_os_sock_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_os_sock_t"));
}


RING_FUNC(ring_uv_poll_start)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_poll_start((uv_poll_t *) RING_API_GETCPOINTER(1,"uv_poll_t"), (int ) RING_API_GETNUMBER(2),RING_API_GETCPOINTER(3,"uv_poll_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_poll_cb"));
}


RING_FUNC(ring_uv_poll_start_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_poll_start((uv_poll_t *) RING_API_GETCPOINTER(1,"uv_poll_t"), (int ) RING_API_GETNUMBER(2),RING_API_GETCPOINTER(3,"uv_poll_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_poll_cb"));
}


RING_FUNC(ring_uv_poll_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_poll_stop((uv_poll_t *) RING_API_GETCPOINTER(1,"uv_poll_t")));
}

RING_FUNC(ring_new_uv_signal_t)
{
	uv_signal_t *pMyPointer ;
	pMyPointer = (uv_signal_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_signal_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_signal_t");
}

RING_FUNC(ring_new_managed_uv_signal_t)
{
	uv_signal_t *pMyPointer ;
	pMyPointer = (uv_signal_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_signal_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_signal_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_signal_t)
{
	uv_signal_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_signal_t*) RING_API_GETCPOINTER(1,"uv_signal_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_signal_t_signum)
{
	uv_signal_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_signal_t");
	RING_API_RETNUMBER(pMyPointer->signum);
}

RING_FUNC(ring_set_uv_signal_t_signum)
{
	uv_signal_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_signal_t");
	pMyPointer->signum = RING_API_GETNUMBER(2);
}


RING_FUNC(ring_uv_signal_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_signal_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_signal_t *) RING_API_GETCPOINTER(2,"uv_signal_t")));
}


RING_FUNC(ring_uv_signal_start)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_signal_start((uv_signal_t *) RING_API_GETCPOINTER(1,"uv_signal_t"),RING_API_GETCPOINTER(2,"uv_signal_cb"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_signal_cb"));
}


RING_FUNC(ring_uv_signal_start_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_signal_start((uv_signal_t *) RING_API_GETCPOINTER(1,"uv_signal_t"),RING_API_GETCPOINTER(2,"uv_signal_cb"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_signal_cb"));
}


RING_FUNC(ring_uv_signal_start_oneshot)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_signal_start_oneshot((uv_signal_t *) RING_API_GETCPOINTER(1,"uv_signal_t"),RING_API_GETCPOINTER(2,"uv_signal_cb"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_signal_cb"));
}


RING_FUNC(ring_uv_signal_start_oneshot_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_signal_start_oneshot((uv_signal_t *) RING_API_GETCPOINTER(1,"uv_signal_t"),RING_API_GETCPOINTER(2,"uv_signal_cb"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_signal_cb"));
}


RING_FUNC(ring_uv_signal_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_signal_stop((uv_signal_t *) RING_API_GETCPOINTER(1,"uv_signal_t")));
}

RING_FUNC(ring_new_uv_process_t)
{
	uv_process_t *pMyPointer ;
	pMyPointer = (uv_process_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_process_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_process_t");
}

RING_FUNC(ring_new_managed_uv_process_t)
{
	uv_process_t *pMyPointer ;
	pMyPointer = (uv_process_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_process_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_process_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_process_t)
{
	uv_process_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_process_t*) RING_API_GETCPOINTER(1,"uv_process_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_process_t_pid)
{
	uv_process_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_process_t");
	RING_API_RETNUMBER(pMyPointer->pid);
}

RING_FUNC(ring_set_uv_process_t_pid)
{
	uv_process_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_process_t");
	pMyPointer->pid = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uv_process_options_t)
{
	uv_process_options_t *pMyPointer ;
	pMyPointer = (uv_process_options_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_process_options_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_process_options_t");
}

RING_FUNC(ring_new_managed_uv_process_options_t)
{
	uv_process_options_t *pMyPointer ;
	pMyPointer = (uv_process_options_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_process_options_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_process_options_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_process_options_t)
{
	uv_process_options_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_process_options_t*) RING_API_GETCPOINTER(1,"uv_process_options_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_stdio_container_t)
{
	uv_stdio_container_t *pMyPointer ;
	pMyPointer = (uv_stdio_container_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_stdio_container_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_stdio_container_t");
}

RING_FUNC(ring_new_managed_uv_stdio_container_t)
{
	uv_stdio_container_t *pMyPointer ;
	pMyPointer = (uv_stdio_container_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_stdio_container_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_stdio_container_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_stdio_container_t)
{
	uv_stdio_container_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_stdio_container_t*) RING_API_GETCPOINTER(1,"uv_stdio_container_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_disable_stdio_inheritance)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	uv_disable_stdio_inheritance();
}


RING_FUNC(ring_uv_spawn)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_spawn((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_process_t *) RING_API_GETCPOINTER(2,"uv_process_t"),(uv_process_options_t *) RING_API_GETCPOINTER(3,"uv_process_options_t")));
}


RING_FUNC(ring_uv_process_kill)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_process_kill((uv_process_t *) RING_API_GETCPOINTER(1,"uv_process_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_kill)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_kill( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}

RING_FUNC(ring_new_uv_stream_t)
{
	uv_stream_t *pMyPointer ;
	pMyPointer = (uv_stream_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_stream_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_stream_t");
}

RING_FUNC(ring_new_managed_uv_stream_t)
{
	uv_stream_t *pMyPointer ;
	pMyPointer = (uv_stream_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_stream_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_stream_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_stream_t)
{
	uv_stream_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_stream_t*) RING_API_GETCPOINTER(1,"uv_stream_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_connect_t)
{
	uv_connect_t *pMyPointer ;
	pMyPointer = (uv_connect_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_connect_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_connect_t");
}

RING_FUNC(ring_new_managed_uv_connect_t)
{
	uv_connect_t *pMyPointer ;
	pMyPointer = (uv_connect_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_connect_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_connect_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_connect_t)
{
	uv_connect_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_connect_t*) RING_API_GETCPOINTER(1,"uv_connect_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_connect_t_handle)
{
	uv_connect_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_connect_t");
	RING_API_RETCPOINTER(pMyPointer->handle,"uv_stream_t");
}

RING_FUNC(ring_set_uv_connect_t_handle)
{
	uv_connect_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_connect_t");
	pMyPointer->handle = (uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t");
}

RING_FUNC(ring_new_uv_shutdown_t)
{
	uv_shutdown_t *pMyPointer ;
	pMyPointer = (uv_shutdown_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_shutdown_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_shutdown_t");
}

RING_FUNC(ring_new_managed_uv_shutdown_t)
{
	uv_shutdown_t *pMyPointer ;
	pMyPointer = (uv_shutdown_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_shutdown_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_shutdown_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_shutdown_t)
{
	uv_shutdown_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_shutdown_t*) RING_API_GETCPOINTER(1,"uv_shutdown_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_shutdown_t_handle)
{
	uv_shutdown_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_shutdown_t");
	RING_API_RETCPOINTER(pMyPointer->handle,"uv_stream_t");
}

RING_FUNC(ring_set_uv_shutdown_t_handle)
{
	uv_shutdown_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_shutdown_t");
	pMyPointer->handle = (uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t");
}

RING_FUNC(ring_new_uv_write_t)
{
	uv_write_t *pMyPointer ;
	pMyPointer = (uv_write_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_write_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_write_t");
}

RING_FUNC(ring_new_managed_uv_write_t)
{
	uv_write_t *pMyPointer ;
	pMyPointer = (uv_write_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_write_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_write_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_write_t)
{
	uv_write_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_write_t*) RING_API_GETCPOINTER(1,"uv_write_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_write_t_handle)
{
	uv_write_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_write_t");
	RING_API_RETCPOINTER(pMyPointer->handle,"uv_stream_t");
}

RING_FUNC(ring_set_uv_write_t_handle)
{
	uv_write_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_write_t");
	pMyPointer->handle = (uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t");
}


RING_FUNC(ring_uv_shutdown)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_shutdown((uv_shutdown_t *) RING_API_GETCPOINTER(1,"uv_shutdown_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t"),RING_API_GETCPOINTER(3,"uv_shutdown_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_shutdown_cb"));
}


RING_FUNC(ring_uv_shutdown_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_shutdown((uv_shutdown_t *) RING_API_GETCPOINTER(1,"uv_shutdown_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t"),RING_API_GETCPOINTER(3,"uv_shutdown_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_shutdown_cb"));
}


RING_FUNC(ring_uv_listen)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_listen((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"), (int ) RING_API_GETNUMBER(2),RING_API_GETCPOINTER(3,"uv_connection_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_connection_cb"));
}


RING_FUNC(ring_uv_listen_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_listen((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"), (int ) RING_API_GETNUMBER(2),RING_API_GETCPOINTER(3,"uv_connection_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_connection_cb"));
}


RING_FUNC(ring_uv_accept)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_accept((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t")));
}


RING_FUNC(ring_uv_read_start)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_read_start((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"),RING_API_GETCPOINTER(2,"uv_alloc_cb"),RING_API_GETCPOINTER(3,"uv_read_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_alloc_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_read_cb"));
}


RING_FUNC(ring_uv_read_start_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_read_start((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"),RING_API_GETCPOINTER(2,"uv_alloc_cb"),RING_API_GETCPOINTER(3,"uv_read_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_alloc_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_read_cb"));
}


RING_FUNC(ring_uv_read_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_read_stop((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t")));
}


RING_FUNC(ring_uv_write)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_write((uv_write_t *) RING_API_GETCPOINTER(1,"uv_write_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t"),(uv_buf_t *) RING_API_GETCPOINTER(3,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_write_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_write_cb"));
}


RING_FUNC(ring_uv_write_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_write((uv_write_t *) RING_API_GETCPOINTER(1,"uv_write_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t"),(uv_buf_t *) RING_API_GETCPOINTER(3,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_write_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_write_cb"));
}


RING_FUNC(ring_uv_write2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_write2((uv_write_t *) RING_API_GETCPOINTER(1,"uv_write_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t"),(uv_buf_t *) RING_API_GETCPOINTER(3,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(4),(uv_stream_t *) RING_API_GETCPOINTER(5,"uv_stream_t"),RING_API_GETCPOINTER(6,"uv_write_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_write_cb"));
}


RING_FUNC(ring_uv_write2_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_write2((uv_write_t *) RING_API_GETCPOINTER(1,"uv_write_t"),(uv_stream_t *) RING_API_GETCPOINTER(2,"uv_stream_t"),(uv_buf_t *) RING_API_GETCPOINTER(3,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(4),(uv_stream_t *) RING_API_GETCPOINTER(5,"uv_stream_t"),RING_API_GETCPOINTER(6,"uv_write_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_write_cb"));
}


RING_FUNC(ring_uv_try_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_try_write((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"),(uv_buf_t *) RING_API_GETCPOINTER(2,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_is_readable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_is_readable((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t")));
}


RING_FUNC(ring_uv_is_writable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_is_writable((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t")));
}


RING_FUNC(ring_uv_stream_set_blocking)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_stream_set_blocking((uv_stream_t *) RING_API_GETCPOINTER(1,"uv_stream_t"), (int ) RING_API_GETNUMBER(2)));
}

RING_FUNC(ring_new_uv_tcp_t)
{
	uv_tcp_t *pMyPointer ;
	pMyPointer = (uv_tcp_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_tcp_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_tcp_t");
}

RING_FUNC(ring_new_managed_uv_tcp_t)
{
	uv_tcp_t *pMyPointer ;
	pMyPointer = (uv_tcp_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_tcp_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_tcp_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_tcp_t)
{
	uv_tcp_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_tcp_t*) RING_API_GETCPOINTER(1,"uv_tcp_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_tcp_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_tcp_t *) RING_API_GETCPOINTER(2,"uv_tcp_t")));
}


RING_FUNC(ring_uv_tcp_init_ex)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_init_ex((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_tcp_t *) RING_API_GETCPOINTER(2,"uv_tcp_t"), (unsigned int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_tcp_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_open((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"),* (uv_os_sock_t  *) RING_API_GETCPOINTER(2,"uv_os_sock_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_os_sock_t"));
}


RING_FUNC(ring_uv_tcp_nodelay)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_nodelay((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_tcp_keepalive)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_keepalive((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"), (int ) RING_API_GETNUMBER(2), (unsigned int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_tcp_simultaneous_accepts)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_simultaneous_accepts((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_tcp_bind)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_bind((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"),(sockaddr *) RING_API_GETCPOINTER(2,"sockaddr"), (unsigned int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_tcp_getsockname)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_getsockname((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"),(struct sockaddr *) RING_API_GETCPOINTER(2,"struct sockaddr"),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_uv_tcp_getpeername)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_getpeername((uv_tcp_t *) RING_API_GETCPOINTER(1,"uv_tcp_t"),(struct sockaddr *) RING_API_GETCPOINTER(2,"struct sockaddr"),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_uv_tcp_connect)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_connect((uv_connect_t *) RING_API_GETCPOINTER(1,"uv_connect_t"),(uv_tcp_t *) RING_API_GETCPOINTER(2,"uv_tcp_t"),(sockaddr *) RING_API_GETCPOINTER(3,"sockaddr"),RING_API_GETCPOINTER(4,"uv_connect_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_connect_cb"));
}


RING_FUNC(ring_uv_tcp_connect_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tcp_connect((uv_connect_t *) RING_API_GETCPOINTER(1,"uv_connect_t"),(uv_tcp_t *) RING_API_GETCPOINTER(2,"uv_tcp_t"),(sockaddr *) RING_API_GETCPOINTER(3,"sockaddr"),RING_API_GETCPOINTER(4,"uv_connect_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_connect_cb"));
}

RING_FUNC(ring_new_uv_pipe_t)
{
	uv_pipe_t *pMyPointer ;
	pMyPointer = (uv_pipe_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_pipe_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_pipe_t");
}

RING_FUNC(ring_new_managed_uv_pipe_t)
{
	uv_pipe_t *pMyPointer ;
	pMyPointer = (uv_pipe_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_pipe_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_pipe_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_pipe_t)
{
	uv_pipe_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_pipe_t*) RING_API_GETCPOINTER(1,"uv_pipe_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_pipe_init)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_pipe_t *) RING_API_GETCPOINTER(2,"uv_pipe_t"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_pipe_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_open((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t"),* (uv_file  *) RING_API_GETCPOINTER(2,"uv_file")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_file"));
}


RING_FUNC(ring_uv_pipe_bind)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_bind((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_uv_pipe_connect)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_pipe_connect((uv_connect_t *) RING_API_GETCPOINTER(1,"uv_connect_t"),(uv_pipe_t *) RING_API_GETCPOINTER(2,"uv_pipe_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_connect_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_connect_cb"));
}


RING_FUNC(ring_uv_pipe_connect_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_pipe_connect((uv_connect_t *) RING_API_GETCPOINTER(1,"uv_connect_t"),(uv_pipe_t *) RING_API_GETCPOINTER(2,"uv_pipe_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_connect_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_connect_cb"));
}


RING_FUNC(ring_uv_pipe_getsockname)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_getsockname((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t"),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}


RING_FUNC(ring_uv_pipe_getpeername)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_getpeername((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t"),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}


RING_FUNC(ring_uv_pipe_pending_instances)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_pipe_pending_instances((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uv_pipe_pending_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_pending_count((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t")));
}


RING_FUNC(ring_uv_pipe_pending_type)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_pending_type((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t")));
}


RING_FUNC(ring_uv_pipe_chmod)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_pipe_chmod((uv_pipe_t *) RING_API_GETCPOINTER(1,"uv_pipe_t"), (int ) RING_API_GETNUMBER(2)));
}

RING_FUNC(ring_new_uv_tty_t)
{
	uv_tty_t *pMyPointer ;
	pMyPointer = (uv_tty_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_tty_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_tty_t");
}

RING_FUNC(ring_new_managed_uv_tty_t)
{
	uv_tty_t *pMyPointer ;
	pMyPointer = (uv_tty_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_tty_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_tty_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_tty_t)
{
	uv_tty_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_tty_t*) RING_API_GETCPOINTER(1,"uv_tty_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_tty_init)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tty_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_tty_t *) RING_API_GETCPOINTER(2,"uv_tty_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
}


RING_FUNC(ring_uv_tty_set_mode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tty_set_mode((uv_tty_t *) RING_API_GETCPOINTER(1,"uv_tty_t"), (uv_tty_mode_t )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_tty_reset_mode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_tty_reset_mode());
}


RING_FUNC(ring_uv_tty_get_winsize)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_tty_get_winsize((uv_tty_t *) RING_API_GETCPOINTER(1,"uv_tty_t"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}

RING_FUNC(ring_new_uv_udp_t)
{
	uv_udp_t *pMyPointer ;
	pMyPointer = (uv_udp_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_udp_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_udp_t");
}

RING_FUNC(ring_new_managed_uv_udp_t)
{
	uv_udp_t *pMyPointer ;
	pMyPointer = (uv_udp_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_udp_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_udp_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_udp_t)
{
	uv_udp_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_udp_t*) RING_API_GETCPOINTER(1,"uv_udp_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_udp_t_send_queue_size)
{
	uv_udp_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_udp_t");
	RING_API_RETNUMBER(pMyPointer->send_queue_size);
}

RING_FUNC(ring_set_uv_udp_t_send_queue_size)
{
	uv_udp_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_udp_t");
	pMyPointer->send_queue_size = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uv_udp_t_send_queue_count)
{
	uv_udp_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_udp_t");
	RING_API_RETNUMBER(pMyPointer->send_queue_count);
}

RING_FUNC(ring_set_uv_udp_t_send_queue_count)
{
	uv_udp_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_udp_t");
	pMyPointer->send_queue_count = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uv_udp_send_t)
{
	uv_udp_send_t *pMyPointer ;
	pMyPointer = (uv_udp_send_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_udp_send_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_udp_send_t");
}

RING_FUNC(ring_new_managed_uv_udp_send_t)
{
	uv_udp_send_t *pMyPointer ;
	pMyPointer = (uv_udp_send_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_udp_send_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_udp_send_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_udp_send_t)
{
	uv_udp_send_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_udp_send_t*) RING_API_GETCPOINTER(1,"uv_udp_send_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_udp_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_udp_t *) RING_API_GETCPOINTER(2,"uv_udp_t")));
}


RING_FUNC(ring_uv_udp_init_ex)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_init_ex((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_udp_t *) RING_API_GETCPOINTER(2,"uv_udp_t"), (unsigned int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_udp_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_open((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),* (uv_os_sock_t  *) RING_API_GETCPOINTER(2,"uv_os_sock_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_os_sock_t"));
}


RING_FUNC(ring_uv_udp_bind)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_bind((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),(sockaddr *) RING_API_GETCPOINTER(2,"sockaddr"), (unsigned int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_udp_getsockname)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_getsockname((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),(struct sockaddr *) RING_API_GETCPOINTER(2,"struct sockaddr"),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_uv_udp_set_membership)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
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
	RING_API_RETNUMBER(uv_udp_set_membership((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (uv_membership )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_uv_udp_set_multicast_loop)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_set_multicast_loop((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_udp_set_multicast_ttl)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_set_multicast_ttl((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_udp_set_multicast_interface)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_set_multicast_interface((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_uv_udp_set_broadcast)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_set_broadcast((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_udp_set_ttl)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_set_ttl((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_udp_send)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_send((uv_udp_send_t *) RING_API_GETCPOINTER(1,"uv_udp_send_t"),(uv_udp_t *) RING_API_GETCPOINTER(2,"uv_udp_t"),(uv_buf_t *) RING_API_GETCPOINTER(3,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(4),(sockaddr *) RING_API_GETCPOINTER(5,"sockaddr"),RING_API_GETCPOINTER(6,"uv_udp_send_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_udp_send_cb"));
}


RING_FUNC(ring_uv_udp_send_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_send((uv_udp_send_t *) RING_API_GETCPOINTER(1,"uv_udp_send_t"),(uv_udp_t *) RING_API_GETCPOINTER(2,"uv_udp_t"),(uv_buf_t *) RING_API_GETCPOINTER(3,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(4),(sockaddr *) RING_API_GETCPOINTER(5,"sockaddr"),RING_API_GETCPOINTER(6,"uv_udp_send_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_udp_send_cb"));
}


RING_FUNC(ring_uv_udp_try_send)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_try_send((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),(uv_buf_t *) RING_API_GETCPOINTER(2,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(3),(sockaddr *) RING_API_GETCPOINTER(4,"sockaddr")));
}


RING_FUNC(ring_uv_udp_recv_start)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_recv_start((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),RING_API_GETCPOINTER(2,"uv_alloc_cb"),RING_API_GETCPOINTER(3,"uv_udp_recv_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_alloc_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_udp_recv_cb"));
}


RING_FUNC(ring_uv_udp_recv_start_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_recv_start((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t"),RING_API_GETCPOINTER(2,"uv_alloc_cb"),RING_API_GETCPOINTER(3,"uv_udp_recv_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_alloc_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_udp_recv_cb"));
}


RING_FUNC(ring_uv_udp_recv_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_udp_recv_stop((uv_udp_t *) RING_API_GETCPOINTER(1,"uv_udp_t")));
}

RING_FUNC(ring_new_uv_fs_event_t)
{
	uv_fs_event_t *pMyPointer ;
	pMyPointer = (uv_fs_event_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_fs_event_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_fs_event_t");
}

RING_FUNC(ring_new_managed_uv_fs_event_t)
{
	uv_fs_event_t *pMyPointer ;
	pMyPointer = (uv_fs_event_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_fs_event_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_fs_event_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_fs_event_t)
{
	uv_fs_event_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_fs_event_t*) RING_API_GETCPOINTER(1,"uv_fs_event_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_fs_event_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_event_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_event_t *) RING_API_GETCPOINTER(2,"uv_fs_event_t")));
}


RING_FUNC(ring_uv_fs_event_start)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(uv_fs_event_start((uv_fs_event_t *) RING_API_GETCPOINTER(1,"uv_fs_event_t"),RING_API_GETCPOINTER(2,"uv_fs_event_cb"),RING_API_GETSTRING(3), (unsigned int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_fs_event_cb"));
}


RING_FUNC(ring_uv_fs_event_start_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(uv_fs_event_start((uv_fs_event_t *) RING_API_GETCPOINTER(1,"uv_fs_event_t"),RING_API_GETCPOINTER(2,"uv_fs_event_cb"),RING_API_GETSTRING(3), (unsigned int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_fs_event_cb"));
}


RING_FUNC(ring_uv_fs_event_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_event_stop((uv_fs_event_t *) RING_API_GETCPOINTER(1,"uv_fs_event_t")));
}


RING_FUNC(ring_uv_fs_event_getpath)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_event_getpath((uv_fs_event_t *) RING_API_GETCPOINTER(1,"uv_fs_event_t"),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}

RING_FUNC(ring_new_uv_fs_poll_t)
{
	uv_fs_poll_t *pMyPointer ;
	pMyPointer = (uv_fs_poll_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_fs_poll_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_fs_poll_t");
}

RING_FUNC(ring_new_managed_uv_fs_poll_t)
{
	uv_fs_poll_t *pMyPointer ;
	pMyPointer = (uv_fs_poll_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_fs_poll_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_fs_poll_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_fs_poll_t)
{
	uv_fs_poll_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_fs_poll_t*) RING_API_GETCPOINTER(1,"uv_fs_poll_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_fs_poll_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_poll_init((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_poll_t *) RING_API_GETCPOINTER(2,"uv_fs_poll_t")));
}


RING_FUNC(ring_uv_fs_poll_start)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(uv_fs_poll_start((uv_fs_poll_t *) RING_API_GETCPOINTER(1,"uv_fs_poll_t"),RING_API_GETCPOINTER(2,"uv_fs_poll_cb"),RING_API_GETSTRING(3), (unsigned int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_fs_poll_cb"));
}


RING_FUNC(ring_uv_fs_poll_start_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(uv_fs_poll_start((uv_fs_poll_t *) RING_API_GETCPOINTER(1,"uv_fs_poll_t"),RING_API_GETCPOINTER(2,"uv_fs_poll_cb"),RING_API_GETSTRING(3), (unsigned int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_fs_poll_cb"));
}


RING_FUNC(ring_uv_fs_poll_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_poll_stop((uv_fs_poll_t *) RING_API_GETCPOINTER(1,"uv_fs_poll_t")));
}


RING_FUNC(ring_uv_fs_poll_getpath)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_poll_getpath((uv_fs_poll_t *) RING_API_GETCPOINTER(1,"uv_fs_poll_t"),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}

RING_FUNC(ring_new_uv_fs_t)
{
	uv_fs_t *pMyPointer ;
	pMyPointer = (uv_fs_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_fs_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_fs_t");
}

RING_FUNC(ring_new_managed_uv_fs_t)
{
	uv_fs_t *pMyPointer ;
	pMyPointer = (uv_fs_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_fs_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_fs_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_fs_t)
{
	uv_fs_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_fs_t*) RING_API_GETCPOINTER(1,"uv_fs_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_timespec_t)
{
	uv_timespec_t *pMyPointer ;
	pMyPointer = (uv_timespec_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_timespec_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_timespec_t");
}

RING_FUNC(ring_new_managed_uv_timespec_t)
{
	uv_timespec_t *pMyPointer ;
	pMyPointer = (uv_timespec_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_timespec_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_timespec_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_timespec_t)
{
	uv_timespec_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_timespec_t*) RING_API_GETCPOINTER(1,"uv_timespec_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_stat_t)
{
	uv_stat_t *pMyPointer ;
	pMyPointer = (uv_stat_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_stat_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_stat_t");
}

RING_FUNC(ring_new_managed_uv_stat_t)
{
	uv_stat_t *pMyPointer ;
	pMyPointer = (uv_stat_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_stat_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_stat_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_stat_t)
{
	uv_stat_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_stat_t*) RING_API_GETCPOINTER(1,"uv_stat_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_fs_req_cleanup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_fs_req_cleanup((uv_fs_t *) RING_API_GETCPOINTER(1,"uv_fs_t"));
}


RING_FUNC(ring_uv_fs_close)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_close((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_open)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_open((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_read)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_read((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),(uv_buf_t *) RING_API_GETCPOINTER(4,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(5), (int64_t ) RING_API_GETNUMBER(6),RING_API_GETCPOINTER(7,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_unlink)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_unlink((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_write)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_write((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),(uv_buf_t *) RING_API_GETCPOINTER(4,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(5), (int64_t ) RING_API_GETNUMBER(6),RING_API_GETCPOINTER(7,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_mkdir)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_mkdir((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_mkdtemp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_mkdtemp((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_rmdir)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_rmdir((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_scandir)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_scandir((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_scandir_next)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_scandir_next((uv_fs_t *) RING_API_GETCPOINTER(1,"uv_fs_t"),(uv_dirent_t *) RING_API_GETCPOINTER(2,"uv_dirent_t")));
}


RING_FUNC(ring_uv_fs_stat)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_stat((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fstat)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fstat((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_lstat)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_lstat((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_rename)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_rename((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fsync)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fsync((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fdatasync)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fdatasync((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_ftruncate)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_ftruncate((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (int64_t ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_copyfile)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_copyfile((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_sendfile)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_sendfile((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),* (uv_file  *) RING_API_GETCPOINTER(4,"uv_file"), (int64_t ) RING_API_GETNUMBER(5), (size_t ) RING_API_GETNUMBER(6),RING_API_GETCPOINTER(7,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_access)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_access((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_chmod)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_chmod((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fchmod)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fchmod((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_utime)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_utime((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_futime)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_futime((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_link)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_link((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_symlink)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_symlink((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_readlink)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_readlink((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_realpath)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_realpath((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_chown)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_chown((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),* (uv_uid_t  *) RING_API_GETCPOINTER(4,"uv_uid_t"),* (uv_gid_t  *) RING_API_GETCPOINTER(5,"uv_gid_t"),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_uid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_gid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fchown)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fchown((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),* (uv_uid_t  *) RING_API_GETCPOINTER(4,"uv_uid_t"),* (uv_gid_t  *) RING_API_GETCPOINTER(5,"uv_gid_t"),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_uid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_gid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_close_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_close((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_open_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_open((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_read_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_read((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),(uv_buf_t *) RING_API_GETCPOINTER(4,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(5), (int64_t ) RING_API_GETNUMBER(6),RING_API_GETCPOINTER(7,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_unlink_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_unlink((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_write_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_write((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),(uv_buf_t *) RING_API_GETCPOINTER(4,"uv_buf_t"), (unsigned int ) RING_API_GETNUMBER(5), (int64_t ) RING_API_GETNUMBER(6),RING_API_GETCPOINTER(7,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_mkdir_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_mkdir((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_mkdtemp_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_mkdtemp((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_rmdir_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_rmdir((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_scandir_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_scandir((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_stat_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_stat((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fstat_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fstat((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_lstat_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_lstat((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_rename_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_rename((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fsync_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fsync((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fdatasync_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fdatasync((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_ftruncate_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_ftruncate((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (int64_t ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_copyfile_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_copyfile((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_sendfile_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_sendfile((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),* (uv_file  *) RING_API_GETCPOINTER(4,"uv_file"), (int64_t ) RING_API_GETNUMBER(5), (size_t ) RING_API_GETNUMBER(6),RING_API_GETCPOINTER(7,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_access_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_access((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_chmod_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(uv_fs_chmod((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fchmod_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fchmod((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (int ) RING_API_GETNUMBER(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_utime_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_utime((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_futime_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_futime((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_link_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_link((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETCPOINTER(5,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_symlink_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_symlink((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_readlink_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_readlink((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_realpath_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_realpath((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),RING_API_GETCPOINTER(4,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_chown_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_chown((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),RING_API_GETSTRING(3),* (uv_uid_t  *) RING_API_GETCPOINTER(4,"uv_uid_t"),* (uv_gid_t  *) RING_API_GETCPOINTER(5,"uv_gid_t"),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_uid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_gid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_fs_fchown_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_fs_fchown((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_fs_t *) RING_API_GETCPOINTER(2,"uv_fs_t"),* (uv_file  *) RING_API_GETCPOINTER(3,"uv_file"),* (uv_uid_t  *) RING_API_GETCPOINTER(4,"uv_uid_t"),* (uv_gid_t  *) RING_API_GETCPOINTER(5,"uv_gid_t"),RING_API_GETCPOINTER(6,"uv_fs_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_file"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_uid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"uv_gid_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"uv_fs_cb"));
}


RING_FUNC(ring_uv_get_osfhandle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		uv_os_fd_t *pValue ; 
		pValue = (uv_os_fd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_os_fd_t)) ;
		*pValue = uv_get_osfhandle( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"uv_os_fd_t",ring_state_free);
	}
}

RING_FUNC(ring_new_uv_work_t)
{
	uv_work_t *pMyPointer ;
	pMyPointer = (uv_work_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_work_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_work_t");
}

RING_FUNC(ring_new_managed_uv_work_t)
{
	uv_work_t *pMyPointer ;
	pMyPointer = (uv_work_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_work_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_work_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_work_t)
{
	uv_work_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_work_t*) RING_API_GETCPOINTER(1,"uv_work_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_queue_work)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_queue_work((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_work_t *) RING_API_GETCPOINTER(2,"uv_work_t"),RING_API_GETCPOINTER(3,"uv_work_cb"),RING_API_GETCPOINTER(4,"uv_after_work_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_work_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_after_work_cb"));
}


RING_FUNC(ring_uv_queue_work_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_queue_work((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_work_t *) RING_API_GETCPOINTER(2,"uv_work_t"),RING_API_GETCPOINTER(3,"uv_work_cb"),RING_API_GETCPOINTER(4,"uv_after_work_cb")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_work_cb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_after_work_cb"));
}

RING_FUNC(ring_new_uv_getaddrinfo_t)
{
	uv_getaddrinfo_t *pMyPointer ;
	pMyPointer = (uv_getaddrinfo_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_getaddrinfo_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_getaddrinfo_t");
}

RING_FUNC(ring_new_managed_uv_getaddrinfo_t)
{
	uv_getaddrinfo_t *pMyPointer ;
	pMyPointer = (uv_getaddrinfo_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_getaddrinfo_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_getaddrinfo_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_getaddrinfo_t)
{
	uv_getaddrinfo_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_getaddrinfo_t*) RING_API_GETCPOINTER(1,"uv_getaddrinfo_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_getnameinfo_t)
{
	uv_getnameinfo_t *pMyPointer ;
	pMyPointer = (uv_getnameinfo_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_getnameinfo_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_getnameinfo_t");
}

RING_FUNC(ring_new_managed_uv_getnameinfo_t)
{
	uv_getnameinfo_t *pMyPointer ;
	pMyPointer = (uv_getnameinfo_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_getnameinfo_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_getnameinfo_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_getnameinfo_t)
{
	uv_getnameinfo_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_getnameinfo_t*) RING_API_GETCPOINTER(1,"uv_getnameinfo_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_getaddrinfo)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_getaddrinfo((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_getaddrinfo_t *) RING_API_GETCPOINTER(2,"uv_getaddrinfo_t"),RING_API_GETCPOINTER(3,"uv_getaddrinfo_cb"),RING_API_GETSTRING(4),RING_API_GETSTRING(5),(struct addrinfo *) RING_API_GETCPOINTER(6,"struct addrinfo")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_getaddrinfo_cb"));
}


RING_FUNC(ring_uv_getaddrinfo_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_getaddrinfo((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_getaddrinfo_t *) RING_API_GETCPOINTER(2,"uv_getaddrinfo_t"),RING_API_GETCPOINTER(3,"uv_getaddrinfo_cb"),RING_API_GETSTRING(4),RING_API_GETSTRING(5),(struct addrinfo *) RING_API_GETCPOINTER(6,"struct addrinfo")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_getaddrinfo_cb"));
}


RING_FUNC(ring_uv_freeaddrinfo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_freeaddrinfo((struct addrinfo *) RING_API_GETCPOINTER(1,"struct addrinfo"));
}


RING_FUNC(ring_uv_getnameinfo)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_getnameinfo((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_getnameinfo_t *) RING_API_GETCPOINTER(2,"uv_getnameinfo_t"),RING_API_GETCPOINTER(3,"uv_getnameinfo_cb"),(sockaddr *) RING_API_GETCPOINTER(4,"sockaddr"), (int ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_getnameinfo_cb"));
}


RING_FUNC(ring_uv_getnameinfo_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_getnameinfo((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(uv_getnameinfo_t *) RING_API_GETCPOINTER(2,"uv_getnameinfo_t"),RING_API_GETCPOINTER(3,"uv_getnameinfo_cb"),(sockaddr *) RING_API_GETCPOINTER(4,"sockaddr"), (int ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_getnameinfo_cb"));
}

RING_FUNC(ring_new_uv_lib_t)
{
	uv_lib_t *pMyPointer ;
	pMyPointer = (uv_lib_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_lib_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_lib_t");
}

RING_FUNC(ring_new_managed_uv_lib_t)
{
	uv_lib_t *pMyPointer ;
	pMyPointer = (uv_lib_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_lib_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_lib_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_lib_t)
{
	uv_lib_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_lib_t*) RING_API_GETCPOINTER(1,"uv_lib_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_dlopen)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_dlopen(RING_API_GETSTRING(1),(uv_lib_t *) RING_API_GETCPOINTER(2,"uv_lib_t")));
}


RING_FUNC(ring_uv_dlclose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_dlclose((uv_lib_t *) RING_API_GETCPOINTER(1,"uv_lib_t"));
}


RING_FUNC(ring_uv_dlsym)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_dlsym((uv_lib_t *) RING_API_GETCPOINTER(1,"uv_lib_t"),RING_API_GETSTRING(2),(void **) RING_API_GETCPOINTER2POINTER(3,"void")));
}


RING_FUNC(ring_uv_dlerror)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uv_dlerror((uv_lib_t *) RING_API_GETCPOINTER(1,"uv_lib_t")));
}

RING_FUNC(ring_new_uv_thread_t)
{
	uv_thread_t *pMyPointer ;
	pMyPointer = (uv_thread_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_thread_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_thread_t");
}

RING_FUNC(ring_new_managed_uv_thread_t)
{
	uv_thread_t *pMyPointer ;
	pMyPointer = (uv_thread_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_thread_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_thread_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_thread_t)
{
	uv_thread_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_thread_t*) RING_API_GETCPOINTER(1,"uv_thread_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_key_t)
{
	uv_key_t *pMyPointer ;
	pMyPointer = (uv_key_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_key_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_key_t");
}

RING_FUNC(ring_new_managed_uv_key_t)
{
	uv_key_t *pMyPointer ;
	pMyPointer = (uv_key_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_key_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_key_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_key_t)
{
	uv_key_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_key_t*) RING_API_GETCPOINTER(1,"uv_key_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_once_t)
{
	uv_once_t *pMyPointer ;
	pMyPointer = (uv_once_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_once_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_once_t");
}

RING_FUNC(ring_new_managed_uv_once_t)
{
	uv_once_t *pMyPointer ;
	pMyPointer = (uv_once_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_once_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_once_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_once_t)
{
	uv_once_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_once_t*) RING_API_GETCPOINTER(1,"uv_once_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_mutex_t)
{
	uv_mutex_t *pMyPointer ;
	pMyPointer = (uv_mutex_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_mutex_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_mutex_t");
}

RING_FUNC(ring_new_managed_uv_mutex_t)
{
	uv_mutex_t *pMyPointer ;
	pMyPointer = (uv_mutex_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_mutex_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_mutex_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_mutex_t)
{
	uv_mutex_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_mutex_t*) RING_API_GETCPOINTER(1,"uv_mutex_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_rwlock_t)
{
	uv_rwlock_t *pMyPointer ;
	pMyPointer = (uv_rwlock_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_rwlock_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_rwlock_t");
}

RING_FUNC(ring_new_managed_uv_rwlock_t)
{
	uv_rwlock_t *pMyPointer ;
	pMyPointer = (uv_rwlock_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_rwlock_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_rwlock_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_rwlock_t)
{
	uv_rwlock_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_rwlock_t*) RING_API_GETCPOINTER(1,"uv_rwlock_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_sem_t)
{
	uv_sem_t *pMyPointer ;
	pMyPointer = (uv_sem_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_sem_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_sem_t");
}

RING_FUNC(ring_new_managed_uv_sem_t)
{
	uv_sem_t *pMyPointer ;
	pMyPointer = (uv_sem_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_sem_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_sem_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_sem_t)
{
	uv_sem_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_sem_t*) RING_API_GETCPOINTER(1,"uv_sem_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_cond_t)
{
	uv_cond_t *pMyPointer ;
	pMyPointer = (uv_cond_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_cond_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_cond_t");
}

RING_FUNC(ring_new_managed_uv_cond_t)
{
	uv_cond_t *pMyPointer ;
	pMyPointer = (uv_cond_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_cond_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_cond_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_cond_t)
{
	uv_cond_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_cond_t*) RING_API_GETCPOINTER(1,"uv_cond_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_barrier_t)
{
	uv_barrier_t *pMyPointer ;
	pMyPointer = (uv_barrier_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_barrier_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_barrier_t");
}

RING_FUNC(ring_new_managed_uv_barrier_t)
{
	uv_barrier_t *pMyPointer ;
	pMyPointer = (uv_barrier_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_barrier_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_barrier_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_barrier_t)
{
	uv_barrier_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_barrier_t*) RING_API_GETCPOINTER(1,"uv_barrier_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_uv_thread_create)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_thread_create((uv_thread_t *) RING_API_GETCPOINTER(1,"uv_thread_t"),RING_API_GETCPOINTER(2,"uv_thread_cb"),(void *) RING_API_GETCPOINTER(3,"void")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_thread_cb"));
}


RING_FUNC(ring_uv_thread_create_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_thread_create((uv_thread_t *) RING_API_GETCPOINTER(1,"uv_thread_t"),RING_API_GETCPOINTER(2,"uv_thread_cb"),(void *) RING_API_GETCPOINTER(3,"void")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_thread_cb"));
}

RING_FUNC(ring_uv_thread_self)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		uv_thread_t *pValue ; 
		pValue = (uv_thread_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_thread_t)) ;
		*pValue = uv_thread_self();
		RING_API_RETMANAGEDCPOINTER(pValue,"uv_thread_t",ring_state_free);
	}
}


RING_FUNC(ring_uv_thread_join)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_thread_join((uv_thread_t *) RING_API_GETCPOINTER(1,"uv_thread_t")));
}


RING_FUNC(ring_uv_thread_equal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_thread_equal((uv_thread_t *) RING_API_GETCPOINTER(1,"uv_thread_t"),(uv_thread_t *) RING_API_GETCPOINTER(2,"uv_thread_t")));
}


RING_FUNC(ring_uv_key_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_key_create((uv_key_t *) RING_API_GETCPOINTER(1,"uv_key_t")));
}


RING_FUNC(ring_uv_key_delete)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_key_delete((uv_key_t *) RING_API_GETCPOINTER(1,"uv_key_t"));
}


RING_FUNC(ring_uv_key_get)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uv_key_get((uv_key_t *) RING_API_GETCPOINTER(1,"uv_key_t")),"void");
}


RING_FUNC(ring_uv_key_set)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_key_set((uv_key_t *) RING_API_GETCPOINTER(1,"uv_key_t"),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_uv_mutex_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_mutex_init((uv_mutex_t *) RING_API_GETCPOINTER(1,"uv_mutex_t")));
}


RING_FUNC(ring_uv_mutex_init_recursive)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_mutex_init_recursive((uv_mutex_t *) RING_API_GETCPOINTER(1,"uv_mutex_t")));
}


RING_FUNC(ring_uv_mutex_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_mutex_destroy((uv_mutex_t *) RING_API_GETCPOINTER(1,"uv_mutex_t"));
}


RING_FUNC(ring_uv_mutex_lock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_mutex_lock((uv_mutex_t *) RING_API_GETCPOINTER(1,"uv_mutex_t"));
}


RING_FUNC(ring_uv_mutex_trylock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_mutex_trylock((uv_mutex_t *) RING_API_GETCPOINTER(1,"uv_mutex_t")));
}


RING_FUNC(ring_uv_mutex_unlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_mutex_unlock((uv_mutex_t *) RING_API_GETCPOINTER(1,"uv_mutex_t"));
}


RING_FUNC(ring_uv_rwlock_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_rwlock_init((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t")));
}


RING_FUNC(ring_uv_rwlock_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_rwlock_destroy((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t"));
}


RING_FUNC(ring_uv_rwlock_rdlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_rwlock_rdlock((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t"));
}


RING_FUNC(ring_uv_rwlock_tryrdlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_rwlock_tryrdlock((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t")));
}


RING_FUNC(ring_uv_rwlock_rdunlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_rwlock_rdunlock((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t"));
}


RING_FUNC(ring_uv_rwlock_wrlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_rwlock_wrlock((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t"));
}


RING_FUNC(ring_uv_rwlock_trywrlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_rwlock_trywrlock((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t")));
}


RING_FUNC(ring_uv_rwlock_wrunlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_rwlock_wrunlock((uv_rwlock_t *) RING_API_GETCPOINTER(1,"uv_rwlock_t"));
}


RING_FUNC(ring_uv_sem_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_sem_init((uv_sem_t *) RING_API_GETCPOINTER(1,"uv_sem_t"), (unsigned int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_sem_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_sem_destroy((uv_sem_t *) RING_API_GETCPOINTER(1,"uv_sem_t"));
}


RING_FUNC(ring_uv_sem_post)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_sem_post((uv_sem_t *) RING_API_GETCPOINTER(1,"uv_sem_t"));
}


RING_FUNC(ring_uv_sem_wait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_sem_wait((uv_sem_t *) RING_API_GETCPOINTER(1,"uv_sem_t"));
}


RING_FUNC(ring_uv_sem_trywait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_sem_trywait((uv_sem_t *) RING_API_GETCPOINTER(1,"uv_sem_t")));
}


RING_FUNC(ring_uv_cond_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_cond_init((uv_cond_t *) RING_API_GETCPOINTER(1,"uv_cond_t")));
}


RING_FUNC(ring_uv_cond_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_cond_destroy((uv_cond_t *) RING_API_GETCPOINTER(1,"uv_cond_t"));
}


RING_FUNC(ring_uv_cond_signal)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_cond_signal((uv_cond_t *) RING_API_GETCPOINTER(1,"uv_cond_t"));
}


RING_FUNC(ring_uv_cond_broadcast)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_cond_broadcast((uv_cond_t *) RING_API_GETCPOINTER(1,"uv_cond_t"));
}


RING_FUNC(ring_uv_cond_wait)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_cond_wait((uv_cond_t *) RING_API_GETCPOINTER(1,"uv_cond_t"),(uv_mutex_t *) RING_API_GETCPOINTER(2,"uv_mutex_t"));
}


RING_FUNC(ring_uv_cond_timedwait)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_cond_timedwait((uv_cond_t *) RING_API_GETCPOINTER(1,"uv_cond_t"),(uv_mutex_t *) RING_API_GETCPOINTER(2,"uv_mutex_t"), (uint64_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_barrier_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_barrier_init((uv_barrier_t *) RING_API_GETCPOINTER(1,"uv_barrier_t"), (unsigned int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_barrier_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_barrier_destroy((uv_barrier_t *) RING_API_GETCPOINTER(1,"uv_barrier_t"));
}


RING_FUNC(ring_uv_barrier_wait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_barrier_wait((uv_barrier_t *) RING_API_GETCPOINTER(1,"uv_barrier_t")));
}

RING_FUNC(ring_new_uv_buf_t)
{
	uv_buf_t *pMyPointer ;
	pMyPointer = (uv_buf_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_buf_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_buf_t");
}

RING_FUNC(ring_new_managed_uv_buf_t)
{
	uv_buf_t *pMyPointer ;
	pMyPointer = (uv_buf_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_buf_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_buf_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_buf_t)
{
	uv_buf_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_buf_t*) RING_API_GETCPOINTER(1,"uv_buf_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uv_buf_t_base)
{
	uv_buf_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_buf_t");
	RING_API_RETCPOINTER(pMyPointer->base,"char");
}

RING_FUNC(ring_set_uv_buf_t_base)
{
	uv_buf_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_buf_t");
	pMyPointer->base = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_uv_buf_t_len)
{
	uv_buf_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uv_buf_t");
	RING_API_RETNUMBER(pMyPointer->len);
}

RING_FUNC(ring_set_uv_buf_t_len)
{
	uv_buf_t *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uv_buf_t");
	pMyPointer->len = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uv_file)
{
	uv_file *pMyPointer ;
	pMyPointer = (uv_file *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_file)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_file");
}

RING_FUNC(ring_new_managed_uv_file)
{
	uv_file *pMyPointer ;
	pMyPointer = (uv_file *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_file)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_file",ring_state_free);
}

RING_FUNC(ring_destroy_uv_file)
{
	uv_file *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_file*) RING_API_GETCPOINTER(1,"uv_file");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_os_sock_t)
{
	uv_os_sock_t *pMyPointer ;
	pMyPointer = (uv_os_sock_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_os_sock_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_os_sock_t");
}

RING_FUNC(ring_new_managed_uv_os_sock_t)
{
	uv_os_sock_t *pMyPointer ;
	pMyPointer = (uv_os_sock_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_os_sock_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_os_sock_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_os_sock_t)
{
	uv_os_sock_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_os_sock_t*) RING_API_GETCPOINTER(1,"uv_os_sock_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_os_fd_t)
{
	uv_os_fd_t *pMyPointer ;
	pMyPointer = (uv_os_fd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_os_fd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_os_fd_t");
}

RING_FUNC(ring_new_managed_uv_os_fd_t)
{
	uv_os_fd_t *pMyPointer ;
	pMyPointer = (uv_os_fd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_os_fd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_os_fd_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_os_fd_t)
{
	uv_os_fd_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_os_fd_t*) RING_API_GETCPOINTER(1,"uv_os_fd_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_pid_t)
{
	uv_pid_t *pMyPointer ;
	pMyPointer = (uv_pid_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_pid_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_pid_t");
}

RING_FUNC(ring_new_managed_uv_pid_t)
{
	uv_pid_t *pMyPointer ;
	pMyPointer = (uv_pid_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_pid_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_pid_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_pid_t)
{
	uv_pid_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_pid_t*) RING_API_GETCPOINTER(1,"uv_pid_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_rusage_t)
{
	uv_rusage_t *pMyPointer ;
	pMyPointer = (uv_rusage_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_rusage_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_rusage_t");
}

RING_FUNC(ring_new_managed_uv_rusage_t)
{
	uv_rusage_t *pMyPointer ;
	pMyPointer = (uv_rusage_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_rusage_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_rusage_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_rusage_t)
{
	uv_rusage_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_rusage_t*) RING_API_GETCPOINTER(1,"uv_rusage_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_cpu_info_t)
{
	uv_cpu_info_t *pMyPointer ;
	pMyPointer = (uv_cpu_info_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_cpu_info_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_cpu_info_t");
}

RING_FUNC(ring_new_managed_uv_cpu_info_t)
{
	uv_cpu_info_t *pMyPointer ;
	pMyPointer = (uv_cpu_info_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_cpu_info_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_cpu_info_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_cpu_info_t)
{
	uv_cpu_info_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_cpu_info_t*) RING_API_GETCPOINTER(1,"uv_cpu_info_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_interface_address_t)
{
	uv_interface_address_t *pMyPointer ;
	pMyPointer = (uv_interface_address_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_interface_address_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_interface_address_t");
}

RING_FUNC(ring_new_managed_uv_interface_address_t)
{
	uv_interface_address_t *pMyPointer ;
	pMyPointer = (uv_interface_address_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_interface_address_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_interface_address_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_interface_address_t)
{
	uv_interface_address_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_interface_address_t*) RING_API_GETCPOINTER(1,"uv_interface_address_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uv_passwd_t)
{
	uv_passwd_t *pMyPointer ;
	pMyPointer = (uv_passwd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_passwd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uv_passwd_t");
}

RING_FUNC(ring_new_managed_uv_passwd_t)
{
	uv_passwd_t *pMyPointer ;
	pMyPointer = (uv_passwd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_passwd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uv_passwd_t",ring_state_free);
}

RING_FUNC(ring_destroy_uv_passwd_t)
{
	uv_passwd_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uv_passwd_t*) RING_API_GETCPOINTER(1,"uv_passwd_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uv_guess_handle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_guess_handle(* (uv_file  *) RING_API_GETCPOINTER(1,"uv_file")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uv_file"));
}


RING_FUNC(ring_uv_replace_allocator)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_replace_allocator(* (uv_malloc_func  *) RING_API_GETCPOINTER(1,"uv_malloc_func"),* (uv_realloc_func  *) RING_API_GETCPOINTER(2,"uv_realloc_func"),* (uv_calloc_func  *) RING_API_GETCPOINTER(3,"uv_calloc_func"),* (uv_free_func  *) RING_API_GETCPOINTER(4,"uv_free_func")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uv_malloc_func"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uv_realloc_func"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"uv_calloc_func"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uv_free_func"));
}


RING_FUNC(ring_uv_buf_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		uv_buf_t *pValue ; 
		pValue = (uv_buf_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_buf_t)) ;
		*pValue = uv_buf_init((char *) RING_API_GETCPOINTER(1,"char"), (unsigned int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"uv_buf_t",ring_state_free);
	}
}


RING_FUNC(ring_uv_setup_args)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uv_setup_args( (int ) RING_API_GETNUMBER(1),(char **) RING_API_GETCPOINTER2POINTER(2,"char")),"char");
}


RING_FUNC(ring_uv_get_process_title)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_get_process_title((char *) RING_API_GETCPOINTER(1,"char"), (size_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uv_set_process_title)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_set_process_title(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_uv_resident_set_memory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_resident_set_memory((size_t *) RING_API_GETCPOINTER(1,"size_t")));
}


RING_FUNC(ring_uv_uptime)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_uptime(RING_API_GETDOUBLEPOINTER(1)));
}


RING_FUNC(ring_uv_getrusage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_getrusage((uv_rusage_t *) RING_API_GETCPOINTER(1,"uv_rusage_t")));
}


RING_FUNC(ring_uv_os_getpid)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		uv_pid_t *pValue ; 
		pValue = (uv_pid_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_pid_t)) ;
		*pValue = uv_os_getpid();
		RING_API_RETMANAGEDCPOINTER(pValue,"uv_pid_t",ring_state_free);
	}
}


RING_FUNC(ring_uv_os_getppid)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		uv_pid_t *pValue ; 
		pValue = (uv_pid_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uv_pid_t)) ;
		*pValue = uv_os_getppid();
		RING_API_RETMANAGEDCPOINTER(pValue,"uv_pid_t",ring_state_free);
	}
}


RING_FUNC(ring_uv_cpu_info)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_cpu_info((uv_cpu_info_t **) RING_API_GETCPOINTER2POINTER(1,"uv_cpu_info_t"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_uv_free_cpu_info)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_free_cpu_info((uv_cpu_info_t *) RING_API_GETCPOINTER(1,"uv_cpu_info_t"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uv_interface_addresses)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_interface_addresses((uv_interface_address_t **) RING_API_GETCPOINTER2POINTER(1,"uv_interface_address_t"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_uv_free_interface_addresses)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_free_interface_addresses((uv_interface_address_t *) RING_API_GETCPOINTER(1,"uv_interface_address_t"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uv_ip4_addr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_ip4_addr(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),(sockaddr_in *) RING_API_GETCPOINTER(3,"sockaddr_in")));
}


RING_FUNC(ring_uv_ip6_addr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_ip6_addr(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),(sockaddr_in6 *) RING_API_GETCPOINTER(3,"sockaddr_in6")));
}


RING_FUNC(ring_uv_ip4_name)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_ip4_name((sockaddr_in *) RING_API_GETCPOINTER(1,"sockaddr_in"),(char *) RING_API_GETCPOINTER(2,"char"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_ip6_name)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_ip6_name((sockaddr_in6 *) RING_API_GETCPOINTER(1,"sockaddr_in6"),(char *) RING_API_GETCPOINTER(2,"char"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_uv_inet_ntop)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_inet_ntop( (int ) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"),(char *) RING_API_GETCPOINTER(3,"char"), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_uv_inet_pton)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_inet_pton( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2),(void *) RING_API_GETCPOINTER(3,"void")));
}


RING_FUNC(ring_uv_if_indextoname)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_if_indextoname( (unsigned int ) RING_API_GETNUMBER(1),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}


RING_FUNC(ring_uv_if_indextoiid)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_if_indextoiid( (unsigned int ) RING_API_GETNUMBER(1),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}


RING_FUNC(ring_uv_exepath)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_exepath((char *) RING_API_GETCPOINTER(1,"char"),(size_t *) RING_API_GETCPOINTER(2,"size_t")));
}


RING_FUNC(ring_uv_cwd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_cwd((char *) RING_API_GETCPOINTER(1,"char"),(size_t *) RING_API_GETCPOINTER(2,"size_t")));
}


RING_FUNC(ring_uv_chdir)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_chdir(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_uv_os_homedir)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_homedir((char *) RING_API_GETCPOINTER(1,"char"),(size_t *) RING_API_GETCPOINTER(2,"size_t")));
}


RING_FUNC(ring_uv_os_tmpdir)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_tmpdir((char *) RING_API_GETCPOINTER(1,"char"),(size_t *) RING_API_GETCPOINTER(2,"size_t")));
}


RING_FUNC(ring_uv_os_get_passwd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_get_passwd((uv_passwd_t *) RING_API_GETCPOINTER(1,"uv_passwd_t")));
}


RING_FUNC(ring_uv_os_free_passwd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_os_free_passwd((uv_passwd_t *) RING_API_GETCPOINTER(1,"uv_passwd_t"));
}


RING_FUNC(ring_uv_get_total_memory)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_get_total_memory());
}


RING_FUNC(ring_uv_hrtime)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(uv_hrtime());
}


RING_FUNC(ring_uv_print_all_handles)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_print_all_handles((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(FILE *) RING_API_GETCPOINTER(2,"FILE"));
}


RING_FUNC(ring_uv_print_active_handles)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uv_print_active_handles((uv_loop_t *) RING_API_GETCPOINTER(1,"uv_loop_t"),(FILE *) RING_API_GETCPOINTER(2,"FILE"));
}


RING_FUNC(ring_uv_os_getenv)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_getenv(RING_API_GETSTRING(1),(char *) RING_API_GETCPOINTER(2,"char"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}


RING_FUNC(ring_uv_os_setenv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_setenv(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_uv_os_unsetenv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_unsetenv(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_uv_os_gethostname)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uv_os_gethostname((char *) RING_API_GETCPOINTER(1,"char"),(size_t *) RING_API_GETCPOINTER(2,"size_t")));
}

RING_API void ring_libuv_start(RingState *pRingState)
{
	RING_API_REGISTER("uv_callback",ring_uv_callback);
	RING_API_REGISTER("uv_eventpara",ring_uv_eventpara);
	RING_API_REGISTER("uv_myalloccallback",ring_uv_myalloccallback);
	RING_API_REGISTER("uv_pointer2string",ring_uv_pointer2string);
	RING_API_REGISTER("uv_free",ring_uv_free);
	RING_API_REGISTER("uv_deletecallbacks",ring_uv_deletecallbacks);
	RING_API_REGISTER("uv_deleteallcallbacks",ring_uv_deleteallcallbacks);
	RING_API_REGISTER("uv_callbackscount",ring_uv_callbackscount);
	RING_API_REGISTER("uv_deletecallbacksafter",ring_uv_deletecallbacksafter);
	RING_API_REGISTER("uv_strerror",ring_uv_strerror);
	RING_API_REGISTER("uv_err_name",ring_uv_err_name);
	RING_API_REGISTER("uv_translate_sys_error",ring_uv_translate_sys_error);
	RING_API_REGISTER("uv_version",ring_uv_version);
	RING_API_REGISTER("uv_version_string",ring_uv_version_string);
	RING_API_REGISTER("uv_loop_init",ring_uv_loop_init);
	RING_API_REGISTER("uv_loop_configure",ring_uv_loop_configure);
	RING_API_REGISTER("uv_loop_close",ring_uv_loop_close);
	RING_API_REGISTER("uv_default_loop",ring_uv_default_loop);
	RING_API_REGISTER("uv_run",ring_uv_run);
	RING_API_REGISTER("uv_loop_alive",ring_uv_loop_alive);
	RING_API_REGISTER("uv_stop",ring_uv_stop);
	RING_API_REGISTER("uv_loop_size",ring_uv_loop_size);
	RING_API_REGISTER("uv_backend_fd",ring_uv_backend_fd);
	RING_API_REGISTER("uv_backend_timeout",ring_uv_backend_timeout);
	RING_API_REGISTER("uv_now",ring_uv_now);
	RING_API_REGISTER("uv_update_time",ring_uv_update_time);
	RING_API_REGISTER("uv_walk",ring_uv_walk);
	RING_API_REGISTER("uv_walk_2",ring_uv_walk_2);
	RING_API_REGISTER("uv_loop_fork",ring_uv_loop_fork);
	RING_API_REGISTER("uv_is_active",ring_uv_is_active);
	RING_API_REGISTER("uv_is_closing",ring_uv_is_closing);
	RING_API_REGISTER("uv_close",ring_uv_close);
	RING_API_REGISTER("uv_close_2",ring_uv_close_2);
	RING_API_REGISTER("uv_ref",ring_uv_ref);
	RING_API_REGISTER("uv_unref",ring_uv_unref);
	RING_API_REGISTER("uv_has_ref",ring_uv_has_ref);
	RING_API_REGISTER("uv_handle_size",ring_uv_handle_size);
	RING_API_REGISTER("uv_send_buffer_size",ring_uv_send_buffer_size);
	RING_API_REGISTER("uv_recv_buffer_size",ring_uv_recv_buffer_size);
	RING_API_REGISTER("uv_fileno",ring_uv_fileno);
	RING_API_REGISTER("uv_cancel",ring_uv_cancel);
	RING_API_REGISTER("uv_req_size",ring_uv_req_size);
	RING_API_REGISTER("uv_timer_init",ring_uv_timer_init);
	RING_API_REGISTER("uv_timer_start",ring_uv_timer_start);
	RING_API_REGISTER("uv_timer_start_2",ring_uv_timer_start_2);
	RING_API_REGISTER("uv_timer_stop",ring_uv_timer_stop);
	RING_API_REGISTER("uv_timer_again",ring_uv_timer_again);
	RING_API_REGISTER("uv_timer_set_repeat",ring_uv_timer_set_repeat);
	RING_API_REGISTER("uv_timer_get_repeat",ring_uv_timer_get_repeat);
	RING_API_REGISTER("uv_prepare_init",ring_uv_prepare_init);
	RING_API_REGISTER("uv_prepare_start",ring_uv_prepare_start);
	RING_API_REGISTER("uv_prepare_start_2",ring_uv_prepare_start_2);
	RING_API_REGISTER("uv_prepare_stop",ring_uv_prepare_stop);
	RING_API_REGISTER("uv_check_init",ring_uv_check_init);
	RING_API_REGISTER("uv_check_start",ring_uv_check_start);
	RING_API_REGISTER("uv_check_start_2",ring_uv_check_start_2);
	RING_API_REGISTER("uv_check_stop",ring_uv_check_stop);
	RING_API_REGISTER("uv_idle_init",ring_uv_idle_init);
	RING_API_REGISTER("uv_idle_start",ring_uv_idle_start);
	RING_API_REGISTER("uv_idle_start_2",ring_uv_idle_start_2);
	RING_API_REGISTER("uv_idle_stop",ring_uv_idle_stop);
	RING_API_REGISTER("uv_async_init",ring_uv_async_init);
	RING_API_REGISTER("uv_async_init_2",ring_uv_async_init_2);
	RING_API_REGISTER("uv_async_send",ring_uv_async_send);
	RING_API_REGISTER("uv_poll_init",ring_uv_poll_init);
	RING_API_REGISTER("uv_poll_init_socket",ring_uv_poll_init_socket);
	RING_API_REGISTER("uv_poll_start",ring_uv_poll_start);
	RING_API_REGISTER("uv_poll_start_2",ring_uv_poll_start_2);
	RING_API_REGISTER("uv_poll_stop",ring_uv_poll_stop);
	RING_API_REGISTER("uv_signal_init",ring_uv_signal_init);
	RING_API_REGISTER("uv_signal_start",ring_uv_signal_start);
	RING_API_REGISTER("uv_signal_start_2",ring_uv_signal_start_2);
	RING_API_REGISTER("uv_signal_start_oneshot",ring_uv_signal_start_oneshot);
	RING_API_REGISTER("uv_signal_start_oneshot_2",ring_uv_signal_start_oneshot_2);
	RING_API_REGISTER("uv_signal_stop",ring_uv_signal_stop);
	RING_API_REGISTER("uv_disable_stdio_inheritance",ring_uv_disable_stdio_inheritance);
	RING_API_REGISTER("uv_spawn",ring_uv_spawn);
	RING_API_REGISTER("uv_process_kill",ring_uv_process_kill);
	RING_API_REGISTER("uv_kill",ring_uv_kill);
	RING_API_REGISTER("uv_shutdown",ring_uv_shutdown);
	RING_API_REGISTER("uv_shutdown_2",ring_uv_shutdown_2);
	RING_API_REGISTER("uv_listen",ring_uv_listen);
	RING_API_REGISTER("uv_listen_2",ring_uv_listen_2);
	RING_API_REGISTER("uv_accept",ring_uv_accept);
	RING_API_REGISTER("uv_read_start",ring_uv_read_start);
	RING_API_REGISTER("uv_read_start_2",ring_uv_read_start_2);
	RING_API_REGISTER("uv_read_stop",ring_uv_read_stop);
	RING_API_REGISTER("uv_write",ring_uv_write);
	RING_API_REGISTER("uv_write_2",ring_uv_write_2);
	RING_API_REGISTER("uv_write2",ring_uv_write2);
	RING_API_REGISTER("uv_write2_2",ring_uv_write2_2);
	RING_API_REGISTER("uv_try_write",ring_uv_try_write);
	RING_API_REGISTER("uv_is_readable",ring_uv_is_readable);
	RING_API_REGISTER("uv_is_writable",ring_uv_is_writable);
	RING_API_REGISTER("uv_stream_set_blocking",ring_uv_stream_set_blocking);
	RING_API_REGISTER("uv_tcp_init",ring_uv_tcp_init);
	RING_API_REGISTER("uv_tcp_init_ex",ring_uv_tcp_init_ex);
	RING_API_REGISTER("uv_tcp_open",ring_uv_tcp_open);
	RING_API_REGISTER("uv_tcp_nodelay",ring_uv_tcp_nodelay);
	RING_API_REGISTER("uv_tcp_keepalive",ring_uv_tcp_keepalive);
	RING_API_REGISTER("uv_tcp_simultaneous_accepts",ring_uv_tcp_simultaneous_accepts);
	RING_API_REGISTER("uv_tcp_bind",ring_uv_tcp_bind);
	RING_API_REGISTER("uv_tcp_getsockname",ring_uv_tcp_getsockname);
	RING_API_REGISTER("uv_tcp_getpeername",ring_uv_tcp_getpeername);
	RING_API_REGISTER("uv_tcp_connect",ring_uv_tcp_connect);
	RING_API_REGISTER("uv_tcp_connect_2",ring_uv_tcp_connect_2);
	RING_API_REGISTER("uv_pipe_init",ring_uv_pipe_init);
	RING_API_REGISTER("uv_pipe_open",ring_uv_pipe_open);
	RING_API_REGISTER("uv_pipe_bind",ring_uv_pipe_bind);
	RING_API_REGISTER("uv_pipe_connect",ring_uv_pipe_connect);
	RING_API_REGISTER("uv_pipe_connect_2",ring_uv_pipe_connect_2);
	RING_API_REGISTER("uv_pipe_getsockname",ring_uv_pipe_getsockname);
	RING_API_REGISTER("uv_pipe_getpeername",ring_uv_pipe_getpeername);
	RING_API_REGISTER("uv_pipe_pending_instances",ring_uv_pipe_pending_instances);
	RING_API_REGISTER("uv_pipe_pending_count",ring_uv_pipe_pending_count);
	RING_API_REGISTER("uv_pipe_pending_type",ring_uv_pipe_pending_type);
	RING_API_REGISTER("uv_pipe_chmod",ring_uv_pipe_chmod);
	RING_API_REGISTER("uv_tty_init",ring_uv_tty_init);
	RING_API_REGISTER("uv_tty_set_mode",ring_uv_tty_set_mode);
	RING_API_REGISTER("uv_tty_reset_mode",ring_uv_tty_reset_mode);
	RING_API_REGISTER("uv_tty_get_winsize",ring_uv_tty_get_winsize);
	RING_API_REGISTER("uv_udp_init",ring_uv_udp_init);
	RING_API_REGISTER("uv_udp_init_ex",ring_uv_udp_init_ex);
	RING_API_REGISTER("uv_udp_open",ring_uv_udp_open);
	RING_API_REGISTER("uv_udp_bind",ring_uv_udp_bind);
	RING_API_REGISTER("uv_udp_getsockname",ring_uv_udp_getsockname);
	RING_API_REGISTER("uv_udp_set_membership",ring_uv_udp_set_membership);
	RING_API_REGISTER("uv_udp_set_multicast_loop",ring_uv_udp_set_multicast_loop);
	RING_API_REGISTER("uv_udp_set_multicast_ttl",ring_uv_udp_set_multicast_ttl);
	RING_API_REGISTER("uv_udp_set_multicast_interface",ring_uv_udp_set_multicast_interface);
	RING_API_REGISTER("uv_udp_set_broadcast",ring_uv_udp_set_broadcast);
	RING_API_REGISTER("uv_udp_set_ttl",ring_uv_udp_set_ttl);
	RING_API_REGISTER("uv_udp_send",ring_uv_udp_send);
	RING_API_REGISTER("uv_udp_send_2",ring_uv_udp_send_2);
	RING_API_REGISTER("uv_udp_try_send",ring_uv_udp_try_send);
	RING_API_REGISTER("uv_udp_recv_start",ring_uv_udp_recv_start);
	RING_API_REGISTER("uv_udp_recv_start_2",ring_uv_udp_recv_start_2);
	RING_API_REGISTER("uv_udp_recv_stop",ring_uv_udp_recv_stop);
	RING_API_REGISTER("uv_fs_event_init",ring_uv_fs_event_init);
	RING_API_REGISTER("uv_fs_event_start",ring_uv_fs_event_start);
	RING_API_REGISTER("uv_fs_event_start_2",ring_uv_fs_event_start_2);
	RING_API_REGISTER("uv_fs_event_stop",ring_uv_fs_event_stop);
	RING_API_REGISTER("uv_fs_event_getpath",ring_uv_fs_event_getpath);
	RING_API_REGISTER("uv_fs_poll_init",ring_uv_fs_poll_init);
	RING_API_REGISTER("uv_fs_poll_start",ring_uv_fs_poll_start);
	RING_API_REGISTER("uv_fs_poll_start_2",ring_uv_fs_poll_start_2);
	RING_API_REGISTER("uv_fs_poll_stop",ring_uv_fs_poll_stop);
	RING_API_REGISTER("uv_fs_poll_getpath",ring_uv_fs_poll_getpath);
	RING_API_REGISTER("uv_fs_req_cleanup",ring_uv_fs_req_cleanup);
	RING_API_REGISTER("uv_fs_close",ring_uv_fs_close);
	RING_API_REGISTER("uv_fs_open",ring_uv_fs_open);
	RING_API_REGISTER("uv_fs_read",ring_uv_fs_read);
	RING_API_REGISTER("uv_fs_unlink",ring_uv_fs_unlink);
	RING_API_REGISTER("uv_fs_write",ring_uv_fs_write);
	RING_API_REGISTER("uv_fs_mkdir",ring_uv_fs_mkdir);
	RING_API_REGISTER("uv_fs_mkdtemp",ring_uv_fs_mkdtemp);
	RING_API_REGISTER("uv_fs_rmdir",ring_uv_fs_rmdir);
	RING_API_REGISTER("uv_fs_scandir",ring_uv_fs_scandir);
	RING_API_REGISTER("uv_fs_scandir_next",ring_uv_fs_scandir_next);
	RING_API_REGISTER("uv_fs_stat",ring_uv_fs_stat);
	RING_API_REGISTER("uv_fs_fstat",ring_uv_fs_fstat);
	RING_API_REGISTER("uv_fs_lstat",ring_uv_fs_lstat);
	RING_API_REGISTER("uv_fs_rename",ring_uv_fs_rename);
	RING_API_REGISTER("uv_fs_fsync",ring_uv_fs_fsync);
	RING_API_REGISTER("uv_fs_fdatasync",ring_uv_fs_fdatasync);
	RING_API_REGISTER("uv_fs_ftruncate",ring_uv_fs_ftruncate);
	RING_API_REGISTER("uv_fs_copyfile",ring_uv_fs_copyfile);
	RING_API_REGISTER("uv_fs_sendfile",ring_uv_fs_sendfile);
	RING_API_REGISTER("uv_fs_access",ring_uv_fs_access);
	RING_API_REGISTER("uv_fs_chmod",ring_uv_fs_chmod);
	RING_API_REGISTER("uv_fs_fchmod",ring_uv_fs_fchmod);
	RING_API_REGISTER("uv_fs_utime",ring_uv_fs_utime);
	RING_API_REGISTER("uv_fs_futime",ring_uv_fs_futime);
	RING_API_REGISTER("uv_fs_link",ring_uv_fs_link);
	RING_API_REGISTER("uv_fs_symlink",ring_uv_fs_symlink);
	RING_API_REGISTER("uv_fs_readlink",ring_uv_fs_readlink);
	RING_API_REGISTER("uv_fs_realpath",ring_uv_fs_realpath);
	RING_API_REGISTER("uv_fs_chown",ring_uv_fs_chown);
	RING_API_REGISTER("uv_fs_fchown",ring_uv_fs_fchown);
	RING_API_REGISTER("uv_fs_close_2",ring_uv_fs_close_2);
	RING_API_REGISTER("uv_fs_open_2",ring_uv_fs_open_2);
	RING_API_REGISTER("uv_fs_read_2",ring_uv_fs_read_2);
	RING_API_REGISTER("uv_fs_unlink_2",ring_uv_fs_unlink_2);
	RING_API_REGISTER("uv_fs_write_2",ring_uv_fs_write_2);
	RING_API_REGISTER("uv_fs_mkdir_2",ring_uv_fs_mkdir_2);
	RING_API_REGISTER("uv_fs_mkdtemp_2",ring_uv_fs_mkdtemp_2);
	RING_API_REGISTER("uv_fs_rmdir_2",ring_uv_fs_rmdir_2);
	RING_API_REGISTER("uv_fs_scandir_2",ring_uv_fs_scandir_2);
	RING_API_REGISTER("uv_fs_stat_2",ring_uv_fs_stat_2);
	RING_API_REGISTER("uv_fs_fstat_2",ring_uv_fs_fstat_2);
	RING_API_REGISTER("uv_fs_lstat_2",ring_uv_fs_lstat_2);
	RING_API_REGISTER("uv_fs_rename_2",ring_uv_fs_rename_2);
	RING_API_REGISTER("uv_fs_fsync_2",ring_uv_fs_fsync_2);
	RING_API_REGISTER("uv_fs_fdatasync_2",ring_uv_fs_fdatasync_2);
	RING_API_REGISTER("uv_fs_ftruncate_2",ring_uv_fs_ftruncate_2);
	RING_API_REGISTER("uv_fs_copyfile_2",ring_uv_fs_copyfile_2);
	RING_API_REGISTER("uv_fs_sendfile_2",ring_uv_fs_sendfile_2);
	RING_API_REGISTER("uv_fs_access_2",ring_uv_fs_access_2);
	RING_API_REGISTER("uv_fs_chmod_2",ring_uv_fs_chmod_2);
	RING_API_REGISTER("uv_fs_fchmod_2",ring_uv_fs_fchmod_2);
	RING_API_REGISTER("uv_fs_utime_2",ring_uv_fs_utime_2);
	RING_API_REGISTER("uv_fs_futime_2",ring_uv_fs_futime_2);
	RING_API_REGISTER("uv_fs_link_2",ring_uv_fs_link_2);
	RING_API_REGISTER("uv_fs_symlink_2",ring_uv_fs_symlink_2);
	RING_API_REGISTER("uv_fs_readlink_2",ring_uv_fs_readlink_2);
	RING_API_REGISTER("uv_fs_realpath_2",ring_uv_fs_realpath_2);
	RING_API_REGISTER("uv_fs_chown_2",ring_uv_fs_chown_2);
	RING_API_REGISTER("uv_fs_fchown_2",ring_uv_fs_fchown_2);
	RING_API_REGISTER("uv_get_osfhandle",ring_uv_get_osfhandle);
	RING_API_REGISTER("uv_queue_work",ring_uv_queue_work);
	RING_API_REGISTER("uv_queue_work_2",ring_uv_queue_work_2);
	RING_API_REGISTER("uv_getaddrinfo",ring_uv_getaddrinfo);
	RING_API_REGISTER("uv_getaddrinfo_2",ring_uv_getaddrinfo_2);
	RING_API_REGISTER("uv_freeaddrinfo",ring_uv_freeaddrinfo);
	RING_API_REGISTER("uv_getnameinfo",ring_uv_getnameinfo);
	RING_API_REGISTER("uv_getnameinfo_2",ring_uv_getnameinfo_2);
	RING_API_REGISTER("uv_dlopen",ring_uv_dlopen);
	RING_API_REGISTER("uv_dlclose",ring_uv_dlclose);
	RING_API_REGISTER("uv_dlsym",ring_uv_dlsym);
	RING_API_REGISTER("uv_dlerror",ring_uv_dlerror);
	RING_API_REGISTER("uv_thread_create",ring_uv_thread_create);
	RING_API_REGISTER("uv_thread_create_2",ring_uv_thread_create_2);
	RING_API_REGISTER("uv_thread_self",ring_uv_thread_self);
	RING_API_REGISTER("uv_thread_join",ring_uv_thread_join);
	RING_API_REGISTER("uv_thread_equal",ring_uv_thread_equal);
	RING_API_REGISTER("uv_key_create",ring_uv_key_create);
	RING_API_REGISTER("uv_key_delete",ring_uv_key_delete);
	RING_API_REGISTER("uv_key_get",ring_uv_key_get);
	RING_API_REGISTER("uv_key_set",ring_uv_key_set);
	RING_API_REGISTER("uv_mutex_init",ring_uv_mutex_init);
	RING_API_REGISTER("uv_mutex_init_recursive",ring_uv_mutex_init_recursive);
	RING_API_REGISTER("uv_mutex_destroy",ring_uv_mutex_destroy);
	RING_API_REGISTER("uv_mutex_lock",ring_uv_mutex_lock);
	RING_API_REGISTER("uv_mutex_trylock",ring_uv_mutex_trylock);
	RING_API_REGISTER("uv_mutex_unlock",ring_uv_mutex_unlock);
	RING_API_REGISTER("uv_rwlock_init",ring_uv_rwlock_init);
	RING_API_REGISTER("uv_rwlock_destroy",ring_uv_rwlock_destroy);
	RING_API_REGISTER("uv_rwlock_rdlock",ring_uv_rwlock_rdlock);
	RING_API_REGISTER("uv_rwlock_tryrdlock",ring_uv_rwlock_tryrdlock);
	RING_API_REGISTER("uv_rwlock_rdunlock",ring_uv_rwlock_rdunlock);
	RING_API_REGISTER("uv_rwlock_wrlock",ring_uv_rwlock_wrlock);
	RING_API_REGISTER("uv_rwlock_trywrlock",ring_uv_rwlock_trywrlock);
	RING_API_REGISTER("uv_rwlock_wrunlock",ring_uv_rwlock_wrunlock);
	RING_API_REGISTER("uv_sem_init",ring_uv_sem_init);
	RING_API_REGISTER("uv_sem_destroy",ring_uv_sem_destroy);
	RING_API_REGISTER("uv_sem_post",ring_uv_sem_post);
	RING_API_REGISTER("uv_sem_wait",ring_uv_sem_wait);
	RING_API_REGISTER("uv_sem_trywait",ring_uv_sem_trywait);
	RING_API_REGISTER("uv_cond_init",ring_uv_cond_init);
	RING_API_REGISTER("uv_cond_destroy",ring_uv_cond_destroy);
	RING_API_REGISTER("uv_cond_signal",ring_uv_cond_signal);
	RING_API_REGISTER("uv_cond_broadcast",ring_uv_cond_broadcast);
	RING_API_REGISTER("uv_cond_wait",ring_uv_cond_wait);
	RING_API_REGISTER("uv_cond_timedwait",ring_uv_cond_timedwait);
	RING_API_REGISTER("uv_barrier_init",ring_uv_barrier_init);
	RING_API_REGISTER("uv_barrier_destroy",ring_uv_barrier_destroy);
	RING_API_REGISTER("uv_barrier_wait",ring_uv_barrier_wait);
	RING_API_REGISTER("uv_guess_handle",ring_uv_guess_handle);
	RING_API_REGISTER("uv_replace_allocator",ring_uv_replace_allocator);
	RING_API_REGISTER("uv_buf_init",ring_uv_buf_init);
	RING_API_REGISTER("uv_setup_args",ring_uv_setup_args);
	RING_API_REGISTER("uv_get_process_title",ring_uv_get_process_title);
	RING_API_REGISTER("uv_set_process_title",ring_uv_set_process_title);
	RING_API_REGISTER("uv_resident_set_memory",ring_uv_resident_set_memory);
	RING_API_REGISTER("uv_uptime",ring_uv_uptime);
	RING_API_REGISTER("uv_getrusage",ring_uv_getrusage);
	RING_API_REGISTER("uv_os_getpid",ring_uv_os_getpid);
	RING_API_REGISTER("uv_os_getppid",ring_uv_os_getppid);
	RING_API_REGISTER("uv_cpu_info",ring_uv_cpu_info);
	RING_API_REGISTER("uv_free_cpu_info",ring_uv_free_cpu_info);
	RING_API_REGISTER("uv_interface_addresses",ring_uv_interface_addresses);
	RING_API_REGISTER("uv_free_interface_addresses",ring_uv_free_interface_addresses);
	RING_API_REGISTER("uv_ip4_addr",ring_uv_ip4_addr);
	RING_API_REGISTER("uv_ip6_addr",ring_uv_ip6_addr);
	RING_API_REGISTER("uv_ip4_name",ring_uv_ip4_name);
	RING_API_REGISTER("uv_ip6_name",ring_uv_ip6_name);
	RING_API_REGISTER("uv_inet_ntop",ring_uv_inet_ntop);
	RING_API_REGISTER("uv_inet_pton",ring_uv_inet_pton);
	RING_API_REGISTER("uv_if_indextoname",ring_uv_if_indextoname);
	RING_API_REGISTER("uv_if_indextoiid",ring_uv_if_indextoiid);
	RING_API_REGISTER("uv_exepath",ring_uv_exepath);
	RING_API_REGISTER("uv_cwd",ring_uv_cwd);
	RING_API_REGISTER("uv_chdir",ring_uv_chdir);
	RING_API_REGISTER("uv_os_homedir",ring_uv_os_homedir);
	RING_API_REGISTER("uv_os_tmpdir",ring_uv_os_tmpdir);
	RING_API_REGISTER("uv_os_get_passwd",ring_uv_os_get_passwd);
	RING_API_REGISTER("uv_os_free_passwd",ring_uv_os_free_passwd);
	RING_API_REGISTER("uv_get_total_memory",ring_uv_get_total_memory);
	RING_API_REGISTER("uv_hrtime",ring_uv_hrtime);
	RING_API_REGISTER("uv_print_all_handles",ring_uv_print_all_handles);
	RING_API_REGISTER("uv_print_active_handles",ring_uv_print_active_handles);
	RING_API_REGISTER("uv_os_getenv",ring_uv_os_getenv);
	RING_API_REGISTER("uv_os_setenv",ring_uv_os_setenv);
	RING_API_REGISTER("uv_os_unsetenv",ring_uv_os_unsetenv);
	RING_API_REGISTER("uv_os_gethostname",ring_uv_os_gethostname);
	RING_API_REGISTER("new_sockaddr_in",ring_new_sockaddr_in);
	RING_API_REGISTER("new_managed_sockaddr_in",ring_new_managed_sockaddr_in);
	RING_API_REGISTER("destroy_sockaddr_in",ring_destroy_sockaddr_in);
	RING_API_REGISTER("new_sockaddr_in6",ring_new_sockaddr_in6);
	RING_API_REGISTER("new_managed_sockaddr_in6",ring_new_managed_sockaddr_in6);
	RING_API_REGISTER("destroy_sockaddr_in6",ring_destroy_sockaddr_in6);
	RING_API_REGISTER("get_uv_e2big",ring_get_uv_e2big);
	RING_API_REGISTER("get_uv_eacces",ring_get_uv_eacces);
	RING_API_REGISTER("get_uv_eaddrinuse",ring_get_uv_eaddrinuse);
	RING_API_REGISTER("get_uv_eaddrnotavail",ring_get_uv_eaddrnotavail);
	RING_API_REGISTER("get_uv_eafnosupport",ring_get_uv_eafnosupport);
	RING_API_REGISTER("get_uv_eagain",ring_get_uv_eagain);
	RING_API_REGISTER("get_uv_eai_addrfamily",ring_get_uv_eai_addrfamily);
	RING_API_REGISTER("get_uv_eai_again",ring_get_uv_eai_again);
	RING_API_REGISTER("get_uv_eai_badflags",ring_get_uv_eai_badflags);
	RING_API_REGISTER("get_uv_eai_badhints",ring_get_uv_eai_badhints);
	RING_API_REGISTER("get_uv_eai_canceled",ring_get_uv_eai_canceled);
	RING_API_REGISTER("get_uv_eai_fail",ring_get_uv_eai_fail);
	RING_API_REGISTER("get_uv_eai_family",ring_get_uv_eai_family);
	RING_API_REGISTER("get_uv_eai_memory",ring_get_uv_eai_memory);
	RING_API_REGISTER("get_uv_eai_nodata",ring_get_uv_eai_nodata);
	RING_API_REGISTER("get_uv_eai_noname",ring_get_uv_eai_noname);
	RING_API_REGISTER("get_uv_eai_overflow",ring_get_uv_eai_overflow);
	RING_API_REGISTER("get_uv_eai_protocol",ring_get_uv_eai_protocol);
	RING_API_REGISTER("get_uv_eai_service",ring_get_uv_eai_service);
	RING_API_REGISTER("get_uv_eai_socktype",ring_get_uv_eai_socktype);
	RING_API_REGISTER("get_uv_ealready",ring_get_uv_ealready);
	RING_API_REGISTER("get_uv_ebadf",ring_get_uv_ebadf);
	RING_API_REGISTER("get_uv_ebusy",ring_get_uv_ebusy);
	RING_API_REGISTER("get_uv_ecanceled",ring_get_uv_ecanceled);
	RING_API_REGISTER("get_uv_echarset",ring_get_uv_echarset);
	RING_API_REGISTER("get_uv_econnaborted",ring_get_uv_econnaborted);
	RING_API_REGISTER("get_uv_econnrefused",ring_get_uv_econnrefused);
	RING_API_REGISTER("get_uv_econnreset",ring_get_uv_econnreset);
	RING_API_REGISTER("get_uv_edestaddrreq",ring_get_uv_edestaddrreq);
	RING_API_REGISTER("get_uv_eexist",ring_get_uv_eexist);
	RING_API_REGISTER("get_uv_efault",ring_get_uv_efault);
	RING_API_REGISTER("get_uv_efbig",ring_get_uv_efbig);
	RING_API_REGISTER("get_uv_ehostunreach",ring_get_uv_ehostunreach);
	RING_API_REGISTER("get_uv_eintr",ring_get_uv_eintr);
	RING_API_REGISTER("get_uv_einval",ring_get_uv_einval);
	RING_API_REGISTER("get_uv_eio",ring_get_uv_eio);
	RING_API_REGISTER("get_uv_eisconn",ring_get_uv_eisconn);
	RING_API_REGISTER("get_uv_eisdir",ring_get_uv_eisdir);
	RING_API_REGISTER("get_uv_eloop",ring_get_uv_eloop);
	RING_API_REGISTER("get_uv_emfile",ring_get_uv_emfile);
	RING_API_REGISTER("get_uv_emsgsize",ring_get_uv_emsgsize);
	RING_API_REGISTER("get_uv_enametoolong",ring_get_uv_enametoolong);
	RING_API_REGISTER("get_uv_enetdown",ring_get_uv_enetdown);
	RING_API_REGISTER("get_uv_enetunreach",ring_get_uv_enetunreach);
	RING_API_REGISTER("get_uv_enfile",ring_get_uv_enfile);
	RING_API_REGISTER("get_uv_enobufs",ring_get_uv_enobufs);
	RING_API_REGISTER("get_uv_enodev",ring_get_uv_enodev);
	RING_API_REGISTER("get_uv_enoent",ring_get_uv_enoent);
	RING_API_REGISTER("get_uv_enomem",ring_get_uv_enomem);
	RING_API_REGISTER("get_uv_enonet",ring_get_uv_enonet);
	RING_API_REGISTER("get_uv_enoprotoopt",ring_get_uv_enoprotoopt);
	RING_API_REGISTER("get_uv_enospc",ring_get_uv_enospc);
	RING_API_REGISTER("get_uv_enosys",ring_get_uv_enosys);
	RING_API_REGISTER("get_uv_enotconn",ring_get_uv_enotconn);
	RING_API_REGISTER("get_uv_enotdir",ring_get_uv_enotdir);
	RING_API_REGISTER("get_uv_enotempty",ring_get_uv_enotempty);
	RING_API_REGISTER("get_uv_enotsock",ring_get_uv_enotsock);
	RING_API_REGISTER("get_uv_enotsup",ring_get_uv_enotsup);
	RING_API_REGISTER("get_uv_eperm",ring_get_uv_eperm);
	RING_API_REGISTER("get_uv_epipe",ring_get_uv_epipe);
	RING_API_REGISTER("get_uv_eproto",ring_get_uv_eproto);
	RING_API_REGISTER("get_uv_eprotonosupport",ring_get_uv_eprotonosupport);
	RING_API_REGISTER("get_uv_eprototype",ring_get_uv_eprototype);
	RING_API_REGISTER("get_uv_erange",ring_get_uv_erange);
	RING_API_REGISTER("get_uv_erofs",ring_get_uv_erofs);
	RING_API_REGISTER("get_uv_eshutdown",ring_get_uv_eshutdown);
	RING_API_REGISTER("get_uv_espipe",ring_get_uv_espipe);
	RING_API_REGISTER("get_uv_esrch",ring_get_uv_esrch);
	RING_API_REGISTER("get_uv_etimedout",ring_get_uv_etimedout);
	RING_API_REGISTER("get_uv_etxtbsy",ring_get_uv_etxtbsy);
	RING_API_REGISTER("get_uv_exdev",ring_get_uv_exdev);
	RING_API_REGISTER("get_uv_unknown",ring_get_uv_unknown);
	RING_API_REGISTER("get_uv_eof",ring_get_uv_eof);
	RING_API_REGISTER("get_uv_enxio",ring_get_uv_enxio);
	RING_API_REGISTER("get_uv_emlink",ring_get_uv_emlink);
	RING_API_REGISTER("get_uv_version_major",ring_get_uv_version_major);
	RING_API_REGISTER("get_uv_version_minor",ring_get_uv_version_minor);
	RING_API_REGISTER("get_uv_version_patch",ring_get_uv_version_patch);
	RING_API_REGISTER("get_uv_version_is_release",ring_get_uv_version_is_release);
	RING_API_REGISTER("get_uv_version_hex",ring_get_uv_version_hex);
	RING_API_REGISTER("get_uv_run_default",ring_get_uv_run_default);
	RING_API_REGISTER("get_uv_run_once",ring_get_uv_run_once);
	RING_API_REGISTER("get_uv_run_nowait",ring_get_uv_run_nowait);
	RING_API_REGISTER("get_uv_unknown_handle",ring_get_uv_unknown_handle);
	RING_API_REGISTER("get_uv_async",ring_get_uv_async);
	RING_API_REGISTER("get_uv_check",ring_get_uv_check);
	RING_API_REGISTER("get_uv_fs_event",ring_get_uv_fs_event);
	RING_API_REGISTER("get_uv_fs_poll",ring_get_uv_fs_poll);
	RING_API_REGISTER("get_uv_handle",ring_get_uv_handle);
	RING_API_REGISTER("get_uv_idle",ring_get_uv_idle);
	RING_API_REGISTER("get_uv_named_pipe",ring_get_uv_named_pipe);
	RING_API_REGISTER("get_uv_poll",ring_get_uv_poll);
	RING_API_REGISTER("get_uv_prepare",ring_get_uv_prepare);
	RING_API_REGISTER("get_uv_process",ring_get_uv_process);
	RING_API_REGISTER("get_uv_stream",ring_get_uv_stream);
	RING_API_REGISTER("get_uv_tcp",ring_get_uv_tcp);
	RING_API_REGISTER("get_uv_timer",ring_get_uv_timer);
	RING_API_REGISTER("get_uv_tty",ring_get_uv_tty);
	RING_API_REGISTER("get_uv_udp",ring_get_uv_udp);
	RING_API_REGISTER("get_uv_signal",ring_get_uv_signal);
	RING_API_REGISTER("get_uv_file",ring_get_uv_file);
	RING_API_REGISTER("get_uv_handle_type_max",ring_get_uv_handle_type_max);
	RING_API_REGISTER("get_uv_unknown_req",ring_get_uv_unknown_req);
	RING_API_REGISTER("get_uv_req",ring_get_uv_req);
	RING_API_REGISTER("get_uv_connect",ring_get_uv_connect);
	RING_API_REGISTER("get_uv_write",ring_get_uv_write);
	RING_API_REGISTER("get_uv_shutdown",ring_get_uv_shutdown);
	RING_API_REGISTER("get_uv_udp_send",ring_get_uv_udp_send);
	RING_API_REGISTER("get_uv_fs",ring_get_uv_fs);
	RING_API_REGISTER("get_uv_work",ring_get_uv_work);
	RING_API_REGISTER("get_uv_getaddrinfo",ring_get_uv_getaddrinfo);
	RING_API_REGISTER("get_uv_getnameinfo",ring_get_uv_getnameinfo);
	RING_API_REGISTER("get_uv_req_type_max",ring_get_uv_req_type_max);
	RING_API_REGISTER("get_uv_readable",ring_get_uv_readable);
	RING_API_REGISTER("get_uv_writable",ring_get_uv_writable);
	RING_API_REGISTER("get_uv_disconnect",ring_get_uv_disconnect);
	RING_API_REGISTER("get_uv_prioritized",ring_get_uv_prioritized);
	RING_API_REGISTER("get_uv_process_setuid",ring_get_uv_process_setuid);
	RING_API_REGISTER("get_uv_process_setgid",ring_get_uv_process_setgid);
	RING_API_REGISTER("get_uv_process_windows_verbatim_arguments",ring_get_uv_process_windows_verbatim_arguments);
	RING_API_REGISTER("get_uv_process_detached",ring_get_uv_process_detached);
	RING_API_REGISTER("get_uv_process_windows_hide",ring_get_uv_process_windows_hide);
	RING_API_REGISTER("get_uv_ignore",ring_get_uv_ignore);
	RING_API_REGISTER("get_uv_create_pipe",ring_get_uv_create_pipe);
	RING_API_REGISTER("get_uv_inherit_fd",ring_get_uv_inherit_fd);
	RING_API_REGISTER("get_uv_inherit_stream",ring_get_uv_inherit_stream);
	RING_API_REGISTER("get_uv_readable_pipe",ring_get_uv_readable_pipe);
	RING_API_REGISTER("get_uv_writable_pipe",ring_get_uv_writable_pipe);
	RING_API_REGISTER("get_uv_tty_mode_normal",ring_get_uv_tty_mode_normal);
	RING_API_REGISTER("get_uv_tty_mode_raw",ring_get_uv_tty_mode_raw);
	RING_API_REGISTER("get_uv_tty_mode_io",ring_get_uv_tty_mode_io);
	RING_API_REGISTER("get_uv_udp_ipv6only",ring_get_uv_udp_ipv6only);
	RING_API_REGISTER("get_uv_udp_partial",ring_get_uv_udp_partial);
	RING_API_REGISTER("get_uv_udp_reuseaddr",ring_get_uv_udp_reuseaddr);
	RING_API_REGISTER("get_uv_leave_group",ring_get_uv_leave_group);
	RING_API_REGISTER("get_uv_join_group",ring_get_uv_join_group);
	RING_API_REGISTER("get_uv_rename",ring_get_uv_rename);
	RING_API_REGISTER("get_uv_change",ring_get_uv_change);
	RING_API_REGISTER("get_uv_fs_event_watch_entry",ring_get_uv_fs_event_watch_entry);
	RING_API_REGISTER("get_uv_fs_event_stat",ring_get_uv_fs_event_stat);
	RING_API_REGISTER("get_uv_fs_event_recursive",ring_get_uv_fs_event_recursive);
	RING_API_REGISTER("get_uv_fs_unknown",ring_get_uv_fs_unknown);
	RING_API_REGISTER("get_uv_fs_custom",ring_get_uv_fs_custom);
	RING_API_REGISTER("get_uv_fs_open",ring_get_uv_fs_open);
	RING_API_REGISTER("get_uv_fs_close",ring_get_uv_fs_close);
	RING_API_REGISTER("get_uv_fs_read",ring_get_uv_fs_read);
	RING_API_REGISTER("get_uv_fs_write",ring_get_uv_fs_write);
	RING_API_REGISTER("get_uv_fs_sendfile",ring_get_uv_fs_sendfile);
	RING_API_REGISTER("get_uv_fs_stat",ring_get_uv_fs_stat);
	RING_API_REGISTER("get_uv_fs_lstat",ring_get_uv_fs_lstat);
	RING_API_REGISTER("get_uv_fs_fstat",ring_get_uv_fs_fstat);
	RING_API_REGISTER("get_uv_fs_ftruncate",ring_get_uv_fs_ftruncate);
	RING_API_REGISTER("get_uv_fs_utime",ring_get_uv_fs_utime);
	RING_API_REGISTER("get_uv_fs_futime",ring_get_uv_fs_futime);
	RING_API_REGISTER("get_uv_fs_access",ring_get_uv_fs_access);
	RING_API_REGISTER("get_uv_fs_chmod",ring_get_uv_fs_chmod);
	RING_API_REGISTER("get_uv_fs_fchmod",ring_get_uv_fs_fchmod);
	RING_API_REGISTER("get_uv_fs_fsync",ring_get_uv_fs_fsync);
	RING_API_REGISTER("get_uv_fs_fdatasync",ring_get_uv_fs_fdatasync);
	RING_API_REGISTER("get_uv_fs_unlink",ring_get_uv_fs_unlink);
	RING_API_REGISTER("get_uv_fs_rmdir",ring_get_uv_fs_rmdir);
	RING_API_REGISTER("get_uv_fs_mkdir",ring_get_uv_fs_mkdir);
	RING_API_REGISTER("get_uv_fs_mkdtemp",ring_get_uv_fs_mkdtemp);
	RING_API_REGISTER("get_uv_fs_rename",ring_get_uv_fs_rename);
	RING_API_REGISTER("get_uv_fs_scandir",ring_get_uv_fs_scandir);
	RING_API_REGISTER("get_uv_fs_link",ring_get_uv_fs_link);
	RING_API_REGISTER("get_uv_fs_symlink",ring_get_uv_fs_symlink);
	RING_API_REGISTER("get_uv_fs_readlink",ring_get_uv_fs_readlink);
	RING_API_REGISTER("get_uv_fs_chown",ring_get_uv_fs_chown);
	RING_API_REGISTER("get_uv_fs_fchown",ring_get_uv_fs_fchown);
	RING_API_REGISTER("get_uv_fs_realpath",ring_get_uv_fs_realpath);
	RING_API_REGISTER("get_uv_fs_copyfile",ring_get_uv_fs_copyfile);
	RING_API_REGISTER("get_uv_dirent_unknown",ring_get_uv_dirent_unknown);
	RING_API_REGISTER("get_uv_dirent_file",ring_get_uv_dirent_file);
	RING_API_REGISTER("get_uv_dirent_dir",ring_get_uv_dirent_dir);
	RING_API_REGISTER("get_uv_dirent_link",ring_get_uv_dirent_link);
	RING_API_REGISTER("get_uv_dirent_fifo",ring_get_uv_dirent_fifo);
	RING_API_REGISTER("get_uv_dirent_socket",ring_get_uv_dirent_socket);
	RING_API_REGISTER("get_uv_dirent_char",ring_get_uv_dirent_char);
	RING_API_REGISTER("get_uv_dirent_block",ring_get_uv_dirent_block);
	RING_API_REGISTER("get_uv_fs_o_append",ring_get_uv_fs_o_append);
	RING_API_REGISTER("get_uv_fs_o_creat",ring_get_uv_fs_o_creat);
	RING_API_REGISTER("get_uv_fs_o_direct",ring_get_uv_fs_o_direct);
	RING_API_REGISTER("get_uv_fs_o_directory",ring_get_uv_fs_o_directory);
	RING_API_REGISTER("get_uv_fs_o_dsync",ring_get_uv_fs_o_dsync);
	RING_API_REGISTER("get_uv_fs_o_excl",ring_get_uv_fs_o_excl);
	RING_API_REGISTER("get_uv_fs_o_exlock",ring_get_uv_fs_o_exlock);
	RING_API_REGISTER("get_uv_fs_o_noatime",ring_get_uv_fs_o_noatime);
	RING_API_REGISTER("get_uv_fs_o_noctty",ring_get_uv_fs_o_noctty);
	RING_API_REGISTER("get_uv_fs_o_nofollow",ring_get_uv_fs_o_nofollow);
	RING_API_REGISTER("get_uv_fs_o_nonblock",ring_get_uv_fs_o_nonblock);
	RING_API_REGISTER("get_uv_fs_o_random",ring_get_uv_fs_o_random);
	RING_API_REGISTER("get_uv_fs_o_rdonly",ring_get_uv_fs_o_rdonly);
	RING_API_REGISTER("get_uv_fs_o_rdwr",ring_get_uv_fs_o_rdwr);
	RING_API_REGISTER("get_uv_fs_o_sequential",ring_get_uv_fs_o_sequential);
	RING_API_REGISTER("get_uv_fs_o_short_lived",ring_get_uv_fs_o_short_lived);
	RING_API_REGISTER("get_uv_fs_o_symlink",ring_get_uv_fs_o_symlink);
	RING_API_REGISTER("get_uv_fs_o_sync",ring_get_uv_fs_o_sync);
	RING_API_REGISTER("get_uv_fs_o_temporary",ring_get_uv_fs_o_temporary);
	RING_API_REGISTER("get_uv_fs_o_trunc",ring_get_uv_fs_o_trunc);
	RING_API_REGISTER("get_uv_fs_o_wronly",ring_get_uv_fs_o_wronly);
	RING_API_REGISTER("get_uv_if_namesize",ring_get_uv_if_namesize);
	RING_API_REGISTER("new_uv_loop_t",ring_new_uv_loop_t);
	RING_API_REGISTER("new_managed_uv_loop_t",ring_new_managed_uv_loop_t);
	RING_API_REGISTER("destroy_uv_loop_t",ring_destroy_uv_loop_t);
	RING_API_REGISTER("get_uv_loop_t_data",ring_get_uv_loop_t_data);
	RING_API_REGISTER("set_uv_loop_t_data",ring_set_uv_loop_t_data);
	RING_API_REGISTER("new_uv_handle_t",ring_new_uv_handle_t);
	RING_API_REGISTER("new_managed_uv_handle_t",ring_new_managed_uv_handle_t);
	RING_API_REGISTER("destroy_uv_handle_t",ring_destroy_uv_handle_t);
	RING_API_REGISTER("get_uv_handle_t_loop",ring_get_uv_handle_t_loop);
	RING_API_REGISTER("set_uv_handle_t_loop",ring_set_uv_handle_t_loop);
	RING_API_REGISTER("get_uv_handle_t_type",ring_get_uv_handle_t_type);
	RING_API_REGISTER("set_uv_handle_t_type",ring_set_uv_handle_t_type);
	RING_API_REGISTER("get_uv_handle_t_data",ring_get_uv_handle_t_data);
	RING_API_REGISTER("set_uv_handle_t_data",ring_set_uv_handle_t_data);
	RING_API_REGISTER("new_uv_req_t",ring_new_uv_req_t);
	RING_API_REGISTER("new_managed_uv_req_t",ring_new_managed_uv_req_t);
	RING_API_REGISTER("destroy_uv_req_t",ring_destroy_uv_req_t);
	RING_API_REGISTER("get_uv_req_t_data",ring_get_uv_req_t_data);
	RING_API_REGISTER("set_uv_req_t_data",ring_set_uv_req_t_data);
	RING_API_REGISTER("get_uv_req_t_type",ring_get_uv_req_t_type);
	RING_API_REGISTER("set_uv_req_t_type",ring_set_uv_req_t_type);
	RING_API_REGISTER("new_uv_timer_t",ring_new_uv_timer_t);
	RING_API_REGISTER("new_managed_uv_timer_t",ring_new_managed_uv_timer_t);
	RING_API_REGISTER("destroy_uv_timer_t",ring_destroy_uv_timer_t);
	RING_API_REGISTER("new_uv_prepare_t",ring_new_uv_prepare_t);
	RING_API_REGISTER("new_managed_uv_prepare_t",ring_new_managed_uv_prepare_t);
	RING_API_REGISTER("destroy_uv_prepare_t",ring_destroy_uv_prepare_t);
	RING_API_REGISTER("new_uv_check_t",ring_new_uv_check_t);
	RING_API_REGISTER("new_managed_uv_check_t",ring_new_managed_uv_check_t);
	RING_API_REGISTER("destroy_uv_check_t",ring_destroy_uv_check_t);
	RING_API_REGISTER("new_uv_idle_t",ring_new_uv_idle_t);
	RING_API_REGISTER("new_managed_uv_idle_t",ring_new_managed_uv_idle_t);
	RING_API_REGISTER("destroy_uv_idle_t",ring_destroy_uv_idle_t);
	RING_API_REGISTER("new_uv_async_t",ring_new_uv_async_t);
	RING_API_REGISTER("new_managed_uv_async_t",ring_new_managed_uv_async_t);
	RING_API_REGISTER("destroy_uv_async_t",ring_destroy_uv_async_t);
	RING_API_REGISTER("new_uv_poll_t",ring_new_uv_poll_t);
	RING_API_REGISTER("new_managed_uv_poll_t",ring_new_managed_uv_poll_t);
	RING_API_REGISTER("destroy_uv_poll_t",ring_destroy_uv_poll_t);
	RING_API_REGISTER("new_uv_signal_t",ring_new_uv_signal_t);
	RING_API_REGISTER("new_managed_uv_signal_t",ring_new_managed_uv_signal_t);
	RING_API_REGISTER("destroy_uv_signal_t",ring_destroy_uv_signal_t);
	RING_API_REGISTER("get_uv_signal_t_signum",ring_get_uv_signal_t_signum);
	RING_API_REGISTER("set_uv_signal_t_signum",ring_set_uv_signal_t_signum);
	RING_API_REGISTER("new_uv_process_t",ring_new_uv_process_t);
	RING_API_REGISTER("new_managed_uv_process_t",ring_new_managed_uv_process_t);
	RING_API_REGISTER("destroy_uv_process_t",ring_destroy_uv_process_t);
	RING_API_REGISTER("get_uv_process_t_pid",ring_get_uv_process_t_pid);
	RING_API_REGISTER("set_uv_process_t_pid",ring_set_uv_process_t_pid);
	RING_API_REGISTER("new_uv_process_options_t",ring_new_uv_process_options_t);
	RING_API_REGISTER("new_managed_uv_process_options_t",ring_new_managed_uv_process_options_t);
	RING_API_REGISTER("destroy_uv_process_options_t",ring_destroy_uv_process_options_t);
	RING_API_REGISTER("new_uv_stdio_container_t",ring_new_uv_stdio_container_t);
	RING_API_REGISTER("new_managed_uv_stdio_container_t",ring_new_managed_uv_stdio_container_t);
	RING_API_REGISTER("destroy_uv_stdio_container_t",ring_destroy_uv_stdio_container_t);
	RING_API_REGISTER("new_uv_stream_t",ring_new_uv_stream_t);
	RING_API_REGISTER("new_managed_uv_stream_t",ring_new_managed_uv_stream_t);
	RING_API_REGISTER("destroy_uv_stream_t",ring_destroy_uv_stream_t);
	RING_API_REGISTER("new_uv_connect_t",ring_new_uv_connect_t);
	RING_API_REGISTER("new_managed_uv_connect_t",ring_new_managed_uv_connect_t);
	RING_API_REGISTER("destroy_uv_connect_t",ring_destroy_uv_connect_t);
	RING_API_REGISTER("get_uv_connect_t_handle",ring_get_uv_connect_t_handle);
	RING_API_REGISTER("set_uv_connect_t_handle",ring_set_uv_connect_t_handle);
	RING_API_REGISTER("new_uv_shutdown_t",ring_new_uv_shutdown_t);
	RING_API_REGISTER("new_managed_uv_shutdown_t",ring_new_managed_uv_shutdown_t);
	RING_API_REGISTER("destroy_uv_shutdown_t",ring_destroy_uv_shutdown_t);
	RING_API_REGISTER("get_uv_shutdown_t_handle",ring_get_uv_shutdown_t_handle);
	RING_API_REGISTER("set_uv_shutdown_t_handle",ring_set_uv_shutdown_t_handle);
	RING_API_REGISTER("new_uv_write_t",ring_new_uv_write_t);
	RING_API_REGISTER("new_managed_uv_write_t",ring_new_managed_uv_write_t);
	RING_API_REGISTER("destroy_uv_write_t",ring_destroy_uv_write_t);
	RING_API_REGISTER("get_uv_write_t_handle",ring_get_uv_write_t_handle);
	RING_API_REGISTER("set_uv_write_t_handle",ring_set_uv_write_t_handle);
	RING_API_REGISTER("new_uv_tcp_t",ring_new_uv_tcp_t);
	RING_API_REGISTER("new_managed_uv_tcp_t",ring_new_managed_uv_tcp_t);
	RING_API_REGISTER("destroy_uv_tcp_t",ring_destroy_uv_tcp_t);
	RING_API_REGISTER("new_uv_pipe_t",ring_new_uv_pipe_t);
	RING_API_REGISTER("new_managed_uv_pipe_t",ring_new_managed_uv_pipe_t);
	RING_API_REGISTER("destroy_uv_pipe_t",ring_destroy_uv_pipe_t);
	RING_API_REGISTER("new_uv_tty_t",ring_new_uv_tty_t);
	RING_API_REGISTER("new_managed_uv_tty_t",ring_new_managed_uv_tty_t);
	RING_API_REGISTER("destroy_uv_tty_t",ring_destroy_uv_tty_t);
	RING_API_REGISTER("new_uv_udp_t",ring_new_uv_udp_t);
	RING_API_REGISTER("new_managed_uv_udp_t",ring_new_managed_uv_udp_t);
	RING_API_REGISTER("destroy_uv_udp_t",ring_destroy_uv_udp_t);
	RING_API_REGISTER("get_uv_udp_t_send_queue_size",ring_get_uv_udp_t_send_queue_size);
	RING_API_REGISTER("set_uv_udp_t_send_queue_size",ring_set_uv_udp_t_send_queue_size);
	RING_API_REGISTER("get_uv_udp_t_send_queue_count",ring_get_uv_udp_t_send_queue_count);
	RING_API_REGISTER("set_uv_udp_t_send_queue_count",ring_set_uv_udp_t_send_queue_count);
	RING_API_REGISTER("new_uv_udp_send_t",ring_new_uv_udp_send_t);
	RING_API_REGISTER("new_managed_uv_udp_send_t",ring_new_managed_uv_udp_send_t);
	RING_API_REGISTER("destroy_uv_udp_send_t",ring_destroy_uv_udp_send_t);
	RING_API_REGISTER("new_uv_fs_event_t",ring_new_uv_fs_event_t);
	RING_API_REGISTER("new_managed_uv_fs_event_t",ring_new_managed_uv_fs_event_t);
	RING_API_REGISTER("destroy_uv_fs_event_t",ring_destroy_uv_fs_event_t);
	RING_API_REGISTER("new_uv_fs_poll_t",ring_new_uv_fs_poll_t);
	RING_API_REGISTER("new_managed_uv_fs_poll_t",ring_new_managed_uv_fs_poll_t);
	RING_API_REGISTER("destroy_uv_fs_poll_t",ring_destroy_uv_fs_poll_t);
	RING_API_REGISTER("new_uv_fs_t",ring_new_uv_fs_t);
	RING_API_REGISTER("new_managed_uv_fs_t",ring_new_managed_uv_fs_t);
	RING_API_REGISTER("destroy_uv_fs_t",ring_destroy_uv_fs_t);
	RING_API_REGISTER("new_uv_timespec_t",ring_new_uv_timespec_t);
	RING_API_REGISTER("new_managed_uv_timespec_t",ring_new_managed_uv_timespec_t);
	RING_API_REGISTER("destroy_uv_timespec_t",ring_destroy_uv_timespec_t);
	RING_API_REGISTER("new_uv_stat_t",ring_new_uv_stat_t);
	RING_API_REGISTER("new_managed_uv_stat_t",ring_new_managed_uv_stat_t);
	RING_API_REGISTER("destroy_uv_stat_t",ring_destroy_uv_stat_t);
	RING_API_REGISTER("new_uv_work_t",ring_new_uv_work_t);
	RING_API_REGISTER("new_managed_uv_work_t",ring_new_managed_uv_work_t);
	RING_API_REGISTER("destroy_uv_work_t",ring_destroy_uv_work_t);
	RING_API_REGISTER("new_uv_getaddrinfo_t",ring_new_uv_getaddrinfo_t);
	RING_API_REGISTER("new_managed_uv_getaddrinfo_t",ring_new_managed_uv_getaddrinfo_t);
	RING_API_REGISTER("destroy_uv_getaddrinfo_t",ring_destroy_uv_getaddrinfo_t);
	RING_API_REGISTER("new_uv_getnameinfo_t",ring_new_uv_getnameinfo_t);
	RING_API_REGISTER("new_managed_uv_getnameinfo_t",ring_new_managed_uv_getnameinfo_t);
	RING_API_REGISTER("destroy_uv_getnameinfo_t",ring_destroy_uv_getnameinfo_t);
	RING_API_REGISTER("new_uv_lib_t",ring_new_uv_lib_t);
	RING_API_REGISTER("new_managed_uv_lib_t",ring_new_managed_uv_lib_t);
	RING_API_REGISTER("destroy_uv_lib_t",ring_destroy_uv_lib_t);
	RING_API_REGISTER("new_uv_thread_t",ring_new_uv_thread_t);
	RING_API_REGISTER("new_managed_uv_thread_t",ring_new_managed_uv_thread_t);
	RING_API_REGISTER("destroy_uv_thread_t",ring_destroy_uv_thread_t);
	RING_API_REGISTER("new_uv_key_t",ring_new_uv_key_t);
	RING_API_REGISTER("new_managed_uv_key_t",ring_new_managed_uv_key_t);
	RING_API_REGISTER("destroy_uv_key_t",ring_destroy_uv_key_t);
	RING_API_REGISTER("new_uv_once_t",ring_new_uv_once_t);
	RING_API_REGISTER("new_managed_uv_once_t",ring_new_managed_uv_once_t);
	RING_API_REGISTER("destroy_uv_once_t",ring_destroy_uv_once_t);
	RING_API_REGISTER("new_uv_mutex_t",ring_new_uv_mutex_t);
	RING_API_REGISTER("new_managed_uv_mutex_t",ring_new_managed_uv_mutex_t);
	RING_API_REGISTER("destroy_uv_mutex_t",ring_destroy_uv_mutex_t);
	RING_API_REGISTER("new_uv_rwlock_t",ring_new_uv_rwlock_t);
	RING_API_REGISTER("new_managed_uv_rwlock_t",ring_new_managed_uv_rwlock_t);
	RING_API_REGISTER("destroy_uv_rwlock_t",ring_destroy_uv_rwlock_t);
	RING_API_REGISTER("new_uv_sem_t",ring_new_uv_sem_t);
	RING_API_REGISTER("new_managed_uv_sem_t",ring_new_managed_uv_sem_t);
	RING_API_REGISTER("destroy_uv_sem_t",ring_destroy_uv_sem_t);
	RING_API_REGISTER("new_uv_cond_t",ring_new_uv_cond_t);
	RING_API_REGISTER("new_managed_uv_cond_t",ring_new_managed_uv_cond_t);
	RING_API_REGISTER("destroy_uv_cond_t",ring_destroy_uv_cond_t);
	RING_API_REGISTER("new_uv_barrier_t",ring_new_uv_barrier_t);
	RING_API_REGISTER("new_managed_uv_barrier_t",ring_new_managed_uv_barrier_t);
	RING_API_REGISTER("destroy_uv_barrier_t",ring_destroy_uv_barrier_t);
	RING_API_REGISTER("new_uv_buf_t",ring_new_uv_buf_t);
	RING_API_REGISTER("new_managed_uv_buf_t",ring_new_managed_uv_buf_t);
	RING_API_REGISTER("destroy_uv_buf_t",ring_destroy_uv_buf_t);
	RING_API_REGISTER("get_uv_buf_t_base",ring_get_uv_buf_t_base);
	RING_API_REGISTER("set_uv_buf_t_base",ring_set_uv_buf_t_base);
	RING_API_REGISTER("get_uv_buf_t_len",ring_get_uv_buf_t_len);
	RING_API_REGISTER("set_uv_buf_t_len",ring_set_uv_buf_t_len);
	RING_API_REGISTER("new_uv_file",ring_new_uv_file);
	RING_API_REGISTER("new_managed_uv_file",ring_new_managed_uv_file);
	RING_API_REGISTER("destroy_uv_file",ring_destroy_uv_file);
	RING_API_REGISTER("new_uv_os_sock_t",ring_new_uv_os_sock_t);
	RING_API_REGISTER("new_managed_uv_os_sock_t",ring_new_managed_uv_os_sock_t);
	RING_API_REGISTER("destroy_uv_os_sock_t",ring_destroy_uv_os_sock_t);
	RING_API_REGISTER("new_uv_os_fd_t",ring_new_uv_os_fd_t);
	RING_API_REGISTER("new_managed_uv_os_fd_t",ring_new_managed_uv_os_fd_t);
	RING_API_REGISTER("destroy_uv_os_fd_t",ring_destroy_uv_os_fd_t);
	RING_API_REGISTER("new_uv_pid_t",ring_new_uv_pid_t);
	RING_API_REGISTER("new_managed_uv_pid_t",ring_new_managed_uv_pid_t);
	RING_API_REGISTER("destroy_uv_pid_t",ring_destroy_uv_pid_t);
	RING_API_REGISTER("new_uv_rusage_t",ring_new_uv_rusage_t);
	RING_API_REGISTER("new_managed_uv_rusage_t",ring_new_managed_uv_rusage_t);
	RING_API_REGISTER("destroy_uv_rusage_t",ring_destroy_uv_rusage_t);
	RING_API_REGISTER("new_uv_cpu_info_t",ring_new_uv_cpu_info_t);
	RING_API_REGISTER("new_managed_uv_cpu_info_t",ring_new_managed_uv_cpu_info_t);
	RING_API_REGISTER("destroy_uv_cpu_info_t",ring_destroy_uv_cpu_info_t);
	RING_API_REGISTER("new_uv_interface_address_t",ring_new_uv_interface_address_t);
	RING_API_REGISTER("new_managed_uv_interface_address_t",ring_new_managed_uv_interface_address_t);
	RING_API_REGISTER("destroy_uv_interface_address_t",ring_destroy_uv_interface_address_t);
	RING_API_REGISTER("new_uv_passwd_t",ring_new_uv_passwd_t);
	RING_API_REGISTER("new_managed_uv_passwd_t",ring_new_managed_uv_passwd_t);
	RING_API_REGISTER("destroy_uv_passwd_t",ring_destroy_uv_passwd_t);
}
