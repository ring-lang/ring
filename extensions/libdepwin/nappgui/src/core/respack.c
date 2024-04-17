/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: respack.c
 *
 */

/* Resource Packages */

#include "respack.h"
#include "respackh.h"
#include "arrpt.h"
#include "arrst.h"
#include "buffer.h"
#include "heap.h"
#include "hfile.h"
#include "stream.h"
#include "strings.h"
#include <osbs/bfile.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

typedef struct i_resource_t i_Resource;

enum i_type_t
{
    i_ekTYPE_EMBEDDED = 0,
    i_ekTYPE_PACKED = 1
};

struct i_resource_t
{
    uint32_t type;
    const byte_t *data;
    uint32_t size;
    void *object;
    FPtr_destroy func_destroy;
};

struct _respack
{
    enum i_type_t type;
    String *name;
    Buffer *buffer;
    ArrSt(i_Resource) *resources;
};

DeclSt(i_Resource);

/*---------------------------------------------------------------------------*/

static void i_init_resource(
    i_Resource *resource,
    const uint32_t type,
    const byte_t *data,
    const uint32_t size,
    void **object)
{
    cassert_no_null(resource);
    resource->type = type;
    resource->data = data;
    resource->size = size;
    resource->object = ptr_dget(object, void);
    resource->func_destroy = NULL;
}

/*---------------------------------------------------------------------------*/

static void i_remove_resource(i_Resource *resource)
{
    cassert_no_null(resource);
    if (resource->object != NULL)
    {
        cassert_no_nullf(resource->func_destroy);
        resource->func_destroy(&resource->object);
    }
}

/*---------------------------------------------------------------------------*/

static ResPack *i_create_respack(const enum i_type_t type, String **name, Buffer **buffer, ArrSt(i_Resource) **resources)
{
    ResPack *pack = heap_new(ResPack);
    pack->type = type;
    pack->name = ptr_dget_no_null(name, String);
    pack->buffer = ptr_dget(buffer, Buffer);
    pack->resources = ptr_dget_no_null(resources, ArrSt(i_Resource));
    return pack;
}

/*---------------------------------------------------------------------------*/

void respack_destroy(ResPack **pack)
{
    cassert_no_null(pack);
    cassert_no_null(*pack);
    str_destroy(&(*pack)->name);
    arrst_destroy(&(*pack)->resources, i_remove_resource, i_Resource);
    if ((*pack)->type == i_ekTYPE_PACKED)
        buffer_destroy(&(*pack)->buffer);
    else
        cassert((*pack)->buffer == NULL);
    heap_delete(pack, ResPack);
}

/*---------------------------------------------------------------------------*/

ResPack *respack_embedded(const char_t *name)
{
    String *lname = str_c(name);
    Buffer *buffer = NULL;
    ArrSt(i_Resource) *resources = arrst_create(i_Resource);
    return i_create_respack(i_ekTYPE_EMBEDDED, &lname, &buffer, &resources);
}

/*---------------------------------------------------------------------------*/

static void i_load_object(Stream *stream, const byte_t **data, uint32_t *size, const uint32_t type)
{
    /* String */
    if (type == 0)
    {
        uint32_t strsize = stm_read_u32(stream);
        *data = stm_buffer(stream);
        *size = 0;
        stm_skip(stream, strsize + 1);
    }
    /* Other file */
    else
    {
        *size = stm_read_u32(stream);
        *data = stm_buffer(stream);
        stm_skip(stream, *size);
    }
}

/*---------------------------------------------------------------------------*/

static void i_load_resource(Stream *stream, const uint32_t locale_code, i_Resource *resource)
{
    uint32_t type;
    const byte_t *data = NULL;
    uint32_t size;
    void *object = NULL;
    register uint32_t i, num_localized;
    type = stm_read_u32(stream);
    i_load_object(stream, &data, &size, type);
    num_localized = stm_read_u32(stream);
    for (i = 0; i < num_localized; ++i)
    {
        register uint32_t lcode = stm_read_u32(stream);
        if (lcode == locale_code)
        {
            i_load_object(stream, &data, &size, type);
        }
        else
        {
            const byte_t *jump_data = NULL;
            uint32_t jump_size;
            i_load_object(stream, &jump_data, &jump_size, type);
        }
    }

    i_init_resource(resource, type, data, size, &object);
}

/*---------------------------------------------------------------------------*/

static Buffer *i_load_pack(ArrSt(i_Resource) *resources, const char_t *name, const char_t *locale)
{
    String *resfile = NULL;
    Buffer *buffer = NULL;

    {
        String *path;
        char_t pathname[512];
        bfile_dir_exec(pathname, 512);
        str_split_pathname(pathname, &path, NULL);
#if defined(__WINDOWS__)
        resfile = str_printf("%s%cres%c%s.res", tc(path), DIR_SEPARATOR, DIR_SEPARATOR, name);
#elif defined(__MACOS__)
        resfile = str_printf("%s%c..%cresources%c%s.res", tc(path), DIR_SEPARATOR, DIR_SEPARATOR, DIR_SEPARATOR, name);
#elif defined(__IOS__)
        cassert(FALSE);
        resfile = str_printf("%s%c..%cresources%c%s.res", tc(path), DIR_SEPARATOR, DIR_SEPARATOR, DIR_SEPARATOR, name);
#elif defined(__LINUX__)
        resfile = str_printf("%s%cres%c%s.res", tc(path), DIR_SEPARATOR, DIR_SEPARATOR, name);
#endif
        str_destroy(&path);
    }

    buffer = hfile_buffer(tc(resfile), NULL);
    if (buffer != NULL)
    {
        uint32_t locale_code = UINT32_MAX;
        Stream *stream = stm_from_block(buffer_data(buffer), buffer_size(buffer));
        register uint32_t num_resources;
        register uint32_t i, num_locales = stm_read_u32(stream);
        for (i = 0; i < num_locales; ++i)
        {
            uint32_t locale_size = stm_read_u32(stream);
            if (locale_code == UINT32_MAX)
            {
                const char_t *locale_name = (const char_t *)stm_buffer(stream);
                if (str_equ_c(locale, locale_name) == TRUE)
                    locale_code = i;
            }

            stm_skip(stream, locale_size);
        }

        num_resources = stm_read_u32(stream);
        for (i = 0; i < num_resources; ++i)
        {
            i_Resource *resource = arrst_new(resources, i_Resource);
            i_load_resource(stream, locale_code, resource);
        }

        stm_close(&stream);
    }
    else
    {
        cassert_fatal_msg(FALSE, "Resource pack can't be loaded.");
    }

    str_destroy(&resfile);
    return buffer;
}

/*---------------------------------------------------------------------------*/

ResPack *respack_packed(const char_t *name, const char_t *locale)
{
    String *lname = str_c(name);
    ArrSt(i_Resource) *resources = arrst_create(i_Resource);
    Buffer *buffer = i_load_pack(resources, name, locale);
    return i_create_respack(i_ekTYPE_PACKED, &lname, &buffer, &resources);
}

/*---------------------------------------------------------------------------*/

void respack_add_msg(ResPack *pack, const char_t *msg)
{
    i_Resource *resource;
    void *object = NULL;
    cassert_no_null(pack);
    cassert(pack->type == i_ekTYPE_EMBEDDED);
    resource = arrst_new(pack->resources, i_Resource);
    i_init_resource(resource, 0, (const byte_t *)msg, UINT32_MAX, &object);
}

/*---------------------------------------------------------------------------*/

void respack_add_cdata(ResPack *pack, const uint32_t type, const byte_t *data, const uint32_t data_size)
{
    i_Resource *resource;
    void *object = NULL;
    cassert_no_null(pack);
    cassert(pack->type == i_ekTYPE_EMBEDDED);
    resource = arrst_new(pack->resources, i_Resource);
    i_init_resource(resource, type, data, data_size, &object);
}

/*---------------------------------------------------------------------------*/

static __INLINE const char_t *i_magic(const ResId id)
{
    const char_t *magic = str_str((const char_t *)id, "::");
    if (magic == NULL)
        return NULL;
    if (str_equ_cn((const char_t *)id, "N23R3C75", (uint32_t)(magic - (const char_t *)id)) == FALSE)
        return NULL;
    if (str_str(magic + 2, "::") == NULL)
        return NULL;
    return magic + 2;
}

/*---------------------------------------------------------------------------*/

static __INLINE uint32_t i_index(ResId id, const String *name)
{
    const char_t *idr = i_magic(id);
    const char_t *packid = NULL;
    cassert_no_null(idr);
    packid = str_str(idr, "::");
    cassert_no_null(packid);
    cassert_unref(str_equ_cn(tc(name), idr, (uint32_t)(packid - idr)) == TRUE, name);
    return str_to_u32(packid + 2, 10, NULL);
}

/*---------------------------------------------------------------------------*/

const char_t *respack_text(const ResPack *pack, const ResId id)
{
    i_Resource *resource = NULL;
    cassert_no_null(pack);
    resource = arrst_get(pack->resources, i_index(id, pack->name), i_Resource);
    cassert_no_null(resource);
    cassert(resource->type == 0);
    return (const char_t *)resource->data;
}

/*---------------------------------------------------------------------------*/

const byte_t *respack_file(const ResPack *pack, const ResId id, uint32_t *size)
{
    i_Resource *resource = NULL;
    cassert_no_null(pack);
    resource = arrst_get(pack->resources, i_index(id, pack->name), i_Resource);
    cassert_no_null(resource);
    cassert(resource->type == 2);
    ptr_assign(size, resource->size);
    return resource->data;
}

/*---------------------------------------------------------------------------*/

void *respack_object_imp(const ResPack *pack, const ResId id, FPtr_create_from_data func_create, FPtr_destroy func_destroy)
{
    i_Resource *resource = NULL;
    cassert_no_null(pack);
    resource = arrst_get(pack->resources, i_index(id, pack->name), i_Resource);
    cassert_no_null(resource);
    if (resource->object == NULL)
    {
        cassert_no_nullf(func_create);
        cassert_no_nullf(func_destroy);
        cassert(resource->func_destroy == NULL);
        resource->object = func_create(resource->data, resource->size);
        resource->func_destroy = func_destroy;
    }

    return resource->object;
}

/*---------------------------------------------------------------------------*/

static __INLINE i_Resource *i_resource(const ArrPt(ResPack) *packs, const ResId id, bool_t *is_resid)
{
    const char_t *idr = i_magic(id);
    const char_t *packid = NULL;
    cassert_no_null(is_resid);
    *is_resid = (bool_t)(idr != NULL);

    if (idr == NULL)
        return NULL;

    packid = str_str(idr, "::");
    if (packid != NULL)
    {
        arrpt_foreach_const(pack, packs, ResPack)
            if (str_cmp_cn(tc(pack->name), idr, (uint32_t)(packid - idr)) == 0)
            {
                uint32_t idx;
                idx = str_to_u32(packid + 2, 10, NULL);
                return arrst_get(pack->resources, idx, i_Resource);
            }
        arrpt_end()
    }
    return NULL;
}

/*---------------------------------------------------------------------------*/

const char_t *respack_atext(const ArrPt(ResPack) *packs, const ResId id, bool_t *is_resid)
{
    const i_Resource *resource = i_resource(packs, id, is_resid);
    if (resource != NULL)
    {
        cassert(resource->type == 0);
        return (const char_t *)resource->data;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

const byte_t *respack_afile(const ArrPt(ResPack) *packs, const ResId id, uint32_t *size, bool_t *is_resid)
{
    i_Resource *resource = i_resource(packs, id, is_resid);
    if (resource != NULL)
    {
        cassert(resource->type == 2);
        ptr_assign(size, resource->size);
        return resource->data;
    }

    ptr_assign(size, 0);
    return NULL;
}

/*---------------------------------------------------------------------------*/

void *respack_aobj_imp(const ArrPt(ResPack) *packs, const ResId id, FPtr_create_from_data func_create, FPtr_destroy func_destroy, bool_t *is_resid)
{
    i_Resource *resource = i_resource(packs, id, is_resid);
    if (resource != NULL)
    {
        if (resource->object == NULL)
        {
            cassert_no_nullf(func_create);
            cassert_no_nullf(func_destroy);
            cassert(resource->func_destroy == NULL);
            resource->object = func_create(resource->data, resource->size);
            resource->func_destroy = func_destroy;
        }

        return resource->object;
    }

    return NULL;
}
