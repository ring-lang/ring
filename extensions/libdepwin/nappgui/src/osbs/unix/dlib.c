/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dlib.c
 *
 */

/* Dynamic library loading */

#include "dlib.h"
#include "osbs.inl"
#include <sewer/blib.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

#if defined(__LINUX__)
static const char_t *i_LIB_PREFIX = "lib";
static const char_t *i_LIB_SUFIX = ".so";
#elif defined(__MACOS__)
static const char_t *i_LIB_PREFIX = "lib";
static const char_t *i_LIB_SUFIX = ".so";
#else
#error Unknown platform
#endif

#include <dlfcn.h>

/*---------------------------------------------------------------------------*/

DLib *dlib_open(const char_t *path, const char_t *libname)
{
    char_t name[512];
    void *lib = NULL;

    cassert_no_null(libname);

    if (path != NULL && path[0] != '\0')
    {
        uint32_t n = blib_strlen(path);
        blib_strcpy(name, sizeof(name), path);
        if (path[n - 1] != '/')
            blib_strcat(name, sizeof(name), "/");
        blib_strcat(name, sizeof(name), i_LIB_PREFIX);
        blib_strcat(name, sizeof(name), libname);
        blib_strcat(name, sizeof(name), i_LIB_SUFIX);
    }
    else
    {
        blib_strcpy(name, sizeof(name), i_LIB_PREFIX);
        blib_strcat(name, sizeof(name), libname);
        blib_strcat(name, sizeof(name), i_LIB_SUFIX);
    }

    lib = dlopen(name, RTLD_LAZY | RTLD_LOCAL);
    if (lib != NULL)
    {
        _osbs_dlib_alloc();
        return (DLib *)lib;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

void dlib_close(DLib **dlib)
{
    int ok = 0;
    cassert_no_null(dlib);
    cassert_no_null(*dlib);
    ok = dlclose((void *)*dlib);
    *dlib = NULL;
    _osbs_dlib_dealloc();
    cassert_unref(ok == 0, ok);
}

/*---------------------------------------------------------------------------*/

FPtr_libproc dlib_proc_imp(DLib *dlib, const char_t *procname)
{
    void *func = NULL;
    FPtr_libproc *proc = NULL;
    cassert_no_null(dlib);
    cassert_no_null(procname);
    func = dlsym((void *)dlib, procname);
    proc = (FPtr_libproc *)(&func);
    return *proc;
}

/*---------------------------------------------------------------------------*/

void *dlib_var_imp(DLib *dlib, const char_t *varname)
{
    cassert_no_null(dlib);
    cassert_no_null(varname);
    return (void *)dlsym((void *)dlib, varname);
}
