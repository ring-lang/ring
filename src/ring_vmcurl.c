/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include "ring_vmcurl.h"
#include "curl/curl.h"
/* Data */
struct upload_status {
	int lines_read  ;
	List *pList  ;
} ;
/* Functions */

void ring_vm_curl_loadfunctions ( RingState *pRingState )
{
	ring_vm_funcregister("download",ring_vm_curl_download);
	ring_vm_funcregister("sendemail",ring_vm_curl_sendemail);
}

size_t ring_getcurldata ( void *buffer, size_t size, size_t nmemb, void *pString )
{
	ring_string_add2(pString,buffer,size*nmemb);
	return size*nmemb ;
}

void ring_vm_curl_download ( void *pPointer )
{
	CURL *curl  ;
	CURLcode res  ;
	String *pString  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	curl = curl_easy_init();
	if ( curl ) {
		pString = ring_string_new("");
		curl_easy_setopt(curl, CURLOPT_URL,RING_API_GETSTRING(1));
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION,1);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL,1);
		curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING,"");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,ring_getcurldata);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA,pString);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		RING_API_RETSTRING2(ring_string_get(pString),ring_string_size(pString));
		ring_string_delete(pString);
	}
}

size_t ring_payload_source ( void *ptr, size_t size, size_t nmemb, void *userp )
{
	const char *data  ;
	struct upload_status *upload_ctx  ;
	size_t len  ;
	upload_ctx = (struct upload_status *)userp ;
	if ( (size == 0) || (nmemb == 0) || ((size*nmemb) < 1) ) {
		return 0 ;
	}
	if ( upload_ctx->lines_read  <= ring_list_getsize(upload_ctx->pList) ) {
		data = ring_list_getstring(upload_ctx->pList,upload_ctx->lines_read);
		len = strlen( data ) ;
		memcpy(ptr, data, len);
		upload_ctx->lines_read++ ;
		return len ;
	}
	return 0 ;
}

void ring_vm_curl_sendemail ( void *pPointer )
{
	CURL *curl  ;
	CURLcode res  ;
	struct curl_slist *recipients  ;
	struct upload_status upload_ctx  ;
	String *pString  ;
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! (RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) && RING_API_ISSTRING(4) && RING_API_ISSTRING(5) && RING_API_ISSTRING(6) && RING_API_ISSTRING(7) && RING_API_ISSTRING(8)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	res = CURLE_OK ;
	recipients = NULL ;
	upload_ctx.lines_read = 1 ;
	curl = curl_easy_init();
	if ( curl ) {
		curl_easy_setopt(curl,CURLOPT_URL,RING_API_GETSTRING(1));
		curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
		curl_easy_setopt(curl, CURLOPT_USERNAME,RING_API_GETSTRING(2));
		curl_easy_setopt(curl,CURLOPT_PASSWORD,RING_API_GETSTRING(3));
		curl_easy_setopt(curl, CURLOPT_MAIL_FROM,RING_API_GETSTRING(4));
		recipients = curl_slist_append(recipients,RING_API_GETSTRING(5));
		recipients = curl_slist_append(recipients,RING_API_GETSTRING(6));
		curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, ring_payload_source);
		curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
		/* Payload Text */
		upload_ctx.pList = ring_list_new(0);
		ring_list_addstring(upload_ctx.pList,"Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n");
		ring_list_addstring(upload_ctx.pList,"To: ");
		pString = ring_list_getstringobject(upload_ctx.pList,2);
		ring_string_add(pString,RING_API_GETSTRING(5));
		ring_string_add(pString,"\r\n");
		ring_list_addstring(upload_ctx.pList,"From: ");
		pString = ring_list_getstringobject(upload_ctx.pList,3);
		ring_string_add(pString,RING_API_GETSTRING(4));
		ring_string_add(pString,"\r\n");
		ring_list_addstring(upload_ctx.pList,"Cc: ");
		pString = ring_list_getstringobject(upload_ctx.pList,4);
		ring_string_add(pString,RING_API_GETSTRING(6));
		ring_string_add(pString,"\r\n");
		ring_list_addstring(upload_ctx.pList,"Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@rfcpedant.example.org>\r\n");
		ring_list_addstring(upload_ctx.pList,"Subject: ");
		pString = ring_list_getstringobject(upload_ctx.pList,6);
		ring_string_add(pString,RING_API_GETSTRING(7));
		ring_string_add(pString,"\r\n");
		ring_list_addstring(upload_ctx.pList,"\r\n");
		ring_list_addstring(upload_ctx.pList,RING_API_GETSTRING(8));
		res = curl_easy_perform(curl);
		if ( res != CURLE_OK ) {
			RING_API_ERROR(curl_easy_strerror(res));
			return ;
		}
		curl_slist_free_all(recipients);
		curl_easy_cleanup(curl);
		ring_list_delete(upload_ctx.pList);
	}
}
