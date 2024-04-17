/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tfilter.c
 *
 */

/* Text filters */

#include "tfilter.inl"
#include "date.h"
#include "strings.h"
#include <sewer/cassert.h>
#include <sewer/unicode.h>

typedef enum _state_t
{
    stSTART,
    stZERO,
    stINTEGER,
    stREAL
} gui_state_t;

/*---------------------------------------------------------------------------*/

void tfilter_number(const char_t *src, char_t *dest, const uint32_t size, const uint32_t num_decimals, const bool_t allow_negatives)
{
    uint32_t csize, i = 0;
    uint32_t codepoint = unicode_to_u32b(src, ekUTF8, &csize);
    uint32_t decimals = 0;
    gui_state_t state = stSTART;
    bool_t valid = FALSE;
    while (codepoint != 0)
    {
        valid = FALSE;
        switch (state)
        {
        case stSTART:
            if (codepoint == '0')
            {
                state = stZERO;
                valid = TRUE;
            }
            else if (codepoint >= '1' && codepoint <= '9')
            {
                state = stINTEGER;
                valid = TRUE;
            }
            else if (codepoint == '.' || codepoint == ',')
            {
                if (num_decimals > 0)
                {
                    state = stREAL;
                    valid = TRUE;
                }
            }
            else if (codepoint == '-')
            {
                if (allow_negatives == TRUE)
                {
                    state = stSTART;
                    valid = TRUE;
                }
            }
            break;

        case stZERO:
            if (num_decimals > 0)
            {
                if (codepoint == '.' || codepoint == ',')
                {
                    state = stREAL;
                    valid = TRUE;
                }
            }
            break;

        case stINTEGER:
            if (codepoint >= '0' && codepoint <= '9')
            {
                state = stINTEGER;
                valid = TRUE;
            }
            else if (codepoint == '.' || codepoint == ',')
            {
                if (num_decimals > 0)
                {
                    state = stREAL;
                    valid = TRUE;
                }
            }
            break;

        case stREAL:
            if (codepoint >= '0' && codepoint <= '9')
            {
                if (decimals < num_decimals)
                {
                    decimals += 1;
                    state = stREAL;
                    valid = TRUE;
                }
            }
            break;

            cassert_default();
        }

        if (valid == TRUE)
        {
            if (i + csize < size - 1)
            {
                dest += unicode_to_char(codepoint, dest, ekUTF8);
                i += csize;
            }
        }

        src = unicode_next(src, ekUTF8);
        codepoint = unicode_to_u32(src, ekUTF8);
    }

    unicode_to_char(0, dest, ekUTF8);
}

/*---------------------------------------------------------------------------*/

static void i_overwrite_mode(const char_t *src, char_t *dest, const uint32_t size, const bool_t deleted, uint32_t *cpos)
{
    cassert_no_null(cpos);

    if (deleted == FALSE)
    {
        uint32_t nc = unicode_nchars(src, ekUTF8);
        if (*cpos >= nc)
        {
            str_copy_c(dest, size, src);
            *cpos = nc;
        }
        else
        {
            uint32_t i = 0, c = *cpos;
            uint32_t cp = 0, nb = 0, sz = size;

            /* Copy the first characters to caret position */
            for (i = 0; i < c; ++i)
            {
                cp = unicode_to_u32b(src, ekUTF8, &nb);

                if (nb < sz)
                {
                    unicode_to_char(cp, dest, ekUTF8);
                    src += nb;
                    dest += nb;
                    sz -= nb;
                }
                else
                {
                    break;
                }
            }

            /* Jump the character after the caret */
            cp = unicode_to_u32b(src, ekUTF8, &nb);
            src += nb;

            /* Copy the rest of the string */
            str_copy_c(dest, sz, src);
        }
    }
    /* We are in 'delete' mode, just copy the original */
    else
    {
        str_copy_c(dest, size, src);
    }
}

/*---------------------------------------------------------------------------*/

void tfilter_date(const char_t *src, char_t *dest, const uint32_t size, const char_t *pattern, const uint32_t cpos, const bool_t deleted, uint32_t *ncpos)
{
    cassert_no_null(ncpos);
    unref(pattern);
    *ncpos = cpos;
    i_overwrite_mode(src, dest, size, deleted, ncpos);
}

/*---------------------------------------------------------------------------*/

Date tfilter_to_date(const char_t *text, const char_t *pattern)
{
    Date date = kDATE_NULL;
    uint32_t n = str_len_c(text);
    if (n == str_len_c(pattern))
    {
        char_t day[3];
        char_t month[3];
        char_t year[5];
        uint32_t id = 0, im = 0, iy = 0, i = 0;
        while (i < n)
        {
            if (pattern[i] == 'd' || pattern[i] == 'D')
            {
                day[id] = text[i];
                id += 1;

                if (id > 2)
                    break;
            }
            else if (pattern[i] == 'm' || pattern[i] == 'M')
            {
                month[im] = text[i];
                im += 1;

                if (im > 2)
                    break;
            }
            else if (pattern[i] == 'y' || pattern[i] == 'Y')
            {
                year[iy] = text[i];
                iy += 1;

                if (iy > 4)
                    break;
            }

            i += 1;
        }

        day[id] = '\0';
        month[im] = '\0';
        year[iy] = '\0';

        date.mday = str_to_u8(day, 10, NULL);
        date.month = str_to_u8(month, 10, NULL);
        date.year = str_to_i16(year, 10, NULL);

        /* Two digits year */
        /* https://www.ibm.com/docs/en/i/7.2?topic=mcdtdi-conversion-2-digit-years-4-digit-years-centuries */
        if (date.year < 100)
        {
            if (date.year >= 40)
                date.year += 1900;
            else
                date.year += 2000;
        }
    }

    return date;
}
