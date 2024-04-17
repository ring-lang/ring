/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmutex.h
 * https://nappgui.com/en/osbs/bmutex.html
 *
 */

/* Basic synchronization services */

#include "osbs.hxx"

__EXTERN_C

_osbs_api Mutex *bmutex_create(void);

_osbs_api void bmutex_close(Mutex **mutex);

_osbs_api void bmutex_lock(Mutex *mutex);

_osbs_api void bmutex_unlock(Mutex *mutex);

__END_C
