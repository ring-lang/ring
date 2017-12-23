/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 20/12/2017
*/
#================================================================

load "openssllib.ring"

# md5() sha1() sha256() sha224() sha384() sha512()

# MD = Message Digest
# SHA = Secure Hash Algorithm

? "Enter Message : " give cMsg
? "md5    = " + md5(cMsg)
? "sha1   = " + sha1(cMsg)
? "sha256 = "+ sha256(cMsg)
? "sha512 = "+ sha512(cMsg)
