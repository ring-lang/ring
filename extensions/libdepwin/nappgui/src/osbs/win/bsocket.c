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

#include "osbs.inl"
#include "bsocket.h"
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <winsock2.h>
#include <mstcpip.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include <sewer/warn.hxx>

/*---------------------------------------------------------------------------*/

static const char_t *i_WELL_KNOW_URL = "www.google.com";

/*---------------------------------------------------------------------------*/

void _osbs_start_sockets(void)
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    cassert_unref(result == 0, result);
}

/*---------------------------------------------------------------------------*/

void _osbs_finish_sockets(void)
{
    int result = WSACleanup();
    cassert_unref(result == 0, result);
}

/*---------------------------------------------------------------------------*/

static serror_t i_socket_error(void)
{
    int sock_error = WSAGetLastError();

    switch (sock_error)
    {
    case WSAETIMEDOUT:
        return ekSTIMEOUT;
    }

    if (bsocket_url_ip(i_WELL_KNOW_URL, NULL) == 0)
        return ekSNONET;
    else
        return ekSNOHOST;
}

/*---------------------------------------------------------------------------*/

Socket *bsocket_connect(const uint32_t ip, const uint16_t port, const uint32_t timeout_ms, serror_t *error)
{
    SOCKET skID = INVALID_SOCKET;
    int ok_connect = SOCKET_ERROR;

    /* Create the socket */
    skID = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (skID == INVALID_SOCKET)
    {
        if (error != NULL)
            *error = i_socket_error();
        return NULL;
    }

    /* Connect to the server */
    if (skID != SOCKET_ERROR)
    {
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = htonl(ip);

        if (timeout_ms == 0)
        {
            ok_connect = connect(skID, (struct sockaddr *)&server, sizeof(server));
            if (ok_connect == SOCKET_ERROR && error != NULL)
                *error = i_socket_error();
        }
        else
        {
            /* put socked in non-blocking mode... */
            u_long block = 1;
            ok_connect = ioctlsocket(skID, FIONBIO, &block);
            if (ok_connect != SOCKET_ERROR)
            {
                if (connect(skID, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
                {
                    if (WSAGetLastError() == WSAEWOULDBLOCK)
                    {
                        /* connection pending */
                        fd_set setW, setE;
                        struct timeval time_out = {0};
                        int ret = 0;

#include <sewer/nowarn.hxx>
                        FD_ZERO(&setW);
                        FD_SET(skID, &setW);
                        FD_ZERO(&setE);
                        FD_SET(skID, &setE);
#include <sewer/warn.hxx>

                        time_out.tv_sec = timeout_ms / 1000;
                        time_out.tv_usec = (timeout_ms % 1000) * 1000;

                        ret = select(0, NULL, &setW, &setE, &time_out);
                        if (ret > 0)
                        {
                            if (FD_ISSET(skID, &setE))
                            {
                                /* connection failed */
                                int err = 0;
                                int errlen = sizeof(err);
                                getsockopt(skID, SOL_SOCKET, SO_ERROR, (char *)&err, &errlen);
                                WSASetLastError(err);
                                ok_connect = SOCKET_ERROR;
                                if (error != NULL)
                                    *error = i_socket_error();
                            }
                        }
                        else
                        {
                            ok_connect = SOCKET_ERROR;
                            if (ret == 0)
                            {
                                WSASetLastError(WSAETIMEDOUT);
                                if (error != NULL)
                                    *error = i_socket_error();
                            }
                        }
                    }
                    else
                    {
                        ok_connect = SOCKET_ERROR;
                    }
                }
            }
        }
    }

    if (ok_connect != SOCKET_ERROR && timeout_ms > 0)
    {
        /* put socked in blocking mode... */
        u_long block = 0;
        if (ioctlsocket(skID, FIONBIO, &block) == SOCKET_ERROR)
        {
            ok_connect = SOCKET_ERROR;
            if (error != NULL)
                *error = i_socket_error();
        }
    }

    if (ok_connect != SOCKET_ERROR)
    {
        ptr_assign(error, ekSOK);
        _osbs_socket_alloc();
        return (Socket *)(intptr_t)skID;
    }
    else
    {
        if (skID != SOCKET_ERROR)
            closesocket(skID);

        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

Socket *bsocket_server(const uint16_t port, const uint32_t max_connect, serror_t *error)
{
    struct sockaddr_in server;
    SOCKET skID;
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
        int sok = SOCKET_ERROR;
        sok = setsockopt(skID, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuseaddr, sizeof(reuseaddr));
        cassert(sok == 0);
    }

    ok = bind(skID, (struct sockaddr *)&server, sizeof(server));
    if (ok == SOCKET_ERROR)
    {
        closesocket(skID);

        if (error != NULL)
            *error = i_socket_error();
        return NULL;
    }

    /* The server will be listening for clients */
    ok = listen(skID, (int)max_connect);
    if (ok == SOCKET_ERROR)
    {
        closesocket(skID);

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
    SOCKET lsockid = 0;
    fd_set set;
    int select_id;
    SOCKET cliID;
    struct sockaddr_in clData;
    socklen_t sizeSt;
    cassert_no_null(lsocket);

    lsockid = (SOCKET)lsocket;
#pragma warning(disable : 4548)
#pragma warning(disable : 4127)
    FD_ZERO(&set);
    FD_SET(lsockid, &set);
#pragma warning(default : 4548)
#pragma warning(default : 4127)

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

    if (select_id == SOCKET_ERROR)
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
    cliID = accept((SOCKET)(intptr_t)lsocket, (struct sockaddr *)&clData, &sizeSt);
    if (cliID == SOCKET_ERROR)
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
    shutdown((SOCKET)(intptr_t)(*lsocket), SD_BOTH);
    ok = closesocket((SOCKET)(*lsocket));
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
    if (getsockname((SOCKET)(intptr_t)lsocket, (struct sockaddr *)&laddress, &addr_size) != -1)
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
    if (getpeername((SOCKET)(intptr_t)lsocket, (struct sockaddr *)&laddress, &addr_size) != -1)
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

void bsocket_read_timeout(Socket *socket, const uint32_t timeout_ms)
{
    int sok = SOCKET_ERROR;
    DWORD timeout = (DWORD)timeout_ms;
    cassert_no_null(socket);
    sok = setsockopt((SOCKET)(intptr_t)socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));
    cassert_unref(sok == 0, sok);
}

/*---------------------------------------------------------------------------*/

void bsocket_write_timeout(Socket *socket, const uint32_t timeout_ms)
{
    int sok = SOCKET_ERROR;
    DWORD timeout = (DWORD)timeout_ms;
    cassert_no_null(socket);
    sok = setsockopt((SOCKET)(intptr_t)socket, SOL_SOCKET, SO_SNDTIMEO, (const char *)&timeout, sizeof(timeout));
    cassert_unref(sok == 0, sok);
}

/*---------------------------------------------------------------------------*/

//uint32_t bsocket_get_timeout(Socket *socket);
//uint32_t bsocket_get_timeout(Socket *lsocket)
//{
//    #if defined(__WINDOWS__)
//    DWORD timeout = 0;
//    int len = sizeof(DWORD);
//    #else
//    struct timeval timeout;
//    socklen_t len = sizeof(struct timeval);
//    #endif
//
//    int ok = SOCKET_FAIL;
//    cassert_no_null(lsocket);
//    ok = getsockopt((SOCKET_ID)(intptr_t)lsocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, &len);
//    cassert(ok == 0);
//
//    #if defined(__WINDOWS__)
//    return (uint32_t)timeout;
//    #else
//    return (uint32_t)((timeout.tv_sec * 1000) + (timeout.tv_usec / 1000));
//    #endif
//}

/*---------------------------------------------------------------------------*/

bool_t bsocket_read(Socket *lsocket, byte_t *data, const uint32_t size, uint32_t *rsize, serror_t *error)
{
    SSIZE_T lrsize = 0;
    serror_t lerror = ekSOK;

    cassert_no_null(lsocket);
    cassert_no_null(data);

    for (;;)
    {
        int num_rbytes = 0;
        cassert((int)size > lrsize);
        num_rbytes = recv((SOCKET)(intptr_t)lsocket, (char *)data, (int)(size - lrsize), 0);
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
        else if (num_rbytes == SOCKET_ERROR)
        {
            int sock_error = WSAGetLastError();
            if (sock_error == WSAETIMEDOUT)
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
        cassert((SSIZE_T)size > lwsize);
        num_wbytes = send((SOCKET)(intptr_t)lsocket, (const char *)data, (int)(size - lwsize), 0);
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
        else if (num_wbytes == SOCKET_ERROR)
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

//bool_t bsocket_shutdown(Socket *socket, serror_t *error);
//bool_t bsocket_shutdown(Socket *lsocket, serror_t *error)
//{
//    int result = 0;
//    cassert_no_null(lsocket);
//    result = shutdown((SOCKET_ID)(intptr_t)lsocket, RECV_SHUTDOWN);
//    if (result == 0)
//    {
//        ptr_assign(error, ekSOK);
//        return TRUE;
//    }
//    else
//    {
//        if (error != NULL)
//            *error = i_socket_error();
//        return FALSE;
//    }
//}

/*---------------------------------------------------------------------------*/

uint32_t bsocket_url_ip(const char_t *url, serror_t *error)
{
    struct hostent *host = NULL;

    cassert_no_null(url);

#include <sewer/nowarn.hxx>
    host = gethostbyname((const char *)url);
#include <sewer/warn.hxx>

    if (host != NULL)
    {
        /* Cast the h_addr_list to in_addr, since h_addr_list also has the ip address in long format only. */
        struct in_addr **addr_list = (struct in_addr **)host->h_addr_list;
        if (addr_list[0] != NULL)
        {
            /* Only for debug (see ip in text) */
            // const char *ip_str = inet_ntoa(*addr_list[0]);
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

/*---------------------------------------------------------------------------*/

const char_t *bsocket_host_name(char_t *buffer, const uint32_t size)
{
    if (gethostname((char *)buffer, (int)size) == 0)
        return buffer;
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

const char_t *bsocket_host_name_ip(const uint32_t ip, char_t *buffer, const uint32_t size)
{
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(ip);

#include <sewer/nowarn.hxx>
    if (getnameinfo((struct sockaddr *)&sa, sizeof(sa), buffer, size, NULL, 0, 0) == 0)
        return buffer;
#include <sewer/warn.hxx>

    return NULL;
}
