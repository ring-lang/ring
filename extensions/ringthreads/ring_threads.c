#include "ring.h"

/* Copyright (c) 2021 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "tinycthread/tinycthread.h"
#include "tinycthread/tinycthread.c"
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
	pMyPointer = (thrd_t *) RING_API_MALLOC(sizeof(thrd_t)) ;
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
	pMyPointer = (thrd_t *) RING_API_MALLOC(sizeof(thrd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"thrd_t",RING_API_FREEFUNC);
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
	pMyPointer = (thrd_t*) RING_API_GETCPOINTER(1,"thrd_t");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_mtx_t)
{
	mtx_t *pMyPointer ;
	pMyPointer = (mtx_t *) RING_API_MALLOC(sizeof(mtx_t)) ;
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
	pMyPointer = (mtx_t *) RING_API_MALLOC(sizeof(mtx_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"mtx_t",RING_API_FREEFUNC);
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
	pMyPointer = (mtx_t*) RING_API_GETCPOINTER(1,"mtx_t");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_cnd_t)
{
	cnd_t *pMyPointer ;
	pMyPointer = (cnd_t *) RING_API_MALLOC(sizeof(cnd_t)) ;
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
	pMyPointer = (cnd_t *) RING_API_MALLOC(sizeof(cnd_t)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"cnd_t",RING_API_FREEFUNC);
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
	pMyPointer = (cnd_t*) RING_API_GETCPOINTER(1,"cnd_t");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
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


void *custom_mtx_init(void)
{
	mtx_t *pMutex;
	pMutex = (mtx_t *) malloc(sizeof(mtx_t));
	if (pMutex == NULL) {
		printf(RING_OOM);
		exit(0);
	}
	mtx_init(pMutex,mtx_plain);
	return pMutex;
}

int custom_thrd_start_t(void *arg)
{
	List *pList;
	VM *pVM;
	const char *cEvent;
	if ( ((const char *) arg)[0] == '\0')
		return 0;

	pList = (List *) arg;
	cEvent = ring_list_getstring(pList,1);
	pVM = (VM *) ring_list_getpointer(pList,2);	
	ring_vm_runcodefromthread(pVM,cEvent);
	ring_list_delete(pList);
	return 0;
}

RING_FUNC(ring_thrd_create)
{
	List *pList;
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

	pList = ring_list_new(0);
	ring_list_addstring(pList,RING_API_GETSTRING(2));
	ring_list_addpointer(pList,pPointer);
	ring_vm_mutexfunctions((VM *) pPointer,custom_mtx_init,mtx_lock,mtx_unlock,mtx_destroy);
	RING_API_RETNUMBER(thrd_create( (thrd_t *) 	RING_API_GETCPOINTER(1,"thrd_t"),custom_thrd_start_t,pList ));

}

RING_FUNC(ring_mtx_destroy)
{
	mtx_t *pMutex;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMutex = (mtx_t *) RING_API_GETCPOINTER(1,"mtx_t");
	mtx_destroy(pMutex);
	free(pMutex);
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
		pValue = (thrd_t *) RING_API_MALLOC(sizeof(thrd_t)) ;
		*pValue = thrd_current();
		RING_API_RETMANAGEDCPOINTER(pValue,"thrd_t",RING_API_FREEFUNC);
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
		RING_API_FREE(RING_API_GETCPOINTER(1,"thrd_t"));
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
		RING_API_FREE(RING_API_GETCPOINTER(1,"thrd_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"thrd_t"));
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
		RING_API_FREE(RING_API_GETCPOINTER(1,"thrd_t"));
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
		RING_API_FREE(RING_API_GETCPOINTER(1,"tss_t"));
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
		RING_API_FREE(RING_API_GETCPOINTER(1,"tss_t"));
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
		RING_API_FREE(RING_API_GETCPOINTER(1,"tss_t"));
}

RING_LIBINIT
{
	RING_API_REGISTER("mtx_init",ring_mtx_init);
	RING_API_REGISTER("mtx_lock",ring_mtx_lock);
	RING_API_REGISTER("mtx_timedlock",ring_mtx_timedlock);
	RING_API_REGISTER("mtx_trylock",ring_mtx_trylock);
	RING_API_REGISTER("mtx_unlock",ring_mtx_unlock);
	RING_API_REGISTER("cnd_init",ring_cnd_init);
	RING_API_REGISTER("cnd_destroy",ring_cnd_destroy);
	RING_API_REGISTER("cnd_signal",ring_cnd_signal);
	RING_API_REGISTER("cnd_broadcast",ring_cnd_broadcast);
	RING_API_REGISTER("cnd_wait",ring_cnd_wait);
	RING_API_REGISTER("cnd_timedwait",ring_cnd_timedwait);
	RING_API_REGISTER("thrd_create",ring_thrd_create);
	RING_API_REGISTER("mtx_destroy",ring_mtx_destroy);
	RING_API_REGISTER("thrd_current",ring_thrd_current);
	RING_API_REGISTER("thrd_detach",ring_thrd_detach);
	RING_API_REGISTER("thrd_equal",ring_thrd_equal);
	RING_API_REGISTER("thrd_exit",ring_thrd_exit);
	RING_API_REGISTER("thrd_join",ring_thrd_join);
	RING_API_REGISTER("thrd_sleep",ring_thrd_sleep);
	RING_API_REGISTER("thrd_yield",ring_thrd_yield);
	RING_API_REGISTER("tss_delete",ring_tss_delete);
	RING_API_REGISTER("tss_get",ring_tss_get);
	RING_API_REGISTER("tss_set",ring_tss_set);
	RING_API_REGISTER("get_time_utc",ring_get_time_utc);
	RING_API_REGISTER("get_tinycthread_version_major",ring_get_tinycthread_version_major);
	RING_API_REGISTER("get_tinycthread_version_minor",ring_get_tinycthread_version_minor);
	RING_API_REGISTER("get_tinycthread_version",ring_get_tinycthread_version);
	RING_API_REGISTER("get_thrd_error",ring_get_thrd_error);
	RING_API_REGISTER("get_thrd_success",ring_get_thrd_success);
	RING_API_REGISTER("get_thrd_timedout",ring_get_thrd_timedout);
	RING_API_REGISTER("get_thrd_busy",ring_get_thrd_busy);
	RING_API_REGISTER("get_thrd_nomem",ring_get_thrd_nomem);
	RING_API_REGISTER("get_mtx_plain",ring_get_mtx_plain);
	RING_API_REGISTER("get_mtx_timed",ring_get_mtx_timed);
	RING_API_REGISTER("get_mtx_recursive",ring_get_mtx_recursive);
	RING_API_REGISTER("new_thrd_t",ring_new_thrd_t);
	RING_API_REGISTER("new_managed_thrd_t",ring_new_managed_thrd_t);
	RING_API_REGISTER("destroy_thrd_t",ring_destroy_thrd_t);
	RING_API_REGISTER("new_mtx_t",ring_new_mtx_t);
	RING_API_REGISTER("new_managed_mtx_t",ring_new_managed_mtx_t);
	RING_API_REGISTER("destroy_mtx_t",ring_destroy_mtx_t);
	RING_API_REGISTER("new_cnd_t",ring_new_cnd_t);
	RING_API_REGISTER("new_managed_cnd_t",ring_new_managed_cnd_t);
	RING_API_REGISTER("destroy_cnd_t",ring_destroy_cnd_t);
}
