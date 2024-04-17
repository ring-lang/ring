/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ptr.c
 *
 */

/* Safety pointer manipulation */

#include "cassert.h"
#include "ptr.h"

/*---------------------------------------------------------------------------*/

void *ptr_dget_imp(void **dptr)
{
    void *pointer;
    cassert_no_null(dptr);
    pointer = *dptr;
    *dptr = NULL;
    return pointer;
}

/*---------------------------------------------------------------------------*/

void *ptr_dget_no_null_imp(void **dptr)
{
    void *pointer;
    cassert_no_null(dptr);
    cassert_no_null(*dptr);
    pointer = *dptr;
    *dptr = NULL;
    return pointer;
}

/*---------------------------------------------------------------------------*/

void ptr_destopt_imp(void **dptr, FPtr_destroy func_destroy)
{
    cassert_no_null(dptr);
    cassert_no_nullf(func_destroy);
    if (*dptr != NULL)
        func_destroy(dptr);
}

/*---------------------------------------------------------------------------*/

void *ptr_copyopt_imp(void *ptr, FPtr_copy func_copy)
{
    cassert_no_nullf(func_copy);
    if (ptr != NULL)
        return func_copy(ptr);
    else
        return NULL;
}
