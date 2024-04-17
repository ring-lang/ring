/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oshttpreq.c
 *
 */

/* HTTP request (WinINet-based implementation) */

#include "oshttpreq.inl"
#include <core/arrst.h>
#include <core/heap.h>
#include <core/stream.h>
#include <core/strings.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")
#include <sewer/warn.hxx>

struct _oshttp_t
{
    HINTERNET hInternet;
    HINTERNET hConnect;
    HINTERNET hRequest;
    ierror_t error;
    bool_t secure;
    Stream *headers;
};

/*---------------------------------------------------------------------------*/

void oshttp_init(void)
{
}

/*---------------------------------------------------------------------------*/

void oshttp_finish(void)
{
}

/*---------------------------------------------------------------------------*/

OSHttp *oshttp_create(const char_t *host, const uint16_t port, const bool_t secure)
{
    OSHttp *http = heap_new0(OSHttp);

    http->secure = secure;
    http->error = ekIOK;
    http->hInternet = InternetOpen(L"nappgui", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    http->headers = stm_memory(1024);
    stm_set_write_utf(http->headers, ekUTF16);

    if (http->hInternet != NULL)
    {
        WCHAR whost[128];
        unicode_convers(host, (char_t *)whost, ekUTF8, ekUTF16, sizeof(whost));
        http->hConnect = InternetConnect(http->hInternet, whost, (INTERNET_PORT)port, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);

        if (http->hConnect == NULL)
            http->error = ekINOHOST;
    }
    else
    {
        http->error = ekINONET;
    }

    return http;
}

/*---------------------------------------------------------------------------*/

void oshttp_destroy(OSHttp **http)
{
    cassert_no_null(http);
    cassert_no_null(*http);

    if ((*http)->hRequest != NULL)
        InternetCloseHandle((*http)->hRequest);

    if ((*http)->hConnect != NULL)
        InternetCloseHandle((*http)->hConnect);

    if ((*http)->hInternet != NULL)
        InternetCloseHandle((*http)->hInternet);

    stm_close(&(*http)->headers);

    heap_delete(http, OSHttp);
}

/*---------------------------------------------------------------------------*/

void oshttp_clear_headers(OSHttp *http)
{
    cassert_no_null(http);
    stm_close(&http->headers);
    http->headers = stm_memory(1024);
    stm_set_write_utf(http->headers, ekUTF16);
}

/*---------------------------------------------------------------------------*/

void oshttp_add_header(OSHttp *http, const char_t *name, const char_t *value)
{
    cassert_no_null(http);

    if (stm_bytes_written(http->headers) > 0)
        stm_writef(http->headers, "\n");

    stm_writef(http->headers, name);
    stm_writef(http->headers, ": ");
    stm_writef(http->headers, value);
}

/*---------------------------------------------------------------------------*/

static void i_request(OSHttp *http, const WCHAR *verb, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    WCHAR wpath[1024];
    uint64_t hsize = 0;
    BOOL status = FALSE;
    DWORD flags = 0;

    cassert_no_null(http);

    if (http->error != ekIOK)
    {
        ptr_assign(error, http->error);
        return;
    }

    unicode_convers(path, (char_t *)wpath, ekUTF8, ekUTF16, sizeof(wpath));

    if (http->hRequest != NULL)
    {
        InternetCloseHandle(http->hRequest);
        http->hRequest = NULL;
    }

    flags |= http->secure ? INTERNET_FLAG_SECURE : 0;
    flags |= auto_redirect ? 0 : INTERNET_FLAG_NO_AUTO_REDIRECT;
    http->hRequest = HttpOpenRequest(http->hConnect, verb, wpath, L"HTTP/1.1", NULL, NULL, flags, 0);
    if (http->hRequest == NULL)
    {
        ptr_assign(error, ekISERVER);
        return;
    }

    hsize = stm_bytes_written(http->headers);
    if (hsize > 0)
    {
        WCHAR *lpszHeaders = (WCHAR *)stm_buffer(http->headers);
        status = HttpSendRequest(http->hRequest, lpszHeaders, (DWORD)hsize / sizeof(WCHAR), (LPVOID)data, (DWORD)size);
    }
    else
    {
        status = HttpSendRequest(http->hRequest, NULL, (DWORD)-1, (LPVOID)data, (DWORD)size);
    }

    if (status == TRUE)
    {
        ptr_assign(error, ekIOK);
    }
    else
    {
        ptr_assign(error, ekISERVER);
        InternetCloseHandle(http->hRequest);
        http->hRequest = NULL;
    }
}

/*---------------------------------------------------------------------------*/

void oshttp_get(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    i_request(http, L"GET", path, data, size, auto_redirect, error);
}

/*---------------------------------------------------------------------------*/

void oshttp_post(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    i_request(http, L"POST", path, data, size, auto_redirect, error);
}

/*---------------------------------------------------------------------------*/

Stream *oshttp_response(OSHttp *http)
{
    cassert_no_null(http);
    if (http->hRequest != NULL)
    {
        uint32_t i = 0;
        DWORD asize = 512;
        DWORD size = 512;
        for (i = 0; i < 2; ++i)
        {
            WCHAR *data = (WCHAR *)heap_malloc((uint32_t)asize, "http_headers");

            if (HttpQueryInfo(http->hRequest, HTTP_QUERY_RAW_HEADERS_CRLF, (LPVOID)data, &size, NULL) == TRUE)
            {
                Stream *stm_src = stm_from_block((const byte_t *)data, (uint32_t)size);
                Stream *stm_dest = stm_memory(size + 10);

                stm_set_read_utf(stm_src, ekUTF16);
                stm_set_write_utf(stm_dest, ekUTF8);

                stm_lines(line, stm_src)
                    stm_writef(stm_dest, line);
                    stm_write_char(stm_dest, 13); // CR '\r'
                    stm_write_char(stm_dest, 10); // LF '\n'
                stm_next(line, stm_src)

                heap_free((byte_t **)&data, (uint32_t)asize, "http_headers");
                stm_close(&stm_src);
                return stm_dest;
            }
            else
            {
                heap_free((byte_t **)&data, (uint32_t)asize, "http_headers");
                if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
                {
                    asize = size;
                }
                else
                {
                    cassert(FALSE);
                }
            }
        }
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

void oshttp_response_body(OSHttp *http, Stream *body, ierror_t *error)
{
    cassert_no_null(http);
    if (http->hRequest != NULL)
    {
        char szBuffer[1024];
        DWORD dwByteRead = 0;

        do
        {
            if (InternetReadFile(http->hRequest, szBuffer, sizeof(szBuffer), &dwByteRead) == TRUE)
            {
                stm_write(body, (const byte_t *)szBuffer, (uint32_t)dwByteRead);
            }
            else
            {
                ptr_assign(error, ekISTREAM);
                return;
            }

        } while (dwByteRead);
    }

    ptr_assign(error, ekIOK);
}
