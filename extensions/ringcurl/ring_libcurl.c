#include "ring.h"

/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com>
*/

#include <curl/curl.h>

typedef struct curl_slist CURLLIST ;
RING_FUNC(ring_new_curllist)
{
	CURLLIST *pMyPointer ;
	pMyPointer = (CURLLIST *) RING_API_MALLOC(sizeof(CURLLIST)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"CURLLIST");
}

RING_FUNC(ring_new_managed_curllist)
{
	CURLLIST *pMyPointer ;
	pMyPointer = (CURLLIST *) RING_API_MALLOC(sizeof(CURLLIST)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"CURLLIST",RING_API_FREEFUNC);
}

RING_FUNC(ring_destroy_curllist)
{
	CURLLIST *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (CURLLIST*) RING_API_GETCPOINTER(1,"CURLLIST");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_curl_global_all)
{
	RING_API_RETNUMBER(CURL_GLOBAL_ALL);
}

RING_FUNC(ring_get_curl_global_ssl)
{
	RING_API_RETNUMBER(CURL_GLOBAL_SSL);
}

RING_FUNC(ring_get_curl_global_win32)
{
	RING_API_RETNUMBER(CURL_GLOBAL_WIN32);
}

RING_FUNC(ring_get_curl_global_nothing)
{
	RING_API_RETNUMBER(CURL_GLOBAL_NOTHING);
}

RING_FUNC(ring_get_curl_global_default)
{
	RING_API_RETNUMBER(CURL_GLOBAL_DEFAULT);
}

RING_FUNC(ring_get_curl_global_ack_eintr)
{
	RING_API_RETNUMBER(CURL_GLOBAL_ACK_EINTR);
}

RING_FUNC(ring_get_curlopt_verbose)
{
	RING_API_RETNUMBER(CURLOPT_VERBOSE);
}

RING_FUNC(ring_get_curlopt_header)
{
	RING_API_RETNUMBER(CURLOPT_HEADER);
}

RING_FUNC(ring_get_curlopt_noprogress)
{
	RING_API_RETNUMBER(CURLOPT_NOPROGRESS);
}

RING_FUNC(ring_get_curlopt_nosignal)
{
	RING_API_RETNUMBER(CURLOPT_NOSIGNAL);
}

RING_FUNC(ring_get_curlopt_wildcardmatch)
{
	RING_API_RETNUMBER(CURLOPT_WILDCARDMATCH);
}

RING_FUNC(ring_get_curlopt_writefunction)
{
	RING_API_RETNUMBER(CURLOPT_WRITEFUNCTION);
}

RING_FUNC(ring_get_curlopt_writedata)
{
	RING_API_RETNUMBER(CURLOPT_WRITEDATA);
}

RING_FUNC(ring_get_curlopt_readfunction)
{
	RING_API_RETNUMBER(CURLOPT_READFUNCTION);
}

RING_FUNC(ring_get_curlopt_readdata)
{
	RING_API_RETNUMBER(CURLOPT_READDATA);
}

RING_FUNC(ring_get_curlopt_ioctlfunction)
{
	RING_API_RETNUMBER(CURLOPT_IOCTLFUNCTION);
}

RING_FUNC(ring_get_curlopt_ioctldata)
{
	RING_API_RETNUMBER(CURLOPT_IOCTLDATA);
}

RING_FUNC(ring_get_curlopt_seekfunction)
{
	RING_API_RETNUMBER(CURLOPT_SEEKFUNCTION);
}

RING_FUNC(ring_get_curlopt_seekdata)
{
	RING_API_RETNUMBER(CURLOPT_SEEKDATA);
}

RING_FUNC(ring_get_curlopt_sockoptfunction)
{
	RING_API_RETNUMBER(CURLOPT_SOCKOPTFUNCTION);
}

RING_FUNC(ring_get_curlopt_sockoptdata)
{
	RING_API_RETNUMBER(CURLOPT_SOCKOPTDATA);
}

RING_FUNC(ring_get_curlopt_opensocketfunction)
{
	RING_API_RETNUMBER(CURLOPT_OPENSOCKETFUNCTION);
}

RING_FUNC(ring_get_curlopt_opensocketdata)
{
	RING_API_RETNUMBER(CURLOPT_OPENSOCKETDATA);
}

RING_FUNC(ring_get_curlopt_closesocketfunction)
{
	RING_API_RETNUMBER(CURLOPT_CLOSESOCKETFUNCTION);
}

RING_FUNC(ring_get_curlopt_closesocketdata)
{
	RING_API_RETNUMBER(CURLOPT_CLOSESOCKETDATA);
}

RING_FUNC(ring_get_curlopt_progressfunction)
{
	RING_API_RETNUMBER(CURLOPT_PROGRESSFUNCTION);
}

RING_FUNC(ring_get_curlopt_progressdata)
{
	RING_API_RETNUMBER(CURLOPT_PROGRESSDATA);
}

RING_FUNC(ring_get_curlopt_headerfunction)
{
	RING_API_RETNUMBER(CURLOPT_HEADERFUNCTION);
}

RING_FUNC(ring_get_curlopt_headerdata)
{
	RING_API_RETNUMBER(CURLOPT_HEADERDATA);
}

RING_FUNC(ring_get_curlopt_debugfunction)
{
	RING_API_RETNUMBER(CURLOPT_DEBUGFUNCTION);
}

RING_FUNC(ring_get_curlopt_debugdata)
{
	RING_API_RETNUMBER(CURLOPT_DEBUGDATA);
}

RING_FUNC(ring_get_curlopt_ssl_ctx_function)
{
	RING_API_RETNUMBER(CURLOPT_SSL_CTX_FUNCTION);
}

RING_FUNC(ring_get_curlopt_ssl_ctx_data)
{
	RING_API_RETNUMBER(CURLOPT_SSL_CTX_DATA);
}

RING_FUNC(ring_get_curlopt_conv_to_network_function)
{
	RING_API_RETNUMBER(CURLOPT_CONV_TO_NETWORK_FUNCTION);
}

RING_FUNC(ring_get_curlopt_conv_from_network_function)
{
	RING_API_RETNUMBER(CURLOPT_CONV_FROM_NETWORK_FUNCTION);
}

RING_FUNC(ring_get_curlopt_conv_from_utf8_function)
{
	RING_API_RETNUMBER(CURLOPT_CONV_FROM_UTF8_FUNCTION);
}

RING_FUNC(ring_get_curlopt_interleavefunction)
{
	RING_API_RETNUMBER(CURLOPT_INTERLEAVEFUNCTION);
}

RING_FUNC(ring_get_curlopt_interleavedata)
{
	RING_API_RETNUMBER(CURLOPT_INTERLEAVEDATA);
}

RING_FUNC(ring_get_curlopt_chunk_bgn_function)
{
	RING_API_RETNUMBER(CURLOPT_CHUNK_BGN_FUNCTION);
}

RING_FUNC(ring_get_curlopt_chunk_end_function)
{
	RING_API_RETNUMBER(CURLOPT_CHUNK_END_FUNCTION);
}

RING_FUNC(ring_get_curlopt_chunk_data)
{
	RING_API_RETNUMBER(CURLOPT_CHUNK_DATA);
}

RING_FUNC(ring_get_curlopt_fnmatch_function)
{
	RING_API_RETNUMBER(CURLOPT_FNMATCH_FUNCTION);
}

RING_FUNC(ring_get_curlopt_fnmatch_data)
{
	RING_API_RETNUMBER(CURLOPT_FNMATCH_DATA);
}

RING_FUNC(ring_get_curlopt_errorbuffer)
{
	RING_API_RETNUMBER(CURLOPT_ERRORBUFFER);
}

RING_FUNC(ring_get_curlopt_stderr)
{
	RING_API_RETNUMBER(CURLOPT_STDERR);
}

RING_FUNC(ring_get_curlopt_failonerror)
{
	RING_API_RETNUMBER(CURLOPT_FAILONERROR);
}

RING_FUNC(ring_get_curlopt_url)
{
	RING_API_RETNUMBER(CURLOPT_URL);
}

RING_FUNC(ring_get_curlopt_protocols)
{
	RING_API_RETNUMBER(CURLOPT_PROTOCOLS);
}

RING_FUNC(ring_get_curlopt_redir_protocols)
{
	RING_API_RETNUMBER(CURLOPT_REDIR_PROTOCOLS);
}

RING_FUNC(ring_get_curlopt_proxy)
{
	RING_API_RETNUMBER(CURLOPT_PROXY);
}

RING_FUNC(ring_get_curlopt_proxyport)
{
	RING_API_RETNUMBER(CURLOPT_PROXYPORT);
}

RING_FUNC(ring_get_curlopt_proxytype)
{
	RING_API_RETNUMBER(CURLOPT_PROXYTYPE);
}

RING_FUNC(ring_get_curlopt_noproxy)
{
	RING_API_RETNUMBER(CURLOPT_NOPROXY);
}

RING_FUNC(ring_get_curlopt_httpproxytunnel)
{
	RING_API_RETNUMBER(CURLOPT_HTTPPROXYTUNNEL);
}

RING_FUNC(ring_get_curlopt_socks5_gssapi_service)
{
	RING_API_RETNUMBER(CURLOPT_SOCKS5_GSSAPI_SERVICE);
}

RING_FUNC(ring_get_curlopt_socks5_gssapi_nec)
{
	RING_API_RETNUMBER(CURLOPT_SOCKS5_GSSAPI_NEC);
}

RING_FUNC(ring_get_curlopt_interface)
{
	RING_API_RETNUMBER(CURLOPT_INTERFACE);
}

RING_FUNC(ring_get_curlopt_localport)
{
	RING_API_RETNUMBER(CURLOPT_LOCALPORT);
}

RING_FUNC(ring_get_curlopt_localportrange)
{
	RING_API_RETNUMBER(CURLOPT_LOCALPORTRANGE);
}

RING_FUNC(ring_get_curlopt_dns_cache_timeout)
{
	RING_API_RETNUMBER(CURLOPT_DNS_CACHE_TIMEOUT);
}

RING_FUNC(ring_get_curlopt_dns_use_global_cache)
{
	RING_API_RETNUMBER(CURLOPT_DNS_USE_GLOBAL_CACHE);
}

RING_FUNC(ring_get_curlopt_buffersize)
{
	RING_API_RETNUMBER(CURLOPT_BUFFERSIZE);
}

RING_FUNC(ring_get_curlopt_port)
{
	RING_API_RETNUMBER(CURLOPT_PORT);
}

RING_FUNC(ring_get_curlopt_tcp_nodelay)
{
	RING_API_RETNUMBER(CURLOPT_TCP_NODELAY);
}

RING_FUNC(ring_get_curlopt_address_scope)
{
	RING_API_RETNUMBER(CURLOPT_ADDRESS_SCOPE);
}

RING_FUNC(ring_get_curlopt_netrc)
{
	RING_API_RETNUMBER(CURLOPT_NETRC);
}

RING_FUNC(ring_get_curlopt_netrc_file)
{
	RING_API_RETNUMBER(CURLOPT_NETRC_FILE);
}

RING_FUNC(ring_get_curlopt_userpwd)
{
	RING_API_RETNUMBER(CURLOPT_USERPWD);
}

RING_FUNC(ring_get_curlopt_proxyuserpwd)
{
	RING_API_RETNUMBER(CURLOPT_PROXYUSERPWD);
}

RING_FUNC(ring_get_curlopt_username)
{
	RING_API_RETNUMBER(CURLOPT_USERNAME);
}

RING_FUNC(ring_get_curlopt_password)
{
	RING_API_RETNUMBER(CURLOPT_PASSWORD);
}

RING_FUNC(ring_get_curlopt_proxyusername)
{
	RING_API_RETNUMBER(CURLOPT_PROXYUSERNAME);
}

RING_FUNC(ring_get_curlopt_proxypassword)
{
	RING_API_RETNUMBER(CURLOPT_PROXYPASSWORD);
}

RING_FUNC(ring_get_curlopt_httpauth)
{
	RING_API_RETNUMBER(CURLOPT_HTTPAUTH);
}

RING_FUNC(ring_get_curlopt_tlsauth_username)
{
	RING_API_RETNUMBER(CURLOPT_TLSAUTH_USERNAME);
}

RING_FUNC(ring_get_curlopt_tlsauth_password)
{
	RING_API_RETNUMBER(CURLOPT_TLSAUTH_PASSWORD);
}

RING_FUNC(ring_get_curlopt_tlsauth_type)
{
	RING_API_RETNUMBER(CURLOPT_TLSAUTH_TYPE);
}

RING_FUNC(ring_get_curlopt_proxyauth)
{
	RING_API_RETNUMBER(CURLOPT_PROXYAUTH);
}

RING_FUNC(ring_get_curlopt_autoreferer)
{
	RING_API_RETNUMBER(CURLOPT_AUTOREFERER);
}

RING_FUNC(ring_get_curlopt_accept_encoding)
{
	RING_API_RETNUMBER(CURLOPT_ACCEPT_ENCODING);
}

RING_FUNC(ring_get_curlopt_transfer_encoding)
{
	RING_API_RETNUMBER(CURLOPT_TRANSFER_ENCODING);
}

RING_FUNC(ring_get_curlopt_followlocation)
{
	RING_API_RETNUMBER(CURLOPT_FOLLOWLOCATION);
}

RING_FUNC(ring_get_curlopt_unrestricted_auth)
{
	RING_API_RETNUMBER(CURLOPT_UNRESTRICTED_AUTH);
}

RING_FUNC(ring_get_curlopt_maxredirs)
{
	RING_API_RETNUMBER(CURLOPT_MAXREDIRS);
}

RING_FUNC(ring_get_curlopt_postredir)
{
	RING_API_RETNUMBER(CURLOPT_POSTREDIR);
}

RING_FUNC(ring_get_curlopt_put)
{
	RING_API_RETNUMBER(CURLOPT_PUT);
}

RING_FUNC(ring_get_curlopt_post)
{
	RING_API_RETNUMBER(CURLOPT_POST);
}

RING_FUNC(ring_get_curlopt_postfields)
{
	RING_API_RETNUMBER(CURLOPT_POSTFIELDS);
}

RING_FUNC(ring_get_curlopt_postfieldsize)
{
	RING_API_RETNUMBER(CURLOPT_POSTFIELDSIZE);
}

RING_FUNC(ring_get_curlopt_postfieldsize_large)
{
	RING_API_RETNUMBER(CURLOPT_POSTFIELDSIZE_LARGE);
}

RING_FUNC(ring_get_curlopt_copypostfields)
{
	RING_API_RETNUMBER(CURLOPT_COPYPOSTFIELDS);
}

RING_FUNC(ring_get_curlopt_httppost)
{
	RING_API_RETNUMBER(CURLOPT_HTTPPOST);
}

RING_FUNC(ring_get_curlopt_referer)
{
	RING_API_RETNUMBER(CURLOPT_REFERER);
}

RING_FUNC(ring_get_curlopt_useragent)
{
	RING_API_RETNUMBER(CURLOPT_USERAGENT);
}

RING_FUNC(ring_get_curlopt_httpheader)
{
	RING_API_RETNUMBER(CURLOPT_HTTPHEADER);
}

RING_FUNC(ring_get_curlopt_http200aliases)
{
	RING_API_RETNUMBER(CURLOPT_HTTP200ALIASES);
}

RING_FUNC(ring_get_curlopt_cookie)
{
	RING_API_RETNUMBER(CURLOPT_COOKIE);
}

RING_FUNC(ring_get_curlopt_cookiefile)
{
	RING_API_RETNUMBER(CURLOPT_COOKIEFILE);
}

RING_FUNC(ring_get_curlopt_cookiejar)
{
	RING_API_RETNUMBER(CURLOPT_COOKIEJAR);
}

RING_FUNC(ring_get_curlopt_cookiesession)
{
	RING_API_RETNUMBER(CURLOPT_COOKIESESSION);
}

RING_FUNC(ring_get_curlopt_cookielist)
{
	RING_API_RETNUMBER(CURLOPT_COOKIELIST);
}

RING_FUNC(ring_get_curlopt_httpget)
{
	RING_API_RETNUMBER(CURLOPT_HTTPGET);
}

RING_FUNC(ring_get_curlopt_http_version)
{
	RING_API_RETNUMBER(CURLOPT_HTTP_VERSION);
}

RING_FUNC(ring_get_curlopt_ignore_content_length)
{
	RING_API_RETNUMBER(CURLOPT_IGNORE_CONTENT_LENGTH);
}

RING_FUNC(ring_get_curlopt_http_content_decoding)
{
	RING_API_RETNUMBER(CURLOPT_HTTP_CONTENT_DECODING);
}

RING_FUNC(ring_get_curlopt_http_transfer_decoding)
{
	RING_API_RETNUMBER(CURLOPT_HTTP_TRANSFER_DECODING);
}

RING_FUNC(ring_get_curlopt_mail_from)
{
	RING_API_RETNUMBER(CURLOPT_MAIL_FROM);
}

RING_FUNC(ring_get_curlopt_mail_rcpt)
{
	RING_API_RETNUMBER(CURLOPT_MAIL_RCPT);
}

RING_FUNC(ring_get_curlopt_tftp_blksize)
{
	RING_API_RETNUMBER(CURLOPT_TFTP_BLKSIZE);
}

RING_FUNC(ring_get_curlopt_ftpport)
{
	RING_API_RETNUMBER(CURLOPT_FTPPORT);
}

RING_FUNC(ring_get_curlopt_quote)
{
	RING_API_RETNUMBER(CURLOPT_QUOTE);
}

RING_FUNC(ring_get_curlopt_postquote)
{
	RING_API_RETNUMBER(CURLOPT_POSTQUOTE);
}

RING_FUNC(ring_get_curlopt_prequote)
{
	RING_API_RETNUMBER(CURLOPT_PREQUOTE);
}

RING_FUNC(ring_get_curlopt_append)
{
	RING_API_RETNUMBER(CURLOPT_APPEND);
}

RING_FUNC(ring_get_curlopt_ftp_use_eprt)
{
	RING_API_RETNUMBER(CURLOPT_FTP_USE_EPRT);
}

RING_FUNC(ring_get_curlopt_ftp_use_epsv)
{
	RING_API_RETNUMBER(CURLOPT_FTP_USE_EPSV);
}

RING_FUNC(ring_get_curlopt_ftp_use_pret)
{
	RING_API_RETNUMBER(CURLOPT_FTP_USE_PRET);
}

RING_FUNC(ring_get_curlopt_ftp_create_missing_dirs)
{
	RING_API_RETNUMBER(CURLOPT_FTP_CREATE_MISSING_DIRS);
}

RING_FUNC(ring_get_curlopt_ftp_response_timeout)
{
	RING_API_RETNUMBER(CURLOPT_FTP_RESPONSE_TIMEOUT);
}

RING_FUNC(ring_get_curlopt_ftp_alternative_to_user)
{
	RING_API_RETNUMBER(CURLOPT_FTP_ALTERNATIVE_TO_USER);
}

RING_FUNC(ring_get_curlopt_ftp_skip_pasv_ip)
{
	RING_API_RETNUMBER(CURLOPT_FTP_SKIP_PASV_IP);
}

RING_FUNC(ring_get_curlopt_ftpsslauth)
{
	RING_API_RETNUMBER(CURLOPT_FTPSSLAUTH);
}

RING_FUNC(ring_get_curlopt_ftp_ssl_ccc)
{
	RING_API_RETNUMBER(CURLOPT_FTP_SSL_CCC);
}

RING_FUNC(ring_get_curlopt_ftp_account)
{
	RING_API_RETNUMBER(CURLOPT_FTP_ACCOUNT);
}

RING_FUNC(ring_get_curlopt_ftp_filemethod)
{
	RING_API_RETNUMBER(CURLOPT_FTP_FILEMETHOD);
}

RING_FUNC(ring_get_curlopt_rtsp_request)
{
	RING_API_RETNUMBER(CURLOPT_RTSP_REQUEST);
}

RING_FUNC(ring_get_curlopt_rtsp_session_id)
{
	RING_API_RETNUMBER(CURLOPT_RTSP_SESSION_ID);
}

RING_FUNC(ring_get_curlopt_rtsp_stream_uri)
{
	RING_API_RETNUMBER(CURLOPT_RTSP_STREAM_URI);
}

RING_FUNC(ring_get_curlopt_rtsp_transport)
{
	RING_API_RETNUMBER(CURLOPT_RTSP_TRANSPORT);
}

RING_FUNC(ring_get_curlopt_rtsp_client_cseq)
{
	RING_API_RETNUMBER(CURLOPT_RTSP_CLIENT_CSEQ);
}

RING_FUNC(ring_get_curlopt_rtsp_server_cseq)
{
	RING_API_RETNUMBER(CURLOPT_RTSP_SERVER_CSEQ);
}

RING_FUNC(ring_get_curlopt_transfertext)
{
	RING_API_RETNUMBER(CURLOPT_TRANSFERTEXT);
}

RING_FUNC(ring_get_curlopt_proxy_transfer_mode)
{
	RING_API_RETNUMBER(CURLOPT_PROXY_TRANSFER_MODE);
}

RING_FUNC(ring_get_curlopt_crlf)
{
	RING_API_RETNUMBER(CURLOPT_CRLF);
}

RING_FUNC(ring_get_curlopt_range)
{
	RING_API_RETNUMBER(CURLOPT_RANGE);
}

RING_FUNC(ring_get_curlopt_resume_from)
{
	RING_API_RETNUMBER(CURLOPT_RESUME_FROM);
}

RING_FUNC(ring_get_curlopt_resume_from_large)
{
	RING_API_RETNUMBER(CURLOPT_RESUME_FROM_LARGE);
}

RING_FUNC(ring_get_curlopt_customrequest)
{
	RING_API_RETNUMBER(CURLOPT_CUSTOMREQUEST);
}

RING_FUNC(ring_get_curlopt_filetime)
{
	RING_API_RETNUMBER(CURLOPT_FILETIME);
}

RING_FUNC(ring_get_curlopt_dirlistonly)
{
	RING_API_RETNUMBER(CURLOPT_DIRLISTONLY);
}

RING_FUNC(ring_get_curlopt_nobody)
{
	RING_API_RETNUMBER(CURLOPT_NOBODY);
}

RING_FUNC(ring_get_curlopt_infilesize)
{
	RING_API_RETNUMBER(CURLOPT_INFILESIZE);
}

RING_FUNC(ring_get_curlopt_infilesize_large)
{
	RING_API_RETNUMBER(CURLOPT_INFILESIZE_LARGE);
}

RING_FUNC(ring_get_curlopt_upload)
{
	RING_API_RETNUMBER(CURLOPT_UPLOAD);
}

RING_FUNC(ring_get_curlopt_maxfilesize)
{
	RING_API_RETNUMBER(CURLOPT_MAXFILESIZE);
}

RING_FUNC(ring_get_curlopt_maxfilesize_large)
{
	RING_API_RETNUMBER(CURLOPT_MAXFILESIZE_LARGE);
}

RING_FUNC(ring_get_curlopt_timecondition)
{
	RING_API_RETNUMBER(CURLOPT_TIMECONDITION);
}

RING_FUNC(ring_get_curlopt_timevalue)
{
	RING_API_RETNUMBER(CURLOPT_TIMEVALUE);
}

RING_FUNC(ring_get_curlopt_timeout)
{
	RING_API_RETNUMBER(CURLOPT_TIMEOUT);
}

RING_FUNC(ring_get_curlopt_timeout_ms)
{
	RING_API_RETNUMBER(CURLOPT_TIMEOUT_MS);
}

RING_FUNC(ring_get_curlopt_low_speed_limit)
{
	RING_API_RETNUMBER(CURLOPT_LOW_SPEED_LIMIT);
}

RING_FUNC(ring_get_curlopt_low_speed_time)
{
	RING_API_RETNUMBER(CURLOPT_LOW_SPEED_TIME);
}

RING_FUNC(ring_get_curlopt_max_send_speed_large)
{
	RING_API_RETNUMBER(CURLOPT_MAX_SEND_SPEED_LARGE);
}

RING_FUNC(ring_get_curlopt_max_recv_speed_large)
{
	RING_API_RETNUMBER(CURLOPT_MAX_RECV_SPEED_LARGE);
}

RING_FUNC(ring_get_curlopt_maxconnects)
{
	RING_API_RETNUMBER(CURLOPT_MAXCONNECTS);
}

RING_FUNC(ring_get_curlopt_fresh_connect)
{
	RING_API_RETNUMBER(CURLOPT_FRESH_CONNECT);
}

RING_FUNC(ring_get_curlopt_forbid_reuse)
{
	RING_API_RETNUMBER(CURLOPT_FORBID_REUSE);
}

RING_FUNC(ring_get_curlopt_connecttimeout)
{
	RING_API_RETNUMBER(CURLOPT_CONNECTTIMEOUT);
}

RING_FUNC(ring_get_curlopt_connecttimeout_ms)
{
	RING_API_RETNUMBER(CURLOPT_CONNECTTIMEOUT_MS);
}

RING_FUNC(ring_get_curlopt_ipresolve)
{
	RING_API_RETNUMBER(CURLOPT_IPRESOLVE);
}

RING_FUNC(ring_get_curlopt_connect_only)
{
	RING_API_RETNUMBER(CURLOPT_CONNECT_ONLY);
}

RING_FUNC(ring_get_curlopt_use_ssl)
{
	RING_API_RETNUMBER(CURLOPT_USE_SSL);
}

RING_FUNC(ring_get_curlopt_resolve)
{
	RING_API_RETNUMBER(CURLOPT_RESOLVE);
}

RING_FUNC(ring_get_curlopt_sslcert)
{
	RING_API_RETNUMBER(CURLOPT_SSLCERT);
}

RING_FUNC(ring_get_curlopt_sslcerttype)
{
	RING_API_RETNUMBER(CURLOPT_SSLCERTTYPE);
}

RING_FUNC(ring_get_curlopt_sslkey)
{
	RING_API_RETNUMBER(CURLOPT_SSLKEY);
}

RING_FUNC(ring_get_curlopt_sslkeytype)
{
	RING_API_RETNUMBER(CURLOPT_SSLKEYTYPE);
}

RING_FUNC(ring_get_curlopt_keypasswd)
{
	RING_API_RETNUMBER(CURLOPT_KEYPASSWD);
}

RING_FUNC(ring_get_curlopt_sslengine)
{
	RING_API_RETNUMBER(CURLOPT_SSLENGINE);
}

RING_FUNC(ring_get_curlopt_sslengine_default)
{
	RING_API_RETNUMBER(CURLOPT_SSLENGINE_DEFAULT);
}

RING_FUNC(ring_get_curlopt_sslversion)
{
	RING_API_RETNUMBER(CURLOPT_SSLVERSION);
}

RING_FUNC(ring_get_curlopt_ssl_verifyhost)
{
	RING_API_RETNUMBER(CURLOPT_SSL_VERIFYHOST);
}

RING_FUNC(ring_get_curlopt_ssl_verifypeer)
{
	RING_API_RETNUMBER(CURLOPT_SSL_VERIFYPEER);
}

RING_FUNC(ring_get_curlopt_cainfo)
{
	RING_API_RETNUMBER(CURLOPT_CAINFO);
}

RING_FUNC(ring_get_curlopt_issuercert)
{
	RING_API_RETNUMBER(CURLOPT_ISSUERCERT);
}

RING_FUNC(ring_get_curlopt_capath)
{
	RING_API_RETNUMBER(CURLOPT_CAPATH);
}

RING_FUNC(ring_get_curlopt_crlfile)
{
	RING_API_RETNUMBER(CURLOPT_CRLFILE);
}

RING_FUNC(ring_get_curlopt_certinfo)
{
	RING_API_RETNUMBER(CURLOPT_CERTINFO);
}

RING_FUNC(ring_get_curlopt_random_file)
{
	RING_API_RETNUMBER(CURLOPT_RANDOM_FILE);
}

RING_FUNC(ring_get_curlopt_egdsocket)
{
	RING_API_RETNUMBER(CURLOPT_EGDSOCKET);
}

RING_FUNC(ring_get_curlopt_ssl_cipher_list)
{
	RING_API_RETNUMBER(CURLOPT_SSL_CIPHER_LIST);
}

RING_FUNC(ring_get_curlopt_ssl_sessionid_cache)
{
	RING_API_RETNUMBER(CURLOPT_SSL_SESSIONID_CACHE);
}

RING_FUNC(ring_get_curlopt_krblevel)
{
	RING_API_RETNUMBER(CURLOPT_KRBLEVEL);
}

RING_FUNC(ring_get_curlopt_gssapi_delegation)
{
	RING_API_RETNUMBER(CURLOPT_GSSAPI_DELEGATION);
}

RING_FUNC(ring_get_curlopt_ssh_auth_types)
{
	RING_API_RETNUMBER(CURLOPT_SSH_AUTH_TYPES);
}

RING_FUNC(ring_get_curlopt_ssh_host_public_key_md5)
{
	RING_API_RETNUMBER(CURLOPT_SSH_HOST_PUBLIC_KEY_MD5);
}

RING_FUNC(ring_get_curlopt_ssh_public_keyfile)
{
	RING_API_RETNUMBER(CURLOPT_SSH_PUBLIC_KEYFILE);
}

RING_FUNC(ring_get_curlopt_ssh_private_keyfile)
{
	RING_API_RETNUMBER(CURLOPT_SSH_PRIVATE_KEYFILE);
}

RING_FUNC(ring_get_curlopt_ssh_knownhosts)
{
	RING_API_RETNUMBER(CURLOPT_SSH_KNOWNHOSTS);
}

RING_FUNC(ring_get_curlopt_ssh_keyfunction)
{
	RING_API_RETNUMBER(CURLOPT_SSH_KEYFUNCTION);
}

RING_FUNC(ring_get_curlopt_ssh_keydata)
{
	RING_API_RETNUMBER(CURLOPT_SSH_KEYDATA);
}

RING_FUNC(ring_get_curlopt_private)
{
	RING_API_RETNUMBER(CURLOPT_PRIVATE);
}

RING_FUNC(ring_get_curlopt_share)
{
	RING_API_RETNUMBER(CURLOPT_SHARE);
}

RING_FUNC(ring_get_curlopt_new_file_perms)
{
	RING_API_RETNUMBER(CURLOPT_NEW_FILE_PERMS);
}

RING_FUNC(ring_get_curlopt_new_directory_perms)
{
	RING_API_RETNUMBER(CURLOPT_NEW_DIRECTORY_PERMS);
}

RING_FUNC(ring_get_curlopt_telnetoptions)
{
	RING_API_RETNUMBER(CURLOPT_TELNETOPTIONS);
}

RING_FUNC(ring_get_curle_ok)
{
	RING_API_RETNUMBER(CURLE_OK);
}

RING_FUNC(ring_get_curle_unknown_option)
{
	RING_API_RETNUMBER(CURLE_UNKNOWN_OPTION);
}

RING_FUNC(ring_get_curle_not_built_in)
{
	RING_API_RETNUMBER(CURLE_NOT_BUILT_IN);
}

RING_FUNC(ring_get_curlinfo_effective_url)
{
	RING_API_RETNUMBER(CURLINFO_EFFECTIVE_URL);
}

RING_FUNC(ring_get_curlinfo_response_code)
{
	RING_API_RETNUMBER(CURLINFO_RESPONSE_CODE);
}

RING_FUNC(ring_get_curlinfo_http_connectcode)
{
	RING_API_RETNUMBER(CURLINFO_HTTP_CONNECTCODE);
}

RING_FUNC(ring_get_curlinfo_filetime)
{
	RING_API_RETNUMBER(CURLINFO_FILETIME);
}

RING_FUNC(ring_get_curlinfo_total_time)
{
	RING_API_RETNUMBER(CURLINFO_TOTAL_TIME);
}

RING_FUNC(ring_get_curlinfo_namelookup_time)
{
	RING_API_RETNUMBER(CURLINFO_NAMELOOKUP_TIME);
}

RING_FUNC(ring_get_curlinfo_connect_time)
{
	RING_API_RETNUMBER(CURLINFO_CONNECT_TIME);
}

RING_FUNC(ring_get_curlinfo_appconnect_time)
{
	RING_API_RETNUMBER(CURLINFO_APPCONNECT_TIME);
}

RING_FUNC(ring_get_curlinfo_pretransfer_time)
{
	RING_API_RETNUMBER(CURLINFO_PRETRANSFER_TIME);
}

RING_FUNC(ring_get_curlinfo_starttransfer_time)
{
	RING_API_RETNUMBER(CURLINFO_STARTTRANSFER_TIME);
}

RING_FUNC(ring_get_curlinfo_redirect_time)
{
	RING_API_RETNUMBER(CURLINFO_REDIRECT_TIME);
}

RING_FUNC(ring_get_curlinfo_redirect_count)
{
	RING_API_RETNUMBER(CURLINFO_REDIRECT_COUNT);
}

RING_FUNC(ring_get_curlinfo_redirect_url)
{
	RING_API_RETNUMBER(CURLINFO_REDIRECT_URL);
}

RING_FUNC(ring_get_curlinfo_size_upload)
{
	RING_API_RETNUMBER(CURLINFO_SIZE_UPLOAD);
}

RING_FUNC(ring_get_curlinfo_size_download)
{
	RING_API_RETNUMBER(CURLINFO_SIZE_DOWNLOAD);
}

RING_FUNC(ring_get_curlinfo_speed_download)
{
	RING_API_RETNUMBER(CURLINFO_SPEED_DOWNLOAD);
}

RING_FUNC(ring_get_curlinfo_speed_upload)
{
	RING_API_RETNUMBER(CURLINFO_SPEED_UPLOAD);
}

RING_FUNC(ring_get_curlinfo_header_size)
{
	RING_API_RETNUMBER(CURLINFO_HEADER_SIZE);
}

RING_FUNC(ring_get_curlinfo_request_size)
{
	RING_API_RETNUMBER(CURLINFO_REQUEST_SIZE);
}

RING_FUNC(ring_get_curlinfo_ssl_verifyresult)
{
	RING_API_RETNUMBER(CURLINFO_SSL_VERIFYRESULT);
}

RING_FUNC(ring_get_curlinfo_ssl_engines)
{
	RING_API_RETNUMBER(CURLINFO_SSL_ENGINES);
}

RING_FUNC(ring_get_curlinfo_content_length_download)
{
	RING_API_RETNUMBER(CURLINFO_CONTENT_LENGTH_DOWNLOAD);
}

RING_FUNC(ring_get_curlinfo_content_length_upload)
{
	RING_API_RETNUMBER(CURLINFO_CONTENT_LENGTH_UPLOAD);
}

RING_FUNC(ring_get_curlinfo_content_type)
{
	RING_API_RETNUMBER(CURLINFO_CONTENT_TYPE);
}

RING_FUNC(ring_get_curlinfo_private)
{
	RING_API_RETNUMBER(CURLINFO_PRIVATE);
}

RING_FUNC(ring_get_curlinfo_httpauth_avail)
{
	RING_API_RETNUMBER(CURLINFO_HTTPAUTH_AVAIL);
}

RING_FUNC(ring_get_curlinfo_proxyauth_avail)
{
	RING_API_RETNUMBER(CURLINFO_PROXYAUTH_AVAIL);
}

RING_FUNC(ring_get_curlinfo_os_errno)
{
	RING_API_RETNUMBER(CURLINFO_OS_ERRNO);
}

RING_FUNC(ring_get_curlinfo_num_connects)
{
	RING_API_RETNUMBER(CURLINFO_NUM_CONNECTS);
}

RING_FUNC(ring_get_curlinfo_primary_ip)
{
	RING_API_RETNUMBER(CURLINFO_PRIMARY_IP);
}

RING_FUNC(ring_get_curlinfo_primary_port)
{
	RING_API_RETNUMBER(CURLINFO_PRIMARY_PORT);
}

RING_FUNC(ring_get_curlinfo_local_ip)
{
	RING_API_RETNUMBER(CURLINFO_LOCAL_IP);
}

RING_FUNC(ring_get_curlinfo_local_port)
{
	RING_API_RETNUMBER(CURLINFO_LOCAL_PORT);
}

RING_FUNC(ring_get_curlinfo_cookielist)
{
	RING_API_RETNUMBER(CURLINFO_COOKIELIST);
}

RING_FUNC(ring_get_curlinfo_lastsocket)
{
	RING_API_RETNUMBER(CURLINFO_LASTSOCKET);
}

RING_FUNC(ring_get_curlinfo_ftp_entry_path)
{
	RING_API_RETNUMBER(CURLINFO_FTP_ENTRY_PATH);
}

RING_FUNC(ring_get_curlinfo_certinfo)
{
	RING_API_RETNUMBER(CURLINFO_CERTINFO);
}

RING_FUNC(ring_get_curlinfo_condition_unmet)
{
	RING_API_RETNUMBER(CURLINFO_CONDITION_UNMET);
}

RING_FUNC(ring_get_curlinfo_rtsp_session_id)
{
	RING_API_RETNUMBER(CURLINFO_RTSP_SESSION_ID);
}

RING_FUNC(ring_get_curlinfo_rtsp_client_cseq)
{
	RING_API_RETNUMBER(CURLINFO_RTSP_CLIENT_CSEQ);
}

RING_FUNC(ring_get_curlinfo_rtsp_server_cseq)
{
	RING_API_RETNUMBER(CURLINFO_RTSP_SERVER_CSEQ);
}

RING_FUNC(ring_get_curlinfo_rtsp_cseq_recv)
{
	RING_API_RETNUMBER(CURLINFO_RTSP_CSEQ_RECV);
}

RING_FUNC(ring_get_curlform_copyname)
{
	RING_API_RETNUMBER(CURLFORM_COPYNAME);
}

RING_FUNC(ring_get_curlform_ptrname)
{
	RING_API_RETNUMBER(CURLFORM_PTRNAME);
}

RING_FUNC(ring_get_curlform_copycontents)
{
	RING_API_RETNUMBER(CURLFORM_COPYCONTENTS);
}

RING_FUNC(ring_get_curlform_ptrcontents)
{
	RING_API_RETNUMBER(CURLFORM_PTRCONTENTS);
}

RING_FUNC(ring_get_curlform_contentslength)
{
	RING_API_RETNUMBER(CURLFORM_CONTENTSLENGTH);
}

RING_FUNC(ring_get_curlform_filecontent)
{
	RING_API_RETNUMBER(CURLFORM_FILECONTENT);
}

RING_FUNC(ring_get_curlform_file)
{
	RING_API_RETNUMBER(CURLFORM_FILE);
}

RING_FUNC(ring_get_curlform_contenttype)
{
	RING_API_RETNUMBER(CURLFORM_CONTENTTYPE);
}

RING_FUNC(ring_get_curlform_filename)
{
	RING_API_RETNUMBER(CURLFORM_FILENAME);
}

RING_FUNC(ring_get_curlform_buffer)
{
	RING_API_RETNUMBER(CURLFORM_BUFFER);
}

RING_FUNC(ring_get_curlform_bufferptr)
{
	RING_API_RETNUMBER(CURLFORM_BUFFERPTR);
}

RING_FUNC(ring_get_curlform_bufferlength)
{
	RING_API_RETNUMBER(CURLFORM_BUFFERLENGTH);
}

RING_FUNC(ring_get_curlform_stream)
{
	RING_API_RETNUMBER(CURLFORM_STREAM);
}

RING_FUNC(ring_get_curlform_array)
{
	RING_API_RETNUMBER(CURLFORM_ARRAY);
}

RING_FUNC(ring_get_curlform_contentheader)
{
	RING_API_RETNUMBER(CURLFORM_CONTENTHEADER);
}


RING_FUNC(ring_curl_global_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_global_init( (long ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_init)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(curl_easy_init(),"CURL");
}


RING_FUNC(ring_curl_easy_cleanup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	curl_easy_cleanup((CURL *) RING_API_GETCPOINTER(1,"CURL"));
}


RING_FUNC(ring_curl_easy_setopt_1)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_setopt((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLoption ) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_setopt_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_setopt((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLoption ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_setopt_3)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_setopt((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLoption ) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_setopt_4)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_setopt((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLoption ) RING_API_GETNUMBER(2),(CURLLIST *) RING_API_GETCPOINTER(3,"CURLLIST"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_perform)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_perform((CURL *) RING_API_GETCPOINTER(1,"CURL"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}

size_t ring_getcurldata ( void *buffer, size_t size, size_t nmemb, void *pString )
{
	ring_string_add2(pString,buffer,size*nmemb);
	return size*nmemb ;
}
RING_FUNC(ring_curl_easy_perform_silent)
{
	String *pString  ;
	CURL *pCurl;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pString = ring_string_new("");
	pCurl = (CURL *) RING_API_GETCPOINTER(1,"CURL") ;
	curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION,ring_getcurldata);
	curl_easy_setopt(pCurl, CURLOPT_WRITEDATA,pString);
	curl_easy_perform(pCurl);
	RING_API_RETSTRING2(ring_string_get(pString),ring_string_size(pString));
	ring_string_delete(pString);
}

RING_FUNC(ring_curl_easy_getinfo_1)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_getinfo((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLINFO )  (int) RING_API_GETNUMBER(2),(char **) RING_API_GETCPOINTER2POINTER(3,"char"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_getinfo_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_getinfo((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLINFO )  (int) RING_API_GETNUMBER(2),(long *) RING_API_GETCPOINTER(3,"long"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_getinfo_3)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_getinfo((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLINFO )  (int) RING_API_GETNUMBER(2),RING_API_GETDOUBLEPOINTER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_getinfo_4)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_getinfo((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLINFO )  (int) RING_API_GETNUMBER(2),(CURLLIST **) RING_API_GETCPOINTER2POINTER(3,"CURLLIST"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_getinfo_5)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_getinfo((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLINFO )  (int) RING_API_GETNUMBER(2),(struct curl_certinfo *) RING_API_GETCPOINTER(3,"struct curl_certinfo"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_easy_getinfo_6)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLcode *pValue ; 
		pValue = (CURLcode *) RING_API_MALLOC(sizeof(CURLcode)) ;
		*pValue = curl_easy_getinfo((CURL *) RING_API_GETCPOINTER(1,"CURL"), (CURLINFO )  (int) RING_API_GETNUMBER(2),(struct curl_tlssessioninfo **) RING_API_GETCPOINTER2POINTER(3,"struct curl_tlssessioninfo"));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(curl_version());
}


RING_FUNC(ring_curl_getdate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		time_t *pValue ; 
		pValue = (time_t *) RING_API_MALLOC(sizeof(time_t)) ;
		*pValue = curl_getdate(RING_API_GETSTRING(1),(time_t *) RING_API_GETCPOINTER(2,"time_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"time_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_1)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),RING_API_GETSTRING(6), (CURLformoption)  (int) RING_API_GETNUMBER(7));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_2)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),RING_API_GETSTRING(6), (CURLformoption)  (int) RING_API_GETNUMBER(7),RING_API_GETSTRING(8), (CURLformoption)  (int) RING_API_GETNUMBER(9));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_3)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),(void *) RING_API_GETCPOINTER(6,"void"), (CURLformoption)  (int) RING_API_GETNUMBER(7));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_4)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),(void *) RING_API_GETCPOINTER(6,"void"), (CURLformoption)  (int) RING_API_GETNUMBER(7), (long) RING_API_GETNUMBER(8), (CURLformoption)  (int) RING_API_GETNUMBER(9));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_5)
{
	if ( RING_API_PARACOUNT != 11 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),(void *) RING_API_GETCPOINTER(6,"void"), (CURLformoption)  (int) RING_API_GETNUMBER(7), (long) RING_API_GETNUMBER(8), (CURLformoption)  (int) RING_API_GETNUMBER(9),(char *) RING_API_GETCPOINTER(10,"char"), (CURLformoption)  (int) RING_API_GETNUMBER(11));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_6)
{
	if ( RING_API_PARACOUNT != 11 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),RING_API_GETSTRING(6), (CURLformoption)  (int) RING_API_GETNUMBER(7),(void *) RING_API_GETCPOINTER(8,"void"), (CURLformoption)  (int) RING_API_GETNUMBER(9), (long) RING_API_GETNUMBER(10), (CURLformoption)  (int) RING_API_GETNUMBER(11));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formadd_7)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		CURLFORMcode *pValue ; 
		pValue = (CURLFORMcode *) RING_API_MALLOC(sizeof(CURLFORMcode)) ;
		*pValue = curl_formadd((struct curl_httppost **) RING_API_GETCPOINTER2POINTER(1,"struct curl_httppost"),(struct curl_httppost **) RING_API_GETCPOINTER2POINTER(2,"struct curl_httppost"), (CURLformoption)  (int) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (CURLformoption)  (int) RING_API_GETNUMBER(5),(struct curl_forms *) RING_API_GETCPOINTER(6,"struct curl_forms"), (CURLformoption)  (int) RING_API_GETNUMBER(7));
		RING_API_RETMANAGEDCPOINTER(pValue,"CURLFORMcode",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_curl_formfree)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	curl_formfree((struct curl_httppost *) RING_API_GETCPOINTER(1,"struct curl_httppost"));
}


RING_FUNC(ring_curl_slist_append)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(curl_slist_append((CURLLIST *) RING_API_GETCPOINTER(1,"CURLLIST"),RING_API_GETSTRING(2)),"CURLLIST");
}


RING_FUNC(ring_curl_slist_free_all)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	curl_slist_free_all((CURLLIST *) RING_API_GETCPOINTER(1,"CURLLIST"));
}


RING_FUNC(ring_curl_easy_escape)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(curl_easy_escape((CURL *) RING_API_GETCPOINTER(1,"CURL"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_curl_easy_unescape)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(curl_easy_unescape((CURL *) RING_API_GETCPOINTER(1,"CURL"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(4) ;
}

RING_API void ringlib_init(RingState *pRingState)
{
	RING_API_REGISTER("curl_global_init",ring_curl_global_init);
	RING_API_REGISTER("curl_easy_init",ring_curl_easy_init);
	RING_API_REGISTER("curl_easy_cleanup",ring_curl_easy_cleanup);
	RING_API_REGISTER("curl_easy_setopt_1",ring_curl_easy_setopt_1);
	RING_API_REGISTER("curl_easy_setopt_2",ring_curl_easy_setopt_2);
	RING_API_REGISTER("curl_easy_setopt_3",ring_curl_easy_setopt_3);
	RING_API_REGISTER("curl_easy_setopt_4",ring_curl_easy_setopt_4);
	RING_API_REGISTER("curl_easy_perform",ring_curl_easy_perform);
	RING_API_REGISTER("curl_easy_perform_silent",ring_curl_easy_perform_silent);
	RING_API_REGISTER("curl_easy_getinfo_1",ring_curl_easy_getinfo_1);
	RING_API_REGISTER("curl_easy_getinfo_2",ring_curl_easy_getinfo_2);
	RING_API_REGISTER("curl_easy_getinfo_3",ring_curl_easy_getinfo_3);
	RING_API_REGISTER("curl_easy_getinfo_4",ring_curl_easy_getinfo_4);
	RING_API_REGISTER("curl_easy_getinfo_5",ring_curl_easy_getinfo_5);
	RING_API_REGISTER("curl_easy_getinfo_6",ring_curl_easy_getinfo_6);
	RING_API_REGISTER("curl_version",ring_curl_version);
	RING_API_REGISTER("curl_getdate",ring_curl_getdate);
	RING_API_REGISTER("curl_formadd_1",ring_curl_formadd_1);
	RING_API_REGISTER("curl_formadd_2",ring_curl_formadd_2);
	RING_API_REGISTER("curl_formadd_3",ring_curl_formadd_3);
	RING_API_REGISTER("curl_formadd_4",ring_curl_formadd_4);
	RING_API_REGISTER("curl_formadd_5",ring_curl_formadd_5);
	RING_API_REGISTER("curl_formadd_6",ring_curl_formadd_6);
	RING_API_REGISTER("curl_formadd_7",ring_curl_formadd_7);
	RING_API_REGISTER("curl_formfree",ring_curl_formfree);
	RING_API_REGISTER("curl_slist_append",ring_curl_slist_append);
	RING_API_REGISTER("curl_slist_free_all",ring_curl_slist_free_all);
	RING_API_REGISTER("curl_easy_escape",ring_curl_easy_escape);
	RING_API_REGISTER("curl_easy_unescape",ring_curl_easy_unescape);
	RING_API_REGISTER("new_curllist",ring_new_curllist);
	RING_API_REGISTER("new_managed_curllist",ring_new_managed_curllist);
	RING_API_REGISTER("destroy_curllist",ring_destroy_curllist);
	RING_API_REGISTER("get_curl_global_all",ring_get_curl_global_all);
	RING_API_REGISTER("get_curl_global_ssl",ring_get_curl_global_ssl);
	RING_API_REGISTER("get_curl_global_win32",ring_get_curl_global_win32);
	RING_API_REGISTER("get_curl_global_nothing",ring_get_curl_global_nothing);
	RING_API_REGISTER("get_curl_global_default",ring_get_curl_global_default);
	RING_API_REGISTER("get_curl_global_ack_eintr",ring_get_curl_global_ack_eintr);
	RING_API_REGISTER("get_curlopt_verbose",ring_get_curlopt_verbose);
	RING_API_REGISTER("get_curlopt_header",ring_get_curlopt_header);
	RING_API_REGISTER("get_curlopt_noprogress",ring_get_curlopt_noprogress);
	RING_API_REGISTER("get_curlopt_nosignal",ring_get_curlopt_nosignal);
	RING_API_REGISTER("get_curlopt_wildcardmatch",ring_get_curlopt_wildcardmatch);
	RING_API_REGISTER("get_curlopt_writefunction",ring_get_curlopt_writefunction);
	RING_API_REGISTER("get_curlopt_writedata",ring_get_curlopt_writedata);
	RING_API_REGISTER("get_curlopt_readfunction",ring_get_curlopt_readfunction);
	RING_API_REGISTER("get_curlopt_readdata",ring_get_curlopt_readdata);
	RING_API_REGISTER("get_curlopt_ioctlfunction",ring_get_curlopt_ioctlfunction);
	RING_API_REGISTER("get_curlopt_ioctldata",ring_get_curlopt_ioctldata);
	RING_API_REGISTER("get_curlopt_seekfunction",ring_get_curlopt_seekfunction);
	RING_API_REGISTER("get_curlopt_seekdata",ring_get_curlopt_seekdata);
	RING_API_REGISTER("get_curlopt_sockoptfunction",ring_get_curlopt_sockoptfunction);
	RING_API_REGISTER("get_curlopt_sockoptdata",ring_get_curlopt_sockoptdata);
	RING_API_REGISTER("get_curlopt_opensocketfunction",ring_get_curlopt_opensocketfunction);
	RING_API_REGISTER("get_curlopt_opensocketdata",ring_get_curlopt_opensocketdata);
	RING_API_REGISTER("get_curlopt_closesocketfunction",ring_get_curlopt_closesocketfunction);
	RING_API_REGISTER("get_curlopt_closesocketdata",ring_get_curlopt_closesocketdata);
	RING_API_REGISTER("get_curlopt_progressfunction",ring_get_curlopt_progressfunction);
	RING_API_REGISTER("get_curlopt_progressdata",ring_get_curlopt_progressdata);
	RING_API_REGISTER("get_curlopt_headerfunction",ring_get_curlopt_headerfunction);
	RING_API_REGISTER("get_curlopt_headerdata",ring_get_curlopt_headerdata);
	RING_API_REGISTER("get_curlopt_debugfunction",ring_get_curlopt_debugfunction);
	RING_API_REGISTER("get_curlopt_debugdata",ring_get_curlopt_debugdata);
	RING_API_REGISTER("get_curlopt_ssl_ctx_function",ring_get_curlopt_ssl_ctx_function);
	RING_API_REGISTER("get_curlopt_ssl_ctx_data",ring_get_curlopt_ssl_ctx_data);
	RING_API_REGISTER("get_curlopt_conv_to_network_function",ring_get_curlopt_conv_to_network_function);
	RING_API_REGISTER("get_curlopt_conv_from_network_function",ring_get_curlopt_conv_from_network_function);
	RING_API_REGISTER("get_curlopt_conv_from_utf8_function",ring_get_curlopt_conv_from_utf8_function);
	RING_API_REGISTER("get_curlopt_interleavefunction",ring_get_curlopt_interleavefunction);
	RING_API_REGISTER("get_curlopt_interleavedata",ring_get_curlopt_interleavedata);
	RING_API_REGISTER("get_curlopt_chunk_bgn_function",ring_get_curlopt_chunk_bgn_function);
	RING_API_REGISTER("get_curlopt_chunk_end_function",ring_get_curlopt_chunk_end_function);
	RING_API_REGISTER("get_curlopt_chunk_data",ring_get_curlopt_chunk_data);
	RING_API_REGISTER("get_curlopt_fnmatch_function",ring_get_curlopt_fnmatch_function);
	RING_API_REGISTER("get_curlopt_fnmatch_data",ring_get_curlopt_fnmatch_data);
	RING_API_REGISTER("get_curlopt_errorbuffer",ring_get_curlopt_errorbuffer);
	RING_API_REGISTER("get_curlopt_stderr",ring_get_curlopt_stderr);
	RING_API_REGISTER("get_curlopt_failonerror",ring_get_curlopt_failonerror);
	RING_API_REGISTER("get_curlopt_url",ring_get_curlopt_url);
	RING_API_REGISTER("get_curlopt_protocols",ring_get_curlopt_protocols);
	RING_API_REGISTER("get_curlopt_redir_protocols",ring_get_curlopt_redir_protocols);
	RING_API_REGISTER("get_curlopt_proxy",ring_get_curlopt_proxy);
	RING_API_REGISTER("get_curlopt_proxyport",ring_get_curlopt_proxyport);
	RING_API_REGISTER("get_curlopt_proxytype",ring_get_curlopt_proxytype);
	RING_API_REGISTER("get_curlopt_noproxy",ring_get_curlopt_noproxy);
	RING_API_REGISTER("get_curlopt_httpproxytunnel",ring_get_curlopt_httpproxytunnel);
	RING_API_REGISTER("get_curlopt_socks5_gssapi_service",ring_get_curlopt_socks5_gssapi_service);
	RING_API_REGISTER("get_curlopt_socks5_gssapi_nec",ring_get_curlopt_socks5_gssapi_nec);
	RING_API_REGISTER("get_curlopt_interface",ring_get_curlopt_interface);
	RING_API_REGISTER("get_curlopt_localport",ring_get_curlopt_localport);
	RING_API_REGISTER("get_curlopt_localportrange",ring_get_curlopt_localportrange);
	RING_API_REGISTER("get_curlopt_dns_cache_timeout",ring_get_curlopt_dns_cache_timeout);
	RING_API_REGISTER("get_curlopt_dns_use_global_cache",ring_get_curlopt_dns_use_global_cache);
	RING_API_REGISTER("get_curlopt_buffersize",ring_get_curlopt_buffersize);
	RING_API_REGISTER("get_curlopt_port",ring_get_curlopt_port);
	RING_API_REGISTER("get_curlopt_tcp_nodelay",ring_get_curlopt_tcp_nodelay);
	RING_API_REGISTER("get_curlopt_address_scope",ring_get_curlopt_address_scope);
	RING_API_REGISTER("get_curlopt_netrc",ring_get_curlopt_netrc);
	RING_API_REGISTER("get_curlopt_netrc_file",ring_get_curlopt_netrc_file);
	RING_API_REGISTER("get_curlopt_userpwd",ring_get_curlopt_userpwd);
	RING_API_REGISTER("get_curlopt_proxyuserpwd",ring_get_curlopt_proxyuserpwd);
	RING_API_REGISTER("get_curlopt_username",ring_get_curlopt_username);
	RING_API_REGISTER("get_curlopt_password",ring_get_curlopt_password);
	RING_API_REGISTER("get_curlopt_proxyusername",ring_get_curlopt_proxyusername);
	RING_API_REGISTER("get_curlopt_proxypassword",ring_get_curlopt_proxypassword);
	RING_API_REGISTER("get_curlopt_httpauth",ring_get_curlopt_httpauth);
	RING_API_REGISTER("get_curlopt_tlsauth_username",ring_get_curlopt_tlsauth_username);
	RING_API_REGISTER("get_curlopt_tlsauth_password",ring_get_curlopt_tlsauth_password);
	RING_API_REGISTER("get_curlopt_tlsauth_type",ring_get_curlopt_tlsauth_type);
	RING_API_REGISTER("get_curlopt_proxyauth",ring_get_curlopt_proxyauth);
	RING_API_REGISTER("get_curlopt_autoreferer",ring_get_curlopt_autoreferer);
	RING_API_REGISTER("get_curlopt_accept_encoding",ring_get_curlopt_accept_encoding);
	RING_API_REGISTER("get_curlopt_transfer_encoding",ring_get_curlopt_transfer_encoding);
	RING_API_REGISTER("get_curlopt_followlocation",ring_get_curlopt_followlocation);
	RING_API_REGISTER("get_curlopt_unrestricted_auth",ring_get_curlopt_unrestricted_auth);
	RING_API_REGISTER("get_curlopt_maxredirs",ring_get_curlopt_maxredirs);
	RING_API_REGISTER("get_curlopt_postredir",ring_get_curlopt_postredir);
	RING_API_REGISTER("get_curlopt_put",ring_get_curlopt_put);
	RING_API_REGISTER("get_curlopt_post",ring_get_curlopt_post);
	RING_API_REGISTER("get_curlopt_postfields",ring_get_curlopt_postfields);
	RING_API_REGISTER("get_curlopt_postfieldsize",ring_get_curlopt_postfieldsize);
	RING_API_REGISTER("get_curlopt_postfieldsize_large",ring_get_curlopt_postfieldsize_large);
	RING_API_REGISTER("get_curlopt_copypostfields",ring_get_curlopt_copypostfields);
	RING_API_REGISTER("get_curlopt_httppost",ring_get_curlopt_httppost);
	RING_API_REGISTER("get_curlopt_referer",ring_get_curlopt_referer);
	RING_API_REGISTER("get_curlopt_useragent",ring_get_curlopt_useragent);
	RING_API_REGISTER("get_curlopt_httpheader",ring_get_curlopt_httpheader);
	RING_API_REGISTER("get_curlopt_http200aliases",ring_get_curlopt_http200aliases);
	RING_API_REGISTER("get_curlopt_cookie",ring_get_curlopt_cookie);
	RING_API_REGISTER("get_curlopt_cookiefile",ring_get_curlopt_cookiefile);
	RING_API_REGISTER("get_curlopt_cookiejar",ring_get_curlopt_cookiejar);
	RING_API_REGISTER("get_curlopt_cookiesession",ring_get_curlopt_cookiesession);
	RING_API_REGISTER("get_curlopt_cookielist",ring_get_curlopt_cookielist);
	RING_API_REGISTER("get_curlopt_httpget",ring_get_curlopt_httpget);
	RING_API_REGISTER("get_curlopt_http_version",ring_get_curlopt_http_version);
	RING_API_REGISTER("get_curlopt_ignore_content_length",ring_get_curlopt_ignore_content_length);
	RING_API_REGISTER("get_curlopt_http_content_decoding",ring_get_curlopt_http_content_decoding);
	RING_API_REGISTER("get_curlopt_http_transfer_decoding",ring_get_curlopt_http_transfer_decoding);
	RING_API_REGISTER("get_curlopt_mail_from",ring_get_curlopt_mail_from);
	RING_API_REGISTER("get_curlopt_mail_rcpt",ring_get_curlopt_mail_rcpt);
	RING_API_REGISTER("get_curlopt_tftp_blksize",ring_get_curlopt_tftp_blksize);
	RING_API_REGISTER("get_curlopt_ftpport",ring_get_curlopt_ftpport);
	RING_API_REGISTER("get_curlopt_quote",ring_get_curlopt_quote);
	RING_API_REGISTER("get_curlopt_postquote",ring_get_curlopt_postquote);
	RING_API_REGISTER("get_curlopt_prequote",ring_get_curlopt_prequote);
	RING_API_REGISTER("get_curlopt_append",ring_get_curlopt_append);
	RING_API_REGISTER("get_curlopt_ftp_use_eprt",ring_get_curlopt_ftp_use_eprt);
	RING_API_REGISTER("get_curlopt_ftp_use_epsv",ring_get_curlopt_ftp_use_epsv);
	RING_API_REGISTER("get_curlopt_ftp_use_pret",ring_get_curlopt_ftp_use_pret);
	RING_API_REGISTER("get_curlopt_ftp_create_missing_dirs",ring_get_curlopt_ftp_create_missing_dirs);
	RING_API_REGISTER("get_curlopt_ftp_response_timeout",ring_get_curlopt_ftp_response_timeout);
	RING_API_REGISTER("get_curlopt_ftp_alternative_to_user",ring_get_curlopt_ftp_alternative_to_user);
	RING_API_REGISTER("get_curlopt_ftp_skip_pasv_ip",ring_get_curlopt_ftp_skip_pasv_ip);
	RING_API_REGISTER("get_curlopt_ftpsslauth",ring_get_curlopt_ftpsslauth);
	RING_API_REGISTER("get_curlopt_ftp_ssl_ccc",ring_get_curlopt_ftp_ssl_ccc);
	RING_API_REGISTER("get_curlopt_ftp_account",ring_get_curlopt_ftp_account);
	RING_API_REGISTER("get_curlopt_ftp_filemethod",ring_get_curlopt_ftp_filemethod);
	RING_API_REGISTER("get_curlopt_rtsp_request",ring_get_curlopt_rtsp_request);
	RING_API_REGISTER("get_curlopt_rtsp_session_id",ring_get_curlopt_rtsp_session_id);
	RING_API_REGISTER("get_curlopt_rtsp_stream_uri",ring_get_curlopt_rtsp_stream_uri);
	RING_API_REGISTER("get_curlopt_rtsp_transport",ring_get_curlopt_rtsp_transport);
	RING_API_REGISTER("get_curlopt_rtsp_client_cseq",ring_get_curlopt_rtsp_client_cseq);
	RING_API_REGISTER("get_curlopt_rtsp_server_cseq",ring_get_curlopt_rtsp_server_cseq);
	RING_API_REGISTER("get_curlopt_transfertext",ring_get_curlopt_transfertext);
	RING_API_REGISTER("get_curlopt_proxy_transfer_mode",ring_get_curlopt_proxy_transfer_mode);
	RING_API_REGISTER("get_curlopt_crlf",ring_get_curlopt_crlf);
	RING_API_REGISTER("get_curlopt_range",ring_get_curlopt_range);
	RING_API_REGISTER("get_curlopt_resume_from",ring_get_curlopt_resume_from);
	RING_API_REGISTER("get_curlopt_resume_from_large",ring_get_curlopt_resume_from_large);
	RING_API_REGISTER("get_curlopt_customrequest",ring_get_curlopt_customrequest);
	RING_API_REGISTER("get_curlopt_filetime",ring_get_curlopt_filetime);
	RING_API_REGISTER("get_curlopt_dirlistonly",ring_get_curlopt_dirlistonly);
	RING_API_REGISTER("get_curlopt_nobody",ring_get_curlopt_nobody);
	RING_API_REGISTER("get_curlopt_infilesize",ring_get_curlopt_infilesize);
	RING_API_REGISTER("get_curlopt_infilesize_large",ring_get_curlopt_infilesize_large);
	RING_API_REGISTER("get_curlopt_upload",ring_get_curlopt_upload);
	RING_API_REGISTER("get_curlopt_maxfilesize",ring_get_curlopt_maxfilesize);
	RING_API_REGISTER("get_curlopt_maxfilesize_large",ring_get_curlopt_maxfilesize_large);
	RING_API_REGISTER("get_curlopt_timecondition",ring_get_curlopt_timecondition);
	RING_API_REGISTER("get_curlopt_timevalue",ring_get_curlopt_timevalue);
	RING_API_REGISTER("get_curlopt_timeout",ring_get_curlopt_timeout);
	RING_API_REGISTER("get_curlopt_timeout_ms",ring_get_curlopt_timeout_ms);
	RING_API_REGISTER("get_curlopt_low_speed_limit",ring_get_curlopt_low_speed_limit);
	RING_API_REGISTER("get_curlopt_low_speed_time",ring_get_curlopt_low_speed_time);
	RING_API_REGISTER("get_curlopt_max_send_speed_large",ring_get_curlopt_max_send_speed_large);
	RING_API_REGISTER("get_curlopt_max_recv_speed_large",ring_get_curlopt_max_recv_speed_large);
	RING_API_REGISTER("get_curlopt_maxconnects",ring_get_curlopt_maxconnects);
	RING_API_REGISTER("get_curlopt_fresh_connect",ring_get_curlopt_fresh_connect);
	RING_API_REGISTER("get_curlopt_forbid_reuse",ring_get_curlopt_forbid_reuse);
	RING_API_REGISTER("get_curlopt_connecttimeout",ring_get_curlopt_connecttimeout);
	RING_API_REGISTER("get_curlopt_connecttimeout_ms",ring_get_curlopt_connecttimeout_ms);
	RING_API_REGISTER("get_curlopt_ipresolve",ring_get_curlopt_ipresolve);
	RING_API_REGISTER("get_curlopt_connect_only",ring_get_curlopt_connect_only);
	RING_API_REGISTER("get_curlopt_use_ssl",ring_get_curlopt_use_ssl);
	RING_API_REGISTER("get_curlopt_resolve",ring_get_curlopt_resolve);
	RING_API_REGISTER("get_curlopt_sslcert",ring_get_curlopt_sslcert);
	RING_API_REGISTER("get_curlopt_sslcerttype",ring_get_curlopt_sslcerttype);
	RING_API_REGISTER("get_curlopt_sslkey",ring_get_curlopt_sslkey);
	RING_API_REGISTER("get_curlopt_sslkeytype",ring_get_curlopt_sslkeytype);
	RING_API_REGISTER("get_curlopt_keypasswd",ring_get_curlopt_keypasswd);
	RING_API_REGISTER("get_curlopt_sslengine",ring_get_curlopt_sslengine);
	RING_API_REGISTER("get_curlopt_sslengine_default",ring_get_curlopt_sslengine_default);
	RING_API_REGISTER("get_curlopt_sslversion",ring_get_curlopt_sslversion);
	RING_API_REGISTER("get_curlopt_ssl_verifyhost",ring_get_curlopt_ssl_verifyhost);
	RING_API_REGISTER("get_curlopt_ssl_verifypeer",ring_get_curlopt_ssl_verifypeer);
	RING_API_REGISTER("get_curlopt_cainfo",ring_get_curlopt_cainfo);
	RING_API_REGISTER("get_curlopt_issuercert",ring_get_curlopt_issuercert);
	RING_API_REGISTER("get_curlopt_capath",ring_get_curlopt_capath);
	RING_API_REGISTER("get_curlopt_crlfile",ring_get_curlopt_crlfile);
	RING_API_REGISTER("get_curlopt_certinfo",ring_get_curlopt_certinfo);
	RING_API_REGISTER("get_curlopt_random_file",ring_get_curlopt_random_file);
	RING_API_REGISTER("get_curlopt_egdsocket",ring_get_curlopt_egdsocket);
	RING_API_REGISTER("get_curlopt_ssl_cipher_list",ring_get_curlopt_ssl_cipher_list);
	RING_API_REGISTER("get_curlopt_ssl_sessionid_cache",ring_get_curlopt_ssl_sessionid_cache);
	RING_API_REGISTER("get_curlopt_krblevel",ring_get_curlopt_krblevel);
	RING_API_REGISTER("get_curlopt_gssapi_delegation",ring_get_curlopt_gssapi_delegation);
	RING_API_REGISTER("get_curlopt_ssh_auth_types",ring_get_curlopt_ssh_auth_types);
	RING_API_REGISTER("get_curlopt_ssh_host_public_key_md5",ring_get_curlopt_ssh_host_public_key_md5);
	RING_API_REGISTER("get_curlopt_ssh_public_keyfile",ring_get_curlopt_ssh_public_keyfile);
	RING_API_REGISTER("get_curlopt_ssh_private_keyfile",ring_get_curlopt_ssh_private_keyfile);
	RING_API_REGISTER("get_curlopt_ssh_knownhosts",ring_get_curlopt_ssh_knownhosts);
	RING_API_REGISTER("get_curlopt_ssh_keyfunction",ring_get_curlopt_ssh_keyfunction);
	RING_API_REGISTER("get_curlopt_ssh_keydata",ring_get_curlopt_ssh_keydata);
	RING_API_REGISTER("get_curlopt_private",ring_get_curlopt_private);
	RING_API_REGISTER("get_curlopt_share",ring_get_curlopt_share);
	RING_API_REGISTER("get_curlopt_new_file_perms",ring_get_curlopt_new_file_perms);
	RING_API_REGISTER("get_curlopt_new_directory_perms",ring_get_curlopt_new_directory_perms);
	RING_API_REGISTER("get_curlopt_telnetoptions",ring_get_curlopt_telnetoptions);
	RING_API_REGISTER("get_curle_ok",ring_get_curle_ok);
	RING_API_REGISTER("get_curle_unknown_option",ring_get_curle_unknown_option);
	RING_API_REGISTER("get_curle_not_built_in",ring_get_curle_not_built_in);
	RING_API_REGISTER("get_curlinfo_effective_url",ring_get_curlinfo_effective_url);
	RING_API_REGISTER("get_curlinfo_response_code",ring_get_curlinfo_response_code);
	RING_API_REGISTER("get_curlinfo_http_connectcode",ring_get_curlinfo_http_connectcode);
	RING_API_REGISTER("get_curlinfo_filetime",ring_get_curlinfo_filetime);
	RING_API_REGISTER("get_curlinfo_total_time",ring_get_curlinfo_total_time);
	RING_API_REGISTER("get_curlinfo_namelookup_time",ring_get_curlinfo_namelookup_time);
	RING_API_REGISTER("get_curlinfo_connect_time",ring_get_curlinfo_connect_time);
	RING_API_REGISTER("get_curlinfo_appconnect_time",ring_get_curlinfo_appconnect_time);
	RING_API_REGISTER("get_curlinfo_pretransfer_time",ring_get_curlinfo_pretransfer_time);
	RING_API_REGISTER("get_curlinfo_starttransfer_time",ring_get_curlinfo_starttransfer_time);
	RING_API_REGISTER("get_curlinfo_redirect_time",ring_get_curlinfo_redirect_time);
	RING_API_REGISTER("get_curlinfo_redirect_count",ring_get_curlinfo_redirect_count);
	RING_API_REGISTER("get_curlinfo_redirect_url",ring_get_curlinfo_redirect_url);
	RING_API_REGISTER("get_curlinfo_size_upload",ring_get_curlinfo_size_upload);
	RING_API_REGISTER("get_curlinfo_size_download",ring_get_curlinfo_size_download);
	RING_API_REGISTER("get_curlinfo_speed_download",ring_get_curlinfo_speed_download);
	RING_API_REGISTER("get_curlinfo_speed_upload",ring_get_curlinfo_speed_upload);
	RING_API_REGISTER("get_curlinfo_header_size",ring_get_curlinfo_header_size);
	RING_API_REGISTER("get_curlinfo_request_size",ring_get_curlinfo_request_size);
	RING_API_REGISTER("get_curlinfo_ssl_verifyresult",ring_get_curlinfo_ssl_verifyresult);
	RING_API_REGISTER("get_curlinfo_ssl_engines",ring_get_curlinfo_ssl_engines);
	RING_API_REGISTER("get_curlinfo_content_length_download",ring_get_curlinfo_content_length_download);
	RING_API_REGISTER("get_curlinfo_content_length_upload",ring_get_curlinfo_content_length_upload);
	RING_API_REGISTER("get_curlinfo_content_type",ring_get_curlinfo_content_type);
	RING_API_REGISTER("get_curlinfo_private",ring_get_curlinfo_private);
	RING_API_REGISTER("get_curlinfo_httpauth_avail",ring_get_curlinfo_httpauth_avail);
	RING_API_REGISTER("get_curlinfo_proxyauth_avail",ring_get_curlinfo_proxyauth_avail);
	RING_API_REGISTER("get_curlinfo_os_errno",ring_get_curlinfo_os_errno);
	RING_API_REGISTER("get_curlinfo_num_connects",ring_get_curlinfo_num_connects);
	RING_API_REGISTER("get_curlinfo_primary_ip",ring_get_curlinfo_primary_ip);
	RING_API_REGISTER("get_curlinfo_primary_port",ring_get_curlinfo_primary_port);
	RING_API_REGISTER("get_curlinfo_local_ip",ring_get_curlinfo_local_ip);
	RING_API_REGISTER("get_curlinfo_local_port",ring_get_curlinfo_local_port);
	RING_API_REGISTER("get_curlinfo_cookielist",ring_get_curlinfo_cookielist);
	RING_API_REGISTER("get_curlinfo_lastsocket",ring_get_curlinfo_lastsocket);
	RING_API_REGISTER("get_curlinfo_ftp_entry_path",ring_get_curlinfo_ftp_entry_path);
	RING_API_REGISTER("get_curlinfo_certinfo",ring_get_curlinfo_certinfo);
	RING_API_REGISTER("get_curlinfo_condition_unmet",ring_get_curlinfo_condition_unmet);
	RING_API_REGISTER("get_curlinfo_rtsp_session_id",ring_get_curlinfo_rtsp_session_id);
	RING_API_REGISTER("get_curlinfo_rtsp_client_cseq",ring_get_curlinfo_rtsp_client_cseq);
	RING_API_REGISTER("get_curlinfo_rtsp_server_cseq",ring_get_curlinfo_rtsp_server_cseq);
	RING_API_REGISTER("get_curlinfo_rtsp_cseq_recv",ring_get_curlinfo_rtsp_cseq_recv);
	RING_API_REGISTER("get_curlform_copyname",ring_get_curlform_copyname);
	RING_API_REGISTER("get_curlform_ptrname",ring_get_curlform_ptrname);
	RING_API_REGISTER("get_curlform_copycontents",ring_get_curlform_copycontents);
	RING_API_REGISTER("get_curlform_ptrcontents",ring_get_curlform_ptrcontents);
	RING_API_REGISTER("get_curlform_contentslength",ring_get_curlform_contentslength);
	RING_API_REGISTER("get_curlform_filecontent",ring_get_curlform_filecontent);
	RING_API_REGISTER("get_curlform_file",ring_get_curlform_file);
	RING_API_REGISTER("get_curlform_contenttype",ring_get_curlform_contenttype);
	RING_API_REGISTER("get_curlform_filename",ring_get_curlform_filename);
	RING_API_REGISTER("get_curlform_buffer",ring_get_curlform_buffer);
	RING_API_REGISTER("get_curlform_bufferptr",ring_get_curlform_bufferptr);
	RING_API_REGISTER("get_curlform_bufferlength",ring_get_curlform_bufferlength);
	RING_API_REGISTER("get_curlform_stream",ring_get_curlform_stream);
	RING_API_REGISTER("get_curlform_array",ring_get_curlform_array);
	RING_API_REGISTER("get_curlform_contentheader",ring_get_curlform_contentheader);
}
