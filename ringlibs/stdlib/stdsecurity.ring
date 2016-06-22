# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	secuirty_class_test()
ok

func secuirty_class_test
	
	osecuirty = new secuirty
	See "Test the secuirty Class Methods" + nl
	osecuirty { 
	}

Class secuirty
 
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

	Func decrypt cString,cKey,cIV
		return std_decrypt(cString,cKey,cIV)

	Func randbytes nSize
		return std_randbytes(nSize)
