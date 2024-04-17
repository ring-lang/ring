/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbs.inl
 *
 */

/* Osbs library (Operating System Basic Services) */

#include "osbs.hxx"

__EXTERN_C

void _osbs_start_sockets(void);

void _osbs_finish_sockets(void);

void _osbs_directory_alloc(void);

void _osbs_file_alloc(void);

void _osbs_mutex_alloc(void);

void _osbs_proc_alloc(void);

void _osbs_dlib_alloc(void);

void _osbs_thread_alloc(void);

void _osbs_socket_alloc(void);

void _osbs_directory_dealloc(void);

void _osbs_file_dealloc(void);

void _osbs_mutex_dealloc(void);

void _osbs_proc_dealloc(void);

void _osbs_dlib_dealloc(void);

void _osbs_thread_dealloc(void);

void _osbs_socket_dealloc(void);

__END_C
