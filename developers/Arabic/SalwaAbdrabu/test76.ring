/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/


load "openssllib.ring"

# md5() sha1() sha256() sha224() sha384() sha512()
# MD  = Message Digest
# SHA = Secure Hash Algorithm

? "Enter Message"
give cMsg
? "MD5 ="+ MD5(cMsg)
? "SHA1   ="+ SHA1(cMsg)
? "SHA256 ="+ SHA256(cMsg)
? "SHA512 ="+ SHA512(cMsg)
