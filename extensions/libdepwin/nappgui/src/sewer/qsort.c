/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: qsort.c
 *
 */

/* Quick sort with data (from glib) */

/* https://github.com/frida/glib/blob/master/glib/gqsort.c */

#include "qsort.inl"
#include "cassert.h"
#include "nowarn.hxx"

typedef void (*i_SWAP)(char *a, char *b, uint32_t size);

/*---------------------------------------------------------------------------*/

static __INLINE void i_SWAP_ALIGN(char *a, char *b, uint32_t size)
{
    register uint32_t n1 = size / (uint32_t)sizeofptr;
    register uint32_t i;
    register void **_a = (void **)a;
    register void **_b = (void **)b;
    register void *swap;
    for (i = 0; i < n1; ++i, ++_a, ++_b)
    {
        swap = *_a;
        *_a = *_b;
        *_b = swap;
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_SWAP_PTR(char *a, char *b, uint32_t size)
{
    register void *swap = *(void **)a;
    *(void **)a = *(void **)b;
    *(void **)b = swap;
    unref(size);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_SWAP_GENERAL(char *a, char *b, uint32_t size)
{
    register uint32_t n1 = size / (uint32_t)sizeofptr;
    register uint32_t i;
    register void **_a = (void **)a;
    register void **_b = (void **)b;
    register void *swap;
    register char swapc;
    for (i = 0; i < n1; ++i, ++_a, ++_b)
    {
        swap = *_a;
        *_a = *_b;
        *_b = swap;
    }

    a += n1 * sizeofptr;
    b += n1 * sizeofptr;
    n1 = size % (uint32_t)sizeofptr;
    for (i = 0; i < n1; ++i, ++a, ++b)
    {
        swapc = *a;
        *a = *b;
        *b = swapc;
    }
}

/*---------------------------------------------------------------------------*/

/*
//#define SWAP(a, b, size)\
//    do\
//    {\
//        register uint32_t __size = (size);\
//        register char *__a = (a), *__b = (b);\
//        do\
//        {\
//            char __tmp = *__a;\
//            *__a++ = *__b;\
//            *__b++ = __tmp;\
//        } while (--__size > 0);\
//    } while (i_FALSE)
*/

/* Discontinue quicksort algorithm when partition gets below this size.
   This particular magic number was chosen to work best on a Sun 4/260. */
#define MAX_THRESH 4

/* Stack node declarations used to store unfulfilled partition obligations. */
typedef struct
{
    char *lo;
    char *hi;
} stack_node;

/* The next 4 #defines implement a very fast in-line stack abstraction. */
/* The stack needs log (total_elements) entries (we could even subtract
   log(MAX_THRESH)).  Since total_elements has type size_t, we get as
   upper bound for log (total_elements):
   bits per byte (CHAR_BIT) * sizeof(size_t).  */
#define CHAR_BIT 8
#define STACK_SIZE (CHAR_BIT * sizeof(uint32_t))
#define PUSH(low, high) ((void)((top->lo = (low)), (top->hi = (high)), ++top))
#define POP(low, high) ((void)(--top, (low = top->lo), (high = top->hi)))
#define STACK_NOT_EMPTY (stack < top)

/* Order size using quicksort.  This implementation incorporates
   four optimizations discussed in Sedgewick:

   1. Non-recursive, using an explicit stack of pointer that store the
      next array partition to sort.  To save time, this maximum amount
      of space required to store an array of SIZE_MAX is allocated on the
      stack.  Assuming a 32-bit (64 bit) integer for size_t, this needs
      only 32 * sizeof(stack_node) == 256 bytes (for 64 bit: 1024 bytes).
      Pretty cheap, actually.

   2. Chose the pivot element using a median-of-three decision tree.
      This reduces the probability of selecting a bad pivot value and
      eliminates certain extraneous comparisons.

   3. Only quicksorts TOTAL_ELEMS / MAX_THRESH partitions, leaving
      insertion sort to order the MAX_THRESH items within each partition.
      This is a big win, since insertion sort is faster for small, mostly
      sorted array segments.

   4. The larger of the two sub-partitions is always pushed onto the
      stack first, with the algorithm then concentrating on the
      smaller partition.  This *guarantees* no more than log (total_elems)
      stack size is needed (actually O(1) in this case)!  */

/**
 * g_qsort_with_data:
 * @pbase: start of array to sort
 * @total_elems: elements in the array
 * @size: size of each element
 * @compare_func: function to compare elements
 * @user_data: data to pass to @compare_func
 *
 * This is just like the standard C qsort() function, but
 * the comparison routine accepts a user data argument.
 *
 **/
void _qsort_ex(const void *data, const uint32_t total_elems, const uint32_t sizeof_elem, FPtr_compare_ex func_compare, const void *user_data)
{
    register i_SWAP SWAP_FUNC;
    register char *base_ptr = (char *)data;
    uint32_t max_thresh = MAX_THRESH * sizeof_elem;

    cassert_no_null(base_ptr);
    cassert(sizeof_elem > 0);
    cassert_no_nullf(func_compare);

    /* Avoid lossage with unsigned arithmetic below.  */
    if (total_elems == 0)
        return;

    if (sizeof_elem == sizeofptr)
        SWAP_FUNC = i_SWAP_PTR;
    else if (sizeof_elem % (uint32_t)sizeofptr == 0)
        SWAP_FUNC = i_SWAP_ALIGN;
    else
        SWAP_FUNC = i_SWAP_GENERAL;

    if (total_elems > MAX_THRESH)
    {
        char *lo = base_ptr;
        char *hi = &lo[sizeof_elem * (total_elems - 1)];
        stack_node stack[STACK_SIZE];
        stack_node *top = stack;

        PUSH(NULL, NULL);

        while (STACK_NOT_EMPTY)
        {
            char *left_ptr;
            char *right_ptr;

            /* Select median value from among LO, MID, and HI. Rearrange
            LO and HI so the three values are sorted. This lowers the
            probability of picking a pathological pivot value and
            skips a comparison for both the LEFT_PTR and RIGHT_PTR in
            the while loops. */

            char *mid = lo + sizeof_elem * ((uint32_t)(hi - lo) / sizeof_elem >> 1);

            if (func_compare((void *)mid, (void *)lo, user_data) < 0)
                SWAP_FUNC(mid, lo, sizeof_elem);

            if ((func_compare)((void *)hi, (void *)mid, user_data) < 0)
                SWAP_FUNC(mid, hi, sizeof_elem);
            else
                goto jump_over;

            if (func_compare((void *)mid, (void *)lo, user_data) < 0)
                SWAP_FUNC(mid, lo, sizeof_elem);

        jump_over:;

            left_ptr = lo + sizeof_elem;
            right_ptr = hi - sizeof_elem;

            /* Here's the famous ``collapse the walls'' section of quicksort.
            Gotta like those tight inner loops!  They are the main reason
            that this algorithm runs much faster than others. */
            do
            {
                while (func_compare((void *)left_ptr, (void *)mid, user_data) < 0)
                    left_ptr += sizeof_elem;

                while (func_compare((void *)mid, (void *)right_ptr, user_data) < 0)
                    right_ptr -= sizeof_elem;

                if (left_ptr < right_ptr)
                {
                    SWAP_FUNC(left_ptr, right_ptr, sizeof_elem);

                    if (mid == left_ptr)
                        mid = right_ptr;
                    else if (mid == right_ptr)
                        mid = left_ptr;

                    left_ptr += sizeof_elem;
                    right_ptr -= sizeof_elem;
                }
                else if (left_ptr == right_ptr)
                {
                    left_ptr += sizeof_elem;
                    right_ptr -= sizeof_elem;
                    break;
                }
            } while (left_ptr <= right_ptr);

            /* Set up pointers for next iteration.  First determine whether
            left and right partitions are below the threshold size.  If so,
            ignore one or both.  Otherwise, push the larger partition's
            bounds on the stack and continue sorting the smaller one. */

            if ((uint32_t)(right_ptr - lo) <= max_thresh)
            {
                /* Ignore both small partitions. */
                if ((uint32_t)(hi - left_ptr) <= max_thresh)
                    POP(lo, hi);
                /* Ignore small left partition. */
                else
                    lo = left_ptr;
            }
            /* Ignore small right partition. */
            else if ((uint32_t)(hi - left_ptr) <= max_thresh)
                hi = right_ptr;
            /* Push larger left partition indices. */
            else if ((right_ptr - lo) > (hi - left_ptr))
            {
                PUSH(lo, right_ptr);
                lo = left_ptr;
            }
            /* Push larger right partition indices. */
            else
            {
                PUSH(left_ptr, hi);
                hi = right_ptr;
            }
        }
    }

    /* Once the BASE_PTR array is partially sorted by quicksort the rest
    is completely sorted using insertion sort, since this is efficient
    for partitions below MAX_THRESH size. BASE_PTR points to the beginning
    of the array to sort, and END_PTR points at the very last element in
    the array (*not* one beyond it!). */

#define min(x, y) ((x) < (y) ? (x) : (y))

    {
        char *const end_ptr = &base_ptr[sizeof_elem * (total_elems - 1)];
        char *tmp_ptr = base_ptr;
        char *thresh = min(end_ptr, base_ptr + max_thresh);
        register char *run_ptr;

        /* Find smallest element in first threshold and place it at the
        array's beginning.  This is the smallest array element,
        and the operation speeds up insertion sort's inner loop. */

        for (run_ptr = tmp_ptr + sizeof_elem; run_ptr <= thresh; run_ptr += sizeof_elem)
            if (func_compare((void *)run_ptr, (void *)tmp_ptr, user_data) < 0)
                tmp_ptr = run_ptr;

        if (tmp_ptr != base_ptr)
            SWAP_FUNC(tmp_ptr, base_ptr, sizeof_elem);

        /* Insertion sort, running from left-hand-side up to right-hand-side.  */
        run_ptr = base_ptr + sizeof_elem;

        while ((run_ptr += sizeof_elem) <= end_ptr)
        {
            tmp_ptr = run_ptr - sizeof_elem;

            while (func_compare((void *)run_ptr, (void *)tmp_ptr, user_data) < 0)
                tmp_ptr -= sizeof_elem;

            tmp_ptr += sizeof_elem;

            if (tmp_ptr != run_ptr)
            {
                char *trav;

                trav = run_ptr + sizeof_elem;

                while (--trav >= run_ptr)
                {
                    char c = *trav;
                    char *hi, *lo;

                    for (hi = lo = trav; (lo -= sizeof_elem) >= tmp_ptr; hi = lo)
                        *hi = *lo;

                    *hi = c;
                }
            }
        }
    }
}
