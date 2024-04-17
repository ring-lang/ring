/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: url.c
 *
 */

/* URL parser */

#include "url.h"
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

struct _url_t
{
    String *scheme;
    String *user;
    String *pass;
    String *host;
    String *path;
    String *params;
    String *query;
    String *fragment;
    uint16_t port;
};

/*---------------------------------------------------------------------------*/

Url *url_parse(const char_t *url)
{
    Url *uurl = heap_new0(Url);
    const char_t *start = url;
    const char_t *end = url + str_len_c(url);
    const char_t *scheme_pos = str_str(start, ":");
    const char_t *at_sign_pos = NULL;
    const char_t *path_pos = NULL;
    uurl->port = UINT16_MAX;

    if (scheme_pos != NULL)
    {
        uurl->scheme = str_cn(start, (uint32_t)(scheme_pos - start));
        start = scheme_pos + 1;
    }

    if (str_str(start, "//") == start)
        start += 2;

    at_sign_pos = str_str(start, "@");
    if (at_sign_pos != NULL)
    {
        const char_t *pass_pos = str_str(start, ":");
        if (pass_pos != NULL && pass_pos < at_sign_pos)
        {
            uurl->pass = str_cn(pass_pos + 1, (uint32_t)(at_sign_pos - pass_pos - 1));
            uurl->user = str_cn(start, (uint32_t)(pass_pos - start));
        }
        else
        {
            uurl->user = str_cn(start, (uint32_t)(at_sign_pos - start));
        }

        start = at_sign_pos + 1;
    }

    path_pos = str_str(start, "/");
    if (path_pos != NULL)
    {
        const char_t *fragment_pos = str_str(start, "#");
        const char_t *query_pos = str_str(start, "?");
        const char_t *param_pos = str_str(start, ";");

        if (fragment_pos != NULL)
        {
            uurl->fragment = str_cn(fragment_pos + 1, (uint32_t)(end - fragment_pos - 1));
            end = fragment_pos;
        }

        if (query_pos != NULL)
        {
            uurl->query = str_cn(query_pos + 1, (uint32_t)(end - query_pos - 1));
            end = query_pos;
        }

        if (param_pos != NULL)
        {
            uurl->params = str_cn(param_pos + 1, (uint32_t)(end - param_pos - 1));
            end = param_pos;
        }

        uurl->path = str_cn(path_pos, (uint32_t)(end - path_pos));
        end = path_pos;
    }

    {
        const char_t *port_pos = str_str(start, ":");
        if (port_pos != NULL && port_pos < end)
        {
            String *port = str_cn(port_pos + 1, (uint32_t)(end - port_pos) - 1);
            uurl->port = str_to_u16(tc(port), 10, NULL);
            uurl->host = str_cn(start, (uint32_t)(port_pos - start));
            str_destroy(&port);
        }
        else
        {
            uurl->host = str_cn(start, (uint32_t)(end - start));
        }
    }

    return uurl;
}

/*---------------------------------------------------------------------------*/

void url_destroy(Url **url)
{
    cassert_no_null(url);
    cassert_no_null(*url);
    str_destopt(&(*url)->scheme);
    str_destopt(&(*url)->user);
    str_destopt(&(*url)->pass);
    str_destopt(&(*url)->host);
    str_destopt(&(*url)->path);
    str_destopt(&(*url)->params);
    str_destopt(&(*url)->query);
    str_destopt(&(*url)->fragment);
    heap_delete(url, Url);
}

/*---------------------------------------------------------------------------*/

const char_t *url_scheme(const Url *url)
{
    cassert_no_null(url);
    return tc(url->scheme);
}

/*---------------------------------------------------------------------------*/

const char_t *url_user(const Url *url)
{
    cassert_no_null(url);
    return tc(url->user);
}

/*---------------------------------------------------------------------------*/

const char_t *url_pass(const Url *url)
{
    cassert_no_null(url);
    return tc(url->pass);
}

/*---------------------------------------------------------------------------*/

const char_t *url_host(const Url *url)
{
    cassert_no_null(url);
    return tc(url->host);
}

/*---------------------------------------------------------------------------*/

const char_t *url_path(const Url *url)
{
    cassert_no_null(url);
    return tc(url->path);
}

/*---------------------------------------------------------------------------*/

const char_t *url_params(const Url *url)
{
    cassert_no_null(url);
    return tc(url->params);
}

/*---------------------------------------------------------------------------*/

const char_t *url_query(const Url *url)
{
    cassert_no_null(url);
    return tc(url->query);
}

/*---------------------------------------------------------------------------*/

const char_t *url_fragment(const Url *url)
{
    cassert_no_null(url);
    return tc(url->fragment);
}

/*---------------------------------------------------------------------------*/

String *url_resource(const Url *url)
{
    String *res = NULL;
    cassert_no_null(url);
    res = str_copy(url->path);

    if (url->params != NULL)
    {
        str_cat(&res, ";");
        str_cat(&res, tc(url->params));
    }

    if (url->query != NULL)
    {
        str_cat(&res, "?");
        str_cat(&res, tc(url->query));
    }

    if (url->fragment != NULL)
    {
        str_cat(&res, "#");
        str_cat(&res, tc(url->fragment));
    }

    return res;
}

/*---------------------------------------------------------------------------*/

uint16_t url_port(const Url *url)
{
    cassert_no_null(url);
    return url->port;
}
