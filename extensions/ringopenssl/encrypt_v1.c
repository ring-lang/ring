/* Versions before OpenSSL 0.98 */

void ring_vm_openssl_encrypt ( void *pPointer )
{
	unsigned char *in, *out, *key, *iv  ;
	int nSize,buflen, tmplen, nSize2  ;
	EVP_CIPHER_CTX ctx  ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		in = (unsigned char *) RING_API_GETSTRING(1) ;
		key = (unsigned char *) RING_API_GETSTRING(2) ;
		iv = (unsigned char *) RING_API_GETSTRING(3) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		out = (unsigned char *) malloc(nSize*2) ;
		EVP_CIPHER_CTX_init(&ctx);
		EVP_EncryptInit_ex(&ctx, EVP_bf_cbc(), NULL, key, iv);
		if ( !EVP_EncryptUpdate(&ctx, out, &buflen, in, nSize) ) {
			free( out ) ;
			return ;
		}
		if ( !EVP_EncryptFinal_ex(&ctx, out + buflen, &tmplen) ) {
			free( out ) ;
			return ;
		}
		nSize2 = buflen + tmplen ;
		RING_API_RETSTRING2((const char *) out,nSize2);
		EVP_CIPHER_CTX_cleanup(&ctx);
		free( out ) ;
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_decrypt ( void *pPointer )
{
	unsigned char *in, *out, *key, *iv  ;
	int nSize,buflen, tmplen, nSize2  ;
	EVP_CIPHER_CTX ctx  ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		in = (unsigned char *) RING_API_GETSTRING(1) ;
		key = (unsigned char *) RING_API_GETSTRING(2) ;
		iv = (unsigned char *) RING_API_GETSTRING(3) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		out = (unsigned char *) malloc(nSize*2) ;
		EVP_CIPHER_CTX_init(&ctx);
		EVP_DecryptInit_ex(&ctx, EVP_bf_cbc(), NULL, key, iv);
		if ( !EVP_DecryptUpdate(&ctx, out, &buflen, in, nSize) ) {
			free( out ) ;
			return ;
		}
		if ( !EVP_DecryptFinal_ex(&ctx, out + buflen, &tmplen) ) {
			free( out ) ;
			return ;
		}
		nSize2 = buflen + tmplen ;
		RING_API_RETSTRING2((const char *) out,nSize2);
		EVP_CIPHER_CTX_cleanup(&ctx);
		free( out ) ;
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
