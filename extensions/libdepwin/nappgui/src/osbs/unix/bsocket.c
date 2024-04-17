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

#include "bsocket.h"
#include "osbs.inl"
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#define SOCKET_ID int
#define SOCKET_NULL -1
#define SOCKET_FAIL -1
#define RECV_SHUTDOWN SHUT_RD
#define ALL_SHUTDOWN SHUT_RDWR
#define SIZE_T size_t
#define SSIZE_T ssize_t

/*---------------------------------------------------------------------------*/

static const char_t *i_WELL_KNOW_URL = "www.google.com";

/*---------------------------------------------------------------------------*/

void _osbs_start_sockets(void)
{
}

/*---------------------------------------------------------------------------*/

void _osbs_finish_sockets(void)
{
}

/*---------------------------------------------------------------------------*/

static serror_t i_socket_error(void)
{
    int sock_error = errno;

    switch (sock_error)
    {
    case ETIMEDOUT:
        return ekSTIMEOUT;
    }

    if (bsocket_url_ip(i_WELL_KNOW_URL, NULL) == 0)
        return ekSNONET;
    else
        return ekSNOHOST;
}

/*---------------------------------------------------------------------------*/

/*
static void i_options(Socket *sock, const SockOpt *opts)
{
   cassert_no_null(sock);
   cassert_no_null(opts);
   if (opts->timeout_ms > 0)
   {
       #if defined(__WINDOWS__)
       DWORD timeout = (DWORD)opts->timeout_ms;
       #else
       struct timeval timeout;
       timeout.tv_sec = opts->timeout_ms / 1000;
       timeout.tv_usec = (opts->timeout_ms % 1000) * 1000;
       #endif

       {
           int sok = setsockopt((SOCKET_ID)(intptr_t)sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)(&timeout), sizeof(timeout));
           cassert_unref(sok == 0, sok);
       }

       {
           int sok = setsockopt((SOCKET_ID)(intptr_t)sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)(&timeout), sizeof(timeout));
           cassert_unref(sok == 0, sok);
       }
   }
}
 */

/*---------------------------------------------------------------------------*/

Socket *bsocket_connect(const uint32_t ip, const uint16_t port, const uint32_t timeout_ms, serror_t *error)
{
    SOCKET_ID skID = SOCKET_NULL;
    int ok_connect = 0;

    /* Create the socket */
    skID = socket(PF_INET, SOCK_STREAM, 0);
    if (skID == SOCKET_FAIL)
    {
        if (error != NULL)
            *error = i_socket_error();
        return NULL;
    }

    /* Connect to the server */
    if (skID != SOCKET_FAIL)
    {
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = htonl(ip);

        if (timeout_ms == 0)
        {
            ok_connect = connect(skID, (struct sockaddr *)&server, sizeof(server));
            if (ok_connect == SOCKET_FAIL && error != NULL)
                *error = i_socket_error();
        }
        else
        {
            /* Set non-blocking */
            long arg = fcntl(skID, F_GETFL, NULL);
            if (arg < 0)
            {
                ok_connect = SOCKET_FAIL;
                if (error != NULL)
                    *error = ekSUNDEF;
            }

            if (ok_connect != SOCKET_FAIL)
            {
                arg |= O_NONBLOCK;
                if (fcntl(skID, F_SETFL, arg) < 0)
                {
                    ok_connect = SOCKET_FAIL;
                    if (error != NULL)
                        *error = ekSUNDEF;
                }
            }

            if (ok_connect != SOCKET_FAIL)
            {
                if (connect(skID, (struct sockaddr *)&server, sizeof(server)) == SOCKET_FAIL)
                {
                    if (errno == EINPROGRESS)
                    {
                        /* connection pending */
                        fd_set setW;
                        struct timeval time_out = {0, 0};
                        int ret = 0;

                        FD_ZERO(&setW);
                        FD_SET(skID, &setW);
                        /* FD_ZERO(&setE);
                        FD_SET(skID, &setE); */
                        time_out.tv_sec = timeout_ms / 1000;
                        time_out.tv_usec = (timeout_ms % 1000) * 1000;

                        ret = select(skID + 1, NULL, &setW, NULL, &time_out);
                        if (ret > 0)
                        {
                            if (FD_ISSET(skID, &setW))
                            {
                                /* connection failed */
                                int err = 0;
                                socklen_t errlen = sizeof(err);
                                getsockopt(skID, SOL_SOCKET, SO_ERROR, (void *)&err, &errlen);
                                if (err != 0)
                                {
                                    errno = err;
                                    ok_connect = SOCKET_FAIL;
                                    if (error != NULL)
                                        *error = i_socket_error();
                                }
                            }
                        }
                        else
                        {
                            ok_connect = SOCKET_FAIL;
                            if (ret == 0)
                            {
                                errno = ETIMEDOUT;
                                if (error != NULL)
                                    *error = i_socket_error();
                            }
                        }
                    }
                    else
                    {
                        ok_connect = SOCKET_FAIL;
                    }
                }
            }
        }
    }

    if (ok_connect != SOCKET_FAIL && timeout_ms > 0)
    {
        /* Set to blocking mode again... */
        long arg = fcntl(skID, F_GETFL, NULL);
        if (arg < 0)
        {
            ok_connect = SOCKET_FAIL;
            if (error != NULL)
                *error = ekSUNDEF;
        }

        if (ok_connect != SOCKET_FAIL)
        {
            arg &= (~O_NONBLOCK);
            if (fcntl(skID, F_SETFL, arg) < 0)
            {
                ok_connect = SOCKET_FAIL;
                if (error != NULL)
                    *error = ekSUNDEF;
            }
        }
    }

    if (ok_connect != SOCKET_FAIL)
    {
        ptr_assign(error, ekSOK);
        _osbs_socket_alloc();
        return (Socket *)(intptr_t)skID;
    }
    else
    {
        if (skID != SOCKET_FAIL)
            close(skID);

        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

Socket *bsocket_server(const uint16_t port, const uint32_t max_connect, serror_t *error)
{
    struct sockaddr_in server;
    SOCKET_ID skID;
    int ok;

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    /* Create the socket */
    skID = socket(PF_INET, SOCK_STREAM, 0);
    if (skID == -1)
    {
        if (error != NULL)
            *error = i_socket_error();
        return NULL;
    }

    /* We are going to attend the service */
    {
        int reuseaddr = 1;
        int sok = SOCKET_FAIL;
        sok = setsockopt(skID, SOL_SOCKET, SO_REUSEADDR, (const char *)(&reuseaddr), sizeof(reuseaddr));
        cassert_unref(sok == 0, sok);
    }

    ok = bind(skID, (struct sockaddr *)&server, sizeof(server));
    if (ok == SOCKET_FAIL)
    {
        close(skID);

        if (error != NULL)
            *error = i_socket_error();
        return NULL;
    }

    /* The server will be listening for clients */
    ok = listen(skID, (int)max_connect);
    if (ok == SOCKET_FAIL)
    {
        close(skID);

        if (error != NULL)
            i_socket_error();

        return NULL;
    }

    /* All Ok! */
    _osbs_socket_alloc();
    return (Socket *)(intptr_t)skID;
}

/*---------------------------------------------------------------------------*/

Socket *bsocket_accept(Socket *lsocket, const uint32_t timeout_ms, serror_t *error)
{
    SOCKET_ID lsockid = 0;
    fd_set set;
    int select_id;
    SOCKET_ID cliID;
    struct sockaddr_in clData;
    socklen_t sizeSt;
    cassert_no_null(lsocket);

    lsockid = (SOCKET_ID)(intptr_t)lsocket;
    FD_ZERO(&set);
    FD_SET(lsockid, &set);

    if (timeout_ms > 0)
    {
        struct timeval timeout;
        timeout.tv_sec = timeout_ms / 1000;
        timeout.tv_usec = (timeout_ms % 1000) * 1000;
        select_id = select((int)lsockid + 1, &set, NULL, NULL, &timeout);
    }
    else
    {
        select_id = select((int)lsockid + 1, &set, NULL, NULL, NULL);
    }

    if (select_id == SOCKET_FAIL)
    {
        ptr_assign(error, ekSUNDEF);
        return NULL;
    }

    if (select_id == 0)
    {
        ptr_assign(error, ekSTIMEOUT);
        return NULL;
    }

    sizeSt = sizeof(clData);
    cliID = accept((SOCKET_ID)(intptr_t)lsocket, (struct sockaddr *)&clData, &sizeSt);
    if (cliID == SOCKET_FAIL)
    {
        if (error != NULL)
            i_socket_error();
        return NULL;
    }

    /* All Ok! */
    _osbs_socket_alloc();
    ptr_assign(error, ekSOK);
    return (Socket *)(intptr_t)cliID;
}

/*---------------------------------------------------------------------------*/

void bsocket_close(Socket **lsocket)
{
    int ok;
    cassert_no_null(lsocket);
    cassert_no_null(*lsocket);
    shutdown((SOCKET_ID)(intptr_t)(*lsocket), ALL_SHUTDOWN);
    ok = close((SOCKET_ID)(intptr_t)(*lsocket));
    cassert_unref(ok == 0, ok);
    _osbs_socket_dealloc();
    *lsocket = NULL;
}

/*---------------------------------------------------------------------------*/

void bsocket_local_ip(Socket *lsocket, uint32_t *ip, uint16_t *port)
{
    struct sockaddr_in laddress;
    socklen_t addr_size = sizeof(laddress);
    cassert_no_null(lsocket);
    cassert(ip != NULL || port != NULL);
    if (getsockname((SOCKET_ID)(intptr_t)lsocket, (struct sockaddr *)&laddress, &addr_size) != -1)
    {
        ptr_assign(ip, ntohl(laddress.sin_addr.s_addr));
        ptr_assign(port, ntohs(laddress.sin_port));
    }
    else
    {
        ptr_assign(ip, 0);
        ptr_assign(port, 0);
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_remote_ip(Socket *lsocket, uint32_t *ip, uint16_t *port)
{
    struct sockaddr_in laddress;
    socklen_t addr_size = sizeof(laddress);
    cassert_no_null(lsocket);
    cassert(ip != NULL || port != NULL);
    if (getpeername((SOCKET_ID)(intptr_t)lsocket, (struct sockaddr *)&laddress, &addr_size) != -1)
    {
        ptr_assign(ip, ntohl(laddress.sin_addr.s_addr));
        ptr_assign(port, ntohs(laddress.sin_port));
    }
    else
    {
        ptr_assign(ip, 0);
        ptr_assign(port, 0);
    }
}

/*---------------------------------------------------------------------------*/

void bsocket_read_timeout(Socket *sock, const uint32_t timeout_ms)
{
    struct timeval timeout;
    int ret = 0;
    timeout.tv_sec = timeout_ms / 1000;
    timeout.tv_usec = (timeout_ms % 1000) * 1000;
    ret = setsockopt((SOCKET_ID)(intptr_t)sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)(&timeout), sizeof(timeout));
    cassert_unref(ret == 0, ret);
}

/*---------------------------------------------------------------------------*/

void bsocket_write_timeout(Socket *sock, const uint32_t timeout_ms)
{
    struct timeval timeout;
    int ret = 0;
    timeout.tv_sec = timeout_ms / 1000;
    timeout.tv_usec = (timeout_ms % 1000) * 1000;
    ret = setsockopt((SOCKET_ID)(intptr_t)sock, SOL_SOCKET, SO_SNDTIMEO, (const char *)(&timeout), sizeof(timeout));
    cassert_unref(ret == 0, ret);
}

/*---------------------------------------------------------------------------*/

bool_t bsocket_read(Socket *lsocket, byte_t *data, const uint32_t size, uint32_t *rsize, serror_t *error)
{
    SSIZE_T lrsize = 0;
    serror_t lerror = ekSOK;

    cassert_no_null(lsocket);
    cassert_no_null(data);

    for (;;)
    {
        SSIZE_T num_rbytes = 0;
        cassert((int)size > lrsize);
        num_rbytes = recv((SOCKET_ID)(intptr_t)lsocket, (char *)data, (SIZE_T)((long)size - (long)lrsize), 0);
        if (num_rbytes > 0)
        {
            lrsize += num_rbytes;
            if ((uint32_t)lrsize == size)
            {
                lerror = ekSOK;
                break;
            }

            data += num_rbytes;
        }
        else if (num_rbytes == 0)
        {
            lerror = ekSOK;
            break;
        }
        else if (num_rbytes == SOCKET_FAIL)
        {
            int sock_error = errno;
            if (sock_error == ETIMEDOUT)
                lerror = ekSTIMEOUT;
            else
                lerror = ekSSTREAM;

            break;
        }
        else
        {
            lerror = ekSSTREAM;
            break;
        }
    }

    ptr_assign(rsize, (uint32_t)lrsize);
    ptr_assign(error, lerror);
    return (bool_t)(lerror == ekSOK);
}

/*---------------------------------------------------------------------------*/

bool_t bsocket_write(Socket *lsocket, const byte_t *data, const uint32_t size, uint32_t *wsize, serror_t *error)
{
    SSIZE_T lwsize = 0;
    bool_t ok = FALSE;
    cassert_no_null(lsocket);
    cassert_no_null(data);

    for (;;)
    {
        SSIZE_T num_wbytes = 0;
        cassert((int)size > lwsize);
        num_wbytes = send((SOCKET_ID)(intptr_t)lsocket, (const char *)(data), (SIZE_T)((long)size - (long)lwsize), 0);
        if (num_wbytes > 0)
        {
            lwsize += num_wbytes;
            if (lwsize == (int)size)
            {
                ok = TRUE;
                break;
            }

            data += num_wbytes;
        }
        else if (num_wbytes == 0)
        {
            cassert(FALSE);
            ok = TRUE;
            break;
        }
        else if (num_wbytes == SOCKET_FAIL)
        {
            ok = FALSE;
            break;
        }
        else
        {
            cassert(FALSE);
            ok = FALSE;
            break;
        }
    }

    ptr_assign(wsize, (uint32_t)lwsize);
    ptr_assign(error, ok == TRUE ? ekSOK : ekSSTREAM);
    return ok;
}

/*---------------------------------------------------------------------------*/

uint32_t bsocket_url_ip(const char_t *url, serror_t *error)
{
    struct hostent *host = NULL;

    cassert_no_null(url);

#if defined(__WINDOWS__)
#pragma warning(disable : 4996)
    host = gethostbyname((const char *)url);
#pragma warning(default : 4996)
#else
    host = gethostbyname((const char *)url);
#endif

    if (host != NULL)
    {
        /* Cast the h_addr_list to in_addr, since h_addr_list also has the ip address in long format only. */
        struct in_addr **addr_list = (struct in_addr **)host->h_addr_list;
        if (addr_list[0] != NULL)
        {
            /* Only for debug (see ip in text) */
            /* const char *ip_str = inet_ntoa(*addr_list[0]); */
            ptr_assign(error, ekSOK);
            return ntohl(addr_list[0]->s_addr);
        }
    }

    if (error != NULL)
    {
        if (bsocket_url_ip(i_WELL_KNOW_URL, NULL) == 0)
            *error = ekSNONET;
        else
            *error = ekSNOHOST;
    }

    return 0;
}
