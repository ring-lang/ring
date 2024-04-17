/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bsocket.c
 *
 */

/* Sockets base API */

#include "osbs.h"
#include "bsocket.h"
#include <sewer/blib.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

static uint8_t i_ip_number(const char_t **ip)
{
    char_t value[4];
    const char_t *st = *ip;
    uint64_t n;
    uint32_t i = 0;

    while (*st >= '0' && *st <= '9' && i < 3)
    {
        value[i] = *st;
        st += 1;
        i += 1;
    }

    value[i] = '\0';

    if (*st != '\0')
        st += 1;

    *ip = st;
    n = blib_strtoul(value, NULL, 10, NULL);
    return (uint8_t)n;
}

/*---------------------------------------------------------------------------*/

uint32_t bsocket_str_ip(const char_t *ip)
{
    uint8_t a, b, c, d;
    cassert_no_null(ip);
    a = i_ip_number(&ip);
    b = i_ip_number(&ip);
    c = i_ip_number(&ip);
    d = i_ip_number(&ip);
    return (uint32_t)((a << 24) | (b << 16) | (c << 8) | (d));
}

/*---------------------------------------------------------------------------*/

const char_t *bsocket_ip_str(const uint32_t ip)
{
    uint8_t a, b, c, d;
    static char_t i_NTOA[32];
    a = (uint8_t)(ip >> 24);
    b = (uint8_t)(ip >> 16);
    c = (uint8_t)(ip >> 8);
    d = (uint8_t)(ip >> 0);
    bstd_sprintf(i_NTOA, sizeof(i_NTOA), "%d.%d.%d.%d", a, b, c, d);
    return i_NTOA;
}

/*---------------------------------------------------------------------------*/

void bsocket_hton2(byte_t *dest, const byte_t *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (osbs_endian() == ekLITEND)
    {
        dest[0] = src[1];
        dest[1] = src[0];
    }
    else
    {
        dest[0] = src[0];
        dest[1] = src[1];
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_hton4(byte_t *dest, const byte_t *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (osbs_endian() == ekLITEND)
    {
        dest[0] = src[3];
        dest[1] = src[2];
        dest[2] = src[1];
        dest[3] = src[0];
    }
    else
    {
        dest[0] = src[0];
        dest[1] = src[1];
        dest[2] = src[2];
        dest[3] = src[3];
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_hton8(byte_t *dest, const byte_t *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (osbs_endian() == ekLITEND)
    {
        dest[0] = src[7];
        dest[1] = src[6];
        dest[2] = src[5];
        dest[3] = src[4];
        dest[4] = src[3];
        dest[5] = src[2];
        dest[6] = src[1];
        dest[7] = src[0];
    }
    else
    {
        dest[0] = src[0];
        dest[1] = src[1];
        dest[2] = src[2];
        dest[3] = src[3];
        dest[4] = src[4];
        dest[5] = src[5];
        dest[6] = src[6];
        dest[7] = src[7];
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_ntoh2(byte_t *dest, const byte_t *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (osbs_endian() == ekLITEND)
    {
        dest[0] = src[1];
        dest[1] = src[0];
    }
    else
    {
        dest[0] = src[0];
        dest[1] = src[1];
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_ntoh4(byte_t *dest, const byte_t *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (osbs_endian() == ekLITEND)
    {
        dest[0] = src[3];
        dest[1] = src[2];
        dest[2] = src[1];
        dest[3] = src[0];
    }
    else
    {
        dest[0] = src[0];
        dest[1] = src[1];
        dest[2] = src[2];
        dest[3] = src[3];
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_ntoh8(byte_t *dest, const byte_t *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (osbs_endian() == ekLITEND)
    {
        dest[0] = src[7];
        dest[1] = src[6];
        dest[2] = src[5];
        dest[3] = src[4];
        dest[4] = src[3];
        dest[5] = src[2];
        dest[6] = src[1];
        dest[7] = src[0];
    }
    else
    {
        dest[0] = src[0];
        dest[1] = src[1];
        dest[2] = src[2];
        dest[3] = src[3];
        dest[4] = src[4];
        dest[5] = src[5];
        dest[6] = src[6];
        dest[7] = src[7];
    }
}
