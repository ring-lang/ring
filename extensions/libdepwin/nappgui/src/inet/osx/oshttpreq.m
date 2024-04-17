/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oshttpreq.m
 *
 */

/* HTTP request (Cocoa-based implementation) */

#include "oshttpreq.inl"
#include <sewer/nowarn.hxx>
#include <Cocoa/Cocoa.h>
#include <sewer/warn.hxx>
#include <core/arrst.h>
#include <core/heap.h>
#include <core/stream.h>
#include <core/strings.h>
#include <osbs/bmutex.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
@interface OSXURLDelegate : NSObject <NSURLSessionDelegate, NSURLSessionDataDelegate, NSURLSessionTaskDelegate>
{
  @public
    OSHttp *http;
    bool_t auto_redirect;
}

@end

#endif

/*---------------------------------------------------------------------------*/

struct _oshttp_t
{
    String *host_url;
    uint16_t port;
    bool_t secure;
    bool_t response;

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
    Mutex *mutex;
    NSURLSession *session;
    OSXURLDelegate *delegate;
#endif

    NSMutableURLRequest *request;
    ierror_t error;
    String *protocol;
    Stream *headers;
    Stream *body;
};

/*---------------------------------------------------------------------------*/

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9

@implementation OSXURLDelegate

#if defined(MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics
{
    NSArray *ar = [metrics transactionMetrics];

    for (NSURLSessionTaskTransactionMetrics *tr in ar)
    {
        NSString *str = [tr networkProtocolName];
        if (str != nil)
        {
            bmutex_lock(self->http->mutex);
            if (self->http->protocol != NULL)
                self->http->protocol = str_c((const char_t *)[str UTF8String]);
            bmutex_unlock(self->http->mutex);
        }
    }

    cassert(metrics != nil);
}

/*---------------------------------------------------------------------------*/

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
    willPerformHTTPRedirection:(NSHTTPURLResponse *)response
                    newRequest:(NSURLRequest *)request
             completionHandler:(void (^)(NSURLRequest *_Nullable))completionHandler
{
    unref(session);
    unref(task);
    unref(response);
    if (auto_redirect == TRUE)
        completionHandler(request);
    else
        completionHandler(nil);
}

#endif

@end

#endif

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
    OSHttp *http = heap_new(OSHttp);

    if (secure == TRUE)
        http->host_url = str_printf("https://%s:%d", host, port);
    else
        http->host_url = str_printf("http://%s:%d", host, port);

    http->port = port;
    http->secure = secure;

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
    http->delegate = [[OSXURLDelegate alloc] init];
    http->delegate->http = http;
    http->delegate->auto_redirect = TRUE;
    http->session = [[NSURLSession sessionWithConfiguration:[NSURLSessionConfiguration defaultSessionConfiguration] delegate:http->delegate delegateQueue:nil] retain];
    http->mutex = bmutex_create();
#endif

    http->request = [[NSMutableURLRequest alloc] init];
    http->response = FALSE;
    http->protocol = NULL;
    http->headers = NULL;
    http->body = NULL;
    return http;
}

/*---------------------------------------------------------------------------*/

void oshttp_destroy(OSHttp **http)
{
    cassert_no_null(http);
    cassert_no_null(*http);
    str_destroy(&(*http)->host_url);

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
    [(*http)->session release];
    [(*http)->delegate release];
    bmutex_close(&(*http)->mutex);
#endif

    [(*http)->request release];
    str_destopt(&(*http)->protocol);

    if ((*http)->headers != NULL)
        stm_close(&(*http)->headers);

    if ((*http)->body != NULL)
        stm_close(&(*http)->body);

    heap_delete(http, OSHttp);
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_reserved_header(const char_t *header)
{
    if (str_equ_nocase(header, "content-length") == TRUE)
        return TRUE;

    if (str_equ_nocase(header, "authorization") == TRUE)
        return TRUE;

    if (str_equ_nocase(header, "connection") == TRUE)
        return TRUE;

    if (str_equ_nocase(header, "host") == TRUE)
        return TRUE;

    if (str_equ_nocase(header, "proxy-authenticate") == TRUE)
        return TRUE;

    if (str_equ_nocase(header, "proxy-authorization") == TRUE)
        return TRUE;

    if (str_equ_nocase(header, "www-authenticate") == TRUE)
        return TRUE;

    return FALSE;
}

/*---------------------------------------------------------------------------*/

void oshttp_clear_headers(OSHttp *http)
{
    cassert_no_null(http);
    unref(http);
}

/*---------------------------------------------------------------------------*/

void oshttp_add_header(OSHttp *http, const char_t *name, const char_t *value)
{
    if (http->request != nil)
    {
        if (i_reserved_header(name) == FALSE)
        {
            NSString *lname = [NSString stringWithUTF8String:name];
            NSString *lvalue = [NSString stringWithUTF8String:value];
            [http->request setValue:lvalue forHTTPHeaderField:lname];
        }
    }
}

/*---------------------------------------------------------------------------*/

static ierror_t i_http_error(const NSInteger code)
{
    switch (code)
    {
    case NSURLErrorUnknown:
        return ekIUNDEF;
    case NSURLErrorCancelled:
        return ekIUNDEF;
    case NSURLErrorBadURL:
        return ekINOHOST;
    case NSURLErrorTimedOut:
        return ekITIMEOUT;
    case NSURLErrorUnsupportedURL:
        return ekINOHOST;
    case NSURLErrorCannotFindHost:
        return ekINOHOST;
    case NSURLErrorCannotConnectToHost:
        return ekINOHOST;
    case NSURLErrorNetworkConnectionLost:
        return ekINONET;
    case NSURLErrorDNSLookupFailed:
        return ekINOHOST;
    case NSURLErrorHTTPTooManyRedirects:
        return ekINOHOST;
    case NSURLErrorResourceUnavailable:
        return ekINOHOST;
    case NSURLErrorNotConnectedToInternet:
        return ekINONET;
    case NSURLErrorRedirectToNonExistentLocation:
        return ekINOHOST;
    case NSURLErrorBadServerResponse:
        return ekISERVER;
    case NSURLErrorUserCancelledAuthentication:
        return ekISERVER;
    case NSURLErrorUserAuthenticationRequired:
        return ekISERVER;
    case NSURLErrorZeroByteResource:
        return ekISERVER;
    case NSURLErrorCannotDecodeRawData:
        return ekISERVER;
    case NSURLErrorCannotDecodeContentData:
        return ekISERVER;
    case NSURLErrorCannotParseResponse:
        return ekISERVER;
    case NSURLErrorFileDoesNotExist:
        return ekINOHOST;
    case NSURLErrorFileIsDirectory:
        return ekISERVER;
    case NSURLErrorNoPermissionsToReadFile:
        return ekISERVER;
    default:
        return ekIUNDEF;
    }
}

/*---------------------------------------------------------------------------*/

static void i_response(NSData *data, NSURLResponse *response, NSError *error, OSHttp *http)
{
#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
    bmutex_lock(http->mutex);
#endif

    cassert(http->response == FALSE);
    cassert(http->headers == NULL);
    cassert(http->body == NULL);

    if (error != nil)
    {
        http->response = TRUE;
        http->error = i_http_error([error code]);
    }
    else if (data != nil)
    {
        NSHTTPURLResponse *http_response = (NSHTTPURLResponse *)response;
        NSInteger code = [http_response statusCode];
        NSDictionary *rheaders = [http_response allHeaderFields];
        NSString *rmessage = [NSHTTPURLResponse localizedStringForStatusCode:code];
        uint32_t dsize = (uint32_t)[data length];
        const byte_t *dbytes = [data bytes];

        http->headers = stm_memory(512);
        if (http->protocol != NULL)
            stm_printf(http->headers, "%s %ld %s", tc(http->protocol), (long)code, [rmessage UTF8String]);
        else
            stm_printf(http->headers, "HTTP/1.1 %ld %s", (long)code, [rmessage UTF8String]);

        stm_write_char(http->headers, 13);
        stm_write_char(http->headers, 10);

        for (NSString *key in rheaders)
        {
            NSString *value = [rheaders objectForKey:key];
            stm_printf(http->headers, "%s: %s", [key UTF8String], [value UTF8String]);
            stm_write_char(http->headers, 13);
            stm_write_char(http->headers, 10);
        }

        http->body = stm_memory(dsize + 32);
        stm_write(http->body, dbytes, dsize);
        http->error = ekIOK;
        http->response = TRUE;
    }
    else
    {
        http->error = ekIUNDEF;
        http->response = TRUE;
    }

#if defined(MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
    bmutex_unlock(http->mutex);
#endif
}

/*---------------------------------------------------------------------------*/

static void i_request(OSHttp *http, NSString *verb, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    cassert_no_null(http);
    http->response = FALSE;
    str_destopt(&http->protocol);
    ptr_destopt(stm_close, &http->headers, Stream);
    ptr_destopt(stm_close, &http->body, Stream);
    http->error = ekIOK;

    {
        NSString *curl = [[NSString alloc] initWithFormat:@"%s/%s", tc(http->host_url), path];
        NSURL *url = [[NSURL alloc] initWithString:curl];
        [http->request setURL:url];
        [url release];
        [curl release];
    }

    [http->request setHTTPMethod:verb];

    if (data != NULL)
    {
        NSData *nsdata = [NSData dataWithBytes:(const void *)data length:(NSUInteger)size];
        [http->request setHTTPBody:nsdata];
    }
    else
    {
        cassert(size == 0);
    }

#if defined(MAC_OS_X_VERSION_10_11) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_11
    {
        /* Synchronous request */
        bool_t end = FALSE;
        NSURLSessionTask *task = nil;
        http->delegate->auto_redirect = auto_redirect;
        task = [http->session dataTaskWithRequest:http->request
                                completionHandler:^(NSData *_Nullable ddata, NSURLResponse *_Nullable response, NSError *_Nullable lerror) {
                                  i_response(ddata, response, lerror, http);
                                }];

        [task resume];

        while (!end)
        {
            bmutex_lock(http->mutex);
            end = http->response;
            bmutex_unlock(http->mutex);
        }
    }
#else
    {
        NSURLResponse *response = nil;
        NSError *lerror = nil;
        NSData *ddata = [NSURLConnection sendSynchronousRequest:http->request returningResponse:&response error:&lerror];
        unref(auto_redirect);
        i_response(ddata, response, lerror, http);
    }
#endif

    ptr_assign(error, http->error);
}

/*---------------------------------------------------------------------------*/

void oshttp_get(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    i_request(http, @"GET", path, data, size, auto_redirect, error);
}

/*---------------------------------------------------------------------------*/

void oshttp_post(OSHttp *http, const char_t *path, const byte_t *data, const uint32_t size, const bool_t auto_redirect, ierror_t *error)
{
    i_request(http, @"POST", path, data, size, auto_redirect, error);
}

/*---------------------------------------------------------------------------*/

Stream *oshttp_response(OSHttp *http)
{
    Stream *stm = NULL;
    cassert_no_null(http);
    cassert(http->response == TRUE);
    if (http->error == ekIOK)
    {
        stm = http->headers;
        http->headers = NULL;
    }

    return stm;
}

/*---------------------------------------------------------------------------*/

void oshttp_response_body(OSHttp *http, Stream *body, ierror_t *error)
{
    cassert_no_null(http);
    cassert(http->response == TRUE);

    if (http->error == ekIOK)
    {
        uint32_t size = stm_buffer_size(http->body);
        stm_pipe(http->body, body, size);
    }

    ptr_assign(error, http->error);
}
