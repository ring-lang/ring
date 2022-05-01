Load "openssllib.ring"

ver = openssl_version()
OpenSSLVersionMajor = ver[1] 
OpenSSLVersionMinor = ver[2] 
OpenSSLVersionFix = ver[3] 
See "Using " + openssl_versionText() + nl
See "Numerical version = " + OpenSSLVersionMajor + "." + OpenSSLVersionMinor + "." + OpenSSLVersionFix + nl
See nl

for bitLength=1024 to 4096 step 1024
	TestRsa(bitLength,65537) /* standard public exponent 0x010001 is the default*/
	TestRsa(bitLength,3) /* a popular public exponent for faster encryption */
next

func TestRsa bitLength, pubExp
	See "Testing " + bitLength + "-bits RSA with e=" + pubExp + nl
	rsaKey = rsa_generate(bitLength, pubExp);
	keyParams = rsa_export_params(rsaKey);

	rsaKey2 = rsa_import_params(keyParams)
	keyParams2 = rsa_export_params(rsaKey2);

	publicParams = [:n = keyParams[:n], :e = keyParams[:e]]
	rsaPubKey = rsa_import_params(publicParams)
	publicParams = rsa_export_params(rsaPubKey)
	rsaPubKey2 = rsa_import_params(publicParams)
	publicParams2 = rsa_export_params(rsaPubKey)

	if Compare(keyParams,keyParams2) See "  full param OK" + nl else See "  full param FAILED!" + nl ok
	if Compare(publicParams,publicParams2) See "  public params OK" + nl else See "  public params FAILED!" + nl ok
	
	if keyParams[:bits] = bitLength See "  Bit length OK" + nl else See "  Bit length FAILED!!" + nl ok
	
	if rsa_is_privatekey(rsaKey) See "  Private key check OK" + nl else See "  Private Key check FAILED" + nl ok
	if !rsa_is_privatekey(rsaPubKey) See "  Public key check OK" + nl else See "  Public Key check FAILED" + nl ok
	
	pemPrivate = rsa_export_pem(rsaKey)
	pemPublic = rsa_export_pem(rsaPubKey)
	
	if (substr(pemPrivate,"-----BEGIN PRIVATE KEY-----") = 1) AND (Right(pemPrivate, 26) = ("-----END PRIVATE KEY-----" + nl))
		See "  Private key PEM export OK" + nl
	else
		See "  Private key PEM export FAILED" + nl 
	ok
	
	if (substr(pemPublic,"-----BEGIN PUBLIC KEY-----") = 1) AND (Right(pemPublic, 25) = ("-----END PUBLIC KEY-----" + nl))
		See "  Public key PEM export OK" + nl
	else
		See "  Public key PEM export FAILED" + nl 
	ok

	data = randbytes(32)
	ciphered = rsa_encrypt_pkcs(rsaPubKey, data)
	data2 = rsa_decrypt_pkcs(rsaKey, ciphered)
	
	if data = data2 See "  PKCS#1 encryption (32 bytes) OK" + nl else See "  PKCS#1 encryption (32 bytes) failed!!" + nl ok

	modulusLen = (bitLength + 7)/8
	data = randbytes( modulusLen - 11)
	ciphered = rsa_encrypt_pkcs(rsaPubKey, data)
	data2 = rsa_decrypt_pkcs(rsaKey, ciphered)

	if data = data2 See "  PKCS#1 encryption (max size) OK" + nl else See "  PKCS#1 encryption (max size) failed!!" + nl ok
	
	hashAlgorithms = [ $OSSL_HASH_MD5, $OSSL_HASH_SHA1, $OSSL_HASH_SHA256, $OSSL_HASH_SHA384, $OSSL_HASH_SHA512]
	
	for hashAlgo in hashAlgorithms
			
		maxInputLen = MaxOaepInputLength(bitLength,hashAlgo)
		/* if using OpenSSL older than 1.0, skip hash algorithms other than SHA1 */
		if (hashAlgo != $OSSL_HASH_SHA1) AND (OpenSSLVersionMajor < 1)
			maxInputLen = 0
		ok
		
		if maxInputLen = 0
			See "  OAEP-" + GetHashName(hashAlgo) + " encryption SKIPPED" + nl
		else
			try
				data = randbytes(maxInputLen)
				ciphered = rsa_encrypt_oaep(rsaPubKey, data, hashAlgo)
				data2 = rsa_decrypt_oaep(rsaKey, ciphered, hashAlgo)
				if data = data2 See "  OAEP-" + GetHashName(hashAlgo) + " encryption (max size) OK" + nl else See "  OAEP-" + GetHashName(hashAlgo) + " encryption (max size) failed!!" + nl ok
				
				/* test some input length*/
				totalLoops = 0
				successLoops = 0
				for inputLen=1 to (maxInputLen-1) step 10
					totalLoops++
					data = randbytes(inputLen)
					ciphered = rsa_encrypt_oaep(rsaPubKey, data, hashAlgo)
					data2 = rsa_decrypt_oaep(rsaKey, ciphered, hashAlgo)
					if data = data2 successLoops++ ok
				next
				
				if successLoops = totalLoops See "  OAEP-" + GetHashName(hashAlgo) + " encryption (various sizes) OK" + nl else See "  OAEP-" + GetHashName(hashAlgo) + " encryption (various sizes) failed!!" + nl ok
				
			catch
				See "  exception = " + cCatchError + nl
			done
		ok
	next
	
	if (OpenSSLVersionMajor >= 1)
		for hashAlgo in hashAlgorithms
			try
				data = randbytes(1000)
				signature = rsa_sign_pss(rsaKey, data, hashAlgo)
				if rsa_verify_pss(rsaPubKey,data,signature,hashAlgo)
					See "  PSS-" + GetHashName(hashAlgo) + " signature (default salt) OK" + nl
				else
					See "  PSS-" + GetHashName(hashAlgo) + " signature (default salt) failed!!" + nl
				ok
			catch
				See "  PSS-" + GetHashName(hashAlgo) + " signature (default salt) exception = " + cCatchError + nl
			done
			
			/* skip SHA512 for keys smaller than 2048 */
			if bitLength < 2048 AND hashAlgo = $OSSL_HASH_SHA512
				See "  PSS-" + GetHashName(hashAlgo) + " signature (salt len = hash len) SKIPPED" + nl
			else
				try
					data = randbytes(1000)
					signature = rsa_sign_pss(rsaKey, data, hashAlgo, -1)
					if rsa_verify_pss(rsaPubKey,data,signature,hashAlgo, -1)
						See "  PSS-" + GetHashName(hashAlgo) + " signature (salt len = hash len) OK" + nl
					else
						See "  PSS-" + GetHashName(hashAlgo) + " signature (salt len = hash len) failed!!" + nl
					ok
				catch
					See "  PSS-" + GetHashName(hashAlgo) + " signature (salt len = hash len) exception = " + cCatchError + nl
				done
			ok
		next
	else
		See "  PSS signature tests SKIPPED"
	ok
	
	/* Testing RSA RAW */
	data = randbytes(32)
	ciphered = rsa_encrypt_pkcs(rsaKey, data)
	
	paddedData = rsa_decrypt_raw (rsaKey, ciphered)
	clearInput = RemovePKCS1Padding(paddedData, 2)
	if clearInput = data
		? "  RSA Decrypt RAW OK"
	else
		? "  RSA Decrypt RAW FAILED"
	ok
	
	paddedData = AddPKCS1Padding(data, modulusLen, 2)
	ciphered = rsa_encrypt_raw(rsaKey, paddedData)
	decryptedData = rsa_decrypt_pkcs(rsaKey, ciphered)
	if decryptedData = data
		? "  RSA Encrypt RAW OK"
	else
		? "  RSA Encrypt RAW FAILED"
	ok
	
	See nl
	
/* helper functions */

func AddPKCS1Padding(inputData,modulusLen,paddingIndicator)
	paddedData = NULL
	inputDataLength = Len(inputData)
	if inputDataLength <= (modulusLen - 11)
		paddingSize = modulusLen - inputDataLength - 2 - 1
		paddingStr = space (paddingSize)
		if paddingIndicator = 2
			/* encryption case. Add random bytes */
			for i=1 to paddingSize
				paddingStr[i] = Char (1 + Random(254))
			next
		else
			/* signature case. Add 0xFF */
			for i=1 to paddingSize
				paddingStr[i] = Char (255)
			next
		end
		
		paddedData = Char(0) + Char(paddingIndicator) + paddingStr + Char (0) + inputData
		
	ok
	return paddedData
	
	
func RemovePKCS1Padding(paddedInput,paddingIndicator)
	i = 0
	clearInput = NULL
	paddedInputLength = len(paddedInput)
	if paddedInputLength > 11 AND Ascii(paddedInput[1]) = 0 AND Ascii(paddedInput[2]) = paddingIndicator
		zeroFound = false
		for j = 3 to paddedInputLength
			if Ascii(paddedInput[j]) = 0
				i = j
				zeroFound = true
				exit
			ok
		next
		
		if zeroFound
			if i = paddedInputLength
				/* unpadded data is empty */
				clearInput = ""
			else
				clearInput = substr(paddedInput,i+1)
			ok
		ok
	ok
	
	return clearInput

func MaxOaepInputLength RsaBitLength, hashAlgo
	maxLen = ((RsaBitLength + 7)/8) - (2 * GetHashSize(hashAlgo)) - 2
	if maxLen <= 0
		return 0
	else
		return maxLen
	ok
	
func GetHashName hashAlgo
	switch hashAlgo
	on $OSSL_HASH_MD5 	 return "MD5"
	on $OSSL_HASH_SHA1 	 return "SHA1"
	on $OSSL_HASH_SHA256 return "SHA256"
	on $OSSL_HASH_SHA384 return "SHA384"
	on $OSSL_HASH_SHA512 return "SHA512"
	other return 0
	off

func GetHashSize hashAlgo
	switch hashAlgo
	on $OSSL_HASH_MD5 	 return 16
	on $OSSL_HASH_SHA1 	 return 20
	on $OSSL_HASH_SHA256 return 32
	on $OSSL_HASH_SHA384 return 48
	on $OSSL_HASH_SHA512 return 64
	other return 0
	off

func PrintKeyElement(params, index, name)
	See name + " = " + params[index] + nl
	
func Compare (list1,list2)
	if islist(list1) and islist(list2)
		if Len(list1) = Len(list2)
			l = Len(list1)
			for i=1 to l
				if not Compare(list1[i],list2[i])
					return false
				ok
			next
			return true
		else
			return false
		ok
	elseif (isstring(list1) and isstring(list2)) or (isnumber(list1) and isnumber(list2))
		if list1 = list2
			return true
		else
			return false
		ok
	elseif isnull(list1) and isnull(list2)
		return true
	else
		return false
	ok
