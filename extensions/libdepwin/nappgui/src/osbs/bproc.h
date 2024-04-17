/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bproc.h
 * https://nappgui.com/en/osbs/bproc.html
 *
 */

/* Processes */

#include "osbs.hxx"

__EXTERN_C

_osbs_api Proc *bproc_exec(const char_t *command, perror_t *error);

_osbs_api void bproc_close(Proc **proc);

_osbs_api bool_t bproc_cancel(Proc *proc);

_osbs_api uint32_t bproc_wait(Proc *proc);

_osbs_api bool_t bproc_finish(Proc *proc, uint32_t *code);

_osbs_api bool_t bproc_read(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error);

_osbs_api bool_t bproc_eread(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error);

_osbs_api bool_t bproc_write(Proc *proc, const byte_t *data, const uint32_t size, uint32_t *wsize, perror_t *error);

_osbs_api bool_t bproc_read_close(Proc *proc);

_osbs_api bool_t bproc_eread_close(Proc *proc);

_osbs_api bool_t bproc_write_close(Proc *proc);

_osbs_api void bproc_exit(const uint32_t code);

__END_C
