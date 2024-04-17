/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: inet.hxx
 * https://nappgui.com/en/inet/inet.html
 *
 */

/* inet library */

#ifndef __INET_HXX__
#define __INET_HXX__

#include <core/core.hxx>
#include "inet.def"

typedef enum _ierror_t
{
    ekINONET = 1,
    ekINOHOST,
    ekITIMEOUT,
    ekISTREAM,
    ekISERVER,
    ekINOIMPL,
    ekIUNDEF,
    ekIOK
} ierror_t;

typedef struct _url_t Url;
typedef struct _http_t Http;
typedef struct _json_t Json;
typedef struct _jsonopts_t JsonOpts;

struct _jsonopts_t
{
    uint32_t not_used;
};

#endif
