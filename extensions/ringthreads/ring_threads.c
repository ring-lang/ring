#include "ring.h"

/* Copyright (c) 2021 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "tinycthread/tinycthread.h"
#include "tinycthread/tinycthread.c"

VM *pThreadsLibVM = NULL ;

List *pLibThreadsEvents = NULL ;

int custom_thrd_start_t(void *arg)
{
	if ( ((const char *) arg)[0] != '\0')
		ring_vm_runcode(pThreadsLibVM,(const char *) arg);
	return 0;
}

void *RegisterEvent(const char *cEvent)
{
	if (pLibThreadsEvents == NULL)
		pLibThreadsEvents = ring_list_new(0);

	ring_list_addstring(pLibThreadsEvents,cEvent);
	return (void *) ring_list_getstring(pLibThreadsEvents,ring_list_getsize(pLibThreadsEvents));
}


RING_FUNC(ring_get_time_utc)
{
	RING_API_RETNUMBER(TIME_UTC);
}

RING_FUNC(ring_get_tinycthread_version_major)
{
	RING_API_RETNUMBER(TINYCTHREAD_VERSION_MAJOR);
}

RING_FUNC(ring_get_tinycthread_version_minor)
{
	RING_API_RETNUMBER(TINYCTHREAD_VERSION_MINOR);
}

RING_FUNC(ring_get_tinycthread_version)
{
	RING_API_RETNUMBER(TINYCTHREAD_VERSION);
}

RING_FUNC(ring_get_thrd_error)
{
	RING_API_RETNUMBER(thrd_error);
}

RING_FUNC(ring_get_thrd_success)
{
	RING_API_RETNUMBER(thrd_success);
}

RING_FUNC(ring_get_thrd_timedout)
{
	RING_API_RETNUMBER(thrd_timedout);
}

RING_FUNC(ring_get_thrd_busy)
{
	RING_API_RETNUMBER(thrd_busy);
}

RING_FUNC(ring_get_thrd_nomem)
{
	RING_API_RETNUMBER(thrd_nomem);
}

RING_FUNC(ring_get_mtx_plain)
{
	RING_API_RETNUMBER(mtx_plain);
}

RING_FUNC(ring_get_mtx_timed)
{
	RING_API_RETNUMBER(mtx_timed);
}

RING_FUNC(ring_get_mtx_recursive)
{
	RING_API_RETNUMBER(mtx_recursive);
}

RING_FUNC(ring_new_thrd_t)
{
	thrd_t *pMyPointer ;
	pMyPointer = (thrd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(thrd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"thrd_t");
}

RING_FUNC(ring_new_managed_thrd_t)
{
	thrd_t *pMyPointer ;
	pMyPointer = (thrd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(thrd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"thrd_t",ring_state_free);
}

RING_FUNC(ring_destroy_thrd_t)
{
	thrd_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"thrd_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_mtx_t)
{
	mtx_t *pMyPointer ;
	pMyPointer = (mtx_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(mtx_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"mtx_t");
}

RING_FUNC(ring_new_managed_mtx_t)
{
	mtx_t *pMyPointer ;
	pMyPointer = (mtx_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(mtx_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"mtx_t",ring_state_free);
}

RING_FUNC(ring_destroy_mtx_t)
{
	mtx_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"mtx_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_cnd_t)
{
	cnd_t *pMyPointer ;
	pMyPointer = (cnd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(cnd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"cnd_t");
}

RING_FUNC(ring_new_managed_cnd_t)
{
	cnd_t *pMyPointer ;
	pMyPointer = (cnd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(cnd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"cnd_t",ring_state_free);
}

RING_FUNC(ring_destroy_cnd_t)
{
	cnd_t *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"cnd_t");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_mtx_init)
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
	RING_API_RETNUMBER(mtx_init((mtx_t *) RING_API_GETCPOINTER(1,"mtx_t"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_mtx_destroy)
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
	mtx_destroy((mtx_t *) RING_API_GETCPOINTER(1,"mtx_t"));
}


RING_FUNC(ring_mtx_lock)
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
	RING_API_RETNUMBER(mtx_lock((mtx_t *) RING_API_GETCPOINTER(1,"mtx_t")));
}


RING_FUNC(ring_mtx_timedlock)
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
	RING_API_RETNUMBER(mtx_timedlock((mtx_t *) RING_API_GETCPOINTER(1,"mtx_t"),(struct timespec *) RING_API_GETCPOINTER(2,"struct timespec")));
}


RING_FUNC(ring_mtx_trylock)
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
	RING_API_RETNUMBER(mtx_trylock((mtx_t *) RING_API_GETCPOINTER(1,"mtx_t")));
}


RING_FUNC(ring_mtx_unlock)
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
	RING_API_RETNUMBER(mtx_unlock((mtx_t *) RING_API_GETCPOINTER(1,"mtx_t")));
}


RING_FUNC(ring_cnd_init)
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
	RING_API_RETNUMBER(cnd_init((cnd_t *) RING_API_GETCPOINTER(1,"cnd_t")));
}


RING_FUNC(ring_cnd_destroy)
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
	cnd_destroy((cnd_t *) RING_API_GETCPOINTER(1,"cnd_t"));
}


RING_FUNC(ring_cnd_signal)
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
	RING_API_RETNUMBER(cnd_signal((cnd_t *) RING_API_GETCPOINTER(1,"cnd_t")));
}


RING_FUNC(ring_cnd_broadcast)
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
	RING_API_RETNUMBER(cnd_broadcast((cnd_t *) RING_API_GETCPOINTER(1,"cnd_t")));
}


RING_FUNC(ring_cnd_wait)
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
	RING_API_RETNUMBER(cnd_wait((cnd_t *) RING_API_GETCPOINTER(1,"cnd_t"),(mtx_t *) RING_API_GETCPOINTER(2,"mtx_t")));
}


RING_FUNC(ring_cnd_timedwait)
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
	RING_API_RETNUMBER(cnd_timedwait((cnd_t *) RING_API_GETCPOINTER(1,"cnd_t"),(mtx_t *) RING_API_GETCPOINTER(2,"mtx_t"),(struct timespec *) RING_API_GETCPOINTER(3,"struct timespec")));
}

RING_FUNC(ring_thrd_create)
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

	if (pThreadsLibVM == NULL)
		pThreadsLibVM = (VM *) pPointer;

	RING_API_RETNUMBER(thrd_create( (thrd_t *) RING_API_GETCPOINTER(1,"thrd_t"),custom_thrd_start_t,RegisterEvent(RING_API_GETSTRING(2)) ));
}

RING_FUNC(ring_thrd_current)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		thrd_t *pValue ; 
		pValue = (thrd_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(thrd_t)) ;
		*pValue = thrd_current();
		RING_API_RETMANAGEDCPOINTER(pValue,"thrd_t",ring_state_free);
	}
}


RING_FUNC(ring_thrd_detach)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(thrd_detach(* (thrd_t  *) RING_API_GETCPOINTER(1,"thrd_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"thrd_t"));
}


RING_FUNC(ring_thrd_equal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(thrd_equal(* (thrd_t  *) RING_API_GETCPOINTER(1,"thrd_t"),* (thrd_t  *) RING_API_GETCPOINTER(2,"thrd_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"thrd_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"thrd_t"));
}


RING_FUNC(ring_thrd_exit)
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
	thrd_exit( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_thrd_join)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(thrd_join(* (thrd_t  *) RING_API_GETCPOINTER(1,"thrd_t"),RING_API_GETINTPOINTER(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"thrd_t"));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_thrd_sleep)
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
	RING_API_RETNUMBER(thrd_sleep((struct timespec *) RING_API_GETCPOINTER(1,"struct timespec"),(struct timespec *) RING_API_GETCPOINTER(2,"struct timespec")));
}


RING_FUNC(ring_thrd_yield)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	thrd_yield();
}


RING_FUNC(ring_tss_delete)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	tss_delete(* (tss_t  *) RING_API_GETCPOINTER(1,"tss_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"tss_t"));
}


RING_FUNC(ring_tss_get)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(tss_get(* (tss_t  *) RING_API_GETCPOINTER(1,"tss_t")),"void");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"tss_t"));
}


RING_FUNC(ring_tss_set)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tss_set(* (tss_t  *) RING_API_GETCPOINTER(1,"tss_t"),(void *) RING_API_GETCPOINTER(2,"void")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"tss_t"));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("mtx_init",ring_mtx_init);
	ring_vm_funcregister("mtx_destroy",ring_mtx_destroy);
	ring_vm_funcregister("mtx_lock",ring_mtx_lock);
	ring_vm_funcregister("mtx_timedlock",ring_mtx_timedlock);
	ring_vm_funcregister("mtx_trylock",ring_mtx_trylock);
	ring_vm_funcregister("mtx_unlock",ring_mtx_unlock);
	ring_vm_funcregister("cnd_init",ring_cnd_init);
	ring_vm_funcregister("cnd_destroy",ring_cnd_destroy);
	ring_vm_funcregister("cnd_signal",ring_cnd_signal);
	ring_vm_funcregister("cnd_broadcast",ring_cnd_broadcast);
	ring_vm_funcregister("cnd_wait",ring_cnd_wait);
	ring_vm_funcregister("cnd_timedwait",ring_cnd_timedwait);
	ring_vm_funcregister("thrd_create",ring_thrd_create);
	ring_vm_funcregister("thrd_current",ring_thrd_current);
	ring_vm_funcregister("thrd_detach",ring_thrd_detach);
	ring_vm_funcregister("thrd_equal",ring_thrd_equal);
	ring_vm_funcregister("thrd_exit",ring_thrd_exit);
	ring_vm_funcregister("thrd_join",ring_thrd_join);
	ring_vm_funcregister("thrd_sleep",ring_thrd_sleep);
	ring_vm_funcregister("thrd_yield",ring_thrd_yield);
	ring_vm_funcregister("tss_delete",ring_tss_delete);
	ring_vm_funcregister("tss_get",ring_tss_get);
	ring_vm_funcregister("tss_set",ring_tss_set);
	ring_vm_funcregister("get_time_utc",ring_get_time_utc);
	ring_vm_funcregister("get_tinycthread_version_major",ring_get_tinycthread_version_major);
	ring_vm_funcregister("get_tinycthread_version_minor",ring_get_tinycthread_version_minor);
	ring_vm_funcregister("get_tinycthread_version",ring_get_tinycthread_version);
	ring_vm_funcregister("get_thrd_error",ring_get_thrd_error);
	ring_vm_funcregister("get_thrd_success",ring_get_thrd_success);
	ring_vm_funcregister("get_thrd_timedout",ring_get_thrd_timedout);
	ring_vm_funcregister("get_thrd_busy",ring_get_thrd_busy);
	ring_vm_funcregister("get_thrd_nomem",ring_get_thrd_nomem);
	ring_vm_funcregister("get_mtx_plain",ring_get_mtx_plain);
	ring_vm_funcregister("get_mtx_timed",ring_get_mtx_timed);
	ring_vm_funcregister("get_mtx_recursive",ring_get_mtx_recursive);
	ring_vm_funcregister("new_thrd_t",ring_new_thrd_t);
	ring_vm_funcregister("new_managed_thrd_t",ring_new_managed_thrd_t);
	ring_vm_funcregister("destroy_thrd_t",ring_destroy_thrd_t);
	ring_vm_funcregister("new_mtx_t",ring_new_mtx_t);
	ring_vm_funcregister("new_managed_mtx_t",ring_new_managed_mtx_t);
	ring_vm_funcregister("destroy_mtx_t",ring_destroy_mtx_t);
	ring_vm_funcregister("new_cnd_t",ring_new_cnd_t);
	ring_vm_funcregister("new_managed_cnd_t",ring_new_managed_cnd_t);
	ring_vm_funcregister("destroy_cnd_t",ring_destroy_cnd_t);
}
