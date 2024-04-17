/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: hfile.h
 * https://nappgui.com/en/core/hfile.html
 *
 */

/* High-level operations in files and directories */

#include "core.hxx"

__EXTERN_C

_core_api bool_t hfile_dir(const char_t *pathname);

_core_api bool_t hfile_dir_create(const char_t *pathname, ferror_t *error);

_core_api bool_t hfile_dir_destroy(const char_t *pathname, ferror_t *error);

_core_api ArrSt(DirEntry) *hfile_dir_list(const char_t *pathname, const bool_t subdirs, ferror_t *error);

_core_api void hfile_dir_entry_remove(DirEntry *entry);

_core_api Date hfile_date(const char_t *pathname, const bool_t recursive);

_core_api bool_t hfile_dir_sync(const char_t *src, const char_t *dest, const bool_t recursive, const bool_t remove_in_dest, const char_t **except, const uint32_t except_size, ferror_t *error);

_core_api bool_t hfile_exists(const char_t *pathname, file_type_t *file_type);

_core_api bool_t hfile_is_uptodate(const char_t *src, const char_t *dest);

_core_api bool_t hfile_copy(const char_t *from, const char_t *to, ferror_t *error);

_core_api Buffer *hfile_buffer(const char_t *pathname, ferror_t *error);

_core_api String *hfile_string(const char_t *pathname, ferror_t *error);

_core_api Stream *hfile_stream(const char_t *pathname, ferror_t *error);

_core_api bool_t hfile_from_string(const char_t *pathname, const String *str, ferror_t *error);

_core_api bool_t hfile_from_data(const char_t *pathname, const byte_t *data, const uint32_t size, ferror_t *error);

_core_api bool_t hfile_dir_loop(const char_t *pathname, Listener *listener, const bool_t subdirs, const bool_t hiddens, ferror_t *error);

_core_api String *hfile_appdata(const char_t *filename);

_core_api String *hfile_home_dir(const char_t *path);

__END_C
