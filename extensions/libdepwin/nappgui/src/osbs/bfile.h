/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bfile.h
 * https://nappgui.com/en/osbs/bfile.html
 *
 */

/* Basic file system access */

#include "osbs.hxx"

__EXTERN_C

_osbs_api uint32_t bfile_dir_work(char_t *pathname, const uint32_t size);

_osbs_api bool_t bfile_dir_set_work(const char_t *pathname, ferror_t *error);

_osbs_api uint32_t bfile_dir_home(char_t *pathname, const uint32_t size);

_osbs_api uint32_t bfile_dir_data(char_t *pathname, const uint32_t size);

_osbs_api uint32_t bfile_dir_exec(char_t *pathname, const uint32_t size);

_osbs_api bool_t bfile_dir_create(const char_t *pathname, ferror_t *error);

_osbs_api Dir *bfile_dir_open(const char_t *pathname, ferror_t *error);

_osbs_api void bfile_dir_close(Dir **dir);

_osbs_api bool_t bfile_dir_get(Dir *dir, char_t *name, const uint32_t size, file_type_t *type, uint64_t *fsize, Date *updated, ferror_t *error);

_osbs_api bool_t bfile_dir_delete(const char_t *pathname, ferror_t *error);

_osbs_api File *bfile_create(const char_t *pathname, ferror_t *error);

_osbs_api File *bfile_open(const char_t *pathname, const file_mode_t mode, ferror_t *error);

_osbs_api void bfile_close(File **file);

_osbs_api bool_t bfile_lstat(const char_t *pathname, file_type_t *type, uint64_t *size, Date *updated, ferror_t *error);

_osbs_api bool_t bfile_fstat(const File *file, file_type_t *type, uint64_t *size, Date *updated, ferror_t *error);

_osbs_api bool_t bfile_read(File *file, byte_t *data, const uint32_t size, uint32_t *rsize, ferror_t *error);

_osbs_api bool_t bfile_write(File *file, const byte_t *data, const uint32_t size, uint32_t *wsize, ferror_t *error);

_osbs_api bool_t bfile_seek(File *file, const int64_t offset, const file_seek_t whence, ferror_t *error);

_osbs_api uint64_t bfile_pos(const File *file);

_osbs_api bool_t bfile_delete(const char_t *pathname, ferror_t *error);

__END_C
