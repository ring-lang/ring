/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: hfile.c
 *
 */

/* High-level operations in files and directories */

#include "hfile.h"
#include "hfileh.h"
#include "arrst.h"
#include "buffer.h"
#include "date.h"
#include "event.h"
#include "stream.h"
#include "strings.h"
#include <osbs/bfile.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

enum i_flag_t
{
    i_ekDIR_FORBIDDEN = 1,
    i_ekDIR_ENTRY = 2,
    i_ekHIDDEN_FILES = 3,
    i_ekHIDDEN_SUBDIRS = 4
};

/*---------------------------------------------------------------------------*/

bool_t hfile_dir(const char_t *pathname)
{
    file_type_t lfile_type;
    ferror_t error;
    if (bfile_lstat(pathname, &lfile_type, NULL, NULL, &error) == TRUE)
    {
        cassert(error == ekFOK);
        if (lfile_type == ekDIRECTORY)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t hfile_dir_create(const char_t *pathname, ferror_t *error)
{
    ferror_t err = ekFOK;
    cassert_no_null(pathname);
    cassert(str_len_c(pathname) > 0);
    if (hfile_dir(pathname) == FALSE)
    {
        uint32_t size = str_len_c(pathname);
        uint32_t i = size;
        uint32_t dirs = 0;
        char_t sep[64];
        while (i > 0)
        {
            if (pathname[i] == '\\' || pathname[i] == '/')
            {
                sep[dirs] = pathname[i];
                ((char_t *)pathname)[i] = '\0';
                dirs += 1;
                if (hfile_dir(pathname) == TRUE)
                    break;
            }

            i -= 1;
        }

        while (i < size)
        {
            if (pathname[i] == '\0')
            {
                cassert(dirs > 0);
                dirs -= 1;
                ((char_t *)pathname)[i] = sep[dirs];
                if (err == ekFOK)
                    bfile_dir_create(pathname, &err);
            }

            i += 1;
        }

        cassert(dirs == 0);
    }

    ptr_assign(error, err);
    return (bool_t)(err == ekFOK);
}

/*---------------------------------------------------------------------------*/

static void i_OnDeleteFile(void *empty, Event *e)
{
    const EvFileDir *params = event_params(e, EvFileDir);
    unref(empty);
    switch (event_type(e))
    {
    case ekEFILE:
        bfile_delete(params->pathname, NULL);
        break;
    case ekEENTRY:
        break;
    case ekEEXIT:
        bfile_dir_delete(params->pathname, NULL);
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

bool_t hfile_dir_destroy(const char_t *pathname, ferror_t *error)
{

    bool_t ok = hfile_dir_loop(pathname, listener(NULL, i_OnDeleteFile, void), TRUE, TRUE, error);
    if (ok == TRUE)
        ok = bfile_dir_delete(pathname, error);
    return ok;
}

/*---------------------------------------------------------------------------*/

static int i_cmp_entry(const DirEntry *entry1, const DirEntry *entry2)
{
    cassert_no_null(entry1);
    cassert_no_null(entry2);
    return str_cmp(entry1->name, tc(entry2->name));
}

/*---------------------------------------------------------------------------*/

ArrSt(DirEntry) *hfile_dir_list(const char_t *pathname, const bool_t subdirs, ferror_t *error)
{
    ArrSt(DirEntry) *entries = arrst_create(DirEntry);
    Dir *dir = bfile_dir_open(pathname, error);
    char_t filename[512];
    file_type_t type;
    uint64_t size;
    Date updated;
    ferror_t err;
    while (bfile_dir_get(dir, filename, 512, &type, &size, &updated, &err) == TRUE)
    {
        if (str_equ_c(filename, ".") == FALSE && str_equ_c(filename, "..") == FALSE)
        {
            if (type == ekARCHIVE || (type == ekDIRECTORY && subdirs == TRUE))
            {
                DirEntry *entry = arrst_new(entries, DirEntry);
                entry->name = str_c(filename);
                entry->size = size;
                entry->type = type;
                entry->date = updated;
            }
        }
    }

    bfile_dir_close(&dir);

    if (err == ekFNOFILES)
    {
        ptr_assign(error, ekFOK);
    }
    else
    {
        ptr_assign(error, err);
    }

    arrst_sort(entries, i_cmp_entry, DirEntry);
    return entries;
}

/*---------------------------------------------------------------------------*/

void hfile_dir_entry_remove(DirEntry *entry)
{
    cassert_no_null(entry);
    str_destroy(&entry->name);
}

/*---------------------------------------------------------------------------*/

static void i_dir_date(Date *date, Event *e)
{
    const EvFileDir *p = event_params(e, EvFileDir);
    Date ldate;
    if (bfile_lstat(p->pathname, NULL, NULL, &ldate, NULL) == TRUE)
    {
        if (date_cmp(&ldate, date) > 0)
            *date = ldate;
    }
}

/*---------------------------------------------------------------------------*/

Date hfile_date(const char_t *pathname, const bool_t recursive)
{
    Date date = kDATE_NULL;
    file_type_t type;
    if (bfile_lstat(pathname, &type, NULL, &date, NULL) == TRUE)
    {
        if (type == ekDIRECTORY && recursive == TRUE)
            hfile_dir_loop(pathname, listener(&date, i_dir_date, Date), TRUE, FALSE, NULL);
    }

    return date;
}

/*---------------------------------------------------------------------------*/

static bool_t i_except(const char_t *name, const char_t **except, const uint32_t except_size)
{
    register uint32_t i;
    if (except == NULL)
        return FALSE;

    for (i = 0; i < except_size; ++i)
    {
        if (str_equ_c(except[i], name) == TRUE)
            return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t hfile_dir_sync(const char_t *src, const char_t *dest, const bool_t recursive, const bool_t remove_in_dest, const char_t **except, const uint32_t except_size, ferror_t *error)
{
    ArrSt(DirEntry) *dir1, *dir2;
    const DirEntry *files1, *files2;
    uint32_t n1, n2, i1 = 0, i2 = 0;
    bool_t ok = TRUE;
    if (!hfile_dir(src))
    {
        ptr_assign(error, ekFNOPATH);
        return FALSE;
    }

    if (hfile_dir(dest) == FALSE)
    {
        if (bfile_dir_create(dest, error) == FALSE)
            return FALSE;
    }

    dir1 = hfile_dir_list(src, TRUE, NULL);
    dir2 = hfile_dir_list(dest, TRUE, NULL);
    files1 = arrst_all(dir1, DirEntry);
    files2 = arrst_all(dir2, DirEntry);
    n1 = arrst_size(dir1, DirEntry);
    n2 = arrst_size(dir2, DirEntry);

    /* Two dirs with entries */
    while (i1 < n1 && i2 < n2 && ok)
    {
        int cmp = str_cmp(files1[i1].name, tc(files2[i2].name));

        /* Entry with the same name in both dirs */
        if (cmp == 0)
        {
            if (i_except(tc(files1[i1].name), except, except_size) == FALSE)
            {
                if (files1[i1].type == ekDIRECTORY)
                {
                    if (recursive == TRUE)
                    {
                        String *path1 = str_cpath("%s/%s", src, tc(files1[i1].name));
                        String *path2 = str_cpath("%s/%s", src, tc(files2[i2].name));
                        ok = hfile_dir_sync(tc(path1), tc(path2), recursive, remove_in_dest, except, except_size, error);
                        str_destroy(&path1);
                        str_destroy(&path2);
                    }
                }
                /* This is a file */
                else
                {
                    /* Source file is more recent --> Copy */
                    if (date_cmp(&files1[i1].date, &files2[i2].date) > 0)
                    {
                        String *path = str_cpath("%s/%s", src, tc(files1[i1].name));
                        ok = hfile_copy(tc(path), dest, error);
                        str_destroy(&path);
                    }
                }
            }

            i1 += 1;
            i2 += 1;
        }

        /* Entry exists in src, but not in dest */
        else if (cmp < 0)
        {
            if (i_except(tc(files1[i1].name), except, except_size) == FALSE)
            {
                if (files1[i1].type == ekDIRECTORY)
                {
                    if (recursive == TRUE)
                    {
                        String *path1 = str_cpath("%s/%s", src, tc(files1[i1].name));
                        String *path2 = str_cpath("%s/%s", src, tc(files2[i2].name));
                        ok = hfile_dir_create(tc(path2), error);
                        if (ok == TRUE)
                            ok = hfile_dir_sync(tc(path1), tc(path2), recursive, remove_in_dest, except, except_size, error);
                        str_destroy(&path1);
                        str_destroy(&path2);
                    }
                }
                /* This is a file */
                else
                {
                    String *path = str_cpath("%s/%s", src, tc(files1[i1].name));
                    ok = hfile_copy(tc(path), dest, error);
                    str_destroy(&path);
                }
            }

            i1 += 1;
        }

        /* Entry exists in dest, but not in src */
        else
        {
            if (remove_in_dest == TRUE && i_except(tc(files2[i2].name), except, except_size) == FALSE)
            {
                String *path = str_cpath("%s/%s", dest, tc(files2[i2].name));

                if (files2[i2].type == ekDIRECTORY)
                    ok = hfile_dir_destroy(tc(path), error);
                else
                    ok = bfile_delete(tc(path), error);

                str_destroy(&path);
            }

            i2 += 1;
        }
    }

    /* Remaining entries in src */
    while (i1 < n1 && ok)
    {
        if (i_except(tc(files1[i1].name), except, except_size) == FALSE)
        {
            if (files1[i1].type == ekDIRECTORY)
            {
                if (recursive == TRUE)
                {
                    String *path1 = str_cpath("%s/%s", src, tc(files1[i1].name));
                    String *path2 = str_cpath("%s/%s", dest, tc(files1[i1].name));
                    ok = hfile_dir_sync(tc(path1), tc(path2), recursive, remove_in_dest, except, except_size, error);
                    str_destroy(&path1);
                    str_destroy(&path2);
                }
            }
            /* This is a file */
            else
            {
                String *path = str_cpath("%s/%s", src, tc(files1[i1].name));
                ok = hfile_copy(tc(path), dest, error);
                str_destroy(&path);
            }
        }

        i1 += 1;
    }

    /* Remaining entries in dest */
    while (i2 < n2 && remove_in_dest && ok)
    {
        if (i_except(tc(files2[i2].name), except, except_size) == FALSE)
        {
            String *path = str_cpath("%s/%s", dest, tc(files2[i2].name));

            if (files2[i2].type == ekDIRECTORY)
                ok = hfile_dir_destroy(tc(path), error);
            else
                ok = bfile_delete(tc(path), error);

            str_destroy(&path);
        }

        i2 += 1;
    }

    arrst_destroy(&dir1, hfile_dir_entry_remove, DirEntry);
    arrst_destroy(&dir2, hfile_dir_entry_remove, DirEntry);

    if (ok == TRUE)
        ptr_assign(error, ekFOK);

    return ok;
}

/*---------------------------------------------------------------------------*/

bool_t hfile_exists(const char_t *pathname, file_type_t *file_type)
{
    file_type_t lfile_type;
    ferror_t error;
    if (bfile_lstat(pathname, &lfile_type, NULL, NULL, &error) == TRUE)
    {
        cassert(error == ekFOK);
        ptr_assign(file_type, lfile_type);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t hfile_is_uptodate(const char_t *src, const char_t *dest)
{
    Date src_date;
    Date dest_date;
    if (bfile_lstat(src, NULL, NULL, &src_date, NULL) == FALSE)
        return TRUE;
    if (bfile_lstat(dest, NULL, NULL, &dest_date, NULL) == FALSE)
        return FALSE;
    if (date_cmp(&src_date, &dest_date) > 0)
        return FALSE;
    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_entire_file(const char_t *pathname, byte_t *file_data, const uint32_t file_size, ferror_t *error)
{
    File *file = NULL;
    uint32_t bytes_readed;
    bool_t readed = FALSE;

    file = bfile_open(pathname, ekREAD, error);
    if (__FALSE_EXPECTED(file == NULL))
        return FALSE;

    readed = bfile_read(file, file_data, file_size, &bytes_readed, error);
    bfile_close(&file);

    if (readed == TRUE && bytes_readed == file_size)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t hfile_copy(const char_t *from, const char_t *to, ferror_t *error)
{
    file_type_t type;
    uint64_t size;
    bool_t ok = FALSE;
    if (bfile_lstat(from, &type, &size, NULL, error) == TRUE)
    {
        if (type == ekARCHIVE)
        {
            String *tofile = NULL;
            Stream *sfrom = NULL;
            Stream *sto = NULL;

            if (hfile_dir(to) == TRUE)
            {
                const char_t *fname = str_filename(from);
                tofile = str_cpath("%s/%s", to, fname);
            }
            else
            {
                tofile = str_c(to);
            }

            sfrom = stm_from_file(from, error);
            sto = stm_to_file(tc(tofile), error);
            if (sfrom != NULL && sto != NULL)
            {
                stm_pipe(sfrom, sto, (uint32_t)size);
                ok = TRUE;
            }

            str_destroy(&tofile);
            ptr_destopt(stm_close, &sfrom, Stream);
            ptr_destopt(stm_close, &sto, Stream);
        }
        else
        {
            ptr_assign(error, ekFNOFILE);
        }
    }

    return ok;
}

/*---------------------------------------------------------------------------*/

Buffer *hfile_buffer(const char_t *pathname, ferror_t *error)
{
    file_type_t file_type;
    uint64_t file_size;
    if (bfile_lstat(pathname, &file_type, &file_size, NULL, error) == TRUE)
    {
        if (file_size < 0xFFFFFFFF)
        {
            Buffer *buffer = buffer_create((uint32_t)file_size);
            if (i_read_entire_file(pathname, buffer_data(buffer), (uint32_t)file_size, error) == TRUE)
            {
                return buffer;
            }
            else
            {
                buffer_destroy(&buffer);
                return NULL;
            }
        }
        else
        {
            ptr_assign(error, ekFBIG);
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

String *hfile_string(const char_t *pathname, ferror_t *error)
{
    file_type_t file_type;
    uint64_t file_size;
    if (bfile_lstat(pathname, &file_type, &file_size, NULL, error) == TRUE)
    {
        if (file_size < 0xFFFFFFFF)
        {
            String *str = str_reserve((uint32_t)file_size);
            if (i_read_entire_file(pathname, (byte_t *)tc(str), (uint32_t)file_size, error) == TRUE)
            {
                ((char_t *)tc(str))[(uint32_t)file_size] = '\0';
                return str;
            }
            else
            {
                str_destroy(&str);
                return NULL;
            }
        }
        else
        {
            ptr_assign(error, ekFBIG);
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

Stream *hfile_stream(const char_t *pathname, ferror_t *error)
{
    file_type_t file_type;
    uint64_t file_size;
    if (bfile_lstat(pathname, &file_type, &file_size, NULL, error) == TRUE)
    {
        if (file_size < 0xFFFFFFFF)
        {
            Stream *stm_in = stm_from_file(pathname, error);
            if (stm_in != NULL)
            {
                Stream *stm_out = stm_memory((uint32_t)file_size);
                stm_pipe(stm_in, stm_out, (uint32_t)file_size);
                stm_close(&stm_in);
                return stm_out;
            }
        }
        else
        {
            ptr_assign(error, ekFBIG);
        }
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

bool_t hfile_from_string(const char_t *pathname, const String *str, ferror_t *error)
{
    File *file = bfile_create(pathname, error);
    if (file != NULL)
    {
        const char_t *data = tc(str);
        uint32_t size = str_len(str);
        bool_t ok = bfile_write(file, (const byte_t *)data, size, NULL, error);
        bfile_close(&file);
        return ok;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t hfile_from_data(const char_t *pathname, const byte_t *data, const uint32_t size, ferror_t *error)
{
    File *file = bfile_create(pathname, error);
    if (file != NULL)
    {
        bool_t ok = bfile_write(file, data, size, NULL, error);
        bfile_close(&file);
        return ok;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_process_whole_directory(Listener *listener, const char_t *pathname, const uint32_t flags, const uint32_t depth_level, ferror_t *error)
{
    Dir *dir = bfile_dir_open(pathname, error);

    if (__TRUE_EXPECTED(dir != NULL))
    {
        bool_t continue_process = TRUE;
        char_t filename[512];
        file_type_t file_type;
        ferror_t file_error = ekFOK;
        uint64_t file_size;

        while (continue_process && bfile_dir_get(dir, filename, 512, &file_type, &file_size, NULL, &file_error) == TRUE)
        {
            switch (file_type)
            {
            case ekARCHIVE:
                if (filename[0] == '.' && BIT_TEST(flags, i_ekHIDDEN_FILES) == FALSE)
                    continue;

                {
                    String *fullname;
                    EvFileDir params;
                    fullname = str_printf("%s%c%s", pathname, DIR_SEPARATOR, filename);
                    params.filename = filename;
                    params.pathname = tc(fullname);
                    params.depth = depth_level;
                    listener_event(listener, ekEFILE, NULL, &params, &continue_process, void, EvFileDir, bool_t);
                    str_destroy(&fullname);
                }

                break;

            case ekDIRECTORY:
                if (str_equ_c(filename, ".") == TRUE)
                    continue;

                if (str_equ_c(filename, "..") == TRUE)
                    continue;

                if (filename[0] == '.' && BIT_TEST(flags, i_ekHIDDEN_SUBDIRS) == FALSE)
                    continue;

                if (BIT_TEST(flags, i_ekDIR_FORBIDDEN) == TRUE)
                {
                    cassert(FALSE);
                    continue;
                }

                if (BIT_TEST(flags, i_ekDIR_ENTRY) == FALSE)
                    continue;

                {
                    String *fullname;
                    EvFileDir params;
                    bool_t enter_subdir = TRUE;
                    fullname = str_printf("%s%c%s", pathname, DIR_SEPARATOR, filename);
                    params.filename = filename;
                    params.pathname = tc(fullname);
                    params.depth = depth_level;
                    listener_event(listener, ekEENTRY, NULL, &params, &enter_subdir, void, EvFileDir, bool_t);
                    if (enter_subdir == TRUE)
                    {
                        continue_process = i_process_whole_directory(listener, tc(fullname), flags, depth_level + 1, error);
                        listener_event(listener, ekEEXIT, NULL, &params, NULL, void, EvFileDir, void);
                    }

                    str_destroy(&fullname);
                }

                break;

            case ekOTHERFILE:
                break;

                cassert_default();
            }
        }

        if (file_error != ekFNOFILES)
            *error = file_error;

        bfile_dir_close(&dir);
        return (bool_t)(continue_process && *error == ekFOK);
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t hfile_dir_loop(const char_t *pathname, Listener *listener, const bool_t subdirs, const bool_t hiddens, ferror_t *error)
{
    uint32_t flags = 0;
    ferror_t ferror = ekFOK;
    if (subdirs == TRUE)
        BIT_SET(flags, i_ekDIR_ENTRY);

    if (hiddens == TRUE)
    {
        BIT_SET(flags, i_ekHIDDEN_FILES);
        if (subdirs == TRUE)
            BIT_SET(flags, i_ekHIDDEN_SUBDIRS);
    }

    i_process_whole_directory(listener, pathname, flags, 0, &ferror);
    ptr_assign(error, ferror);
    listener_destroy(&listener);
    return (bool_t)(ferror == ekFOK);
}

/*---------------------------------------------------------------------------*/

String *hfile_appdata(const char_t *filename)
{
    char_t appdata[512];
    char_t appname[512];
    String *name;
    String *appdir;
    String *path = NULL;
    bfile_dir_data(appdata, 512);
    bfile_dir_exec(appname, 512);
    str_split_pathext(appname, NULL, &name, NULL);
    appdir = str_cpath("%s/%s", appdata, tc(name));
    if (hfile_dir_create(tc(appdir), NULL) == TRUE)
        path = str_cpath("%s/%s/%s", appdata, tc(name), filename);
    str_destroy(&appdir);
    str_destroy(&name);
    return path;
}

/*---------------------------------------------------------------------------*/

String *hfile_exename(void)
{
    char_t appname[512];
    String *name;
    bfile_dir_exec(appname, 512);
    str_split_pathext(appname, NULL, &name, NULL);
    return name;
}

/*---------------------------------------------------------------------------*/

String *hfile_home_dir(const char_t *path)
{
    char_t homedir[512];
    bfile_dir_home(homedir, 512);
    return str_cpath("%s/%s", homedir, path);
}
