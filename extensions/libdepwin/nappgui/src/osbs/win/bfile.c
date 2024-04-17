/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bfile.c
 *
 */

/* Basic file system access */

#include "osbs.inl"
#include "bfile.h"
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <ShlObj.h>
#include <sewer/warn.hxx>

struct _dir_t
{
    HANDLE handle;
    WIN32_FIND_DATA find;
    BOOL more_files;
    DWORD find_next_error;
};

static const uint32_t i_NUM_RETRYS = 10;

/*---------------------------------------------------------------------------*/

static void i_file_error(ferror_t *error)
{
    if (error != NULL)
    {
        DWORD err = GetLastError();
        if (err == ERROR_ALREADY_EXISTS)
            *error = ekFEXISTS;
        else if (err == ERROR_PATH_NOT_FOUND)
            *error = ekFNOPATH;
        else if (err == ERROR_FILE_NOT_FOUND || err == ERROR_INVALID_NAME)
            *error = ekFNOFILE;
        else if (err == ERROR_DIR_NOT_EMPTY)
            *error = ekFNOEMPTY;
        else if (err == ERROR_ACCESS_DENIED)
            *error = ekFNOACCESS;
        else if (err == ERROR_SHARING_VIOLATION)
            *error = ekFLOCK;
        else
        {
            cassert_msg(FALSE, "Unknown file error");
            *error = ekFUNDEF;
        }
    }
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_work(char_t *pathname, const uint32_t size)
{
    WCHAR pathnamew[MAX_PATH + 1];
    GetCurrentDirectory(sizeof(pathnamew), pathnamew);
    return unicode_convers((const char_t *)pathnamew, pathname, ekUTF16, ekUTF8, size);
}

/*---------------------------------------------------------------------------*/

bool_t bfile_dir_set_work(const char_t *pathname, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 1];
    unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (SetCurrentDirectory(pathnamew) != 0)
    {
        ptr_assign(error, ekFOK);
        return TRUE;
    }
    else
    {
        ptr_assign(error, ekFUNDEF);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_home(char_t *pathname, const uint32_t size)
{
    WCHAR wname[MAX_PATH + 1];
    if (SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, wname) == S_OK)
        return unicode_convers((const char_t *)wname, pathname, ekUTF16, ekUTF8, size);
    pathname[0] = '\0';
    return 1;
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_data(char_t *pathname, const uint32_t size)
{
    WCHAR wname[MAX_PATH + 1];
    if (SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, wname) == S_OK)
        return unicode_convers((const char_t *)wname, pathname, ekUTF16, ekUTF8, size);
    pathname[0] = '\0';
    return 1;
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_exec(char_t *pathname, const uint32_t size)
{
    TCHAR wname[MAX_PATH + 1];
    GetModuleFileName(NULL, wname, MAX_PATH + 1);
    return unicode_convers((const char_t *)wname, pathname, ekUTF16, ekUTF8, size);
}

/*---------------------------------------------------------------------------*/

bool_t bfile_dir_create(const char_t *pathname, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 1];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        if (CreateDirectory(pathnamew, NULL) != 0)
        {
            ptr_assign(error, ekFOK);
            return TRUE;
        }
        else
        {
            i_file_error(error);
            return FALSE;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

Dir *bfile_dir_open(const char_t *pathname, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 10];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        HANDLE handle;
        WIN32_FIND_DATA find;
        wcscat_s(pathnamew, MAX_PATH + 10, L"\\*.*");
        handle = FindFirstFile(pathnamew, &find);
        if (handle != INVALID_HANDLE_VALUE)
        {
            Dir *dir = (Dir *)bmem_malloc(sizeof(Dir));
            _osbs_directory_alloc();
            dir->handle = handle;
            dir->find = find;
            dir->more_files = TRUE;
            ptr_assign(error, ekFOK);
            return dir;
        }
        else
        {
            i_file_error(error);
            return NULL;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

void bfile_dir_close(Dir **dir)
{
    BOOL ok;
    cassert_no_null(dir);
    cassert_no_null(*dir);
    ok = FindClose((*dir)->handle);
    cassert_unref(ok == TRUE, ok);
    bmem_free((byte_t *)*dir);
    *dir = NULL;
    _osbs_directory_dealloc();
}

/*---------------------------------------------------------------------------*/

static file_type_t i_file_type(DWORD file_attrs)
{
    if ((file_attrs & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
        return ekDIRECTORY;
    if ((file_attrs & FILE_ATTRIBUTE_DEVICE) == FILE_ATTRIBUTE_DEVICE)
        return ekOTHERFILE;
    if ((file_attrs & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
        return ekARCHIVE;
    if ((file_attrs & FILE_ATTRIBUTE_NORMAL) == FILE_ATTRIBUTE_NORMAL)
    {
        /* The file does not have other attributes set. This attribute is valid only if used alone. */
        cassert(file_attrs == FILE_ATTRIBUTE_NORMAL);
        return ekARCHIVE;
    }
    return ekOTHERFILE;
}

/*---------------------------------------------------------------------------*/

static void i_file_date(FILETIME *ftime, Date *date)
{
    BOOL ok;
    FILETIME ft;
    SYSTEMTIME st;
    cassert_no_null(ftime);
    cassert_no_null(date);
    ok = FileTimeToLocalFileTime(ftime, &ft);
    FileTimeToSystemTime(&ft, &st);
    cassert_unref(ok == TRUE, ok);
    date->wday = (week_day_t)st.wDayOfWeek;
    date->mday = (uint8_t)st.wDay;
    date->month = (month_t)st.wMonth;
    date->year = (uint16_t)st.wYear;
    date->hour = (uint8_t)st.wHour;
    date->minute = (uint8_t)st.wMinute;
    date->second = (uint8_t)st.wSecond;
}

/*---------------------------------------------------------------------------*/

bool_t bfile_dir_get(Dir *dir, char_t *name, const uint32_t size, file_type_t *type, uint64_t *fsize, Date *updated, ferror_t *error)
{
    cassert_no_null(dir);
    if (dir->more_files == TRUE)
    {
        if (name != NULL)
        {
            uint32_t nb = unicode_convers((const char_t *)dir->find.cFileName, name, ekUTF16, ekUTF8, size);
            if (nb == size)
            {
                ptr_assign(error, ekFBIGNAME);
                return FALSE;
            }
        }

        if (type != NULL)
            *type = i_file_type(dir->find.dwFileAttributes);

        if (fsize != NULL)
        {
            LARGE_INTEGER lfsize;
            lfsize.LowPart = dir->find.nFileSizeLow;
            lfsize.HighPart = dir->find.nFileSizeHigh;
            *fsize = (uint64_t)lfsize.QuadPart;
        }

        if (updated != NULL)
            i_file_date(&dir->find.ftLastWriteTime, updated);

        if (FindNextFile(dir->handle, &dir->find) == FALSE)
        {
            dir->find_next_error = GetLastError();
            dir->more_files = FALSE;
        }

        ptr_assign(error, ekFOK);
        return TRUE;
    }
    else
    {
        if (error != NULL)
        {
            if (dir->find_next_error == ERROR_NO_MORE_FILES)
                *error = ekFNOFILES;
            else
                i_file_error(error);
        }

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bfile_dir_delete(const char_t *pathname, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 1];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        BOOL result = RemoveDirectory(pathnamew);
        if (result == TRUE)
        {
            ptr_assign(error, ekFOK);
            return TRUE;
        }
        else
        {
            i_file_error(error);
            return FALSE;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

File *bfile_create(const char_t *pathname, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 1];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        HANDLE file = CreateFile(pathnamew, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (file != INVALID_HANDLE_VALUE)
        {
            _osbs_file_alloc();
            ptr_assign(error, ekFOK);
            return (File *)file;
        }
        else
        {
            i_file_error(error);
            return NULL;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

File *bfile_open(const char_t *pathname, const file_mode_t mode, ferror_t *error)
{
    /*#C.h2("OJO!!! comprobar bloqueo en archivos escritura")*/
    WCHAR pathnamew[MAX_PATH + 1];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        DWORD access = 0;
        HANDLE file = 0;
        switch (mode)
        {
        case ekREAD:
            access = GENERIC_READ;
            break;
        case ekWRITE:
        case ekAPPEND:
            access = GENERIC_READ | GENERIC_WRITE;
            break;
            cassert_default();
        }

        file = CreateFile(pathnamew, access, 0 /*dwSharedMode*/, NULL /*lpSecurityAttributes */, OPEN_EXISTING, 0, NULL /*hTemplateFile*/);
        if (file != INVALID_HANDLE_VALUE)
        {
            (void)_osbs_file_alloc();

            if (mode == ekAPPEND)
                SetFilePointer(file, 0, NULL, FILE_END);

            ptr_assign(error, ekFOK);

#if defined(__x64__)
            // Avoid warning C4306: 'type cast' : conversion from 'HFILE' to 'File *' of greater size
            return (File *)(uint64_t)file;
#else
            return (File *)file;
#endif
        }
        else
        {
            i_file_error(error);
            return NULL;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

void bfile_close(File **file)
{
    BOOL ok;
    cassert_no_null(file);
    cassert_no_null(*file);
    ok = CloseHandle((HANDLE)*file);
    cassert(ok != 0);
    _osbs_file_dealloc();
    *file = NULL;
}

/*---------------------------------------------------------------------------*/

/*
static bool_t i_file_stat(HANDLE file, file_type_t *file_type, uint64_t *file_size, enum io_error_t *error)
{
    if (file_type != NULL)
    {
        ekARCHIVE,
        ekDIRECTORY,
        ekFILE_SYMBOLIC_LINK,
        ekFILE_CHARACTER_DEVICE,
        ekFILE_BLOCK_DEVICE,
        ekFILE_PIPE,
        ekFILE_SOCKET,
        ekFILE_UNKNOW
        *file_type = i_file_type(info->st_mode);
    }

    if (file_size != NULL)
    {
        LARGE_INTEGER size;
        BOOL ret;
        ret = GetFileSizeEx(file, &size);
        cassert(ret == TRUE);
        *file_size = (uint64_t)size.QuadPart;
    }

    if (error != NULL)
        *error = ekIO_ERROR_ANY;

    return TRUE;

    }
    else
    {
        if (error != NULL)
            *error = i_file_error();

        return FALSE;
    }
}*/

/*---------------------------------------------------------------------------*/

bool_t bfile_lstat(const char_t *pathname, file_type_t *type, uint64_t *size, Date *updated, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 1];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        WIN32_FILE_ATTRIBUTE_DATA attribs;
        register BOOL ok = 0;
        register uint32_t i = 0;
        while ((ok = GetFileAttributesEx(pathnamew, GetFileExInfoStandard, &attribs)) == 0)
        {
            i++;
            if (i == i_NUM_RETRYS)
                break;
        }

        if (ok != 0)
        {
            if (type != NULL)
                *type = i_file_type(attribs.dwFileAttributes);

            if (size != NULL)
            {
                LARGE_INTEGER lsize;
                lsize.LowPart = attribs.nFileSizeLow;
                lsize.HighPart = attribs.nFileSizeHigh;
                *size = (uint64_t)lsize.QuadPart;
            }

            if (updated != NULL)
                i_file_date(&attribs.ftLastWriteTime, updated);

            ptr_assign(error, ekFOK);
            return TRUE;
        }
        else
        {
            ptr_assign(type, ekOTHERFILE);
            ptr_assign(size, 0);
            i_file_error(error);
            return FALSE;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bfile_fstat(const File *file, file_type_t *type, uint64_t *size, Date *updated, ferror_t *error)
{
    cassert_no_null(file);
    if (type != NULL)
    {
        DWORD ltype = GetFileType((HANDLE)file);

        switch (ltype)
        {
        case FILE_TYPE_DISK:
            *type = ekARCHIVE;
            break;
        case FILE_TYPE_CHAR:
            *type = ekOTHERFILE;
            break;
        case FILE_TYPE_PIPE:
            *type = ekOTHERFILE;
            break;
        case FILE_TYPE_UNKNOWN:
            *type = ekOTHERFILE;
            if (GetLastError() != 0)
            {
                break;
            }
            else
            {
                i_file_error(error);
                return FALSE;
            }

        default:
            cassert_msg(FALSE, "file_fstat: unknown type");
            *type = ekOTHERFILE;
        }
    }

    if (size != NULL)
    {
        LARGE_INTEGER lsize;
        BOOL ok = GetFileSizeEx((HANDLE)file, &lsize);
        if (ok != 0)
        {
            *size = (uint64_t)lsize.QuadPart;
        }
        else
        {
            i_file_error(error);
            return FALSE;
        }
    }

    if (updated != NULL)
    {
        BOOL ok;
        FILETIME ft;
        ok = GetFileTime((HANDLE)file, NULL, NULL, &ft);
        cassert_unref(ok == TRUE, ok);
        i_file_date(&ft, updated);
    }

    ptr_assign(error, ekFOK);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t bfile_read(File *file, byte_t *data, const uint32_t size, uint32_t *rsize, ferror_t *error)
{
    DWORD lrsize = 0;
    BOOL ok;
    cassert_no_null(file);
    cassert_no_null(data);
    ok = ReadFile((HANDLE)file, (LPVOID)data, (DWORD)size, &lrsize, NULL);
    if (ok != 0)
    {
        if (lrsize > 0)
        {
            ptr_assign(rsize, (uint32_t)lrsize);
            ptr_assign(error, ekFOK);
            return TRUE;
        }
        else
        {
            cassert(lrsize == 0);
            ptr_assign(rsize, 0);
            ptr_assign(error, ekFOK);
            return FALSE;
        }
    }
    else
    {
        i_file_error(error);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bfile_write(File *file, const byte_t *data, const uint32_t size, uint32_t *wsize, ferror_t *error)
{
    DWORD lwsize = 0;
    BOOL ok;
    cassert_no_null(file);
    cassert_no_null(data);
    ok = WriteFile((HANDLE)file, (LPVOID)data, (DWORD)size, &lwsize, NULL);
    if (ok != 0)
    {
        ptr_assign(wsize, (uint32_t)lwsize);
        ptr_assign(error, ekFOK);
        return TRUE;
    }
    else
    {
        i_file_error(error);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bfile_seek(File *file, const int64_t offset, const file_seek_t whence, ferror_t *error)
{
    LARGE_INTEGER li;
    DWORD method = 0;
    DWORD ret;

    cassert_no_null(file);

    li.QuadPart = (LONGLONG)offset;
    switch (whence)
    {
    case ekSEEKSET:
        method = FILE_BEGIN;
        break;
    case ekSEEKCUR:
        method = FILE_CURRENT;
        break;
    case ekSEEKEND:
        method = FILE_END;
        break;
        cassert_default();
    }

    ret = SetFilePointer((HANDLE)file, li.LowPart, &li.HighPart, method);

    if (ret != INVALID_SET_FILE_POINTER)
    {
        ptr_assign(error, ekFOK);
        return TRUE;
    }
    else
    {
        if (GetLastError() == ERROR_NEGATIVE_SEEK)
        {
            ptr_assign(error, ekFSEEKNEG);
        }
        else
        {
            ptr_assign(error, ekFUNDEF);
        }

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

uint64_t bfile_pos(const File *file)
{
    DWORD low = 0;
    LONG high = 0;
    cassert_no_null(file);
    low = SetFilePointer((HANDLE)file, 0, &high, FILE_CURRENT);
    return ((uint64_t)high << 32) | low;
}

/*---------------------------------------------------------------------------*/

bool_t bfile_delete(const char_t *pathname, ferror_t *error)
{
    WCHAR pathnamew[MAX_PATH + 1];
    uint32_t num_bytes = unicode_convers(pathname, (char_t *)pathnamew, ekUTF8, ekUTF16, sizeof(pathnamew));
    if (num_bytes < sizeof(pathnamew))
    {
        if (DeleteFile(pathnamew) != 0)
        {
            ptr_assign(error, ekFOK);
            return TRUE;
        }
        else
        {
            i_file_error(error);
            return FALSE;
        }
    }
    else
    {
        ptr_assign(error, ekFBIGNAME);
        return FALSE;
    }
}
