/* Version OpenSSL 0.9.8 and Later */

/* function defintion: encrypt (input, key, iv [, cipherName])
 * cipherName is optional. If it is not specified, Blowfish-CBC is used.
 * cipherName specifies the algorithm to use. It uses OpenSSL nomenclature
 * Typical cipherName values: "bf", "des", "des3", "aes128", "aes192", "aes256" which all use CBC mode
 *
 */ 
void ring_vm_openssl_encrypt ( void *pPointer )
{
	unsigned char *in, *out, *key, *iv  ;
	char* sCipherName;
	int nSize,buflen, tmplen, nSize2, nKeySize, nIVSize  ;
	/* we use Blowfish-CBC by default for compatibility */
	const EVP_CIPHER *cipherType = EVP_bf_cbc();
	EVP_CIPHER_CTX *ctx  ;
	if ( RING_API_PARACOUNT < 3 || RING_API_PARACOUNT > 4 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		in = (unsigned char *) RING_API_GETSTRING(1) ;
		key = (unsigned char *) RING_API_GETSTRING(2) ;
		nKeySize = RING_API_GETSTRINGSIZE(2) ;
		iv = (unsigned char *) RING_API_GETSTRING(3) ;
		nIVSize = RING_API_GETSTRINGSIZE(3) ;
		
		if ( RING_API_PARACOUNT == 4) {
			/* Use specified cipher name */
			if ( !RING_API_ISSTRING(4) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return ;
			}
			
			/* ignore if it is null */
			if (RING_API_GETSTRINGSIZE(4)) {
				sCipherName = (char*) RING_API_GETSTRING(4) ;

				cipherType = EVP_get_cipherbyname (sCipherName);
				if (cipherType == NULL) {
					/* the cipher name is not recognized */
					RING_API_ERROR(RING_API_BADPARAVALUE);
					return ;
				}
			}
		}
		
		/* check that the passed IV has correct length */
		if (nIVSize < EVP_CIPHER_iv_length(cipherType)) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}

		ctx = EVP_CIPHER_CTX_new();
		if ( ctx == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		
		/* set the cypher to use, its key length and then initialize its key and IV */
		if (!EVP_EncryptInit_ex(ctx, cipherType, NULL, NULL, NULL) ||
			!EVP_CIPHER_CTX_set_key_length(ctx, nKeySize) ||
			!EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv)) {
			EVP_CIPHER_CTX_free(ctx);
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return ;
		}

		nSize = RING_API_GETSTRINGSIZE(1) ;
		/* Allow enough space in output buffer for additional block */
		out = (unsigned char *) RING_API_MALLOC (nSize + EVP_MAX_BLOCK_LENGTH + 64); // 64 is for maximum tag length when using GCM/CCM mode
		if ( out == NULL ) {
			EVP_CIPHER_CTX_free(ctx);
			RING_API_ERROR(RING_OOM);
			return ;
		}
		
		if ( EVP_EncryptUpdate(ctx, out, &buflen, in, nSize) && EVP_EncryptFinal_ex(ctx, out + buflen, &tmplen)) {
			nSize2 = buflen + tmplen ;
			RING_API_RETSTRING2((const char *) out,nSize2);
		}
		else {
			RING_API_ERROR(RING_API_INTERNALFAILURE);
		}
		RING_API_FREE( out ) ;
		EVP_CIPHER_CTX_free(ctx);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_decrypt ( void *pPointer )
{
	unsigned char *in, *out, *key, *iv  ;
	const char* sCipherName;
	int nSize,buflen, tmplen, nSize2, nKeySize, nIVSize  ;
	/* we use Blowfish-CBC by default for compatibility */
	const EVP_CIPHER *cipherType = EVP_bf_cbc();
	EVP_CIPHER_CTX *ctx  ;
	if ( RING_API_PARACOUNT < 3 || RING_API_PARACOUNT > 4 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		in = (unsigned char *) RING_API_GETSTRING(1) ;
		key = (unsigned char *) RING_API_GETSTRING(2) ;
		nKeySize = RING_API_GETSTRINGSIZE(2) ;
		iv = (unsigned char *) RING_API_GETSTRING(3) ;
		nIVSize = RING_API_GETSTRINGSIZE(3) ;
		
		if ( RING_API_PARACOUNT == 4) {
			/* Use specified cipher name */
			if ( !RING_API_ISSTRING(4) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return ;
			}
			
			/* ignore if it is null */
			if (RING_API_GETSTRINGSIZE(4)) {
				sCipherName = (char*) RING_API_GETSTRING(4) ;

				cipherType = EVP_get_cipherbyname (sCipherName);
				if (cipherType == NULL) {
					/* the cipher name is not recognized */
					RING_API_ERROR(RING_API_BADPARAVALUE);
					return ;
				}
			}
		}
		
		/* check that the passed IV has correct length */
		if (nIVSize < EVP_CIPHER_iv_length(cipherType)) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}

		ctx = EVP_CIPHER_CTX_new();
		if ( ctx == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		
		/* set the cypher to use, its key length and then initialize its key and IV */
		if (!EVP_DecryptInit_ex(ctx, cipherType, NULL, NULL, NULL) ||
			!EVP_CIPHER_CTX_set_key_length(ctx, nKeySize) ||
			!EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv)) {
			EVP_CIPHER_CTX_free(ctx);
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return ;
		}

		nSize = RING_API_GETSTRINGSIZE(1) ;
		/* Allow enough space in output buffer for additional block */
		out = (unsigned char *) RING_API_MALLOC (nSize + EVP_MAX_BLOCK_LENGTH + 64); // 64 is for maximum tag length when using GCM/CCM mode
		if ( out == NULL ) {
			EVP_CIPHER_CTX_free(ctx);
			RING_API_ERROR(RING_OOM);
			return ;
		}
		
		if ( EVP_DecryptUpdate(ctx, out, &buflen, in, nSize) && EVP_DecryptFinal_ex(ctx, out + buflen, &tmplen)) {
			nSize2 = buflen + tmplen ;
			RING_API_RETSTRING2((const char *) out,nSize2);
		}
		else {
			RING_API_ERROR(RING_API_INTERNALFAILURE);
		}
		RING_API_FREE( out ) ;
		EVP_CIPHER_CTX_free(ctx);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
