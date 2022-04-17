/*
**  Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include "ring_vmopenssl.h"
#include "openssl/md5.h"
#include "openssl/sha.h"
#include "openssl/evp.h"
#include "openssl/rand.h"
#include "ring_vmopenssl.h"
/* Functions Depend on the Library Version */
#if OPENSSL_VERSION_NUMBER >= 0x00908000L
/* OpenSSL 0.98 and later */
#include "encrypt_v2.c"
#else
#include "encrypt_v1.c"
#endif
/* Functions */

typedef struct ListCipherArg {
	void *pPointer;
	List *pList;
} ListCipherArg;

RING_LIBINIT
{
	RING_API_REGISTER("md5init",ring_vm_openssl_md5_init);
	RING_API_REGISTER("md5update",ring_vm_openssl_md5_update);
	RING_API_REGISTER("md5final",ring_vm_openssl_md5_final);
	RING_API_REGISTER("md5",ring_vm_openssl_md5);
	RING_API_REGISTER("sha1init",ring_vm_openssl_sha1_init);
	RING_API_REGISTER("sha1update",ring_vm_openssl_sha1_update);
	RING_API_REGISTER("sha1final",ring_vm_openssl_sha1_final);
	RING_API_REGISTER("sha1",ring_vm_openssl_sha1);
	RING_API_REGISTER("sha256init",ring_vm_openssl_sha256_init);
	RING_API_REGISTER("sha256update",ring_vm_openssl_sha256_update);
	RING_API_REGISTER("sha256final",ring_vm_openssl_sha256_final);
	RING_API_REGISTER("sha256",ring_vm_openssl_sha256);
	RING_API_REGISTER("sha512init",ring_vm_openssl_sha512_init);
	RING_API_REGISTER("sha512update",ring_vm_openssl_sha512_update);
	RING_API_REGISTER("sha512final",ring_vm_openssl_sha512_final);
	RING_API_REGISTER("sha512",ring_vm_openssl_sha512);
	RING_API_REGISTER("sha384init",ring_vm_openssl_sha384_init);
	RING_API_REGISTER("sha384update",ring_vm_openssl_sha384_update);
	RING_API_REGISTER("sha384final",ring_vm_openssl_sha384_final);
	RING_API_REGISTER("sha384",ring_vm_openssl_sha384);
	RING_API_REGISTER("sha224init",ring_vm_openssl_sha224_init);
	RING_API_REGISTER("sha224update",ring_vm_openssl_sha224_update);
	RING_API_REGISTER("sha224final",ring_vm_openssl_sha224_final);
	RING_API_REGISTER("sha224",ring_vm_openssl_sha224);
	RING_API_REGISTER("encrypt",ring_vm_openssl_encrypt);
	RING_API_REGISTER("decrypt",ring_vm_openssl_decrypt);
	RING_API_REGISTER("randbytes",ring_vm_openssl_randbytes);
	RING_API_REGISTER("supportedciphers",ring_vm_openssl_list_ciphers);
	/* Before OpenSSL 1.1, calling OpenSSL_add_all_algorithms is required */
	/* Ref: https://wiki.openssl.org/index.php/Library_Initialization */
	#if OPENSSL_VERSION_NUMBER < 0x10100000L
	OpenSSL_add_all_algorithms();
	#endif
}

static void ring_vm_openssl_buf2hex (const unsigned char* pData, int nLen, char* cStr)
{
	static const char cHexChars[] = "0123456789abcdef" ;
	unsigned char bVal ;
	int i ;
	for (i = 0; i < nLen; i++) {
		bVal = pData[i];
		cStr[i*2] = cHexChars[bVal >> 4] ;
		cStr[(i*2)+1] = cHexChars[bVal & 0x0F] ;
	}
	cStr[2*nLen] = 0;
}

void ring_vm_openssl_md5_init ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		MD5_CTX* pValue ;
		pValue = (MD5_CTX *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(MD5_CTX)) ;
		MD5_Init (pValue);
		RING_API_RETMANAGEDCPOINTER(pValue,"MD5_CTX",ring_state_free);
	}
}

void ring_vm_openssl_md5_update ( void *pPointer )
{
	int x,nSize  ;
	char *cInput  ;
	MD5_CTX* pValue ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (MD5_CTX *) RING_API_GETCPOINTER(1,"MD5_CTX") ;
	if ( pValue == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cInput = RING_API_GETSTRING(2) ;
	nSize = RING_API_GETSTRINGSIZE(2) ;
	RING_API_RETNUMBER(MD5_Update(pValue, cInput, (unsigned long) nSize));
}

void ring_vm_openssl_md5_final ( void *pPointer )
{
	unsigned char digest[MD5_DIGEST_LENGTH]  ;
	char cString[MD5_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	MD5_CTX* pValue ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
	pValue = (MD5_CTX *) RING_API_GETCPOINTER(1,"MD5_CTX") ;
	if ( pValue == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	MD5_Final (digest, pValue);
	ring_vm_openssl_buf2hex (digest, MD5_DIGEST_LENGTH, cString);
	RING_API_RETSTRING(cString);
}

void ring_vm_openssl_md5 ( void *pPointer )
{
	unsigned char digest[MD5_DIGEST_LENGTH]  ;
	char cString[33]  ;
	int nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		MD5((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		ring_vm_openssl_buf2hex (digest, MD5_DIGEST_LENGTH, cString);
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha1_init ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		SHA_CTX* pValue ;
		pValue = (SHA_CTX *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SHA_CTX)) ;
		SHA1_Init (pValue);
		RING_API_RETMANAGEDCPOINTER(pValue,"SHA_CTX",ring_state_free);
	}
}

void ring_vm_openssl_sha1_update ( void *pPointer )
{
	int x,nSize  ;
	char *cInput  ;
	SHA_CTX* pValue ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (SHA_CTX *) RING_API_GETCPOINTER(1,"SHA_CTX") ;
	if ( pValue == NULL ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cInput = RING_API_GETSTRING(2) ;
	nSize = RING_API_GETSTRINGSIZE(2) ;
	RING_API_RETNUMBER(SHA1_Update(pValue, cInput, (unsigned long) nSize));
}

void ring_vm_openssl_sha1_final ( void *pPointer )
{
	unsigned char digest[SHA_DIGEST_LENGTH]  ;
	char cString[SHA_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	SHA_CTX* pValue ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	pValue = (SHA_CTX *) RING_API_GETCPOINTER(1,"SHA_CTX") ;
	if ( pValue == NULL ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SHA1_Final (digest, pValue);
	ring_vm_openssl_buf2hex (digest, SHA_DIGEST_LENGTH, cString);
	RING_API_RETSTRING(cString);
}

void ring_vm_openssl_sha1 ( void *pPointer )
{
	unsigned char digest[SHA_DIGEST_LENGTH]  ;
	char cString[SHA_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA1((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		ring_vm_openssl_buf2hex (digest, SHA_DIGEST_LENGTH, cString);
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha256_init ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		SHA256_CTX* pValue;
		pValue = (SHA256_CTX *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SHA256_CTX)) ;
		SHA256_Init (pValue);
		RING_API_RETMANAGEDCPOINTER(pValue,"SHA256_CTX",ring_state_free);
	}
}

void ring_vm_openssl_sha256_update ( void *pPointer )
{
	int x,nSize  ;
	char *cInput  ;
	SHA256_CTX* pValue ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (SHA256_CTX *) RING_API_GETCPOINTER(1,"SHA256_CTX");
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cInput = RING_API_GETSTRING(2) ;
	nSize = RING_API_GETSTRINGSIZE(2) ;
	RING_API_RETNUMBER(SHA256_Update(pValue, cInput, (unsigned long) nSize));
}

void ring_vm_openssl_sha256_final ( void *pPointer )
{
	unsigned char digest[SHA256_DIGEST_LENGTH]  ;
	char cString[SHA256_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	SHA256_CTX* pValue ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (SHA256_CTX *) RING_API_GETCPOINTER(1,"SHA256_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SHA256_Final (digest, pValue);
	ring_vm_openssl_buf2hex (digest, SHA256_DIGEST_LENGTH, cString);
	RING_API_RETSTRING(cString);
}

void ring_vm_openssl_sha256 ( void *pPointer )
{
	unsigned char digest[SHA256_DIGEST_LENGTH]  ;
	char cString[SHA256_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA256((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		ring_vm_openssl_buf2hex (digest, SHA256_DIGEST_LENGTH, cString);
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha512_init ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		SHA512_CTX* pValue;
		pValue = (SHA512_CTX *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SHA512_CTX)) ;
		SHA512_Init (pValue);
		RING_API_RETMANAGEDCPOINTER(pValue,"SHA512_CTX",ring_state_free);
	}
}

void ring_vm_openssl_sha512_update ( void *pPointer )
{
	int x,nSize  ;
	char *cInput  ;
	SHA512_CTX* pValue ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (SHA512_CTX *) RING_API_GETCPOINTER(1,"SHA512_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cInput = RING_API_GETSTRING(2) ;
	nSize = RING_API_GETSTRINGSIZE(2) ;
	RING_API_RETNUMBER(SHA512_Update(pValue, cInput, (unsigned long) nSize));
}

void ring_vm_openssl_sha512_final ( void *pPointer )
{
	unsigned char digest[SHA512_DIGEST_LENGTH]  ;
	char cString[SHA512_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	SHA512_CTX* pValue ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	pValue = (SHA512_CTX *) RING_API_GETCPOINTER(1,"SHA512_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SHA512_Final (digest, pValue);
	ring_vm_openssl_buf2hex (digest, SHA512_DIGEST_LENGTH, cString);
	RING_API_RETSTRING(cString);
}

void ring_vm_openssl_sha512 ( void *pPointer )
{
	unsigned char digest[SHA512_DIGEST_LENGTH]  ;
	char cString[SHA512_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA512((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		ring_vm_openssl_buf2hex (digest, SHA512_DIGEST_LENGTH, cString);
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha384_init ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		SHA512_CTX* pValue;
		pValue = (SHA512_CTX *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SHA512_CTX)) ;
		SHA384_Init (pValue);
		RING_API_RETMANAGEDCPOINTER(pValue,"SHA384_CTX",ring_state_free);
	}
}

void ring_vm_openssl_sha384_update ( void *pPointer )
{
	int x,nSize  ;
	char *cInput  ;
	SHA512_CTX* pValue ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (SHA512_CTX *) RING_API_GETCPOINTER(1,"SHA384_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cInput = RING_API_GETSTRING(2) ;
	nSize = RING_API_GETSTRINGSIZE(2) ;
	RING_API_RETNUMBER(SHA384_Update(pValue, cInput, (unsigned long) nSize));
}

void ring_vm_openssl_sha384_final ( void *pPointer )
{
	unsigned char digest[SHA384_DIGEST_LENGTH]  ;
	char cString[SHA384_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	SHA512_CTX* pValue ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	pValue = (SHA512_CTX *) RING_API_GETCPOINTER(1,"SHA384_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SHA384_Final (digest, pValue);
	ring_vm_openssl_buf2hex (digest, SHA384_DIGEST_LENGTH, cString);
	RING_API_RETSTRING(cString);
}

void ring_vm_openssl_sha384 ( void *pPointer )
{
	unsigned char digest[SHA384_DIGEST_LENGTH]  ;
	char cString[SHA384_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA384((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		ring_vm_openssl_buf2hex (digest, SHA384_DIGEST_LENGTH, cString);
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha224_init ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		SHA256_CTX* pValue;
		pValue = (SHA256_CTX *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SHA256_CTX)) ;
		SHA224_Init (pValue);
		RING_API_RETMANAGEDCPOINTER(pValue,"SHA224_CTX",ring_state_free);
	}
}

void ring_vm_openssl_sha224_update ( void *pPointer )
{
	int x,nSize  ;
	char *cInput  ;
	SHA256_CTX* pValue ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pValue = (SHA256_CTX *) RING_API_GETCPOINTER(1,"SHA224_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cInput = RING_API_GETSTRING(2) ;
	nSize = RING_API_GETSTRINGSIZE(2) ;
	RING_API_RETNUMBER(SHA224_Update(pValue, cInput, (unsigned long) nSize));
}

void ring_vm_openssl_sha224_final ( void *pPointer )
{
	unsigned char digest[SHA224_DIGEST_LENGTH]  ;
	char cString[SHA224_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	SHA256_CTX* pValue ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	pValue = (SHA256_CTX *) RING_API_GETCPOINTER(1,"SHA224_CTX") ;
	if ( ! pValue ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SHA224_Final (digest, pValue);
	ring_vm_openssl_buf2hex (digest, SHA224_DIGEST_LENGTH, cString);
	RING_API_RETSTRING(cString);
}

void ring_vm_openssl_sha224 ( void *pPointer )
{
	unsigned char digest[SHA224_DIGEST_LENGTH]  ;
	char cString[SHA224_DIGEST_LENGTH*2+1]  ;
	int nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA224((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		ring_vm_openssl_buf2hex (digest, SHA224_DIGEST_LENGTH, cString);
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_randbytes ( void *pPointer )
{
	unsigned char *cStr  ;
	int nNum1  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nNum1 = (int) RING_API_GETNUMBER(1) ;
		if ( nNum1 > 0 ) {
			cStr =  malloc(nNum1) ;
			if ( cStr == NULL ) {
				RING_API_ERROR(RING_OOM);
				return ;
			}
			if ( RAND_bytes(cStr,nNum1) ) {
				RING_API_RETSTRING2((const char *) cStr,nNum1);
			}
			else {
				RING_API_ERROR(RING_API_INTERNALFAILURE);
			}
			free(cStr);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

static void list_ciphers_fn(const OBJ_NAME *name, void *arg)
{
	const char *cStr = name->name ;
	const EVP_CIPHER *cipher;
    ListCipherArg* pCipherArg = (ListCipherArg*) arg;

    if (!islower((unsigned char)*cStr))
        return;
	
    /* Filter out ciphers that we cannot use */
    cipher = EVP_get_cipherbyname(cStr);
    if (cipher == NULL)
        return;

	/* add only if the string doesn't already exist in the list*/
	if ( (ring_list_getsize(pCipherArg->pList) == 0) || (ring_list_findstring(pCipherArg->pList,cStr,0) < 1) ) {
		ring_list_addstring_gc(((VM *) pCipherArg->pPointer)->pRingState,pCipherArg->pList,cStr);
	}

}

void ring_vm_openssl_list_ciphers ( void *pPointer )
{
	List *pList  ;
	ListCipherArg cipherArg;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	else {
		pList = RING_API_NEWLIST ;
		cipherArg.pList = pList;
		cipherArg.pPointer = pPointer;
		OBJ_NAME_do_all_sorted(OBJ_NAME_TYPE_CIPHER_METH, list_ciphers_fn, &cipherArg);
		RING_API_RETLIST(pList);
	}
}

