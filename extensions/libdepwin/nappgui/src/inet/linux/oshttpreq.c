/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oshttpreq.c
 *
 */

/* HTTP request (LibCURL-based implementation) */

#include "oshttpreq.inl"
#include <core/arrst.h>
#include <core/heap.h>
#include <core/stream.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <curl/curl.h>

#if !defined(__LINUX__)
#error This file is only for Linux system
#endif

struct _oshttp_t
{
    CURL *curl;
    struct curl_slist *headers;
    String *host_url;
    bool_t secure;
    Stream *resp_headers;
    Stream *resp_data;
    ierror_t error;
};

/*---------------------------------------------------------------------------*/

void oshttp_init(void)
{
    curl_global_init(CURL_GLOBAL_ALL);
}

/*---------------------------------------------------------------------------*/

void oshttp_finish(void)
{
    curl_global_cleanup();
}

/*---------------------------------------------------------------------------*/

OSHttp *oshttp_create(const char_t *host, const uint16_t port, const bool_t secure)
{
    OSHttp *http = heap_new(OSHttp);
    http->curl = curl_easy_init();
    http->error = ekIOK;
    http->secure = secure;
    http->headers = NULL;
    http->resp_headers = NULL;
    http->resp_data = NULL;

    if (secure == TRUE)
        http->host_url = str_printf("https://%s", host);
    else
        http->host_url = str_printf("http://%s", host);

    if (http->curl != NULL)
    {
        int res = curl_easy_setopt(http->curl, CURLOPT_PORT, port);
        cassert_unref(res == CURLE_OK, res);
    }
    else
    {
        http->error = ekIUNDEF;
    }

    return http;
}

/*---------------------------------------------------------------------------*/

void oshttp_destroy(OSHttp **http)
{
    cassert_no_null(http);
    cassert_no_null(*http);

    if ((*http)->headers != NULL)
    {
        curl_slist_free_all((*http)->headers);
        (*http)->headers = NULL;
    }

    str_destroy(&(*http)->host_url);

    if ((*http)->curl != NULL)
        curl_easy_cleanup((*http)->curl);

    if ((*http)->resp_headers != NULL)
        stm_close(&(*http)->resp_headers);

    if ((*http)->resp_data != NULL)
        stm_close(&(*http)->resp_data);

    heap_delete(http, OSHttp);
}

/*---------------------------------------------------------------------------*/

void oshttp_clear_headers(OSHttp *http)
{
    cassert_no_null(http);
    if (http->headers != NULL)
    {
        curl_slist_free_all(http->headers);
        http->headers = NULL;
    }
}

/*---------------------------------------------------------------------------*/

void oshttp_add_header(OSHttp *http, const char_t *name, const char_t *value)
{
    String *str = NULL;
    cassert(http != NULL);
    str = str_printf("%s: %s", name, value);
    http->headers = curl_slist_append(http->headers, tc(str));
    str_destroy(&str);
}

/*---------------------------------------------------------------------------*/

static size_t i_write_response(char *buffer, size_t size, size_t nitems, void *userdata)
{
    Stream *stm = (Stream *)userdata;
    stm_write(stm, (const byte_t *)buffer, (uint32_t)(size * nitems));
    return nitems * size;
}

/*---------------------------------------------------------------------------*/

static void i_request(OSHttp *http, const bool_t use_get, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    int res = 0;
    cassert_no_null(http);

    if (http->error != ekIOK)
    {
        ptr_assign(error, http->error);
        return;
    }

    /* Seems that CURLOPT_FOLLOWLOCATION fails */
    res = curl_easy_setopt(http->curl, CURLOPT_FOLLOWLOCATION, auto_redirect ? 1L : 0L);
    cassert_unref(res == CURLE_OK, res);

    {
        String *url = str_printf("%s%s", tc(http->host_url), path);
        res = curl_easy_setopt(http->curl, CURLOPT_URL, tc(url));
        cassert_unref(res == CURLE_OK, res);
        str_destroy(&url);
    }

    if (http->headers != NULL)
    {
        res = curl_easy_setopt(http->curl, CURLOPT_HTTPHEADER, http->headers);
        cassert_unref(res == CURLE_OK, res);
    }

    if (data != NULL)
    {
        res = curl_easy_setopt(http->curl, CURLOPT_POSTFIELDSIZE, size);
        cassert_unref(res == CURLE_OK, res);
        res = curl_easy_setopt(http->curl, CURLOPT_POSTFIELDS, (char *)data);
        cassert_unref(res == CURLE_OK, res);
    }

    if (use_get == TRUE)
    {
        res = curl_easy_setopt(http->curl, CURLOPT_HTTPGET, 1);
        cassert_unref(res == CURLE_OK, res);
    }
    else
    {
        res = curl_easy_setopt(http->curl, CURLOPT_POST, 1);
        cassert_unref(res == CURLE_OK, res);
    }

    if (http->resp_headers != NULL)
        stm_close(&http->resp_headers);

    if (http->resp_data != NULL)
        stm_close(&http->resp_data);

    http->resp_headers = stm_memory(100 * 1024);
    http->resp_data = stm_memory(1024 * 1024);

    res = curl_easy_setopt(http->curl, CURLOPT_HEADERFUNCTION, i_write_response);
    cassert(res == CURLE_OK);
    res = curl_easy_setopt(http->curl, CURLOPT_HEADERDATA, http->resp_headers);
    cassert(res == CURLE_OK);

    res = curl_easy_setopt(http->curl, CURLOPT_WRITEFUNCTION, i_write_response);
    cassert(res == CURLE_OK);
    res = curl_easy_setopt(http->curl, CURLOPT_WRITEDATA, http->resp_data);
    cassert(res == CURLE_OK);

    res = curl_easy_perform(http->curl);
    if (res == CURLE_OK)
    {
        ptr_assign(error, ekIOK);
    }
    else
    {
        /* TODO: Error codes */
        ptr_assign(error, ekISERVER);
    }
}

/*---------------------------------------------------------------------------*/

void oshttp_get(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    i_request(http, TRUE, path, data, size, auto_redirect, error);
}

/*---------------------------------------------------------------------------*/

void oshttp_post(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    i_request(http, FALSE, path, data, size, auto_redirect, error);
}

/*---------------------------------------------------------------------------*/

Stream *oshttp_response(OSHttp *http)
{
    Stream *stm = NULL;
    cassert_no_null(http);
    stm = http->resp_headers;
    http->resp_headers = NULL;
    return stm;
}

/*---------------------------------------------------------------------------*/

void oshttp_response_body(OSHttp *http, Stream *body, ierror_t *error)
{
    const byte_t *data = NULL;
    uint32_t size = 0;
    cassert_no_null(http);
    data = stm_buffer(http->resp_data);
    size = stm_buffer_size(http->resp_data);
    stm_write(body, data, size);
    stm_close(&http->resp_data);
    ptr_assign(error, ekIOK);
}
