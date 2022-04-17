# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	security_class_test()
ok

func security_class_test
	
	osecurity = new security
	See "Test the security Class Methods" + nl
	osecurity { 
		see md5("hello") + nl + 
		sha1("hello") + nl + sha256("hello") + nl +
		sha512("hello") + nl + sha384("hello") + nl + 
		sha256("hello") + nl 
		list = 0:15  cKey=""   for x in list cKey += char(x) next
		list = 1:8   cIV = ""   for x in list cIV += char(x) next
		cCipher = encrypt("hello",cKey,cIV)
		see cCipher + nl + decrypt(cCipher,cKey,cIV) + nl
	}

Class security
 
	Func md5 cString
		return std_md5(cString)

	Func sha1 cString
		return std_sha1(cString)

	Func sha256 cString
		return std_sha256(cString)

	Func sha512 cString
		return std_sha512(cString)

	Func sha384 cString
		return std_sha384(cString)

	Func sha224 cString
		return std_sha224(cString)

	Func encrypt cString,cKey,cIV
		return std_encrypt(cString,cKey,cIV)
		
	Func encrypt_ex cString,cKey,cIV,cCipher
		return std_encrypt(cString,cKey,cIV,cCipher)

	Func decrypt cString,cKey,cIV
		return std_decrypt(cString,cKey,cIV)
		
	Func decrypt_ex cString,cKey,cIV,cCipher
		return std_decrypt(cString,cKey,cIV,cCipher)
	
	Func supportedciphers
		return std_supportedciphers()

	Func randbytes nSize
		return std_randbytes(nSize)
