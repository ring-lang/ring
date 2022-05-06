/* Version OpenSSL 0.9.8 and Later */

/* implementation of RSA functions
 * Author: Mounir IDRASSI (mounir@idrix.fr)
 * First version: April 23rd 2022
 */
 
static void ring_vm_openssl_pkeyfree( void *pRingState,void *pPointer )
{
    EVP_PKEY *pKey  ;
    pKey = (EVP_PKEY *) pPointer ;
    EVP_PKEY_free( pKey ) ;
}

static unsigned char ring_vm_openssl_hex2nibble(char cVal)
{
	unsigned char bVal = 0;
	if (cVal >= '0' && cVal <= '9') {
		bVal = cVal - '0';
	}
	else if (cVal >= 'a' && cVal <= 'f') {
		bVal = cVal - 'a' + 10;
	}
	else if (cVal >= 'A' && cVal <= 'F') {
		bVal = cVal - 'A' + 10;
	}
	else {
		bVal = 0xFF;
	}
	return bVal;
}

static int ring_vm_openssl_hex2buf (const char* cStr, unsigned char* pData)
{
	size_t x, nLen = strlen(cStr);
	unsigned char bNibble,bVal ;
	int i;
	i = 0;
	for ( x = 0 ; x < nLen ; x+=2 ) {
		bNibble = ring_vm_openssl_hex2nibble(cStr[x]);
		if ( bNibble != 0xFF ) {
			bVal = bNibble ;
			bNibble = ring_vm_openssl_hex2nibble(cStr[x+1]);
			if ( bNibble != 0xFF ) {
				bVal = (bVal << 4) + bNibble ;
			}
		}
		if ( bNibble == 0xFF ) {
			return 0;
		}
		pData[i] = (unsigned char) bVal ;
		i++ ;
	}
	
	return i;
}

void ring_vm_openssl_rsa_generate ( void *pPointer )
{
	EVP_PKEY *pKey ;
	BIGNUM *e ;
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX *ctx;
	#else
	RSA *pRsa  ;
	#endif
	int nBits, nPubExp=65537;/* we use 65537 as default exponent */
	if ( RING_API_PARACOUNT != 1 && RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	nBits = (int) RING_API_GETNUMBER(1) ;
	
	if (nBits < 512 || nBits > OPENSSL_RSA_MAX_MODULUS_BITS) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	if ( RING_API_PARACOUNT == 2 ) {
		if ( ! RING_API_ISNUMBER(2) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return ;
		}
		
		nPubExp = (int) RING_API_GETNUMBER(2) ;
		
		if (nPubExp < 3) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return ;
		}
	}
	
	e = BN_new();
	BN_set_word (e,nPubExp);
	pKey = NULL;
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
	if (ctx) {
		if ( (EVP_PKEY_keygen_init(ctx) > 0) 
			&& (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, nBits) > 0) 
			&& (EVP_PKEY_CTX_set_rsa_keygen_pubexp(ctx, e) > 0) ) {
            /* e belongs now to ctx so we should not free it */
            e = NULL;
			/* perform RSA key generation */
			if (EVP_PKEY_keygen(ctx, &pKey) <= 0) {
				/* failure */
				pKey = NULL;
			}
		}
		
		EVP_PKEY_CTX_free(ctx);
	}
	#else
	pRsa = RSA_new() ;
	if (RSA_generate_key_ex(pRsa,nBits,e,NULL)) {
		pKey = EVP_PKEY_new();
		EVP_PKEY_assign_RSA(pKey, pRsa); /* pRsa is now owned by pKey */
	}
	else {
		RSA_free(pRsa);
	}
	#endif
	
	if (pKey) {
		/* success case: return the object */
		RING_API_RETMANAGEDCPOINTER(pKey,"OSSL_PKEY",ring_vm_openssl_pkeyfree);
	}
	else {
		RING_API_ERROR(RING_API_INTERNALFAILURE);
	}
	if (e) {
        BN_free(e);
    }
}

void ring_vm_openssl_rsa_is_privatekey ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	RSA *pRsa  ;
	const BIGNUM *p,*q,*dmp1,*dmq1,*iqmp,*n,*e,*d;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	pRsa = EVP_PKEY_get1_RSA(pKey);
	
	/* export all parameters */
	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	n = RSA_get0_n(pRsa);
	e = RSA_get0_e(pRsa);
	d = RSA_get0_d(pRsa);
	p = RSA_get0_p(pRsa);
	q = RSA_get0_q(pRsa);
	dmp1 = RSA_get0_dmp1(pRsa);
	dmq1 = RSA_get0_dmq1(pRsa);
	iqmp = RSA_get0_iqmp(pRsa);
	#else
	n = pRsa->n;
	e = pRsa->e;
	d = pRsa->d;
	p = pRsa->p;
	q = pRsa->q;
	dmp1 = pRsa->dmp1;
	dmq1 = pRsa->dmq1;
	iqmp = pRsa->iqmp;
	#endif
	
	if (!n || !e) {
		/* modulus and public exponent must always be present */
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	else if (d || (p && q && dmp1 && dmq1 && iqmp)) {
		/* this is private key */
		RING_API_RETNUMBER(1);
	}
	else {
		/* this is a public key */
		RING_API_RETNUMBER(0);
	}

	RSA_free(pRsa);
}

static void ring_vm_openssl_add_bignum_to_list( void *pPointer, const char* cComponentName, const BIGNUM* pComponent, List* pList, unsigned char* pBuf )
{
	char* cStr;
	List* pSubList;
	
	pSubList = ring_list_newlist_gc(((VM *) pPointer)->pRingState,pList);
	/* first add component name, then add component value */
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pSubList,cComponentName);
	if (pComponent) {
		cStr = BN_bn2hex(pComponent);
		ring_list_addstring_gc(((VM *) pPointer)->pRingState,pSubList,cStr);
	}
	else {
		/* add empty string */
		ring_list_addstring_gc(((VM *) pPointer)->pRingState,pSubList,"");
	}
}

static void ring_vm_openssl_add_bits_to_list( void *pPointer, int nBits, List* pList )
{
	List* pSubList;
	
	pSubList = ring_list_newlist_gc(((VM *) pPointer)->pRingState,pList);
	/* first add component name, then add component value */
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pSubList,"bits");
	ring_list_adddouble_gc(((VM *) pPointer)->pRingState,pSubList, (double) nBits);
}

static void ring_vm_openssl_add_keytype_to_list( void *pPointer, const char* cKeyType, List* pList )
{
	List* pSubList;
	
	pSubList = ring_list_newlist_gc(((VM *) pPointer)->pRingState,pList);
	/* first add component name, then add component value */
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pSubList,"type");
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pSubList,cKeyType);
}

void ring_vm_openssl_rsa_export_params ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	RSA *pRsa  ;
	const BIGNUM *p,*q,*dmp1,*dmq1,*iqmp,*n,*e,*d;
	List *pList  ;
	int nBits;
	unsigned char* pBuf;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	pRsa = EVP_PKEY_get1_RSA(pKey);
	
	/* export all parameters */
	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	n = RSA_get0_n(pRsa);
	e = RSA_get0_e(pRsa);
	d = RSA_get0_d(pRsa);
	p = RSA_get0_p(pRsa);
	q = RSA_get0_q(pRsa);
	dmp1 = RSA_get0_dmp1(pRsa);
	dmq1 = RSA_get0_dmq1(pRsa);
	iqmp = RSA_get0_iqmp(pRsa);
	#else
	n = pRsa->n;
	e = pRsa->e;
	d = pRsa->d;
	p = pRsa->p;
	q = pRsa->q;
	dmp1 = pRsa->dmp1;
	dmq1 = pRsa->dmq1;
	iqmp = pRsa->iqmp;
	#endif
	
	nBits = BN_num_bits(n);
	
	/* allocate a buffer that is enough to encode all components */
	pBuf = (unsigned char*) RING_API_MALLOC(BN_num_bytes(n));
	if (pBuf) {
		pList = RING_API_NEWLIST;

		ring_vm_openssl_add_bits_to_list(pPointer, nBits, pList);
		ring_vm_openssl_add_keytype_to_list(pPointer, "RSA", pList);
		ring_vm_openssl_add_bignum_to_list(pPointer, "n", n, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "e", e, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "d", d, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "p", p, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "q", q, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "dmp1", dmp1, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "dmq1", dmq1, pList, pBuf);
		ring_vm_openssl_add_bignum_to_list(pPointer, "iqmp", iqmp, pList, pBuf);

		RING_API_FREE(pBuf);
		RING_API_RETLIST(pList);		
	}
	else {
		RING_API_ERROR(RING_OOM);
	}
	
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_export_pem ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	RSA *pRsa  ;
	const BIGNUM *p,*q,*dmp1,*dmq1,*iqmp,*n,*e,*d;
	BIO *bio;
	int nSize,nStatus;
	char* cStr;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	pRsa = EVP_PKEY_get1_RSA(pKey);
	
	/* export all parameters */
	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	n = RSA_get0_n(pRsa);
	e = RSA_get0_e(pRsa);
	d = RSA_get0_d(pRsa);
	p = RSA_get0_p(pRsa);
	q = RSA_get0_q(pRsa);
	dmp1 = RSA_get0_dmp1(pRsa);
	dmq1 = RSA_get0_dmq1(pRsa);
	iqmp = RSA_get0_iqmp(pRsa);
	#else
	n = pRsa->n;
	e = pRsa->e;
	d = pRsa->d;
	p = pRsa->p;
	q = pRsa->q;
	dmp1 = pRsa->dmp1;
	dmq1 = pRsa->dmq1;
	iqmp = pRsa->iqmp;
	#endif
	
	/* n and e must not be NULL */
	if (!n || !e) {
		RSA_free(pRsa);
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}
	
	bio = BIO_new(BIO_s_mem());
	
	if (d || (p && q && dmp1 && dmq1 && iqmp)) {
		/* this is a private key */
		nStatus = PEM_write_bio_PrivateKey(bio, pKey, NULL, NULL, 0, 0, NULL);
	}
	else {
		/* this is a public key */
		nStatus = PEM_write_bio_PUBKEY(bio, pKey);
	}
	
	if (  nStatus > 0 ) {
		nSize = (int) BIO_pending(bio);
        /* Pre-allocated the return value on the stack */
        RING_API_RETSTRINGSIZE(nSize);
        cStr = ring_string_get(RING_API_GETSTRINGRAW);
		BIO_read(bio, cStr, nSize);
		BIO_free_all(bio);
	}
	else {
		/* OpenSSL error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_import_params ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	RSA *pRsa  ;
	BIGNUM *p=NULL,*q=NULL,*dmp1=NULL,*dmq1=NULL,*iqmp=NULL,*n=NULL,*e=NULL,*d=NULL;
	BIGNUM **targetComponent;
	List *pList,*pSubList  ;
	int x,nSize,nFailed,nBufSize;
	char* cStrIndex;
	unsigned char* pBuf;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISLIST(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pList = RING_API_GETLIST(1);
	nSize = ring_list_getsize(pList);
	/* the minimal list is the one container the modulus and public exponent */
	if ( nSize < 2) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	/* check that each element of the list is a list that has two string elements */
	nFailed = 0;
	for ( x = 1; x <= nSize ; x++ ) {
		if ( !ring_list_islist(pList,x) ) {
			nFailed = 1;
			break ;
		}
		
		pSubList = ring_list_getlist(pList,x);
		if ( ring_list_getsize(pSubList) != 2 ) {
			nFailed = 1;
			break ;
		}
		if ( !ring_list_isstring(pSubList,1)) {
			nFailed = 1;
			break;
		}
		if ( !ring_list_isstring(pSubList,2)) {
			continue;
		}

		cStrIndex = (char*) ring_list_getstring(pSubList,1);
		pBuf = (unsigned char*) ring_list_getstring(pSubList,2);
		nBufSize = (int) ring_list_getstringsize(pSubList,2);
		
		/* skip if the entry is empty */
		if ( (*cStrIndex == 0) || (nBufSize == 0) ) {
			continue;
		}
		
		/* look for RSA components by name */
		if ( strcmp(cStrIndex,"n") == 0) {
			targetComponent = &n;
		}
		else if (strcmp(cStrIndex,"e") == 0) {
			targetComponent = &e;
		}
		else if (strcmp(cStrIndex,"d") == 0) {
			targetComponent = &d;
		}
		else if (strcmp(cStrIndex,"p") == 0) {
			targetComponent = &p;
		}
		else if (strcmp(cStrIndex,"q") == 0) {
			targetComponent = &q;
		}
		else if (strcmp(cStrIndex,"dmp1") == 0) {
			targetComponent = &dmp1;
		}
		else if (strcmp(cStrIndex,"dmq1") == 0) {
			targetComponent = &dmq1;
		}
		else if (strcmp(cStrIndex,"iqmp") == 0) {
			targetComponent = &iqmp;
		}
		else {
			targetComponent = NULL;
		}
		
		if (targetComponent) {
			/* if we have been already allocated, then return error since it means there is 
			 * a duplicated entry in the list
			 */
			if ( *targetComponent )
			{
				nFailed = 1;
				break;				
			}

			if ( !BN_hex2bn(targetComponent, (const char*) (pBuf)) ) {
				nFailed = 1;
				break;
			}
		}
	}
	
	/* n and e must be set */
	if ( (nFailed == 0) && (!n || !e) )
	{
		nFailed = 1;
	}
	
	if ( nFailed == 0) {
		/* create the key */
		pRsa = RSA_new() ;
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		RSA_set0_key(pRsa,n,e,d);
		RSA_set0_factors(pRsa,p,q);
		RSA_set0_crt_params(pRsa,dmp1,dmq1,iqmp);
		#else
		pRsa->n = n;
		pRsa->e = e;
		pRsa->d = d;
		pRsa->p = p;
		pRsa->q = q;
		pRsa->dmp1 = dmp1;
		pRsa->dmq1 = dmq1;
		pRsa->iqmp = iqmp;
		#endif
		/* memory management transfered to RSA object */
		n = NULL;
		e = NULL;
		d = NULL;
		p = NULL;
		q = NULL;
		dmp1 = NULL;
		dmq1 = NULL;
		iqmp = NULL;
		
		pKey = EVP_PKEY_new();
		EVP_PKEY_assign_RSA(pKey, pRsa); /* pRsa is now owned by pKey */
		/* success case: return the object */
		RING_API_RETMANAGEDCPOINTER(pKey,"OSSL_PKEY",ring_vm_openssl_pkeyfree);
	}
	else
	{
		RING_API_ERROR(RING_API_BADPARAVALUE);
	}
	
	if (n) BN_free(n);
	if (e) BN_free(e);
	if (d) BN_free(d);
	if (p) BN_free(p);
	if (q) BN_free(q);
	if (dmp1) BN_free(dmp1);
	if (dmq1) BN_free(dmq1);
	if (iqmp) BN_free(iqmp);
}

void ring_vm_openssl_rsa_import_pem ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	char* cStr;
	int nSize;
	BIO *bio;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	cStr = RING_API_GETSTRING(1);
	nSize = RING_API_GETSTRINGSIZE(1);
	if ( nSize < 2) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	bio = BIO_new(BIO_s_mem());
	BIO_write(bio, cStr, nSize);
	pKey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
	BIO_free_all(bio);
	
	if (!pKey) {
		/* try public key import */
		bio = BIO_new(BIO_s_mem());
		BIO_write(bio, cStr, nSize);
		pKey = PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);
		BIO_free_all(bio);
	}
	
	if (!pKey) {
		/* invalid PEM */
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		EVP_PKEY_free(pKey);
		RING_API_ERROR(RING_API_BADPARAVALUE);
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		EVP_PKEY_free(pKey);
		RING_API_ERROR(RING_API_BADPARAVALUE);
	}
	#endif
	
	/* success case: return the object */
	RING_API_RETMANAGEDCPOINTER(pKey,"OSSL_PKEY",ring_vm_openssl_pkeyfree);
}

void ring_vm_openssl_rsa_encrypt_pkcs ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	RSA *pRsa = NULL  ;
	int nSize, nModulusLen;
	unsigned char *cInput, *cOutput;
	if ( RING_API_PARACOUNT != 2  ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);
	
	/* input size must be less than modulusLen - 11 */
	if ( nSize > (nModulusLen - 11) ) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}
	
	pRsa = EVP_PKEY_get1_RSA(pKey);
	
	if (RSA_public_encrypt(nSize, cInput,cOutput,pRsa,RSA_PKCS1_PADDING) != nModulusLen) {
		/* OpenSSL error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	else {
		RING_API_RETSTRING2((const char*) cOutput,nModulusLen);
	}
	
	
	RING_API_FREE(cOutput);
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_decrypt_pkcs ( void *pPointer )
{
	EVP_PKEY *pKey = NULL;
	RSA *pRsa = NULL  ;
	int nSize, nModulusLen, nOutput;
	unsigned char *cInput, *cOutput;
	if ( RING_API_PARACOUNT != 2  ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);
	
	/* input size must be equal to modulusLen*/
	if ( nSize != nModulusLen ) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}
	
	pRsa = EVP_PKEY_get1_RSA(pKey);
	
	nOutput = RSA_private_decrypt(nSize, cInput,cOutput,pRsa,RSA_PKCS1_PADDING);
	
	if ( nOutput < 0 ) {
		/* OpenSSL error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	else {
		RING_API_RETSTRING2((const char*) cOutput,nOutput);
	}
	
	
	RING_API_FREE(cOutput);
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_encrypt_oaep ( void *pPointer )
{
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX *ctx ;
    size_t nOutput ;
    int nStatus ;
	#else
	RSA *pRsa ;
    int nOutput ;
	#endif
	EVP_PKEY *pKey ;
	const EVP_MD *md ;
	int nSize,nModulusLen,nMgfHashAlg;
	unsigned char *cInput, *cOutput;
	if ( RING_API_PARACOUNT != 2 && RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	if ( (RING_API_PARACOUNT == 3) && ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	if (RING_API_PARACOUNT == 3) {
		nMgfHashAlg = (int) RING_API_GETNUMBER(3);
	}
	else {
		/* use SHA1 by default */
		nMgfHashAlg = OSSL_OAEP_SHA1;
	}
	
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	switch (nMgfHashAlg) {
	case OSSL_OAEP_MD5: md = EVP_md5(); break;
	case OSSL_OAEP_SHA1: md = EVP_sha1(); break;
	case OSSL_OAEP_SHA256: md = EVP_sha256(); break;
	case OSSL_OAEP_SHA384: md = EVP_sha384(); break;
	case OSSL_OAEP_SHA512: md = EVP_sha512(); break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	#else
	/* we support only SHA1 for old OpenSSL */
	if (nMgfHashAlg != OSSL_OAEP_SHA1) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	md = EVP_sha1();
	#endif
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);
	
	/* input size for OAEP must be less than modulusLen - (2*hashSize) - 2 */
	if ( nSize > (nModulusLen - (2 * EVP_MD_size(md)) - 2) ) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	nOutput = (size_t) nModulusLen;
	ctx = EVP_PKEY_CTX_new(pKey,NULL);
	if ( 	(EVP_PKEY_encrypt_init(ctx) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_oaep_md(ctx, md) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_mgf1_md(ctx, md) > 0)
		) {
		nStatus = EVP_PKEY_encrypt(ctx, cOutput, &nOutput, cInput, nSize);
		if (  nStatus <= 0 ) {
			/* error occured */
			RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETSTRING2((const char*) cOutput,nModulusLen);
		}
	}
	else {
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nOutput = RSA_public_encrypt(nSize, cInput,cOutput,pRsa,RSA_PKCS1_OAEP_PADDING);
	if ( nOutput == nModulusLen) {
		RING_API_RETSTRING2((const char*) cOutput,nModulusLen);
	}
	else {
		/* error occured */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#endif


	RING_API_FREE(cOutput);
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
	#else
	RSA_free(pRsa);
	#endif
}

void ring_vm_openssl_rsa_decrypt_oaep ( void *pPointer )
{
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	const EVP_MD *md;
	EVP_PKEY_CTX *ctx;
    size_t nOutput ;
	#else
	RSA *pRsa ;
    int nOutput ;
	#endif
	EVP_PKEY *pKey;
	int nSize,nModulusLen,nMgfHashAlg;
	unsigned char *cInput, *cOutput;
	if ( RING_API_PARACOUNT != 2 && RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	if ( (RING_API_PARACOUNT == 3) && ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif
	
	if (RING_API_PARACOUNT == 3) {
		nMgfHashAlg = (int) RING_API_GETNUMBER(3);
	}
	else {
		/* use SHA1 by default */
		nMgfHashAlg = OSSL_OAEP_SHA1;
	}
	
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	switch (nMgfHashAlg) {
	case OSSL_OAEP_MD5: md = EVP_md5(); break;
	case OSSL_OAEP_SHA1: md = EVP_sha1(); break;
	case OSSL_OAEP_SHA256: md = EVP_sha256(); break;
	case OSSL_OAEP_SHA384: md = EVP_sha384(); break;
	case OSSL_OAEP_SHA512: md = EVP_sha512(); break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	#else
	/* we support only SHA1 for old OpenSSL */
	if (nMgfHashAlg != OSSL_OAEP_SHA1) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	#endif
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);
	
	/* input size must be equal to modulusLen */
	if ( nSize != nModulusLen ) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return ;
	}
	
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	nOutput = (size_t) nModulusLen;
	ctx = EVP_PKEY_CTX_new(pKey,NULL);
	if ( 	(EVP_PKEY_decrypt_init(ctx) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_oaep_md(ctx, md) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_mgf1_md(ctx, md) > 0)
		) {
		if ( EVP_PKEY_decrypt(ctx, cOutput, &nOutput, cInput, (size_t) nSize) <= 0 ) {
			/* error occured */
			RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETSTRING2((const char*) cOutput,(int) nOutput);
		}
	}
	else {
		/* error occured */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nOutput = RSA_private_decrypt(nSize, cInput,cOutput,pRsa,RSA_PKCS1_OAEP_PADDING);
	if ( nOutput < 0 ) {
		/* unexpected error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	else {
		RING_API_RETSTRING2((const char*) cOutput,nOutput);
	}
	#endif

	RING_API_FREE(cOutput);
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
	#else
	RSA_free(pRsa);
	#endif
}

void ring_vm_openssl_rsa_encrypt_raw(void* pPointer)
{
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX* ctx;
	size_t nOutput;
	int nStatus;
#else
	RSA* pRsa;
	int nOutput;
#endif
	EVP_PKEY* pKey;
	int nSize, nModulusLen;
	unsigned char* cInput, * cOutput;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	pKey = (EVP_PKEY*)RING_API_GETCPOINTER(1, "OSSL_PKEY");
	if (pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	/* check that this is indeed an RSA key */
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#endif

	cInput = (unsigned char*)RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);

	/* input size for RSA RAW must be equal to modulusLen */
	if (nSize != nModulusLen) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	cOutput = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cOutput == NULL) {
		RING_API_ERROR(RING_OOM);
		return;
	}

#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	nOutput = (size_t)nModulusLen;
	ctx = EVP_PKEY_CTX_new(pKey, NULL);
	if ((EVP_PKEY_encrypt_init(ctx) > 0)
		&& (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_NO_PADDING) > 0)
		) {
		nStatus = EVP_PKEY_encrypt(ctx, cOutput, &nOutput, cInput, nSize);
		if (nStatus <= 0) {
			/* error occured */
			RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETSTRING2((const char*)cOutput, nModulusLen);
		}
	}
	else {
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
	}
#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nOutput = RSA_public_encrypt(nSize, cInput, cOutput, pRsa, RSA_NO_PADDING);
	if (nOutput == nModulusLen) {
		RING_API_RETSTRING2((const char*)cOutput, nModulusLen);
	}
	else {
		/* error occured */
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
	}
#endif


	RING_API_FREE(cOutput);
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
#else
	RSA_free(pRsa);
#endif
}

void ring_vm_openssl_rsa_decrypt_raw(void* pPointer)
{
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX* ctx;
	size_t nOutput;
#else
	RSA* pRsa;
	int nOutput;
#endif
	EVP_PKEY* pKey;
	int nSize, nModulusLen;
	unsigned char* cInput, * cOutput;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	pKey = (EVP_PKEY*)RING_API_GETCPOINTER(1, "OSSL_PKEY");
	if (pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	/* check that this is indeed an RSA key */
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#endif

	cInput = (unsigned char*)RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);

	/* input size must be equal to modulusLen */
	if (nSize != nModulusLen) {
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	cOutput = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cOutput == NULL) {
		RING_API_ERROR(RING_OOM);
		return;
	}

#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	nOutput = (size_t)nModulusLen;
	ctx = EVP_PKEY_CTX_new(pKey, NULL);
	if ((EVP_PKEY_decrypt_init(ctx) > 0)
		&& (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_NO_PADDING) > 0)
		) {
		if (EVP_PKEY_decrypt(ctx, cOutput, &nOutput, cInput, (size_t)nSize) <= 0) {
			/* error occured */
			RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETSTRING2((const char*)cOutput, (int)nOutput);
		}
	}
	else {
		/* error occured */
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
	}
#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nOutput = RSA_private_decrypt(nSize, cInput, cOutput, pRsa, RSA_NO_PADDING);
	if (nOutput < 0) {
		/* unexpected error */
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
	}
	else {
		RING_API_RETSTRING2((const char*)cOutput, nOutput);
	}
#endif

	RING_API_FREE(cOutput);
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
#else
	RSA_free(pRsa);
#endif
}


void ring_vm_openssl_rsa_sign_pkcs ( void *pPointer )
{
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX *ctx;
    size_t nOutput ;
	#else
	RSA *pRsa ;
    int nOutput ;
	#endif
	EVP_PKEY *pKey;
	int nSize,nModulusLen;
	unsigned char *cInput, *cOutput;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif	
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	nModulusLen = EVP_PKEY_size(pKey);
	
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	nOutput = (size_t) nModulusLen;
	ctx = EVP_PKEY_CTX_new(pKey,NULL);
	if ( 	(EVP_PKEY_sign_init(ctx) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) > 0)
		) {
		if ( EVP_PKEY_sign(ctx, cOutput, &nOutput, cInput, (size_t) nSize) <= 0 ) {
			/* error occured */
			RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETSTRING2((const char*) cOutput,(int) nOutput);
		}
	}
	else {
		/* error occured */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nOutput = RSA_private_encrypt(nSize, cInput,cOutput,pRsa,RSA_PKCS1_PADDING);
	if ( nOutput < 0 ) {
		/* unexpected error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	else {
		RING_API_RETSTRING2((const char*) cOutput,nOutput);
	}
	#endif

	RING_API_FREE(cOutput);
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
	#else
	RSA_free(pRsa);
	#endif
}

void ring_vm_openssl_rsa_signhash_pkcs ( void *pPointer )
{
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX *ctx;
    size_t nOutput ;
	#else
	RSA *pRsa ;
    unsigned int nOutput ;
	#endif
	EVP_PKEY *pKey;
	const EVP_MD* md;
	int nSize,nModulusLen,nDigest;
	unsigned char *cInput, *cOutput, cDigest[64];
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif	
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	/* the input must be a hash from a supported algorithm */
	/* we support both raw digest and hexadecimal digest */
	switch (nSize) {
	case 16: md = EVP_md5(); break;
	case 20: md = EVP_sha1(); break;
	case 32: 
		/* either MD5 in hexadecimal or raw SHA256 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 16) {
			cInput = cDigest;
			nSize = 16;
			md = EVP_md5();
		}
		else {
			md = EVP_sha256();
		}
		break;
	case 40: 
		/* SHA1 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 20) {
			cInput = cDigest;
			nSize = 20;
			md = EVP_sha1();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 48: md = EVP_sha384(); break;
	case 64:
		/* either SHA256 in hexadecimal or raw SHA512 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 32) {
			cInput = cDigest;
			nSize = 32;
			md = EVP_sha256();
		}
		else {
			md = EVP_sha512();
		}
		break;
	case 96:
		/* SHA384 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 48) {
			cInput = cDigest;
			nSize = 48;
			md = EVP_sha384();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 128:
		/* SHA512 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 64) {
			cInput = cDigest;
			nSize = 64;
			md = EVP_sha512();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	nModulusLen = EVP_PKEY_size(pKey);
	
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	nOutput = (size_t) nModulusLen;
	ctx = EVP_PKEY_CTX_new(pKey,NULL);
	if ( 	(EVP_PKEY_sign_init(ctx) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) > 0)
		&&	(EVP_PKEY_CTX_set_signature_md(ctx, md) > 0)
		) {
		if ( EVP_PKEY_sign(ctx, cOutput, &nOutput, cInput, (size_t) nSize) <= 0 ) {
			/* error occured */
			RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETSTRING2((const char*) cOutput,(int) nOutput);
		}
	}
	else {
		/* error occured */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	if ( RSA_sign(EVP_MD_type(md),cInput,(unsigned int)nSize,cOutput,&nOutput,pRsa) != 1 ) {
		/* unexpected error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	else {
		RING_API_RETSTRING2((const char*) cOutput,(int)nOutput);
	}
	#endif

	RING_API_FREE(cOutput);
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
	#else
	RSA_free(pRsa);
	#endif
}

void ring_vm_openssl_rsa_verify_pkcs ( void *pPointer )
{
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX *ctx;
	int nStatus;
	#else
	RSA *pRsa ;
	unsigned char *cOutput;
    int nOutput ;
	#endif
	EVP_PKEY *pKey;
	int nSize,nModulusLen,nSignature;
	unsigned char *cInput, *cSignature;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) || ! RING_API_ISSTRING(3)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif	
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);
	
	cSignature = (unsigned char*) RING_API_GETSTRING(3);
	nSignature = RING_API_GETSTRINGSIZE(3);

	nModulusLen = EVP_PKEY_size(pKey);

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	ctx = EVP_PKEY_CTX_new(pKey,NULL);
	if ( 	(EVP_PKEY_verify_init(ctx) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) > 0)
		) {
		nStatus = EVP_PKEY_verify(ctx, cSignature, (size_t) nSignature, cInput, (size_t) nSize);
		if ( nStatus < 0 ) {
			/* error occured */
			RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETNUMBER(nStatus);
		}
	}
	else {
		/* error occured */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#else
	cOutput = (unsigned char*) RING_API_MALLOC(nModulusLen);
	if ( cOutput == NULL ) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	pRsa = EVP_PKEY_get1_RSA(pKey);
	nOutput = RSA_public_decrypt(nSignature, cSignature,cOutput,pRsa,RSA_PKCS1_PADDING);
	if ( nOutput < 0 ) {
		/* unexpected error */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	else {
		if (nOutput == nSize && 0 == memcmp(cOutput, cInput, nSize)) {
			RING_API_RETNUMBER(1);
		}
		else {
			RING_API_RETNUMBER(0);
		}
	}
	#endif

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
	#else
	RING_API_FREE(cOutput);
	RSA_free(pRsa);
	#endif
}

void ring_vm_openssl_rsa_verifyhash_pkcs ( void *pPointer )
{
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX *ctx;
	int nStatus;
	#else
	RSA *pRsa ;
	#endif
	EVP_PKEY *pKey;
	const EVP_MD* md;
	int nSize,nModulusLen,nSignature,nDigest;
	unsigned char *cInput, *cSignature, cDigest[64];
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) || ! RING_API_ISSTRING(2) || ! RING_API_ISSTRING(3)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	pKey = (EVP_PKEY*) RING_API_GETCPOINTER(1,"OSSL_PKEY");
	if ( pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	
	/* check that this is indeed an RSA key */
	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	#endif	
	
	cInput = (unsigned char*) RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);
	
	cSignature = (unsigned char*) RING_API_GETSTRING(3);
	nSignature = RING_API_GETSTRINGSIZE(3);

	/* the input must be a hash from a supported algorithm */
	/* we support both raw digest and hexadecimal digest */
	switch (nSize) {
	case 16: md = EVP_md5(); break;
	case 20: md = EVP_sha1(); break;
	case 32: 
		/* either MD5 in hexadecimal or raw SHA256 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 16) {
			cInput = cDigest;
			nSize = 16;
			md = EVP_md5();
		}
		else {
			md = EVP_sha256();
		}
		break;
	case 40: 
		/* SHA1 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 20) {
			cInput = cDigest;
			nSize = 20;
			md = EVP_sha1();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 48: md = EVP_sha384(); break;
	case 64:
		/* either SHA256 in hexadecimal or raw SHA512 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 32) {
			cInput = cDigest;
			nSize = 32;
			md = EVP_sha256();
		}
		else {
			md = EVP_sha512();
		}
		break;
	case 96:
		/* SHA384 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 48) {
			cInput = cDigest;
			nSize = 48;
			md = EVP_sha384();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 128:
		/* SHA512 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 64) {
			cInput = cDigest;
			nSize = 64;
			md = EVP_sha512();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	nModulusLen = EVP_PKEY_size(pKey);

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	ctx = EVP_PKEY_CTX_new(pKey,NULL);
	if ( 	(EVP_PKEY_verify_init(ctx) > 0)
		&&	(EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) > 0)
		&&	(EVP_PKEY_CTX_set_signature_md(ctx, md) > 0)
		) {
		nStatus = EVP_PKEY_verify(ctx, cSignature, (size_t) nSignature, cInput, (size_t) nSize);
		if ( nStatus < 0 ) {
			/* error occured */
			RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
		}
		else {
			RING_API_RETNUMBER(nStatus);
		}
	}
	else {
		/* error occured */
		RING_API_ERROR( ERR_reason_error_string(ERR_get_error()));
	}
	#else
	pRsa = EVP_PKEY_get1_RSA(pKey);
	if (RSA_verify(EVP_MD_type(md),cInput,(unsigned int)nSize,cSignature,(unsigned int)nSignature,pRsa) == 1) {
		RING_API_RETNUMBER(1);
	}
	else {
		RING_API_RETNUMBER(0);
	}
	#endif

	#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	EVP_PKEY_CTX_free(ctx);
	#else
	RSA_free(pRsa);
	#endif
}

/* define PSS salt length configuration for older OpenSSL*/
#if OPENSSL_VERSION_NUMBER < 0x10100000L
/* Salt length matches digest */
# define RSA_PSS_SALTLEN_DIGEST -1
/* Verify only: auto detect salt length */
# define RSA_PSS_SALTLEN_AUTO   -2
/* Set salt length to maximum possible */
# define RSA_PSS_SALTLEN_MAX    -3
/* Old compatible max salt length for sign only */
# define RSA_PSS_SALTLEN_MAX_SIGN    -2
#endif

void ring_vm_openssl_rsa_sign_pss(void* pPointer)
{
	const EVP_MD* md;
	RSA* pRsa;
	EVP_PKEY* pKey;
#if OPENSSL_VERSION_NUMBER >= 0x10100001L
	EVP_MD_CTX* md_ctx;
#else
	EVP_MD_CTX md_ctx;
#endif
	int nSize, nModulusLen, nSaltLen, nHashAlg, nStatus;
	unsigned char* cInput, * cOutput, * cPaddedPss;
	unsigned char CDigest[64]; /* enough for largest hash */
	unsigned int nDigestLen = 64;
	/* possible parameters: 
		- key, dataToSign, hashAlgo
		- key, dataToSign, hashAlgo, saltLen
	*/
	if (RING_API_PARACOUNT != 3 && RING_API_PARACOUNT != 4) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2) || !RING_API_ISNUMBER(3)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	if ((RING_API_PARACOUNT == 4) && !RING_API_ISNUMBER(4)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	pKey = (EVP_PKEY*)RING_API_GETCPOINTER(1, "OSSL_PKEY");
	if (pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	/* check that this is indeed an RSA key */
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#endif

	nHashAlg = (int)RING_API_GETNUMBER(3);

	switch (nHashAlg) {
	case OSSL_OAEP_MD5: md = EVP_md5(); break;
	case OSSL_OAEP_SHA1: md = EVP_sha1(); break;
	case OSSL_OAEP_SHA256: md = EVP_sha256(); break;
	case OSSL_OAEP_SHA384: md = EVP_sha384(); break;
	case OSSL_OAEP_SHA512: md = EVP_sha512(); break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	if (RING_API_PARACOUNT == 4) {
		nSaltLen = (int) RING_API_GETNUMBER(4);

		if (nSaltLen <= -1 && (nSaltLen != RSA_PSS_SALTLEN_DIGEST && nSaltLen != RSA_PSS_SALTLEN_MAX_SIGN)) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		if (nSaltLen == RSA_PSS_SALTLEN_MAX_SIGN) {
			nSaltLen = RSA_PSS_SALTLEN_MAX;
		}
		#endif
	}
	else {
		/* by default we use maximum salt length */
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		nSaltLen = RSA_PSS_SALTLEN_MAX;
		#else
		nSaltLen = RSA_PSS_SALTLEN_MAX_SIGN;
		#endif
	}

	cInput = (unsigned char*)RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	/* hash the input */
#if OPENSSL_VERSION_NUMBER >= 0x10100001L
	md_ctx = EVP_MD_CTX_new();
	EVP_DigestInit(md_ctx, md);
	EVP_DigestUpdate(md_ctx, (const void*)cInput, (size_t) nSize);
	EVP_DigestFinal(md_ctx, CDigest, &nDigestLen);
	EVP_MD_CTX_free(md_ctx);
#else
	EVP_MD_CTX_init(&md_ctx);
	EVP_DigestInit(&md_ctx, md);
	EVP_DigestUpdate(&md_ctx, (const void*)cInput, (size_t)nSize);
	EVP_DigestFinal(&md_ctx, CDigest, &nDigestLen);
	EVP_MD_CTX_cleanup(&md_ctx);
#endif

	nModulusLen = EVP_PKEY_size(pKey);

	cOutput = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cOutput == NULL) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	cPaddedPss = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cPaddedPss == NULL) {
		RING_API_FREE(cOutput);
		RING_API_ERROR(RING_OOM);
		return;
	}


	/* compute the PSS padded data */
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nStatus = RSA_padding_add_PKCS1_PSS(pRsa, cPaddedPss, CDigest, md, nSaltLen);
	if (!nStatus)
	{
		RING_API_FREE(cOutput);
		RING_API_FREE(cPaddedPss);
		RSA_free(pRsa);
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		return;
	}

	/* perform digital signature */
	nStatus = RSA_private_encrypt(nModulusLen, cPaddedPss, cOutput, pRsa, RSA_NO_PADDING);
	if (nStatus == -1)
	{
		RING_API_FREE(cOutput);
		RING_API_FREE(cPaddedPss);
		RSA_free(pRsa);
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		return;
	}

	RING_API_RETSTRING2((const char*)cOutput, nModulusLen);

	RING_API_FREE(cOutput);
	RING_API_FREE(cPaddedPss);
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_verify_pss(void* pPointer)
{
	const EVP_MD* md;
	RSA* pRsa;
	EVP_PKEY* pKey;
#if OPENSSL_VERSION_NUMBER >= 0x10100001L
	EVP_MD_CTX* md_ctx;
#else
	EVP_MD_CTX md_ctx;
#endif
	int nSize, nModulusLen, nSaltLen, nHashAlg, nStatus, nSignatureSize;
	unsigned char* cInput, * cPaddedPss, * cSignature;
	unsigned char CDigest[64]; /* enough for largest hash */
	unsigned int nDigestLen = 64;
	/* possible parameters:
		- key, data, signature, hashAlgo
		- key, data, signature, hashAlgo, saltLen
	*/
	if (RING_API_PARACOUNT != 4 && RING_API_PARACOUNT != 5) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2) || !RING_API_ISSTRING(3) || !RING_API_ISNUMBER(4)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	if ((RING_API_PARACOUNT == 5) && !RING_API_ISNUMBER(5)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	pKey = (EVP_PKEY*)RING_API_GETCPOINTER(1, "OSSL_PKEY");
	if (pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	/* check that this is indeed an RSA key */
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#endif

	nHashAlg = (int)RING_API_GETNUMBER(4);

	switch (nHashAlg) {
	case OSSL_OAEP_MD5: md = EVP_md5(); break;
	case OSSL_OAEP_SHA1: md = EVP_sha1(); break;
	case OSSL_OAEP_SHA256: md = EVP_sha256(); break;
	case OSSL_OAEP_SHA384: md = EVP_sha384(); break;
	case OSSL_OAEP_SHA512: md = EVP_sha512(); break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	if (RING_API_PARACOUNT == 5) {
		nSaltLen = (int)RING_API_GETNUMBER(5);

		if (nSaltLen <= -1 && (nSaltLen != RSA_PSS_SALTLEN_DIGEST && nSaltLen != RSA_PSS_SALTLEN_MAX_SIGN)) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		if (nSaltLen == RSA_PSS_SALTLEN_MAX_SIGN) {
			nSaltLen = RSA_PSS_SALTLEN_MAX;
		}
		#endif
	}
	else {
		/* by default we use maximum salt length */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		nSaltLen = RSA_PSS_SALTLEN_MAX;
#else
		nSaltLen = RSA_PSS_SALTLEN_MAX_SIGN;
#endif
	}

	cInput = (unsigned char*)RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	cSignature = (unsigned char*)RING_API_GETSTRING(3);
	nSignatureSize = RING_API_GETSTRINGSIZE(3);

	nModulusLen = EVP_PKEY_size(pKey);

	/* signature size must be equal to modulus length*/
	if (nSignatureSize != nModulusLen) {
		RING_API_ERROR("rsa_verify_pss: signature size must be equal to the RSA key modulus length");
		return;
	}

	cPaddedPss = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cPaddedPss == NULL) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	/* hash the input */
#if OPENSSL_VERSION_NUMBER >= 0x10100001L
	md_ctx = EVP_MD_CTX_new();
	EVP_DigestInit(md_ctx, md);
	EVP_DigestUpdate(md_ctx, (const void*)cInput, (size_t)nSize);
	EVP_DigestFinal(md_ctx, CDigest, &nDigestLen);
	EVP_MD_CTX_free(md_ctx);
#else
	EVP_MD_CTX_init(&md_ctx);
	EVP_DigestInit(&md_ctx, md);
	EVP_DigestUpdate(&md_ctx, (const void*)cInput, (size_t)nSize);
	EVP_DigestFinal(&md_ctx, CDigest, &nDigestLen);
	EVP_MD_CTX_cleanup(&md_ctx);
#endif

	/* decrypt the PSS padded data */
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nStatus = RSA_public_decrypt(nModulusLen, cSignature, cPaddedPss, pRsa, RSA_NO_PADDING);
	if (nStatus == -1)
	{
		RING_API_FREE(cPaddedPss);
		RSA_free(pRsa);
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		return;
	}

	/* verify the data */
	nStatus = RSA_verify_PKCS1_PSS(pRsa, CDigest, md, cPaddedPss, nSaltLen);
	if (nStatus == 1)
	{
		RING_API_RETNUMBER(1);
	}
	else
	{
		RING_API_RETNUMBER(0);
	}

	RING_API_FREE(cPaddedPss);
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_signhash_pss(void* pPointer)
{
	const EVP_MD* md;
	RSA* pRsa;
	EVP_PKEY* pKey;
	int nSize, nModulusLen, nSaltLen, nStatus, nDigest;
	unsigned char* cInput, * cOutput, * cPaddedPss, cDigest[64];
	/* possible parameters: 
		- key, digestToSign
		- key, digestToSign, saltLen
	*/
	if (RING_API_PARACOUNT != 2 && RING_API_PARACOUNT != 3) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	if ((RING_API_PARACOUNT == 3) && !RING_API_ISNUMBER(3)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	pKey = (EVP_PKEY*)RING_API_GETCPOINTER(1, "OSSL_PKEY");
	if (pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	/* check that this is indeed an RSA key */
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#endif

	cInput = (unsigned char*)RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);


	/* the input must be a hash from a supported algorithm */
	/* we support both raw digest and hexadecimal digest */
	switch (nSize) {
	case 16: md = EVP_md5(); break;
	case 20: md = EVP_sha1(); break;
	case 32: 
		/* either MD5 in hexadecimal or raw SHA256 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 16) {
			cInput = cDigest;
			nSize = 16;
			md = EVP_md5();
		}
		else {
			md = EVP_sha256();
		}
		break;
	case 40: 
		/* SHA1 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 20) {
			cInput = cDigest;
			nSize = 20;
			md = EVP_sha1();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 48: md = EVP_sha384(); break;
	case 64:
		/* either SHA256 in hexadecimal or raw SHA512 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 32) {
			cInput = cDigest;
			nSize = 32;
			md = EVP_sha256();
		}
		else {
			md = EVP_sha512();
		}
		break;
	case 96:
		/* SHA384 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 48) {
			cInput = cDigest;
			nSize = 48;
			md = EVP_sha384();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 128:
		/* SHA512 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 64) {
			cInput = cDigest;
			nSize = 64;
			md = EVP_sha512();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	if (RING_API_PARACOUNT == 3) {
		nSaltLen = (int) RING_API_GETNUMBER(3);

		if (nSaltLen <= -1 && (nSaltLen != RSA_PSS_SALTLEN_DIGEST && nSaltLen != RSA_PSS_SALTLEN_MAX_SIGN)) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		if (nSaltLen == RSA_PSS_SALTLEN_MAX_SIGN) {
			nSaltLen = RSA_PSS_SALTLEN_MAX;
		}
		#endif
	}
	else {
		/* by default we use maximum salt length */
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		nSaltLen = RSA_PSS_SALTLEN_MAX;
		#else
		nSaltLen = RSA_PSS_SALTLEN_MAX_SIGN;
		#endif
	}

	nModulusLen = EVP_PKEY_size(pKey);

	cOutput = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cOutput == NULL) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	cPaddedPss = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cPaddedPss == NULL) {
		RING_API_FREE(cOutput);
		RING_API_ERROR(RING_OOM);
		return;
	}


	/* compute the PSS padded data */
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nStatus = RSA_padding_add_PKCS1_PSS(pRsa, cPaddedPss, cInput, md, nSaltLen);
	if (!nStatus)
	{
		RING_API_FREE(cOutput);
		RING_API_FREE(cPaddedPss);
		RSA_free(pRsa);
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		return;
	}

	/* perform digital signature */
	nStatus = RSA_private_encrypt(nModulusLen, cPaddedPss, cOutput, pRsa, RSA_NO_PADDING);
	if (nStatus == -1)
	{
		RING_API_FREE(cOutput);
		RING_API_FREE(cPaddedPss);
		RSA_free(pRsa);
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		return;
	}

	RING_API_RETSTRING2((const char*)cOutput, nModulusLen);

	RING_API_FREE(cOutput);
	RING_API_FREE(cPaddedPss);
	RSA_free(pRsa);
}

void ring_vm_openssl_rsa_verifyhash_pss(void* pPointer)
{
	const EVP_MD* md;
	RSA* pRsa;
	EVP_PKEY* pKey;
	int nSize, nModulusLen, nSaltLen, nStatus, nSignatureSize, nDigest;
	unsigned char* cInput, * cPaddedPss, * cSignature, cDigest[64];
	/* possible parameters:
		- key, digest, signature
		- key, digest, signature, saltLen
	*/
	if (RING_API_PARACOUNT != 3 && RING_API_PARACOUNT != 4) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2) || !RING_API_ISSTRING(3)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	if ((RING_API_PARACOUNT == 4) && !RING_API_ISNUMBER(4)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	pKey = (EVP_PKEY*)RING_API_GETCPOINTER(1, "OSSL_PKEY");
	if (pKey == NULL) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	/* check that this is indeed an RSA key */
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
	if (EVP_PKEY_base_id(pKey) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#else
	if (EVP_PKEY_type(pKey->type) != EVP_PKEY_RSA) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
#endif

	cInput = (unsigned char*)RING_API_GETSTRING(2);
	nSize = RING_API_GETSTRINGSIZE(2);

	/* the input must be a hash from a supported algorithm */
	/* we support both raw digest and hexadecimal digest */
	switch (nSize) {
	case 16: md = EVP_md5(); break;
	case 20: md = EVP_sha1(); break;
	case 32: 
		/* either MD5 in hexadecimal or raw SHA256 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 16) {
			cInput = cDigest;
			nSize = 16;
			md = EVP_md5();
		}
		else {
			md = EVP_sha256();
		}
		break;
	case 40: 
		/* SHA1 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 20) {
			cInput = cDigest;
			nSize = 20;
			md = EVP_sha1();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 48: md = EVP_sha384(); break;
	case 64:
		/* either SHA256 in hexadecimal or raw SHA512 */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 32) {
			cInput = cDigest;
			nSize = 32;
			md = EVP_sha256();
		}
		else {
			md = EVP_sha512();
		}
		break;
	case 96:
		/* SHA384 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 48) {
			cInput = cDigest;
			nSize = 48;
			md = EVP_sha384();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	case 128:
		/* SHA512 in hexadecimal */
		nDigest = ring_vm_openssl_hex2buf(RING_API_GETSTRING(2), cDigest);
		if (nDigest == 64) {
			cInput = cDigest;
			nSize = 64;
			md = EVP_sha512();
		}
		else {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		break;
	default:
		RING_API_ERROR(RING_API_BADPARAVALUE);
		return;
	}

	if (RING_API_PARACOUNT == 4) {
		nSaltLen = (int)RING_API_GETNUMBER(4);

		if (nSaltLen <= -1 && (nSaltLen != RSA_PSS_SALTLEN_DIGEST && nSaltLen != RSA_PSS_SALTLEN_MAX_SIGN)) {
			RING_API_ERROR(RING_API_BADPARAVALUE);
			return;
		}
		#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		if (nSaltLen == RSA_PSS_SALTLEN_MAX_SIGN) {
			nSaltLen = RSA_PSS_SALTLEN_MAX;
		}
		#endif
	}
	else {
		/* by default we use maximum salt length */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
		nSaltLen = RSA_PSS_SALTLEN_MAX;
#else
		nSaltLen = RSA_PSS_SALTLEN_MAX_SIGN;
#endif
	}

	cSignature = (unsigned char*)RING_API_GETSTRING(3);
	nSignatureSize = RING_API_GETSTRINGSIZE(3);

	nModulusLen = EVP_PKEY_size(pKey);

	/* signature size must be equal to modulus length*/
	if (nSignatureSize != nModulusLen) {
		RING_API_ERROR("rsa_verify_pss: signature size must be equal to the RSA key modulus length");
		return;
	}

	cPaddedPss = (unsigned char*)RING_API_MALLOC(nModulusLen);
	if (cPaddedPss == NULL) {
		RING_API_ERROR(RING_OOM);
		return;
	}

	/* decrypt the PSS padded data */
	pRsa = EVP_PKEY_get1_RSA(pKey);
	nStatus = RSA_public_decrypt(nModulusLen, cSignature, cPaddedPss, pRsa, RSA_NO_PADDING);
	if (nStatus == -1)
	{
		RING_API_FREE(cPaddedPss);
		RSA_free(pRsa);
		RING_API_ERROR(ERR_reason_error_string(ERR_get_error()));
		return;
	}

	/* verify the data */
	nStatus = RSA_verify_PKCS1_PSS(pRsa, cInput, md, cPaddedPss, nSaltLen);
	if (nStatus == 1)
	{
		RING_API_RETNUMBER(1);
	}
	else
	{
		RING_API_RETNUMBER(0);
	}

	RING_API_FREE(cPaddedPss);
	RSA_free(pRsa);
}
