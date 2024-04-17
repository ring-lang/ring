/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: httpreq.c
 *
 */

/* HTTP request */

#include "httpreq.h"
#include "oshttpreq.inl"
#include "url.h"
#include <core/arrst.h>
#include <core/heap.h>
#include <core/stream.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

struct _http_t
{
    OSHttp *oshttp;
    String *host_name;
    uint32_t host_ip;
    uint16_t host_port;
    ierror_t error;
    uint32_t rcode;
    String *rprotocol;
    String *rmsg;
    ArrSt(Field) *headers;
};

/*---------------------------------------------------------------------------*/

static void i_remove_field(Field *field)
{
    cassert_no_null(field);
    str_destroy(&field->name);
    str_destroy(&field->value);
}

/*---------------------------------------------------------------------------*/

void http_destroy(Http **http)
{
    cassert_no_null(http);
    cassert_no_null(*http);
    str_destroy(&(*http)->host_name);
    ptr_destopt(str_destroy, &(*http)->rprotocol, String);
    ptr_destopt(str_destroy, &(*http)->rmsg, String);
    arrst_destroy(&(*http)->headers, i_remove_field, Field);
    oshttp_destroy(&(*http)->oshttp);
    heap_delete(http, Http);
}

/*---------------------------------------------------------------------------*/

static Http *i_create(const char_t *host, const uint16_t port, const bool_t secure)
{
    Http *http = heap_new(Http);
    http->oshttp = oshttp_create(host, port, secure);
    http->host_name = str_c(host);
    http->host_port = port;
    http->error = ENUM_MAX(ierror_t);
    http->rcode = UINT32_MAX;
    http->rmsg = NULL;
    http->rprotocol = NULL;
    http->headers = arrst_create(Field);
    return http;
}

/*---------------------------------------------------------------------------*/

Http *http_create(const char_t *host, const uint16_t port)
{
    return i_create(host, port == UINT16_MAX ? 80 : port, FALSE);
}

/*---------------------------------------------------------------------------*/

Http *http_secure(const char_t *host, const uint16_t port)
{
    return i_create(host, port == UINT16_MAX ? 443 : port, TRUE);
}

/*---------------------------------------------------------------------------*/

void http_clear_headers(Http *http)
{
    cassert_no_null(http);
    oshttp_clear_headers(http->oshttp);
}

/*---------------------------------------------------------------------------*/

void http_add_header(Http *http, const char_t *name, const char_t *value)
{
    cassert_no_null(http);
    oshttp_add_header(http->oshttp, name, value);
}

/*---------------------------------------------------------------------------*/

static const char_t *i_field(ArrSt(Field) *fields, const char_t *name)
{
    arrst_foreach(field, fields, Field)
        if (str_equ_nocase(tc(field->name), name) == TRUE)
            return tc(field->value);
    arrst_end()
    return NULL;
}

/*---------------------------------------------------------------------------*/

static void i_clear_response(Http *http)
{
    cassert_no_null(http);
    http->error = ENUM_MAX(ierror_t);
    http->rcode = UINT32_MAX;
    ptr_destopt(str_destroy, &http->rprotocol, String);
    ptr_destopt(str_destroy, &http->rmsg, String);
    arrst_clear(http->headers, i_remove_field, Field);
}

/*---------------------------------------------------------------------------*/

bool_t http_get(Http *http, const char_t *path, const byte_t *data, const uint32_t size, ierror_t *error)
{
    cassert_no_null(http);
    i_clear_response(http);
    oshttp_get(http->oshttp, path, data, size, TRUE, &http->error);
    ptr_assign(error, http->error);
    return http->error == ekIOK ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t http_post(Http *http, const char_t *path, const byte_t *data, const uint32_t size, ierror_t *error)
{
    cassert_no_null(http);
    i_clear_response(http);
    oshttp_post(http->oshttp, path, data, size, TRUE, &http->error);
    ptr_assign(error, http->error);
    return http->error == ekIOK ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_response(Http *http)
{
    cassert_no_null(http);
    if (http->rcode == UINT32_MAX)
    {
        if (http->error == ekIOK)
        {
            Stream *stm = oshttp_response(http->oshttp);
            if (stm != NULL)
            {
                cassert(http->rprotocol == NULL);
                cassert(http->rmsg == NULL);

                stm_lines(line, stm)

                    if (str_empty_c(line) == FALSE)
                    {
                        /* The headers could contain several responses (redirection)
                        We get the last one */
                        if (str_str(line, ":") == NULL)
                        {
                            const char_t *st = line;
                            char_t code[64];
                            uint32_t i = 0;

                            str_destopt(&http->rprotocol);
                            str_destopt(&http->rmsg);

                            while (*line != ' ')
                                line++;
                            http->rprotocol = str_cn(st, (uint32_t)(line - st));

                            line++;
                            while (*line != ' ' && *line != '\0')
                            {
                                code[i] = *line;
                                line++;
                                i++;
                            }

                            code[i] = '\0';

                            http->rcode = str_to_u32(code, 10, NULL);

                            if (*line != '\0')
                            {
                                line++;
                                http->rmsg = str_c(line);
                            }
                            else
                            {
                                http->rmsg = str_c("");
                            }

                            arrst_clear(http->headers, i_remove_field, Field);
                        }
                        else
                        {
                            Field *header = arrst_new(http->headers, Field);
                            str_split_trim(line, ":", &header->name, &header->value);
                        }
                    }

                stm_next(line, stm)

                stm_close(&stm);
                return TRUE;
            }
            else
            {
                http->error = ekIUNDEF;
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return TRUE;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t http_response_status(const Http *http)
{
    if (i_response((Http *)http) == TRUE)
        return http->rcode;
    else
        return UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

const char_t *http_response_protocol(const Http *http)
{
    if (i_response((Http *)http) == TRUE)
        return tc(http->rprotocol);
    else
        return "";
}

/*---------------------------------------------------------------------------*/

const char_t *http_response_message(const Http *http)
{
    if (i_response((Http *)http) == TRUE)
        return tc(http->rmsg);
    else
        return "";
}

/*---------------------------------------------------------------------------*/

uint32_t http_response_size(const Http *http)
{
    if (i_response((Http *)http) == TRUE)
        return arrst_size(http->headers, Field);
    else
        return 0;
}

/*---------------------------------------------------------------------------*/

const char_t *http_response_name(const Http *http, const uint32_t index)
{
    if (i_response((Http *)http) == TRUE)
    {
        const Field *field = arrst_get(http->headers, index, Field);
        return tc(field->name);
    }
    else
    {
        return "";
    }
}

/*---------------------------------------------------------------------------*/

const char_t *http_response_value(const Http *http, const uint32_t index)
{
    if (i_response((Http *)http) == TRUE)
    {
        const Field *field = arrst_get(http->headers, index, Field);
        return tc(field->value);
    }
    else
    {
        return "";
    }
}

/*---------------------------------------------------------------------------*/

const char_t *http_response_header(const Http *http, const char_t *name)
{
    if (i_response((Http *)http) == TRUE)
    {
        const char_t *value = i_field(http->headers, name);
        if (value != NULL)
            return value;
        else
            return "";
    }
    else
    {
        return "";
    }
}

/*---------------------------------------------------------------------------*/

bool_t http_response_body(const Http *http, Stream *body, ierror_t *error)
{
    ierror_t lerror;
    cassert_no_null(http);
    oshttp_response_body(http->oshttp, body, &lerror);
    ptr_assign(error, lerror);
    return lerror == ekIOK ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

Stream *http_dget(const char_t *url, uint32_t *result, ierror_t *error)
{
    Url *uurl = url_parse(url);
    const char_t *sh = url_scheme(uurl);
    const char_t *host = url_host(uurl);
    uint16_t port = url_port(uurl);
    Http *http = NULL;
    Stream *stm = NULL;

    ptr_assign(error, ekIOK);

    if (str_equ_nocase(sh, "http") == TRUE)
        http = http_create(host, port);
    else if (str_equ_nocase(sh, "https") == TRUE)
        http = http_secure(host, port);

    if (http != NULL)
    {
        String *res = url_resource(uurl);
        if (http_get(http, tc(res), NULL, 0, error) == TRUE)
        {
            if (result != NULL)
                *result = http_response_status(http);

            stm = stm_memory(2048);
            if (http_response_body(http, stm, error) == FALSE)
                stm_close(&stm);
        }

        http_destroy(&http);
        str_destroy(&res);
    }
    else
    {
        ptr_assign(error, ekINOHOST);
    }

    url_destroy(&uurl);
    return stm;
}

/*---------------------------------------------------------------------------*/

bool_t http_exists(const char_t *url)
{
    bool_t exists = FALSE;
    Url *uurl = url_parse(url);
    const char_t *sh = url_scheme(uurl);
    const char_t *host = url_host(uurl);
    uint16_t port = url_port(uurl);
    Http *http = NULL;

    if (str_equ_nocase(sh, "http") == TRUE)
        http = http_create(host, port);
    else if (str_equ_nocase(sh, "https") == TRUE)
        http = http_secure(host, port);

    if (http != NULL)
    {
        String *res = url_resource(uurl);
        i_clear_response(http);
        oshttp_get(http->oshttp, tc(res), NULL, 0, FALSE, &http->error);
        if (http->error == ekIOK)
        {
            uint32_t result = http_response_status(http);
            if (result >= 200 && result <= 299)
                exists = TRUE;
        }

        http_destroy(&http);
        str_destroy(&res);
    }

    url_destroy(&uurl);
    return exists;
}
