/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbs.h
 * https://nappgui.com/en/osbs/osbs.html
 *
 */

/* Operating System Basic Services */

#include "osbs.hxx"

__EXTERN_C

_osbs_api void osbs_start(void);

_osbs_api void osbs_finish(void);

_osbs_api platform_t osbs_platform(void);

_osbs_api win_t osbs_windows(void);

_osbs_api endian_t osbs_endian(void);

_osbs_api void osbs_memory_mt(Mutex *mutex);

__END_C
