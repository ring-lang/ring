/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: heap.c
 *
 */

/* Fast memory allocator and auditor */

#include "heap.h"
#include "heap.inl"
#include "strings.h"
#include <osbs/osbs.h>
#include <osbs/bmutex.h>
#include <osbs/bthread.h>
#include <osbs/log.h>
#include <sewer/blib.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

typedef struct i_page_t i_Page;
typedef struct i_memory_t i_Memory;

#if defined(__MEMORY_AUDITOR__)

#define OBJECT_NAME_SIZE 64
typedef struct i_object_t i_Object;
struct i_object_t
{
    char_t name[OBJECT_NAME_SIZE];
    uint32_t size;
    uint32_t num_allocs;
    uint32_t num_deallocs;
    uint64_t bytes_alloc;
    uint64_t bytes_dealloc;
    bool_t equal_sized;
};

typedef struct i_access_t i_Access;
struct i_access_t
{
    void *page;
    void *ptr;
    uint32_t object;
    uint32_t time;
    uint32_t op;
};

#endif

struct i_page_t
{
    uint32_t num_allocs;
    uint32_t used_memory;
    uint32_t offset;
    uint32_t mark;
    i_Page *next;
    i_Page *prev;
};

struct i_memory_t
{
    int main_thread_id;
    Mutex *mutex;
    uint32_t mtcount;
    uint32_t page_size;
    i_Page *current_page;
    uint64_t num_allocs;
    uint64_t total_bytes_allocated;
    uint64_t num_deallocs;
    uint64_t total_bytes_deallocated;
    uint64_t num_reallocs;
    uint64_t num_effective_reallocs;
    uint64_t total_bytes_moved_in_reallocs;
    uint64_t bytes_allocated;
    uint64_t max_bytes_allocated;
    uint32_t std_pages_alloc;
    uint32_t great_pages_alloc;
    uint32_t std_pages_dealloc;
    uint32_t great_pages_dealloc;

#if defined(__MEMORY_AUDITOR__)
    i_Object *objects;
    uint32_t objects_alloc;
    uint32_t num_objects;
#endif
};

/*---------------------------------------------------------------------------*/

static i_Memory i_MEMORY;

#if defined(__x86__)
#define DEFAULT_PAGE_SIZE 65536
#elif defined(__x64__)
#define DEFAULT_PAGE_SIZE 65536
#elif defined(__ARM__)
#define DEFAULT_PAGE_SIZE 65536
#elif defined(__ARM64__)
#define DEFAULT_PAGE_SIZE 65536
#endif

#define OBJECTS_ARRAY_GROW_SIZE 128
static uint32_t i_PAGESIZE = DEFAULT_PAGE_SIZE;
static bool_t i_HEAP_VERBOSE = FALSE;
static bool_t i_HEAP_STATS = TRUE;
static bool_t i_HEAP_LEAKS = FALSE;

/*---------------------------------------------------------------------------*/

static void i_init_page(i_Page *page)
{
    cassert_no_null(page);
    page->num_allocs = 0;
    page->used_memory = 0;
    page->offset = sizeof(i_Page);
    page->mark = 0xA16F9B0C;
}

/*---------------------------------------------------------------------------*/

static void i_new_page(const uint32_t page_size, i_Page **current_page, uint32_t *num_pages)
{
    i_Page *new_page = NULL;
    cassert_no_null(current_page);
    cassert_no_null(num_pages);
    new_page = (i_Page *)bmem_malloc(page_size);
    *num_pages += 1;
    i_init_page(new_page);
    new_page->next = NULL;
    new_page->prev = *current_page;

    if ((*current_page) != NULL)
        (*current_page)->next = new_page;

    *current_page = new_page;
}

/*---------------------------------------------------------------------------*/

static void i_init_memory(i_Memory *memory, const uint32_t page_size)
{
    cassert_no_null(memory);
    /* Page size is power of 2 */
    cassert((page_size != 0) && (page_size & (page_size - 1)) == 0);
    bmem_zero(memory, i_Memory);
    memory->main_thread_id = bthread_current_id();
    memory->mutex = bmutex_create();
    memory->mtcount = 0;
    memory->page_size = page_size;
    i_new_page(memory->page_size, &memory->current_page, &memory->std_pages_alloc);

#if defined(__MEMORY_AUDITOR__)
    memory->objects_alloc = OBJECTS_ARRAY_GROW_SIZE;
    memory->objects = (i_Object *)bmem_malloc((uint32_t)(memory->objects_alloc * sizeof(i_Object)));
    memory->num_objects = 0;
#endif
}

/*---------------------------------------------------------------------------*/

static void i_remove_memory(i_Memory *memory)
{
    cassert_no_null(memory);
    cassert(bthread_current_id() == memory->main_thread_id);
    cassert(memory->mtcount == 0);

    bmem_free((byte_t *)memory->current_page);
    memory->current_page = NULL;
    bmutex_close(&memory->mutex);

#if defined(__MEMORY_AUDITOR__)
    bmem_free((byte_t *)memory->objects);
    memory->objects = NULL;
    memory->num_objects = 0;
    memory->objects_alloc = 0;
#endif
}

/*---------------------------------------------------------------------------*/

static byte_t *i_malloc(i_Memory *memory, const uint32_t size, const uint32_t align)
{
    byte_t *mem = NULL;

    cassert_no_null(memory);
    cassert_no_null(memory->current_page);

    /* Block can be stored by paged allocator */
    if (__TRUE_EXPECTED(size + align + sizeof(i_Page) + sizeofptr < memory->page_size))
    {
        register uint32_t mod = memory->current_page->offset % align;
        register uint32_t offset = memory->current_page->offset;

        if (mod > 0)
            offset += align - mod;

        /* Block can't be stored in current page */
        if (offset + size + sizeofptr >= memory->page_size)
        {
            i_new_page(memory->page_size, &memory->current_page, &memory->std_pages_alloc);
            offset = memory->current_page->offset + (memory->current_page->offset % align);
        }

        cassert(offset + size + sizeofptr < memory->page_size);
        memory->current_page->num_allocs += 1;
        memory->current_page->used_memory += size;
        memory->current_page->offset = offset + size + (uint32_t)sizeofptr;
        mem = (byte_t *)memory->current_page + offset;
        *((void **)(mem + size)) = (void *)memory->current_page;
    }
    /* Block needs its own allocation */
    else
    {
        mem = bmem_aligned_malloc(size, align);
        memory->great_pages_alloc += 1;
    }

    cassert_fatal((mem != NULL) && ((intptr_t)mem % (intptr_t)align) == 0);
    return mem;
}

/*---------------------------------------------------------------------------*/

static void i_free(i_Memory *memory, byte_t *mem, const uint32_t size, const uint32_t align)
{
    cassert_no_null(memory);

/* Block filled with waste */
#if defined(__ASSERTS__)
    bmem_set1(mem, size, 0x3F);
#endif

    /* Block was stored by paged allocator */
    if (__TRUE_EXPECTED(size + align + sizeof(i_Page) + sizeofptr < memory->page_size))
    {
        i_Page *page = (i_Page *)*((void **)(mem + size));
        cassert_no_null(page);
        cassert(page->mark == 0xA16F9B0C);
        cassert(page->num_allocs > 0);
        cassert(page->used_memory >= size);
        page->num_allocs -= 1;
        page->used_memory -= size;

        /* The whole page is freeded, we destroy the page */
        if (page->num_allocs == 0)
        {
            cassert(page->used_memory == 0);

            /* The page isn't the current page. Update list pointers and free. */
            if (__TRUE_EXPECTED(page != memory->current_page))
            {
                cassert(page->next != NULL);
                page->next->prev = page->prev;
                if (page->prev != NULL)
                    page->prev->next = page->next;

                bmem_free((byte_t *)page);
                memory->std_pages_dealloc += 1;
            }
            /* Page for free is current page, we can reuse it. */
            else
            {
                cassert(page->next == NULL);
                i_init_page(page);
            }
        }
    }
    /* Block was stored using an own block */
    else
    {
        bmem_free(mem);
        memory->great_pages_dealloc += 1;
    }
}

/*---------------------------------------------------------------------------*/

static byte_t *i_realloc(i_Memory *memory, byte_t *prev_mem, const uint32_t size, const uint32_t prev_size, const uint32_t align)
{
    byte_t *mem = NULL;
    cassert_no_null(memory);
    cassert_no_null(memory->current_page);

    /* Some of new/previous block can be/is stored in paged allocator */
    if (__TRUE_EXPECTED((prev_size + align + sizeof(i_Page) + sizeofptr < memory->page_size) || (size + align + sizeof(i_Page) + sizeofptr < memory->page_size)))
    {
        register uint32_t min_size;
        mem = i_malloc(memory, size, align);
        min_size = prev_size < size ? prev_size : size;
        bmem_copy(mem, prev_mem, min_size);
        i_free(memory, prev_mem, prev_size, align);
    }
    /* Previous block is in own allocation and new block needs its own allocation too. */
    /* We can call to system realloc. */
    else
    {
        mem = bmem_aligned_realloc(prev_mem, prev_size, size, align);
    }

    cassert_fatal((mem != NULL) && ((intptr_t)mem % (intptr_t)align) == 0);
    return mem;
}

/*---------------------------------------------------------------------------*/

void _heap_start(void)
{
    i_init_memory(&i_MEMORY, i_PAGESIZE);
}

/*---------------------------------------------------------------------------*/

void _heap_finish(void)
{
/* Show Objects Leaks*/
#if defined(__MEMORY_AUDITOR__)
    {
        bool_t with_object_leaks = FALSE;
        register uint32_t i;
        for (i = 0; i < i_MEMORY.num_objects; ++i)
        {
            if (i_MEMORY.objects[i].num_allocs != i_MEMORY.objects[i].num_deallocs)
            {
                if (with_object_leaks == FALSE)
                {
                    log_printf("[FAIL] Heap Object Leaks!!!");
                    log_printf("===========================");
                    with_object_leaks = TRUE;
                }

                log_printf("'%s' a/deallocations: %u, %u (%u leaks)", i_MEMORY.objects[i].name, i_MEMORY.objects[i].num_allocs, i_MEMORY.objects[i].num_deallocs, (i_MEMORY.objects[i].num_allocs - i_MEMORY.objects[i].num_deallocs));
            }
            else if (i_MEMORY.objects[i].bytes_alloc != i_MEMORY.objects[i].bytes_dealloc)
            {
                if (with_object_leaks == FALSE)
                {
                    log_printf("[FAIL] Heap Object Leaks!!!");
                    log_printf("===========================");
                    with_object_leaks = TRUE;
                }

                log_printf("'%s' bytes a/deallocated: %" PRIu64 ", %" PRIu64 " (%" PRIu64 " bytes)", i_MEMORY.objects[i].name, i_MEMORY.objects[i].bytes_alloc, i_MEMORY.objects[i].bytes_dealloc, i_MEMORY.objects[i].bytes_alloc - i_MEMORY.objects[i].bytes_dealloc);
            }
        }

        if (with_object_leaks == TRUE)
            log_printf("===========================");
    }
#endif

    if (i_MEMORY.num_allocs != i_MEMORY.num_deallocs || i_MEMORY.total_bytes_allocated != i_MEMORY.total_bytes_deallocated || i_MEMORY.bytes_allocated > 0)
    {
        log_printf("[FAIL] Heap Global Memory Leaks!!!");
        log_printf("==================================");
        log_printf("Total a/dellocations: %" PRIu64 ", %" PRIu64 " (%" PRIu64 " leaks)", i_MEMORY.num_allocs, i_MEMORY.num_deallocs, i_MEMORY.num_allocs - i_MEMORY.num_deallocs);
        log_printf("Total bytes a/dellocated: %" PRIu64 ", %" PRIu64 " (%" PRIu64 " bytes)", i_MEMORY.total_bytes_allocated, i_MEMORY.total_bytes_deallocated, i_MEMORY.total_bytes_allocated - i_MEMORY.total_bytes_deallocated);
        log_printf("Max bytes allocated: %" PRIu64, i_MEMORY.max_bytes_allocated);
        log_printf("==================================");
        i_HEAP_LEAKS = TRUE;
    }
    else
    {
        if (i_HEAP_STATS == TRUE)
        {
            log_printf("[OK] Heap Memory Staticstics");
            log_printf("============================");
            log_printf("Total a/dellocations: %" PRIu64 ", %" PRIu64, i_MEMORY.num_allocs, i_MEMORY.num_deallocs);
            log_printf("Total bytes a/dellocated: %" PRIu64 ", %" PRIu64, i_MEMORY.total_bytes_allocated, i_MEMORY.total_bytes_deallocated);
            log_printf("Max bytes allocated: %" PRIu64, i_MEMORY.max_bytes_allocated);
            log_printf("Effective reallocations: (%" PRIu64 "/%" PRIu64 ")", i_MEMORY.num_effective_reallocs, i_MEMORY.num_reallocs);
            log_printf("Real allocations: %u pages of %u bytes", i_MEMORY.std_pages_alloc, i_MEMORY.page_size);
            if (i_MEMORY.great_pages_alloc > 0)
                log_printf("                  %u pages greater than %u bytes", i_MEMORY.great_pages_alloc, i_MEMORY.page_size);
            log_printf("============================");

#if defined(__MEMORY_AUDITOR__)
            if (i_HEAP_VERBOSE == TRUE)
            {
                register uint32_t i;
                for (i = 0; i < i_MEMORY.num_objects; ++i)
                    log_printf("'%s' a/deallocations: %u, %u (%" PRIu64 ") bytes", i_MEMORY.objects[i].name, i_MEMORY.objects[i].num_allocs, i_MEMORY.objects[i].num_deallocs, i_MEMORY.objects[i].bytes_alloc);
            }
#endif
        }
    }

    if (i_MEMORY.mtcount > 0)
        log_printf("Multi-threaded support has not been closed.");

    if (i_HEAP_STATS == TRUE)
    {
#if defined(__DEBUG__)
        log_printf("Config: Debug");
#elif defined(__ASSERTS__)
        log_printf("Config: ReleaseWithAssert");
#else
        log_printf("Config: Release");
#endif
    }

    i_remove_memory(&i_MEMORY);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_next_pow2(const uint32_t value)
{
    register uint32_t v = value;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

/*---------------------------------------------------------------------------*/

void _heap_page_size(const uint32_t size)
{
    cassert(i_MEMORY.current_page == NULL);
    i_PAGESIZE = i_next_pow2(size);
    if (i_PAGESIZE < 1024)
        i_PAGESIZE = 1024;
}

#if defined(__MEMORY_AUDITOR__)

/*---------------------------------------------------------------------------*/

/*
static void i_dump_objects(void)
{
   register uint32_t i;
   log_printf("Num objects: %d", i_MEMORY.num_objects);
   for (i = 0; i < i_MEMORY.num_objects; ++i)
       log_printf("%s %d %d", i_MEMORY.objects[i].name, i_MEMORY.objects[i].num_allocs, i_MEMORY.objects[i].num_deallocs);
}
 */

/*---------------------------------------------------------------------------*/

static int i_object_key(const i_Object *object, const char_t *name)
{
    return str_cmp_cn(object->name, name, OBJECT_NAME_SIZE);
}

/*---------------------------------------------------------------------------*/

static i_Object *i_get_object(const char_t *name, const bool_t equal_sized, const uint32_t size)
{
    uint32_t index = UINT32_MAX;
    if (blib_bsearch((const byte_t *)i_MEMORY.objects, (const byte_t *)name, i_MEMORY.num_objects, sizeof(i_Object), (FPtr_compare)i_object_key, &index) == TRUE)
    {
        i_Object *object = i_MEMORY.objects + index;
        cassert_msg(object->equal_sized == equal_sized, "heap auditor: Not 'equal_sized' property with same 'name'.");
        cassert_msg(object->equal_sized == FALSE || object->size == size, "heap auditor: alloc 'equal_sized' object type with different size.");
        return object;
    }
    else
    {
        i_Object *new_object = NULL;
        if (i_MEMORY.num_objects == i_MEMORY.objects_alloc)
        {
            i_MEMORY.objects = (i_Object *)bmem_realloc((byte_t *)i_MEMORY.objects, i_MEMORY.objects_alloc * (uint32_t)sizeof(i_Object), (i_MEMORY.objects_alloc + OBJECTS_ARRAY_GROW_SIZE) * (uint32_t)sizeof(i_Object));
            i_MEMORY.objects_alloc += OBJECTS_ARRAY_GROW_SIZE;
        }

        /* Move all elems from index 1 postion right (keep the array sorted) */
        if ((i_MEMORY.num_objects - index) > 0)
        {
            bmem_move((byte_t *)(i_MEMORY.objects + index + 1),
                      (const byte_t *)(i_MEMORY.objects + index),
                      (i_MEMORY.num_objects - index) * (uint32_t)sizeof(i_Object));
        }

        new_object = i_MEMORY.objects + index;
        bmem_zero(new_object, i_Object);
        str_copy_c(new_object->name, OBJECT_NAME_SIZE, name);
        new_object->equal_sized = equal_sized;
        new_object->size = size;
        i_MEMORY.num_objects += 1;
        return new_object;
    }
}

/*---------------------------------------------------------------------------*/

static i_Object *i_get_existing_object(const char_t *name)
{
    uint32_t index = UINT32_MAX;
    if (blib_bsearch((const byte_t *)i_MEMORY.objects, (const byte_t *)name, i_MEMORY.num_objects, sizeof(i_Object), (FPtr_compare)i_object_key, &index) == TRUE)
    {
        return i_MEMORY.objects + index;
    }
    else
    {
        cassert_fatal_msg(FALSE, "heap auditor: non-existent 'name' object.");
        return NULL;
    }
}

#endif

/*---------------------------------------------------------------------------*/

static __INLINE byte_t *i_malloc_imp(const uint32_t size, const uint32_t align, const char_t *name, const bool_t equal_sized)
{
    byte_t *mem = NULL;

    cassert(size > 0);

    if (i_MEMORY.mutex != NULL)
        bmutex_lock(i_MEMORY.mutex);

    i_MEMORY.num_allocs += 1;
    i_MEMORY.total_bytes_allocated += size;
    i_MEMORY.bytes_allocated += size;
    if (i_MEMORY.bytes_allocated > i_MEMORY.max_bytes_allocated)
        i_MEMORY.max_bytes_allocated = i_MEMORY.bytes_allocated;

#if defined(__MEMORY_AUDITOR__)
    {
        i_Object *object = i_get_object(name, equal_sized, size);
        object->num_allocs += 1;
        object->bytes_alloc += size;
    }
#else
    unref(name);
    unref(equal_sized);
#endif

    mem = i_malloc(&i_MEMORY, size, align);

    if (i_MEMORY.mutex != NULL)
        bmutex_unlock(i_MEMORY.mutex);

    return mem;
}

/*---------------------------------------------------------------------------*/

void heap_start_mt(void)
{
    bmutex_lock(i_MEMORY.mutex);
    i_MEMORY.mtcount += 1;
    osbs_memory_mt(i_MEMORY.mutex);
    bmutex_unlock(i_MEMORY.mutex);
}

/*---------------------------------------------------------------------------*/

void heap_end_mt(void)
{
    bmutex_lock(i_MEMORY.mutex);
    cassert(i_MEMORY.mtcount > 0);
    i_MEMORY.mtcount -= 1;
    if (i_MEMORY.mtcount == 0)
        osbs_memory_mt(NULL);
    bmutex_unlock(i_MEMORY.mutex);
}

/*---------------------------------------------------------------------------*/

void heap_verbose(const bool_t verbose)
{
    i_HEAP_VERBOSE = verbose;
}

/*---------------------------------------------------------------------------*/

void heap_stats(const bool_t stats)
{
    i_HEAP_STATS = stats;
}

/*---------------------------------------------------------------------------*/

bool_t heap_leaks(void)
{
    return i_HEAP_LEAKS;
}

/*---------------------------------------------------------------------------*/

byte_t *heap_malloc_imp(const uint32_t size, const char_t *name, const bool_t equal_sized)
{
    return i_malloc_imp(size, sizeofptr, name, equal_sized);
}

/*---------------------------------------------------------------------------*/

byte_t *heap_calloc_imp(const uint32_t size, const char_t *name, const bool_t equal_sized)
{
    byte_t *new_mem = i_malloc_imp(size, sizeofptr, name, equal_sized);
    bmem_set_zero(new_mem, size);
    return new_mem;
}

/*---------------------------------------------------------------------------*/

static __INLINE byte_t *i_realloc_imp(byte_t *mem, const uint32_t size, const uint32_t new_size, const uint32_t align, const char_t *name)
{
    cassert_no_null(mem);
    cassert(size > 0);
    cassert(new_size > 0);

    if (__TRUE_EXPECTED(size != new_size))
    {
        byte_t *new_mem = NULL;
        bool_t locked = FALSE;

        if (i_MEMORY.mtcount > 0)
        {
            bmutex_lock(i_MEMORY.mutex);
            locked = TRUE;
        }

        new_mem = i_realloc(&i_MEMORY, mem, new_size, size, align);
        i_MEMORY.num_reallocs += 1;
        i_MEMORY.total_bytes_deallocated += size;
        i_MEMORY.total_bytes_allocated += new_size;

        if (new_mem != mem)
            i_MEMORY.total_bytes_moved_in_reallocs += size;
        else
            i_MEMORY.num_effective_reallocs += 1;

        if (new_size > size)
        {
            i_MEMORY.bytes_allocated += new_size - size;
            if (i_MEMORY.bytes_allocated > i_MEMORY.max_bytes_allocated)
                i_MEMORY.max_bytes_allocated = i_MEMORY.bytes_allocated;
        }
        else
        {
            i_MEMORY.bytes_allocated -= size - new_size;
        }

#if defined(__MEMORY_AUDITOR__)
        {
            i_Object *object = i_get_object(name, FALSE, UINT32_MAX);
            object->bytes_alloc += new_size;
            object->bytes_dealloc += size;
        }
#else
        unref(name);
#endif

        if (locked == TRUE)
            bmutex_unlock(i_MEMORY.mutex);

        return new_mem;
    }
    else
    {
        cassert((intptr_t)mem % (intptr_t)align == 0);
        return mem;
    }
}

/*---------------------------------------------------------------------------*/

byte_t *heap_realloc(byte_t *mem, const uint32_t size, const uint32_t new_size, const char_t *name)
{
    return i_realloc_imp(mem, size, new_size, sizeofptr, name);
}

/*---------------------------------------------------------------------------*/

byte_t *heap_aligned_malloc_imp(const uint32_t size, const uint32_t align, const char_t *name, const bool_t equal_sized)
{
    return i_malloc_imp(size, align, name, equal_sized);
}

/*---------------------------------------------------------------------------*/

byte_t *heap_aligned_calloc_imp(const uint32_t size, const uint32_t align, const char_t *name, const bool_t equal_sized)
{
    byte_t *new_mem = i_malloc_imp(size, align, name, equal_sized);
    bmem_set_zero(new_mem, size);
    return new_mem;
}

/*---------------------------------------------------------------------------*/

byte_t *heap_aligned_realloc(byte_t *mem, const uint32_t size, const uint32_t new_size, const uint32_t align, const char_t *name)
{
    return i_realloc_imp(mem, size, new_size, align, name);
}

/*---------------------------------------------------------------------------*/

void heap_free(byte_t **mem, const uint32_t size, const char_t *name)
{
    byte_t *mem_ptr = NULL;
    bool_t locked = FALSE;
    cassert_no_null(mem);
    cassert_no_null(*mem);
    cassert(size > 0);

    if (i_MEMORY.mtcount > 0)
    {
        bmutex_lock(i_MEMORY.mutex);
        locked = TRUE;
    }

    mem_ptr = *mem;
    *mem = NULL;
    i_free(&i_MEMORY, mem_ptr, size, sizeofptr);

    i_MEMORY.num_deallocs += 1;
    i_MEMORY.total_bytes_deallocated += size;
    cassert_fatal(i_MEMORY.bytes_allocated >= size);
    i_MEMORY.bytes_allocated -= size;

#if defined(__MEMORY_AUDITOR__)
    {
        i_Object *object = i_get_existing_object(name);
        cassert_msg(object->equal_sized == FALSE || object->size == size, "heap auditor: free 'equal_sized' object type with different size.");
        cassert_msg(object->num_allocs > 0, "heap auditor: free object type without allocs.");
        object->num_deallocs += 1;
        object->bytes_dealloc += size;
    }
#else
    unref(name);
#endif

    if (locked == TRUE)
        bmutex_unlock(i_MEMORY.mutex);
}

/*---------------------------------------------------------------------------*/

void heap_auditor_add(const char_t *name)
{
#if defined(__MEMORY_AUDITOR__)
    {
        i_Object *object = NULL;
        bool_t locked = FALSE;

        if (i_MEMORY.mtcount > 0)
        {
            bmutex_lock(i_MEMORY.mutex);
            locked = TRUE;
        }

        object = i_get_object(name, TRUE, 0);
        object->num_allocs += 1;
        i_MEMORY.num_allocs += 1;

        if (locked == TRUE)
            bmutex_unlock(i_MEMORY.mutex);
    }
#else
    unref(name);
#endif
}

/*---------------------------------------------------------------------------*/

void heap_auditor_delete(const char_t *name)
{
#if defined(__MEMORY_AUDITOR__)
    {
        i_Object *object = NULL;
        bool_t locked = FALSE;

        if (i_MEMORY.mtcount > 0)
        {
            bmutex_lock(i_MEMORY.mutex);
            locked = TRUE;
        }

        object = i_get_existing_object(name);
        cassert_msg(object->num_allocs > 0, "heap auditor: free auditor object type without allocs.");
        object->num_deallocs += 1;
        i_MEMORY.num_deallocs += 1;

        if (locked == TRUE)
            bmutex_unlock(i_MEMORY.mutex);
    }
#else
    unref(name);
#endif
}
